#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->buttonReset,SIGNAL(clicked()),this,SLOT(resetButtonPressed()));
    connect(ui->buttonRun,SIGNAL(clicked()),this,SLOT(runButtonPressed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resetButtonPressed() {
    ui->spinRounds->setValue(100);
    ui->comboTests->setCurrentIndex(0);
    ui->textConsole->clear();
}

void MainWindow::runButtonPressed() {
    int index = ui->comboTests->currentIndex();
    if (index != 0)
	runTest(index);
    else {
	float all = 0;
	for (int i=1; i<=14; ++i)
	    all += runTest(i);
	printf("Total: %f ms\n\n", all);
	ui->textConsole->append(QString("Total: %1 ms").arg(all));
    }
    ui->tabMain->setCurrentIndex(0);
}

float MainWindow::runTest(int testnum) {
    int tests = ui->spinRounds->value();
    QString line;
    float result;
    switch (testnum) {
    case 1:
	result = test_lineedit(tests);
	line = QString("QLineEdit - %1 s").arg(result);
	break;
    case 2:
	result = test_combobox(tests);
	line = QString("QComboBox - %1 s").arg(result);
	break;
    case 3:
	result = test_comboboxentry(tests);
	line = QString("QComboBoxEntry - %1 s").arg(result);
	break;
    case 4:
	result = test_spinbox(tests);
	line = QString("QSpinBox - %1 s").arg(result);
	break;
    case 5:
	result = test_progressbar(tests);
	line = QString("QProgressBar - %1 s").arg(result);
	break;
    case 6:
	result = test_pushbutton(tests);
	line = QString("QPushButton - %1 s").arg(result);
	break;
    case 7:
	result = test_checkbox(tests);
	line = QString("QCheckbox - %1 s").arg(result);
	break;
    case 8:
	result = test_radiobutton(tests);
	line = QString("QRadioButton - %1 s").arg(result);
	break;
    case 9:
	result = test_textedit_add(tests);
	line = QString("QTextEdit - Add text - %1 s").arg(result);
	break;
    case 10:
	result = test_textedit_scroll(tests);
	line = QString("QTextEdit - Scroll - %1 s").arg(result);
	break;
    case 11:
	result = test_qpainter_lines(tests);
	line = QString("QPainter - Lines - %1 s").arg(result);
	break;
    case 12:
	result = test_qpainter_circles(tests);
	line = QString("QPainter - Circles - %1 s").arg(result);
	break;
    case 13:
	result = test_qpainter_text(tests);
	line = QString("QPainter - Text - %1 s").arg(result);
	break;
    case 14:
	result = test_qpainter_image(tests);
	line = QString("QPainter - Pixmap - %1 s").arg(result);
	break;
    default:
	// what?
	break;
    }
    printf("%s\n",qPrintable(line));
    ui->textConsole->append(line);
    return result;
}

float MainWindow::test_lineedit(int count) {
    ui->tabMain->setCurrentIndex(1);
    QTime start = QTime::currentTime();
    for (int i=0; i<count; ++i) {
	ui->testLineEdit->setText("Test String");
	ui->testLineEdit->repaint();
	ui->testLineEdit->setText("Longer test string");
	ui->testLineEdit->repaint();
    }
    return (float)start.msecsTo(QTime::currentTime())/1000.0f;
}

float MainWindow::test_combobox(int count) {
    ui->tabMain->setCurrentIndex(1);
    QTime start = QTime::currentTime();
    int index=0;
    for (int i=0; i<count; ++i) {
	ui->testComboBox->showPopup();
	ui->testComboBox->repaint();
	QApplication::processEvents();
	index = ui->testComboBox->currentIndex();
	if (index == 9)
	    ui->testComboBox->setCurrentIndex(0);
	else
	    ui->testComboBox->setCurrentIndex(index++);
	ui->testComboBox->repaint();
	QApplication::processEvents();
	ui->testComboBox->hidePopup();
	ui->testComboBox->repaint();
	QApplication::processEvents();
    }
    return (float)start.msecsTo(QTime::currentTime())/1000.0f;
}

float MainWindow::test_comboboxentry(int count) {
    ui->tabMain->setCurrentIndex(1);
    QTime start = QTime::currentTime();
    int index=0;
    for (int i=0; i<count; ++i) {
	ui->testComboBoxEd->showPopup();
	ui->testComboBoxEd->repaint();
	QApplication::processEvents();
	index = ui->testComboBoxEd->currentIndex();
	if (index == 9)
	    ui->testComboBoxEd->setCurrentIndex(0);
	else
	    ui->testComboBoxEd->setCurrentIndex(index++);
	ui->testComboBoxEd->repaint();
	QApplication::processEvents();
	ui->testComboBoxEd->hidePopup();
	ui->testComboBoxEd->repaint();
	QApplication::processEvents();
    }
    return (float)start.msecsTo(QTime::currentTime())/1000.0f;
}

float MainWindow::test_spinbox(int count) {
    ui->tabMain->setCurrentIndex(1);
    QTime start = QTime::currentTime();
    int index=0;
    for (int i=0; i<count; ++i) {
	index = ui->testSpinBox->value();
	if (index==ui->testSpinBox->maximum())
	    index = 0;
	else
	    index++;
	ui->testSpinBox->setValue(index);
	ui->testSpinBox->repaint();
    }
    return (float)start.msecsTo(QTime::currentTime())/1000.0f;
}

float MainWindow::test_progressbar(int count) {
    ui->tabMain->setCurrentIndex(1);
    QTime start = QTime::currentTime();
    int index=0;
    for (int i=0; i<count; ++i) {
	index = ui->testProgressBar->value();
	if (index == ui->testProgressBar->maximum())
	    index = 0;
	else
	    index++;
	ui->testProgressBar->setValue(index);
	ui->testProgressBar->repaint();
    }
    return (float)start.msecsTo(QTime::currentTime())/1000.0f;
}

float MainWindow::test_pushbutton(int count) {
    ui->tabMain->setCurrentIndex(2);
    QTime start = QTime::currentTime();
    for (int i=0; i<count; ++i) {
	ui->testButton->setDown(!ui->testButton->isDown());
	ui->testButton->repaint();
    }
    return (float)start.msecsTo(QTime::currentTime())/1000.0f;
}

float MainWindow::test_checkbox(int count) {
    ui->tabMain->setCurrentIndex(2);
    QTime start = QTime::currentTime();
    for (int i=0; i<count; ++i) {
	ui->testCheckBox->setChecked(!ui->testCheckBox->isChecked());
	ui->testCheckBox->repaint();
    }
    return (float)start.msecsTo(QTime::currentTime())/1000.0f;
}

float MainWindow::test_radiobutton(int count) {
    ui->tabMain->setCurrentIndex(2);
    QTime start = QTime::currentTime();
    bool flag = true;
    for (int i=0; i<count; ++i) {
	ui->testRadioButton1->setChecked(flag);
	ui->testRadioButton2->setChecked(!flag);
	ui->testRadioButton1->repaint();
	ui->testRadioButton2->repaint();
	flag = !flag;
    }
    return (float)start.msecsTo(QTime::currentTime())/1000.0f;
}

float MainWindow::test_textedit_add(int count) {
    ui->tabMain->setCurrentIndex(3);
    QTime start = QTime::currentTime();
    for (int i=0; i<count; ++i) {
	ui->testTextEdit->insertPlainText("Future is open. ");
	ui->testTextEdit->repaint();
    }
    return (float)start.msecsTo(QTime::currentTime())/1000.0f;
}

float MainWindow::test_textedit_scroll(int count) {
    ui->tabMain->setCurrentIndex(3);
    QTime start = QTime::currentTime();
    int step = 1;
    for (int i=0; i<count; ++i) {
	if (ui->testTextEdit->verticalScrollBar()->value() == ui->testTextEdit->verticalScrollBar()->maximum())
	    step = -1;
	if (ui->testTextEdit->verticalScrollBar()->value() == ui->testTextEdit->verticalScrollBar()->minimum())
	    step = 1;
	ui->testTextEdit->verticalScrollBar()->setValue(ui->testTextEdit->verticalScrollBar()->value() + step);
	ui->testTextEdit->repaint();
    }
    return (float)start.msecsTo(QTime::currentTime())/1000.0f;
}

float MainWindow::test_qpainter_lines(int count) {
    ui->tabMain->setCurrentIndex(4);
    QTime start = QTime::currentTime();
    ui->testDrawWidget->setType(TestWidget::TEST_LINES);
    for (int i=0; i<count*1000; ++i) {
	ui->testDrawWidget->repaint();
    }
    ui->testDrawWidget->type = TestWidget::TEST_IDLE;
    return (float)start.msecsTo(QTime::currentTime())/1000.0f;
}

float MainWindow::test_qpainter_circles(int count) {
    ui->tabMain->setCurrentIndex(4);
    QTime start = QTime::currentTime();
    ui->testDrawWidget->setType(TestWidget::TEST_CIRCLES);
    for (int i=0; i<count*1000; ++i) {
	ui->testDrawWidget->repaint();
    }
    ui->testDrawWidget->type = TestWidget::TEST_IDLE;
    return (float)start.msecsTo(QTime::currentTime())/1000.0f;
}

float MainWindow::test_qpainter_text(int count) {
    ui->tabMain->setCurrentIndex(4);
    QTime start = QTime::currentTime();
    ui->testDrawWidget->setType(TestWidget::TEST_TEXT);
    for (int i=0; i<count*100; ++i) {
	ui->testDrawWidget->repaint();
    }
    ui->testDrawWidget->type = TestWidget::TEST_IDLE;
    return (float)start.msecsTo(QTime::currentTime())/1000.0f;
}

float MainWindow::test_qpainter_image(int count) {
    ui->tabMain->setCurrentIndex(4);
    QTime start = QTime::currentTime();
    ui->testDrawWidget->setType(TestWidget::TEST_PIXMAP);
    for (int i=0; i<count*10; ++i) {
	ui->testDrawWidget->repaint();
    }
    ui->testDrawWidget->type = TestWidget::TEST_IDLE;
    return (float)start.msecsTo(QTime::currentTime())/1000.0f;
}
