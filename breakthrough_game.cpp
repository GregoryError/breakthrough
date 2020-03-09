#include "breakthrough_game.h"
#include <GmBitBoard.h>

#include <QDebug>

Breakthrough_Game::Breakthrough_Game()
{

    //engine.load(QUrl(QStringLiteral("qrc:/mainView.qml")));

}

void Breakthrough_Game::setBoard(const std::size_t& w, const std::size_t& h)
{
    //Gm::GmBitBoard* board = new Gm::GmBitBoard(w, h, 2);   // Creating board
    std::shared_ptr<Gm::GmBitBoard> board(new Gm::GmBitBoard(w, h, 2));
    board->arrange({1, 1, 1, 1, 1, 1, 1, 1,
                    0, 0, 1, 1, 1, 1, 0, 0}, Gm::cross);
    addBoard(board);
    addFigure({0, 0, 0, 0, 0,
               0, 1, 1, 1, 0,
               0, 1, 1, 1, 0,
               0, 1, 1, 1, 0,
               0, 0, 0, 0, 0}, 1);  // Creating a pawn with some skills

}

Breakthrough_Game::~Breakthrough_Game()
{
   // delete p_board;
}

void Breakthrough_Game::start()
{
    p_board->DIAG_showBoard();
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
