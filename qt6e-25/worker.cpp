#include "worker.h"

Worker::Worker(QObject *parent) : QObject(parent)
{

}


void Worker::run()
{
    //Threadpool runs this code

    for(int i = 0; i < 10; i++)
    {
        //m_mutex->lock();
        QMutexLocker locker(m_mutex); //Lock - pay attention to SCOPE
        int value = *m_count;
        value++;
        *m_count = value; //DANGER!!!!

        qInfo() << QThread::currentThread() << *m_count;
        //unlock
        //m_mutex->unlock();
    }

    qInfo() << QThread::currentThread() << "Done";
}

void Worker::setCount(int *newCount)
{
    m_count = newCount;
}

void Worker::setMutex(QMutex *newMutex)
{
    m_mutex = newMutex;
}
