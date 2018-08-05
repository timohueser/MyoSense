#include <QWidget>
#include <QMainWindow>
#include <QLabel>
#include <QMenuBar>
#include <QTime>
#include <QCoreApplication>
#include <QEventLoop>
#include <QVector>
#include <QString>
#include <QList>
#include <termios.h>
#include <stdint.h>
#include <iostream>
#include <QtSerialPort/QSerialPort>




inline void delayl(int n) {
	QTime dieTime = QTime::currentTime().addSecs(n);
	while (QTime::currentTime() < dieTime) QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}


#define IR_ADDRESS 10



class I2C_mcp2221 {
public:
	I2C_mcp2221();
	int file;
	char filename[20];
	int adapter_nr;
	int send_instruction(unsigned int addr, unsigned int mode, unsigned int cmd);
	int check_conn(unsigned int addr);
	int get_ack(unsigned int addr);
	int get_int(unsigned int addr);
};

class SerialInterface
{
public:
	SerialInterface();
	int serial_write(void *cmd, int nwrite); 
	int serial_read(void *response, int nread);
	int open_port(const char *port);
	int close_port();
private:
	int USB;
	struct termios tty;
	
};


class QAction;
class QActionGroup;
class QLabel;
class QMenu;
class QPushButton;
class QMenuBar;
class QLineEdit;
class QFont;
class QGridLayout;
class QHBoxLayout;
class QVBoxLayout;
class QFrame;
class QComboBox;
class QString;
class QFile;
class QTextStream;
class QTimer;
class QFileDialog;
class QMessageBox;
class QCheckBox;
class QCustomPlot;
class QSerialPortInfo;
class LedIndicator;

extern bool OnePlotMode;
extern bool SettingsChanged;


class NetSettingsMenu : public QWidget {
	Q_OBJECT
public:
	explicit NetSettingsMenu(QWidget *parent = 0);
private:
	void get_setup(QString filename);
	
	bool temp;
	QGridLayout *layout;
	const QFont *font;
	QLabel *liveLabel;
	QCheckBox *PlotModeBox;
	QPushButton *saveButton;
	QPushButton *closeButton;
	QWidget *middleFiller;
	QWidget *rightFiller;
public slots:
	void handleExit();
	void update_file();	
};



class IRModeWidget : public QWidget {
	Q_OBJECT
public:
	explicit IRModeWidget(QWidget *parent = 0);
	//I2C_mcp2221 mcp2221_ir;
private:
	QString slot_names[6];
	bool slot_active[6];
	bool manual_active;
	
	void get_setup(QString filename);
	void update_file();
	void test();

	
	QWidget *manualWidget;
	QWidget *presetWidget;
	QWidget *slotswidget;
	QWidget *bottomFiller;
	QWidget *middleFiller;
	QWidget *centerFillerM;
	QWidget *bottomFillerM;
	QWidget *topFillerM;
	
	QFrame *HLine;
	QGridLayout *presetlayout;
	QGridLayout *manuallayout;
	QGridLayout *layout;
	QGridLayout *slotslayout;
	
	const QFont *font;
	const QFont *fontsmall;
	QLabel *SlotsLabel;
	QLabel *NewSignalLabel;
	QLabel *ActiveSlotLabel;
	QLabel *StatusLabel;
	QLabel *SetNameLabel;
	QLabel *manualInfoLabel;
	QLabel *presetInfoLabel;
	QPushButton *SlotButtons[6];
	QPushButton *presetModeButton;
	QPushButton *manualModeButton;
	QLineEdit *SlotName;	
	QPushButton *RecordButton;
	QPushButton *StoreButton;
	QPushButton *TestButton;
	QPushButton *RemoveButton;
	QComboBox *DropDownSlots;
	
	QPushButton *PresetTestButton;
	
private slots:
	void manual_clicked();
	void preset_clicked();
	void store_signal();
	void remove_slot();
	void get_signal();
	void slot1_send();
	void slot2_send();
	void slot3_send();
	void slot4_send();
	void slot5_send();
	void slot6_send();

	
};


class NetModeWidget : public QWidget {
	Q_OBJECT
public:
	explicit NetModeWidget(QWidget *parent = 0);
	//I2C_mcp2221 mcp2221_net;
	SerialInterface serial_net;
private:
	bool serial_conn;
	int get_active_channels();
	void setup_plots();
	void setup_oneplot();
	void setup_recordoneplot();
	void setup_setupWindow();
	void initialize_savefile(QString savefilename);
	void update_savefile(QString savefilename);
	void get_move_counts();
	void reset_slot(int slot);
	
	bool active_channels[8];
	int16_t voltages[8];
	int highest_active_channel;
	int num_active_channels;
	bool active_moves[8];
	QString move_names[8];
	QString active_savefile;
	QString active_recordfile;
	const QFont *font;
	const QFont *fontsmall;
	const QFont *fontsmallf;
	
	QFrame *HLine;
	QSerialPort *serialPort;
	QString serialPortName;
	
	QCustomPlot *customPlot[8];
	QCustomPlot *oneplot;
	QCustomPlot *recordoneplot;
	QTimer *dataTimer;
	QVector<double> x[8], y[8];
	QGridLayout *layout;
	QPushButton *liveModeButton;
	QPushButton *learnModeButton;
	QPushButton *recordModeButton;
	QWidget *bottomFiller;
	QWidget *channelDisplay;
	QGridLayout *channellayout;
	LedIndicator *channelLEDs[8];
	
	QWidget *liveWidget;
	QGridLayout *livelayout;
	QWidget *plotWidget;
	QGridLayout *plotlayout;
	QWidget *oneplotWidget;
	QGridLayout *oneplotlayout;
	QLabel *NumDisplayLabel;
	QComboBox *NumDisplaySel;
	
	
	QWidget *learnWidget;
	
	
	QWidget *recordWidget;
	QGridLayout *recordlayout;
	QWidget *counterWidget;
	QGridLayout *counterlayout;
	QLabel *SelectMoveLabel;
	QComboBox *SelectMoveBox;
	QPushButton *RecordButton;
	QPushButton *SaveButton;
	QPushButton *DiscardButton;
	QPushButton *SetupButton;
	QLabel *CounterLabel;
	QLabel *MoveCounterLabels[8];
	QLineEdit *MoveCounters[8];
	QWidget *recordoneplotWidget;
	QGridLayout *recordoneplotlayout;
	QVector<double> recordx[8], recordy[8];
	QWidget *recordMiddleFiller;
	QWidget *counterMiddleFiller;
	QWidget *setupFiller;
	
	QWidget *setupWindow;
	QGridLayout *setuplayout;
	QLabel *SaveFileLabel;
	QWidget *SaveFileWidget;
	QGridLayout *savefilelayout;
	QLineEdit *SaveFileName;
	QPushButton *ChangeButton;
	QPushButton *NewButton;
	QLabel *MoveLabel;
	QLabel *ActiveLabel;
	QLabel *MoveNameLabel;
	QCheckBox *activeMoveSel[8];
	QLineEdit *MoveNames[8];
	QPushButton *MoveResetButtons[8];
	QPushButton *SetupSave;
	QPushButton *SetupClose;
	
private slots:
	void live_clicked();
	void learn_clicked();
	void record_clicked();
	void update_data();
	void change_plots(int index);
	void show_setup();
	void close_setup();
	void change_savefile();
	void new_savefile();
	void start_record_clicked();
	void save_record_clicked();
	void discard_record_clicked();
	void save_setup();
	void readDataBurst();
	void reset_clicked0();
	void reset_clicked1();
	void reset_clicked2();
	void reset_clicked3();
	void reset_clicked4();
	void reset_clicked5();
	void reset_clicked6();
	void reset_clicked7();
};


class MainWindow : public QMainWindow	{
	Q_OBJECT
public:
	explicit MainWindow(QMainWindow *parent = 0);
	QLabel *infoLabel;
	NetSettingsMenu net_settings_menu;
	IRModeWidget ir_mode_widget;
	NetModeWidget net_mode_widget;
	void send_data();
private:
	void createActions();
	void createMenus();
	
	QString projectfilename;
	QStringList projectfile;
	
	QMenu *FileMenu;
	QMenu *ModesMenu;
	QMenu *SettingsMenu;
	
	QAction *NewProjectAct;
	QAction *LoadProjectAct; 
	QAction *SaveProjectAct;
	QAction *SaveAsProjectAct;
	QAction *exitAct;
	
	QAction *IRAct;
	QAction *NetAct;
	QAction *NextModeAct;
	QAction *PreviousModeAct;
	
	QAction *NetSettingsAct;
	
	QWidget *Menus;
	QGridLayout *layout;
	
	
private slots:
	void NewProject();
	void LoadProject();
	void SaveProject();
	void SaveAsProject();
	
	
	void IRRemote();
	void NeuralNet();
	void NextMode();
	void PreviousMode();
	
	void NetSettings();
};














