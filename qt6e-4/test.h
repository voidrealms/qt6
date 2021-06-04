#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QDebug>

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = nullptr);

signals:
    void close();

public slots:
    void dostuff();

};

#endif // TEST_H
