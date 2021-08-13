#include <queue>
#include <string>
#include "card.h"
#include "player.h"
player::player(std::string name_, std::queue<card> hand_)
{
    name=name_;
    hand=hand_;
}
void player::addCards(std::vector<card> &cards)
{
    for(auto it = cards.cbegin();it!=cards.cend();++it)
    {
        hand.push(*it);
    }
    cards.clear();
}
void player::playCard(std::vector<card> &pile)
{
    card top = hand.front();
    hand.pop();
    pile.push_back(top);
}
std::string player::getName()
{
    return name;
}
std::queue<card> player::getHand()
{
    return hand;
}
int player::getHandSize()
{
    return hand.size();
}