//
// Created by echen on 8/13/2021.
//

#ifndef ERS_PLAYER_H
#define ERS_PLAYER_H
class player
{
private:
    queue<card> hand;
    std::string name;
public:
    player(std::string name_, queue<card> hand_);

};
#endif //ERS_PLAYER_H
