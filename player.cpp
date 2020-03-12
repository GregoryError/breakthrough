#include "player.h"
#include <random>
#include <ctime>
#include <vector>
#include <map>
#include <algorithm>

#include <QDebug>

void player::play()
{
    unsigned board_SZ = board->getWidth() * board->getHeight();

    cell_from = cell_to = 0;
    std::mt19937 gen(std::time(0));


    std::map<unsigned, std::vector<unsigned>> free_cells_map;

    std::vector<unsigned> t_vct, from_vct;

    for (unsigned i = 0; i < (board_SZ); ++i)
    {
        if (board->getSide(i) == 0 && board->getCell(i))
        {
            if (i > 1)
                if (checkCell(i, i - 1))
                    t_vct.push_back(i - 1);
            if (i > 7)
                if (checkCell(i, i - 7))
                    t_vct.push_back(i - 7);
            if (i > 8)
                if (checkCell(i, i - 8))
                    t_vct.push_back(i - 8);
            if (i > 9)
                if (checkCell(i, i - 9))
                    t_vct.push_back(i - 9);

            if ((i + 1) < board_SZ)
                if (checkCell(i, i + 1))
                    t_vct.push_back(i + 1);
            if ((i + 7) < board_SZ)
                if (checkCell(i, i + 7))
                    t_vct.push_back(i + 7);
            if ((i + 8) < board_SZ)
                if (checkCell(i, i + 8))
                    t_vct.push_back(i + 8);
            if ((i + 9) < board_SZ)
                if (checkCell(i, i + 9))
                    t_vct.push_back(i + 9);

            if (!t_vct.empty())
            {
                free_cells_map.insert(std::pair<unsigned, std::vector<unsigned>>(i, t_vct));
                from_vct.push_back(i);
            }
            t_vct.clear();
        }
    }


    std::random_shuffle(from_vct.begin(), from_vct.end());

    cell_from = from_vct[0];

    std::uniform_int_distribution<> uid_to(0, free_cells_map[cell_from].size());

    cell_to = free_cells_map[cell_from][uid_to(gen)];
}
