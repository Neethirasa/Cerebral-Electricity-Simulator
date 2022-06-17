/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_8;
    QGroupBox *SimulatorView;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_7;
    QWidget *InfoDisplayGroup;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *BatteryBox;
    QSpacerItem *horizontalSpacer;
    QWidget *BatteryInfo;
    QHBoxLayout *_2;
    QLabel *BatteryLabel;
    QProgressBar *BatteryBar;
    QPushButton *PowerButton;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout;
    QLCDNumber *TimerDisplay;
    QGroupBox *SettingsDisplayGroup;
    QHBoxLayout *horizontalLayout_2;
    QLabel *FrequencyLabel;
    QLabel *WaveformLabel;
    QWidget *AmpSelectorGroup;
    QHBoxLayout *horizontalLayout_4;
    QProgressBar *AmpProgressBar;
    QPushButton *AmpDownButton;
    QPushButton *AmpUpButton;
    QHBoxLayout *SettingsBar;
    QGroupBox *TreatmentGroupBox;
    QVBoxLayout *verticalLayout_4;
    QPushButton *StartButton;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *RecordButton;
    QLabel *RecordIcon;
    QComboBox *RecordHistoryComboBox;
    QGroupBox *CycleGroup;
    QVBoxLayout *verticalLayout;
    QRadioButton *Min20RadioButton;
    QRadioButton *Min40RadioButton;
    QRadioButton *Min60RadioButton;
    QGroupBox *FrequencyGroup;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *Hz05RadioButton;
    QRadioButton *Hz77RadioButton;
    QRadioButton *Hz100RadioButton;
    QGroupBox *WaveFormGroup;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *AlphaRadioButtton;
    QRadioButton *BetaRadioButton;
    QRadioButton *GammaRadioButton;
    QGroupBox *AdminView;
    QVBoxLayout *verticalLayout_8;
    QGroupBox *ElectrodeGroup;
    QVBoxLayout *verticalLayout_5;
    QCheckBox *LeftEarCheck;
    QCheckBox *RightEarCheck;
    QPushButton *KillButton;
    QPushButton *ChargeUpButton;
    QPushButton *DecreaseBatteryButton;
    QPushButton *DecreaseBatteryButton_2;
    QPushButton *DecreaseTimeButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(858, 583);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(9, 0, 838, 522));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        SimulatorView = new QGroupBox(layoutWidget);
        SimulatorView->setObjectName(QString::fromUtf8("SimulatorView"));
        horizontalLayout_7 = new QHBoxLayout(SimulatorView);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        InfoDisplayGroup = new QWidget(SimulatorView);
        InfoDisplayGroup->setObjectName(QString::fromUtf8("InfoDisplayGroup"));
        verticalLayout_6 = new QVBoxLayout(InfoDisplayGroup);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        BatteryBox = new QHBoxLayout();
        BatteryBox->setObjectName(QString::fromUtf8("BatteryBox"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        BatteryBox->addItem(horizontalSpacer);

        BatteryInfo = new QWidget(InfoDisplayGroup);
        BatteryInfo->setObjectName(QString::fromUtf8("BatteryInfo"));
        _2 = new QHBoxLayout(BatteryInfo);
        _2->setObjectName(QString::fromUtf8("_2"));
        BatteryLabel = new QLabel(BatteryInfo);
        BatteryLabel->setObjectName(QString::fromUtf8("BatteryLabel"));
        BatteryLabel->setMaximumSize(QSize(180, 64));

        _2->addWidget(BatteryLabel);

        BatteryBar = new QProgressBar(BatteryInfo);
        BatteryBar->setObjectName(QString::fromUtf8("BatteryBar"));
        BatteryBar->setMinimumSize(QSize(180, 0));
        BatteryBar->setMaximumSize(QSize(180, 16777215));
        BatteryBar->setStyleSheet(QString::fromUtf8(""));
        BatteryBar->setValue(100);

        _2->addWidget(BatteryBar);


        BatteryBox->addWidget(BatteryInfo);

        PowerButton = new QPushButton(InfoDisplayGroup);
        PowerButton->setObjectName(QString::fromUtf8("PowerButton"));
        PowerButton->setMinimumSize(QSize(32, 32));
        PowerButton->setMaximumSize(QSize(32, 32));
        PowerButton->setStyleSheet(QString::fromUtf8(""));
        PowerButton->setCheckable(true);

        BatteryBox->addWidget(PowerButton);


        verticalLayout_6->addLayout(BatteryBox);

        widget_6 = new QWidget(InfoDisplayGroup);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        horizontalLayout = new QHBoxLayout(widget_6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        TimerDisplay = new QLCDNumber(widget_6);
        TimerDisplay->setObjectName(QString::fromUtf8("TimerDisplay"));
        TimerDisplay->setMinimumSize(QSize(0, 48));
        TimerDisplay->setDigitCount(8);
        TimerDisplay->setProperty("value", QVariant(0.000000000000000));

        horizontalLayout->addWidget(TimerDisplay);


        verticalLayout_6->addWidget(widget_6);

        SettingsDisplayGroup = new QGroupBox(InfoDisplayGroup);
        SettingsDisplayGroup->setObjectName(QString::fromUtf8("SettingsDisplayGroup"));
        horizontalLayout_2 = new QHBoxLayout(SettingsDisplayGroup);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        FrequencyLabel = new QLabel(SettingsDisplayGroup);
        FrequencyLabel->setObjectName(QString::fromUtf8("FrequencyLabel"));

        horizontalLayout_2->addWidget(FrequencyLabel);

        WaveformLabel = new QLabel(SettingsDisplayGroup);
        WaveformLabel->setObjectName(QString::fromUtf8("WaveformLabel"));

        horizontalLayout_2->addWidget(WaveformLabel);


        verticalLayout_6->addWidget(SettingsDisplayGroup);


        verticalLayout_7->addWidget(InfoDisplayGroup);

        AmpSelectorGroup = new QWidget(SimulatorView);
        AmpSelectorGroup->setObjectName(QString::fromUtf8("AmpSelectorGroup"));
        horizontalLayout_4 = new QHBoxLayout(AmpSelectorGroup);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        AmpProgressBar = new QProgressBar(AmpSelectorGroup);
        AmpProgressBar->setObjectName(QString::fromUtf8("AmpProgressBar"));
        AmpProgressBar->setMaximum(500);
        AmpProgressBar->setValue(0);

        horizontalLayout_4->addWidget(AmpProgressBar);

        AmpDownButton = new QPushButton(AmpSelectorGroup);
        AmpDownButton->setObjectName(QString::fromUtf8("AmpDownButton"));

        horizontalLayout_4->addWidget(AmpDownButton);

        AmpUpButton = new QPushButton(AmpSelectorGroup);
        AmpUpButton->setObjectName(QString::fromUtf8("AmpUpButton"));

        horizontalLayout_4->addWidget(AmpUpButton);


        verticalLayout_7->addWidget(AmpSelectorGroup);

        SettingsBar = new QHBoxLayout();
        SettingsBar->setObjectName(QString::fromUtf8("SettingsBar"));
        SettingsBar->setContentsMargins(16, 16, 16, 16);
        TreatmentGroupBox = new QGroupBox(SimulatorView);
        TreatmentGroupBox->setObjectName(QString::fromUtf8("TreatmentGroupBox"));
        TreatmentGroupBox->setMinimumSize(QSize(140, 140));
        verticalLayout_4 = new QVBoxLayout(TreatmentGroupBox);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(8, 8, 8, 8);
        StartButton = new QPushButton(TreatmentGroupBox);
        StartButton->setObjectName(QString::fromUtf8("StartButton"));
        StartButton->setCheckable(true);
        StartButton->setChecked(false);

        verticalLayout_4->addWidget(StartButton);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        RecordButton = new QPushButton(TreatmentGroupBox);
        RecordButton->setObjectName(QString::fromUtf8("RecordButton"));
        RecordButton->setCheckable(true);

        horizontalLayout_6->addWidget(RecordButton);

        RecordIcon = new QLabel(TreatmentGroupBox);
        RecordIcon->setObjectName(QString::fromUtf8("RecordIcon"));
        RecordIcon->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(RecordIcon);


        verticalLayout_4->addLayout(horizontalLayout_6);

        RecordHistoryComboBox = new QComboBox(TreatmentGroupBox);
        RecordHistoryComboBox->addItem(QString());
        RecordHistoryComboBox->setObjectName(QString::fromUtf8("RecordHistoryComboBox"));
        RecordHistoryComboBox->setCurrentText(QString::fromUtf8("Default Treatment"));

        verticalLayout_4->addWidget(RecordHistoryComboBox);


        SettingsBar->addWidget(TreatmentGroupBox);

        CycleGroup = new QGroupBox(SimulatorView);
        CycleGroup->setObjectName(QString::fromUtf8("CycleGroup"));
        verticalLayout = new QVBoxLayout(CycleGroup);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        Min20RadioButton = new QRadioButton(CycleGroup);
        Min20RadioButton->setObjectName(QString::fromUtf8("Min20RadioButton"));

        verticalLayout->addWidget(Min20RadioButton);

        Min40RadioButton = new QRadioButton(CycleGroup);
        Min40RadioButton->setObjectName(QString::fromUtf8("Min40RadioButton"));

        verticalLayout->addWidget(Min40RadioButton);

        Min60RadioButton = new QRadioButton(CycleGroup);
        Min60RadioButton->setObjectName(QString::fromUtf8("Min60RadioButton"));

        verticalLayout->addWidget(Min60RadioButton);


        SettingsBar->addWidget(CycleGroup);

        FrequencyGroup = new QGroupBox(SimulatorView);
        FrequencyGroup->setObjectName(QString::fromUtf8("FrequencyGroup"));
        verticalLayout_2 = new QVBoxLayout(FrequencyGroup);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        Hz05RadioButton = new QRadioButton(FrequencyGroup);
        Hz05RadioButton->setObjectName(QString::fromUtf8("Hz05RadioButton"));

        verticalLayout_2->addWidget(Hz05RadioButton);

        Hz77RadioButton = new QRadioButton(FrequencyGroup);
        Hz77RadioButton->setObjectName(QString::fromUtf8("Hz77RadioButton"));

        verticalLayout_2->addWidget(Hz77RadioButton);

        Hz100RadioButton = new QRadioButton(FrequencyGroup);
        Hz100RadioButton->setObjectName(QString::fromUtf8("Hz100RadioButton"));

        verticalLayout_2->addWidget(Hz100RadioButton);


        SettingsBar->addWidget(FrequencyGroup);

        WaveFormGroup = new QGroupBox(SimulatorView);
        WaveFormGroup->setObjectName(QString::fromUtf8("WaveFormGroup"));
        WaveFormGroup->setFlat(false);
        WaveFormGroup->setCheckable(false);
        WaveFormGroup->setChecked(false);
        verticalLayout_3 = new QVBoxLayout(WaveFormGroup);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        AlphaRadioButtton = new QRadioButton(WaveFormGroup);
        AlphaRadioButtton->setObjectName(QString::fromUtf8("AlphaRadioButtton"));

        verticalLayout_3->addWidget(AlphaRadioButtton);

        BetaRadioButton = new QRadioButton(WaveFormGroup);
        BetaRadioButton->setObjectName(QString::fromUtf8("BetaRadioButton"));

        verticalLayout_3->addWidget(BetaRadioButton);

        GammaRadioButton = new QRadioButton(WaveFormGroup);
        GammaRadioButton->setObjectName(QString::fromUtf8("GammaRadioButton"));

        verticalLayout_3->addWidget(GammaRadioButton);


        SettingsBar->addWidget(WaveFormGroup);


        verticalLayout_7->addLayout(SettingsBar);


        horizontalLayout_7->addLayout(verticalLayout_7);


        horizontalLayout_8->addWidget(SimulatorView);

        AdminView = new QGroupBox(layoutWidget);
        AdminView->setObjectName(QString::fromUtf8("AdminView"));
        AdminView->setMinimumSize(QSize(240, 240));
        AdminView->setMaximumSize(QSize(240, 16777215));
        verticalLayout_8 = new QVBoxLayout(AdminView);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        ElectrodeGroup = new QGroupBox(AdminView);
        ElectrodeGroup->setObjectName(QString::fromUtf8("ElectrodeGroup"));
        ElectrodeGroup->setMaximumSize(QSize(16777215, 180));
        verticalLayout_5 = new QVBoxLayout(ElectrodeGroup);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        LeftEarCheck = new QCheckBox(ElectrodeGroup);
        LeftEarCheck->setObjectName(QString::fromUtf8("LeftEarCheck"));

        verticalLayout_5->addWidget(LeftEarCheck);

        RightEarCheck = new QCheckBox(ElectrodeGroup);
        RightEarCheck->setObjectName(QString::fromUtf8("RightEarCheck"));

        verticalLayout_5->addWidget(RightEarCheck);


        verticalLayout_8->addWidget(ElectrodeGroup);

        KillButton = new QPushButton(AdminView);
        KillButton->setObjectName(QString::fromUtf8("KillButton"));

        verticalLayout_8->addWidget(KillButton);

        ChargeUpButton = new QPushButton(AdminView);
        ChargeUpButton->setObjectName(QString::fromUtf8("ChargeUpButton"));

        verticalLayout_8->addWidget(ChargeUpButton);

        DecreaseBatteryButton = new QPushButton(AdminView);
        DecreaseBatteryButton->setObjectName(QString::fromUtf8("DecreaseBatteryButton"));

        verticalLayout_8->addWidget(DecreaseBatteryButton);

        DecreaseBatteryButton_2 = new QPushButton(AdminView);
        DecreaseBatteryButton_2->setObjectName(QString::fromUtf8("DecreaseBatteryButton_2"));

        verticalLayout_8->addWidget(DecreaseBatteryButton_2);

        DecreaseTimeButton = new QPushButton(AdminView);
        DecreaseTimeButton->setObjectName(QString::fromUtf8("DecreaseTimeButton"));

        verticalLayout_8->addWidget(DecreaseTimeButton);


        horizontalLayout_8->addWidget(AdminView);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 858, 28));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        SimulatorView->setTitle(QApplication::translate("MainWindow", "CES", nullptr));
        BatteryLabel->setText(QApplication::translate("MainWindow", "Battery Label", nullptr));
        BatteryBar->setFormat(QApplication::translate("MainWindow", "Battery %p%", nullptr));
        PowerButton->setText(QApplication::translate("MainWindow", "\342\217\273", nullptr));
        SettingsDisplayGroup->setTitle(QApplication::translate("MainWindow", "Settings Display", nullptr));
        FrequencyLabel->setText(QApplication::translate("MainWindow", "Frequency Label", nullptr));
        WaveformLabel->setText(QApplication::translate("MainWindow", "WaveForm Label", nullptr));
        AmpProgressBar->setFormat(QApplication::translate("MainWindow", "%v amps", nullptr));
        AmpDownButton->setText(QApplication::translate("MainWindow", "Down-", nullptr));
        AmpUpButton->setText(QApplication::translate("MainWindow", "Up+", nullptr));
        TreatmentGroupBox->setTitle(QApplication::translate("MainWindow", "Treatment", nullptr));
        StartButton->setText(QApplication::translate("MainWindow", "Start/Stop Treatment", nullptr));
        RecordButton->setText(QApplication::translate("MainWindow", "Record", nullptr));
        RecordIcon->setText(QApplication::translate("MainWindow", "\342\254\244", nullptr));
        RecordHistoryComboBox->setItemText(0, QApplication::translate("MainWindow", "Default Treatment", nullptr));

        CycleGroup->setTitle(QApplication::translate("MainWindow", "Cycles", nullptr));
        Min20RadioButton->setText(QApplication::translate("MainWindow", "20 min", nullptr));
        Min40RadioButton->setText(QApplication::translate("MainWindow", "40 min", nullptr));
        Min60RadioButton->setText(QApplication::translate("MainWindow", "60 min", nullptr));
        FrequencyGroup->setTitle(QApplication::translate("MainWindow", "Frequency ", nullptr));
        Hz05RadioButton->setText(QApplication::translate("MainWindow", "0.5Hz", nullptr));
        Hz77RadioButton->setText(QApplication::translate("MainWindow", "77Hz", nullptr));
        Hz100RadioButton->setText(QApplication::translate("MainWindow", "100Hz", nullptr));
        WaveFormGroup->setTitle(QApplication::translate("MainWindow", "WaveForm", nullptr));
        AlphaRadioButtton->setText(QApplication::translate("MainWindow", "Alpha", nullptr));
        BetaRadioButton->setText(QApplication::translate("MainWindow", "Beta", nullptr));
        GammaRadioButton->setText(QApplication::translate("MainWindow", "Gamma", nullptr));
        AdminView->setTitle(QApplication::translate("MainWindow", "Admin", nullptr));
        ElectrodeGroup->setTitle(QApplication::translate("MainWindow", "Electrode Connections", nullptr));
        LeftEarCheck->setText(QApplication::translate("MainWindow", "Left Ear", nullptr));
        RightEarCheck->setText(QApplication::translate("MainWindow", "Right Ear", nullptr));
        KillButton->setText(QApplication::translate("MainWindow", "Kill Button", nullptr));
        ChargeUpButton->setText(QApplication::translate("MainWindow", "Charge Battery", nullptr));
        DecreaseBatteryButton->setText(QApplication::translate("MainWindow", "-1% Battery", nullptr));
        DecreaseBatteryButton_2->setText(QApplication::translate("MainWindow", "-10% Battery", nullptr));
        DecreaseTimeButton->setText(QApplication::translate("MainWindow", "-30 seconds", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
