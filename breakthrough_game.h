#ifndef BREAKTHROUGH_GAME_H
#define BREAKTHROUGH_GAME_H
#include <QObject>

#include <GmAbstrBoardGame.h>
#include <GmBreakthroughStrategy.h> // - Certain strategy of game. Sets of rules; main logic etc


class Breakthrough_Game : public QObject, Gm::GmAbstrBoardGame<Gm::GmBreakthroughStrategy>
{
    Q_OBJECT
private:
    std::size_t width_, height_;


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

    virtual void start() override;

signals:
   // void eaten();

};

#endif // BREAKTHROUGH_GAME_H
