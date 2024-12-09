#include <QCoreApplication>
#include <QIODevice>
#include <QDataStream>
#include <QDebug>

QByteArray encoding()
{
    quint32 value1 = 123; // 4bytes
    quint8 value2 = 124; // 1bytes
    quint32 value3 = 125; // 4bytes

    QByteArray outData;
    QDataStream outStream(&outData, QIODevice::WriteOnly);

    outStream << value1;
    outStream << value2;
    outStream << value3;

    return outData;
}

void decoding(QByteArray _data)
{
    QByteArray inData = _data;
    QDataStream inStream(&inData, QIODevice::ReadOnly);

    quint32 value1; // 4bytes
    quint8 value2; // 1bytes;
    quint32 value3; // 4bytes;

    inStream >> value1;
    inStream >> value2;
    inStream >> value3;

    qDebug("[첫 번째 값 : %d] [두 번째 값 : %d] [세 번째 값 : %d]", value1, value2, value3);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QByteArray encData = encoding();

    qDebug() << "encData size : " << encData.size() << " Bytes";
    decoding(encData);

    return a.exec();
}
