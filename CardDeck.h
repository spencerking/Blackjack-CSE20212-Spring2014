//Spencer King, Lab 4 Part 3, Blackjack, CardDeck.h

#ifndef CARDDECK_H
#define CARDDECK_H
#include <iostream>
#include <deque>

using namespace std;

class CardDeck{

friend ostream &operator<<( ostream &, const CardDeck & );

	public:
	CardDeck(int=52); //non-default constructor, takes int number of cards
	int getSize() const; //returns the size of the deck
	int getCard(int) const; //returns a card
	void shuffle(); //shuffles the deck
	void print(); //prints the array
	int inOrder(); //check if elements are in non-decreasing order
	int Deal(int); //deals cards
	void Blackjack(); //plays blackjack
	int hit(int, int);  //player hits
	int stand(int); //player stands
	void blackjack(int, int, CardDeck);

	private:
	deque<int> Deck;


};

#endif
