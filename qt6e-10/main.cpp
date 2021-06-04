/*
    QStringView
    https://doc.qt.io/qt-5/qstringview.html#details

    A QStringView references a contiguous portion of a UTF-16 string it does not own.
    It acts as an interface type to all kinds of UTF-16 string, without the
    need to construct a QString first.

    Why: Its faster than copying a QString, and its read only!
 */


#include <QCoreApplication>

void readname(QString &name) //address of is access of
{
    name.insert(0,"Mr.");
    qInfo() << "Changed" << name;
}

void readonly(QStringView name)
{
    qInfo() << "name" << name.data() << name;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString firstname = "Bryan";
    QString lastname = "Cairns";

    //--- Copy and modification issues
    //readname(firstname);
    qInfo() << "Original" << firstname;

    //---Read only, no copy
    qInfo() << "name" << firstname.data() << firstname;
    readonly(firstname);

    //--- Basic parsing

    QString fullname = firstname + " " + lastname;

    foreach(QStringView part, QStringView(fullname).split(QChar(' ')))
    {
        qInfo() << "part" << part;
        //Data types can get a bit annoying
        if(part.startsWith(QStringView(firstname),Qt::CaseInsensitive))
        {
            qInfo() << "~First name detected~";
            readonly(QStringView(firstname).mid(1,3));
        }
    }








    return a.exec();
}
