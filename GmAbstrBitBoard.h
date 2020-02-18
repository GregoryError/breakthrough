// Gregory Kolesnikoff 2020
//
// This abstract class keeps data about current game board state.
// The data is keeped as an array of bytes.
// Bit 1 - means there is a filled cell, 0 - means it is empty.
// BitBoard objects also have data about whose figure on a cells.
// There is an extra array that represents a 'type' of figures if
// application requires it.
// There are methods like set(pos)/pos get() - that set/return
// data in a cells.

#ifndef GMABSTRBITBOARD_H
#define GMABSTRBITBOARD_H

/////// DIAG
#include <iostream>
/////// DIAG

#include <cstdint>
#include <memory>
#include <initializer_list>

namespace Gm {

class GmAbstrBitBoard
{
private:
    std::size_t WIDTH, HEIGHT;
    std::size_t TYPES;
    std::size_t board_space;
    std::unique_ptr<std::int8_t[]> p_cells;
    std::unique_ptr<std::int8_t[]> p_side;
    std::unique_ptr<std::int8_t[]> p_types;

    void setCell(const std::size_t& pos);                 // 1 - filled, 0 - empty
    void setSide(const std::size_t& pos);                 // 1 - one player, 0 - another
    void setType(const std::size_t& pos,                  // (position on brd, type of figure)
                 const std::size_t& n_type);
    bool getCell(const std::size_t& pos) const;           // empty or filled
    bool getSide(const std::size_t& pos) const;           // whose figure
    std::size_t getType(const std::size_t& pos) const;

public:
    GmAbstrBitBoard() = delete;
    GmAbstrBitBoard(const std::size_t& height,
                    const std::size_t& width,
                    const std::size_t& tps);

    void arrange(const std::initializer_list<std::size_t>& lst);

    void DIAG_showBoard();
};



}

#endif // GMABSTRBITBOARD_H
