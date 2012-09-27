#include "testwidget.h"
#include "ui_testwidget.h"

TestWidget::TestWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestWidget)
{
    ui->setupUi(this);
    type = TEST_IDLE;
    this->setAttribute(Qt::WA_NoBackground);
    this->setAttribute(Qt::WA_NoSystemBackground);
    duck.load(":/pixmaps/duck.png", "PNG");
}

TestWidget::~TestWidget()
{
    delete ui;
}

void TestWidget::paintEvent(QPaintEvent *) {
    QPainter painter;
    painter.begin(this);
    int w = this->width();
    int h = this->height();
    int s = 60;
    QColor color = randomColor();
    painter.setPen(color);
    painter.setBrush(QBrush(color));
    painter.setFont(QFont("Arial",16,QFont::Bold));

    switch (type) {
    case TEST_LINES:
	painter.drawLine(qrand() % w, qrand() % h, qrand() % w, qrand() % h);
	break;
    case TEST_CIRCLES:
	painter.drawEllipse(qrand() % w, qrand() % h, qrand() % s, qrand() % s);
	break;
    case TEST_TEXT:
	painter.drawText(qrand() % w, qrand() % h, "Future is open. ");
	break;
    case TEST_PIXMAP:
	painter.drawPixmap(qrand() % w, qrand() % h, duck);
	break;
    case TEST_IDLE:
	painter.setBrush(QBrush(Qt::white));
	painter.drawRect(0,0,w,h);
    }
    painter.end();
}

QColor TestWidget::randomColor()
{
    return QColor(qrand() % 255, qrand() % 255, qrand() % 255);
}

void TestWidget::setType(TestType newtype) {
    type = TEST_IDLE;
    repaint();
    type = newtype;
}
