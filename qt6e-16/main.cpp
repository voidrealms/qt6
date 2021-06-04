/*

    Determining the OS

    At Compile Time
    Q_OS_WIN
    Q_OS_MACOS
    Q_OS_LINUX
    https://doc.qt.io/qt-6/qtglobal.html

    At Run Time
    QSystemInfo
    https://doc.qt.io/qt-6/qsysinfo.html


*/

#include <QCoreApplication>
#include <QDebug>
#include <QSysInfo>

void compileTime()
{
#ifdef Q_OS_MACOS
    qDebug() << "This is Mac";
#endif

#ifdef Q_OS_LINUX
    qDebug() << "This is Linux";
#endif

#ifdef Q_OS_WIN
    qDebug() << "This is Windows";

#ifdef #Q_OS_WIN32
    qDebug() << "This is Windows 32 bit";
#endif

#ifdef #Q_OS_WIN64
    qDebug() << "This is Windows 64 bit";
#endif
#endif
}

void runTime()
{
    QSysInfo info;
    qInfo() << "prettyProductName:" << info.prettyProductName();
    qInfo() << "productType:" <<  info.productType();
    qInfo() << "productVersion:" <<  info.productVersion();
    qInfo() << "machineHostName:" <<  info.machineHostName();
    qInfo() << "machineUniqueId:" <<  info.machineUniqueId();
    qInfo() << "currentCpuArchitecture:" <<  info.currentCpuArchitecture();
    qInfo() << "buildCpuArchitecture:" <<  info.buildCpuArchitecture();
    qInfo() << "buildAbi:" <<  info.buildAbi();

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //--- At Compile time
    compileTime();


    //--- At Run time
    runTime();

    return a.exec();
}
