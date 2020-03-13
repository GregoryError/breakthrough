#include "GmBreakthroughStrategy.h"

#include <QDebug>


using namespace Gm;

GmBreakthroughStrategy::GmBreakthroughStrategy()
{

}

void GmBreakthroughStrategy::addBoard(std::shared_ptr<GmBitBoard> b)
{
    p_board = b;
}
void GmBreakthroughStrategy::addFigure(const std::initializer_list<std::int8_t>& lst,
                                       const int8_t& n_name)
{
    figure = std::make_unique<GmFigure>(lst, n_name);
}

bool GmBreakthroughStrategy::move(const std::size_t &side,
                                  const std::size_t& pos_from,
                                  const std::size_t& pos_to)
{
    if (p_board->getCell(pos_from) != 0 && (pos_to != pos_from))   // - If on 'pos_from' is not empty cell AND
        if ((!p_board->getSide(pos_from) && side == 0) ||          // - If the figure on pos 'pos_from' yours, AND
                (p_board->getSide(pos_from) && side == 1))         // - If the cell where you want to move is
            if ((p_board->getCell(pos_to) == 0) ||                 // free, OR if it is filled with opponent
                    (p_board->getSide(pos_to) && side == 0) ||     // you are allowed to make a move.
                    (!p_board->getSide(pos_to) && side == 1))
            {
                if (checkSkill(pos_from, pos_to))
                {
                    if ((p_board->getCell(pos_to) != 0) &&         // TODO Check if it is not just move but eating
                            ((p_board->getSide(pos_to) && side == 0) ||
                             (!p_board->getSide(pos_to) && side == 1)))
                        collide = true;
                    p_board->move(pos_from, pos_to);
                    return true;
                }
            }
    return false;
}

bool GmBreakthroughStrategy::checkSkill(const std::size_t& from, const std::size_t& to)         // move allowed according to figures skills
{
    switch (p_board->getDirection(from, to))
    {
    case right: if (figure->c_RIGHT >= (p_board->getDistance(from, to))) return true; break;
    case left: if (figure->c_LEFT >= (p_board->getDistance(from, to))) return true; break;
    case up: if (figure->c_UP >= (p_board->getDistance(from, to))) return true; break;
    case down: if (figure->c_DOWN >= (p_board->getDistance(from, to))) return true; break;
    case leftUp: if (figure->c_LEFTUP >= (p_board->getDistance(from, to))) return true; break;
    case rightUp: if (figure->c_RIGHTUP >= (p_board->getDistance(from, to))) return true; break;
    case rightDown: if (figure->c_RIGHTDOWN >= (p_board->getDistance(from, to))) return true; break;
    case leftDown: if (figure->c_LEFTDOWN >= (p_board->getDistance(from, to))) return true; break;
    case undefined: return false;
    }
    return false;
}

bool GmBreakthroughStrategy::isEaten()
{
    bool t = collide;
    collide = false;
    return t;
}

int GmBreakthroughStrategy::win()
{
    if (p_board->empty())    // absolutely empty board, return 2 - means nobody win (tied)
        return 2;

    int result = 3;         // 3 - neams the game is continue

    for (std::size_t i = 0; i <= p_board->getWidth(); ++i)     // is player 1 wins?
        if (p_board->getSide(i))
            result = 1;
    for (std::size_t i = (p_board->getWidth() * p_board->getHeight() - 1);          // is player 0 win?
         i >= (p_board->getWidth() * p_board->getHeight() - p_board->getWidth()); --i)
    {
        if (p_board->getSide(i) == 0 && p_board->getCell(i) == 1)
            result = result == 1 ? 2 : 0;                                  // or both?
    }

    return result;
}








