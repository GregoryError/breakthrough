// Gregory Kolesnikoff 2020

// This abstract class represents a figure.
// The class keeps following information:
// - the 'name' of figure - just a numder.
// - how figure can move.
// There are 26 bit in the array of bytes.
// Bits 0 - 24 describe directions in which
// the figure can move. Bit #25 - sets whether
// figure can move unlimited(queen) or not.


#ifndef GMABSTRFIGURE_H
#define GMABSTRFIGURE_H

#include <initializer_list>
#include <cstdint>

namespace Gm {

struct GmAbstrFigure
{
    std::int8_t n_name;
    std::int8_t skills[4];
    GmAbstrFigure() = delete;
    GmAbstrFigure(const std::initializer_list<int8_t>& lst,
                  const std::int8_t& name = 0);
    void setBit(const std::size_t& pos);
    bool getBit(const std::size_t& pos);
    bool operator[](const std::size_t& pos);
};

}

#endif // GMABSTRFIGURE_H
