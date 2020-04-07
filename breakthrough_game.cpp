#include <ctime>
#include <QDesktopServices>
#include "player.h"
#include "breakthrough_game.h"
#include "GmBitBoard.h"


//#include <QDebug>

Breakthrough_Game::Breakthrough_Game()
{    

   // dataSet.clear();

    Player_Bohr = player(0, "qrc:/visualsources/players/bohr .png", "Niels Bohr", 0);
    Player_Bohr.addQuote("На свете есть столь серьезные вещи, что говорить о них можно только шутя.");
    Player_Bohr.addQuote("Эксперт — это человек, который совершил все возможные ошибки в очень узкой специальности.");
    Player_Bohr.addQuote("Противоположности - не противоречия, они - дополнения.");
    if (!dataSet.value("Player_Bohr_win").isValid())
    {
        dataSet.setValue("Player_Bohr_win", 0);
        dataSet.setValue("Player_Bohr_lose", 0);
    }

    Player_Lama = player(0, "qrc:/visualsources/players/dalai_lama_14.png", "Dalai Lama XIV", 1);
    Player_Lama.addQuote("Процветание приходит благодаря действиям, а не благодаря молитвам.");
    Player_Lama.addQuote("Мы никогда не установим гармонию с окружающим миром, пока не примиримся с собой.");
    Player_Lama.addQuote("Когда человеку кажется, что всё идёт наперекосяк, в его жизнь пытается войти нечто чудесное.");
    if (!dataSet.value("Player_Lama_win").isValid())
    {
        dataSet.setValue("Player_Lama_win", 0);
        dataSet.setValue("Player_Lama_lose", 0);
    }

    Player_Einstein = player(0, "qrc:/visualsources/players/einstein .png", "Albert Einstein", 2);
    Player_Einstein.addQuote("Только дурак нуждается в порядке — гений господствует над хаосом.");
    Player_Einstein.addQuote("Есть только две бесконечные вещи: Вселенная и глупость. Хотя насчет Вселенной я не уверен.");
    Player_Einstein.addQuote("При помощи совпадений Бог сохраняет анонимность.");
    if (!dataSet.value("Player_Einstein_win").isValid())
    {
        dataSet.setValue("Player_Einstein_win", 0);
        dataSet.setValue("Player_Einstein_lose", 0);
    }

    Player_Hemingway = player(0, "qrc:/visualsources/players/hemingway .png", "Ernest Hemingway", 3);
    Player_Hemingway.addQuote("Никогда не отправляйтесь в путешествие с теми, кого не любите.");
    Player_Hemingway.addQuote("Тот, кто щеголяет эрудицией или ученостью, не имеет ни того, ни другого.");
    Player_Hemingway.addQuote("Если вы перестали делать какие-то вещи просто для удовольствия, считайте, что вы больше не живете.");
    if (!dataSet.value("Player_Hemingway_win").isValid())
    {
        dataSet.setValue("Player_Hemingway_win", 0);
        dataSet.setValue("Player_Hemingway_lose", 0);
    }

    Player_Hoking = player(0, "qrc:/visualsources/players/hokinq .png", "Stiven Hoking", 4);
    Player_Hoking.addQuote("Я понятия не имею, какой у меня IQ. Те, кого интересует их IQ, просто неудачники.");
    Player_Hoking.addQuote("Перспектива рано умереть заставила меня понять, что жизнь стоит того, чтобы ее прожить.");
    Player_Hoking.addQuote("Среди всех систем, которые у нас есть, самые сложные - это наши собственные тела.");
    if (!dataSet.value("Player_Hoking_win").isValid())
    {
        dataSet.setValue("Player_Hoking_win", 0);
        dataSet.setValue("Player_Hoking_lose", 0);
    }

    Player_Holmes = player(0, "qrc:/visualsources/players/holms.png", "Sherlok Holmes", 5);
    Player_Holmes.addQuote("Пожалуйста, не говори вслух, ты понижаешь IQ всей улицы!");
    Player_Holmes.addQuote("Хочешь спрятать дерево — спрячь его в лесу.");
    Player_Holmes.addQuote("Вы смотрите, но вы не наблюдаете, а это большая разница.");
    if (!dataSet.value("Player_Holmes_win").isValid())
    {
        dataSet.setValue("Player_Holmes_win", 0);
        dataSet.setValue("Player_Holmes_lose", 0);
    }

    Player_Popov = player(0, "qrc:/visualsources/players/popov.png", "Александр Попов", 6);
    Player_Popov.addQuote("Счастлив я, что не за рубежом, а в России открыто новое средство связи.");
    Player_Popov.addQuote("Разум есть способность обобщать и обмениваться обобщением.");
    Player_Popov.addQuote("Здесь собран прибор для телеграфирования. Связной телеграммы мы не сумели послать, все детали приборов нужно ещё разработать.");
    if (!dataSet.value("Player_Popov_win").isValid())
    {
        dataSet.setValue("Player_Popov_win", 0);
        dataSet.setValue("Player_Popov_lose", 0);
    }

    Player_Tesla = player(0, "qrc:/visualsources/players/tesla.png", "Nikola Tesla", 7);
    Player_Tesla.addQuote("Если вы хотите познать секреты вселенной - мыслите единицами измерения энергии, частоты и вибрации.");
    Player_Tesla.addQuote("Великие тайны нашего бытия еще только предстоит разгадать, даже смерть может оказаться не концом.");
    Player_Tesla.addQuote("Волны, создаваемые моим передатчиком, будут величайшим спонтанным проявлением энергии на планете.");
    if (!dataSet.value("Player_Tesla_win").isValid())
    {
        dataSet.setValue("Player_Tesla_win", 0);
        dataSet.setValue("Player_Tesla_lose", 0);
    }

    backSound_0.setVolume(0.20);
    winSound.setVolume(0.55);
    loseSound.setVolume(0.60);
    moveSound.setVolume(1);

    moveSound.setSource(QUrl("qrc:/sounds/move.wav"));
    winSound.setSource(QUrl("qrc:/sounds/winsound.wav"));
    loseSound.setSource(QUrl("qrc:/sounds/lose.wav"));

    std::srand(std::time(0));

    if (!dataSet.value("music").isValid())
        dataSet.setValue("music", true);

    if (!dataSet.value("sound").isValid())
        dataSet.setValue("sound", true);

    if (!dataSet.value("firstIn").isValid())
        dataSet.setValue("firstIn", true);

    if (!dataSet.value("player_win").isValid())
    {
        dataSet.setValue("player_win", 0);
        dataSet.setValue("player_lose", 0);
    }

}

void Breakthrough_Game::setBoard(const std::size_t& w, const std::size_t& h)
{
    auto board(std::make_shared<Gm::GmBitBoard>(w, h, 2));

    short arrangeType = std::rand() % 7;

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
                        1, 0, 0, 0, 1, 0, 0, 1}, Gm::cross);

    if (arrangeType == 4)
        board->arrange({1, 1, 1, 1, 1, 1, 1, 1,
                        0, 1, 0, 1, 0, 1, 0, 1,
                        1, 0, 1, 0, 1, 0, 1, 0 }, Gm::cross);

    if (arrangeType == 5)
        board->arrange({1, 1, 1, 1, 1, 1, 1, 1,
                        0, 0, 1, 1, 1, 1, 0, 0}, Gm::cross);

    if (arrangeType == 6)
        board->arrange({1, 1, 1, 1, 1, 1, 1, 1,
                        0, 0, 1, 1, 1, 1, 0, 0}, Gm::cross);


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
    int playTimes = std::rand() % 4;

    if (playTimes == 0)
        backSound_0.setSource(QUrl("qrc:/sounds/background_0.wav"));
    if (playTimes == 1)
        backSound_0.setSource(QUrl("qrc:/sounds/background_1.wav"));
    if (playTimes == 2)
        backSound_0.setSource(QUrl("qrc:/sounds/background_2.wav"));
    if (playTimes == 3)
        backSound_0.setSource(QUrl("qrc:/sounds/background_3.wav"));

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

    need_music = dataSet.value("music").toBool();
    need_sound = dataSet.value("sound").toBool();

    if (need_sound && need_music)
        backSound_0.play();

    if (dataSet.value("firstIn").toBool()) // show game instructions for first launch
    {
        dataSet.setValue("firstIn", false);
        emit showRules();
    }

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
    if (need_sound)
    {
        backSound_0.stop();
        winSound.play();
    }
    dataSet.setValue("player_win", dataSet.value("player_win").toUInt() + 1);
    addDefeat();
}

void Breakthrough_Game::lose()
{
    if (need_sound)
    {
        backSound_0.stop();
        loseSound.play();
    }

    dataSet.setValue("player_lose", dataSet.value("player_lose").toUInt() + 1);
    addVictory();
}

void Breakthrough_Game::soundsOnOff()
{
    if (need_sound)
    {
        need_sound = false;
        dataSet.setValue("sound", false);
        backSound_0.stop();
    }
    else
    {
        need_sound = true;
        dataSet.setValue("sound", true);
    }


}

void Breakthrough_Game::musicOnOff()
{
    if (need_music && need_sound)
    {
        need_music = false;
        dataSet.setValue("music", false);
        backSound_0.stop();
    }
    else
    {
        need_music = true;
        dataSet.setValue("music", true);
        backSound_0.play();

    }
}

void Breakthrough_Game::openUrl(const QString &url)
{
    QDesktopServices::openUrl(QUrl(url, QUrl::TolerantMode));
}

void Breakthrough_Game::clickSound()
{
    if (need_sound)
        moveSound.play();
}

void Breakthrough_Game::addVictory()
{
    switch (current_player->player_num)
    {
    case 0: dataSet.setValue("Player_Bohr_win", dataSet.value("Player_Bohr_win").toUInt() + 1); break;
    case 1: dataSet.setValue("Player_Lama_win", dataSet.value("Player_Lama_win").toUInt() + 1); break;
    case 2: dataSet.setValue("Player_Einstein_win", dataSet.value("Player_Einstein_win").toUInt() + 1); break;
    case 3: dataSet.setValue("Player_Hemingway_win", dataSet.value("Player_Hemingway_win").toUInt() + 1); break;
    case 4: dataSet.setValue("Player_Hoking_win", dataSet.value("Player_Hoking_win").toUInt() + 1); break;
    case 5: dataSet.setValue("Player_Holmes_win", dataSet.value("Player_Holmes_win").toUInt() + 1); break;
    case 6: dataSet.setValue("Player_Popov_win", dataSet.value("Player_Popov_win").toUInt() + 1); break;
    case 7: dataSet.setValue("Player_Tesla_win", dataSet.value("Player_Tesla_win").toUInt() + 1); break;
    }
}

void Breakthrough_Game::addDefeat()
{
    switch (current_player->player_num)
    {
    case 0: dataSet.setValue("Player_Bohr_lose", dataSet.value("Player_Bohr_lose").toUInt() + 1); break;
    case 1: dataSet.setValue("Player_Lama_lose", dataSet.value("Player_Lama_lose").toUInt() + 1); break;
    case 2: dataSet.setValue("Player_Einstein_lose", dataSet.value("Player_Einstein_lose").toUInt() + 1); break;
    case 3: dataSet.setValue("Player_Hemingway_lose", dataSet.value("Player_Hemingway_lose").toUInt() + 1); break;
    case 4: dataSet.setValue("Player_Hoking_lose", dataSet.value("Player_Hoking_lose").toUInt() + 1); break;
    case 5: dataSet.setValue("Player_Holmes_lose", dataSet.value("Player_Holmes_lose").toUInt() + 1); break;
    case 6: dataSet.setValue("Player_Popov_lose", dataSet.value("Player_Popov_lose").toUInt() + 1); break;
    case 7: dataSet.setValue("Player_Tesla_lose", dataSet.value("Player_Tesla_lose").toUInt() + 1); break;
    }
}

unsigned Breakthrough_Game::showVictories()
{
    switch (current_player->player_num)
    {
    case 0: return dataSet.value("Player_Bohr_win").toUInt();
    case 1: return dataSet.value("Player_Lama_win").toUInt();
    case 2: return dataSet.value("Player_Einstein_win").toUInt();
    case 3: return dataSet.value("Player_Hemingway_win").toUInt();
    case 4: return dataSet.value("Player_Hoking_win").toUInt();
    case 5: return dataSet.value("Player_Holmes_win").toUInt();
    case 6: return dataSet.value("Player_Popov_win").toUInt();
    case 7: return dataSet.value("Player_Tesla_win").toUInt();
    default: return 0;
    }
}

unsigned Breakthrough_Game::showDefeats()
{
    switch (current_player->player_num)
    {
    case 0: return dataSet.value("Player_Bohr_lose").toUInt();
    case 1: return dataSet.value("Player_Lama_lose").toUInt();
    case 2: return dataSet.value("Player_Einstein_lose").toUInt();
    case 3: return dataSet.value("Player_Hemingway_lose").toUInt();
    case 4: return dataSet.value("Player_Hoking_lose").toUInt();
    case 5: return dataSet.value("Player_Holmes_lose").toUInt();
    case 6: return dataSet.value("Player_Popov_lose").toUInt();
    case 7: return dataSet.value("Player_Tesla_lose").toUInt();
    default: return 0;
    }
}

unsigned Breakthrough_Game::showPlayerVictories()
{
    return dataSet.value("player_win").toUInt();
}

unsigned Breakthrough_Game::showPlayerDefeats()
{
    return dataSet.value("player_lose").toUInt();
}

bool Breakthrough_Game::move_(const unsigned int &pos_from, const unsigned int &pos_to)
{
    auto res = move(getSide_(pos_from), pos_from, pos_to);
    if (need_sound)
        moveSound.play();
    return res;
}

int Breakthrough_Game::win_()
{
    return  win();
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








































