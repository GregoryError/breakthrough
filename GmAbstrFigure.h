// Gregory Kolesnikoff 2020
//
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

namespace Gm {

class GmAbstrFigure
{
public:
    GmAbstrFigure();
};



}

#endif // GMABSTRFIGURE_H
