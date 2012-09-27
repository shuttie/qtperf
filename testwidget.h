#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include <QWidget>
#include <QPainter>
#include <stdio.h>

namespace Ui {
    class TestWidget;
}

class TestWidget : public QWidget
{
    Q_OBJECT

public:
    typedef enum {TEST_LINES, TEST_CIRCLES, TEST_TEXT, TEST_PIXMAP, TEST_IDLE} TestType;
    TestType type;
    explicit TestWidget(QWidget *parent = 0);
    void setType(TestType newtype);
    ~TestWidget();
protected:
    void paintEvent(QPaintEvent *);

private:
    QPixmap duck;
    Ui::TestWidget *ui;
    QColor randomColor();
};

#endif // TESTWIDGET_H
