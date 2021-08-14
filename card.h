//
// Created by echen on 8/13/2021.
//
#pragma once
#include <string>

class card
{
private:
    std::string suit;
    int val;
public:
    card(std::string suit_, int val_);
    std::string getSuit();
    int getVal();
    void printCard();
};