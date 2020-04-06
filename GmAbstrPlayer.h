#ifndef GMABSTRPLAYER_H
#define GMABSTRPLAYER_H

#include <string>
#include <vector>
#include "GmBitBoard.h"
#include <memory>


namespace Gm {

class GmAbstrPlayer
{
public:
    std::string name;
    std::string img_path;
    unsigned short n_side;
    std::shared_ptr<GmBitBoard> board;
    std::vector<std::string> quotes;
    unsigned int cell_from, cell_to;
    unsigned player_num = 0;

public:
    GmAbstrPlayer() = default;
    GmAbstrPlayer(const unsigned short& side, const std::string& img, const std::string& nm, const unsigned& pl_num);
    void addQuote(const std::string& txt);
    void addBoard(std::shared_ptr<GmBitBoard>& b) { board = b; }
    std::string getQuote();

    virtual bool checkCell(const unsigned& from, const unsigned& to);

    virtual void play() = 0;

    virtual unsigned int from() const
    { return cell_from; }

    virtual unsigned int to() const
    { return cell_to; }

    virtual ~GmAbstrPlayer();
};

}

#endif // GMABSTRPLAYER_H
