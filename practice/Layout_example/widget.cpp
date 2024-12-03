#include "widget.h"
#include <QtWidgets>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QHBoxLayout *hboxLayout = new QHBoxLayout();
    QPushButton *hBtn[6];

    QString btnStr[6] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday","Saturday"};

    for(int i = 0; i < 6; i++){
        hBtn[i] = new QPushButton(btnStr[i]);
        hboxLayout->addWidget(hBtn[i]);
    }

    QVBoxLayout *vboxLayout = new QVBoxLayout();
    QPushButton *vBtn[3];
    QString btnStr2[3] = {"Movie", "Drama", "Animation"};

    for(int i = 0; i < 3; i++){
        vBtn[i] = new QPushButton(btnStr2[i]);
        vboxLayout->addWidget(vBtn[i]);
    }

    QGridLayout *gridLayout = new QGridLayout();
    QPushButton *gBtn[5];

    for(int i = 0; i < 5; i++){
        gBtn[i] = new QPushButton(btnStr[i]);
    }

    gridLayout->addWidget(gBtn[0], 0,0);
    gridLayout->addWidget(gBtn[1], 0,1);
    gridLayout->addWidget(gBtn[2], 1, 0, 1, 2);
    gridLayout->addWidget(gBtn[3], 2,0);
    gridLayout->addWidget(gBtn[4], 2,1);

    QVBoxLayout *defaultLayout = new QVBoxLayout();
    defaultLayout->addLayout(hboxLayout);
    defaultLayout->addLayout(vboxLayout);
    defaultLayout->addLayout(gridLayout);

    setLayout(defaultLayout);

}

Widget::~Widget() {}
