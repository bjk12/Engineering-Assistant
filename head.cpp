#include "head.h"
#include "windows.h"
#include "mywin.h"
#include <QDebug>
MyWin*       g_myWin       = NULL;
std::wstring g_processName = L"ScreenRecord";
std::wstring g_parentName  = L"ScreenRecord";
std::string  g_pathName    = "QM";
int          g_fps         = 10;
bool         isStarted     = NULL;
int CameraInit()
{
    if (!g_myWin)
    {
        g_myWin = new MyWin(g_processName, g_parentName, g_pathName, g_fps);
    }
    return 1;
}
int CameraStart()
{
    if (!isStarted)
    {
        if (g_myWin)
        {
            g_myWin->Start();
            isStarted = true;
            return 1;
        }
    }
    return 0;
}
int CameraStop()
{
    if (isStarted)
    {
        if (g_myWin)
        {
            g_myWin->Stop();
            g_myWin = NULL;
            isStarted = false;
            return 1;
        }
    }
    return 0;
}
