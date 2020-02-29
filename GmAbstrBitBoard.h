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

enum BEG {direct, cross};
enum DIRECTION {right, left, up, down, leftUp,
                rightUp, rightDown, leftDown, undefined};

class GmAbstrBitBoard
{
private:
    std::size_t WIDTH, HEIGHT;
    std::size_t TYPES;
    std::size_t board_space;
    std::unique_ptr<std::uint8_t[]> p_side;
    std::unique_ptr<std::uint8_t[]> p_forces;
public:
    bool getSide(const std::size_t& pos) const;    // whose figure
    void setSide(const std::size_t& pos);          // 1 - one player, 0 - another
    void setCell(const std::size_t& pos,           // (position on brd, type of figure)
                 const std::size_t& n_type);
    std::size_t getCell(const std::size_t& pos) const;
   // void clearCell(const std::size_t& pos);

public:
    GmAbstrBitBoard() = delete;
    GmAbstrBitBoard(const std::size_t& height,
                    const std::size_t& width,
                    const std::size_t& tps);

    void arrange(const std::initializer_list<std::size_t>& lst,
                 const BEG& beg = cross);
    void move(const std::size_t& pos_from,
              const std::size_t& pos_to);


    // these guys show how many cells available in this direction
    std::size_t getCellsRIGHT(const std::size_t& pos) const;
    std::size_t getCellsLEFT(const std::size_t& pos) const;
    std::size_t getCellsUP(const std::size_t& pos) const;
    std::size_t getCellsDOWN(const std::size_t& pos) const;
    std::size_t getCellsLEFTUP(const std::size_t& pos) const;
    std::size_t getCellsRIGHTUP(const std::size_t& pos) const;
    std::size_t getCellsRIGHTDOWN(const std::size_t& pos) const;
    std::size_t getCellsLEFTDOWN(const std::size_t& pos) const;

    // this shows direction by positions
    DIRECTION getDirection(const std::size_t& pos_from, const std::size_t& pos_to) const;
    std::size_t getDistance(const std::size_t& pos_from, const std::size_t& pos_to) const;

    void DIAG_showBoard();

    const std::size_t& getWidth() const { return WIDTH; }
    const std::size_t& getHeight() const { return HEIGHT; }
    bool empty();
};

}

#endif // GMABSTRBITBOARD_H
