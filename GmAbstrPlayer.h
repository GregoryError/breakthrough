#ifndef GMABSTRPLAYER_H
#define GMABSTRPLAYER_H

#include <string>
#include <vector>
#include "GmBitBoard.h"
#include <memory>


namespace Gm {

class GmAbstrPlayer
{
protected:
public:
    unsigned short n_side;
    std::string img_path;
    std::string name;
    std::shared_ptr<GmBitBoard> board;
    std::vector<std::string> quotes;
    unsigned int cell_from, cell_to;

public:
    GmAbstrPlayer() = default;
    GmAbstrPlayer(const unsigned short& side, const std::string& img, const std::string& nm);
    void addQuote(const std::string& txt);
    void addBoard(std::shared_ptr<GmBitBoard>& b) { board = b; }

    virtual void play() = 0;

    virtual unsigned int from() const
    { return cell_from; }

    virtual unsigned int to() const
    { return cell_to; }

    virtual ~GmAbstrPlayer();
};

}

#endif // GMABSTRPLAYER_H
