#include "GmAbstrPlayer.h"
#include <QDebug>

using namespace Gm;

GmAbstrPlayer::GmAbstrPlayer(const unsigned short &side, const std::string &img, const std::string &nm)
{
    n_side = side;
    img_path = img;
    name = nm;
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

bool GmAbstrPlayer::checkCell(const unsigned &from, const unsigned &to)
{
    if (from == board->getWidth() - 1 && to == (board->getWidth() - 1) + 1)
        return false;
    if (to == board->getWidth() - 1 && from == (board->getWidth() - 1) + 1)
        return false;
    if (board->getCell(from) != 0 && (to != from) && (!board->getSide(from)))
        if ((board->getCell(to) == 0) ||
                (board->getSide(to)))
        {
            switch (board->getDirection(from, to))
            {
            case right: if (1 >= (board->getDistance(from, to))) return true; break;
            case left: if (1 >= (board->getDistance(from, to))) return true; break;
            case up: if (1 >= (board->getDistance(from, to))) return true; break;
            case down: if (1 >= (board->getDistance(from, to))) return true; break;
            case leftUp: if (1 >= (board->getDistance(from, to))) return true; break;
            case rightUp: if (1 >= (board->getDistance(from, to))) return true; break;
            case rightDown: if (1 >= (board->getDistance(from, to))) return true; break;
            case leftDown: if (1 >= (board->getDistance(from, to))) return true; break;
            case undefined: return false;
            }

        }
    return false;
}
