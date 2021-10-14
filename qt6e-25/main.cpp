/*

  Mutex and Mutex locker

  When threads share resources
  Because some people want to watch the world burn
 */

#include <QCoreApplication>
#include <QThread>
#include <QThreadPool>
#include <QMutex>
#include <QDebug>
#include "worker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int count = 0; //Shared resource
    int max = 5000; //Number of threads

    QMutex mutex;

    for(int i = 0; i < max; i++)
    {
        Worker *worker = new Worker();
        worker->setCount(&count);
        worker->setMutex(&mutex);
        worker->setAutoDelete(true);

        QThreadPool::globalInstance()->start(worker);
    }

    QThreadPool::globalInstance()->waitForDone();
    qInfo() << "Count:" << count;


    return a.exec();
}
