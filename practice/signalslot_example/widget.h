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

private:
    Ui::Widget *ui;

signals:
    void sig_textChanged(QString str);

private slots:
    void slot_valueChanged(int val);
    void slot_textChanged(QString str);
};
#endif // WIDGET_H
