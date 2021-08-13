//
// Created by echen on 8/13/2021.
//

#ifndef ERS_DECK_H
#define ERS_DECK_H
class deck
{
public:
    int size;
    queue<Card> deck_;
private:
    deck(int size_);
    void shuffle();

};
#endif //ERS_DECK_H
