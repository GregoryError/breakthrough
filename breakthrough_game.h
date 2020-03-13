#ifndef BREAKTHROUGH_GAME_H
#define BREAKTHROUGH_GAME_H
#include <QObject>

#include "GmAbstrBoardGame.h"
#include "GmBreakthroughStrategy.h" // - Certain strategy of game. Sets of rules; main logic etc
#include "player.h"
#include <QString>


class Breakthrough_Game : public QObject, Gm::GmAbstrBoardGame<Gm::GmBreakthroughStrategy>
{
    Q_OBJECT
private:
    unsigned width_, height_;

    player Player_Bohr;
    player Player_Lama;
    player Player_Einstein;
    player Player_Hemingway;
    player Player_Hoking;
    player Player_Holmes;
    player Player_Popov;
    player Player_Tesla;
    player* current_player;

public:
    Breakthrough_Game();
    void setBoard(const std::size_t& w = 8, const std::size_t& h = 8);
    ~Breakthrough_Game() override;

public slots:
    bool move_(const unsigned int& pos_from,
               const unsigned int& pos_to);

    int win_() { return win(); }

    bool getSide_(const unsigned int& pos) const;         // whose figure

    unsigned int getCell_(const unsigned int& pos) const;  // returns KIND of figure on 'pos'

    void clearCell_(const std::size_t& pos);

    bool eaten() { return isEaten(); }

    bool hasUnit(const unsigned int& pos);

    QString opponent_Name() const;

    QString opponent_img() const;

    unsigned int opponent_from() { return current_player->from(); }  // Artificial player is moving

    unsigned int opponent_to() { return current_player->to(); }

    void opponentPlay() { current_player->play(); }

    virtual void start() override;

    bool move_0(const unsigned& from, const unsigned& to);

signals:

    void opponentReady();

};

#endif // BREAKTHROUGH_GAME_H


