#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(slot_pushbutton()));

    // 위와 다른 방식 , 인자가 없는 것에 대해서는 단점이 있다.
    // connect(ui->pushButton, &QPushButton::clicked, this, &Widget::slot_pushbutton);
}

void Widget::slot_pushbutton()
{
    qDebug() << Q_FUNC_INFO << "Hello World";
}

Widget::~Widget()
{
    delete ui;
}
