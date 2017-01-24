#include "cards.hpp"
#include <cstdlib>
#include <iostream>

/* 
 You might or might not need these two extra libraries 
 #include <iomanip>
 #include <algorithm>
 */


/* *************************************************
 Card class
 ************************************************* */

/* 
 Default constructor for the Card class.
 It could give repeated cards. This is OK.
 Most variations of Blackjack are played with 
 several decks of cards at the same time.
 */
Card::Card(){
    int r = 1 + rand() % 4;
    switch (r) {
        case 1: suit = OROS; break;
        case 2: suit = COPAS; break; 
        case 3: suit = ESPADAS; break;
        case 4: suit = BASTOS; break; 
        default: break;
    }
    
    r = 1 + rand() % 10;  
    switch (r) {
        case  1: rank = AS; break; 
        case  2: rank = DOS; break; 
        case  3: rank = TRES; break; 
        case  4: rank = CUATRO; break; 
        case  5: rank = CINCO; break; 
        case  6: rank = SEIS; break; 
        case  7: rank = SIETE; break; 
        case  8: rank = SOTA; break; 
        case  9: rank = CABALLO; break; 
        case 10: rank = REY; break; 
        default: break;
    }
}

// Accessor: returns a string with the suit of the card in Spanish 
string Card::get_spanish_suit() const { 
    string suitName;
    switch (suit) {
        case OROS: 
            suitName = "oros"; 
            break;
        case COPAS: 
            suitName = "copas"; 
            break; 
        case ESPADAS: 
            suitName = "espadas"; 
            break;
        case BASTOS: 
            suitName = "bastos"; 
            break; 
        default: break;
    }
    return suitName;
}

// Accessor: returns a string with the rank of the card in Spanish 
string Card::get_spanish_rank() const { 
    string rankName;
    switch (rank) {
        case AS:
            rankName = "As"; 
            break; 
        case DOS: 
            rankName = "Dos"; 
            break; 
        case TRES: 
            rankName = "Tres"; 
            break; 
        case CUATRO: 
            rankName = "Cuatro"; 
            break; 
        case CINCO: 
            rankName = "Cinco"; 
            break; 
        case SEIS: 
            rankName = "Seis"; 
            break; 
        case SIETE: 
            rankName = "Siete"; 
            break; 
        case SOTA: 
            rankName = "Sota"; 
            break; 
        case CABALLO: 
            rankName = "Caballo"; 
            break; 
        case REY: 
            rankName = "Rey"; 
            break; 
        default: break;
    }
    return rankName;
}



// Accessor: returns a string with the suit of the card in English 
// This is just a stub! Modify it to your liking.
string Card::get_english_suit() const { 
    string suitName;
    switch (suit) {
        case OROS: 
            suitName = "coins"; 
            break;
        case COPAS: 
            suitName = "cups"; 
            break; 
        case ESPADAS: 
            suitName = "spades"; 
            break;
        case BASTOS: 
            suitName = "clubs"; 
            break; 
        default: break;
    }
    return suitName;}

// Accessor: returns a string with the rank of the card in English 
// This is just a stub! Modify it to your liking.
string Card::get_english_rank() const { 
    string rankName;
    switch (rank) {
        case AS:
            rankName = "Ace"; 
            break; 
        case DOS: 
            rankName = "Two"; 
            break; 
        case TRES: 
            rankName = "Three"; 
            break; 
        case CUATRO: 
            rankName = "Four"; 
            break; 
        case CINCO: 
            rankName = "Five"; 
            break; 
        case SEIS: 
            rankName = "Six"; 
            break; 
        case SIETE: 
            rankName = "Seven"; 
            break; 
        case SOTA: 
            rankName = "Jack"; 
            break; 
        case CABALLO: 
            rankName = "Knight"; 
            break; 
        case REY: 
            rankName = "King"; 
            break; 
        default: break;
    }
    return rankName;
}



// Assigns a numerical value to card based on rank.
// AS=1, DOS=2, ..., SIETE=7, SOTA=10, CABALLO=11, REY=12
int Card::get_rank() const {
    return static_cast<int>(rank) + 1 ;
}

// Comparison operator for cards
// Returns TRUE if card1 < card2
bool Card::operator < (Card card2) const {
    return rank < card2.rank;
}



/* *************************************************
 Hand class
 ************************************************* */
//need default hand() constructor
Hand::Hand(){
    Card randomPlayerCard;
    playerHand.push_back(randomPlayerCard.get_rank());
    
    Card randomDealerCard;
    dealerHand.push_back(randomDealerCard.get_rank());

}

//will ask player if he wants to be dealt a card and will do so until user says no or until his total value is 7.5 or greater
void Hand::dealToPlayer(){
    
    //player will only have option to be dealt cards if his total is less than 7.5
    while (getPlayerTotal() < 7.5) {

    
    //string that will record whether or not player wants another hand
    std::string dealCard;
    
    std::cout << "Do you want another card (y/n)?" << std::endl;
    std::cin >> dealCard;
    
    while (dealCard == "y") {
        
        Card randomCard;
        
        //will account for rank of card, and it's effect on total number, but not suit of card 
        playerHand.push_back(randomCard.get_rank());

        std::cout << "Do you want another card (y/n)?";
        std::cin >> dealCard;
    }
}
}

//accessor, returns the total sum of the players card values
int Hand::getPlayerTotal(){
    
    int playerTotal = 0;
    for (size_t i = 1; i < playerHand.size(); ++i) {
        playerTotal = playerTotal + playerHand[i];
    }
    
    return playerTotal;
}

// will automatically deal cards to dealer until his or her card total reaches 5.5
void Hand::dealToDealer(){
    
    //player will only have option to be dealt cards if his total is less than 7.5
    while (getDealerTotal() < 5.5) {

        Card randomCard;
            
        //will account for rank of card, and it's effect on total number, but not suit of card 
        dealerHand.push_back(randomCard.get_rank());

    }
}


//accessor, returns the total sum of the players card values
int Hand::getDealerTotal(){
    
    int dealerTotal = 0;
    for (size_t i = 1; i < dealerHand.size(); ++i) {
        dealerTotal = dealerTotal + dealerHand[i];
    }
    
    return dealerTotal;
}



/* *************************************************
 Player class
 ************************************************* */

//default constructor
Player::Player(int m){
    money = m;
}

int Player::getMoney(){
    return money;
}

void Player::loseMoney(int betAmount){
    money = money - betAmount;
}

void Player::winMoney(int betAmount){
    money = money + betAmount;
}

