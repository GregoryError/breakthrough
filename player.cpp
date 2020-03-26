#include "player.h"
#include <random>
#include <ctime>
#include <algorithm>

#include <QDebug>


void player::goToCell(const unsigned& gap, const std::vector<unsigned>& forces_vct,
                    std::map<unsigned, std::vector<unsigned>>& possible_cells_map)
{
    unsigned minDistance = 64;
    for (unsigned i = 0; i < forces_vct.size(); ++i)
    {
        for (unsigned j = 0; j < possible_cells_map[forces_vct[i]].size(); ++j)
        {
            if (gap - possible_cells_map[forces_vct[i]][j] < minDistance)
            {
                minDistance = gap - possible_cells_map[forces_vct[i]][j];

                if (possible_cells_map[forces_vct[i]][j] - forces_vct[i] < 7)
                    continue;
                cell_from = forces_vct[i];
                cell_to = possible_cells_map[forces_vct[i]][j];
            }
        }
    }
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

        if (cell_to < free_cells_map[cell_from][i])
            cell_to = free_cells_map[cell_from][i];

        if (board->getCell(free_cells_map[cell_from][i]) && board->getSide(free_cells_map[cell_from][i]))
        {
            cell_to = free_cells_map[cell_from][i];             // try eat if item is near
            break;
        }

                    // choose a max

    }

    // TODO: here must be something that detect if there is a gap on a board and attack,
    // and if there is a dangerous context near own base and defense
    // How to know if need to defense?
    // - If opponent forces on cell less (or equal to) than 31
    // - Opponent forces concentrated on certain part of board (prepare for attack)
    // How to know if need to attack?
    // there is a gap on a opponent horizontal


    // check if need to defense

    unsigned distance = 64;
    unsigned protected_cell = 0;

    for (unsigned i = 0; i < 33; ++i)
    {
        if (board->getCell(i) && board->getSide(i))
        {
            for (unsigned j = 0; j < 8; ++j)
            {
                if (!board->getCell(j))
                {
                    if (board->getDistance(j, i) < distance)
                    {
                        distance = board->getDistance(j, i);
                        protected_cell = j;
                    }
                }
            }
        }
    }

    if (distance < 64)
    {
        goToCell(protected_cell, from_vct, free_cells_map);
    }



    // Attack

    for (unsigned i = 56; i < 64; ++i)
    {
        if (!board->getCell(i))
        {
            goToCell(i, from_vct, free_cells_map);
        }
    }


//    static int move_call = 1;
//    if (move_call % 2 == 0)
//    {
//        ++move_call;
//        for (unsigned i = 56; i < 64; ++i)
//        {
//            if (!board->getCell(i))
//            {
//                attack(i, from_vct, free_cells_map);
//            }
//        }

//        for (unsigned i = 0; i < 8; ++i)
//        {
//            if (!board->getCell(i))
//            {
//                attack(i, from_vct, free_cells_map);
//            }
//        }
//    }








    //    qDebug() << "player::from = " << cell_from << " player::to = " << cell_to;
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




























