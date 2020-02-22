#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <GmAbstrBitBoard.h>
#include <GmAbstrFigure.h>

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

    Gm::GmAbstrBitBoard obj(8, 8, 7);
             //  0  1  2  3  4  5  6  7
    obj.arrange({2, 3, 4, 5, 6, 4, 3, 2,                                             ///
                 1, 1, 1, 1, 1, 1, 1, 1}, Gm::cross);

    obj.DIAG_showBoard();


//    Gm::GmAbstrFigure some({0, 0, 0, 0, 0,
//                            0, 1, 1, 1, 0,
//                            0, 1, 1, 1, 0,
//                            0, 1, 1, 1, 0,
//                            0, 0, 0, 0, 0, 1}, 1);

//    std::cout << "\n\nFIGURE:\n";
//    for(std::size_t i = 0; i < 26; ++i)
//    {
//        std::cout << some[i] << ' ';
//        if ((i + 1) % 5 == 0)
//            std::cout << '\n';
//    }

    return 0;


//    return app.exec();
}
