#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "breakthrough_game.h"


int main(int argc, char *argv[])
{   
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);


    QGuiApplication app(argc, argv);

    app.setApplicationDisplayName("Прорыв");
    app.setOrganizationName("Kolesnikoff");
    app.setOrganizationDomain("https://play.google.com/store/apps/dev?id=5304440424969692355");
    app.setApplicationName("breakthrough");

    Breakthrough_Game GAME;

    GAME.setBoard(8, 8); // to change boars size you not only have to change board here

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

    GAME.start();
    return app.exec();
}



