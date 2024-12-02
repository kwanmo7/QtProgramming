#include "widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(300, 200);

    m_str = QString("버튼");
    m_button = new QPushButton(m_str, this);
    m_button->setGeometry(10,10,100,30);

    // 버튼과 함수 연결
    connect(m_button, SIGNAL(pressed()), this, SLOT(slot_btn()));
}

void Widget::slot_btn()
{
    qDebug() << "Hello World, Button Click.";
}

Widget::~Widget()
{

}
