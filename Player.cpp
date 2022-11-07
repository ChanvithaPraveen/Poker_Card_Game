#include "Player.h"
#include "Card.h"
#include<iostream>
#include<stdlib.h>
#include<string>
#include<vector>

using namespace std;

Player::Player()
{
	this->name = "Player1";
	this->id = 1;
}

Player::Player(string name, int id)
{
	this->name = name;
	this->id = id;
}

string Player::get_name() const
{
	return Player::name;
}

void Player::set_name(string name)
{
	this->name = name;
}

int Player::get_id()
{
	return Player::id;
}

void Player::set_id(int id)
{
	this->id = id;
}

int Player::get_score()
{
    return Player::score;
}

void Player::set_score(int score)
{
    this->score = score;
}

int Player::get_points()
{
    return Player::points;
}

void Player::set_points(int points)
{
    this->points += points;
}

void Player::print_hand()
{

	for (int i = 0; i < 5; i++)
	{
		this->card_hand[i].print_card();
	}
}

int Player::compare_pattern(vector<Card> &card_hand)
{
    //sort the carh_hand according to the value
	Card temp;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (card_hand[j].get_value() > card_hand[j+1].get_value())
			{
				temp = card_hand[j];
				card_hand[j] = card_hand[j+1];
				card_hand[j+1] = temp;
			}			
		}
	}
	

    //check for straight flush
    if (card_hand[0].get_suit() == card_hand[1].get_suit() && card_hand[1].get_suit() == card_hand[2].get_suit()
        && card_hand[2].get_suit() == card_hand[3].get_suit() && card_hand[3].get_suit() == card_hand[4].get_suit())
        return 90;

    //check for four of a kind
    else if (card_hand[0].get_value() == card_hand[3].get_value() || card_hand[1].get_value() == card_hand[4].get_value())
        return 80;

    //check for three of a kind and pair
    else if ((card_hand[0].get_value() == card_hand[1].get_value() && card_hand[2].get_value() == card_hand[4].get_value())
        || (card_hand[0].get_value() == card_hand[2].get_value() && card_hand[3].get_value() == card_hand[4].get_value()))
        return 70;

    //check whether all five cards are in same color
    else if (card_hand[0].get_card_color() == card_hand[1].get_card_color() && card_hand[1].get_card_color() == card_hand[2].get_card_color()
        && card_hand[2].get_card_color() == card_hand[3].get_card_color() && card_hand[3].get_card_color() == card_hand[4].get_card_color())
        return 60;

    //check whether five cards are in sequence
    else if ((card_hand[0].get_value() + 1 == card_hand[1].get_value() && card_hand[1].get_value() + 1 == card_hand[2].get_value()
        && card_hand[2].get_value() + 1 == card_hand[3].get_value() && card_hand[3].get_value() + 1 == card_hand[4].get_value())
        || (card_hand[4].get_value() == 14 && card_hand[0].get_value() == 2 && card_hand[1].get_value() == 3 && card_hand[2].get_value() == 4
            && card_hand[3].get_value() == 5))
        return 50;

    //check for three of a kind
    else if (card_hand[0].get_value() == card_hand[2].get_value() || card_hand[1].get_value() == card_hand[3].get_value()
        || card_hand[2].get_value() == card_hand[4].get_value())
        return 40;

    //check for two pairs
    else if ((card_hand[0].get_value() == card_hand[1].get_value() && card_hand[2].get_value() == card_hand[3].get_value()) ||
        (card_hand[1].get_value() == card_hand[2].get_value() && card_hand[3].get_value() == card_hand[4].get_value()) ||
        (card_hand[0].get_value() == card_hand[1].get_value() && card_hand[3].get_value() == card_hand[4].get_value()))
        return 30;

    //high card
    else 
    {
        for (int i = 0;i < 4;i++) 
        {
            if (card_hand[i].get_value() == card_hand[i + 1].get_value()) 
            {
                return 20;
            }
        }

        return card_hand[4].get_value();
    }
}

