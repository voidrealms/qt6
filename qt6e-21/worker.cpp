#include "worker.h"

Worker::Worker(QObject *parent) : QObject(parent)
{
    qInfo() << this << "Constructed" << QThread::currentThread();
}

Worker::~Worker()
{
    qInfo() << this << "Deconstructed" << QThread::currentThread();
}

void Worker::run()
{
    for(int i = 0; i < 10; i++)
    {
        qInfo() << "Working" << QString::number(i) << QThread::currentThread();
        QThread::currentThread()->msleep(500);
    }

    this->deleteLater();
}
