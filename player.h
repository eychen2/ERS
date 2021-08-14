//
// Created by echen on 8/13/2021.
//
#include <queue>
#include <string>
#pragma once
class player
{
private:
    std::queue<card> hand;
    std::string name;
public:
    player(std::string name_, std::queue<card> hand_);
    void addCards(std::vector<card> &cards);
    void playCard(std::vector<card> &pile);
    int getHandSize();
    std::string getName();
    std::queue<card> getHand();
};