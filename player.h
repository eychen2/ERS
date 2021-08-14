//
// Created by echen on 8/13/2021.
//
#pragma once
#include <queue>
#include <string>
#include "card.h"
class player
{
private:
    std::queue<card> hand;
    std::string name;
public:
    player(std::string name_, std::queue<card> hand_);
    void addCards(std::vector<card> &cards);
    void addCard(card& c);
    void playCard(std::vector<card> &pile);
    int getHandSize();
    std::string getName();
    std::queue<card> getHand();
};