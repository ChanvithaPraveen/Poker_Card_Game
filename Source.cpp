#include "Card.h"
#include "Player.h"
#include<iostream>
#include<fstream>
#include<windows.h>
#include<string>
#include<vector>
using namespace std;

int main()
{
	Card card;
	char input1;
	int number_of_rounds;
	vector<Card> card_pack;
	vector<Card> shuffled_card_pack;
	Player dealer("Dealer", 1);
	Player player2("Alex", 2);
	Player player3("Ben", 3);
	Player player4("Mike", 4);
	ofstream log("Log.txt");

	//**********************************create card pack
	std::cout << "***********************POKER CARD GAME***********************" <<std::endl;
	log << "***********************POKER CARD GAME***********************\n" << std::endl;
	std::cout << "\nCards before shuffling:\n";
	
	//create a temporary suit array by using card class 
	vector<string> suit_arr = card.suit_array;for (int i = 0; i < 52; i++)
	{
		card_pack.push_back(Card(suit_arr[i % 4], (i % 13) + 2));
	}

	//print the card pack before shuffling
	for (int i = 0; i < 52; i++)
	{
		card_pack[i].print_card();
		log << "\t\tThe card is: " << card_pack[i].get_suit() << " " << card_pack[i].get_value() << endl;
	}

	//**********************************shuffle card pack
	
	//simulate_shuffle_card_pack
	std::cout << "\n**********ROUND**********\n";
	log << "\n**********ROUND**********\n";
	srand(time(NULL));
	int j;
	std::cout << "\nStart shuffling the card pack (Y/N): ";
	log << "\nStart shuffling the card pack (Y/N): ";
	cin >> input1;

	if ((input1 == 'Y') || (input1 == 'y'))
	{
		std::cout << "Shuffling the card pack";
		for (int i = 1; i < 5; i++)
		{
			cout << ".";
			Sleep(1000);
		}
		std::cout << "\n";

		//create random card and shuffle with sequence cards
		for (unsigned int i = 0; i < 52; i++)
		{
			int j = (rand() % 52);
			Card temp = card_pack[i];
			card_pack[i] = card_pack[j];
			card_pack[j] = temp;
		}

		//push back the random cards in to shuffled card pack vector
		for (int i = 0; i < 52; i++)
		{
			shuffled_card_pack.push_back(card_pack[i]);
		}

		//print the cards after shuffled
		std::cout << "\nCards after the shuffling:\n\n";
		log << "\nCards after the shuffling:\n\n";
		for (int i = 0; i < 52; i++)
		{
			shuffled_card_pack[i].print_card();
			log << "\t\tThe card is: " << shuffled_card_pack[i].get_suit() << " " << shuffled_card_pack[i].get_value() << endl;
		}
	}
	else
	{
		std::cout << "You have to shuffle the card pack to enter the game!!!\n";
		log << "You have to shuffle the card pack to enter the game!!!\n";
	}


	//*************************simulate_distribute_card_pack

	//remove last 2 cards from the card pack
	card_pack.pop_back();
	card_pack.pop_back();

	//simulate the distributing cards
	std::cout << "\nDealer is distributing cards";
	log << "\nDealer is distributing cards";
	for (int i = 1; i < 5; i++)
	{
		cout << ".";
		Sleep(1000);
	}
	std::cout << "\n\n";
	std::cout << "\t\t" << dealer.get_name() << ": Distributed\n";
	std::cout << "\t\t" << player2.get_name() << ": Distributed\n";
	std::cout << "\t\t" << player3.get_name() << ": Distributed\n";
	std::cout << "\t\t" << player4.get_name() << ": Distributed\n";

	log << "\n\n";
	log << "\t\t" << dealer.get_name() << ": Distributed\n";
	log << "\t\t" << player2.get_name() << ": Distributed\n";
	log << "\t\t" << player3.get_name() << ": Distributed\n";
	log << "\t\t" << player4.get_name() << ": Distributed\n";


	//distribute cards among the players including the dealer (card_hand)
	for (int i = 5; i < 10; i++)
		dealer.card_hand.push_back(shuffled_card_pack[i]);
	for (int j = 10; j < 15; j++)
		player2.card_hand.push_back(shuffled_card_pack[j]);
	for (int k = 15; k < 20; k++)
		player3.card_hand.push_back(shuffled_card_pack[k]);
	for (int m = 20; m < 25; m++)
		player4.card_hand.push_back(shuffled_card_pack[m]);

	std::cout << "\nBelow is the dealers card hand:\n\n";
	log << "\nBelow is the dealers card hand:\n\n";
	dealer.print_hand();//to see dealers card hand

	//log the dealers card hand
	for (int i = 0; i < 5; i++)
	{
		log << "\t\t" << dealer.card_hand[i].get_suit() << " " << dealer.card_hand[i].get_value() << endl;;
	}
	
	std::cout << "\n\n";
	log << "\n\n";


	//******************************compare pattern

	//compare dealers score and store the score in a vector
	int dealer_returned_value;
	vector<int> returned_value_array;
	dealer_returned_value = dealer.compare_pattern(dealer.card_hand);
	returned_value_array.push_back(dealer_returned_value);
	dealer.set_score(dealer_returned_value);
	//cout << dealer.get_score() << endl;

	//compare player2 score and store the score in a vector
	int player2_returned_value;
	player2_returned_value = player2.compare_pattern(player2.card_hand);
	returned_value_array.push_back(player2_returned_value);
	player2.set_score(player2_returned_value);
	//cout << player2.get_score() << endl;

	//compare player3 score and store the score in a vector
	int player3_returned_value;
	player3_returned_value = player3.compare_pattern(player3.card_hand);
	returned_value_array.push_back(player3_returned_value);
	player3.set_score(player3_returned_value);
	//cout << player3.get_score() << endl;

	//compare player4 score and store the score in a vector
	int player4_returned_value;
	player4_returned_value = player4.compare_pattern(player4.card_hand);
	returned_value_array.push_back(player4_returned_value);
	player4.set_score(player4_returned_value);
	//cout << player4.get_score() << endl;


	//check the index of maximum score in the returned_value_array
	int largest_element = returned_value_array[0]; //let, first element is the biggest one
	int smallest_element = returned_value_array[0];
	int largest_element_index = 0, smallest_element_index = 0;

	//start iterating from the second element
	for (int i = 1; i < returned_value_array.size(); i++)
	{
		if (returned_value_array[i] > largest_element)
		{
			largest_element = returned_value_array[i];
			largest_element_index = i;
		}
		if (returned_value_array[i] < smallest_element)
		{
			smallest_element = returned_value_array[i];
			smallest_element_index = i;
		}
	}

	switch (largest_element_index)
	{
	case 0: std::cout << "The winner of this round is " << dealer.get_name();
		log << "The winner of this round is " << dealer.get_name();
		player2.set_points(-1);
		player3.set_points(-1);
		player4.set_points(-1);
		break;
	case 1: std::cout << "The winner of this round is " << player2.get_name();
		log << "The winner of this round is " << player2.get_name();
		player2.set_points(10);
		player3.set_points(-1);
		player4.set_points(-1);
		break;
	case 2: std::cout << "The winner of this round is " << player3.get_name();
		log << "The winner of this round is " << player3.get_name();
		player2.set_points(-1);
		player3.set_points(10);
		player4.set_points(-1);
		break;
	case 3: std::cout << "The winner of this round is " << player4.get_name();
		log << "The winner of this round is " << player4.get_name();
		player2.set_points(-1);
		player3.set_points(-1);
		player4.set_points(10);
		break;
	}

	switch (smallest_element_index)
	{
		case 1: std::cout << "\nThe withdrawer of this round is " << player2.get_name();
			log << "\nThe withdrawer of this round is " << player2.get_name();
			break;
		case 2: std::cout << "\nThe withdrawer of this round is " << player3.get_name();
			log << "\nThe withdrawer of this round is " << player3.get_name();
			break;
		case 3: std::cout << "\nThe withdrawer of this round is " << player4.get_name();
			log << "\nThe withdrawer of this round is " << player4.get_name();
			break;
	}

	//print the points upto now
	std::cout << "\n\nThis round points of the players:\n";
	std::cout << "\n\t\t" << dealer.get_name() << "\t=  " << dealer.get_points() << endl;
	std::cout << "\t\t" << player2.get_name() << "\t=  " << player2.get_points() << endl;
	std::cout << "\t\t" << player3.get_name() << "\t=  " << player3.get_points() << endl;
	std::cout << "\t\t" << player4.get_name() << "\t=  " << player4.get_points() << endl;

	//log last points
	log << "\n\nThis round points of the players:\n";
	log << "\n\t\t" << dealer.get_name() << "\t=  " << dealer.get_points() << endl;
	log << "\t\t" << player2.get_name() << "\t=  " << player2.get_points() << endl;
	log << "\t\t" << player3.get_name() << "\t=  " << player3.get_points() << endl;
	log << "\t\t" << player4.get_name() << "\t=  " << player4.get_points() << endl;

	
	return 0;
}
