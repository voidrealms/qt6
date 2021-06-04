/*
  Qt memory managment
  Parent child relationship
*/

#include <QCoreApplication>
#include <QTimer>
#include "test.h"

//Setting in the constructor
Test* getTest(QObject* parent)
{
    return new Test(parent);
}

//Setting up after constructor
Test* getTest()
{
    return new Test(); //No parent
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTimer timer;
    timer.singleShot(3000,&a,&QCoreApplication::quit);

    //Setting in the constructor
    Test* dog = getTest(&a);
    dog->setObjectName("Spot");

    //Setting up after constructor
    Test* cat = getTest();
    cat->setObjectName("Princess");
    cat->setParent(dog);

    int value = a.exec();
    qInfo() << "Exit code:" << value;
    return value;
}
