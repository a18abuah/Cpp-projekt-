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

	cout << "Hej och v�lkommen till tr�ningsspelet, h�r kommer du kunna l�gga in pengar mellan 100 till 5000 och satsa 100,300 eller 500. N�r du har satsat kommer du och datorn kasta t�rninger, n�r t�rningarna �r kastade s� kommer din h�gsta g� emot datorns h�gsta f�r att utse en vinnare. " << endl;

	cout << "l�gg in pengar: ";

	cin >> inpengar;                                    // l�gger in pengar

	while (inpengar < 100 || inpengar > 5000) {       // Regel f�r att man inte f�r l�gga in mer �n 5000 och inte mindre �n 100, annars skriver du in tills det �r r�tt.

		cout << "Du har lagt in fel summa pengar, var v�nlig och f�r�sk igen." << endl;

		cin >> inpengar;

	}



	cout << "Du har: " << inpengar << endl;

	int back1;                                              
	back1 = 0;
	bool back = true;

	while (back == true)                      // g�r en loop runt hela spelet om back �r true och det kommer den att vara s� l�nge man vill spela vidare
	{ 
		int bet;

		cout << "Betta mellan 100, 300 eller 500: ";

		cin >> bet;                                      // L�gg in bet



		while (inpengar < bet) {                  // g�r en regel f�r att inte kunna betta mer �n vad som finns p� kontot, annars skriver du in tills det �r r�tt.

			cout << "Du har inte tillr�ckligt med pengar f�r att betta den summan." << endl;

			cout << "betta r�tt summa";

			cin >> bet;

		}

		while ((bet != 100) && (bet != 300) && (bet != 500)) // g�r en regel f�r att inte kunna betta n�got annat �n 100,300 eller 500 , annars skriver du in tills det �r r�tt.


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
		while (ScoreComputer != 2 && ScorePlayer != 2) {           // g�r en while loop runt sj�lva t�rningskastet tills spelaren eller datorn f�r tv� po�ng

			int slumptal = rand() % 6 + 1;

			int slumptal2 = rand() % 6 + 1;

			int slumptal3 = rand() % 6 + 1;

			int slumptal4 = rand() % 6 + 1;


			cout << "Nu kastar spelaren t�rnigen" << "\n" << endl;           // h�r f�r vi reda p� hur mycket spelarens tv� t�rningar blev           

			cout << "T�rning1: " << slumptal << endl;

			cout << "T�rning2: " << slumptal2 << endl;


			if (slumptal >= slumptal2) {                               // P� denna IF sats f�r vi reda p� vilken t�rnigns som �r st�rst
				                                                            // sedan ger vi den st�rsta t�rningen en ny variabel
				cout << "Din h�gsta t�rning: " << slumptal << endl;
				highestdiceplayer = slumptal;
			}
			else {
				cout << "Din h�gsta t�rning: " << slumptal2 << endl;
				highestdiceplayer = slumptal2;

			}

			cout << "Nu kastar datorn t�rningen" << "\n" << endl;

			cout << "T�rning1: " << slumptal3 << endl;
			cout << "T�rning2: " << slumptal4 << endl;

			if (slumptal3 >= slumptal4) {                                // P� denna IF sats f�r vi reda p� vilken t�rnigns som �r st�rst
																			  // sedan ger vi den st�rsta t�rningen en ny variabel
				cout << "Datorns h�gsta t�rning: " << slumptal3 << endl;
				highestdicecomputer = slumptal3;
			}

			else {
				cout << "Datorns h�gsta t�rning: " << slumptal4 << endl;
				highestdicecomputer = slumptal4;

				
			}


			if (highestdiceplayer > highestdicecomputer) {                // P� denna IF sats ser vi vem som vann rundan av de h�gsta t�rningarna. 
				                                                            //Sedan ger vi de en po�ng beronde p� vem som vann rundan
				cout << "grattis du vann denna runda" << endl;
				ScorePlayer++;
			}

			else if (highestdicecomputer > highestdiceplayer) {
				cout << "tyv�rr f�rlorade du denna runda" << endl;
				ScoreComputer++;
			}

			else if (highestdicecomputer == highestdiceplayer) {
				cout << "tyv�rr f�rlorade du denna runda" << endl;
				ScoreComputer++;
			}

		}

		if (ScorePlayer == 2) {                                   // P� den h�r if satsen s� ger vi vinsten till spelaren ifall den vann, om inte s� tar vi ut den summan den f�rlorade
			                                                           // Sedan s� r�knar vi ut totalvinsten f�r spelets omg�ng.
			cout << "grattis du har vunnit: " << bet << endl;
			inpengar = inpengar + bet;
			totalvinst = totalvinst + bet;
		}
		else {

			inpengar = inpengar - bet;
			cout << "tyv�rr du f�rlorade: " << bet << endl;
			totalvinst = totalvinst - bet;

		}

		cout << "Din totalvinstsummar �r" << totalvinst << endl;

		int spelaigen;
		int merpengar;
		merpengar = 0;

		cout << "du har: " << inpengar << " p� kontot" << endl;                                                 

		cout << "vill du spela igen? (1 f�r ja eller 2 f�r nej)";       // h�r f�r du ett f�rfr�gan om du vill spela igen, om man trycker p� ja kommer man in p� If satsen


		cin >> spelaigen;
		if (spelaigen == 1) {

			if (inpengar >= 100)          // P� denna if sats s� fr�gar programmet den som har 100 eller p� p� kontot om den vill l�gga till pengar, om den har mindre s� �r det ett m�ste               
			{
				cout << "vill du l�gga till mer pengar";
				cin >> merpengar;
				while (merpengar < 0 || merpengar > 5000) {              // om spelaren skulle redan ha mer �n vad som beh�vs s� kan den skriva 0 s� kommer den vidare



					cout << "Du har gjort fel" << endl;

					cin >> merpengar;

				}

			}
			else if (inpengar < 100)
			{
				cout << "du m�ste l�gga till mer pengar ifall du vill betta igen" << endl;

				while (merpengar < 100 || merpengar > 5000) {

					cin >> merpengar;
				}
			}

			inpengar += merpengar;
			cout << "tryck p� n�gon siffra f�r att forts�tta:  ";
			cin >> back1;
			if (back1 == 1)        // OM du skriver 1 eller n�gon  annan siffra s� kommer du att skickas upp till while looopen d�r du f�r b�rja om igen om du vill spela vidare
			{
				back = true;

			}
			else
			{
				back = true;
			}
		}


		else {
			cout << "tack f�r att du spelade" << endl;        // Den �r �r else om du inte vill spela vidare. OM du inte tryckte p� 1 l�ngre upp p� if satsen s� avslutas spelet.
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
