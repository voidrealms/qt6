/*
 QList
 https://doc.qt.io/qt-6.0/qlistwidget.html
 https://www.qt.io/blog/qlist-changes-in-qt-6

 QList is a templated container
 QList is not a QObject
 QList and QVector are the same thing
 No more 2 gb limit
 QList will auto resize itself
 QObjects and pointers need to be cleaned up
*/

#include <QCoreApplication>
#include <QRandomGenerator>
#include <QSharedPointer>
#include "test.h"

//--- Creating and adding data
QList<int> getNumbers()
{
    QList<int> list;

    //use the operator
    list << 300 << 400 << 500;

    int max = QRandomGenerator::global()->bounded(1,10);
    for(int i = 0; i < max; i++)
    {
        list.append(QRandomGenerator::global()->bounded(1,100));
    }

    return list;
}
void test_numbers()
{
    QList<int> list = getNumbers();
    qInfo() << list;

    qInfo() << "Length" << list.length(); //Same
    qInfo() << "Count" << list.count(); //Same
    qInfo() << "Size" << list.size(); //Same

    for(int i = 0; i < list.length(); i++)
    {
        qInfo() << i << "=" << list.at(i) << "or" << list[i];
    }

    qInfo() << "----------";
    foreach(int i, list)
    {
        qInfo() << i;
    }
}

//--- Modifying exiting data
void test_modifying()
{
    QList<int> list = getNumbers();



    //direct mod
    list[0] = 1000;
    //list.at(0) = 3000;

    //appending
    list.append(99);
    list << 2000 << 3000;

    //inserting
    list.insert(0,55);
    list.insert(1,22);
    list.insert(1,255);
    list.insert(1,255);
    list.insert(1,255);
    list.insert(1,255);
    list.insert(1,255);
    list.insert(1,255);
    list.insert(1,255);



    //Removing
    qInfo() << "Length" << list.length();
    list.removeAt(0);
    qInfo() << "RemoveAt" << list.length();
    list.removeOne(255);
    qInfo() << "RemoveOne" << list.length();
    list.removeAll(255);
    qInfo() << "RemoveAll" << list.length();
    list.remove(5,7);
    qInfo() << "Remove" << list.length();

    for(int i = 0; i < list.length(); i++)
     {
         qInfo() << i << "=" << list.at(i);
     }

}

//--- Searching ---
void test_search()
{
    QList<int> list = getNumbers();
    int item = 999;

    list.insert(0,item);
    list.insert(3,item);
    list.append(item);

    for(int i = 0; i < list.length(); i++)
    {
        qInfo() << i << "=" << list.at(i);
    }

    //First
    int fpos = list.indexOf(item);
    qInfo() << "First" << fpos;

    //Last
    int lpos = list.lastIndexOf(item);
    qInfo() << "Last" << lpos;


    //All
    int pos = list.indexOf(item);
    do
    {
        qInfo() << "At" << pos;
        pos = list.indexOf(item,pos + 1);
    } while(pos > -1);

    qInfo()  << "Contains" << list.contains(item);

    //Get a slice
    QList<int>  items = list.sliced(1,4);
    qInfo() << list;
    qInfo() << items;
}

//--- Memory considerations ---
void test_deleteall()
{
    QList<Test*> list;
    for(int i = 0; i < 5; i++)
    {
        list.append(new Test()); //Danger no parent
    }

    qInfo() << "Cleanup";
    qDeleteAll(list);
    list.clear();
    qInfo() << list.length();
}

void test_smart()
{
    QList<QSharedPointer<Test>> list;
    for(int i = 0; i < 5; i++)
    {
        QSharedPointer<Test> item(new Test); //Auto memory management
        list.append(item);
    }

    qInfo() << "Remove first";
    list.removeFirst();

    qInfo() << "Clear";
    list.clear();
    qInfo() << list.length();


}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //--- Creating and adding data
    //test_numbers();

    //--- Modifying exiting data
    //test_modifying();

    //--- Searching ---
    //test_search();

    //--- Memory considerations ---
    //test_deleteall();
    test_smart();

    return a.exec();
}
