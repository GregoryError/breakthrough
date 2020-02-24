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
#include <initializer_list>

namespace Gm {

class GmBreakthroughStrategy
{
private:
    GmAbstrBitBoard* p_board;
    std::unique_ptr<GmAbstrFigure> figure;

public:
    GmBreakthroughStrategy();
    void addBoard(GmAbstrBitBoard* b);
    void addFigure(const std::initializer_list<std::int8_t>& lst,
                          const int8_t& n_name);

    bool move(const std::uint8_t& side,
                   const std::uint8_t& pos_from,
                   const std::uint8_t& pos_to);

    bool checkSkill(const std::uint8_t& from,
                    const std::uint8_t& to);



};

}

#endif // GMBREAKTHROUGHSTRATEGY_H
















