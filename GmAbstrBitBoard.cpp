#include "GmAbstrBitBoard.h"

using namespace Gm;

GmAbstrBitBoard::GmAbstrBitBoard(const std::size_t& height,
                const std::size_t& width,
                const std::size_t& tps)
{
    WIDTH = width;
    HEIGHT = height;

    board_space = (height * width) / 8 + 1;
    p_cells = std::make_unique<std::int8_t[]>(board_space);
    p_side = std::make_unique<std::int8_t[]>(board_space);
    p_types = std::make_unique<std::int8_t[]>(tps / 8 + 1);

   // p_cells = std::unique_ptr<std::int8_t[]>(new std::int8_t[board_space]);
   // p_side = std::unique_ptr<std::int8_t[]>(new std::int8_t[board_space]);
   // p_types = std::unique_ptr<std::int8_t[]>(new std::int8_t[tps / 8 + 1]);


}

bool GmAbstrBitBoard::getCell(const std::size_t &pos)
{
    return p_cells[pos / 8] & (1 << (pos % 8));
}

bool GmAbstrBitBoard::getSide(const std::size_t &pos)
{
    return p_side[pos / 8] & (1 << (pos % 8));
}


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
