// Gregory Kolesnikoff 2020
//
// The template class resieves the strategy of current game
// For example GmBoardGame<chessStrategy> or
// GmBoardGame<checkersStrategy>
// This class works as a game core, accordingly
// to the certain strategy.

#ifndef GMBOARDGAME_H
#define GMBOARDGAME_H

namespace Gm {

template <class GameStrategy>
class GmBoardGame : public GameStrategy
{
public:
    GmBoardGame();
};

}

#endif // GMBOARDGAME_H
