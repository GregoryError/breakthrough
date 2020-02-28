#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <GmAbstrBitBoard.h>
#include <GmAbstrFigure.h>
#include <GmBoardGame.h>
#include <GmBreakthroughStrategy.h>

void directionTest(Gm::GmAbstrBitBoard& board, int from, int to)
{
    std::cout << "From: " << from << ", to: " << to << "\n";
    if (board.getDirection(from, to) == Gm::right)
        std::cout << "to RIGHT\n";
    if (board.getDirection(from, to) == Gm::left)
        std::cout << "to LEFT\n";
    if (board.getDirection(from, to) == Gm::up)
        std::cout << "to UP\n";
    if (board.getDirection(from, to) == Gm::down)
        std::cout << "to DOWN\n";
    if (board.getDirection(from, to) == Gm::leftUp)
        std::cout << "to LEFTUP\n";
    if (board.getDirection(from, to) == Gm::rightUp)
        std::cout << "to RIGHTUP\n";
    if (board.getDirection(from, to) == Gm::rightDown)
        std::cout << "to RIGHTDOWN\n";
    if (board.getDirection(from, to) == Gm::leftDown)
        std::cout << "to LEFTDOWN\n";
}

int main(int argc, char *argv[])
{   
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    //    QGuiApplication app(argc, argv);

    //    QQmlApplicationEngine engine;
    //    const QUrl url(QStringLiteral("qrc:/main.qml"));
    //    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
    //                     &app, [url](QObject *obj, const QUrl &objUrl) {
    //        if (!obj && url == objUrl)
    //            QCoreApplication::exit(-1);
    //    }, Qt::QueuedConnection);
    //    engine.load(url);

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
    std::cout << "Distance: " << obj.getDistance(0, 56) << '\n';
    Game.move(0, 7, 23);


    obj.DIAG_showBoard();

    std::size_t f, t;
    while (std::cin >> f >> t)
    {
        std::cout << "Distance: " << obj.getDistance(f, t) << '\n';
    }


//    // tests:
//    // rightUp
//    for (int i = 8, j = 1; i != 56; i += 8, ++j)
//            directionTest(obj, i, j);
//    directionTest(obj, 56, 7);
//    for (int i = 57, j = 15; i != 63; ++i, j += 8)
//        directionTest(obj, i, j);
//    std::cout << "\n\n";

//    // leftDown
//    for (int i = 8, j = 1; i != 56; i += 8, ++j)
//            directionTest(obj, j, i);
//    directionTest(obj, 7, 56);
//    for (int i = 57, j = 15; i != 63; ++i, j += 8)
//        directionTest(obj, j, i);
//    std::cout << "\n\n";


//    // rightDown
//    for (int i = 48, j = 57; i != 0; i -= 8, ++j)
//            directionTest(obj, i, j);
//    directionTest(obj, 0, 63);
//    for (int i = 1, j = 55; i < 7; ++i, j -= 8)
//        directionTest(obj, i, j);
//    std::cout << "\n\n";

//    // leftUp
//    for (int i = 48, j = 57; i != 0; i -= 8, ++j)
//            directionTest(obj, j, i);
//    directionTest(obj, 63, 0);
//    for (int i = 1, j = 55; i < 7; ++i, j -= 8)
//        directionTest(obj, j, i);
//    std::cout << "\n\nSimple directions:\n";

//    // up
//    for (int i = 56, j = 0; j <= 7; ++j, ++i)
//        directionTest(obj, i, j);
//    std::cout << "\n\n";
//    // down
//    for (int i = 56, j = 0; j <= 7; ++j, ++i)
//        directionTest(obj, j, i);
//    std::cout << "\n\n";

//    // left
//    for (int i = 7, j = 0; i <= 63; j += 8, i += 8)
//        directionTest(obj, i, j);
//    std::cout << "\n\n";

//    // right
//    for (int i = 7, j = 0; i <= 63; j += 8, i += 8)
//        directionTest(obj, j, i);
//    std::cout << "\n\n";



    return 0;


    //    return app.exec();
}
