#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtDebug>
#include <QQmlContext>

#include "stopwatch.h"

int main(int argc, char *argv[])
{

//    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<StopWatch>("dsx3.d3xs.stopwatch",1,0,"StopWatch");

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
