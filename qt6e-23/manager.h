#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include <QThreadPool>
#include <QRunnable>
#include <QThread>
#include <QDebug>
#include "worker.h"

class Manager : public QObject
{
    Q_OBJECT
public:
    explicit Manager(QObject *parent = nullptr);

signals:
    void work(); //not the best way

public slots:
    void start();
    void started();
    void finished();

};

#endif // MANAGER_H
