//
// Created by echen on 8/13/2021.
//
#include<string>
#include"card.h"
card::card(std::string suit_, int val_)
{
    suit=suit_;
    val=val_;
}
std::string card::getSuit()
{
    return suit;
}
int card::getVal()
{
    return val;
}