#include "player.h"
#include "card.h"
#include "deck.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <unordered_map>
bool isSlap(std::vector<int> pile)
{
    if(pile[0]==pile[pile.size()-1]||pile[pile.size()-1]==pile[pile.size()-3])
        return true;
    return false;
}
std::unordered_map<std::string,std::vector<int>> diff ={{"Easy",{800,5}},{"Normal",{500,6}},{"Hard",{400,8}},{"Challenging",{300,9}},{"Impossible",{200,10}}};
int main() {
    deck d(false);
    std::vector<player> players;
    int playerTurn=rand()%2;
    int face=0;
    std::cout<<"Welcome. You will be playing Egyptian Rat Screw against a computer"<<std::endl;
    std::cout<<"Name?"<<std::endl;
    std::string cheese;
    std::cin>>cheese;
    player player1(cheese,std::queue<card>());
    player computer("Computer",std::queue<card>());
    players.emplace_back(player1);
    players.emplace_back(computer);
    std::cout<<"Difficulty? Easy,Normal,Hard,Challenging,Impossible"<<std::endl;
    std::cin>>cheese;
    while(diff.find(cheese)==diff.end())
    {
        std::cout<<"That is not a difficulty option. Try again. "<<std::endl;
        std::cin>>cheese;
    }
    d.shuffle();
    d.deal(players);


}
