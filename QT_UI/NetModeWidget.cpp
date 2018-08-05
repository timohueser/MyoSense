#include "i2c_mcp2221.hpp"
#include <QPushButton>
#include <QApplication>
#include <QLineEdit>
#include <QFont>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFrame>
#include <QComboBox>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QTimer>
#include <QVector>
#include "qcustomplot.h"
#include "ledindicator.h"
#include <QSerialPortInfo>

#define DISPLAYNUM 150
#define DISPLAYNUMR 75
uint16_t burstData[DISPLAYNUMR][8];
int moveCounts[8] = {0,0,0,0,0,0,0,0};


void NetModeWidget::live_clicked() {
	RecordButton->setChecked(false);
	RecordButton->setText("Start Recording");
	QObject::disconnect(serialPort, 0, this, 0);
	dataTimer->start(20);
	liveWidget->show();
	learnWidget->hide();
	recordWidget->hide();
}

void NetModeWidget::learn_clicked()  {
	RecordButton->setChecked(false);
	RecordButton->setText("Start Recording");
	QObject::disconnect(serialPort, 0, this, 0);
	dataTimer->stop();
	liveWidget->hide();
	learnWidget->show();
	recordWidget->hide();
}

void NetModeWidget::record_clicked() {
	dataTimer->stop();
	liveWidget->hide();
	learnWidget->hide();
	recordWidget->show();
}

void NetModeWidget::change_plots(int index) {
	for (int i = 0; i <= index; i++) {
		customPlot[i]->show();
	}
	for (int i = index+1; i < 8; i++) {
		customPlot[i]->hide();
	}
}


void NetModeWidget::update_data() {
	if (serial_conn) {
		if (SettingsChanged) { 
			if (OnePlotMode) {
				plotWidget->hide();
				oneplotWidget->show();
			}
			else {
				oneplotWidget->hide();
				plotWidget->show();
			}
			SettingsChanged = false;
		}
		QByteArray cmd;
		cmd[0] = 1;
		cmd[1] = 0;
		serialPort->clear(QSerialPort::Input);
		serialPort->write(cmd);
		serialPort->flush();
		serialPort->waitForBytesWritten(-1);
		for (int i = 0; i < num_active_channels*2; i++) {
			serialPort->waitForReadyRead(10);
		}
		int nread = serialPort->read((char*)voltages, num_active_channels*2);
		if (nread != num_active_channels*2) return;
		int j = 0;
		for (int sensor = 0; sensor <= highest_active_channel; sensor++) {
			if (active_channels[sensor]) {
				for (int i=0; i<DISPLAYNUM; ++i) {
					y[sensor][i] = y[sensor][i+1];
				}
				y[sensor][DISPLAYNUM] = voltages[j++];
				if (OnePlotMode) {
					oneplot->graph(sensor)->setData(x[sensor], y[sensor]);
					oneplot->replot();
				}
				else {
					customPlot[sensor]->graph(0)->setData(x[sensor], y[sensor]);
					customPlot[sensor]->replot();
				}
			}
		}
	}
}

void NetModeWidget::show_setup() {
	setupWindow->show();
}

void NetModeWidget::change_savefile() {
	QString prev_savefile = active_savefile;
	active_savefile = QFileDialog::getOpenFileName(this, tr("Open SaveFile"), "", tr("Savefile (*.svf);;All Files (*)"));
	if (active_savefile.isEmpty()) return;
	active_recordfile = active_savefile.left(active_savefile.length() - 3) + "txt";
	QFile file(active_savefile);
	QStringList savefile;
	if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
		while(!file.atEnd()) savefile.append(file.readLine());
	}
	QStringList temp = savefile[16].split(",");
	for (int i = 0; i< 8; i++) {
		if (temp[i].toInt() != active_channels[i]) {
			active_savefile = prev_savefile;
			QMessageBox msgBox;
			msgBox.setText("Active channels don't match savefile!");
			msgBox.setInformativeText("Create new savefile?");
			QString Info = "Activate channels ";
			for (int i = 0; i < 8; i++) {
				if(temp[i].toInt()) Info.append(QString::number(i)+ ", ");
			}
			Info = Info.left(Info.length() - 2);
			Info.append(" to use this savefile!");
			msgBox.setDetailedText(Info);
			msgBox.setStandardButtons(QMessageBox::Yes |QMessageBox::Retry | QMessageBox::Cancel);
			msgBox.setDefaultButton(QMessageBox::Cancel);
			int ret = msgBox.exec();
			switch (ret) {
				case QMessageBox::Retry:
					change_savefile();
					break;
				case QMessageBox::Yes:
					new_savefile();
					break;
				case QMessageBox::Cancel:
					break;
				default:
					// should never be reached
					break;
			}	
			return;
		}
	}
	get_move_counts();
	SaveFileName->setText(active_savefile);
	RecordButton->setEnabled(true);
	SetupButton->setEnabled(true);
	SelectMoveBox->clear();
	for (int i = 0; i < 8; i++) {
		active_moves[i] = savefile[2*i].toInt();
		move_names[i] = savefile[2*i+1];
		move_names[i].remove(QRegExp("[\\n\\t\\r]"));
		if (!move_names[i].isEmpty()) MoveCounterLabels[i]->setText(move_names[i]);
		else MoveCounterLabels[i]->setText("<empty>");
		MoveNames[i]->setText(move_names[i]);
		if (!move_names[i].isEmpty()) SelectMoveBox->addItem(move_names[i]);
		else SelectMoveBox->addItem("<empty>");
		activeMoveSel[i]->setChecked(active_moves[i]);
	}
	
}

void NetModeWidget::new_savefile() {
	active_savefile = QFileDialog::getSaveFileName(this, tr("New Savefile"), "", tr("Savefile (*.svf);;All Files (*)"));
	if (active_savefile.isEmpty()) return;
	active_recordfile = active_savefile.left(active_savefile.length() - 3) + "txt";
	SaveFileName->setText(active_savefile);
	RecordButton->setEnabled(true);
	SetupButton->setEnabled(true);
	initialize_savefile(active_savefile);
	QFile file(active_savefile);
	QStringList savefile;
	if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
		while(!file.atEnd()) savefile.append(file.readLine());
	}
	for (int i = 0; i < 8; i++) {
		active_moves[i] = savefile[2*i].toInt();
		move_names[i] = savefile[2*i+1];
		move_names[i].remove(QRegExp("[\\n\\t\\r]"));
		if (!move_names[i].isEmpty()) MoveCounterLabels[i]->setText(move_names[i]);
		else MoveCounterLabels[i]->setText("<empty>");
		MoveNames[i]->setText(move_names[i]);
		activeMoveSel[i]->setChecked(active_moves[i]);
	}
}


void NetModeWidget::get_move_counts() {
	for (int i = 0; i < 8; i++) {
		moveCounts[i] = 0;
	}
	QFile file(active_recordfile);
	QStringList recordfile;
	if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
		while(!file.atEnd()) recordfile.append(file.readLine());
	}
	for (int i = 0; i < recordfile.length()/2; i++) {
		moveCounts[recordfile[2*i].toInt()]++;
	}
	for (int i = 0; i < 8; i++) {
		MoveCounters[i]->setText(QString::number(moveCounts[i]));
	}
}


void NetModeWidget::initialize_savefile(QString savefilename) {
	QFile file(savefilename);
	QTextStream s(&file);
	if (file.open(QIODevice::WriteOnly)) {
		for (int i = 0; i < 8; ++i) {
			s << 0 << endl;
			s << "<empty>" << endl;
		}
		for (int i = 0; i < 8; i++) {
			s << active_channels[i] << ",";
		}
		s << endl;
	}
	file.close();
}

void NetModeWidget::update_savefile(QString savefilename) {
	QFile file(savefilename);
	QStringList savefile;
	if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
		while(!file.atEnd()) savefile.append(file.readLine());
	}
	for (int i = 0; i < 8; i++) {
		savefile[2*i] = QString::number((int)active_moves[i]);
		savefile[2*i+1] = move_names[i];
	}
	file.resize(0);
	QTextStream s(&file);
	for (int i = 0; i < savefile.size(); ++i) {
		s << savefile.at(i) << endl;
	}
}


void NetModeWidget::close_setup() {
	setupWindow->hide();
}

void NetModeWidget::start_record_clicked() {
	if(RecordButton->isChecked()) {
		RecordButton->setText("Stop Recording");
		QByteArray cmd;
		cmd[0] = 1;
		cmd[1] = 1;
		serialPort->clear(QSerialPort::Input);
		serialPort->write(cmd);
		serialPort->flush();
		serialPort->waitForBytesWritten(-1);
		QObject::connect(serialPort, SIGNAL(readyRead()),this,SLOT(readDataBurst()));
		
	}
	else {
		QByteArray cmd;
		cmd[0] = 1;
		cmd[1] = 2;
		serialPort->write(cmd);
		serialPort->flush();
		serialPort->waitForBytesWritten(-1);
		QObject::disconnect(serialPort, 0, this, 0);
		RecordButton->setText("Start Recording");
	}
}

void NetModeWidget::save_record_clicked() {
	QFile file(active_recordfile);
	if (file.open(QIODevice::ReadWrite | QIODevice::Append)) {
		QTextStream s(&file);
		s << SelectMoveBox->currentIndex() << endl;
		for (int i = 0; i < num_active_channels;i++) {
			for (int j = 0; j < DISPLAYNUMR; j++) {
				s << burstData[j][i] << ",";
			}
		}
		s << endl;
		file.close();
	}
	moveCounts[SelectMoveBox->currentIndex()]++;
	MoveCounters[SelectMoveBox->currentIndex()]->setText(QString::number(moveCounts[SelectMoveBox->currentIndex()]));
	if (RecordButton->isChecked()) {
		QByteArray cmd;
		cmd[0] = 1;
		cmd[1] = 2;
		serialPort->write(cmd);
		serialPort->flush();
		serialPort->waitForBytesWritten(-1);
		QTime timer;
		timer.start();
		while (timer.elapsed() < 10);
		cmd[0] = 1;
		cmd[1] = 1;
		serialPort->write(cmd);
		serialPort->flush();
		serialPort->waitForBytesWritten(-1);
	}
	int j = 0;
	for (int sensor = 0; sensor <= highest_active_channel; sensor++) {
		if (active_channels[sensor]) {
			for (int i=0; i<DISPLAYNUMR; i++) {
				recordy[sensor][i] = 0;
			}
			j++;
			recordoneplot->graph(sensor)->setData(recordx[sensor], recordy[sensor]);
			recordoneplot->replot();
		}
	}
	SaveButton->setEnabled(false);
	DiscardButton->setEnabled(false);
}

void NetModeWidget::discard_record_clicked() {
	if (RecordButton->isChecked()) {
		QByteArray cmd;
		cmd[0] = 1;
		cmd[1] = 2;
		serialPort->write(cmd);
		serialPort->flush();
		serialPort->waitForBytesWritten(-1);
		QTime timer;
		timer.start();
		while (timer.elapsed() < 10);
		cmd[0] = 1;
		cmd[1] = 1;
		serialPort->write(cmd);
		serialPort->flush();
		serialPort->waitForBytesWritten(-1);
	}
	int j = 0;
	for (int sensor = 0; sensor <= highest_active_channel; sensor++) {
		if (active_channels[sensor]) {
			for (int i=0; i<DISPLAYNUMR; i++) {
				recordy[sensor][i] = 0;
			}
			j++;
			recordoneplot->graph(sensor)->setData(recordx[sensor], recordy[sensor]);
			recordoneplot->replot();
		}
	}
	SaveButton->setEnabled(false);
	DiscardButton->setEnabled(false);
}

void NetModeWidget::readDataBurst() {
	int setsread = 0;
	QTime timer;
	timer.start();
	while (setsread < DISPLAYNUMR && timer.elapsed() < DISPLAYNUMR*4+200) {
		while (serialPort->bytesAvailable() < 4 && timer.elapsed() < DISPLAYNUMR*4+200) {
			serialPort->waitForReadyRead(2);
		}
		
		int nread = serialPort->read((char*)burstData[setsread], num_active_channels*2);
		//std::cout << burstData[setsread][0] << "......" << nread <<  std::endl;
		if (nread == num_active_channels*2) setsread++;
	}
	int j = 0;
	for (int sensor = 0; sensor <= highest_active_channel; sensor++) {
		if (active_channels[sensor]) {
			for (int i=0; i<DISPLAYNUMR; i++) {
				recordy[sensor][i] = burstData[i][j];
			}
			j++;
			recordoneplot->graph(sensor)->setData(recordx[sensor], recordy[sensor]);
			recordoneplot->replot();
		}
	}
	SaveButton->setEnabled(true);
	DiscardButton->setEnabled(true);
}


void NetModeWidget::save_setup() {
	SelectMoveBox->clear();
	for (int i = 0; i < 8; i++) {
		active_moves[i] = activeMoveSel[i]->isChecked();
		move_names[i] = MoveNames[i]->text();
		MoveCounterLabels[i]->setText(move_names[i]);
		if (!move_names[i].isEmpty()) SelectMoveBox->addItem(move_names[i]);
		else SelectMoveBox->addItem("<empty>");
	}
	update_savefile(active_savefile);
}

int NetModeWidget::get_active_channels() {
	QTime myTimer;
	highest_active_channel = 0;
	QByteArray cmd;
	cmd[0] = 0;
	cmd[1] = 1;
	serialPort->write(cmd);
	serialPort->flush();
	serialPort->waitForBytesWritten(-1);
	int nread = 0;
	num_active_channels = 0;
	char conn;	
	serialPort->waitForReadyRead(2100);
	myTimer.start();
	while (nread < 1 && myTimer.elapsed() < 200) {
		nread = serialPort->read(&conn,1);
	}
	if((int)conn == 1) {
		cmd[0] = 0;
		cmd[1] = 0;
		serialPort->write(cmd);
		serialPort->waitForBytesWritten(-1);
		myTimer.start();
		for (int i = 0; i < 8; i++) {
			serialPort->waitForReadyRead(500);
		}
		char *data = (char*) active_channels;
		if (serialPort->read(data, 8) != 8) return 0;
		std::cout << "Active Channels: ";
		for (int i = 0; i< 8; i++) {
			std::cout << active_channels[i] << ", ";
			if (active_channels[i]) {
				highest_active_channel = i;
				num_active_channels++;
			}
		}
		std::cout << std::endl;
		return 1;
	}
	else return 0;
}


NetModeWidget::NetModeWidget(QWidget *parent) : QWidget(parent, Qt::Window) {
	/*for (int i = 0; i < 8; i++) {
	 *	if (mcp2221_net.check_conn(i)) {
	 *		active_channels[i] = true;
	 *		if (highest_active_channel < i) highest_active_channel = i;
}
else active_channels[i] = false;
}*/
	QList<QSerialPortInfo> serialPortInfos = QSerialPortInfo::availablePorts();
	for (int i= 0; i <  serialPortInfos.count(); i++) {
		if (serialPortInfos[i].description() == "MCP2221 USB-I2C UART Combo") {
			serialPortName = serialPortInfos[i].portName();
		}
	}
	std::cout << serialPortName.toStdString() << std::endl;
	serialPort = new QSerialPort();
	serialPort->setPortName(serialPortName);
	if(this->serialPort->open(QIODevice::ReadWrite))
	{
		serial_conn = true;
		serialPort->setBaudRate(QSerialPort::Baud19200);
		serialPort->setParity(QSerialPort::NoParity);
		serialPort->setStopBits(QSerialPort::OneStop);
		serialPort->setFlowControl(QSerialPort::NoFlowControl);
		serialPort->setDataBits(QSerialPort::Data8);
		if(!get_active_channels()) {
			QMessageBox msgBox;
			msgBox.setText("Wireless connection could not be established!");
			msgBox.exec();
		}
	}
	else {
		serial_conn = false;
		QMessageBox msgBox;
		msgBox.setText("No Receiver connected!");
		msgBox.exec();
		for (int i = 0; i < 8; i++) {
			active_channels[i] = 0;
		}
		num_active_channels = 0;
		highest_active_channel = 0;
	}
	font = new QFont("Arial", 12, QFont::Bold);
	fontsmall = new QFont("Arial", 11);
	fontsmallf = new QFont("Arial", 10, QFont::Bold);
	
	
	layout = new QGridLayout;
	liveModeButton = new QPushButton("Display Signal", this);
	liveModeButton->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Minimum);
	liveModeButton->setMinimumSize(200,40);
	liveModeButton->setCheckable(true);
	liveModeButton->setAutoExclusive(true);
	QObject::connect(liveModeButton, SIGNAL (clicked()), this, SLOT (live_clicked()));
	learnModeButton = new QPushButton("Train Network", this);
	learnModeButton->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Minimum);
	learnModeButton->setMinimumSize(200,40);
	learnModeButton->setCheckable(true);
	learnModeButton->setAutoExclusive(true);
	QObject::connect(learnModeButton, SIGNAL (clicked()), this, SLOT (learn_clicked()));
	recordModeButton = new QPushButton("Record Data", this);
	recordModeButton->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Minimum);
	recordModeButton->setMinimumSize(200,40);
	recordModeButton->setCheckable(true);
	recordModeButton->setAutoExclusive(true);
	QObject::connect(recordModeButton, SIGNAL (clicked()), this, SLOT (record_clicked()));
	HLine = new QFrame;
	HLine->setFrameShape(QFrame::HLine);
	bottomFiller = new QWidget(this);
	channelDisplay = new QWidget(this);
	channellayout = new QGridLayout(channelDisplay);
	QWidget *channelFiller = new QWidget(channelDisplay);
	QLabel *channelLabel = new QLabel("Active Channels:",channelDisplay);
	channelLabel->setFont(*fontsmallf);
	channelFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Ignored);
	channellayout->addWidget(channelLabel,0,0);
	for (int i = 0; i <8; i++) {
		channelLEDs[i] = new LedIndicator(channelDisplay); //creates new instance whih off state
		channelLEDs[i]->setState(active_channels[i]);
		channellayout->addWidget(channelLEDs[i], 0,i+1);
	}
	channellayout->addWidget(channelFiller,0,9);
	channellayout->setMargin(0);
	channelDisplay->setLayout(channellayout);
	
	//******************************************************************************************
	liveWidget = new QWidget(this);
	liveWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	livelayout = new QGridLayout(liveWidget);
	NumDisplayLabel = new QLabel("Number of Channels to display:", liveWidget);
	NumDisplayLabel->setFont(*font);
	NumDisplaySel = new QComboBox(liveWidget);
	NumDisplaySel->addItem(tr("1"));
	NumDisplaySel->addItem(tr("2"));
	NumDisplaySel->addItem(tr("3"));
	NumDisplaySel->addItem(tr("4"));
	NumDisplaySel->addItem(tr("5"));
	NumDisplaySel->addItem(tr("6"));
	NumDisplaySel->addItem(tr("7"));
	NumDisplaySel->addItem(tr("8"));
	NumDisplaySel->setCurrentIndex(highest_active_channel);
	QObject::connect(NumDisplaySel, SIGNAL (activated(int)), this, SLOT (change_plots(int)));
	livelayout->addWidget(NumDisplayLabel,0,0);
	livelayout->addWidget(NumDisplaySel,0,1);
	setup_plots();
	setup_oneplot();
	livelayout->addWidget(plotWidget,2,0,1,2);
	livelayout->addWidget(oneplotWidget,2,0,1,2);
	if(OnePlotMode) plotWidget->hide();
	else oneplotWidget->hide();
	liveWidget->setLayout(livelayout);	
	for (int i = 0; i <= highest_active_channel; i++) {
		customPlot[i]->show();
	}
	for (int i = highest_active_channel+1; i < 8; i++) {
		customPlot[i]->hide();
	}
	
	//******************************************************************************************
	learnWidget = new QWidget(this);
	learnWidget->hide();
	
	
	//******************************************************************************************
	recordWidget = new QWidget(this);
	recordWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	recordWidget->hide();
	recordlayout = new QGridLayout(recordWidget);
	SelectMoveLabel = new QLabel("Select Move to record:", recordWidget);
	SelectMoveLabel->setFont(*font);
	SelectMoveBox = new QComboBox(recordWidget);
	RecordButton = new QPushButton("Start Recording",recordWidget);
	RecordButton->setMinimumSize(60,30);
	RecordButton->setCheckable(true);
	RecordButton->setEnabled(false);
	QObject::connect(RecordButton, SIGNAL (clicked()), this, SLOT (start_record_clicked()));
	SaveButton = new QPushButton("Save", recordWidget);
	SaveButton->setShortcut(QKeySequence(Qt::SHIFT + Qt::Key_S));
	SaveButton->setMinimumSize(100,30);
	SaveButton->setEnabled(false);
	QObject::connect(SaveButton, SIGNAL (clicked()), this, SLOT (save_record_clicked()));
	DiscardButton = new QPushButton("Discard", recordWidget);
	DiscardButton->setShortcut(QKeySequence(Qt::SHIFT + Qt::Key_D));
	DiscardButton->setMinimumSize(100,30);
	DiscardButton->setEnabled(false);
	QObject::connect(DiscardButton, SIGNAL (clicked()), this, SLOT (discard_record_clicked()));
	SetupButton = new QPushButton("Setup", recordWidget);
	SetupButton->setMinimumSize(60,40);
	SetupButton->setEnabled(false);
	QObject::connect(SetupButton, SIGNAL (clicked()), this, SLOT (show_setup()));
	setupFiller = new QWidget(recordWidget);
	//setupFiller->setMinimumSize(60,30);
	CounterLabel = new QLabel("Number of Moves recorded:", recordWidget);
	CounterLabel->setFont(*font);
	
	SaveFileWidget = new QWidget(recordWidget);
	savefilelayout = new QGridLayout(SaveFileWidget);
	SaveFileLabel = new QLabel("Active Savefile:", SaveFileWidget);
	SaveFileLabel->setFont(*fontsmallf);
	SaveFileName = new QLineEdit("savefile", SaveFileWidget);
	SaveFileName->setMinimumSize(200,30);
	ChangeButton = new QPushButton("Change", SaveFileWidget);
	ChangeButton->setMinimumSize(60,30);
	QObject::connect(ChangeButton, SIGNAL (clicked()), this, SLOT (change_savefile()));
	NewButton = new QPushButton("New", SaveFileWidget);
	NewButton->setMinimumSize(60,30);
	QObject::connect(NewButton, SIGNAL (clicked()), this, SLOT (new_savefile()));
	savefilelayout->addWidget(SaveFileLabel,0,0);
	savefilelayout->addWidget(SaveFileName,0,1);
	savefilelayout->addWidget(ChangeButton,0,2);
	savefilelayout->addWidget(NewButton,0,3);
	SaveFileWidget->setLayout(savefilelayout);
	
	counterWidget = new QWidget(recordWidget);
	counterlayout = new QGridLayout(counterWidget);
	counterMiddleFiller = new QWidget(counterWidget);
	counterMiddleFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	for (int i = 0; i < 8; i++) {
		MoveCounterLabels[i] = new QLabel("<empty>", counterWidget);
		MoveCounterLabels[i]->setFont(*fontsmall);
		MoveCounterLabels[i]->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
		MoveCounters[i] = new QLineEdit("0", counterWidget);
		MoveCounters[i]->setMaximumSize(60,20);
		MoveCounters[i]->setReadOnly(true);
	}
	for (int i = 0; i < 8; i+=2) {
		counterlayout->addWidget(MoveCounterLabels[i],1+(i/2),0);
		counterlayout->addWidget(MoveCounters[i], 1+(i/2),1);
	}
	counterlayout->addWidget(counterMiddleFiller,1,2,4,1);
	for (int i = 1; i < 8; i+=2) {
		counterlayout->addWidget(MoveCounterLabels[i],(1+i)/2,3);
		counterlayout->addWidget(MoveCounters[i], (1+i)/2,4);
	}
	counterWidget->setLayout(counterlayout);
	
	setup_recordoneplot();
	recordMiddleFiller = new QWidget(recordWidget);
	recordMiddleFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	
	recordlayout->addWidget(SaveFileWidget,0,0,1,4,Qt::AlignCenter);
	recordlayout->addWidget(SelectMoveLabel,1,0,1,2);
	recordlayout->addWidget(SelectMoveBox,2,0,1,2);
	recordlayout->addWidget(RecordButton,3,0,1,2);
	recordlayout->addWidget(SaveButton,4,0);
	recordlayout->addWidget(DiscardButton,4,1);
	recordlayout->addWidget(recordMiddleFiller,1,2,5,1);
	recordlayout->addWidget(CounterLabel, 1,3);
	recordlayout->addWidget(setupFiller,5,0,1,2);
	recordlayout->addWidget(SetupButton,6,0,1,2);
	recordlayout->addWidget(counterWidget,2,3,5,1);
	recordlayout->addWidget(recordoneplotWidget, 7,0,1,4);
	recordWidget->setLayout(recordlayout);
	
	setup_setupWindow();
	
	
	
	
	
	dataTimer = new QTimer;
	connect(dataTimer, SIGNAL(timeout()), this, SLOT(update_data()));
	dataTimer->start(20);	
	
	
	
	layout->setMargin(0);
	layout->addWidget(liveModeButton, 0,0);
	layout->addWidget(learnModeButton, 0,1);
	layout->addWidget(recordModeButton,0,2);
	layout->addWidget(HLine, 1,0,1,3);
	layout->addWidget(liveWidget, 2,0,1,3);
	layout->addWidget(learnWidget,2,0,1,3);
	layout->addWidget(recordWidget,2,0,1,3);
	layout->addWidget(bottomFiller,3,0,1,3);
	layout->addWidget(channelDisplay,4,0,1,3);
	setLayout(layout);
	
}


void NetModeWidget::setup_plots() {
	plotWidget = new QWidget(liveWidget);
	plotlayout = new QGridLayout(plotWidget);
	
	for (int p = 0; p < 8; p++) {
		customPlot[p] = new QCustomPlot(plotWidget);
		x[p].resize(DISPLAYNUM);
		y[p].resize(DISPLAYNUM);
		for (int i=0; i<DISPLAYNUM; ++i)
		{
			x[p][i] = i;
		}
		customPlot[p]->addGraph();
		customPlot[p]->graph(0)->setData(x[p], y[p]);
		customPlot[p]->yAxis->setLabel("Voltage");
		customPlot[p]->xAxis->setRange(0, DISPLAYNUM);
		customPlot[p]->yAxis->setRange(0, 1024);
		customPlot[p]->replot();
		customPlot[p]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	}
	QCPTextElement *title[8];
	title[0] = new QCPTextElement(customPlot[0], "Channel 1", QFont("Arial", 9, QFont::Bold));
	title[1] = new QCPTextElement(customPlot[1], "Channel 2", QFont("Arial", 9, QFont::Bold));
	title[2] = new QCPTextElement(customPlot[2], "Channel 3", QFont("Arial", 9, QFont::Bold));
	title[3] = new QCPTextElement(customPlot[3], "Channel 4", QFont("Arial", 9, QFont::Bold));
	title[4] = new QCPTextElement(customPlot[4], "Channel 5", QFont("Arial", 9, QFont::Bold));
	title[5] = new QCPTextElement(customPlot[5], "Channel 6", QFont("Arial", 9, QFont::Bold));
	title[6] = new QCPTextElement(customPlot[6], "Channel 7", QFont("Arial", 9, QFont::Bold));
	title[7] = new QCPTextElement(customPlot[7], "Channel 8", QFont("Arial", 9, QFont::Bold));
	for (int i = 0; i < 8; i++) {
		customPlot[i]->plotLayout()->insertRow(0);
		customPlot[i]->plotLayout()->addElement(0, 0, title[i]);
	}
	plotlayout->addWidget(customPlot[0],0,0);
	plotlayout->addWidget(customPlot[1],0,1);
	plotlayout->addWidget(customPlot[2],1,0);
	plotlayout->addWidget(customPlot[3],1,1);
	plotlayout->addWidget(customPlot[4],2,0);
	plotlayout->addWidget(customPlot[5],2,1);
	plotlayout->addWidget(customPlot[6],3,0);
	plotlayout->addWidget(customPlot[7],3,1);
}

void NetModeWidget::setup_oneplot() {
	oneplotWidget = new QWidget(liveWidget);
	oneplotlayout = new QGridLayout(oneplotWidget);
	oneplot = new QCustomPlot(oneplotWidget);
	for (int i = 0; i < 8; i++) {
		oneplot->addGraph();
		oneplot->graph(i)->setData(x[i], y[i]);
	}
	oneplot->graph(0)->setPen(QPen(Qt::blue));
	oneplot->graph(1)->setPen(QPen(Qt::red));
	oneplot->graph(2)->setPen(QPen(QColor(255,20,147, 255)));
	oneplot->graph(3)->setPen(QPen(Qt::yellow));
	oneplot->graph(4)->setPen(QPen(Qt::cyan));
	oneplot->graph(5)->setPen(QPen(QColor(255,140,0, 255)));
	oneplot->graph(6)->setPen(QPen(QColor(139,0,139, 255)));
	oneplot->graph(7)->setPen(QPen(Qt::green));
	
	oneplot->yAxis->setLabel("Voltage");
	oneplot->xAxis->setRange(0,DISPLAYNUM);
	oneplot->yAxis->setRange(0,1024);
	oneplot->replot();
	oneplot->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	oneplotlayout->addWidget(oneplot);
}

void NetModeWidget::setup_recordoneplot() {
	recordoneplotWidget = new QWidget(recordWidget);
	recordoneplotWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	recordoneplotlayout = new QGridLayout(recordoneplotWidget);
	
	recordoneplot = new QCustomPlot(recordoneplotWidget);
	recordoneplotlayout->addWidget(recordoneplot);
	recordoneplotWidget->setLayout(recordoneplotlayout);
	
	for (int p = 0; p < 8; p++) {
		recordx[p].resize(DISPLAYNUMR);
		recordy[p].resize(DISPLAYNUMR);
		for (int i=0; i<DISPLAYNUMR; ++i)
		{
			recordx[p][i] = i;
		}
		recordoneplot->addGraph();
		recordoneplot->graph(p)->setData(recordx[p], recordy[p]);
	}
	recordoneplot->graph(0)->setPen(QPen(Qt::blue));
	recordoneplot->graph(1)->setPen(QPen(Qt::red));
	recordoneplot->graph(2)->setPen(QPen(QColor(255,20,147, 255)));
	recordoneplot->graph(3)->setPen(QPen(Qt::yellow));
	recordoneplot->graph(4)->setPen(QPen(Qt::cyan));
	recordoneplot->graph(5)->setPen(QPen(QColor(255,140,0, 255)));
	recordoneplot->graph(6)->setPen(QPen(QColor(139,0,139, 255)));
	recordoneplot->graph(7)->setPen(QPen(Qt::green));
	recordoneplot->yAxis->setLabel("Voltage");
	recordoneplot->xAxis->setRange(0, DISPLAYNUMR);
	recordoneplot->yAxis->setRange(0, 1024);
	recordoneplot->replot();
}


void NetModeWidget::setup_setupWindow() {
	setupWindow = new QWidget(recordWidget, Qt::Window);
	setupWindow->resize(400,320);
	setuplayout = new QGridLayout(setupWindow);
	MoveLabel = new QLabel("Configure Moves:", setupWindow);
	MoveLabel->setFont(*font);
	ActiveLabel = new QLabel("active", setupWindow);
	ActiveLabel->setFont(*fontsmallf);
	MoveNameLabel = new QLabel("Name", setupWindow);
	MoveNameLabel->setFont(*fontsmallf);
	for (int i = 0; i < 8; i++) {
		activeMoveSel[i] = new QCheckBox(setupWindow);
		MoveNames[i] = new QLineEdit(setupWindow);
		MoveNames[i]->setText(move_names[i]);
		MoveResetButtons[i] = new QPushButton("reset", setupWindow);
		MoveResetButtons[i]->setMinimumSize(50,20);
		MoveResetButtons[i]->setToolTip("deletes all recorded moves in this slot");
	}
	QObject::connect(MoveResetButtons[0], SIGNAL(clicked()), this, SLOT(reset_clicked0()));
	QObject::connect(MoveResetButtons[1], SIGNAL(clicked()), this, SLOT(reset_clicked1()));
	QObject::connect(MoveResetButtons[2], SIGNAL(clicked()), this, SLOT(reset_clicked2()));
	QObject::connect(MoveResetButtons[3], SIGNAL(clicked()), this, SLOT(reset_clicked3()));
	QObject::connect(MoveResetButtons[4], SIGNAL(clicked()), this, SLOT(reset_clicked4()));
	QObject::connect(MoveResetButtons[5], SIGNAL(clicked()), this, SLOT(reset_clicked5()));
	QObject::connect(MoveResetButtons[6], SIGNAL(clicked()), this, SLOT(reset_clicked6()));
	QObject::connect(MoveResetButtons[7], SIGNAL(clicked()), this, SLOT(reset_clicked7()));
	SetupSave = new QPushButton("Save", setupWindow);
	SetupSave->setMinimumSize(60,30);
	SetupSave->setMaximumSize(60,30);
	QObject::connect(SetupSave, SIGNAL (clicked()), this, SLOT (save_setup()));
	SetupClose = new QPushButton("Close", setupWindow);
	SetupClose->setMinimumSize(60,30);
	SetupClose->setMaximumSize(60,30);
	QObject::connect(SetupClose, SIGNAL (clicked()), this, SLOT (close_setup()));
	setuplayout->addWidget(MoveLabel,0,0,1,2);
	setuplayout->addWidget(ActiveLabel,1,0);
	setuplayout->addWidget(MoveNameLabel,1,1);
	for (int i = 0; i < 8; i++) {
		setuplayout->addWidget(activeMoveSel[i], 2+i,0,Qt::AlignCenter);
		setuplayout->addWidget(MoveNames[i], 2+i,1);
		setuplayout->addWidget(MoveResetButtons[i],2+i,2);
	}
	setuplayout->addWidget(SetupSave,10,2,Qt::AlignRight);
	setuplayout->addWidget(SetupClose,10,3);
	setupWindow->setLayout(setuplayout);
	
}

void NetModeWidget::reset_clicked0() {
	reset_slot(0);
}
void NetModeWidget::reset_clicked1() {
	reset_slot(1);
}
void NetModeWidget::reset_clicked2() {
	reset_slot(2);
}
void NetModeWidget::reset_clicked3() {
	reset_slot(3);
}
void NetModeWidget::reset_clicked4() {
	reset_slot(4);
}
void NetModeWidget::reset_clicked5() {
	reset_slot(5);
}
void NetModeWidget::reset_clicked6() {
	reset_slot(6);
}
void NetModeWidget::reset_clicked7() {
	reset_slot(7);
}

void NetModeWidget::reset_slot(int slot) {
	QMessageBox msgBox;
	QString Info = "Do you want to reset Slot ";
	Info.append(QString::number(slot) + " (" + move_names[slot] + ")?");
	msgBox.setText(Info);
	msgBox.setStandardButtons(QMessageBox::Yes |QMessageBox::No);
	msgBox.setDefaultButton(QMessageBox::No);
	int ret = msgBox.exec();
	if (ret == QMessageBox::No) return;
	QFile file(active_recordfile);
	QStringList recordfile;
	QStringList prev_recordfile;
	if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
		while(!file.atEnd()) {
			recordfile.append(file.readLine());
			prev_recordfile.append(recordfile[recordfile.length()-1]);
		}
	}
	int j = 0;
	for (int i = 0; i < prev_recordfile.length()/2; i++) {
		if (prev_recordfile[2*i].toInt() == slot) {
			recordfile.removeAt(2*i+1+j);
			recordfile.removeAt(2*i+j);
			j-=2;
		}
	}
	file.resize(0);
	QTextStream s(&file);
	for (int i = 0; i < recordfile.size(); ++i) {
		s << recordfile.at(i);
	}
	file.close();
	get_move_counts();
}
