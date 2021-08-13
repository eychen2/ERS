//
// Created by echen on 8/13/2021.
//
#include<string>
#include <iostream>
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
void card::printCard()
{
    switch (val) {
        case 1:
            std::cout<<"Ace of " <<suit<<"s"<<std::endl;
            break;
        case 11:
            std::cout<<"Jack of " <<suit<<"s"<<std::endl;
            break;
        case 12:
            std::cout<<"Queen of " <<suit<<"s"<<std::endl;
            break;
        case 13:
            std::cout<<"King of " <<suit<<"s"<<std::endl;
            break;
        default:
            std::cout<<std::to_string(val) <<suit<<"s"<<std::endl;
            break;
    }
}