#include <QCoreApplication>

#include "test.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Test test;

    //Connect the signal and the slot
    QObject::connect(&test,&Test::close,&a,&QCoreApplication::quit,Qt::QueuedConnection);

    test.dostuff();

    int value = a.exec();

    qInfo() << "Exit value:" << value;

    return value;
}
