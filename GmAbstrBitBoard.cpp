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



























