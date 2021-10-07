#include <QCoreApplication>
#include <QDebug>
#include <QRandomGenerator>
#include <QThread>
#include <QFuture>
#include <QtConcurrent>

void test()
{
    qInfo() << "Test" << QThread::currentThread();
}

int testRandom(int max)
{
    qInfo() << "Random" << QThread::currentThread();
    QThread::currentThread()->msleep(5000);
   return QRandomGenerator::global()->bounded(max);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main Thread");
    qInfo() << "Starting" << QThread::currentThread();

    QFuture<void> f1 = QtConcurrent::run(test);
    f1.waitForFinished();

    QFuture<int> f2 = QtConcurrent::run(testRandom,100);

    qInfo() << "Random: " << f2.result();

    qInfo() << "Finished" << QThread::currentThread();

    return a.exec();
}
