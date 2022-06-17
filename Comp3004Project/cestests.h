#ifndef CESTESTS_H
#define CESTESTS_H

#include <QtTest/QtTest>
#include "cranialelectricalsimulation.h"
#include <QDebug>
#include <QObject>
using CES = CranialElectricalSimulation;
class CESTests: public QObject
{
    Q_OBJECT
public:
    CES ces;
    CESTests(){
        QTest::qExec(this);
    }
private slots:
    void initTestCase(){
        qDebug("Testing CES Model");
    }

    void ampTest();
    void waveformTest();
    void frequencyTest();
    void earNodeTest();
    void timeTest();
    void batteryTest();
    void availabilityTest();

    void cleanupTestCase(){}
    void init(){}
    void cleanup(){}

};

#endif // CESTESTS_H

