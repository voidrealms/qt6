#include "kitten.h"

Kitten::Kitten(QObject *parent) : QObject(parent)
{

}

void Kitten::meow()
{
    qWarning() << "I am hungry";
}
