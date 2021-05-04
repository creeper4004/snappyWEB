#ifndef BROWSER_H
#define BROWSER_H

#include "downloadmanagerwidget.h"

#include <QVector>
#include <QWebEngineProfile>

class BrowserWindow;

class Browser
{
public:
    Browser();

    QVector<BrowserWindow*> windows() { return m_windows; }

    BrowserWindow *createWindow(bool offTheRecord = false);

    DownloadManagerWidget &downloadManagerWidget() { return m_downloadManagerWidget; }

private:
    QVector<BrowserWindow*> m_windows;
    DownloadManagerWidget m_downloadManagerWidget;
    QWebEngineProfile m_otrProfile;
};
#endif // BROWSER_H
