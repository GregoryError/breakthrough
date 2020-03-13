#ifndef PLAYER_H
#define PLAYER_H

#include "GmAbstrPlayer.h"


#include <map>
#include <vector>

class player : public Gm::GmAbstrPlayer
{
private:

public:
    player() = default;
    player(const unsigned short& side, const std::string& img, const std::string& nm) : Gm::GmAbstrPlayer(side, img, nm) {}


    void play() override;

    bool checkCell(const unsigned int &from, const unsigned int &to) override
    {
        return GmAbstrPlayer::checkCell(from, to);     // Check for 1 cell is enough
    }

    void DIAG_showPlayer(const std::map<unsigned, std::vector<unsigned>>& M);

};

#endif // PLAYER_H





