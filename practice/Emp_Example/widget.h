#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    typedef struct _tEmployee{
        int num;
        QString name;
        QString part;
    } tEmployee;

    QList<tEmployee> m_employeeList;

private:
    Ui::Widget *ui;

private slots:
    void slot_btnSave();
    void slot_btnPrint();
};

#endif // WIDGET_H
