#include "worker.h"

Worker::Worker(QObject *parent) : QObject(parent)
{
    qInfo() << this << Q_FUNC_INFO << QThread::currentThread();
}

Worker::~Worker()
{
    qInfo() << this << Q_FUNC_INFO << QThread::currentThread();
}

void Worker::run()
{
    qInfo() << this << Q_FUNC_INFO << QThread::currentThread();

    qInfo() << this << "Starting..." << QThread::currentThread();

    QScopedPointer<QEventLoop> loop(new QEventLoop);
    QScopedPointer<QTimer> timer(new QTimer);

    timer->setInterval(5000);

    connect(timer.data(),&QTimer::timeout, this,&Worker::work, Qt::DirectConnection);
    connect(this,&Worker::finished, loop.data(),&QEventLoop::quit, Qt::DirectConnection);

    timer->start();
    loop->exec(); //Block

    qInfo() << this << "Finished" << QThread::currentThread();
}

void Worker::work()
{
    qInfo() << this << Q_FUNC_INFO << QThread::currentThread();

    //TO DO - do something cool here

    emit finished();
}
