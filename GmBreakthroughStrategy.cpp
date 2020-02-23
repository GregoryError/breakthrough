#include "GmBreakthroughStrategy.h"
#include <initializer_list>

using namespace Gm;

GmBreakthroughStrategy::GmBreakthroughStrategy()
{
    figure = std::make_unique<GmAbstrFigure>
            (std::initializer_list<int8_t> {0, 0, 0, 0, 0,
                                            0, 1, 1, 1, 0,
                                            0, 1, 1, 1, 0,
                                            0, 1, 1, 1, 0,
                                            0, 0, 0, 0, 0, 0}, 0);

    figure->DIAG_showFigure();

}

bool GmBreakthroughStrategy::make_Move(const std::uint8_t& side,
               const std::uint8_t& pos_from,
               const std::uint8_t& pos_to)
{
    if (p_board->getCell(pos_from) != 0)                           // - If on 'pos_from' is not empty cell AND
        if ((!p_board->getSide(pos_from) && side == 0) ||          // - If the figure on pos 'pos_from' yours, AND
                (p_board->getSide(pos_from) && side == 1))         // - If the cell where you want to move is
            if ((p_board->getCell(pos_to) == 0) ||                 // free, OR if it is filled with opponent
                    (p_board->getSide(pos_to) && side == 0) ||     // you are allowed to make a move.
                    (!p_board->getSide(pos_to) && side == 1))
            {





                p_board->move(pos_from, pos_from);                 // TODO: move allowed according to figures skills
                return true;
            }
    return false;
}
