#include <QCoreApplication>
#include <QIODevice>
#include <QTextStream>
#include <QDebug>

QByteArray write(QByteArray _data){

    QByteArray temp = _data; // "Hello world." 12Bytes
    QByteArray data;
    QTextStream textStream(&data, QIODevice::WriteOnly);

    for(qsizetype i = 0; i < temp.size(); i++){
        textStream << temp.at(i);
    }
    textStream.flush();

    return data;
}

void read(QByteArray _data){
    QByteArray inData;
    QTextStream textStream(&_data, QIODevice::ReadOnly);

    for(qsizetype i = 0; i < _data.size(); i++){
        char data;
        textStream >> data;
        inData.append(data);
    }

    qDebug("READ DATA : [%s]", inData.data());
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QByteArray data = write("Hello world.");
    qDebug() << "write data size : " << data.size() << " Bytes";
    read(data);

    return a.exec();
}
