#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <GmAbstrBitBoard.h>
#include <GmAbstrFigure.h>
#include <GmBoardGame.h>
#include <GmBreakthroughStrategy.h>

#include <vector>

int main(int argc, char *argv[])
{   
    // QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    // QGuiApplication app(argc, argv);

    //    QQmlApplicationEngine engine;
    //    const QUrl url(QStringLiteral("qrc:/main.qml"));
    //    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
    //                     &app, [url](QObject *obj, const QUrl &objUrl) {
    //        if (!obj && url == objUrl)
    //            QCoreApplication::exit(-1);
    //    }, Qt::QueuedConnection);
    //    engine.load(url);

    Gm::GmAbstrBitBoard obj(6, 8, 2);
    //  0  1  2  3  4  5  6  7


    obj.arrange({1, 1, 1, 1, 1, 1, 1, 1,
                 0, 0, 1, 1, 1, 1, 0, 0}, Gm::cross);

    Gm::GmBoardGame<Gm::GmBreakthroughStrategy> Game;
    Game.addBoard(&obj);
    Game.addFigure({0, 0, 0, 0, 0,
                    0, 1, 1, 1, 0,
                    0, 1, 1, 1, 0,
                    0, 1, 1, 1, 0,
                    0, 0, 0, 0, 0}, 1);
    obj.DIAG_showBoard();




    std::cout << "Distance: " << obj.getDistance(8, 17) << '\n';
    std::cout << "Direction: " << obj.getDirection(48, 41) << '\n';

    std::size_t f, t, side = 0;
    std::cout << side << " move: ";

    std::vector<std::size_t> vct_from {0, 47, 1, 45, 8, 39, 16, 35, 24, 28, 32, 21, 0, 34, 8, 44, 16, 21, 24};
    std::vector<std::size_t> vct_to {8, 39, 0, 38, 16, 31, 24, 28, 32, 21, 40, 22, 8, 27, 16, 37, 24, 12, 32};




    while (std::cin >> f >> t)
    {

        system("cls");
        if (Game.move(side, f, t)) std::cout << "Accepted.\n";
        obj.DIAG_showBoard();
        if (side == 0)
            side = 1;
        else
            side = 0;
        switch (Game.win())
        {
        case 0: std::cout << "Player 0 wins!\n"; break;
        case 1: std::cout << "Player 1 wins!\n"; break;
        case 2: std::cout << "NOBODY WIN!\n"; break;
        case 3: break;
        }
        std::cout << side << " move: ";
    }



    return 0;


    //    return app.exec();
}
