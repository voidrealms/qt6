#ifndef CAT_H
#define CAT_H

#include <QObject>
#include <QDebug>

class Cat : public QObject
{
    Q_OBJECT
public:
    explicit Cat(QObject *parent = nullptr);
    ~Cat();

    QString name() const;
    void setName(const QString &name);

    int age() const;
    void setAge(int age);

signals:

private:
    QString m_name;
    int m_age;

};

#endif // CAT_H
