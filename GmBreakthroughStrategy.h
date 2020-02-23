// Gregory Kolesnokoff 2020
//
// The class bescribes a strategy with which
// the game is happaning.
// chess strategy, checkers strategy, any strategy

#ifndef GMBREAKTHROUGHSTRATEGY_H
#define GMBREAKTHROUGHSTRATEGY_H

#include <cstdint>
#include <GmAbstrBitBoard.h>
#include <GmAbstrFigure.h>
#include <memory>

namespace Gm {

class GmBreakthroughStrategy
{
private:
    GmAbstrBitBoard* p_board;
    std::unique_ptr<GmAbstrFigure> figure;
public:
    GmBreakthroughStrategy();
    void addBoard(GmAbstrBitBoard* b)
    {
        p_board = b;
    }

    bool make_Move(const std::uint8_t& side,
                   const std::uint8_t& pos_from,
                   const std::uint8_t& pos_to);

};

}

#endif // GMBREAKTHROUGHSTRATEGY_H
















