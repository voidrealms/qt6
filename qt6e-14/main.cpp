/*
 QTextStream
 Viewer request: please show the Qt way of doing user input and output
 Facebook group: voidrealms
 */

#include <QCoreApplication>
#include <QTextStream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //--- QTextStream
    QTextStream qin(stdin);
    QTextStream qout(stdout);

    //--- endl
    qout << "Please enter your name:" << Qt::endl;

    //---Reading
    QString name = qin.readLine();

    //--- Flushing
    qout << "You entered: " << name << "\n";
    qout << "Enter your age:\n";
    qout.flush();

    //---Example
    bool ok;
    int age = qin.readLine().toInt(&ok);

    if(ok)
    {
        qout << "You are " << age << " years old";
    }
    else
    {
        qout << "You have failed to enter a valid number!!!!!!!";
    }
    qout.flush();

    return a.exec();
}
