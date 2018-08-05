#include "i2c_mcp2221.hpp"
#include <QPushButton>
#include <QDesktopWidget>
#include <QApplication>
#include <QGridLayout>
#include <QMainWindow>
#include <QWidget>
#include <QIcon>
#include <QFileDialog>ParameterSettingsAct
#include <QMessageBox>
#include <QTextStream>



MainWindow::MainWindow(QMainWindow *parent) : QMainWindow(parent) {
	Menus = new QWidget;
	setCentralWidget(Menus);
	layout = new QGridLayout;
	layout->addWidget(&ir_mode_widget);
	layout->addWidget(&net_mode_widget);
	Menus->setLayout(layout);
	setCentralWidget(Menus);
	ir_mode_widget.hide();
	createActions();
	createMenus();
	resize(840, 580);
	setMinimumSize(320,160);
}


void MainWindow::NewProject() {
}

void MainWindow::LoadProject() {
	/*projectfilename = QFileDialog::getOpenFileName(this, tr("Load Project"), "", tr("Project File (*.prof);;All Files (*)"));
	QFile file(projectfilename);
      if (file.open(QIODevice::ReadOnly)) {
		while(!file.atEnd()) projectfile.append(file.readLine());
	}
	file.close();*/
}

void MainWindow::SaveProject() {
	/*if (projectfilename.isEmpty()) {
	projectfilename = QFileDialog::getSaveFileName(this, tr("Save Project"), "", tr("Project File (*.prof);;All Files (*)"));
	QFile file(projectfilename);
	if (file.open(QIODevice::WriteOnly)) {
		QTextStream s(&file);
		for (int i = 0; i < projectfile.size(); ++i) {
			s << projectfile.at(i) << '\n';
		}
	}
	file.close();
	}*/
}

void MainWindow::SaveAsProject() {
}

void MainWindow::IRRemote() {
	ir_mode_widget.show();
	net_mode_widget.hide();
}

void MainWindow::NeuralNet() {
	ir_mode_widget.hide();
	net_mode_widget.show();
}

void MainWindow::NextMode() {
}

void MainWindow::PreviousMode() {
}

void MainWindow::NetSettings() {
	net_settings_menu.show();

}


void MainWindow::createActions() {
	NewProjectAct = new QAction(tr("&New Project"), this);
	NewProjectAct->setShortcuts(QKeySequence::New);
	NewProjectAct->setStatusTip(tr("Create new Project"));
	connect(NewProjectAct, &QAction::triggered, this, &MainWindow::NewProject);
	
	LoadProjectAct = new QAction(tr("&Open Project"), this);
	LoadProjectAct->setShortcuts(QKeySequence::Open);
	LoadProjectAct->setStatusTip(tr("Load old Project"));
	connect(LoadProjectAct, &QAction::triggered, this, &MainWindow::LoadProject);
	
	SaveProjectAct = new QAction(tr("&Save Project"), this);
	SaveProjectAct->setStatusTip(tr("Save Project"));
	SaveProjectAct->setShortcuts(QKeySequence::Save);
	connect(SaveProjectAct, &QAction::triggered, this, &MainWindow::SaveProject);
	
	SaveAsProjectAct = new QAction(tr("&Save Project as..."), this);
	SaveAsProjectAct->setStatusTip(tr("Save Project as..."));
	SaveAsProjectAct->setShortcuts(QKeySequence::SaveAs);
	connect(SaveAsProjectAct, &QAction::triggered, this, &MainWindow::SaveAsProject);
	
	exitAct = new QAction(tr("&Exit"), this);
	exitAct->setShortcuts(QKeySequence::Quit);
	exitAct->setStatusTip(tr("Exit the application"));
	connect(exitAct, &QAction::triggered, this, &QWidget::close);
	
	
	IRAct = new QAction(tr("&IR-Remote"), this);
	IRAct->setStatusTip(tr("Open IR-Remote mode"));
	connect(IRAct, &QAction::triggered, this, &MainWindow::IRRemote);
	
	NetAct = new QAction(tr("&Neural Net"), this);
	NetAct->setStatusTip(tr("&Open Neural Net mode"));
	connect(NetAct, &QAction::triggered, this, &MainWindow::NeuralNet);
	
	NextModeAct = new QAction(tr("&Next Mode"), this);
	NextModeAct->setShortcuts(QKeySequence::MoveToNextWord);
	NextModeAct->setStatusTip(tr("&Switch  to next Mode"));
	connect(NextModeAct, &QAction::triggered, this, &MainWindow::NextMode);
	
	PreviousModeAct = new QAction(tr("&Previous Mode"), this);
	PreviousModeAct->setShortcuts(QKeySequence::MoveToPreviousWord);
	PreviousModeAct->setStatusTip(tr("&Switch  to previous Mode"));
	connect(PreviousModeAct, &QAction::triggered, this, &MainWindow::PreviousMode);
	
	
	NetSettingsAct = new QAction(tr("&Neural Net Settings"), this);
	connect(NetSettingsAct, &QAction::triggered, this, &MainWindow::NetSettings);
}


void MainWindow::createMenus()
{
	FileMenu = menuBar()->addMenu(tr("&File"));
	FileMenu->addAction(NewProjectAct);
	FileMenu->addSeparator();
	FileMenu->addAction(LoadProjectAct);
	FileMenu->addSeparator();
	FileMenu->addAction(SaveProjectAct);
	FileMenu->addAction(SaveAsProjectAct);
	FileMenu->addSeparator();
	FileMenu->addAction(exitAct);
	
	ModesMenu = menuBar()->addMenu(tr("&Modes"));
	ModesMenu->addAction(IRAct);
	ModesMenu->addAction(NetAct);
	ModesMenu->addSeparator();
	ModesMenu->addAction(NextModeAct);
	ModesMenu->addAction(PreviousModeAct);
	
	SettingsMenu = menuBar()->addMenu(tr("&Settings"));
	SettingsMenu->addAction(NetSettingsAct);
	
}
