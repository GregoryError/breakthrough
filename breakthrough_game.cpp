#include "breakthrough_game.h"
#include "GmBitBoard.h"
#include "player.h"

#include <QDebug>

Breakthrough_Game::Breakthrough_Game()
{    
    player Player_Bohr(0, "qrc:/visualsources/players/bohr.png", "Niels Bohr", p_board);
    Player_Bohr.addQuote("");

    player Player_Lama(0, "qrc:/visualsources/players/dalai_lama_14.png", "Dalai Lama XIV", p_board);
    Player_Lama.addQuote("");

    player Player_Einstein(0, "qrc:/visualsources/players/einstein.png", "Albert Einstein", p_board);
    Player_Einstein.addQuote("");

    player Player_Hemingway(0, "qrc:/visualsources/players/hemingway.png", "Ernest Hemingway", p_board);
    Player_Hemingway.addQuote("");

    player Player_Hoking(0, "qrc:/visualsources/players/hokinq.png", "Stiven Hoking", p_board);
    Player_Hoking.addQuote("");

    player Player_Holmes(0, "qrc:/visualsources/players/holms.png", "Sherlok Holmes", p_board);
    Player_Holmes.addQuote("");

    player Player_Popov(0, "qrc:/visualsources/players/popov.png", "Александр Попов", p_board);
    Player_Popov.addQuote("");

    player Player_Tesla(0, "qrc:/visualsources/players/tesla.png", "Nikola Tesla", p_board);
    Player_Tesla.addQuote("");

}

void Breakthrough_Game::setBoard(const std::size_t& w, const std::size_t& h)
{
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
