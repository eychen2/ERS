//
// Created by echen on 8/13/2021.
//
#pragma once

#include <vector>

class deck
{

    int size;
public:
    std::vector<card> deck_;
    deck(bool joker);
    void shuffle();
    void deal(std::vector<player> &players);
};

