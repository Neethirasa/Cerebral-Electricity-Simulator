#ifndef CRANIALELECTRICALSIMULATION_H
#define CRANIALELECTRICALSIMULATION_H

#include <QObject>
#include <QTime>
#include <QDateTime>
#include <vector>
#include <tuple>
#include <QtTest>

#include "enumtypes.h"
using wf = Waveform;
using hz = Frequency;

class CranialElectricalSimulation: public QObject
{
    Q_OBJECT
public:
    CranialElectricalSimulation();

    void setAmps(int a);
    int getAmps();

    void setWaveform(wf w);
    wf getWaveform();


    void setFrequency(hz f);
    hz getFrequency();

    void setTime(int m, int s=0);
    void setTime(QTime t);
    void timeStep();
    QTime getTime();

    void addToHistory();
    bool retrieveTreatment(int choice, std::tuple<QDateTime,QTime,int,wf,hz> &output);
    bool setTreatment(int choice);
    bool doTreatment();

    void setLeftNode(bool t);
    void setRightNode(bool t);
    bool checkNodeConnection();

    void updateLatestTimeStamp();
    QTime getLatestTimeStamp();

    bool getAvailability();
private:
    int battery = 100;
    int amps = 0;
    int elapsed_time_since_last_battery_decrease = 0;
    int elapsed_time_since_ear_disconnected = 0;

    bool left_node = false;
    bool right_node = false;

    wf waveform = wf::Alpha;
    hz frequency = hz::hz05;
    QTime time = QTime(0,0,0);
    QTime elapsed_time = QTime(0,0,0);
    QTime latest_update = QTime(0,0);
    const QTime max_latest_update = QTime(30,0);

    std::vector< std::tuple<QDateTime,QTime,int,wf,hz> > history;
    bool available = false;
    bool killed = false;
    bool treatmentOngoing = false;
    bool treatmentStartable = false;

    const int amp_increase = 50;
    const int amp_decrease = -100;
    const int amp_max = 500;
    const int amp_min = 0;
    const int battery_max = 100;
    const int battery_min = 0;
    const int battery_shutdown = 2;
    const int battery_second_per_percent = 10;
    const int ear_shutdown_time = 5;
    const QTime max_time = QTime(2,0);


public slots:
    void increaseAmps();
    void decreaseAmps();

    void decreaseBattery();
    void chargeBattery();
    void batteryTimeStep();

    bool startTreatment();
    bool interruptTreatment();

    void setCESAvailability(bool available);
    void killCES();

    void toggleLeftNode();
    void toggleRightNode();

signals:
    void waveformChanged(wf w);
    void frequencyChanged(hz f);
    void timeChanged(QTime t);
    void ampsChanged(int a);
    void batteryChanged(int b);
    void historyChanged(QDateTime,QTime,int,wf,hz);

    void earConnectionDisconnected();
    void earConnectionEstablished();

    void treatmentStarted();
    void treatmentEnded();
    void treatmentInterrupted();
    void CESDisabled();
    void CESAvailabilityChanged(bool isAvailable);

    void timeStampChanged(QTime t);


    friend class CESTests;
};

#endif // CRANIALELECTRICALSIMULATION_H
