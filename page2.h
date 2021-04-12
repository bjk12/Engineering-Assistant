#ifndef PAGE2_H
#define PAGE2_H

#include <QDialog>

namespace Ui {
class page2;
}

class page2 : public QDialog
{
    Q_OBJECT

public:
    explicit page2(QWidget *parent = 0);
    ~page2();

private slots:
    void on_backButton_clicked();
    void on_timeout () ; //定时溢出处理槽函数
    void on_startButton_clicked();

    void on_suspendButton_clicked();

    void on_calculate51Button_clicked();

    void on_changetButton_clicked();

private:
    Ui::page2 *ui;
    void reject();
    QTimer* Timer1;
signals:
      void back2page1();
};

#endif // PAGE2_H
