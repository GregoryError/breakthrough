#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "breakthrough_game.h"


int main(int argc, char *argv[])
{   
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    Breakthrough_Game GAME;

    GAME.setBoard(8, 8);

    GAME.start();

    QQmlApplicationEngine engine;
    QQmlContext* cont;
    cont = engine.rootContext();
    cont->setContextProperty("game_core", &GAME);
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);


    return app.exec();
}
