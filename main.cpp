#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <GmAbstrBitBoard.h>
#include <GmAbstrFigure.h>

int main(int argc, char *argv[])
{   
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    Gm::GmAbstrBitBoard obj(8, 8, 5);
    obj.DIAG_showBoard();

    Gm::GmAbstrFigure some{0, 0, 0, 0, 0,
                           0, 1, 1, 1, 0,
                           0, 1, 1, 1, 0,
                           0, 1, 1, 1, 0,
                           0, 0, 0, 0, 0, 0};


    return app.exec();
}
