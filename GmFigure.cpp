#include "GmFigure.h"
#include <iostream>

using namespace Gm;

GmFigure::GmFigure(const std::initializer_list<int8_t>& lst,
                             const std::int8_t& name) : n_name(name)
{    
    if (lst.size() <= 26)
    {
        std::size_t i = 0;
        for (const auto& v : lst)
        {
            if (v == 1)
                setBit(i);
            ++i;
        }

        //        c_RIGHT, c_LEFT, c_UP, c_DOWN,
        //        c_LEFTUP, c_RIGHTUP, c_RIGHTDOWN, c_LEFTDOWN;

        c_RIGHT = 0;
        if (getBit(13))
        {
            ++c_RIGHT;
            if (getBit(14))
                ++c_RIGHT;
        }

        c_LEFT = 0;
        if (getBit(11))
        {
            ++c_LEFT;
            if (getBit(10))
                ++c_LEFT;
        }


        c_UP = 0;
        if (getBit(7))
        {
            ++c_UP;
            if (getBit(3))
                ++c_UP;
        }

        c_DOWN = 0;
        if (getBit(17))
        {
            ++c_DOWN;
            if (getBit(22))
                ++c_DOWN;
        }

        c_LEFTUP = 0;
        if (getBit(6))
        {
            ++c_LEFTUP;
            if (getBit(0))
                ++c_LEFTUP;
        }

        c_RIGHTUP = 0;
        if (getBit(8))
        {
            ++c_RIGHTUP;
            if (getBit(4))
                ++c_RIGHTUP;
        }

        c_RIGHTDOWN = 0;
        if (getBit(18))
        {
            ++c_RIGHTDOWN;
            if (getBit(24))
                ++c_RIGHTDOWN;
        }

        c_LEFTDOWN = 0;
        if (getBit(16))
        {
            ++c_LEFTDOWN;
            if (getBit(20))
                ++c_LEFTDOWN;
        }


    }

  //  DIAG_showFigure();

}

void GmFigure::setBit(const size_t &pos)
{
    skills[pos / 8] ^= (1 << (pos % 8));
}

bool GmFigure::getBit(const size_t &pos)
{
    return skills[pos / 8] & (1 << (pos % 8));
}

//void GmFigure::DIAG_showFigure()
//{
//    std::cout << "c_RIGHT: " << c_RIGHT << " c_LEFT: " << c_LEFT << " c_UP: " << c_UP << " c_DOWN: " << c_DOWN
//              << "\nc_DOWN: " << c_DOWN << " c_LEFTUP: " << c_LEFTUP << " c_RIGHTUP: " << c_RIGHTUP
//              << " c_LEFTDOWN: " << c_LEFTDOWN << '\n';

//    std::cout << "\n\nFIGURE:\n";
//    for(std::size_t i = 0; i < 26; ++i)
//    {
//        if (i == 0) std::cout << "V\n";
//        std::cout << getBit(i) << ' ';
//        if ((i + 1) % 5 == 0)
//            std::cout << '\n';
//    }
//}

//bool GmFigure::operator[](const size_t &pos)
//{
//    return getBit(pos);
//}
