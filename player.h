#ifndef PLAYER_H
#define PLAYER_H

#include "GmAbstrPlayer.h"

class player : public Gm::GmAbstrPlayer
{
private:

public:
    player() = default;
    player(const unsigned short& side, const std::string& img, const std::string& nm) : Gm::GmAbstrPlayer(side, img, nm) {}

    void play() override;

};

#endif // PLAYER_H
