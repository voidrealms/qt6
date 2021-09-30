#include "worker.h"

Worker::Worker(QObject *parent) : QObject(parent)
{
    qInfo() << "Created" << this << QThread::currentThread();
}

Worker::~Worker()
{
    qInfo() << "Destroyed" << this << QThread::currentThread();
}

void Worker::work()
{
    qInfo() << "Work" << this << QThread::currentThread();
}

void Worker::run()
{
    //Starting in the thread
    qInfo() << "Starting" << this << QThread::currentThread();
    emit started();

    for(int i = 0; i < 5; i++)
    {
        qInfo() << "Running" << this << QThread::currentThread();
        QThread::currentThread()->msleep(1000);
    }

    qInfo() << "Finishing" << this << QThread::currentThread();
    emit finished();
    //Finishing in the thread
}
