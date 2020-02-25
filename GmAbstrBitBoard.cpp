#include "GmAbstrBitBoard.h"

using namespace Gm;

GmAbstrBitBoard::GmAbstrBitBoard(const std::size_t& height,
                                 const std::size_t& width,
                                 const std::size_t& tps)
{
    WIDTH = width;
    HEIGHT = height;
    TYPES = tps;
    board_space = (height * width) / 8 + 1;
    p_side = std::make_unique<std::uint8_t[]>(board_space);
    p_forces = std::make_unique<std::uint8_t[]>(TYPES * board_space);
}

void GmAbstrBitBoard::setSide(const std::size_t &pos)
{
    if (pos < WIDTH * HEIGHT)
        p_side[pos / 8] ^= (1 << (pos % 8));
}

void GmAbstrBitBoard::setCell(const std::size_t &pos, const std::size_t& n_type)
{
    if (pos < WIDTH * HEIGHT)
        p_forces[(pos / 8) + (8 * n_type)] ^= (1 << (pos % 8));
}

bool GmAbstrBitBoard::getSide(const std::size_t &pos) const
{
    if (pos < WIDTH * HEIGHT)
        return p_side[pos / 8] & (1 << (pos % 8));
    else
        return false;
}

std::size_t GmAbstrBitBoard::getCell(const std::size_t &pos) const
{
    std::size_t i;
    for (i = 0; i < TYPES; ++i)
        if (p_forces[(pos / 8) + (8 * i)] & (1 << pos % 8))
            return i;
    return 0;
}

//////////////////////////////////////////////////////////////////////////////
///    2, 3, 4, 5, 6, 4, 3, 2,                                             ///
///    1, 1, 1, 1, 1, 1, 1, 1,                                             ///
///    0, 0, 0, 0, 0, 0, ... - Typical example of chess forces arrangement ///
//////////////////////////////////////////////////////////////////////////////
/// \brief GmAbstrBitBoard::arrange                                        ///
/// \param lst {2, 3, 4, 5, 5, 4, 6, 2, 1, 1, 1, 1, 1, 1, 1, 1}            ///
//////////////////////////////////////////////////////////////////////////////
/// Arranges forces on board according how it was made for one side,       ///
/// but for both sides. Mirror-like way.                                   ///
//////////////////////////////////////////////////////////////////////////////

void GmAbstrBitBoard::arrange(const std::initializer_list<std::size_t> &lst, const BEG& beg)
{
    std::cout << "ENUM: " << beg << '\n';
    std::size_t i = 0;
    for (const auto& v : lst)
    {
        if (v != 0)
        {                                                        //player 0
            setCell(i, v);
            if (beg == cross)
            {                                                    // player 1
                setCell(WIDTH * HEIGHT - 1 - i, v);
                setSide(WIDTH * HEIGHT - 1 - i);
            }
        }
        ++i;
    }

    if (beg == direct)
    {
        for (i = 0; i < lst.size(); ++i)
        {
            setCell(WIDTH * HEIGHT - lst.size() + i, getCell(i));
            setSide(WIDTH * HEIGHT - lst.size() + i);
        }
    }
}

void GmAbstrBitBoard::move(const std::size_t &pos_from, const std::size_t &pos_to)
{
    setCell(pos_to, getCell(pos_from));
    setCell(pos_from, 0);
}

std::size_t GmAbstrBitBoard::getCellsRIGHT(const std::size_t &pos) const
{
    std::size_t i = 0;
    for (; i * WIDTH <= pos; ++i) ;
    return (i * WIDTH - pos) - 1;

}

std::size_t GmAbstrBitBoard::getCellsLEFT(const std::size_t &pos) const
{
    std::size_t i = 0;
    for (; i * WIDTH <= pos; ++i) ;
    return pos - (i * WIDTH - WIDTH);
}

std::size_t GmAbstrBitBoard::getCellsUP(const std::size_t &pos) const
{
    std::size_t i = 0;
    for (; i * WIDTH < pos; ++i) ;
    return (i == 0) ? i : (i - 1);
}

std::size_t GmAbstrBitBoard::getCellsDOWN(const std::size_t &pos) const
{
    std::size_t i = 0;
    for (; i * WIDTH < pos; ++i) ;
    return HEIGHT - i;
}

std::size_t GmAbstrBitBoard::getCellsLEFTUP(const std::size_t &pos) const
{
    return getCellsLEFT(pos) <= getCellsUP(pos) ? getCellsLEFT(pos) : getCellsUP(pos);
}

std::size_t GmAbstrBitBoard::getCellsRIGHTUP(const std::size_t &pos) const
{
    return getCellsRIGHT(pos) <= getCellsUP(pos) ? getCellsRIGHT(pos) : getCellsUP(pos);
}

std::size_t GmAbstrBitBoard::getCellsRIGHTDOWN(const std::size_t &pos) const
{
    return getCellsRIGHT(pos) <= getCellsDOWN(pos) ? getCellsRIGHT(pos) : getCellsDOWN(pos);
}

std::size_t GmAbstrBitBoard::getCellsLEFTDOWN(const std::size_t &pos) const
{
    return getCellsLEFT(pos) <= getCellsDOWN(pos) ? getCellsLEFT(pos) : getCellsDOWN(pos);
}

DIRECTION GmAbstrBitBoard::getDirection(const std::size_t &pos_from, const std::size_t &pos_to) const
{
    if (pos_to > pos_from)
    {
        if (pos_to - pos_from < WIDTH &&
                getCellsRIGHT(pos_from) < WIDTH)
            return right;

    }
    if (pos_to < pos_from)
    {
        if (pos_from - pos_to < WIDTH &&
                getCellsLEFT(pos_from) < WIDTH)
            return left;
    }
    if (pos_to < pos_from)
    {
        if ((pos_from - pos_to) % WIDTH == 0)
            return up;
    }
    if (pos_to > pos_from)
    {
        if ((pos_to - pos_from) % WIDTH == 0)
            return down;
    }
    if (pos_to < pos_from)
    {
        auto rows = (pos_from - pos_to) / WIDTH;
        auto endPos = (rows * WIDTH) + rows;

        if (pos_to == pos_from - endPos)
            return leftUp;
    }

    if (pos_to < pos_from)
    {
        auto rows = (pos_from - pos_to) / WIDTH;
        auto endPos = (rows * WIDTH) + rows;
        std::cout << "ROWS: " << rows << '\n';
        if (pos_to == pos_from - endPos)
            return rightUp;
    }










    return undefined;
}





/////// DIAGNOSTIC

void GmAbstrBitBoard::DIAG_showBoard()
{
    std::cout << "DIAG_showBoard():\n";
    for (std::size_t i = 0; i < WIDTH * HEIGHT; ++i)
    {
        std::cout << getCell(i) << " ";
        if ((i + 1) % WIDTH == 0)
            std::cout << '\n';
    }
    // std::cout << std::endl << std::cout;

}



























