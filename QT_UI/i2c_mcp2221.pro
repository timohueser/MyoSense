CONFIG += qt
TEMPLATE = app
QT = core gui


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport serialport

HEADERS += i2c_mcp2221.hpp
HEADERS += qcustomplot.h
HEADERS += ledindicator.h
SOURCES += serial_class.cpp
SOURCES += i2c_class.cpp
SOURCES += MainWindow.cpp
SOURCES += NetSettingsMenu.cpp
SOURCES += IRModeWidget.cpp
SOURCES += NetModeWidget.cpp
SOURCES += main.cpp
SOURCES += qcustomplot.cpp
SOURCES += ledindicator.cpp

