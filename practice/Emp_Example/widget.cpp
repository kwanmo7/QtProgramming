#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->btnSave, SIGNAL(pressed()), this, SLOT(slot_btnSave()));
    connect(ui->btnPrint, SIGNAL(pressed()), this, SLOT(slot_btnPrint()));

}

void Widget::slot_btnSave()
{
    qDebug() << Q_FUNC_INFO;

    tEmployee employee;
    employee.num = ui->leNum->text().toInt();
    employee.name = ui->leName->text();
    employee.part = ui->lePart->text();

    m_employeeList.append(employee);

    ui->leNum->clear();
    ui->leName->clear();
    ui->lePart->clear();
}

void Widget::slot_btnPrint()
{
    qDebug() << Q_FUNC_INFO;

    ui->textEdit->clear();

    for(qsizetype i = 0; i < m_employeeList.size(); i++){
        int num = m_employeeList.at(i).num;
        QString name = m_employeeList.at(i).name;
        QString part = m_employeeList.at(i).part;

        QString str;
        str = QString("[사원번호: %1] [성명: %2] [부서: %3]").arg(num).arg(name, part);

        ui->textEdit->append(str);
    }

}

Widget::~Widget()
{
    delete ui;
}
