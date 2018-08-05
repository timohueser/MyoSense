#include <stdio.h>      // standard input / output functions
#include <string.h>     // string function definitions
#include <unistd.h>     // UNIX standard function definitions
#include <fcntl.h>      // File control definitions
#include <errno.h>      // Error number definitions
#include <iostream>
#include <sys/stat.h>
#include <sys/time.h>

#include "i2c_mcp2221.hpp"


int SerialInterface::serial_write (void *cmd,int nwrite) {
	char * data = (char*) cmd;
	int n_written = 0;
	n_written = write( USB, data, nwrite);
	return n_written;
}

int SerialInterface::serial_read(void *response, int nread) {
	int spot = 0;
	int n;
	int rv;
	char *buf;
	buf = (char*) response;
	fd_set set;
	struct timeval timeout;
	FD_ZERO(&set); /* clear the set */
	FD_SET(USB, &set); /* add our file descriptor to the set */
	timeout.tv_sec = 0;
	timeout.tv_usec = 1000000;
	
	do {
		rv = select(USB + 1, &set, NULL, NULL, &timeout);
		if(rv == -1) return -1;
		else if(rv == 0) {
			std::cout << "Timeout" << std::endl;
			return 0;
		}
		else n = read(USB, buf+spot, nread); /* there was data to read */
			//std::cout << (int)buf[spot] << std::endl;
			spot += n;
	} while( spot < nread && n > 0);
	
	if (n < 0) {
		std::cout << "Error reading: " << strerror(errno) << std::endl;
	}
	else if (n == 0) {
		std::cout << "Read nothing!" << std::endl;
	}
	else {
		//std::cout << "Response: " << response << std::endl;
	}
	return spot;
}

int SerialInterface::open_port(const char* port) {
	USB = open(port, O_RDWR| O_NOCTTY );
	if (errno != 0) {
		std::cout << "Error " << errno << " while opening Port: " << strerror(errno) << std::endl;
		return 0;
	}
	/* Flush Port, then applies attributes */
	tcflush(USB, TCIOFLUSH);
	if ( tcsetattr (USB, TCSANOW, &tty ) != 0) {
		std::cout << "Error " << errno << " from tcsetattr" << std::endl;
		return 0;
	}
	return 1;
}

int SerialInterface::close_port() {
	if(close(USB)) return 1;
	else return 1;
}


SerialInterface::SerialInterface() {
	//struct termios tty;
	struct termios tty_old;
	memset (&tty, 0, sizeof tty);
	/* Set Baud Rate */
	cfsetospeed (&tty, (speed_t)B19200);
	cfsetispeed (&tty, (speed_t)B19200);
	/* Setting other Port Stuff */
	tty.c_cflag     &=  ~PARENB;            // Make 8n1
	tty.c_cflag     &=  ~CSTOPB;
	tty.c_cflag     &=  ~CSIZE;
	tty.c_cflag     |=  CS8;
	tty.c_cflag     &=  ~CRTSCTS;           // no flow control
	tty.c_cc[VMIN]   =  1;                  // read doesn't block
	tty.c_cc[VTIME]  =  1;                  // 0.5 seconds read timeout
	tty.c_cflag     |=  CREAD | CLOCAL;     // turn on READ & ignore ctrl lines
	cfmakeraw(&tty);

}









