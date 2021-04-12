#ifndef MYWIN_H
#define MYWIN_H
#include <QDialog>
#include "avilib.h"
class MyWin:public QDialog
{
    Q_OBJECT
public:
    MyWin(std::wstring _processName, std::wstring _parentName, std::string _pathName, int _fps);
    ~MyWin();
    std::wstring m_processName;
    std::wstring m_parentName;
    std::string m_pathName;
    int m_fps;
    QTimer* m_timer;
    HWND m_hwnd;
    avi_t* m_avi;
    void Start();
    void Stop();
private slots:
    void Timer2();
};
#endif // MYWIN_H
