#pragma region include

#include <iostream>
#include <fstream>
#include <string> //ha getline()
//#include <stdio.h>//ha printf()
//#include <stdlib.h>
//#include <cstdlib>
#include <stdbool.h>
#include <conio.h> // _getch();
#include <Windows.h> //console color 
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
void htmlricette(string path, int* ric, int len, int tot);
void htmldispensa(string path);
#pragma endregion

int main()
{
	//non va, buh
	//SetConsoleOutputCP(GetACP()); // GetACP() returns the system codepage.

	string path = get_current_dir();
	//cout << path << endl;
	path = path.erase(path.length() - 7) + "pasticceria"; // es1 cpp 7 char
	//cout << path << endl;

#pragma region ApriIlBrowser
	// String to convert
	string test1 = path + " html\\HomePage.html";
	const char* test = test1.c_str();

	// Calculate the length of the resulting wide string
	int wideLen = MultiByteToWideChar(CP_UTF8, 0, test, -1, NULL, 0);

	// Allocate memory for the wide string
	wchar_t* wideStr = new wchar_t[wideLen];

	// Convert the string from multibyte to wide
	MultiByteToWideChar(CP_UTF8, 0, test, -1, wideStr, wideLen);

	// Use the wide string
	LPCWSTR bpath = wideStr;
	//LPCWSTR testpath1 = L"C:\\Users\\ldamo\\OneDrive\\Desktop\\esercitazioni-cpp-Arrigoni-D-Amora-Zappa\\pasticceria html\\HomePage.html";

	// Deallocate memory
	//delete[] wideStr;

	//open browser
	ShellExecute(NULL, L"open", bpath, NULL, NULL, SW_SHOWNORMAL);
#pragma endregion

	cout << "metti schermo intero e premi qualunque tasto per continuare...";
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

		int totric = 10;
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

		int ri[] = { 1, 1, 2, 2, 3 };
		//stampa le ricette in html
		htmlricette(path, ri, 5, totric);
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
			consumi[31] = 15;//Maraschino g 100
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
			consumi[3] = 45; //Acqua di fiori d'arancio ml 100
			consumi[7] = 75; //Burro g 400
			consumi[12] = 50; //Cedro candito g 70
			consumi[16] = 250; //Farina 00 g 1000
			consumi[25] = 200; //Grano cotto g 500
			consumi[27] = 140; //Latte intero ml 1000
			consumi[38] = 40; //Miele millefiori g 100
			consumi[49] = 200; //Ricotta di pecora g 2000
			consumi[51] = 1; //Sale g 100
			consumi[53] = 1; //Scorza d'arancia n 10
			consumi[54] = 1; //Scorza di limone n 10
			consumi[55] = 50; //Strutto g 200
			consumi[56] = 4; //Uova n 12
			consumi[59] = 260; //Zucchero g 1000
			consumi[61] = 30; //Zucchero a velo g 1000
			break;
		case 6:
			consumi[2] = 320; //Acqua ml 1000
			consumi[17] = 500; //Farina di grano duro g 1000
			consumi[37] = 200; //Miele di castagno g 300
			consumi[46] = 500; //Pecorino g 1000
			consumi[54] = 1; //Scorza di limone n 10
			consumi[55] = 70; //Strutto g 200
			consumi[56] = 1; //Uova n 12
			break;
		case 7:
			consumi[2] = 30; //Acqua ml 1000
			consumi[7] = 50; //Burro g 400
			consumi[11] = 3; //Cannella in polvere g 10
			consumi[16] = 130; //Farina 00 g 1000
			consumi[35] = 750; //Mele Golden g 1000
			consumi[39] = 9; //Olio di semi di girasole g 1000
			consumi[42] = 60; //Pangrattato g 100
			consumi[48] = 25; //Pinoli tostati g 100
			consumi[50] = 2; //Rum cucchiai 10
			consumi[51] = 1; //Sale g 100
			consumi[54] = 1; //Scorza di limone n 10
			consumi[56] = 1; //Uova n 12
			consumi[57] = 50; //Uvetta g 150
			consumi[59] = 60; //Zucchero g 1000
			consumi[61] = 30; //Zucchero a velo g 1000
			break;
		case 8:
			consumi[7] = 100; //Burro g 400
			consumi[14] = 200; //Cioccolato fondente g 400
			consumi[16] = 50; //Farina 00 g 1000
			consumi[56] = 4; //Uova n 12
			consumi[59] = 150; //Zucchero g 1000
			consumi[61] = 20; //Zucchero a velo g 1000
			break;
		case 9:
			consumi[9] = 60; //Cacao amaro in polvere g 75
			consumi[10] = 300; //Caffè g 500
			consumi[34] = 750; //Mascarpone g 1000
			consumi[52] = 250; //Savoiardi g 500
			consumi[56] = 5; //Uova n 12
			consumi[59] = 120; //Zucchero g 1000
			break;
		case 10:
			consumi[6] = 1; //Baccello di vaniglia n 5
			consumi[8] = 200; //Burro morbido ma ancora plastico g 400
			consumi[16] = 200; //Farina 00 g 1000
			consumi[18] = 100; //Farina di mais fioretto g 1000
			consumi[19] = 200; //Farina di mandorle g 1000
			consumi[29] = 10; //Lievito per dolci g 20
			consumi[30] = 40; //Mandorle g 100
			consumi[31] = 30; //Maraschino g 100
			consumi[51] = 2; //Sale g 100
			consumi[56] = 2; //Uova n 12
			consumi[59] = 200; //Zucchero g 1000
			break;
		default:
			//consumi[] = ; //
			cout << "dolce non implementato";
			break;
		}

		//magazzino

		system("CLS"); // pulisce la console
		bool lista[100] = { false };
		string lines[100];

		htmldispensa(path);

		ifstream ifmag(path + "\\magazzino.txt"); // ifstream magazzino; apertura file in lettura
		for (int i = 0; getline(ifmag, lines[i]); i++)
		{
			lines[i] += "\n";
			cout << lines[i];
		}
		ifmag.close();

		int qui; //quantità ingrediente

#pragma region elencoControlliECalcoliIngredienti

		//Aceto di vino bianco ml 500, il valore è in char 24
		qui = stoi(lines[1].substr(24));
		if (qui < 500)
		{
			lista[1] = true;
			qui += 500;
		}
		lines[1] = "Aceto di vino bianco ml " + to_string(qui - consumi[1]) + "\n";

		//Acqua ml 1000, il valore è in char 9
		qui = stoi(lines[2].substr(9));
		if (qui < 1000)
		{
			lista[2] = true;
			qui += 1000;
		}
		lines[2] = "Acqua ml " + to_string(qui - consumi[2]) + "\n";

		//Acqua di fiori d'arancio ml 100, il valore è in char 28
		qui = stoi(lines[3].substr(28));
		if (qui < 100)
		{
			lista[3] = true;
			qui += 100;
		}
		lines[3] = "Acqua di fiori d'arancio ml " + to_string(qui - consumi[3]) + "\n";

		//Amarene sciroppate n 40, il valore è in char 21
		qui = stoi(lines[4].substr(21));
		if (qui < 40)
		{
			lista[4] = true;
			qui += 40;
		}
		lines[4] = "Amarene sciroppate n " + to_string(qui - consumi[4]) + "\n";

		//Arancia candita g 100, il valore è in char 18
		qui = stoi(lines[5].substr(18));
		if (qui < 100)
		{
			lista[5] = true;
			qui += 100;
		}
		lines[5] = "Arancia candita g " + to_string(qui - consumi[5]) + "\n";

		//Baccello di vaniglia n 5, il valore è in char 23
		qui = stoi(lines[6].substr(23));
		if (qui < 5)
		{
			lista[6] = true;
			qui += 5;
		}
		lines[6] = "Baccello di vaniglia n " + to_string(qui - consumi[6]) + "\n";

		//Burro g 400, il valore è in char 8
		qui = stoi(lines[7].substr(8));
		if (qui < 400)
		{
			lista[7] = true;
			qui += 400;
		}
		lines[7] = "Burro g " + to_string(qui - consumi[7]) + "\n";

		//Burro morbido ma ancora plastico g 400, il valore è in char 35
		qui = stoi(lines[8].substr(35));
		if (qui < 400)
		{
			lista[8] = true;
			qui += 400;
		}
		lines[8] = "Burro morbido ma ancora plastico g " + to_string(qui - consumi[8]) + "\n";

		//Cacao amaro in polvere g 75, il valore è in char 25
		qui = stoi(lines[9].substr(25));
		if (qui < 75)
		{
			lista[9] = true;
			qui += 75;
		}
		lines[9] = "Cacao amaro in polvere g " + to_string(qui - consumi[9]) + "\n";

		//Caffè g 500, il valore è in char 8
		qui = stoi(lines[10].substr(8));
		if (qui < 500)
		{
			lista[10] = true;
			qui += 500;
		}
		lines[10] = "Caffè g " + to_string(qui - consumi[10]) + "\n";

		//Cannella in polvere g 10, il valore è in char 22
		qui = stoi(lines[11].substr(22));
		if (qui < 10)
		{
			lista[11] = true;
			qui += 10;
		}
		lines[11] = "Cannella in polvere g " + to_string(qui - consumi[11]) + "\n";

		//Cedro candito g 70, il valore è in char 16
		qui = stoi(lines[12].substr(16));
		if (qui < 70)
		{
			lista[12] = true;
			qui += 70;
		}
		lines[12] = "Cedro candito g " + to_string(qui - consumi[12]) + "\n";

		//Ciliegie candite n 100, il valore è in char 19
		qui = stoi(lines[13].substr(19));
		if (qui < 100)
		{
			lista[13] = true;
			qui += 100;
		}
		lines[13] = "Ciliegie candite n " + to_string(qui - consumi[13]) + "\n";

		//Cioccolato fondente g 400, il valore è in char 22
		qui = stoi(lines[14].substr(22));
		if (qui < 400)
		{
			lista[14] = true;
			qui += 400;
		}
		lines[14] = "Cioccolato fondente g " + to_string(qui - consumi[14]) + "\n";

		//Farina 0 g 1000, il valore è in char 11
		qui = stoi(lines[15].substr(11));
		if (qui < 1000)
		{
			lista[15] = true;
			qui += 1000;
		}
		lines[15] = "Farina 0 g " + to_string(qui - consumi[15]) + "\n";

		//Farina 00 g 1000, il valore è in char 12
		qui = stoi(lines[16].substr(12));
		if (qui < 1000)
		{
			lista[16] = true;
			qui += 1000;
		}
		lines[16] = "Farina 00 g " + to_string(qui - consumi[16]) + "\n";

		//Farina di grano duro g 1000, il valore è in char 23
		qui = stoi(lines[17].substr(23));
		if (qui < 1000)
		{
			lista[17] = true;
			qui += 1000;
		}
		lines[17] = "Farina di grano duro g " + to_string(qui - consumi[17]) + "\n";

		//Farina di mais fioretto g 1000, il valore è in char 26
		qui = stoi(lines[18].substr(26));
		if (qui < 1000)
		{
			lista[18] = true;
			qui += 1000;
		}
		lines[18] = "Farina di mais fioretto g " + to_string(qui - consumi[18]) + "\n";

		//Farina di mandorle g 1000, il valore è in char 21
		qui = stoi(lines[19].substr(21));
		if (qui < 1000)
		{
			lista[19] = true;
			qui += 1000;
		}
		lines[19] = "Farina di mandorle g " + to_string(qui - consumi[19]) + "\n";

		//Farina g 1000, il valore è in char 9
		qui = stoi(lines[20].substr(9));
		if (qui < 1000)
		{
			lista[20] = true;
			qui += 1000;
		}
		lines[20] = "Farina g " + to_string(qui - consumi[20]) + "\n";

		//Farina Manitoba g 1000, il valore è in char 18
		qui = stoi(lines[21].substr(18));
		if (qui < 1000)
		{
			lista[21] = true;
			qui += 1000;
		}
		lines[21] = "Farina Manitoba g " + to_string(qui - consumi[21]) + "\n";

		//Frutta candita g 150, il valore è in char 17
		qui = stoi(lines[22].substr(17));
		if (qui < 150)
		{
			lista[22] = true;
			qui += 150;
		}
		lines[22] = "Frutta candita g " + to_string(qui - consumi[22]) + "\n";

		//Gocce di cioccolato fondente g 250, il valore è in char 31
		qui = stoi(lines[23].substr(31));
		if (qui < 250)
		{
			lista[23] = true;
			qui += 250;
		}
		lines[23] = "Gocce di cioccolato fondente g " + to_string(qui - consumi[23]) + "\n";

		//Granella di pistacchi g 1000, il valore è in char 24
		qui = stoi(lines[24].substr(24));
		if (qui < 1000)
		{
			lista[24] = true;
			qui += 1000;
		}
		lines[24] = "Granella di pistacchi g " + to_string(qui - consumi[24]) + "\n";

		//Grano cotto g 500, il valore è in char 14
		qui = stoi(lines[25].substr(14));
		if (qui < 500)
		{
			lista[25] = true;
			qui += 500;
		}
		lines[25] = "Grano cotto g " + to_string(qui - consumi[25]) + "\n";

		//Latte ml 1000, il valore è in char 9
		qui = stoi(lines[26].substr(9));
		if (qui < 1000)
		{
			lista[26] = true;
			qui += 1000;
		}
		lines[26] = "Latte ml " + to_string(qui - consumi[26]) + "\n";

		//Latte intero ml 1000, il valore è in char 16
		qui = stoi(lines[27].substr(16));
		if (qui < 1000)
		{
			lista[27] = true;
			qui += 1000;
		}
		lines[27] = "Latte intero ml " + to_string(qui - consumi[27]) + "\n";

		//Lievito di birra g 20, il valore è in char 19
		qui = stoi(lines[28].substr(19));
		if (qui < 20)
		{
			lista[28] = true;
			qui += 20;
		}
		lines[28] = "Lievito di birra g " + to_string(qui - consumi[28]) + "\n";

		//Lievito per dolci g 20, il valore è in char 20
		qui = stoi(lines[29].substr(20));
		if (qui < 20)
		{
			lista[29] = true;
			qui += 20;
		}
		lines[29] = "Lievito per dolci g " + to_string(qui - consumi[29]) + "\n";

		//Mandorle g 100, il valore è in char 11
		qui = stoi(lines[30].substr(11));
		if (qui < 100)
		{
			lista[30] = true;
			qui += 100;
		}
		lines[30] = "Mandorle g " + to_string(qui - consumi[30]) + "\n";

		//Maraschino g 100, il valore è in char 13
		qui = stoi(lines[31].substr(13));
		if (qui < 100)
		{
			lista[31] = true;
			qui += 100;
		}
		lines[31] = "Maraschino g " + to_string(qui - consumi[31]) + "\n";

		//Marsala ml 100, il valore è in char 11
		qui = stoi(lines[32].substr(11));
		if (qui < 100)
		{
			lista[32] = true;
			qui += 100;
		}
		lines[32] = "Marsala ml " + to_string(qui - consumi[32]) + "\n";

		//Marzapane g 500, il valore è in char 12
		qui = stoi(lines[33].substr(12));
		if (qui < 500)
		{
			lista[33] = true;
			qui += 500;
		}
		lines[33] = "Marzapane g " + to_string(qui - consumi[33]) + "\n";

		//Mascarpone g 1000, il valore è in char 13
		qui = stoi(lines[34].substr(13));
		if (qui < 1000)
		{
			lista[34] = true;
			qui += 1000;
		}
		lines[34] = "Mascarpone g " + to_string(qui - consumi[34]) + "\n";

		//Mele Golden g 1000, il valore è in char 14
		qui = stoi(lines[35].substr(14));
		if (qui < 1000)
		{
			lista[35] = true;
			qui += 1000;
		}
		lines[35] = "Mele Golden g " + to_string(qui - consumi[35]) + "\n";

		//Miele g 100, il valore è in char 8
		qui = stoi(lines[36].substr(8));
		if (qui < 100)
		{
			lista[36] = true;
			qui += 100;
		}
		lines[36] = "Miele g " + to_string(qui - consumi[36]) + "\n";

		//Miele di castagno g 300, il valore è in char 20
		qui = stoi(lines[37].substr(20));
		if (qui < 300)
		{
			lista[37] = true;
			qui += 300;
		}
		lines[37] = "Miele di castagno g " + to_string(qui - consumi[37]) + "\n";

		//Miele millefiori g 100, il valore è in char 19
		qui = stoi(lines[38].substr(19));
		if (qui < 100)
		{
			lista[38] = true;
			qui += 100;
		}
		lines[38] = "Miele millefiori g " + to_string(qui - consumi[38]) + "\n";

		//Olio di semi di girasole g 1000, il valore è in char 27
		qui = stoi(lines[39].substr(27));
		if (qui < 1000)
		{
			lista[39] = true;
			qui += 1000;
		}
		lines[39] = "Olio di semi di girasole g " + to_string(qui - consumi[39]) + "\n";

		//Olio di semi l 1, il valore è in char 15
		qui = stoi(lines[40].substr(15));
		if (qui < 1)
		{
			lista[40] = true;
			qui += 1;
		}
		lines[40] = "Olio di semi l " + to_string(qui - consumi[40]) + "\n";

		//Olio d'oliva ml 500, il valore è in char 16
		qui = stoi(lines[41].substr(16));
		if (qui < 500)
		{
			lista[41] = true;
			qui += 500;
		}
		lines[41] = "Olio d'oliva ml " + to_string(qui - consumi[41]) + "\n";

		//Pangrattato g 100, il valore è in char 14
		qui = stoi(lines[42].substr(14));
		if (qui < 100)
		{
			lista[42] = true;
			qui += 100;
		}
		lines[42] = "Pangrattato g " + to_string(qui - consumi[42]) + "\n";

		//Panna liquida g 600, il valore è in char 16
		qui = stoi(lines[43].substr(16));
		if (qui < 600)
		{
			lista[43] = true;
			qui += 600;
		}
		lines[43] = "Panna liquida g " + to_string(qui - consumi[43]) + "\n";

		//Panna montata g 500, il valore è in char 16
		qui = stoi(lines[44].substr(16));
		if (qui < 500)
		{
			lista[44] = true;
			qui += 500;
		}
		lines[44] = "Panna montata g " + to_string(qui - consumi[44]) + "\n";

		//Pasta di pistacchi g 100, il valore è in char 21
		qui = stoi(lines[45].substr(21));
		if (qui < 100)
		{
			lista[45] = true;
			qui += 100;
		}
		lines[45] = "Pasta di pistacchi g " + to_string(qui - consumi[45]) + "\n";

		//Pecorino g 1000, il valore è in char 11
		qui = stoi(lines[46].substr(11));
		if (qui < 1000)
		{
			lista[46] = true;
			qui += 1000;
		}
		lines[46] = "Pecorino g " + to_string(qui - consumi[46]) + "\n";

		//Pinoli g 100, il valore è in char 9
		qui = stoi(lines[47].substr(9));
		if (qui < 100)
		{
			lista[47] = true;
			qui += 100;
		}
		lines[47] = "Pinoli g " + to_string(qui - consumi[47]) + "\n";

		//Pinoli tostati g 100, il valore è in char 17
		qui = stoi(lines[48].substr(17));
		if (qui < 100)
		{
			lista[48] = true;
			qui += 100;
		}
		lines[48] = "Pinoli tostati g " + to_string(qui - consumi[48]) + "\n";

		//Ricotta di pecora g 2000, il valore è in char 20
		qui = stoi(lines[49].substr(20));
		if (qui < 2000)
		{
			lista[49] = true;
			qui += 2000;
		}
		lines[49] = "Ricotta di pecora g " + to_string(qui - consumi[49]) + "\n";

		//Rum cucchiai 10, il valore è in char 13
		qui = stoi(lines[50].substr(13));
		if (qui < 10)
		{
			lista[50] = true;
			qui += 10;
		}
		lines[50] = "Rum cucchiai " + to_string(qui - consumi[50]) + "\n";

		//Sale g 100, il valore è in char 7
		qui = stoi(lines[51].substr(7));
		if (qui < 100)
		{
			lista[51] = true;
			qui += 100;
		}
		lines[51] = "Sale g " + to_string(qui - consumi[51]) + "\n";

		//Savoiardi g 500, il valore è in char 12
		qui = stoi(lines[52].substr(12));
		if (qui < 500)
		{
			lista[52] = true;
			qui += 500;
		}
		lines[52] = "Savoiardi g " + to_string(qui - consumi[52]) + "\n";

		//Scorza d'arancia n 10, il valore è in char 19
		qui = stoi(lines[53].substr(19));
		if (qui < 10)
		{
			lista[53] = true;
			qui += 10;
		}
		lines[53] = "Scorza d'arancia n " + to_string(qui - consumi[53]) + "\n";

		//Scorza di limone n 10, il valore è in char 19
		qui = stoi(lines[54].substr(19));
		if (qui < 10)
		{
			lista[54] = true;
			qui += 10;
		}
		lines[54] = "Scorza di limone n " + to_string(qui - consumi[54]) + "\n";

		//Strutto g 200, il valore è in char 10
		qui = stoi(lines[55].substr(10));
		if (qui < 200)
		{
			lista[55] = true;
			qui += 200;
		}
		lines[55] = "Strutto g " + to_string(qui - consumi[55]) + "\n";

		//Uova n 12, il valore è in char 7
		qui = stoi(lines[56].substr(7));
		if (qui < 12)
		{
			lista[56] = true;
			qui += 12;
		}
		lines[56] = "Uova n " + to_string(qui - consumi[56]) + "\n";

		//Uvetta g 150, il valore è in char 9
		qui = stoi(lines[57].substr(9));
		if (qui < 150)
		{
			lista[57] = true;
			qui += 150;
		}
		lines[57] = "Uvetta g " + to_string(qui - consumi[57]) + "\n";

		//Vaniglia aroma n 10, il valore è in char 17
		qui = stoi(lines[58].substr(17));
		if (qui < 10)
		{
			lista[58] = true;
			qui += 10;
		}
		lines[58] = "Vaniglia aroma n " + to_string(qui - consumi[58]) + "\n";

		//Zucchero g 1000, il valore è in char 11
		qui = stoi(lines[59].substr(11));
		if (qui < 1000)
		{
			lista[59] = true;
			qui += 1000;
		}
		lines[59] = "Zucchero g " + to_string(qui - consumi[59]) + "\n";

		//Zucchero a velo vanigliato g 1000, il valore è in char 29
		qui = stoi(lines[60].substr(29));
		if (qui < 1000)
		{
			lista[60] = true;
			qui += 1000;
		}
		lines[60] = "Zucchero a velo vanigliato g " + to_string(qui - consumi[60]) + "\n";

		//Zucchero a velo g 1000, il valore è in char 18
		qui = stoi(lines[61].substr(18));
		if (qui < 1000)
		{
			lista[61] = true;
			qui += 1000;
		}
		lines[61] = "Zucchero a velo g " + to_string(qui - consumi[61]) + "\n";

#pragma endregion

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
		if (lista[0])
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
void htmlricette(string path, int* ric, int len, int tot)
{
	string lines[139];
	ifstream ifhtml(path + " html\\Ricette.html"); // ifstream html; apertura file in lettura
	for (int i = 0; i < 139; i++)
	{
		getline(ifhtml, lines[i]);
		lines[i] += "\n";
	}
	ifhtml.close();

	ofstream ofhtml(path + " html\\Ricette.html"); // ofstream html; apertura file in scrittura
	for (int i = 0; i < 139; i++)
		ofhtml << lines[i];

	for (int i = 1; i <= tot; i++)
	{
		for (int j = 0; j < len; j++)
			if (ric[j] == i)
			{
				ofhtml << "\t<p id = \"ricettetesto\">\n";
				string line = path + "\\libro delle ricette\\ricetta" + to_string(ric[j]) + ".txt";
				ifstream ifric(line); // ifstream ricette; apertura file in lettura
				while (getline(ifric, line))
					ofhtml << line << endl;
				ifric.close();
				ofhtml << "\t</p>\n";
				break;
			}
	}
	ofhtml << "</body>\n</html>";
	ofhtml.close();
}

void htmldispensa(string path)
{
	string lines[139];
	ifstream ifhtml(path + " html\\Dispensa.html"); // ifstream html; apertura file in lettura
	for (int i = 0; i < 139; i++)
	{
		getline(ifhtml, lines[i]);
		lines[i] += "\n";
	}
	ifhtml.close();

	ofstream ofhtml(path + " html\\Dispensa.html"); // ofstream html; apertura file in scrittura
	for (int i = 0; i < 139; i++)
		ofhtml << lines[i];

	ofhtml << "\t<p id = \"listadispensa\">\n";
	string line = path + "\\magazzino.txt";
	ifstream ifmag(line); // ifstream magazzino; apertura file in lettura
	while (getline(ifmag, line))
		ofhtml << line << endl;
	ifmag.close();
	ofhtml << "\t</p>\n</body>\n</html>";
	ofhtml.close();
}