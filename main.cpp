#include "player.h"
#include "card.h"
#include "deck.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <unordered_map>
bool isSlap(std::vector<card> pile)
{
    if(pile.size()>1)
    {
        if(pile.size()>=3)
            return (pile[0].getVal()==pile[pile.size()-1].getVal())||(pile[pile.size()-1].getVal()==pile[pile.size()-3].getVal());
        else
            return (pile[0].getVal()==pile[pile.size()-1].getVal());
    }
    return false;
}
std::unordered_map<std::string,std::vector<int>> diff ={{"Easy",{800,5}},{"Normal",{500,6}},{"Hard",{400,8}},{"Challenging",{300,9}},{"Impossible",{200,10}}};
int main() {
    deck d(false);
    std::vector<player> players;
    int playerTurn=rand()%2;
    int face=0;
    char move;
    bool burn=false;
    int personBurned=0;
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
    char key;
    d.shuffle();
    d.deal(players);
    int pcChance = diff[cheese].back();
    int pcDelay = diff[cheese].front();
    std::cout<<"You will press the space key to slap and the enter key to play the next card. Good luck and have fun!"<<std::endl;
    std::cout<<"By coin flip, "<<players[playerTurn].getName()<< " will go first"<<std::endl;
    std::vector<card> pile;
    while(players[0].getHandSize()!=0&&players[1].getHandSize()!=0)
    {
        players[playerTurn].playCard(pile,burn);
        if(!burn)
        {
            std::cout << "The card that " << players[playerTurn].getName() << " played is ";
            pile[pile.size()-1].printCard();
        }
        else
        {
            std::cout << "The card that " << players[personBurned].getName() << " played is ";
            pile[0].printCard();
        }
        if(pile[pile.size()-1].getVal()>10)
            face=pile[pile.size()-1].getVal()-10;
        if(pile[pile.size()-1].getVal()==1)
            face=4;

        if(isSlap(pile))
        {
            bool compW=false;
            int compSlap = rand()%10+1;
            auto start = std::chrono::steady_clock::now();
            while(key!='\n'&&key!=' ')
            {
                if(std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now()-start).count()<pcDelay&&compSlap<=pcChance) {
                    break;
                    compW=true;
                }
                key = std::cin.get();
            }
            if(compW) {
                players[1].addCards(pile);
                playerTurn=1;
            }
            else if(key=='\n')
            {
                if(playerTurn==1)
                    playerTurn=0;
                else
                    playerTurn=1;
            }
            else
            {
                players[0].addCards(pile);
                playerTurn=0;
            }

        }
        else
        {
            burn = true;
        }
        if(!burn)
        {
            if(face>0)
            {
                --face;
                if(face==0)
                {
                    if(playerTurn==0)
                    {
                        std::cout << players[1].getName() << " has won the pile" << std::endl;
                        playerTurn=1;
                        players[1].addCards(pile);
                    }
                    else
                    {
                        std::cout << players[0].getName() << " has won the pile" << std::endl;
                        playerTurn=0;
                        players[0].addCards(pile);
                    }
                }
            }
            else
            {
                if(playerTurn==0)
                    playerTurn=1;
                else
                    playerTurn=0;
            }
        }
    }
}
