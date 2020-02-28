
void directionTest(Gm::GmAbstrBitBoard& board, int from, int to)
{
    std::cout << "From: " << from << ", to: " << to << "\n";
    if (board.getDirection(from, to) == Gm::right)
        std::cout << "to RIGHT\n";
    if (board.getDirection(from, to) == Gm::left)
        std::cout << "to LEFT\n";
    if (board.getDirection(from, to) == Gm::up)
        std::cout << "to UP\n";
    if (board.getDirection(from, to) == Gm::down)
        std::cout << "to DOWN\n";
    if (board.getDirection(from, to) == Gm::leftUp)
        std::cout << "to LEFTUP\n";
    if (board.getDirection(from, to) == Gm::rightUp)
        std::cout << "to RIGHTUP\n";
    if (board.getDirection(from, to) == Gm::rightDown)
        std::cout << "to RIGHTDOWN\n";
    if (board.getDirection(from, to) == Gm::leftDown)
        std::cout << "to LEFTDOWN\n";
}
