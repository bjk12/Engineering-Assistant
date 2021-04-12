#include "page2.h"
#include "ui_page2.h"
int time1=0,time51=0,tt=0,th=0,tl=0;
page2::page2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::page2)
{
    ui->setupUi(this);
    Qt::WindowFlags flags= this->windowFlags();
    setWindowFlags(flags&~(
                           Qt::WindowContextHelpButtonHint|
                           Qt::WindowMaximizeButtonHint|
                           Qt::WindowMinimizeButtonHint|
                           Qt::WindowCloseButtonHint)
                   );
    Timer1=new QTimer(this);
    Timer1->stop();
    Timer1->setInterval (1000) ;
    connect(Timer1,SIGNAL(timeout()),this,SLOT(on_timeout()));
    ui->suspendButton->setEnabled(false);
    ui->donetimeEdit->setReadOnly(true);
    ui->h51->setReadOnly(true);
    ui->l51->setReadOnly(true);
    ui->c2Text->setReadOnly(true);
}

page2::~page2()
{
    delete ui;
}

void page2::reject()
{
}
void page2::on_backButton_clicked()
{
    this->accept();
    emit back2page1();
}
void page2::on_startButton_clicked()
{
    QString m1=ui->settimeEdit->text();
    if(m1.isEmpty())
    {
        ui->settimeEdit->setText("请输入数据");
        return;
    }
    time1=ui->settimeEdit->text().toInt();
    if(time1==0)
    {
        ui->settimeEdit->setText("请输入有意义的数字");
        return;
    }
    ui->startButton->setEnabled(false);
    ui->suspendButton->setEnabled(true);
    ui->donetimeEdit->clear();
    tt=0;
    Timer1->start();
}

void page2::on_suspendButton_clicked()
{
    Timer1->stop();
    ui->startButton->setEnabled(true);
    ui->suspendButton->setEnabled(false);
}
void page2::on_timeout()
{
    tt++;
    ui->settimeEdit->setText(QString::number(time1-tt));
    ui->donetimeEdit->setText(QString::number(tt,10));
    if(tt>=time1)
    {
        this->on_suspendButton_clicked();
    }
}

void page2::on_calculate51Button_clicked()
{
    if(ui->combo51Box->currentIndex()==0)
    {
        time51=ui->set51time->text().toInt();
        if(time51<=65536)
        {
            th=(65536-time51)/256;
            tl=(65536-time51)%256;
            ui->h51->setText(QString("0x%1").arg(th,2,16, QLatin1Char('0')));
            ui->l51->setText(QString("0x%1").arg(tl,2,16, QLatin1Char('0')));
        }
        else
        {
            QApplication::setQuitOnLastWindowClosed(false);//防止消息框退出界面
            QMessageBox::about(NULL, "温馨提示", "设定时间过长。");
        }
    }
    else if(ui->combo51Box->currentIndex()==1)
    {
        time51=ui->set51time->text().toInt();
        if(time51<=256)
        {
            th=256-time51;
            tl=256-time51;
            ui->h51->setText(QString("0x%1").arg(th,2,16, QLatin1Char('0')));
            ui->l51->setText(QString("0x%1").arg(tl,2,16, QLatin1Char('0')));
        }
        else
        {
            QApplication::setQuitOnLastWindowClosed(false);
            QMessageBox::about(NULL, "温馨提示", "设定时间过长。");
        }
    }
}

void page2::on_changetButton_clicked()
{
    QString m1=ui->c1Text->toPlainText();
    if(m1.isEmpty())
    {
        ui->c1Text->setPlainText("请输入数据");
        return;
    }
    int Number=ui->c1Text->document()->lineCount(); //读取TextEdit里的行数
    m1.clear();
    for(int n=0;n<Number;n++)
    {
        m1.append(ui->c1Text->toPlainText().section('\n',n-Number,n-Number,QString::SectionSkipEmpty)); //取得每行（以换行符进行换行）;
    }
    ui->c2Text->setPlainText(m1);
}
