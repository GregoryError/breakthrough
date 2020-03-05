#ifndef BREAKTHROUGH_GAME_H
#define BREAKTHROUGH_GAME_H

#include <GmAbstrBoardGame.h>
#include <GmBreakthroughStrategy.h>

class Breakthrough_Game : public Gm::GmAbstrBoardGame<Gm::GmBreakthroughStrategy>
{
public:
    Breakthrough_Game();
    void start() override;
};

#endif // BREAKTHROUGH_GAME_H
