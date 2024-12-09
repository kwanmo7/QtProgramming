#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "QStandardItemModel"
#include "QTableView"
#include "QVBoxLayout"
#include "QDate"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
};
#endif // WIDGET_H
