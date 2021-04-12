#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "descrypt.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_conversionButton_clicked();
    void on_timeout () ; //定时溢出处理槽函数
    void on_milEdit_textEdited(const QString &arg1);

    void on_mmEdit_textEdited(const QString &arg1);

    void on_moreButton_clicked();

    void on_startButton_clicked();

    void on_endButton_clicked();

    void on_screencutButton_clicked();

    void on_jiaButton_clicked();

    void on_jieButton_clicked();

private:
    Ui::MainWindow *ui;
    QTimer* Timer1;
    DesCrypt* Des = new DesCrypt();
};

#endif // MAINWINDOW_H
