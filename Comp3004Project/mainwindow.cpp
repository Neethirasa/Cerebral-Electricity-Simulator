#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "enumtypes.h"
#include <QDebug>
using wf = Waveform;
using hz = Frequency;
#include "cranialelectricalsimulation.h"

#include <iostream>

MainWindow::MainWindow(CES * ces, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , ces(ces)
{
    ui->setupUi(this);

    connect(ui->StartButton, &QPushButton::toggled, ces, [=](bool toggled){
        if (toggled) {ces->startTreatment(); ui->RecordHistoryComboBox->setEnabled(false);}
        else {ces->interruptTreatment(); ui->RecordHistoryComboBox->setEnabled(true);}
    });

    connect(ui->LeftEarCheck, &QCheckBox::toggled, ces, &CES::setLeftNode);
    connect(ui->RightEarCheck, &QCheckBox::toggled, ces, &CES::setRightNode);

    connect(ui->ChargeUpButton, &QPushButton::clicked, ces, &CES::chargeBattery);

    connect(ui->AmpUpButton, &QPushButton::clicked, ces, &CES::increaseAmps);
    connect(ui->AmpDownButton, &QPushButton::clicked, ces, &CES::decreaseAmps);

    connect(ui->AlphaRadioButtton,  &QRadioButton::clicked, this,   [=](){ces->setWaveform(wf::Alpha);});
    connect(ui->BetaRadioButton,    &QRadioButton::clicked, this,   [=](){ces->setWaveform(wf::Beta);});
    connect(ui->GammaRadioButton,   &QRadioButton::clicked, this,   [=](){ces->setWaveform(wf::Gamma);});

    connect(ui->Hz05RadioButton,    &QRadioButton::clicked, this,   [=](){ces->setFrequency(hz::hz05);});
    connect(ui->Hz77RadioButton,    &QRadioButton::clicked, this,   [=](){ces->setFrequency(hz::hz77);});
    connect(ui->Hz100RadioButton,   &QRadioButton::clicked, this,   [=](){ces->setFrequency(hz::hz100);});

    connect(ui->Min20RadioButton,   &QRadioButton::clicked, this,   [=](){ces->setTime(20);});
    connect(ui->Min40RadioButton,   &QRadioButton::clicked, this,   [=](){ces->setTime(40);});
    connect(ui->Min60RadioButton,   &QRadioButton::clicked, this,   [=](){ces->setTime(60);});

    connect(ui->RecordButton, &QPushButton::toggled, this, [=](bool toggled){ RecordToggle(toggled);if (!toggled) ces->addToHistory();});
    connect(ui->RecordHistoryComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [=](int index){
        ces->setTreatment(index-1);
    });

    connect(ces, &CES::waveformChanged, this, &MainWindow::setWaveform);
    connect(ces, &CES::frequencyChanged, this, &MainWindow::setFrequency);
    connect(ces, &CES::timeChanged, this, &MainWindow::setTime);
    connect(ces, &CES::ampsChanged, this, &MainWindow::setAmps);
    connect(ces, &CES::batteryChanged, this, &MainWindow::setBattery);
    connect(ces, &CES::CESAvailabilityChanged, this, &MainWindow::updateCESAvailability);
    connect(ces, &CES::earConnectionDisconnected, this, [=](){ui->ElectrodeLabel->setText("Electrodes: OFF");});
    connect(ces, &CES::earConnectionEstablished, this, [=](){ui->ElectrodeLabel->setText("Electrodes: ON");});
    connect(ces, &CES::timeStampChanged, this, [=](QTime time){
        startTimeout = time;
        timeout = QTime(0,0);
    });


    connect(ces, &CES::treatmentInterrupted, this, [=](){
        ui->RecordButton->setChecked(false);
        ui->StartButton->setChecked(false);
    });
    connect(ces, &CES::treatmentEnded, this, [=](){
        ui->RecordButton->setChecked(false);
        ui->StartButton->setChecked(false);
    });
    connect(ces, &CES::historyChanged, this, [=](QDateTime dt, QTime t, int amp, wf w, hz f){
        QString s;
        s += (dt.toString("yyyy/MM/dd-hh:mm")) + ", ";
        s += t.toString("H:mm:ss") + ", ";
        s += QString::number(amp) + " amps, ";
        switch (w) {
            case wf::Alpha:
                s += "Alpha, ";
                break;
            case wf::Beta:
                s += "Beta, ";
                break;
            case wf::Gamma:
                s += "Gamma, ";
                break;
        }
        switch (f) {
            case hz::hz05:
                s += "0.5hz";
                break;
            case hz::hz77:
                s += "77hz";
                break;
            case hz::hz100:
                s += "100hz";
                break;
        }
        ui->RecordHistoryComboBox->addItem(s);
    });

    ces->chargeBattery();
    ui->AlphaRadioButtton->click();
    ui->Hz05RadioButton->click();
    ui->Min20RadioButton->click();
    ui->LeftEarCheck->click();
    ui->RightEarCheck->click();
    ui->LeftEarCheck->click();
    ui->RightEarCheck->click();
    ces->setAmps(100);
    ces->setCESAvailability(false);

    connect(ui->KillButton, SIGNAL(released()),this, SLOT(killButtonPressed()));


    time_step_timer = new QTimer(this);
    connect(time_step_timer, &QTimer::timeout, this, &MainWindow::time_step);
    time_step_timer->start(1000);

}

MainWindow::~MainWindow()
{
    delete time_step_timer;
    delete ui;
}

void MainWindow::on_PowerButton_toggled(bool checked)
{
    ces->setCESAvailability(checked);
}

void MainWindow::RecordToggle(bool value)
{
    ui->RecordIcon->setStyleSheet(value ? "color: Red" : "color: Black");
}

void MainWindow::setWaveform(wf w)
{
    QString text("Waveform: ");
    switch (w) {
    case wf::Alpha:
        text += "Alpha";
        break;
    case wf::Beta:
        text += "Beta";
        break;
    case wf::Gamma:
        text += "Gamma";
        break;
    }
    ui->WaveformLabel->setText(text);
}

void MainWindow::setFrequency(hz f)
{
    QString text("Frequency: ");
    switch (f) {
    case hz::hz05:
        text += "0.5Hz";
        break;
    case hz::hz77:
        text += "77Hz";
        break;
    case hz::hz100:
        text += "100Hz";
        break;
    }
    ui->FrequencyLabel->setText(text);
}

void MainWindow::setTime(QTime t)
{

    QString timeString;
    timeString += QString::number(t.minute() + t.hour()*60) + " ";
    timeString += t.toString("ss");
    ui->TimerDisplay->display(timeString);
}

void MainWindow::setAmps(int ampValue)
{
    ui->AmpProgressBar->setValue(ampValue);
}

void MainWindow::setBattery(int batteryValue)
{
    ui->BatteryBar->setValue(batteryValue);

    if (batteryValue > 5){
        ui->BatteryLabel->setText("Battery %");
    }
    if (batteryValue <= 5){
       ui->BatteryLabel->setText("Warning Charge Device.");
    }
    if (batteryValue <= 2){
       ui->BatteryLabel->setText("Danger Charge Device!");
    }
    if (batteryValue < 2){
       ui->BatteryLabel->setText("Charge Battery!");
    }

}
void MainWindow::killButtonPressed() {
    ces->killCES();
    ui->PowerButton->setEnabled(false);
}

void MainWindow::updateCESAvailability(bool isAvailable) {

    if(!isAvailable) {
        ui->StartButton->setChecked(false);
        ui->RecordButton->setChecked(false);
    }

    ui->FrequencyGroup->setEnabled(isAvailable);
    ui->WaveFormGroup->setEnabled(isAvailable);
    ui->CycleGroup->setEnabled(isAvailable);
    ui->AmpSelectorGroup->setEnabled(isAvailable);
    ui->TreatmentGroupBox->setEnabled(isAvailable);
    ui->BatteryInfo->setEnabled(isAvailable);
    ui->CycleGroup->setEnabled(isAvailable);
    ui->TimerDisplay->setEnabled(isAvailable);
    ui->SettingsDisplayGroup->setEnabled(isAvailable);

}

void MainWindow::time_step()
{
    ces->timeStep();
    if(ces->getAvailability()){
        timeout = timeout.addSecs(1);
        int s = QTime(0,0).secsTo(timeout);
        QTime endTime = startTimeout.addSecs(s);
        int diffTime = startTimeout.secsTo(endTime);
        int compTime = QTime(0,0).secsTo(max_timeout) - diffTime;

        if(compTime <= 0){
            ces->setCESAvailability(false);
        }
    }
}


void MainWindow::on_DecreaseBatteryButton_clicked()
{
    ces->decreaseBattery();
}

void MainWindow::on_DecreaseBatteryButton_2_clicked()
{
    for (int i = 0; i < 10; ++i) {
        ces->decreaseBattery();
    }
}

void MainWindow::on_DecreaseTimeButton_clicked()
{
    for (int i = 0; i < 30; ++i) {
        time_step();
    }
}
