#include "player.h"
#include <random>
#include <ctime>
#include <vector>
#include <map>
#include <algorithm>

#include <QDebug>

void player::defense(const unsigned& gap)
{

}

void player::atack(const unsigned& gap)
{


}

void player::play()
{
    unsigned board_SZ = board->getWidth() * board->getHeight();

    GmAbstrPlayer::play();
    std::mt19937 gen(std::time(0));

    std::map<unsigned, std::vector<unsigned>> free_cells_map; // cells with forces

    std::vector<unsigned> t_vct, from_vct;

    for (unsigned i = 0; i < (board_SZ); ++i)
    {
        if (!board->getSide(i) && board->getCell(i))
        {
            if (i % 8 != 0 && (i - 7) % 8 != 0)
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
            }
            else
            {
                if (i % 8 == 0)
                {
                    if (i > 7)
                        if (checkCell(i, i - 7))
                            t_vct.push_back(i - 7);
                    if (i > 8)
                        if (checkCell(i, i - 8))
                            t_vct.push_back(i - 8);
                    if ((i + 1) < board_SZ)
                        if (checkCell(i, i + 1))
                            t_vct.push_back(i + 1);
                    if ((i + 8) < board_SZ)
                        if (checkCell(i, i + 8))
                            t_vct.push_back(i + 8);
                    if ((i + 9) < board_SZ)
                        if (checkCell(i, i + 9))
                            t_vct.push_back(i + 9);

                }
                if ((i - 7) % 8 == 0)
                {
                    if (i > 9)
                        if (checkCell(i, i - 9))
                            t_vct.push_back(i - 9);
                    if (i > 1)
                        if (checkCell(i, i - 1))
                            t_vct.push_back(i - 1);
                    if ((i + 7) < board_SZ)
                        if (checkCell(i, i + 7))
                            t_vct.push_back(i + 7);
                }
            }

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

    for (unsigned i = 0; i < from_vct.size() / 2; ++i)
        if (cell_from < from_vct[i])
            cell_from = from_vct[i];                     // random maximum from half (choose pos_from)

    cell_to = free_cells_map[cell_from][0];

    for (unsigned i = 0; i < free_cells_map[cell_from].size(); ++i)
    {

        if (board->getCell(free_cells_map[cell_from][i]) && board->getSide(free_cells_map[cell_from][i]))
        {
            cell_to = free_cells_map[cell_from][i];             // try eat if item is near
            break;
        }

        if (cell_to < free_cells_map[cell_from][i])
            cell_to = free_cells_map[cell_from][i];             // choose a max


    }


    // TODO: here must be something that detect if there is a gap on a board and atack,
    // and if there is a dangerous context near own base and defense


    qDebug() << "player::from = " << cell_from << " player::to = " << cell_to;
}




void player::DIAG_showPlayer(const std::map<unsigned, std::vector<unsigned>>& M)
{
    qDebug() << "Player base:\n";
    for (const auto& K : M)
    {
        qDebug() << "Key: " << K.first << ":\n";
        for (unsigned i = 0 ; i < K.second.size(); ++i)
        {
            qDebug() << K.second[i] << " ";
        }
    }
}




























