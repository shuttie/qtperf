#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QScrollBar>
#include <stdio.h>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void runButtonPressed();
    void resetButtonPressed();

private:
    Ui::MainWindow *ui;
    float runTest(int testnum);
    float test_lineedit(int count);
    float test_combobox(int count);
    float test_comboboxentry(int count);
    float test_spinbox(int count);
    float test_progressbar(int count);
    float test_pushbutton(int count);
    float test_checkbox(int count);
    float test_radiobutton(int count);
    float test_textedit_add(int count);
    float test_textedit_scroll(int count);
    float test_qpainter_lines(int count);
    float test_qpainter_circles(int count);
    float test_qpainter_text(int count);
    float test_qpainter_image(int count);


};

#endif // MAINWINDOW_H
