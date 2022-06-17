#include "cranialelectricalsimulation.h"
#include <iostream>
#include <QDebug>
#include <QTimer>
#include <array>

CranialElectricalSimulation::CranialElectricalSimulation()
{
    using CES = CranialElectricalSimulation;
    connect(this, &CES::ampsChanged, this, &CES::updateLatestTimeStamp);
    connect(this, &CES::waveformChanged, this, &CES::updateLatestTimeStamp);
    connect(this, &CES::frequencyChanged, this, &CES::updateLatestTimeStamp);
    connect(this, &CES::timeChanged, this, &CES::updateLatestTimeStamp);
    connect(this, &CES::historyChanged, this, &CES::updateLatestTimeStamp);
    connect(this, &CES::CESAvailabilityChanged, this, &CES::updateLatestTimeStamp);
    connect(this, &CES::earConnectionDisconnected, this, &CES::updateLatestTimeStamp);
    connect(this, &CES::earConnectionEstablished, this, &CES::updateLatestTimeStamp);
    connect(this, &CES::treatmentStarted, this, &CES::updateLatestTimeStamp);
    connect(this, &CES::treatmentEnded, this, &CES::updateLatestTimeStamp);
    connect(this, &CES::treatmentInterrupted, this, &CES::updateLatestTimeStamp);
    connect(this, &CES::CESDisabled, this, &CES::updateLatestTimeStamp);
}

void CranialElectricalSimulation::setAmps(int a)
{
    if(a != amps){
        amps = a;
        amps = std::min(amp_max, amps);
        amps = std::max(amp_min, amps);
        emit ampsChanged(amps);
    }
}

int CranialElectricalSimulation::getAmps()
{
    return amps;
}

void CranialElectricalSimulation::setWaveform(wf w)
{
    waveform = w;
    emit waveformChanged(waveform);
}

wf CranialElectricalSimulation::getWaveform()
{
    return waveform;
}

void CranialElectricalSimulation::setFrequency(hz f)
{
    frequency = f;
    emit frequencyChanged(frequency);
}

hz CranialElectricalSimulation::getFrequency()
{
    return frequency;
}

void CranialElectricalSimulation::setTime(int m, int s)
{
    QTime t(0,0,0);
    t = t.addSecs(s + m*60);
    setTime(t);

}

void CranialElectricalSimulation::setTime(QTime t)
{
    time = QTime(t);
    if(time >= max_time){
        time = max_time;
    }
    if(time <= QTime(0,0,0)){
        time = QTime(0,0);
    }
    elapsed_time.setHMS(0,0,0);
    emit timeChanged(time);
}

void CranialElectricalSimulation::timeStep()
{
    if(treatmentOngoing){
        if(time == QTime(0,0)) return;
        time = time.addSecs(-1);
        elapsed_time = elapsed_time.addSecs(1);
        emit timeChanged(time);
    }
    batteryTimeStep();
}


QTime CranialElectricalSimulation::getTime()
{
    return time;
}

void CranialElectricalSimulation::addToHistory()
{
    if(elapsed_time.secsTo(QTime(0,0))==0) return;
    history.emplace_back(
                QDateTime::currentDateTime(), elapsed_time, amps, waveform, frequency
                );
    emit historyChanged(QDateTime::currentDateTime(),elapsed_time,amps,waveform,frequency);
}

bool CranialElectricalSimulation::retrieveTreatment(int choice, std::tuple<QDateTime, QTime, int, wf, hz> &output)
{
    if(choice > history.size() || choice < 0) return false;
    output = history[choice];
    return true;
}

bool CranialElectricalSimulation::startTreatment()
{
    treatmentOngoing = true;
    elapsed_time_since_ear_disconnected = 0;
    emit treatmentStarted();
    doTreatment();
}

bool CranialElectricalSimulation::interruptTreatment()
{
    treatmentOngoing = false;
    emit treatmentInterrupted();
}

void CranialElectricalSimulation::setCESAvailability(bool isAvailable)
{
    isAvailable = killed ? false : isAvailable;
    isAvailable = battery < battery_shutdown ? false : isAvailable;
    available = isAvailable;
    if(!isAvailable){
        interruptTreatment();
    }
    emit CESAvailabilityChanged(isAvailable);

}

void CranialElectricalSimulation::killCES()
{
    killed = true;
    setCESAvailability(false);
    emit CESDisabled();

}

void CranialElectricalSimulation::toggleLeftNode()
{
    left_node = !left_node;
}

void CranialElectricalSimulation::toggleRightNode()
{
    right_node = !right_node;
}

bool CranialElectricalSimulation::setTreatment(int choice)
{
    std::tuple<QDateTime, QTime, int, wf, hz> output ;
    if(retrieveTreatment(choice,output)){
        QTime t;
        int amps;
        wf waveform;
        hz frequency;
        std::tie(std::ignore, t, amps, waveform, frequency) = output;
        setAmps(amps);
        setTime(t);
        setWaveform(waveform);
        setFrequency(frequency);
        return true;
    }
    return false;
}

bool CranialElectricalSimulation::doTreatment()
{
    elapsed_time_since_ear_disconnected = checkNodeConnection() ? 0 : elapsed_time_since_ear_disconnected + 1;
    if(
            !treatmentOngoing ||
            time.msecsSinceStartOfDay() <= 0 ||
            elapsed_time_since_ear_disconnected >= ear_shutdown_time
            ) {
        treatmentOngoing = false;
        emit treatmentEnded();
        return false;
    }
    else QTimer::singleShot(1000, this, &CranialElectricalSimulation::doTreatment);
    return true;
}

void CranialElectricalSimulation::setLeftNode(bool t)
{

    bool start = checkNodeConnection();
    left_node = t;
    bool end = checkNodeConnection();

    if(start != end){
        if(end) emit earConnectionEstablished();
        else emit earConnectionDisconnected();
    }
}

void CranialElectricalSimulation::setRightNode(bool t)
{
    bool start = checkNodeConnection();
    right_node = t;
    bool end = checkNodeConnection();

    if(start != end){
        if(end) emit earConnectionEstablished();
        else emit earConnectionDisconnected();
    }

}

bool CranialElectricalSimulation::checkNodeConnection()
{
    return left_node && right_node;
}

void CranialElectricalSimulation::updateLatestTimeStamp()
{
    latest_update = QTime::currentTime();
    emit timeStampChanged(latest_update);
}

QTime CranialElectricalSimulation::getLatestTimeStamp()
{
    return latest_update;
}

bool CranialElectricalSimulation::getAvailability()
{
    return available;
}


void CranialElectricalSimulation::increaseAmps()
{

      amps += amp_increase;
      amps = std::min(amps,amp_max);
      emit ampsChanged(amps);

}

void CranialElectricalSimulation::decreaseAmps()
{
    amps += amp_decrease;
    amps = std::max(amps,amp_min);
    emit ampsChanged(amps);
}

void CranialElectricalSimulation::chargeBattery() {
    battery = battery_max;
    emit batteryChanged(battery_max);
}

void CranialElectricalSimulation::batteryTimeStep()
{
    if(!available) return;
    elapsed_time_since_last_battery_decrease++;
    if(elapsed_time_since_last_battery_decrease >= battery_second_per_percent){
        elapsed_time_since_last_battery_decrease = 0;
        decreaseBattery();
    }
}

//battery decrease by 1% every battery_second_per_percent seconds
void CranialElectricalSimulation::decreaseBattery()
{
    battery--;
    if (battery < battery_shutdown ){
        battery = std::max(battery,0);
        setCESAvailability(false);
    }
    emit batteryChanged(battery);

}

