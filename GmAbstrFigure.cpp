#include "GmAbstrFigure.h"

using namespace Gm;

GmAbstrFigure::GmAbstrFigure(const std::initializer_list<int8_t> &lst)
{
    if (lst.size() <= 26)
    {
        std::size_t i = 0;
        for (const auto& v : lst)
            skills[i++] = v;
    }
}
