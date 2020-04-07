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
    player(const unsigned short& side, const std::string& img, const std::string& nm, const unsigned& pl_nm) : Gm::GmAbstrPlayer(side, img, nm, pl_nm) {}

    void play() override;

    void goToCell(const unsigned& gap, const std::vector<unsigned>& forces_vct,
               std::map<unsigned, std::vector<unsigned>>& possible_cells_map);

    bool checkCell(const unsigned int &from, const unsigned int &to) override
    {
        return GmAbstrPlayer::checkCell(from, to);     // Check for 1 cell is enough
    }

 //   void DIAG_showPlayer(const std::map<unsigned, std::vector<unsigned>>& M);

};

#endif // PLAYER_H






