#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <GmAbstrBitBoard.h>
#include <GmAbstrFigure.h>
#include <GmBoardGame.h>
#include <GmBreakthroughStrategy.h>

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

    Gm::GmAbstrBitBoard obj(8, 8, 2);
    //  0  1  2  3  4  5  6  7
    obj.arrange({1, 1, 1, 1, 1, 1, 1, 1,
                 0, 0, 1, 1, 1, 1, 0, 0}, Gm::cross);

    Gm::GmBoardGame<Gm::GmBreakthroughStrategy> Game;
    Game.addBoard(&obj);
    Game.addFigure({0, 0, 0, 0, 0,
                    0, 1, 1, 1, 0,
                    0, 1, 1, 1, 0,
                    0, 1, 1, 1, 0,
                    0, 0, 0, 0, 0}, 0);
    obj.DIAG_showBoard();

    //   std::cout << "Distance: " << obj.getDistance(8, 17) << '\n';
    //    std::cout << "Direction: " << obj.getDirection(48, 41) << '\n';

    std::size_t f, t, side = 0;
    std::cout << side << " move: ";
    while (std::cin >> f >> t)
    {

        system("cls");
        if (Game.move(side, f, t)) std::cout << "Accepted.\n";
        obj.DIAG_showBoard();
        if (side == 0)
            side = 1;
        else
            side = 0;
        std::cout << side << " move: ";
    }



    return 0;


    //    return app.exec();
}
