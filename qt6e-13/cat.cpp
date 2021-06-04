#include "cat.h"

Cat::Cat(QObject *parent) : QObject(parent)
{
    qInfo() << this << "Constructed";
}

Cat::~Cat()
{
    qInfo() << this << "Deconstructed";
}

QString Cat::name() const
{
    return m_name;
}

void Cat::setName(const QString &name)
{
    m_name = name;
    setObjectName(m_name);
}

int Cat::age() const
{
    return m_age;
}

void Cat::setAge(int age)
{
    m_age = age;
}
