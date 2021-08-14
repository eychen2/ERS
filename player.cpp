
#include "card.h"
#include "player.h"
player::player(std::string name, std::queue<card> hand):name(name),hand(hand)
{
}
void player::addCards(std::vector<card> &cards)
{
    for(auto it = cards.cbegin();it!=cards.cend();++it)
    {
        hand.emplace(*it);
    }
    cards.clear();
}
void player::playCard(std::vector<card> &pile)
{
    card top = hand.front();
    hand.pop();
    pile.emplace_back(top);
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