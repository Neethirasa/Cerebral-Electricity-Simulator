#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "cranialelectricalsimulation.h"
#include <QMainWindow>
#include <QString>
#include <QLabel>
#include <QTimer>
using CES = CranialElectricalSimulation;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(CES * ces, QWidget *parent = nullptr);
    ~MainWindow();


    void setWaveform(wf w);
    void setFrequency(hz w);
    void setTime(QTime time);
    void setAmps(int ampValue);
    void setBattery(int batteryValue);

private:
    void updateCESAvailability(bool isAvailable);
    void time_step();

private slots:
    void on_PowerButton_toggled(bool checked);
    void RecordToggle(bool value);
    void killButtonPressed();

    void on_DecreaseBatteryButton_clicked();

    void on_DecreaseBatteryButton_2_clicked();

    void on_DecreaseTimeButton_clicked();

private:
    CES * ces;

    QTime timeout = QTime(0,0);
    QTime startTimeout = QTime(0,0);
    QTimer * time_step_timer;
    const QTime max_timeout = QTime(0,30);

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
