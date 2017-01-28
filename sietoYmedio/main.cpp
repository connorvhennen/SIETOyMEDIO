#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.hpp"

using namespace std;

// Global constants (if any)


// Non member functions declarations (if any)

//will activate a full turn
void turn(Player& userPlayer);

void game(){
    
}

// Stub for main
int main(){
    
    Player me(900);
    turn(me);
    return 0;
}

// Non member functions implementations (if any)
void turn(Player& userPlayer){
    
    int bet;
    std::cout << "You have: " << userPlayer.getMoney() << ". Enter bet: ";
    std::cin >> bet;
    
    //constructs hands for player and dealer
    Hand playerHand;
    Hand dealerHand;
    
    std::cout << "Your cards:" << std::endl;
    std::cout << "	    " << playerHand.getPlayerRank(0) << " de " << playerHand.getPlayerSuit(0) << "      (" << playerHand.getPlayerEnglishRank(0) << " of " << playerHand.getPlayerEnglishSuit(0) << ")." << std::endl;
    std::cout << "Your total is " << playerHand.getPlayerTotal() << ".  ";
    
    playerHand.dealToPlayer();
    dealerHand.dealToPlayer();
    
    if (playerHand.getPlayerTotal() >= 7.5) {
        userPlayer.loseMoney(bet);
    }
    else if (playerHand.getPlayerTotal() <= 7.5 && playerHand.getPlayerTotal() > dealerHand.getDealerTotal()) {
        userPlayer.winMoney(bet);
    }
    else if (playerHand.getPlayerTotal() <= 7.5 && playerHand.getPlayerTotal() == dealerHand.getDealerTotal()) {
        //it's a tie
        return;
    }
    else if (dealerHand.getDealerTotal() <= 7.5 && dealerHand.getDealerTotal() > playerHand.getPlayerTotal()) {
        userPlayer.loseMoney(bet);
    }
}
