#ifndef CARD_H
#define CARD_H
#include<iostream>
#include<stdlib.h>
#include<string>
#include<vector>

using namespace std;

class Card
{
private:
	int value;
	string name;
	string suit;
	
public:
	Card();
	Card(string suit, int value);
	vector<int> value_array{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
	vector<string> name_array{ "One", "Two", "Three", "Four", "Five", "Six", "Seven",
							"Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace" };
	vector<string> suit_array{ "Spade", "Diamond", "Heart", "Club" };
	
	int get_value() const;
	void set_value(int value);
	string get_name();
	void set_name(string name);
	string get_suit();
	void set_suit(string suit);
	string get_card_color();
	void print_card();
	
};

#endif