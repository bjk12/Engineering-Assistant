#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "page2.h"
#include "head.h"
int flag1=0,count=0,time11=0,time22=0,flagtime=0;
page2* dlg1;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dlg1=new page2(this);
    this->setWindowFlags(Qt::WindowMinMaxButtonsHint);
    //去掉最大化最小化按钮，保留关闭按钮
    this->setWindowFlags(Qt::WindowCloseButtonHint);
    QObject::connect(dlg1, &page2::back2page1, this, &MainWindow::show);
    ui->endButton->setEnabled(false);
//    int width=QApplication::desktop()->width();
//    int height=QApplication::desktop()->height();
    QDir *temp = new QDir;
    bool exist = temp->exists("./temp");
    if(exist)
    ;
//        QMessageBox::warning(this,tr("创建文件夹"),tr("文件夹已经存在！"));
    else
    {
        bool ok = temp->mkdir("./temp");
//        if( ok )
//            QMessageBox::warning(this,tr("创建文件夹"),tr("文件夹创建成功！"));
    }
    Timer1=new QTimer(this);
    Timer1->stop();
    Timer1->setInterval (1000) ;
    connect(Timer1,SIGNAL(timeout()),this,SLOT(on_timeout()));
    ui->m2Text->setReadOnly(true);
    ui->m3Text->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_conversionButton_clicked()
{
    if(ui->milEdit->text().isEmpty() && ui->mmEdit->text().isEmpty())
    {
        QMessageBox::about(NULL, "温馨提示", "请先在英制文本框或公制文本框中输入数字，再点击此按钮完成换算。");
    }
    else if(ui->milEdit->text().isEmpty())
        {
            double a=ui->mmEdit->text().toDouble()*39.37007874015748;
            ui->milEdit->setText(QString::number(a,'f',5));
        }
    else if(ui->mmEdit->text().isEmpty())
        {
            double a=ui->milEdit->text().toDouble()*0.0254;
            ui->mmEdit->setText(QString::number(a,'f',5));
        }
    else if(3==flag1)
    {
        double a=ui->mmEdit->text().toDouble()*39.37007874015748;
        ui->milEdit->setText(QString::number(a,'f',5));
    }
    else
    {
        double a=ui->milEdit->text().toDouble()*0.0254;
        ui->mmEdit->setText(QString::number(a,'f',5));
    }
}

void MainWindow::on_timeout()
{
    QTime T1=QTime::currentTime();
    int time0=3600*T1.hour()+60*T1.minute()+T1.second();
    if(time0>=time11 && time0<time22 && flagtime==0)
    {
        flagtime=1;
        CameraInit();
        CameraStart();
    }
    else if(time0>=time22 && flagtime==1)
    {
        flagtime=0;
        on_endButton_clicked();
    }
}

void MainWindow::on_milEdit_textEdited(const QString &arg1)
{
    if(arg1.toDouble()==0 && arg1.compare("0")!=0
            && arg1.compare("0.")!=0
            && arg1.compare("0.0")!=0
            && arg1.compare("0.00")!=0
            && arg1.compare("0.000")!=0
            && arg1.compare("0.0000")!=0
            && arg1.compare("0.00000")!=0
            && arg1.compare("0.000000")!=0
            && arg1.compare("0.0000000")!=0
            && arg1.compare("0.00000000")!=0
            && arg1.compare("0.000000000")!=0
            && arg1.compare("0.0000000000")!=0
            && arg1.compare("")!=0
            )
        QMessageBox::about(NULL, "温馨提示", "请输入有意义的数字。");
    else
        flag1=2;
}

void MainWindow::on_mmEdit_textEdited(const QString &arg1)
{
//    ui->milEdit->setFocusPolicy(Qt::NoFocus);
    if(arg1.toDouble()==0 && arg1.compare("0")!=0
            && arg1.compare("0.")!=0
            && arg1.compare("0.0")!=0
            && arg1.compare("0.00")!=0
            && arg1.compare("0.000")!=0
            && arg1.compare("0.0000")!=0
            && arg1.compare("0.00000")!=0
            && arg1.compare("0.000000")!=0
            && arg1.compare("0.0000000")!=0
            && arg1.compare("0.00000000")!=0
            && arg1.compare("0.000000000")!=0
            && arg1.compare("0.0000000000")!=0
            && arg1.compare("")!=0
            )
        QMessageBox::about(NULL, "温馨提示", "请输入有意义的数字。");
    else
    flag1=3;
}

void MainWindow::on_moreButton_clicked()
{
    dlg1->setModal(false);
    dlg1->show();
    this->hide();
}

void MainWindow::on_startButton_clicked()
{
    ui->startButton->setEnabled(false);
    ui->endButton->setEnabled(true);
    time11=3600*(ui->hour1->text().toInt())+60*(ui->minute1->text().toInt());
    time22=3600*(ui->hour2->text().toInt())+60*(ui->minute2->text().toInt());
    Timer1->start();
}

void MainWindow::on_endButton_clicked()
{
    Timer1->stop();
    if(flagtime==1)
    {
        flagtime=0;
    }
    CameraStop();
    ui->endButton->setEnabled(false);
    ui->startButton->setEnabled(true);
}

void MainWindow::on_screencutButton_clicked()
{
    QScreen *screen = QApplication::primaryScreen(); //获取当前程序的主窗口对象
    QPixmap map = screen->grabWindow(QApplication::desktop()->winId()); //调用主窗口对象的捕捉窗口图像，并传递桌面窗口的id号
    count++;
    QString str1="./temp/QM"+QString::number(count,10)+".jpg";
    map.save(str1,"jpg"); //保存图像
}

void MainWindow::on_jiaButton_clicked()
{
    QString Qkey="computer";
    QString m1=ui->m1Text->toPlainText();
    if(m1.isEmpty())
    {
        ui->m1Text->setPlainText("请输入数据。");
        return;
    }
    int nCount = m1.count();
    for(int i = 0 ; i < nCount ; i++)
    {
        QChar cha = m1.at(i);
        ushort uni = cha.unicode();
        if(uni >= 0x4E00 && uni <= 0x9FA5)
        {
            //这个字符是中文
            ui->m1Text->setPlainText("抱歉，目前无法加密汉字，请输入英文字母或数字。");;
            return;
        }
    }
    QByteArray byte = m1.toUtf8();
    if(ui->jiamifangshi->currentIndex()==0)
    {
        for(int i = 0; i < m1.size(); i++)
        {
            switch(int(byte.at(i)))
            {
                case 55:
                    {
                        byte[i]=int(byte.at(i))-7;
                        break;
                    }
                case 56:
                    {
                        byte[i]=int(byte.at(i))-7;
                        break;
                    }
                case 57:
                    {
                        byte[i]=int(byte.at(i))-7;
                        break;
                    }
                case 90:
                    {
                        byte[i]=int(byte.at(i))-23;
                        break;
                    }
                case 89:
                    {
                        byte[i]=int(byte.at(i))-23;
                        break;
                    }
                case 88:
                    {
                        byte[i]=int(byte.at(i))-23;
                        break;
                    }
                case 122:
                    {
                        byte[i]=int(byte.at(i))-23;
                        break;
                    }
                case 121:
                    {
                        byte[i]=int(byte.at(i))-23;
                        break;
                    }
                case 120:
                    {
                        byte[i]=int(byte.at(i))-23;
                        break;
                    }
                 default: byte[i]=int(byte.at(i))+3;
            }
        }
        ui->m2Text->setText(byte);
    }
    else if(ui->jiamifangshi->currentIndex()==1)
    {
        char *key = Qkey.toLatin1().data();
        Des->setKey(key);
        Des->encrypt(m1.toLatin1().data());
        QString endata = QString::fromLocal8Bit(Des->endata.c_str());
        ui->m2Text->setPlainText(endata);
    }
    else if(ui->jiamifangshi->currentIndex()==2)
    {
        int p=11,q=7,n=0,x1=0,x2=0,x4=0,x8=0;
        n=p*q;//e=11,d=3
        QByteArray c;
        c.resize(m1.size());
        for(int i = 0; i < m1.size(); i++)
        {
            if(int(byte.at(i))==32)
            {
                c[i]=32;
            }
            else
            {
                x1=(int(byte.at(i))-48)%n;
                x2=(x1*x1)%n;
                x4=(x2*x2)%n;
                x8=(x4*x4)%n;
                c[i]=(x1*x2*x8)%n+48;
            }
        }
        ui->m2Text->setText(c);
    }
}

void MainWindow::on_jieButton_clicked()
{
    QString Qkey="computer";
    QString m1=ui->m1Text->toPlainText();
    if(m1.isEmpty())
    {
        ui->m1Text->setPlainText("请输入数据");
        return;
    }
    QByteArray byte = m1.toUtf8();
    if(ui->jiamifangshi->currentIndex()==0)
    {
        for(int i = 0; i < m1.size(); i++)
        {
            switch(int(byte.at(i)))
            {
                case 48:
                    {
                        byte[i]=int(byte.at(i))+7;
                        break;
                    }
                case 49:
                    {
                        byte[i]=int(byte.at(i))+7;
                        break;
                    }
                case 50:
                    {
                        byte[i]=int(byte.at(i))+7;
                        break;
                    }
                case 65:
                    {
                        byte[i]=int(byte.at(i))+23;
                        break;
                    }
                case 66:
                    {
                        byte[i]=int(byte.at(i))+23;
                        break;
                    }
                case 67:
                    {
                        byte[i]=int(byte.at(i))+23;
                        break;
                    }
                case 97:
                    {
                        byte[i]=int(byte.at(i))+23;
                        break;
                    }
                case 98:
                    {
                        byte[i]=int(byte.at(i))+23;
                        break;
                    }
                case 99:
                    {
                        byte[i]=int(byte.at(i))+23;
                        break;
                    }
                 default: byte[i]=int(byte.at(i))-3;
            }
        }
        ui->m3Text->setText(byte);
    }
    else if(ui->jiamifangshi->currentIndex()==1)
    {
        char *key = Qkey.toLatin1().data();
        Des->setKey(key);
        Des->decrypt(m1.toLatin1().data());
        QString dedata = QString::fromLocal8Bit(Des->dedata.c_str());
        ui->m3Text->setPlainText(dedata);
    }
    else if(ui->jiamifangshi->currentIndex()==2)
    {
        int p=11,q=7,n=0,x1=0,x2=0,x4=0,x8=0;
        n=p*q;//e=11,d=3
        QByteArray c;
        c.resize(m1.size());
        for(int i = 0; i < m1.size(); i++)
        {
            if(int(byte.at(i))==32)
            {
                c[i]=32;
            }
            else
            {
                x1=int(byte.at(i)-48)%n;
                x2=(x1*x1)%n;
                x4=(x2*x2)%n;
                x8=(x4*x4)%n;
                c[i]=(x1*x2*x8)%n+48;
            }
        }
        ui->m3Text->setText(c);
    }
}
