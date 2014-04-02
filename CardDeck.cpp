//Spencer King, Lab 4 Part 3, Blackjack, CardDeck.cpp

#include <iostream>
#include <deque>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <list>
#include "CardDeck.h"
using namespace std;

//overloaded << operator, prints the deck 
ostream &operator<<( ostream &print, const CardDeck &Deck1 ){
	for (int i=0; i<Deck1.getSize(); i++){
		print << Deck1.getCard(i) << ", ";
	}
	print << endl;
	return (print);
}



//non-default constructor to determine deck size
CardDeck::CardDeck(int n){
	
	srand(time(NULL)); //seeds with time
	for (int i=0; i!=n; i++){
		Deck.push_back(i);
	}


}

//returns a card
int CardDeck::getCard(int i) const{
	return (Deck[i]);
}

//returns the size of the deck
int CardDeck::getSize() const{

	return (Deck.size());

}


//shuffles the deck
void CardDeck::shuffle(){

	std::random_shuffle(Deck.begin(), Deck.end());

}

//prints the deck
void CardDeck::print(){
	cout << *this <<endl;
}

//deals a card
int CardDeck::Deal(int i){
	return (Deck[i]);
}

//player stands
int CardDeck::stand(int i){
	int dealer=0;
	int card;
	card=CardDeck::Deal(i); //deal a card
	card=card%12+2; //convert the number to an actual playing card number
	if (card>10){ //if number greater than 10, set value to 10
		card=10;
	}
	if (card==1){ //if ace, set value to 11
		card=11;
	}
	dealer=dealer+card; //add value to dealer's current score
	return (dealer); //return the score

}

//player hits
int CardDeck::hit(int score, int i){
	int card;
	card=CardDeck::Deal(i); //deal a card
	card=card%12+2; //convert the number to an actual playing card number
	if (card>10){ //if number greater than 10, set value to 10
		card=10;
	}
	if (card==1){ //if ace, set value to 11
		card=11;
	}
	score=score+card; //add value to player's current score
	cout<< "Your score: " << score <<endl; //print the score
	return (score); //return the score

}

//checks if elements are in non-decreasing order
int CardDeck::inOrder(){

	for (int i=0; i<Deck.size()-1; i++){ //for loop runs through the deck
		if (Deck[i]<=Deck[i+1]){ //cards in order
			
		}
		else{ //cards not in order
			return 0;
		}
	}
	return 1;

}

//plays blackjack
void CardDeck::blackjack(int playerWins, int dealerWins, CardDeck Deck1){
int y=2; //while loop condition
int currentCard=0; //keeps track of how many cards have been dealt
while (y==2){
	int x=2; //while loop condition
	int score=0;
	int j;
	int dealerScore=0;
	string playerInput;
	while(x==2){
		cout<< "hit or stand?" << endl; //reads in a move
		cin >> playerInput;
		if (playerInput=="hit"){
			score=Deck1.hit(score, currentCard);//gets score
			currentCard++; //increment cards dealt
			if (score>21){ //checks if player lost
				cout << "You lose!" <<endl;
				dealerWins++; //increment dealer win count
				x=3;
			}
		}
		else if(playerInput=="stand"){
			while (dealerScore<17){
				j=Deck1.stand(currentCard);//deals card
				currentCard++; //increment cards dealt
				dealerScore=dealerScore+j; //get score
			}
			cout<< "Dealer score: " << dealerScore <<endl;
			if (dealerScore>21){ //checks if dealer lost
				cout << "You win!" <<endl;
				playerWins++; //increment player win count
				x=3;
			}
			else if(dealerScore>score){ //checks if player lost
				cout << "You lose!" <<endl;
				dealerWins++; //increment dealer win count
				x=3;
			}
			else if(score>dealerScore){ //checks if player lost
				cout << "You win!" <<endl;
				playerWins++; //increment dealer win count
				x=3;
			}
			else{
				cout << "You lose!" <<endl;
				dealerWins++;
				x=3;
			}
		}
		
	}
	cout<< "Player wins: " << playerWins << endl; //print win counts
	cout<< "Dealer wins: " << dealerWins << endl;
	cout<< "Would you like to play again?" << endl;
	cin >> playerInput;
	if (playerInput=="no"){ //checks if player wants to continue
		y=3;
	}
	if (currentCard>37){ //checks if less than 15 cards left
		currentCard=0; //set dealt cards to 0
		Deck1.shuffle(); //reshuffle the deck
	}
}



}

