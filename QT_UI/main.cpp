#include "i2c_mcp2221.hpp"
#include <iostream>
using namespace std;
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char **argv)
{
	QApplication app (argc, argv);
	MainWindow m_window;
	m_window.show();
	
	
	return app.exec();
}
