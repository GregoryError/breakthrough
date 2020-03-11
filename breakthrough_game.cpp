#include "breakthrough_game.h"
#include "GmBitBoard.h"
#include <ctime>
#include "player.h"
#include <QDebug>



Breakthrough_Game::Breakthrough_Game()
{    

    Player_Bohr = player(0, "qrc:/visualsources/players/bohr .png", "Niels Bohr");
    Player_Bohr.addQuote("");

    Player_Lama = player(0, "qrc:/visualsources/players/dalai_lama_14.png", "Dalai Lama XIV");
    Player_Lama.addQuote("");

    Player_Einstein = player(0, "qrc:/visualsources/players/einstein .png", "Albert Einstein");
    Player_Einstein.addQuote("");

    Player_Hemingway = player(0, "qrc:/visualsources/players/hemingway .png", "Ernest Hemingway");
    Player_Hemingway.addQuote("");

    Player_Hoking = player(0, "qrc:/visualsources/players/hokinq .png", "Stiven Hoking");
    Player_Hoking.addQuote("");

    Player_Holmes = player(0, "qrc:/visualsources/players/holms.png", "Sherlok Holmes");
    Player_Holmes.addQuote("");

    Player_Popov = player(0, "qrc:/visualsources/players/popov.png", "Александр Попов");
    Player_Popov.addQuote("");

    Player_Tesla = player(0, "qrc:/visualsources/players/tesla.png", "Nikola Tesla");
    Player_Tesla.addQuote("");

    std::srand(std::time(0));
}

void Breakthrough_Game::setBoard(const std::size_t& w, const std::size_t& h)
{

    auto board(std::make_shared<Gm::GmBitBoard>(w, h, 2));


    board->arrange({1, 1, 1, 1, 1, 1, 1, 1,
                    0, 0, 1, 1, 1, 1, 0, 0}, Gm::cross);
    addBoard(board);
    addFigure({0, 0, 0, 0, 0,
               0, 1, 1, 1, 0,
               0, 1, 1, 1, 0,
               0, 1, 1, 1, 0,
               0, 0, 0, 0, 0}, 1);  // Creating a pawn with some skills

    width_ = p_board->getWidth();
    height_ = p_board->getHeight();


}

Breakthrough_Game::~Breakthrough_Game()
{
    // delete p_board;
}

void Breakthrough_Game::start()
{
    p_board->DIAG_showBoard();


    // chose opponent
//    while (true)
//    {
        switch (std::rand() % 8)
        {
        case 0: current_player = &Player_Bohr; break;
        case 1: current_player = &Player_Lama; break;
        case 2: current_player = &Player_Einstein; break;
        case 3: current_player = &Player_Hemingway; break;
        case 4: current_player = &Player_Hoking; break;
        case 5: current_player = &Player_Holmes; break;
        case 6: current_player = &Player_Popov; break;
        case 7: current_player = &Player_Tesla; break;
        default: break;
        }

        emit opponentReady();

        current_player->addBoard(p_board);

        current_player->play();


//        if (isAvailable(0, 10, 17))
//            qDebug() << "YES\n";
//        else
//            qDebug() << "NO\n";



        // entery point

//        while (win() == 3)
//        {

//        }

//    }
}

bool Breakthrough_Game::move_(const unsigned int &pos_from, const unsigned int &pos_to)
{
    return move(getSide_(pos_from), pos_from, pos_to);
}


bool Breakthrough_Game::getSide_(const unsigned int& pos) const
{
    return p_board->getSide(pos);
}

unsigned int Breakthrough_Game::getCell_(const unsigned int& pos) const
{
    return p_board->getCell(pos);
}

void Breakthrough_Game::clearCell_(const std::size_t &pos)
{
    p_board->clearCell(pos);
}

bool Breakthrough_Game::hasUnit(const unsigned int &pos)
{
    return p_board->getCell(pos) && p_board->getSide(pos) == 1;
}

QString Breakthrough_Game::opponent_Name() const
{
    return QString::fromStdString(current_player->name);
}

QString Breakthrough_Game::opponent_img() const
{
    return QString::fromStdString(current_player->img_path);
}








































