#include "widget.h"
#include "QAbstractItemModel"
#include "QStringListModel"
#include "QListView"
#include "QModelIndex"
#include "QLabel"
#include "QVBoxLayout"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Model & View");

    resize(600,300);
    QStringList strList;
    strList << "월요일" << "화요일" << "수요일" << "목요일" << "금요일" << "토요일" << "일요일";

    QAbstractItemModel *model = new QStringListModel(strList);

    QListView *view = new QListView();
    view->setModel(model);

    QModelIndex index = model->index(3,0);
    QString text = model->data(index, Qt::DisplayRole).toString();

    QLabel *label = new QLabel(text);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(view);
    layout->addWidget(label);

    setLayout(layout);

}

Widget::~Widget() {}
