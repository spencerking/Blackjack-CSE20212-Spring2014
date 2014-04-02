//Spencer King, Lab 4 Part 3, Blackjack, main.cpp
#include <iostream>
#include "CardDeck.h"

using namespace std;

int main(){
	
	CardDeck Deck1(52); //instantiate a deck
	Deck1.shuffle();  //shuffle the deck
	Deck1.blackjack(0,0, Deck1); //play blackjack


}
