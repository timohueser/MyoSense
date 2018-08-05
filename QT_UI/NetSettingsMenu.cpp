#include "i2c_mcp2221.hpp"
#include <QPushButton>
#include <QApplication>
#include <QCheckBox>
#include <QTextStream>
#include <QFile>
#include <QGridLayout>
#include <QLabel>
#include <QFont>

bool OnePlotMode;
bool SettingsChanged = false;

void NetSettingsMenu::handleExit() {
	close();
}

void NetSettingsMenu::get_setup(QString filename) {
	QFile file(filename);
	if (file.open(QIODevice::ReadOnly |QIODevice::Text)) {
		QTextStream stream (&file);
		if (stream.readLine() == "1") OnePlotMode = true;
		else OnePlotMode = false;
	}
}

void NetSettingsMenu::update_file() {
	SettingsChanged = true;
	OnePlotMode = PlotModeBox->checkState();
	QFile file("NetSettingsMenu.txt");
	if (file.open(QIODevice::ReadWrite |QIODevice::Text)) {
		QTextStream stream (&file);
			if (OnePlotMode == true) stream << "1" << endl;
			else stream << "0" << endl;
	}
}


NetSettingsMenu::NetSettingsMenu(QWidget *parent) : QWidget(parent, Qt::Window) {
	get_setup("NetSettingsMenu.txt");
	resize(480,320);
	font = new QFont("Arial", 12, QFont::Bold);
	layout = new QGridLayout(this);
	liveLabel = new QLabel("Signal Display Settings:");
	liveLabel->setFont(*font);
	PlotModeBox = new QCheckBox("Combine all Waveforms into one plot", this);
	PlotModeBox->setChecked(OnePlotMode);
	saveButton = new QPushButton("Save", this);
	saveButton->setMinimumSize(60,30);
	QObject::connect(saveButton, SIGNAL (clicked()), this, SLOT (update_file()));
	closeButton = new QPushButton("Close", this);
	closeButton->setMinimumSize(60,30);
	QObject::connect(closeButton, SIGNAL (clicked()), this, SLOT (handleExit()));
	middleFiller = new QWidget(this);
	middleFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	rightFiller = new QWidget(this);
	//rightFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	
	layout->addWidget(liveLabel,0,0);
	layout->addWidget(PlotModeBox,1,0);
	layout->addWidget(middleFiller,2,0,1,3);
	layout->addWidget(rightFiller,3,0);
	layout->addWidget(saveButton,3,1);
	layout->addWidget(closeButton,3,2);
	setLayout(layout);
}
