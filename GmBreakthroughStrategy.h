// Gregory Kolesnokoff 2020
//
// The class bescribes a strategy with which
// the game is happaning.
// chess strategy, checkers strategy, any strategy

#ifndef GMBREAKTHROUGHSTRATEGY_H
#define GMBREAKTHROUGHSTRATEGY_H

#include <cstdint>
#include "GmBitBoard.h"
#include "GmFigure.h"
#include <memory>
#include <initializer_list>

namespace Gm {

class GmBreakthroughStrategy // here actualy should be an abstract class with common interface, and different certain algorithms might be accessable...
{
protected:
    std::shared_ptr<GmBitBoard> p_board;
    std::unique_ptr<GmFigure> figure;
    bool collide = false;

public:
    GmBreakthroughStrategy();
//    void addBoard(GmBitBoard* b);
    void addBoard(std::shared_ptr<GmBitBoard> b);
    void addFigure(const std::initializer_list<std::int8_t>& lst,
                          const int8_t& n_name);

    bool move(const std::size_t& side,
                   const std::size_t& pos_from,
                   const std::size_t& pos_to);

    bool checkSkill(const std::size_t& from,
                    const std::size_t& to);

    bool isEaten();

    int win();
};

}

#endif // GMBREAKTHROUGHSTRATEGY_H
















