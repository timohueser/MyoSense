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


void IRModeWidget::get_setup(QString filename) {
	QFile file(filename);
	if (file.open(QIODevice::ReadOnly |QIODevice::Text)) {
		QTextStream stream (&file);
		while (stream.readLine() != "IR-Remote");
		for (int i = 0; i<6; i++) {
			if (stream.readLine() == "1") slot_active[i] = true;
			else slot_active[i] = false;
			slot_names[i] = stream.readLine();
		}
	}
}

void IRModeWidget::update_file() {
		QFile file("IRModeWidget.txt");
	if (file.open(QIODevice::ReadWrite |QIODevice::Text)) {
		QTextStream stream (&file);
		stream << "IR-Remote" << endl;
		for (int i = 0; i < 6; i++) {
			if (slot_active[i] == true) stream << "1" << endl;
			else stream << "0" << endl;
			stream << slot_names[i] << endl;
		}
	}
}



void IRModeWidget::manual_clicked() {
		presetWidget->hide();
		manualWidget->show();
		//manualInfoLabel->setText("active");
		//presetInfoLabel->setText("press to activate");
}

void IRModeWidget::preset_clicked() {
		manualWidget->hide();
		presetWidget->show();
		//presetInfoLabel->setText("active");
		//manualInfoLabel->setText("press to activate");
}

void IRModeWidget::store_signal() {
	int selected_slot = DropDownSlots->currentIndex();
	SlotButtons[selected_slot]->setText(SlotName->text());
	slot_names[selected_slot] = SlotName->text();
	slot_active[selected_slot] = true;
	StatusLabel->setText("Ready...");
	update_file();
}



void IRModeWidget::remove_slot() {
	int selected_slot = DropDownSlots->currentIndex();
	slot_active[selected_slot] = false;
	slot_names[selected_slot] = "empty";
	SlotButtons[selected_slot]->setText("empty");
	update_file();
}
	


void IRModeWidget::get_signal() {
	StatusLabel->setText("Recording...");
	//mcp2221_ir.send_instruction(1,2,DropDownSlots->currentIndex());
	delayl(1);
	StatusLabel->setText("Signal recorded!");
}

void IRModeWidget::slot1_send() {
	//mcp2221_ir.send_instruction(1, 1,0);
}
void IRModeWidget::slot2_send() {
	//mcp2221_ir.send_instruction(1, 1,1);
}
void IRModeWidget::slot3_send() {
	//mcp2221_ir.send_instruction(1, 1,2);
}
void IRModeWidget::slot4_send() {
	//mcp2221_ir.send_instruction(1, 1,3);
}
void IRModeWidget::slot5_send() {
	//mcp2221_ir.send_instruction(1, 1,4);
}
void IRModeWidget::slot6_send() {
	//mcp2221_ir.send_instruction(1, 1,5);
}



IRModeWidget::IRModeWidget(QWidget *parent) : QWidget(parent, Qt::Window) {
	manual_active = true;
	get_setup("IRModeWidget.txt");
	font = new QFont("Arial", 12, QFont::Bold);
	fontsmall = new QFont("Arial", 12);
	bottomFiller = new QWidget(this);
	bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	middleFiller = new QWidget(this);
	middleFiller->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
	middleFiller->setMinimumSize(1,30);
	HLine = new QFrame;
	HLine->setFrameShape(QFrame::HLine);
	layout = new QGridLayout;
	presetModeButton = new QPushButton("Preset Mode", this);
	presetModeButton->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Minimum);
	presetModeButton->setMinimumSize(200,40);
	QObject::connect(presetModeButton, SIGNAL (clicked()), this, SLOT (preset_clicked()));
	manualModeButton = new QPushButton("Manual Mode", this);
	manualModeButton->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
	manualModeButton->setMinimumSize(200,40);
	QObject::connect(manualModeButton, SIGNAL (clicked()), this, SLOT (manual_clicked()));
	manualModeButton->setCheckable(true);
	manualModeButton->setAutoExclusive(true);
	presetModeButton->setCheckable(true);
	presetModeButton->setAutoExclusive(true);
	//manualInfoLabel = new QLabel("active", this);
	//presetInfoLabel = new QLabel("press to activate", this);
	
	
	presetWidget = new QWidget(this);
	presetlayout = new QGridLayout(presetWidget);
	PresetTestButton = new QPushButton("test", presetWidget);
	presetlayout->addWidget(PresetTestButton);
	presetWidget->setLayout(presetlayout);
	presetWidget->hide();
	
	manualWidget = new QWidget(this);
	centerFillerM = new QWidget(manualWidget);
	centerFillerM->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	bottomFillerM = new QWidget(manualWidget);
	bottomFillerM->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	topFillerM = new QWidget(manualWidget);
	topFillerM->setMaximumSize(100,7);
	topFillerM->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	manuallayout = new QGridLayout;
	DropDownSlots = new QComboBox(manualWidget);
	DropDownSlots->addItem(tr("1"));
	DropDownSlots->addItem(tr("2"));
	DropDownSlots->addItem(tr("3"));
	DropDownSlots->addItem(tr("4"));
	DropDownSlots->addItem(tr("5"));
	DropDownSlots->addItem(tr("6"));
	NewSignalLabel = new QLabel ("Record new Remote Signal:",manualWidget);
	NewSignalLabel->setFont(*font);
	ActiveSlotLabel = new QLabel ("Select Slot:", manualWidget);
	ActiveSlotLabel->setFont(*fontsmall);
	ActiveSlotLabel->setMinimumSize(100,30);
	StatusLabel = new QLabel ("Ready...", manualWidget);
	StatusLabel->setFont(*font);
	StatusLabel->setMinimumSize(10,30);
	SetNameLabel = new QLabel("Set Name:", manualWidget);
	SetNameLabel->setFont(*fontsmall);
	
	SlotName = new QLineEdit("Slot 1", manualWidget);
	RecordButton = new QPushButton("Record Signal", manualWidget);
	RecordButton->setMinimumSize(100,30);
	QObject::connect(RecordButton, SIGNAL (clicked()), this, SLOT (get_signal()));
	TestButton = new QPushButton("Test", manualWidget);
	TestButton->setMinimumSize(60,30);
	StoreButton = new QPushButton("Save", manualWidget);
	StoreButton->setMinimumSize(60,30);
	QObject::connect(StoreButton, SIGNAL (clicked()), this, SLOT (store_signal()));
	RemoveButton = new QPushButton("Remove Slot", manualWidget);
	RemoveButton->setMinimumSize(60,30);
	QObject::connect(RemoveButton, SIGNAL (clicked()), this, SLOT (remove_slot()));


	
	
	slotswidget = new QWidget(manualWidget);
	slotswidget->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
	slotslayout = new QGridLayout;
	SlotsLabel = new QLabel("Available Slots:", this);
	SlotsLabel->setFont(*font);
	for(int i = 0; i < 6; i++) {
		SlotButtons[i] = new QPushButton(slot_names[i], slotswidget);
		SlotButtons[i]->setMinimumSize(150,30);
		SlotButtons[i]->setStatusTip("press to test");
	}
	QObject::connect(SlotButtons[0], SIGNAL (clicked()), this, SLOT(slot1_send()));
	QObject::connect(SlotButtons[1], SIGNAL (clicked()), this, SLOT(slot2_send()));
	QObject::connect(SlotButtons[2], SIGNAL (clicked()), this, SLOT(slot3_send()));
	QObject::connect(SlotButtons[3], SIGNAL (clicked()), this, SLOT(slot4_send()));
	QObject::connect(SlotButtons[4], SIGNAL (clicked()), this, SLOT(slot5_send()));
	QObject::connect(SlotButtons[5], SIGNAL (clicked()), this, SLOT(slot6_send()));
	
	
	
	slotslayout->addWidget(SlotsLabel, 0,0,1,2);
	slotslayout->addWidget(SlotButtons[0], 1, 0,1,2);
	slotslayout->addWidget(SlotButtons[1], 2, 0,1,2);
	slotslayout->addWidget(SlotButtons[2], 3, 0,1,2);
	slotslayout->addWidget(SlotButtons[3], 4, 0,1,2);
	slotslayout->addWidget(SlotButtons[4], 5, 0,1,2);
	slotslayout->addWidget(SlotButtons[5], 6, 0,1,2);
	slotswidget->setLayout(slotslayout);
	
	manuallayout->addWidget(slotswidget,0,0,9,1);
	manuallayout->addWidget(topFillerM,0,2,1,2);
	manuallayout->addWidget(centerFillerM,0,1,9,1);
	manuallayout->addWidget(NewSignalLabel,1,2,1,2);
	manuallayout->addWidget(ActiveSlotLabel,2,2);
	manuallayout->addWidget(DropDownSlots, 2,3);
	manuallayout->addWidget(RecordButton,3,2,1,2);
	manuallayout->addWidget(SetNameLabel,4,2);
	manuallayout->addWidget(SlotName,4,3);
	manuallayout->addWidget(bottomFillerM,8,2,1,2);
	manuallayout->addWidget(StatusLabel,5,2,1,2);
	manuallayout->addWidget(TestButton,6,2);
	manuallayout->addWidget(StoreButton,6,3);
	manuallayout->addWidget(RemoveButton,7,2,1,2);
	manualWidget->setLayout(manuallayout);
	
	layout->setMargin(30);
	layout->addWidget(presetModeButton,0,0);
	layout->addWidget(manualModeButton,0,2);
	//layout->addWidget(manualInfoLabel,1,0);
	//layout->addWidget(presetInfoLabel,1,2);
	layout->addWidget(HLine, 2,0,1,3);
	layout->addWidget(manualWidget,3,0,1,3);
	layout->addWidget(presetWidget,3,0,1,3);
	layout->addWidget(bottomFiller,4,0,1,3);
	
	setLayout(layout);	
}
