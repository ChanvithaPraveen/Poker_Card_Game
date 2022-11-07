#include "Card.h"
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<random>
#include<string>
#include<vector>

using namespace std;

Card::Card()
{
	this->value = 0;
	this->suit = "default suit";
}

Card::Card(string suit, int value)
{
	this->value = value;
	this->suit = suit;
	this->name = name;
};

int Card::get_value() const
{
	return Card::value;
}

void Card::set_value(int value)
{
	this->value = value;
}

string Card::get_name()
{
	return Card::name;
}

void Card::set_name(string name)
{
	this->name = name;
}

string Card::get_suit()
{
	return Card::suit;
}

void Card::set_suit(string suit)
{
	this->suit = suit;
}

// this function returns the color of a card according to its suite
string Card::get_card_color() 
{
	if (this->get_suit() == "Heart" || this->get_suit() == "Diamond")
		return "Red";
	else return "Black";
}

//print card details
void Card::print_card() 
{
	cout << "\t\tThe card is: " << this->get_suit() << " " << this->get_value() << endl;
}






