/*

    Testing different ways of threading
    Pros and cons of each
    GUI Exmaple

*/

#include <QCoreApplication>
#include <QDebug>
#include <QThread>
#include <QThreadPool>
#include <QTimer>
#include <QtConcurrent>
#include "worker.h"

void testMain()
{
    qInfo() << "Testing on main";

    Worker* worker = new Worker();
    worker->run();
    worker->deleteLater();
    qInfo() << "Testing...";

}

void testThread()
{
    QThread* thread = new QThread();
    thread->setObjectName("Worker Thread");
    qInfo() << "Testing on Worker Thread";
    Worker* worker = new Worker();

    worker->moveToThread(thread);

    QObject::connect(thread,&QThread::started,worker,&Worker::run);
    QObject::connect(worker,&Worker::finished,worker,&Worker::deleteLater);
    QObject::connect(worker,&Worker::finished,thread,&QThread::quit);
    QObject::connect(thread,&QThread::finished,thread,&QThread::deleteLater);

    thread->start();

    qInfo() << "Testing...";
}

void testPool()
{
    qInfo() << "Testing on Thread Pool";
    Worker* worker = new Worker();
    worker->setAutoDelete(true);
    QThreadPool::globalInstance()->start(worker);

    qInfo() << "Testing...";
}

void testConcurrent()
{
    qInfo() << "Testing on Concurrent";
    QScopedPointer<Worker> worker(new Worker);
    worker->run();
    qInfo() << "Testing...";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main Thread");

    //testMain();
    //testThread();
    //testPool();
    QtConcurrent::run(&testConcurrent);


    qInfo() << "Finished in" << QThread::currentThread();

    return a.exec();
}
