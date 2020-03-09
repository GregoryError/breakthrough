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
    unsigned short n_side;
    std::string img_path;
    std::string name;
    std::shared_ptr<GmBitBoard> board;
    std::vector<std::string> quotes;
    unsigned int cell_from, cell_to;

public:
    GmAbstrPlayer() = delete;
    GmAbstrPlayer(const unsigned short& side, const std::string& img, const std::string& nm,
                  std::shared_ptr<GmBitBoard>& b);
    void addQuote(const std::string& txt);
    virtual void play() = 0;
    const unsigned int& from() const
    { return cell_from; }
    const unsigned int& to() const
    { return cell_to; }
    virtual ~GmAbstrPlayer();
};

}

#endif // GMABSTRPLAYER_H
