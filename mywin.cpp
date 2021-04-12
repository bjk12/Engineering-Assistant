#include "mywin.h"
#include <QApplication>
#include <QScreen>
#include <QDesktopWidget>
#include <QBuffer>
#include <QFile>
#include <QDebug>
#include <windows.h>
#include <QDateTime>
MyWin::MyWin(std::wstring _processName, std::wstring _parentName, std::string _pathName, int _fps)
{
    m_processName = _processName;
    m_parentName  = _parentName;
    m_pathName    = _pathName;
    m_fps         = _fps;
    m_timer       = new QTimer;
    m_hwnd        = 0;
    connect(m_timer, SIGNAL(timeout()), this, SLOT(Timer2()));
}
MyWin::~MyWin()
{
    if (m_avi)
    {
        AVI_close(m_avi);
    }
}
void MyWin::Start()
{
    //get window handle.
    m_hwnd = FindWindow(NULL, m_processName.c_str());
    //use system time and file name to creat file.
    m_pathName = "./" + m_pathName + " " + QDateTime::currentDateTime().toString("yyyy-MM-dd hh-mm-ss").toStdString() + ".avi";
    m_avi = AVI_open_output_file(const_cast<char*>(m_pathName.c_str()));
    //adjust the screenshot size.
    RECT rect;
    ::GetWindowRect(m_hwnd, &rect);
    AVI_set_video(m_avi, rect.right - rect.left, rect.bottom - rect.top, m_fps, "mjpg");
    //screenshot 1000/m_fps times per second.
    m_timer->start(1000 / m_fps);
}
void MyWin::Stop()
{
    m_timer->stop();
    AVI_close(m_avi);
}
void MyWin::Timer2()
{
    //get window wid.
    QScreen *screen = QApplication::primaryScreen();
    QPixmap map     = screen->grabWindow(WId(m_hwnd));
    //begin screenshot.
    QByteArray ba;
    QBuffer    bf(&ba);
    if (!map.save(&bf, "jpg",100))
    {
        exit(0);
    }
    //write in file.
    AVI_write_frame(m_avi, ba.data(), ba.size(), 1);
}
