#include "cestests.h"

void CESTests::ampTest(){
    QVERIFY(ces.getAmps() == 0);
    ces.increaseAmps();
    QVERIFY(ces.getAmps() == 50);
    ces.decreaseAmps();
    QVERIFY(ces.getAmps() == 0);
    ces.increaseAmps();
    ces.increaseAmps();
    ces.increaseAmps();
    QVERIFY(ces.getAmps() == 150);
    ces.increaseAmps();
    ces.increaseAmps();
    ces.decreaseAmps();
    QVERIFY(ces.getAmps() == 150);
    ces.increaseAmps();
    ces.increaseAmps();
    ces.increaseAmps();
    ces.increaseAmps();
    QVERIFY(ces.getAmps() == 350);
    ces.increaseAmps();
    ces.increaseAmps();
    ces.increaseAmps();
    ces.increaseAmps();
    QVERIFY(ces.getAmps() == 500);
    ces.decreaseAmps();
    QVERIFY(ces.getAmps() == 400);
    ces.decreaseAmps();
    QVERIFY(ces.getAmps() == 300);
    ces.decreaseAmps();
    QVERIFY(ces.getAmps() == 200);
    ces.decreaseAmps();
    QVERIFY(ces.getAmps() == 100);
    ces.decreaseAmps();
    QVERIFY(ces.getAmps() == 0);
    ces.decreaseAmps();
    ces.setAmps(31);
    QVERIFY(ces.getAmps() == 31);
    ces.setAmps(-10);
    QVERIFY(ces.getAmps() == 0);
    ces.setAmps(510);
    QVERIFY(ces.getAmps() == 500);
}

void CESTests::waveformTest()
{
    ces.setWaveform(wf::Alpha);
    QVERIFY(ces.getWaveform() == wf::Alpha);
    ces.setWaveform(wf::Beta);
    QVERIFY(ces.getWaveform() == wf::Beta);
    ces.setWaveform(wf::Gamma);
    QVERIFY(ces.getWaveform() == wf::Gamma);
}

void CESTests::frequencyTest()
{
    ces.setFrequency(hz::hz05);
    QVERIFY(ces.getFrequency() == hz::hz05);
    ces.setFrequency(hz::hz77);
    QVERIFY(ces.getFrequency() == hz::hz77);
    ces.setFrequency(hz::hz100);
    QVERIFY(ces.getFrequency() == hz::hz100);
}

void CESTests::earNodeTest()
{
    ces.setLeftNode(true);
    ces.setRightNode(true);
    QVERIFY(ces.checkNodeConnection() == true);
    ces.setRightNode(false);
    QVERIFY(ces.checkNodeConnection() == false);
    ces.setLeftNode(false);
    QVERIFY(ces.checkNodeConnection() == false);
    ces.setLeftNode(true);
    QVERIFY(ces.checkNodeConnection() == false);
    ces.setRightNode(true);
    QVERIFY(ces.checkNodeConnection() == true);

}

void CESTests::timeTest()
{
    ces.setCESAvailability(true);
    ces.setTime(0,0);
    QVERIFY(ces.getTime() == QTime(0,0));
    ces.setTime(1,0);
    QVERIFY(ces.getTime() == QTime(0,1));
    ces.setTime(1,30);
    QVERIFY(ces.getTime() == QTime(0,1,30));
    ces.setTime(60,30);
    QVERIFY(ces.getTime() == QTime(1,0,30));
    ces.setTime(120,30);
    QVERIFY(ces.getTime() == QTime(2,0,0));
    ces.setTime(1,0);
    ces.timeStep();
    QVERIFY(ces.getTime() == QTime(0,1,0));
    ces.setTime(1,0);
    ces.treatmentOngoing = true;
    ces.timeStep();
    QVERIFY(ces.getTime() == QTime(0,0,59));
    ces.timeStep();
    QVERIFY(ces.getTime() == QTime(0,0,58));
    ces.setTime(0,0);
    ces.timeStep();
    QVERIFY(ces.getTime() == QTime(0,0));
}

void CESTests::batteryTest()
{
    ces.chargeBattery();
    QVERIFY(ces.battery == 100);
    ces.decreaseBattery();
    QVERIFY(ces.battery == 99);
    ces.battery = 3;
    ces.decreaseBattery();
    QVERIFY(ces.battery == 2);
    ces.decreaseBattery();
    QVERIFY(ces.battery == 1);
    ces.decreaseBattery();
    QVERIFY(ces.battery == 0);
    ces.decreaseBattery();
    QVERIFY(ces.battery == 0);
    ces.chargeBattery();
    QVERIFY(ces.battery == 100);
}

void CESTests::availabilityTest()
{
    ces.battery = 100;
    ces.setCESAvailability(true);
    QVERIFY(ces.available == true);
    ces.setCESAvailability(false);
    QVERIFY(ces.available == false);
    ces.setCESAvailability(true);
    ces.battery = 3;
    ces.decreaseBattery();
    QVERIFY(ces.available == true);
    ces.decreaseBattery();
    QVERIFY(ces.available == false);
    ces.setCESAvailability(true);
    QVERIFY(ces.available == false);
    ces.battery = 100;
    ces.setCESAvailability(true);
    QVERIFY(ces.available == true);
    ces.killCES();
    QVERIFY(ces.available == false);
    ces.setCESAvailability(true);
    QVERIFY(ces.available == false);
    ces.killed = false;
    ces.battery = 100;
    ces.setCESAvailability(true);
    QVERIFY(ces.available == true);
}
