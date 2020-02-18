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
    p_cells = std::make_unique<std::int8_t[]>(board_space);
    p_side = std::make_unique<std::int8_t[]>(board_space);
    p_types = std::make_unique<std::int8_t[]>(TYPES * board_space);


    arrange({1, 1, 1, 1, 1, 1, 1, 1,
             0, 0, 1, 1, 1, 1, 0, 0});

   // std::cout << "4: " << getType(4) << " " << " 11: " << getType(11) << '\n';


}

void GmAbstrBitBoard::setCell(const std::size_t &pos)
{
    if (pos < WIDTH * HEIGHT)
        p_cells[pos / 8] ^= (1 << (pos % 8));
}

void GmAbstrBitBoard::setSide(const std::size_t &pos)
{
    if (pos < WIDTH * HEIGHT)
        p_side[pos / 8] ^= (1 << (pos % 8));
}

void GmAbstrBitBoard::setType(const std::size_t &pos, const std::size_t& n_type)
{
    p_types[(pos / 8) + (8 * n_type)] ^= (1 << (pos % 8));
}

bool GmAbstrBitBoard::getCell(const std::size_t &pos) const
{
    if (pos < WIDTH * HEIGHT)
        return p_cells[pos / 8] & (1 << (pos % 8));
    else
        return false;
}

bool GmAbstrBitBoard::getSide(const std::size_t &pos) const
{
    if (pos < WIDTH * HEIGHT)
        return p_side[pos / 8] & (1 << (pos % 8));
    else
        return false;
}

std::size_t GmAbstrBitBoard::getType(const std::size_t &pos) const
{
    std::size_t i;
    for (i = 0; i < TYPES; ++i)
        if (p_types[(pos / 8) + (8 * i)] & (1 << pos % 8))
            return i;
    return 0;
}

//////////////////////////////////////////////////////////////////////////////
///    2, 3, 4, 5, 5, 4, 6, 2,                                             ///
///    1, 1, 1, 1, 1, 1, 1, 1,                                             ///
///    0, 0, 0, 0, 0, 0, ...      - Typical example of chess forces arrangement
//////////////////////////////////////////////////////////////////////////////
/// \brief GmAbstrBitBoard::arrange                                        ///
/// \param lst {2, 3, 4, 5, 5, 4, 6, 2, 1, 1, 1, 1, 1, 1, 1, 1}            ///
//////////////////////////////////////////////////////////////////////////////
/// Arranges forces on board according how it was made for one side,       ///
/// but for both sides. Mirror-like way.                                   ///
//////////////////////////////////////////////////////////////////////////////

void GmAbstrBitBoard::arrange(const std::initializer_list<std::size_t> &lst)
{
    std::size_t i = 0;
    for (auto l_beg = lst.begin(); l_beg != lst.end(); ++l_beg)
    {
        if (*l_beg != 0)
        {
            setCell(i);                             //player 0
            setType(i, *l_beg);

            setCell(WIDTH * HEIGHT - 1 - i);       // Player 1
            setType(WIDTH * HEIGHT - 1 - i, *l_beg);
            setSide(WIDTH * HEIGHT - 1 - i);
        }
        ++i;
    }
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
    std::cout << std::endl;
}



























