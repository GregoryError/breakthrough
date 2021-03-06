#include "GmBitBoard.h"

using namespace Gm;

GmBitBoard::GmBitBoard(const std::size_t& height,
                       const std::size_t& width,
                       const std::size_t& tps)
{
    if (HEIGHT >= 6)
        HEIGHT = height;
    else
        HEIGHT = 8;
    if (width >= 8)
        WIDTH = width;
    else
        WIDTH = 8;

    TYPES = tps;
    board_space = (HEIGHT * WIDTH) / 8 + 1;
    p_side = std::make_unique<std::uint8_t[]>(board_space);
    p_forces = std::make_unique<std::uint8_t[]>(TYPES * board_space);
    for (std::size_t i = 0 ; i < board_space; ++i) p_side[i] = 0;
    for (std::size_t i = 0 ; i < (TYPES * board_space); ++i) p_forces[i] = 0;
}


//////////////////////////////////////////////////////////////////////////////
///    2, 3, 4, 5, 6, 4, 3, 2,                                             ///
///    1, 1, 1, 1, 1, 1, 1, 1,                                             ///
///    0, 0, 0, 0, 0, 0, ... - Typical example of chess forces arrangement ///
//////////////////////////////////////////////////////////////////////////////
/// \brief GmBitBoard::arrange                                        ///
/// \param lst {2, 3, 4, 5, 5, 4, 6, 2, 1, 1, 1, 1, 1, 1, 1, 1}            ///
//////////////////////////////////////////////////////////////////////////////
/// Arranges forces on board according how it was made for one side,       ///
/// but for both sides. Mirror-like way or directly.                       ///
//////////////////////////////////////////////////////////////////////////////

void GmBitBoard::arrange(const std::initializer_list<std::size_t> &lst, const BEG& beg)
{
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

void GmBitBoard::move(const std::size_t &pos_from, const std::size_t &pos_to)
{
    setCell(pos_to, getCell(pos_from));
    // setCell(pos_from, getCell(pos_to));
    clearCell(pos_from);

    if (getSide(pos_to))
        setSide(pos_to);

    if (getSide(pos_from))
    {
        setSide(pos_to);
        setSide(pos_from);
    }

  //  DIAG_showBoard();
}

bool GmBitBoard::getSide(const std::size_t &pos) const
{
    if (pos < WIDTH * HEIGHT)
        return p_side[pos / 8] & (1 << (pos % 8));
    else
        return false;
}

void GmBitBoard::setSide(const std::size_t &pos)
{
    if (pos < WIDTH * HEIGHT)
        p_side[pos / 8] ^= (1 << (pos % 8));
}

void GmBitBoard::setCell(const std::size_t &pos, const std::size_t& n_type)
{
    if (pos < WIDTH * HEIGHT)
    {
        p_forces[(pos / 8) + (8 * n_type)] ^= (1 << (pos % 8));
    }
}

unsigned GmBitBoard::getCell(const std::size_t& pos) const
{
    std::size_t i;
    for (i = 0; i < TYPES; ++i)
        if (p_forces[(pos / 8) + (8 * i)] & (1 << pos % 8))
            return i;
    return 0;
}

void GmBitBoard::clearCell(const std::size_t &pos)
{
    std::size_t i;
    for (i = 0; i < TYPES; ++i)
        if (p_forces[(pos / 8) + (8 * i)] & (1 << pos % 8))
            setCell(pos, i);
}

std::size_t GmBitBoard::getCellsRIGHT(const std::size_t &pos) const
{
    std::size_t i = 0;
    for (; i * WIDTH <= pos; ++i) ;
    return (i * WIDTH - pos) - 1;
}

std::size_t GmBitBoard::getCellsLEFT(const std::size_t &pos) const
{
    std::size_t i = 0;
    for (; i * WIDTH <= pos; ++i) ;
    return pos - (i * WIDTH - WIDTH);
}

std::size_t GmBitBoard::getCellsUP(const std::size_t &pos) const
{
    std::size_t i = 0;
    for (; i * WIDTH < pos; ++i) ;
    return (i == 0) ? i : (i - 1);
}

std::size_t GmBitBoard::getCellsDOWN(const std::size_t &pos) const
{
    std::size_t i = 0;
    for (; i * WIDTH < pos; ++i) ;
    return HEIGHT - i;
}

std::size_t GmBitBoard::getCellsLEFTUP(const std::size_t &pos) const
{
    return getCellsLEFT(pos) <= getCellsUP(pos) ? getCellsLEFT(pos) : getCellsUP(pos);
}

std::size_t GmBitBoard::getCellsRIGHTUP(const std::size_t &pos) const
{
    return getCellsRIGHT(pos) <= getCellsUP(pos) ? getCellsRIGHT(pos) : getCellsUP(pos);
}

std::size_t GmBitBoard::getCellsRIGHTDOWN(const std::size_t &pos) const
{
    return getCellsRIGHT(pos) <= getCellsDOWN(pos) ? getCellsRIGHT(pos) : getCellsDOWN(pos);
}

std::size_t GmBitBoard::getCellsLEFTDOWN(const std::size_t &pos) const
{
    return getCellsLEFT(pos) <= getCellsDOWN(pos) ? getCellsLEFT(pos) : getCellsDOWN(pos);
}

DIRECTION GmBitBoard::getDirection(const std::size_t &pos_from, const std::size_t &pos_to) const  // TODO: Check here not shure this works properly
{
    if (pos_to < pos_from)                            // -left, -leftUp, -up, -rightUp
    {
        auto rows = (pos_from - pos_to) / WIDTH;
        auto endPos = (rows * WIDTH) + rows;
        if (pos_to == pos_from - endPos)
            return leftUp;



        if (pos_from - pos_to <= getCellsLEFT(pos_from))
            return left;

        if ((pos_from - pos_to) % WIDTH == 0)
            return up;

        rows = ((pos_from - pos_to) / WIDTH) + 1;
        endPos = pos_from - (rows * WIDTH) + rows;
        if (pos_to == endPos)
            return rightUp;
    }

    if (pos_to > pos_from)                            // leftDown, -down, rightDown, -right
    {
        auto rows = (pos_to - pos_from) / WIDTH;
        auto endPos = (rows * WIDTH) + rows;
        if (pos_to == pos_from + endPos)
            return rightDown;

        if (pos_to - pos_from <= getCellsRIGHT(pos_from))
            return right;

        if ((pos_to - pos_from) % WIDTH == 0)
            return down;

        rows = ((pos_to - pos_from) / WIDTH) + 1;
        endPos = pos_from + (rows * WIDTH) - rows;
        if (pos_to == endPos)
            return leftDown;
    }

    return undefined;
}

std::size_t GmBitBoard::getDistance(const std::size_t &pos_from, const std::size_t &pos_to) const
{
    std::size_t row_first = 0;
    std::size_t row_second = 0;
    std::size_t diff = 0;
    if (pos_from > pos_to)
    {
        diff = pos_from - pos_to;
        for (row_first = pos_to; row_first % WIDTH != 0; --row_first) ;
        for (row_second = pos_from; row_second % WIDTH != 0; ++row_second) ;

    }
    if (pos_to > pos_from)
    {
        diff = pos_to - pos_from;
        for (row_first = pos_from; row_first % WIDTH != 0; --row_first) ;
        for (row_second = pos_to; row_second % WIDTH != 0; ++row_second) ;

    }

    if (pos_from < row_first && pos_to < row_second)
        if (diff == 1 || diff == 7 || diff == 8 || diff == 9) return diff;

    for (std::size_t i = 1; i < WIDTH; ++i)
        if (diff == 1 * i || diff == 7 * i || diff == 8 * i || diff == 9 * i) return i;
    return 0;
}

bool GmBitBoard::empty()
{
    for (std::size_t i = 0; i < WIDTH * HEIGHT; ++i)
        if (getCell(i))
            return false;
    return true;
}


///////// DIAGNOSTIC // delete leter

//void GmBitBoard::DIAG_showBoard()
//{
//    std::cout << "DIAG_showBoard()::Sides\n";
//    for (std::size_t i = 0; i < WIDTH * HEIGHT; ++i)
//    {
//        std::cout << getSide(i) << " ";
//        if ((i + 1) % WIDTH == 0)
//            std::cout << '\n';
//    }


//    std::cout << "DIAG_showBoard()::Cells\n";
//    for (std::size_t i = 0; i < WIDTH * HEIGHT; ++i)
//    {
//        std::cout << getCell(i) << " ";
//        if ((i + 1) % WIDTH == 0)
//            std::cout << '\n';
//    }
//    std::cout << std::endl;

//}

//void GmBitBoard::DIAG_showMask()
//{
//    for (int i = 0; i < WIDTH * HEIGHT; ++i)
//    {
//        std::cout << i << ' ';
//        if ((i + 1) % WIDTH == 0)
//            std::cout << '\n';
//    }
//    std::cout << std::endl;

//}

//void GmBitBoard::DIAG_showDirection(const unsigned &from, const unsigned &to)
//{
//    std::cout << "DIAG_showDirection():\n";
//    switch (getDirection(from, to))
//    {
//    case DIRECTION::right: std::cout << "RIGHT"; break;
//    case DIRECTION::left: std::cout << "LEFT"; break;
//    case DIRECTION::up: std::cout << "UP"; break;
//    case DIRECTION::down: std::cout << "DOWN"; break;
//    case DIRECTION::leftUp: std::cout << "LEFT_UP"; break;
//    case DIRECTION::rightUp: std::cout << "RIGHT_UP"; break;
//    case DIRECTION::rightDown: std::cout << "RIGHT_DOWN"; break;
//    case DIRECTION::leftDown: std::cout << "LEFT_DOWN"; break;
//    default: std::cout << "undefined\n"; break;
//    }
//    std::cout << std::endl;
//}




















