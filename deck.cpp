//
// Created by echen on 8/13/2021.
//
#include <array>
#include <bits/stdc++.h>
#include "card.h"
#include "player.h"
#include "deck.h"
std::array<std::string,4> suite = { "Club", "Diamond","Heart", "Spade" };
deck::deck(bool joker)
{
    for(unsigned int i=0; i<4;++i)
    {
        for(int j=1; j<14;++j)
        {
            deck_.emplace_back(card(suite[i],j));
        }
    }
    if(joker)
    {
        deck_.emplace_back(card("black",14));
        deck_.emplace_back(card("red",14));
    }
}
void deck::shuffle()
{
    unsigned seed =0;
    std::shuffle(deck_.begin(), deck_.end(),std::default_random_engine(seed));
}
void deck::deal(std::vector<player> & players)
{
    for(unsigned int i =0; i<players.size();++i)
    {
        std::vector<card> temp(deck_.begin()+i*deck_.size()/players.size(),deck_.begin()+(i+1)*deck_.size()/players.size());
        players[i].addCards(temp);
    }
}