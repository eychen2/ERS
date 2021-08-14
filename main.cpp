#include <iostream>
#include <chrono>
#include <thread>
#include "player.h"
#include "card.h"
#include "deck.h"
bool isSlap(std::vector<int> pile)
{
    if(pile[0]==pile[pile.size()-1]||pile[pile.size()-1]==pile[pile.size()-3])
        return true;
    return false;
}
int main() {
    card c("heart",2);
    return 0;
}
