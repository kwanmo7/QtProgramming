#include <QCoreApplication>
#include <QTemporaryDir>
#include <QTemporaryFile>
#include <QDebug>

void createTempFile(){
    QString fileName;

    fileName = QDir::tempPath() + "/" + "MY_TEMP.txt";

    qDebug() << "Temp File Dir & File Name : " << fileName;

    QTemporaryFile tempFile(fileName);
    tempFile.setAutoRemove(false); // temp 파일의 자동 삭제 방지 / 기본적으로 QTemporaryFile을 생성한 함수가 끝날때 자동적으로 삭제됨

    tempFile.open();

    tempFile.write("Hello world");
    tempFile.flush();

    tempFile.close();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    createTempFile();

    return a.exec();
}
