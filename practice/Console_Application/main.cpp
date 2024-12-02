#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int myValue = 10;

    qDebug() << "Hello world. value : " << myValue;
    qDebug("Qt First Program, myValue : %d", myValue);

    return a.exec();
}
