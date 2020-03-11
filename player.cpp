#include "player.h"
#include <random>
#include <ctime>

#include <QDebug>

void player::play()
{
    cell_from = cell_to = 0;
    std::mt19937 gen(std::time(0));
    std::uniform_int_distribution<> uid(0, board->getWidth() * board->getHeight());

    // pointer to board allows us to know current state of forces on the field
    //


//    for (int i = 0; i < 15; ++i)
//        qDebug() << uid(gen) << " - ";


}
