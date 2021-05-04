#include "browser.h"
#include "browserwindow.h"
#include "webview.h"
#include <QApplication>
#include <QWebEngineSettings>

QUrl getCommandLineUrlArgument() {
  const QStringList args = QCoreApplication::arguments();
  if (args.count() > 1)
    return QUrl::fromUserInput(args.last());
  return QUrl();
}

int main(int argc, char **argv) {
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);

  QApplication app(argc, argv);
  app.setWindowIcon(QIcon(QStringLiteral(":AppLogoColor.png")));

  QWebEngineSettings::defaultSettings()->setAttribute(
      QWebEngineSettings::PluginsEnabled, true);

  QUrl url = getCommandLineUrlArgument();
  if (!url.isValid())
    url = QStringLiteral("https://www.qt.io");

  Browser browser;
  BrowserWindow *window = browser.createWindow();
  window->currentTab()->setUrl(url);

  return app.exec();
}
