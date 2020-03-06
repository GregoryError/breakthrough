// Gregory Kolesnikoff 2020
//
// The template class resieves the strategy of current game
// For example GmBoardGame<chessStrategy> or
// GmBoardGame<checkersStrategy>
// This class works as a game core, accordingly
// to the certain strategy.

#ifndef GMABSTRBOARDGAME_H
#define GMABSTRBOARDGAME_H

#include <cstdint>

namespace Gm {

template <class GameStrategy>
class GmAbstrBoardGame : public GameStrategy
{
public:
    GmAbstrBoardGame() = default;

    virtual void start() = 0;
    virtual ~GmAbstrBoardGame() {}

};

}

#endif // GMABSTRBOARDGAME_H
