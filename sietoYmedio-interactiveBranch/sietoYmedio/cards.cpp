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
    srand (time(NULL));
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
    playerHandValue.push_back(randomPlayerCard.get_rank());
    playerHandSuit.push_back(randomPlayerCard.get_spanish_suit());
    playerHandRank.push_back(randomPlayerCard.get_spanish_rank());
    playerHandEnglishRank.push_back(randomPlayerCard.get_english_rank());
    playerHandEnglishSuit.push_back(randomPlayerCard.get_english_suit());
    
    
    Card randomDealerCard;
    dealerHandValue.push_back(randomDealerCard.get_rank());
    dealerHandSuit.push_back(randomDealerCard.get_spanish_suit());
    dealerHandRank.push_back(randomDealerCard.get_spanish_rank());
    dealerHandEnglishRank.push_back(randomDealerCard.get_english_rank());
    dealerHandEnglishSuit.push_back(randomDealerCard.get_english_suit());
    
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
            int cardNumber = 0;
            
            Card randomCard;
            
            playerHandValue.push_back(randomCard.get_rank());
            playerHandSuit.push_back(randomCard.get_spanish_suit());
            playerHandRank.push_back(randomCard.get_spanish_rank());
            playerHandEnglishRank.push_back(randomCard.get_english_rank());
            playerHandEnglishSuit.push_back(randomCard.get_english_suit());
            
            std::cout << "Do you want another card (y/n)?";
            std::cin >> dealCard;
            
            cardNumber = cardNumber + 1;
            
            playerHandValue.push_back(randomCard.get_rank());
            playerHandSuit.push_back(randomCard.get_spanish_suit());
            playerHandRank.push_back(randomCard.get_spanish_rank());
            playerHandEnglishRank.push_back(randomCard.get_english_rank());
            playerHandEnglishSuit.push_back(randomCard.get_english_suit());
            
            std::cout << "New card:" << std::endl;
            
        }
    }
}

//accessor, returns the total sum of the players card values
int Hand::getPlayerTotal(){
    
    int playerTotal = 0;
    for (size_t i = 0; i <= playerHandValue.size(); ++i) {
        playerTotal = playerTotal + playerHandValue[i];
    }
    
    return playerTotal;
}

// will automatically deal cards to dealer until his or her card total reaches 5.5
void Hand::dealToDealer(){
    
    //player will only have option to be dealt cards if his total is less than 7.5
    while (getDealerTotal() < 5.5) {
        
        Card randomCard;
        
        //will account for rank of card, and it's effect on total number, but not suit of card 
        dealerHandValue.push_back(randomCard.get_rank());
        dealerHandRank.push_back(randomCard.get_spanish_rank());
        dealerHandSuit.push_back(randomCard.get_spanish_suit());
        dealerHandEnglishRank.push_back(randomCard.get_english_rank());
        dealerHandEnglishSuit.push_back(randomCard.get_english_suit());
    }
}


//accessor, returns the total sum of the players card values
int Hand::getDealerTotal(){
    
    int dealerTotal = 0;
    for (size_t i = 0; i <= dealerHandValue.size(); ++i) {
        dealerTotal = dealerTotal + dealerHandValue[i];
    }
    
    return dealerTotal;
}

std::string Hand::getPlayerSuit(const int num){
    return playerHandSuit[num];
};

std::string Hand::getPlayerRank(const int num){
    return playerHandRank[num];
};

std::string Hand::getDealerSuit(const int num){
    return dealerHandSuit[num];
};

std::string Hand::getDealerRank(const int num){
    return dealerHandRank[num];
};

std::string Hand::getPlayerEnglishSuit(const int num){
    return playerHandEnglishSuit[num];
};

std::string Hand::getPlayerEnglishRank(const int num){
    return playerHandEnglishRank[num];
}

std::string Hand::getDealerEnglishSuit(const int num){
    return dealerHandEnglishSuit[num];
}
std::string Hand::getDealerEnglishRank(const int num){
    return dealerHandEnglishRank[num];
};

//std::string Hand::printCard(Hand playerHand, const int num){
//    std::cout << "	    " << playerHand.getPlayerRank(num) << " de " << playerHand.getPlayerSuit(num) << "      (" << playerHand.getPlayerEnglishRank(num) << " of " << playerHand.getPlayerEnglishSuit(num) << ")." << std::endl;
//};

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
