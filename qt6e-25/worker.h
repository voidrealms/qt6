#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QMutex>
#include <QMutexLocker>
#include <QThread>
#include <QRunnable>
#include <QDebug>

class Worker : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);

signals:

public:
    void run() Q_DECL_OVERRIDE;

    void setCount(int *newCount);

    void setMutex(QMutex *newMutex);

private:
    int *m_count;
    QMutex *m_mutex;
};

#endif // WORKER_H
