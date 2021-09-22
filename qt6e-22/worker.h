#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <QTimer>
#include <QRandomGenerator>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);

    bool producer() const;
    void setProducer(bool newProducer);

signals:
    void produced(int value);
    void finished();

public slots:
    void consume(int value);
    void start();
    void quit();

private:
    QTimer *m_timer; //Timers can not be started from another thread
    bool m_producer;
    int m_count;

    void timeout();

};

#endif // WORKER_H
