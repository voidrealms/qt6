/*

Thread pools
Fast
Efficient
Easy

*/

#include <QCoreApplication>
#include <QThread>
#include "manager.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main Thread");
    Manager manager;
    manager.start();

    return a.exec();
}
