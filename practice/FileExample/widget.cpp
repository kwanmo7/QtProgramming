#include "widget.h"
#include "ui_widget.h"

#include <QDataStream>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowTitle("QFile Example");

    connect(ui->btnSave, SIGNAL(pressed()), this, SLOT(slot_btnFileSave()));

    connect(ui->btnRead, SIGNAL(pressed()), this, SLOT(slot_btnFileRead()));

    m_file = new QFile();
}

void Widget::slot_btnFileSave()
{
    QString fileName;
    fileName = QString("../../price.data"); // 파일 Dir

    m_file->setFileName(fileName); // 파일 생성
    if(!m_file->open(QIODevice::WriteOnly | QIODevice::Truncate)){
        qDebug() << "File open fail";
        return;
    }else{
        qint32 keyboardPrice = ui->leKeyboard->text().toInt(); // ui에서 값을 가져옴
        qint32 monitorPrice = ui->leMonitor->text().toInt();

        QDataStream out(m_file); // ui에서 가져온 값을 file에 씀
        out << keyboardPrice;
        out << monitorPrice;

        m_file->close();
    }
}

void Widget::slot_btnFileRead()
{
    if(!m_file->open(QIODevice::ReadOnly)){
        qDebug() << "File open fail";
        return;
    }else{
        qint32 keyboardPrice;
        qint32 monitorPrice;

        QDataStream in(m_file); // 파일로 부터 값을 가져옴
        in >> keyboardPrice;
        in >> monitorPrice;

        m_file->close();

        // 가져온 값이 int형이기 때문에 string으로 변환
        QString str1 = QString("키보드가격 : %L1").arg(keyboardPrice);
        QString str2 = QString("모니터가격 : %L1").arg(monitorPrice);

        // 가져온 값을 ui에 출력
        ui->textEdit->clear();
        ui->textEdit->append(str1);
        ui->textEdit->append(str2);
    }
}

Widget::~Widget()
{
    delete ui;
}
