/*

Threaded Exmaple
Communicating between threads
Super simple

*/

#include <QCoreApplication>
#include <QThread>
#include "worker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread pThread;
    QThread cThread;

    Worker producer;
    Worker consumer;

    producer.moveToThread(&pThread);
    consumer.moveToThread(&cThread);

    producer.setProducer(true);

    pThread.setObjectName("Producer Thread");
    cThread.setObjectName("Consumer Thread");
    producer.setObjectName("Producer");
    consumer.setObjectName("Consumer");

    QObject::connect(&pThread,&QThread::started, &producer,&Worker::start);
    QObject::connect(&cThread,&QThread::started, &consumer,&Worker::start);

    QObject::connect(&producer,&Worker::produced,&consumer,&Worker::consume);
    QObject::connect(&producer,&Worker::finished,&consumer,&Worker::quit);

    cThread.start();
    pThread.start();

    return a.exec();
}
