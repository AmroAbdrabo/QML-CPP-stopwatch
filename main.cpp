#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include "stopwatch.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);    
    qmlRegisterType<Stopwatch>("ch.epfl.stopwatch", 1, 0, "Stopwatch");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    /*QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);*/
    engine.load(url);

    return app.exec();
}
