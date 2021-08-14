//
// Created by echen on 8/13/2021.
//
#pragma once

#include <vector>

class deck
{
public:
    int size;
    std::vector<card> deck_;
private:
    deck(bool joker);
    void shuffle();
    void deal(std::vector<player> players);
};

