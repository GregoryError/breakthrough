#include "GmAbstrPlayer.h"

using namespace Gm;

GmAbstrPlayer::GmAbstrPlayer(const unsigned short &side, const std::string &img, const std::string &nm, std::shared_ptr<GmBitBoard>& b)
{
    n_side = side;
    img_path = img;
    name = nm;
    board = b;
}

void GmAbstrPlayer::addQuote(const std::string &txt)
{
    quotes.push_back(txt);
}

void GmAbstrPlayer::play()
{
    cell_to = cell_from = 0;
}

GmAbstrPlayer::~GmAbstrPlayer()
{

}
