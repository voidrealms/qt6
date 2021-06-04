#include <QCoreApplication>

#include "cat.h"
#include <QDebug>

void test(Cat &cat)
{
    qInfo() << "Addr " << &cat;
}

void test2(Cat *cat)
{
    qInfo() << "Ptr " << cat;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Cat kitty;
    kitty.setObjectName("kitty");

    Cat death;
    death.setObjectName("Death");

    test(kitty);
    test2(&kitty);

    test(death);
    test2(&death);

    return a.exec();
}
