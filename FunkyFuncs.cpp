#include "FunkyFuncs.h"
#define NUM 0xffffffff
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <windows.h>

using namespace std;

void Game1() {
	string name;

	cout << "Hello! Welcome to the Guessing Game! Not very interesting I know, but this is a surprise tool that will help us later.\n";
	cout << "Anyway, what's your name?\n";
	cin >> name;
	cout << "\nWrong!\n";
	cout << "\nJust kidding! Your name is fine.....maybe....\n";
	cout << "\nAnywho, guess a number between 1 and 10.\n";
	
	char guess;
	cin >> guess;
	if (guess == '5') {
		cout << "Wow, you guessed that? Huh. Guess we're in sync after all, don't let it go to your head though or else I'll destroy you.\n";
		cout << "Onto Game 2!";
	}
	else {
		cout << "Wow. Such wrong. Such bad. Moving on from that failure, Game 2!\n\n\n";
	}
	system("pause");
}

void Game2() {
	int usr_in_int; //The number the user inputs
	int our_rand; //The random number the system provides
	srand(time(0));
	string profs[10] = { "Bill", "Juan", "Gustov", "Frank", "Ron",
	"Nicole", "Ian", "Eric", "Hank", "Homer" }; //The string that connects to the number the user inputs
	string rooms[15] = { "r107", "108", "THR", "252", "215",
	"Cafe", "888", "667", "Studio", "LARP", "Disco", "Hidden",
	"ASSC", "Space", "Safe-Space" }; //The string that connects to the number the system provides

	cout << "\n\n\nHello! Welcome to yet another Guessing Game! But this one tortures you more!\n";
	cout << "You know the rules, and so do I, so guess a number between 1 and 10, guess wrong and I'll haunt you.\n";
	our_rand = rand() % 10 + 1; //The random number generator the system uses to decide on a number
	cin >> usr_in_int; //The user types in a random number
	int trys = 0; //The variable that lets the user have different tries
	while (our_rand == usr_in_int || trys < 3) { //The loop that specifies the amount of tries the user has or if the user won
		if (our_rand == usr_in_int) { //The specifications that allow the user to win
			cout << "You won? Well good for you! What? you want a cookie? Onto Game 3!";
			
		}
		else {
			cout << "Nope, do it again.\n";
			cin >> usr_in_int; //This allows the user to try again
			trys++; //This determines how many tries the user has attempted

			//If the user tries three times and fails, they are met with a beep
			if (trys == 3) {
				cout << "Welp, looks like you lost, failure...\n";
				cout << "Onto game 3!\n";
				Beep(500, 1000);			
				system("pause");
			}
		}

	}
}

void Game3() {
	srand(time(0));

	bool play = true; //This is the logic that lets the game run
	string tmp; //This puts each person in the randomly assigned rooms
	string uin; //This is the user input that prompts the player to play again
	int uin_int; //Prompts the player to input a number for a random room
	int r1, r2; //Integers for each row, one for peeps, one for rooms
	//The amount of people on a string, I only put 5 peeps to randomize because 10 makes the game too easy
	string peeps[15] = { "Bill", "Jill", "Phill", "Mike", "Anna" ,"Nope", "Nope", "Nope", "Nope", "Nope", "Nope", "Nope", "Nope", "Nope", "Nope" };
	string rooms[15] = { "102", "103", "104", "202", "203", "204", "100", "120", "200", "220", "180", "750", "305", "170", "909" }; //String for the rooms
	char Skill[6] = { 'F', 'D', 'C', 'B', 'A', 'S' }; //The skill meter
	int level = 3; //The starting social skill level

	cout << "\n\n\nWell well well, look who it is, up for round 3 of, you guessed it, ANOTHER GUESSING GAME. But it's like, so sadistic omg.\n";
	cout << "Anyway, for context you have barely any social skills (obviously), and you need to get more friends.\n";
	cout << "You're in a hallway full of doors (don't ask where you are, go with it and I'll set you free), \n";
	cout << "pick a room that has someone in it, and your social skill rises! What a concept, talking to people gives you social skills? Who knew! Anyway.\n";
	while (play) { //Loop that plays the game

		//These functions randomize each row so the game is "challenging"
		for (int i = 0; i < 5; i++) {
			r1 = rand() % 15;
			r2 = rand() % 15;
			while (r1 == r2) {
				r2 = rand() % 15;
			}
			tmp = rooms[r1];
			rooms[r1] = rooms[r2];
			rooms[r2] = tmp;
		}

		for (int i = 0; i < 5; i++) {
			r1 = rand() % 15;
			r2 = rand() % 15;
			while (r1 == r2) {
				r2 = rand() % 15;
			}
			tmp = peeps[r1];
			peeps[r1] = peeps[r2];
			peeps[r2] = tmp;
		}

		//Prompts you to play again after each turn
		cout << "Guess a number between 0 and 14 to get more friends. If only it were that easy right?\n";
		cin >> uin_int;
		//This tells you the result of your guess, if there is a person in the room you guessed, your level goes up by one
		if (peeps[uin_int] != "Nope") {
			cout << "You knock on room " << rooms[uin_int] << ".\n";
			cout << "Is there anyone here? " << peeps[uin_int] << "'s here! You made a friend finally!\n";
			cout << "Your skill increases, now only if it were real.\n";
			++level;
		}
		//If there is no one in the room you guessed, your level goes down by one
		else {
			cout << "You knock on room " << rooms[uin_int] << ".\n";
			cout << "Is there anyone here? " << peeps[uin_int] << ". No new friends for you. Boo hoo.\n";
			cout << "Your sociability decreases and you're somehow more socially awkward than before.\n";
			--level;
		}

		//If the starting level goes up to 5, then you win with an S and are met with a tune and text saying "Good job on your fake friends, your mom would be so proud!"
		if (level == 5) {

			cout << "You have an " << Skill[5] << "! Wow, surprising. You actually made some friends, now do it for real! No? Well at least it was fun.\n";
			cout << "Well, fun for me at least, your opinion is irrelevant to me, but you won, now go away. You're free to go.";
			Beep(400, 500);
			Beep(500, 500);
			Beep(600, 1000);
			play = false;
		}
		//If the starting level goes down to 1, you lose with an F and are met with a tune and text saying how great you are at losing. 
		else if (level == 1) {

			cout << "You have an " << Skill[1] << ". Wow, you can't even make fake friends, dude, you need to work on that.\n";
			cout << "But, you've finished the game (even though you failed) and I said I'd let you go. Now go away, I have Spongebob to watch!\n";
			cout << "*Sounds of Spongeboy me Bob playing in the background, but you're not invited since you failed*";
			Beep(400, 500);
			Beep(300, 500);
			Beep(200, 1000);
			play = false;
		}

		//If the grade number is between 1 and 5, then the user is prompted and can continue playing and is met with a tone signifying a bell
		if (level < 5 && level > 1) {
			cout << "*rings a bell so you'll hurry up with your interaction so I can get back to my show*\n";
			Beep(400, 1500);
			cout << "Will you go to the next room or..? Y or N?\n";
			cin >> uin;

			//If the user responds 'y', then the game will continue
			if (uin == "y") {

				play = true;
			}
			//If the user responds with anything else, then the game will end and the window will close
			else {

				play = false;
			}
		}
	}
}