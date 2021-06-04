/*
 Intercepting QDebug

 https://doc-snapshots.qt.io/qt6-dev/qtglobal.html

 Message types
 https://doc-snapshots.qt.io/qt6-dev/qtglobal.html#QtMsgType-enum

 QtMessageHandler is a typedef
 https://doc-snapshots.qt.io/qt6-dev/qtglobal.html#QtMessageHandler-typedef

 qInstallMessageHandler installs the handler
 https://doc-snapshots.qt.io/qt6-dev/qtglobal.html#qInstallMessageHandler

 */

#include <QCoreApplication>
#include <QDebug>
#include <QTextStream>
#include <iostream>
#include "kitten.h"

using namespace std;

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    //Because we can intercept this from anywhere in the app, we can log to a file, or the system log

    QByteArray localMsg = msg.toLocal8Bit();
    const char *file = context.file ? context.file : "";
    const char *function = context.function ? context.function : "";
    switch (type) {
    case QtDebugMsg:
        fprintf(stderr, "Debug: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
        break;
    case QtInfoMsg:
        fprintf(stderr, "Info: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
        break;
    case QtWarningMsg:
        fprintf(stderr, "Warning: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
        break;
    case QtCriticalMsg:
        fprintf(stderr, "Critical: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
        break;
    case QtFatalMsg:
        fprintf(stderr, "Fatal: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
        break;
    }
}

void test()
{
    qDebug() << "test";
    qInfo() << "test";
    qWarning() << "test";
    qCritical() << "test";
    qFatal("fatal message");

    Kitten kitty;
    kitty.meow();
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //--- Setup (and copy the code)
    QTextStream qin(stdin);
    cout << "Starting" << endl;

    bool running = true;
    do
    {
        cout << "Enter a command (start, stop, test, or exit)" << endl;
        QString command = qin.readLine();
        qInfo() << "You entered:" << command;

        //--- Install
        if(command.toUpper() == "START") qInstallMessageHandler(myMessageOutput);

        //--- Uninstall
        if(command.toUpper() == "STOP") qInstallMessageHandler(0);

        //--- Test
        if(command.toUpper() == "TEST") test();

        //--- Exit the loop
        if(command.toUpper() == "EXIT") running = false;

    }while (running);


    cout << "Finished" << endl;

    return a.exec();
}
