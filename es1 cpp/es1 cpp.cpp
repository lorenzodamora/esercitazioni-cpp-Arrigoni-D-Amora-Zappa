#pragma region include

#include <iostream>
#include <fstream>
#include <string> //ha getline()
//#include <stdio.h>//ha printf()
//#include <stdlib.h>
//#include <cstdlib>
#include <stdbool.h>
#include <conio.h> // _getch();
#include <windows.h> //console color 
//#include <limits>

using namespace std;

#pragma endregion

#pragma region Path

#include <direct.h>
#define GetCurrentDir _getcwd

std::string get_current_dir()
{
	char buff[FILENAME_MAX]; //create string buffer to hold path
	GetCurrentDir(buff, FILENAME_MAX);
	string current_working_dir(buff);
	return current_working_dir;
}
#pragma endregion

#pragma region prototipi

#pragma endregion

int main()
{
	//non va, buh
	//SetConsoleOutputCP(GetACP()); // GetACP() returns the system codepage.

	string path = get_current_dir();
	cout << path << endl;
	path = path.erase(path.length() - 7) + "pasticceria"; // es1 cpp 7 char
	cout << path << endl;
	_getch(); // Console readkey true
	HANDLE console; //#include <windows.h>
	console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, 240); //nero su bianco

	bool end = false;
	do
	{
		system("CLS"); // pulisce la console
#pragma region menu
		cout << "\t\t\tQuesto " << "e'" << " il menu della pasticceria\n\n\n";
		cout << "1. cannoli siciliani\n";
		cout << "2. cassata siciliana\n";
		cout << "3. maritozzo con la panna\n";
		cout << "4. pasticciotto\n";
		cout << "5. pastiera alla napoletana\n";
		cout << "6. sebadas\n";
		cout << "7. strudel\n";
		cout << "8. tenerina\n";
		cout << "9. tiramisu\n";
		cout << "10. torta sbrisolona\n\n\n";

		cout << "Scegli il dolce: ";
#pragma endregion

		int ric = 0;
		bool input;
#pragma region input
		do
		{
			try
			{
				input = true;
				string sric;
				getline(cin, sric);
				//cin.ignore(INT_MAX, '\n'); // quando c'era cin >> sric   senza cin.ignore, se scrivesse a a a attiverebbe 3 volte il catch
				//cin.ignore(INT_MAX, ' '); //test
				ric = stoi(sric); // se scrivo "1 a" o "1a"  mi prende 1
				if (ric < 1 || ric > 10 || to_string(ric) != sric)
					throw "";
				//throw sric;
			} //catch (string sric) da errore
			catch (...)
			{ // 17 | 12
				//console = GetStdHandle(STD_OUTPUT_HANDLE);
				//COORD pos = { 17 , 15 };
				SetConsoleCursorPosition(console, { 17, 16 });
				cout << "scrivi un numero da 1 a 10 per scegliere un dolce";
				CONSOLE_SCREEN_BUFFER_INFO csbi;
				GetConsoleScreenBufferInfo(console, &csbi);
				SetConsoleCursorPosition(console, { 17, 15 });
				//COORD coo = csbi.dwSize;
				//cout << string(coo.X, ' ');
				cout << string(csbi.dwSize.X, ' ');
				SetConsoleCursorPosition(console, { 17, 15 });
				input = false;
			}
		} while (!input);
#pragma endregion

		//consumi

		int consumi[100] = { 0 };
		switch (ric)
		{
		case 1:
			consumi[1] = 10; //Aceto di vino bianco ml 500
			consumi[5] = 100; //Arancia candita g 100
			consumi[9] = 5; //Cacao amaro in polvere g 75
			consumi[13] = 60; //Ciliegie candite n 100
			consumi[20] = 260; //Farina g 1000
			consumi[23] = 80; //Gocce di cioccolato fondente g 250
			consumi[32] = 60; //Marsala ml 100
			consumi[40] = 1; //Olio di semi l 1
			consumi[49] = 1000; //Ricotta di pecora g 2000
			consumi[51] = 5; //Sale g 100
			consumi[55] = 30; //Strutto g 200
			consumi[56] = 2; //Uova n 12
			consumi[59] = 150; //Zucchero g 1000
			consumi[61] = 240; //Zucchero a velo g 1000
			break;

		case 2:
			consumi[3] = 150; //Acqua ml 1000
			consumi[5] = 50; //Arancia candita g 100
			consumi[16] = 300;// Farina 00 g 1000
			consumi[22] = 100;//Frutta candita g 150
			consumi[23] = 100; //Gocce di cioccolato fondente g 250
			consumi[31]= 15;//Maraschino g 100
			consumi[33] = 200;//Marzapane g 500
			consumi[45] = 20;//Pasta di pistacchi g 100
			consumi[49] = 1200; //Ricotta di pecora g 2000
			consumi[51] = 1; //Sale g 100
			consumi[54] = 1;//Scorza di limone n 10
			consumi[56] = 11; //Uova n 12
			consumi[59] = 350; //Zucchero g 1000
			consumi[60] = 150; //Zucchero a velo vanigliato g 1000
			consumi[61] = 630; //Zucchero a velo g 1000
			break;

		case 3:
			consumi[3] = 100; //Acqua ml 1000
			consumi[6] = 1; //Baccello di vaniglia n 5
			consumi[15] = 500; //Farina 0 g 1000
			consumi[27] = 175; //Latte intero ml 1000
			consumi[28] = 13; //Lievito di birra g 20
			consumi[36] = 10; //Miele g 100
			consumi[41] = 75; //Olio d'oliva ml 500
			consumi[43] = 500; //Panna liquida g 600
			consumi[47] = 50; //Pinoli g 100
			consumi[51] = 10; //Sale g 100
			consumi[53] = 1; //Scorza d'arancia n 10
			consumi[56] = 3; //Uova n 12
			consumi[57] = 90; //Uvetta g 150
			consumi[59] = 55; //Zucchero g 1000
			consumi[61] = 750; //Zucchero a velo g 1000
			break;
		case 4:
			consumi[4] = 15; //Amarene sciroppate n 40
			consumi[6] = 2; //Baccello di vaniglia n 5
			consumi[7] = 250; //Burro g 400
			consumi[16] = 700; //Farina 00 g 1000
			consumi[26] = 500; //Latte ml 1000
			consumi[43] = 45; //Panna liquida g 600
			consumi[56] = 11; //Uova n 12
			consumi[61] = 200; //Zucchero a velo g 1000
			break;
		case 5:
			consumi[] = ; //
			break;
		default:
			//
			break;
		}

		//magazzino

		system("CLS"); // pulisce la console
		bool lista[100] = { false };
		string lines[100];

		ifstream ifmag(path + "\\magazzino.txt"); // ifstream magazzino; apertura file in lettura
		for (int i = 0; getline(ifmag, lines[i]); i++)
		{
			lines[i] += "\n";
			cout << lines[i];
		}
		ifmag.close();

		int qui; //quantità ingrediente

		//ingrediente 1 g|200, 2 è il char 16
		qui = stoi(lines[1].substr(16));
		if (qui < 1000)
		{
			lista[1] = true;
			qui += 2000;
		}
		lines[1] = "ingrediente 1 g " + to_string(qui - consumi[1]) + "\n";

		//ingrediente 2 g|200, 2 è il char 16
		qui = stoi(lines[2].substr(16));
		if (qui < 500)
		{
			lista[2] = true;
			qui += 1000;
		}
		lines[2] = "ingrediente 2 g " + to_string(qui - consumi[2]) + "\n";
		//ingredienti 3 4 5 ..

		ofstream ofmag(path + "\\magazzino.txt"); // ofstream magazzino; apertura file in scrittura
		for (auto lin : lines)
			if (lin != "")
				ofmag << lin;
		ofmag.close();

		_getch();

		for (int i = 1; i < 100; i++)
			lista[0] |= lista[i];
		
		//spesa

		system("CLS"); // pulisce la console
		fill_n(lines, 100, ""); //svuota l'array
		if (lista[0] == true)
		{
			ifstream ifspe(path + "\\spesa.txt"); // ifstream spesa; apertura file in lettura
			getline(ifspe, lines[0]);
			cout << lines[0] << endl;
			for (int i = 1; getline(ifspe, lines[i]); i++)
				if (lista[i] == true)
					cout << lines[i] << endl;
			ifspe.close();

			cout << "\n\nIngredienti aggiunti al magazzino!";
		}
		else
			cout << "Non mancano ingredienti in magazzino!";

		_getch();

		//ricetta

		system("CLS"); // pulisce la console
		fill_n(lines, 100, ""); //svuota l'array

		ifstream ifric(path + "\\libro delle ricette\\ricetta" + to_string(ric) + ".txt"); // ifstream ricetta; apertura file in lettura
		for (int i = 0; getline(ifric, lines[i]); i++)
			cout << lines[i] << endl;
		ifric.close();

		_getch();

		cout << "\n\nGli ingredienti usati sono stati rimossi dal magazzino!";

		_getch();

	} while (!end);
}