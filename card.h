//
// Created by echen on 8/13/2021.
//

#ifndef ERS_CARD_H
#define ERS_CARD_H
class card
{
private:
    std::string suit;
    int val;
public:
    card(std::string suit_, int val_);
    std::string getSuit();
    int getVal();
};
#endif //ERS_CARD_H
