#pragma once
#include "Card.h"
#include<iostream>
#include<stdlib.h>
#include<string>
#include<vector>

using namespace std;

class Player
{
private:
	string name;
	int id;
	int score;
	int points = 0;

public:
	Player();
	Player(string name, int id);
	vector<Card> card_hand;
	string get_name() const;
	void set_name(string name);
	int get_id();
	void set_id(int id);
	int get_score();
	void set_score(int score);
	int get_points();
	void set_points(int points);
	void print_hand();
	int compare_pattern(vector<Card> &card_deck);
};

