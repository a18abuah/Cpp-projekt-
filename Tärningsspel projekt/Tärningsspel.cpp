// Console// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

#include <iostream>

#include <ctime>

#include "pch.h"

#include <iostream>

using namespace std;

int ScorePlayer;

int ScoreComputer;

int main() {
	setlocale(LC_ALL, "swedish");

	int totalvinst = 0;

	int inpengar;

	cout << "Hej och välkommen till träningsspelet, här kommer du kunna lägga in pengar mellan 100 till 5000 och satsa 100,300 eller 500. När du har satsat kommer du och datorn kasta tärninger, när tärningarna är kastade så kommer din högsta gå emot datorns högsta för att utse en vinnare. " << endl;

	cout << "lägg in pengar: ";

	cin >> inpengar;                                    // lägger in pengar

	while (inpengar < 100 || inpengar > 5000) {       // Regel för att man inte får lägga in mer än 5000 och inte mindre än 100, annars skriver du in tills det är rätt.

		cout << "Du har lagt in fel summa pengar, var vänlig och förösk igen." << endl;

		cin >> inpengar;

	}



	cout << "Du har: " << inpengar << endl;

	int back1;                                              
	back1 = 0;
	bool back = true;

	while (back == true)                      // gör en loop runt hela spelet om back är true och det kommer den att vara så länge man vill spela vidare
	{ 
		int bet;

		cout << "Betta mellan 100, 300 eller 500: ";

		cin >> bet;                                      // Lägg in bet



		while (inpengar < bet) {                  // gör en regel för att inte kunna betta mer än vad som finns på kontot, annars skriver du in tills det är rätt.

			cout << "Du har inte tillräckligt med pengar för att betta den summan." << endl;

			cout << "betta rätt summa";

			cin >> bet;

		}

		while ((bet != 100) && (bet != 300) && (bet != 500)) // gör en regel för att inte kunna betta något annat än 100,300 eller 500 , annars skriver du in tills det är rätt.


		{
			cout <<
			" fel bet" << endl;

			cout << " Betta igen: ";

			cin >> bet;
		}


		cout << "Du har bettat: " << bet << endl;               // visar hur mycket du har bettat

		srand(time(0));

		int highestdiceplayer;
		int highestdicecomputer;

		ScoreComputer = 0;
		ScorePlayer = 0;
		while (ScoreComputer != 2 && ScorePlayer != 2) {           // gör en while loop runt själva tärningskastet tills spelaren eller datorn får två poäng

			int slumptal = rand() % 6 + 1;

			int slumptal2 = rand() % 6 + 1;

			int slumptal3 = rand() % 6 + 1;

			int slumptal4 = rand() % 6 + 1;


			cout << "Nu kastar spelaren tärnigen" << "\n" << endl;           // här får vi reda på hur mycket spelarens två tärningar blev           

			cout << "Tärning1: " << slumptal << endl;

			cout << "Tärning2: " << slumptal2 << endl;


			if (slumptal >= slumptal2) {                               // På denna IF sats får vi reda på vilken tärnigns som är störst
				                                                            // sedan ger vi den största tärningen en ny variabel
				cout << "Din högsta tärning: " << slumptal << endl;
				highestdiceplayer = slumptal;
			}
			else {
				cout << "Din högsta tärning: " << slumptal2 << endl;
				highestdiceplayer = slumptal2;

			}

			cout << "Nu kastar datorn tärningen" << "\n" << endl;

			cout << "Tärning1: " << slumptal3 << endl;
			cout << "Tärning2: " << slumptal4 << endl;

			if (slumptal3 >= slumptal4) {                                // På denna IF sats får vi reda på vilken tärnigns som är störst
																			  // sedan ger vi den största tärningen en ny variabel
				cout << "Datorns högsta tärning: " << slumptal3 << endl;
				highestdicecomputer = slumptal3;
			}

			else {
				cout << "Datorns högsta tärning: " << slumptal4 << endl;
				highestdicecomputer = slumptal4;

				
			}


			if (highestdiceplayer > highestdicecomputer) {                // PÅ denna IF sats ser vi vem som vann rundan av de högsta tärningarna. 
				                                                            //Sedan ger vi de en poäng beronde på vem som vann rundan
				cout << "grattis du vann denna runda" << endl;
				ScorePlayer++;
			}

			else if (highestdicecomputer > highestdiceplayer) {
				cout << "tyvärr förlorade du denna runda" << endl;
				ScoreComputer++;
			}

			else if (highestdicecomputer == highestdiceplayer) {
				cout << "tyvärr förlorade du denna runda" << endl;
				ScoreComputer++;
			}

		}

		if (ScorePlayer == 2) {                                   // På den här if satsen så ger vi vinsten till spelaren ifall den vann, om inte så tar vi ut den summan den förlorade
			                                                           // Sedan så räknar vi ut totalvinsten för spelets omgång.
			cout << "grattis du har vunnit: " << bet << endl;
			inpengar = inpengar + bet;
			totalvinst = totalvinst + bet;
		}
		else {

			inpengar = inpengar - bet;
			cout << "tyvärr du förlorade: " << bet << endl;
			totalvinst = totalvinst - bet;

		}

		cout << "Din totalvinstsummar är" << totalvinst << endl;

		int spelaigen;
		int merpengar;
		merpengar = 0;

		cout << "du har: " << inpengar << " på kontot" << endl;                                                 

		cout << "vill du spela igen? (1 för ja eller 2 för nej)";       // här får du ett förfrågan om du vill spela igen, om man trycker på ja kommer man in på If satsen


		cin >> spelaigen;
		if (spelaigen == 1) {

			if (inpengar >= 100)          // På denna if sats så frågar programmet den som har 100 eller på på kontot om den vill lägga till pengar, om den har mindre så är det ett måste               
			{
				cout << "vill du lägga till mer pengar";
				cin >> merpengar;
				while (merpengar < 0 || merpengar > 5000) {              // om spelaren skulle redan ha mer än vad som behövs så kan den skriva 0 så kommer den vidare



					cout << "Du har gjort fel" << endl;

					cin >> merpengar;

				}

			}
			else if (inpengar < 100)
			{
				cout << "du måste lägga till mer pengar ifall du vill betta igen" << endl;

				while (merpengar < 100 || merpengar > 5000) {

					cin >> merpengar;
				}
			}

			inpengar += merpengar;
			cout << "tryck på någon siffra för att fortsätta:  ";
			cin >> back1;
			if (back1 == 1)        // OM du skriver 1 eller någon  annan siffra så kommer du att skickas upp till while looopen där du får börja om igen om du vill spela vidare
			{
				back = true;

			}
			else
			{
				back = true;
			}
		}


		else {
			cout << "tack för att du spelade" << endl;        // Den är är else om du inte vill spela vidare. OM du inte tryckte på 1 längre upp på if satsen så avslutas spelet.
			return 0;
		}
	}
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file 
