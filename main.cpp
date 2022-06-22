#include <QApplication>
#include <QQmlApplicationEngine>
#include "RecScreen.h"
#include "shot.h"
#include  <QQmlContext>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    CaptureScreen *capture = new CaptureScreen();
    Shot *fullscreen = new Shot();
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("recshot",capture);
    engine.rootContext()->setContextProperty("fullshot",fullscreen);
    const QUrl url(u"qrc:/ScreenShot/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(urls);

    return app.exec();
}
