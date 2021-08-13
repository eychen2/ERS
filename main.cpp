#include <iostream>
#include <chrono>
#include <thread>
#include "player.cpp"
bool isSlap(std::vector<int> pile)
{
    if(pile[0]==pile[pile.size()-1]||pile[pile.size()-1]==pile[pile.size()-3])
        return true;
    return false;
}
int main() {
    return 0;
}
