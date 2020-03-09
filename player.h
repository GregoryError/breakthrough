#ifndef PLAYER_H
#define PLAYER_H

#include "GmAbstrPlayer.h"

class player : public Gm::GmAbstrPlayer
{
public:
    player() = default;
    player(const unsigned short& side, const std::string& img, const std::string& nm,
           std::shared_ptr<Gm::GmBitBoard>& b) : Gm::GmAbstrPlayer(side, img, nm, b) {}
    void play() override;

};

#endif // PLAYER_H
