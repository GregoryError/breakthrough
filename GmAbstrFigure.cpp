#include "GmAbstrFigure.h"
#include <iostream>

using namespace Gm;

GmAbstrFigure::GmAbstrFigure(const std::initializer_list<int8_t>& lst,
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
    }
}

void GmAbstrFigure::setBit(const size_t &pos)
{
    skills[pos / 8] ^= (1 << (pos % 8));
}

bool GmAbstrFigure::getBit(const size_t &pos)
{
    return skills[pos / 8] & (1 << (pos % 8));
}

bool GmAbstrFigure::operator[](const size_t &pos)
{
    return getBit(pos);
}
