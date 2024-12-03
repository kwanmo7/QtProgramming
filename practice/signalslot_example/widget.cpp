#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 슬라이더에서 첫번째 텍스트 박스에 값을 넣어주는 것을 연결
    connect(ui->hSlider, SIGNAL(valueChanged(int)), this, SLOT(slot_valueChanged(int)));

    // 첫번째 텍스트 박스에 값을 두번째 텍스트 박스에 넣어주는 것을 연결
    connect(this, SIGNAL(sig_textChanged(QString)), this, SLOT(slot_textChanged(QString)));

    // 위의 소스와 같음, 작성 방식의 차이, 함수가 여러개인 경우 사용하지 못함
//  connect(this, &Widget::sig_textChanged, this, &Widget::slot_textChanged);
}

// 슬라이더에서 첫번째 텍스트 박스에 값을 설정
void Widget::slot_valueChanged(int val)
{
    QString str = QString("%1").arg(val);
    ui->leText->setText(str);

    emit sig_textChanged(str); // signal 호출
}

// 첫번째 텍스트 박스의 값을 두번째 텍스트 박스에 값을 설정
void Widget::slot_textChanged(QString str)
{
    ui->leTextCopy->setText(str);
}

Widget::~Widget()
{
    delete ui;
}
