//
// Created by echen on 8/13/2021.
//

#ifndef ERS_DECK_H
#define ERS_DECK_H
class deck
{
public:
    int size;
    vector<Card> deck_;
private:
    deck(int size_);
    void shuffle();
    void deal(vector<player> players);
};
#endif //ERS_DECK_H
