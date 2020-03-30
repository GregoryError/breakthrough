#include "breakthrough_game.h"
#include "GmBitBoard.h"
#include <ctime>
#include "player.h"
#include <QDebug>

Breakthrough_Game::Breakthrough_Game()
{    
    Player_Bohr = player(0, "qrc:/visualsources/players/bohr .png", "Niels Bohr");
    Player_Bohr.addQuote("На свете есть столь серьезные вещи, что говорить о них можно только шутя.");
    Player_Bohr.addQuote("Эксперт — это человек, который совершил все возможные ошибки в очень узкой специальности.");
    Player_Bohr.addQuote("Противоположности - не противоречия, они - дополнения.");

    Player_Lama = player(0, "qrc:/visualsources/players/dalai_lama_14.png", "Dalai Lama XIV");
    Player_Lama.addQuote("Процветание приходит благодаря действиям, а не благодаря молитвам.");
    Player_Lama.addQuote("Мы никогда не установим гармонию с окружающим миром, пока не примиримся с собой.");
    Player_Lama.addQuote("Когда человеку кажется, что всё идёт наперекосяк, в его жизнь пытается войти нечто чудесное.");

    Player_Einstein = player(0, "qrc:/visualsources/players/einstein .png", "Albert Einstein");
    Player_Einstein.addQuote("Только дурак нуждается в порядке — гений господствует над хаосом.");
    Player_Einstein.addQuote("Есть только две бесконечные вещи: Вселенная и глупость. Хотя насчет Вселенной я не уверен.");
    Player_Einstein.addQuote("При помощи совпадений Бог сохраняет анонимность.");

    Player_Hemingway = player(0, "qrc:/visualsources/players/hemingway .png", "Ernest Hemingway");
    Player_Hemingway.addQuote("Никогда не отправляйтесь в путешествие с теми, кого не любите.");
    Player_Hemingway.addQuote("Тот, кто щеголяет эрудицией или ученостью, не имеет ни того, ни другого.");
    Player_Hemingway.addQuote("Если вы перестали делать какие-то вещи просто для удовольствия, считайте, что вы больше не живете.");

    Player_Hoking = player(0, "qrc:/visualsources/players/hokinq .png", "Stiven Hoking");
    Player_Hoking.addQuote("Я понятия не имею, какой у меня IQ. Те, кого интересует их IQ, просто неудачники.");
    Player_Hoking.addQuote("Перспектива рано умереть заставила меня понять, что жизнь стоит того, чтобы ее прожить.");
    Player_Hoking.addQuote("Среди всех систем, которые у нас есть, самые сложные - это наши собственные тела.");

    Player_Holmes = player(0, "qrc:/visualsources/players/holms.png", "Sherlok Holmes");
    Player_Holmes.addQuote("Пожалуйста, не говори вслух, ты понижаешь IQ всей улицы!");
    Player_Holmes.addQuote("Хочешь спрятать дерево — спрячь его в лесу.");
    Player_Holmes.addQuote("Вы смотрите, но вы не наблюдаете, а это большая разница.");

    Player_Popov = player(0, "qrc:/visualsources/players/popov.png", "Александр Попов");
    Player_Popov.addQuote("Счастлив я, что не за рубежом, а в России открыто новое средство связи.");
    Player_Popov.addQuote("Разум есть способность обобщать и обмениваться обобщением.");
    Player_Popov.addQuote("Здесь собран прибор для телеграфирования. Связной телеграммы мы не сумели послать, все детали приборов нужно ещё разработать.");

    Player_Tesla = player(0, "qrc:/visualsources/players/tesla.png", "Nikola Tesla");
    Player_Tesla.addQuote("Если вы хотите познать секреты вселенной - мыслите единицами измерения энергии, частоты и вибрации.");
    Player_Tesla.addQuote("Великие тайны нашего бытия еще только предстоит разгадать, даже смерть может оказаться не концом.");
    Player_Tesla.addQuote("Волны, создаваемые моим передатчиком, будут величайшим спонтанным проявлением энергии на планете.");

    backSound_0.setVolume(0.42);
    winSound.setVolume(0.70);

    moveSound.setSource(QUrl("qrc:/sounds/move.wav"));
    winSound.setSource(QUrl("qrc:/sounds/winsound.wav"));

    std::srand(std::time(0));
}

void Breakthrough_Game::setBoard(const std::size_t& w, const std::size_t& h)
{
    auto board(std::make_shared<Gm::GmBitBoard>(w, h, 2));


    short arrangeType = std::rand() % 5;


    if (arrangeType == 0)
        board->arrange({1, 1, 1, 1, 1, 1, 1, 1,
                        0, 0, 1, 1, 1, 1, 0, 0}, Gm::cross);

    if (arrangeType == 1)
        board->arrange({1, 1, 1, 1, 1, 1, 1, 1,
                        0, 1, 0, 0, 0, 0, 1, 0,
                        0, 0, 1, 0, 0, 1, 0, 0,
                        0, 0, 0, 1, 1, 0, 0, 0}, Gm::cross);

    if (arrangeType == 2)
        board->arrange({1, 1, 1, 1, 1, 1, 1, 1,
                        1, 0, 0, 0, 0, 0, 0, 1}, Gm::cross);

    if (arrangeType == 3)
        board->arrange({1, 1, 1, 1, 1, 1, 1, 1,
                        1, 0, 0, 0, 0, 0, 0, 1,
                        1, 0, 0, 0, 0, 0, 0, 1,
                        1, 0, 0, 0, 0, 0, 0, 1}, Gm::cross);

    if (arrangeType == 4)
        board->arrange({1, 1, 1, 1, 1, 1, 1, 1,
                        1, 1, 1, 1, 1, 1, 1, 1,
                        1, 1, 1, 1, 1, 1, 1, 1,
                        1, 1, 1, 1, 1, 1, 1, 1}, Gm::cross);






    addBoard(board);
    addFigure({0, 0, 0, 0, 0,
               0, 1, 1, 1, 0,
               0, 1, 1, 1, 0,
               0, 1, 1, 1, 0,
               0, 0, 0, 0, 0}, 1);  // Creating a pawn with some skills

    width_ = p_board->getWidth();
    height_ = p_board->getHeight();
}

Breakthrough_Game::~Breakthrough_Game()
{
    // delete p_board;
}

void Breakthrough_Game::start()
{
    static int playTimes = 1;
    if (playTimes % 2 == 0)
    {
        backSound_0.setSource(QUrl("qrc:/sounds/background_0.wav"));
    }
    else
        backSound_0.setSource(QUrl("qrc:/sounds/background_1.wav"));
    ++playTimes;

    switch (std::rand() % 8)
    {
    case 0: current_player = &Player_Bohr; break;
    case 1: current_player = &Player_Lama; break;
    case 2: current_player = &Player_Einstein; break;
    case 3: current_player = &Player_Hemingway; break;
    case 4: current_player = &Player_Hoking; break;
    case 5: current_player = &Player_Holmes; break;
    case 6: current_player = &Player_Popov; break;
    case 7: current_player = &Player_Tesla; break;
    default: break;
    }

    emit opponentReady();

    current_player->addBoard(p_board);

    current_player->play();

    backSound_0.play();

}

QString Breakthrough_Game::getQuote()
{
    return QString::fromStdString(current_player->getQuote());
}

void Breakthrough_Game::swapCell(const unsigned &A, const unsigned &B)
{
    struct TEMP_Cell
    {
        short side;
        unsigned pos;
        TEMP_Cell(const short& s, const unsigned& p)
        {
            side = s;
            pos = p;
        }
    };

    TEMP_Cell t(p_board->getSide(A), A);

    p_board->clearCell(A);
    p_board->setCell(A, 1);
    if (p_board->getSide(B))
        p_board->setSide(B);

    p_board->clearCell(B);
    p_board->setCell(B, 1);
    if (t.side == 0)
        p_board->setSide(t.pos);

}

bool Breakthrough_Game::isAvailable(const unsigned &from, const unsigned &to)
{
    return checkSkill(from, to);
}

void Breakthrough_Game::newGame()
{
    setBoard(8, 8);
    start();
    emit resetBoard();
}

void Breakthrough_Game::congrat()
{
    backSound_0.stop();
    winSound.play();
}

bool Breakthrough_Game::move_(const unsigned int &pos_from, const unsigned int &pos_to)
{
    auto res = move(getSide_(pos_from), pos_from, pos_to);
    moveSound.play();
    return res;
}

bool Breakthrough_Game::move_0(const unsigned &from, const unsigned &to)
{
    return move(0, from, to);
}

bool Breakthrough_Game::getSide_(const unsigned int& pos) const
{
    return p_board->getSide(pos);
}

unsigned int Breakthrough_Game::getCell_(const unsigned int& pos) const
{
    return p_board->getCell(pos);
}

void Breakthrough_Game::clearCell_(const std::size_t &pos)
{
    p_board->clearCell(pos);
}

bool Breakthrough_Game::hasUnit(const unsigned int &pos)
{
    return p_board->getCell(pos) && p_board->getSide(pos) == 1;
}

QString Breakthrough_Game::opponent_Name() const
{
    return QString::fromStdString(current_player->name);
}

QString Breakthrough_Game::opponent_img() const
{
    return QString::fromStdString(current_player->img_path);
}








































