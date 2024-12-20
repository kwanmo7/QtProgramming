#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "QSplitter"
#include "QFileSystemModel"
#include "QTreeView"
#include "QListView"
#include "QVBoxLayout"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
};
#endif // WIDGET_H
