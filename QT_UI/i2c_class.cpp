#include "i2c_mcp2221.hpp"
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/param.h>	/* for NAME_MAX */
#include <sys/ioctl.h>
#include <string.h>
#include <strings.h>	/* for strcasecmp() */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <dirent.h>
#include <fcntl.h>
#include <errno.h>
#include "i2cbusses.h"
#include "i2cbusses.c"
#include <linux/i2c-dev.h>
#include <iostream>
using namespace std;

I2C_mcp2221::I2C_mcp2221() {
	system("./driver_load.sh");
	adapter_nr = lookup_i2c_bus_by_name("i2c-mcp2221");
	if (adapter_nr != -1) {
		printf("Adapter present on bus %d.\n",adapter_nr);
		snprintf(filename, 19, "/dev/i2c-%d", adapter_nr);
		file = open(filename, O_RDWR);
		if (file < 0) {
			perror ("Unable to establish connection");
		}
	}
}

int I2C_mcp2221::send_instruction(unsigned int addr, unsigned int mode, unsigned int cmd) {
	char outbuf[2];
	struct i2c_rdwr_ioctl_data packets;
	struct i2c_msg messages[1];
	
	messages[0].addr  = addr;
	messages[0].flags = 0;
	messages[0].len   = sizeof(outbuf);
	messages[0].buf   = outbuf;
	
	outbuf[0] = mode;
	outbuf[1] = cmd;
	
	packets.msgs  = messages;
	packets.nmsgs = 1;
	if(ioctl(file, I2C_RDWR, &packets) < 0) {
		perror("Unable to send data");
		return 1;
	}
	return 0;
}

int I2C_mcp2221::get_ack(unsigned int addr) {
	char inbuf[1];
	struct i2c_rdwr_ioctl_data packets;
	struct i2c_msg messages[1];

	messages[0].addr  = addr;
	messages[0].flags = I2C_M_RD/* | I2C_M_NOSTART*/;
	messages[0].len   = sizeof(inbuf);
	messages[0].buf   = inbuf;
	
	packets.msgs      = messages;
	packets.nmsgs     = 1;
	if(ioctl(file, I2C_RDWR, &packets) < 0) {
        perror("Something went wrong!");
        return 0;
	}
	if (inbuf[0] != 1) return 0;
	return 1;
}

int I2C_mcp2221::check_conn(unsigned int addr) {
	char outbuf[4] = {0,0};
	struct i2c_rdwr_ioctl_data packets;
	struct i2c_msg messages[1];
	
	messages[0].addr  = addr;
	messages[0].flags = 0;
	messages[0].len   = sizeof(outbuf);
	messages[0].buf   = outbuf;
	packets.msgs  = messages;
	packets.nmsgs = 1;
	ioctl(file, I2C_RDWR, &packets);
	if(ioctl(file, I2C_RDWR, &packets) < 0) {
		return 0;
	}
	return 1;
}

int I2C_mcp2221::get_int(unsigned int addr) {
    char inbuf[2];
    int res[2];
    struct i2c_rdwr_ioctl_data packets;
    struct i2c_msg messages[1];

    messages[0].addr  = addr;
    messages[0].flags = I2C_M_RD/* | I2C_M_NOSTART*/;
    messages[0].len   = sizeof(inbuf);
    messages[0].buf   = inbuf;

    packets.msgs      = messages;
    packets.nmsgs     = 1;
    if(ioctl(file, I2C_RDWR, &packets) < 0) {
        perror("Unable to send data");
        return -1;
    }
    res[0] = inbuf[0];
    res[1] = inbuf[1];
    if (res[1] < 0) res[1] = 256+res[1];
    return res[0]*256+res[1];
}

