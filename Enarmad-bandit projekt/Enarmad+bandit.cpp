#include "pch.h"
#include <iostream>
#include <ctime>
using namespace std;

int konto() {
	int pengar;
	cout << "lägg in 100,300 eller 500: ";                                                                                  /// Lägger in pengar
	cin >> pengar;

	while ((pengar != 100) && (pengar != 300) && (pengar != 500)) {                                        /// man får bara lägga in 100,300 eller 500

		cout << "fel satsning satsa igen: ";
		cin >> pengar;
	}

	return pengar;

}
int sats(int inpeng) {                                                      /// satsa pengar
	int bet;

	cout << "betta pengarna";
	cin >> bet;

	while (bet > inpeng) {                                                     /// Får inte satsa mer än vad som finns på konto
		cout << " Du har inte tillräckligt med pengar på kontot, betta igen: ";
		cin >> bet;
	}
	return bet;
}




int vinst(char spelet[3][3]) {                                                            /// beräknar vunna rader
	int spelrader = 0;

	if (spelet[0][0] == spelet[0][1] && spelet[0][1] == spelet[0][2]) {                  /// beräknar alla lodrätta rader              
		spelrader++;
	}
	if (spelet[1][0] == spelet[1][1] && spelet[1][1] == spelet[1][2]) {
		spelrader++;
	}
	if (spelet[2][0] == spelet[2][1] && spelet[2][1] == spelet[2][2]) {
		spelrader++;
	}


	if (spelet[0][0] == spelet[1][0] && spelet[1][0] == spelet[2][0]) {                   /// beräknar alla vågrätta rader
		spelrader++;
	}
	if (spelet[0][1] == spelet[1][1] && spelet[1][1] == spelet[2][1]) {
		spelrader++;
	}
	if (spelet[0][2] == spelet[1][2] && spelet[1][2] == spelet[2][2]) {
		spelrader++;
	}

	if (spelet[0][0] == spelet[1][1] && spelet[1][1] == spelet[2][2]) {                  /// beräknar båda diagonalerna

		spelrader++;
	}

	if (spelet[0][2] == spelet[1][1] && spelet[1][1] == spelet[2][0]) {

		spelrader++;
	}

	return spelrader;
}

int spelvinst(int rader, int bet) {            /// beräknar summan man har vunnit beroende                                 
	int vinsten = 0;
	if (rader == 1) {
		vinsten = bet * 2;

	}
	else if (rader == 2) {
		vinsten = bet * 3;

	}
	else if (rader == 3) {
		vinsten = bet * 4;
	}
	else if (rader == 4) {
		vinsten = bet * 5;
	}
	else if (rader == 5) {
		vinsten = bet * 7;
	}
	else if (rader == 6) {
		vinsten = bet * 8;
	}
	else if (rader == 8) {
		vinsten = bet * 10;
	}
	return vinsten;
}







int main()
{
	setlocale(LC_ALL, "swedish");
	srand(time(0));
	int inpengar;
	int inbet;
	int summa;
	int y = 0;
	int x = 0;
	int antalrader = 0;
	int vinstpengarna = 0;
	int slutsumman = 0;


	inpengar = konto();                                                /// Kör funktionen pengar och sedan överför all data till inpengar som är spelar kontot(return)

	cout << " du har lagt in:  " << inpengar << "på kontot" << endl;


	int back1;
	back1 = 0;
	bool back = true;

	while (back == true)                                                                          /// kör en loop på spelet efter första omgången
	{

		inbet = sats(inpengar);                                                    /// Kör satsningens funktionen, överför data till inbet som är variabel för sasningen i huvudprogrammet(return), Sen skickas det data ifrån spelar kontot upp till funktionen satsning(parameter)

		cout << " du har bettat:  " << inbet << endl;
		inpengar = inpengar - inbet;                                              /// tar bort satsningen ifrån pengarna på kontot

		char spel[3][3];                                                                 /// skapar spelet

		for (int y = 0; y < 3; y++) {                                              /// kört en loop som ger bokstäverna random siffror

			for (int x = 0; x < 3; x++) {

				switch (rand() % 3 + 1) {                                              /// därefter med hjälp av swistch omvandlar de till symboler
				case 1:
					spel[y][x] = 'X';
					break;
				case 2:
					spel[y][x] = 'A';
					break;
				case 3:
					spel[y][x] = 'O';
					break;


				}

			}

		}





		cout << "-----" << endl;                                                                /// skriver ut spelet med hjälp av en cout
		cout << spel[0][0] << "|" << spel[0][1] << "|" << spel[0][2] << endl;
		cout << "-----" << endl;
		cout << spel[1][0] << "|" << spel[1][1] << "|" << spel[1][2] << endl;
		cout << "-----" << endl;
		cout << spel[2][0] << "|" << spel[2][1] << "|" << spel[2][2] << endl;
		cout << "-----" << endl;


		antalrader = vinst(spel);                                                                   /// Kör funktionen som räknar hur många rader som spelaen vann, överför datan till en variabel i huvudprogrammet, skickar upp spelet till funktionen(parameter)

		cout << " du har fått:" << antalrader << "rader!" << endl;


		slutsumman = spelvinst(antalrader, inbet);                                                 /// kör funktionen som räknar ut spelvinsten, överför datan till variabel i huvudprogrammet, skickar data till funktionen om satsningen och de antal raderna som spelaren vann.

		cout << " Du har vunnit " << slutsumman << endl;

		inpengar = slutsumman + inpengar;                                                       /// räknar ut hur mycket spelaren har kvar på kontot efter omgången.






		int spelaigen;
		int merpengar;
		merpengar = 0;

		cout << "du har: " << inpengar << " på kontot" << endl;

		cout << "vill du spela igen? (1 för ja eller 2 för nej)";                                                             
		cin >> spelaigen;
		if (spelaigen == 1) {                                                                           /// bestämmer om spelaren vill spela vidare eller inte

			if (inpengar > 0)                                                                          /// om spelaren vill spela vidare så måste den ha mer än 0 på kontot, sen kan den välja om den vill lägga till mer
			{
				cout << "vill du lägga till mer pengar(skriv 0 om du inte vill): ";
				cin >> merpengar;
				while (merpengar < 0 || merpengar > 100000) {

					cout << "Du har gjort fel: " << endl;

					cin >> merpengar;



				}

			}



			else if (inpengar == 0)                                                                        /// om den har 0 så måste den lägga in något.
			{
				cout << "du måste lägga till mer pengar ifall du vill betta igen" << endl;
				while (merpengar < 1 || merpengar > 100000) {

					cin >> merpengar;
				}



			}

			inpengar += merpengar;
			cout << "skriv 1 för att betta:  ";
			cin >> back1;
			if (back1 == 1)                                                        
			{
				back = true;

			}
			else
			{
				back = false;
			}


		}

		else {
			cout << "tack för att du spelade" << endl;                                             
			return 0;
		}

	}
}
