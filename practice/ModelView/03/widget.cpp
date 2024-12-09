#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Model & View");

    resize(600,300);

    QStandardItemModel *model = new QStandardItemModel(0,3);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Subject"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Description"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));

    model->setVerticalHeaderItem(0, new QStandardItem("1"));
    model->setVerticalHeaderItem(1, new QStandardItem("2"));

    model->setData(model->index(0,0), "Monitor");
    model->setData(model->index(0, 1), "LG LED 27 inch");
    model->setData(model->index(0,2), QDate(2024, 12, 9));

    model->setData(model->index(1,0), "CPU");
    model->setData(model->index(1,1), "Intel 13th Gen");
    model->setData(model->index(1,2), QDate(2024, 12, 9));

    QTableView *view = new QTableView();
    view->setModel(model);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(view);

    setLayout(layout);

}

Widget::~Widget() {}
