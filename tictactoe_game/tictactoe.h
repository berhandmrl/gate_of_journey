#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

char field[10];

int singleplayer();
void multiplayer();
void help();
bool checkFull();
bool checkWin(char);
char keyInput(bool x);
void AI(int);


void clearConsole()
{
    system("cls");
}

void resetField()
{
    for(int i = 0; i < 10; i++)
    {
	field[i] = ' ';
    }
}

int menu()
{
	int sayi= 0, hatasayisi =0;
	do{
		resetField();
		char inputmenu;
		cout << "\n\n"
			<< "Menu\n\n"
			<< "1: Oyuna Basla\n"
			//<< "2: Multiplayer\n"
			<< "2: Yardim\n"
			//<< "3: Cikis\n\n\n"
			<< "Yapmak istediginiz islemi secin: ";
		cin >> inputmenu;
		
		if(inputmenu == '1'){
			sayi = singleplayer();
			if(sayi == 0)
				hatasayisi++;
		}
		else if(inputmenu == '2'){
			help();
			sayi = 0;
			}else {clearConsole(); cout << "\nYanlis secim!";}
		//else if(inputmenu == '3' || inputmenu == 'q')return 0;
		
	}while(sayi != 25);
    //while(true){
	/*resetField();
	char inputmenu;
	cout << "\n\n"
	     << "MENU\n\n"
	     << "1: Singleplayer\n"
	     //<< "2: Multiplayer\n"
	     << "2: Help\n"
	     << "3: Quit\n\n\n"
	     << "Input: ";
	cin >> inputmenu;
	
	if(inputmenu == '1')
		sayi = singleplayer();
	//else if(inputmenu == '2')multiplayer();
	else if(inputmenu == '2')help();
	else if(inputmenu == '3' || inputmenu == 'q')return 0;
	else {clearConsole(); cout << "\nInvalid Input!";}*/
    //}

	return hatasayisi;
}

void drawField()
{
    //clearConsole();
    cout << "\n\n\n"
	 << "     " << field[1] << " | " << field[2] << " | " << field[3] << endl
	 << "    ---|---|---" << endl
	 << "     " << field[4] << " | " << field[5] << " | " << field[6] << endl
	 << "    ---|---|---" << endl
	 << "     " << field[7] << " | " << field[8] << " | " << field[9] << endl;
}

int singleplayer()
{
    //clearConsole();
    char input = ' ';
    int difficulty = 3;
    /*cout << "\n\n\nDIFFICULTY\n\n\n1: Easy\n\n2: Medium\n\n3: Hard\n\n";
    cout << "\n\n\nInput: ";
    cin >> input;*/
    /*switch(input)
    {
	case '1': difficulty = 1; break;
	case '2': difficulty = 2; break;
	case '3': difficulty = 3; break;
	case 'q': return; break;
	default:	cout << "\nInvalid Input!"; singleplayer(); break;
    }*/
    
    while(true)
    {
	drawField();
	if(checkWin('O'))
	{
	    cout << "\nRakip kazandi\n\n";
	    return 0;
	}
	if(checkFull())
	{
	    cout << "\nBerabere\n\n";
	    return 5;
	}
	input = keyInput(true);
	drawField();
	if(checkWin('X'))
	{
	    cout << "\nKazandin!\n\n";
	    return 25;
	}
	AI(difficulty);
    }
}

void multiplayer()
{
    char input = ' ';
    bool player1Turn = true;
    while(true)
    {
	drawField();
	if(checkWin('X'))
	{
	    cout << "\nPlayer1 has won\n\n";
	    return;
	}
	else if(checkWin('O'))
	{
	    cout << "\n Player2 has won\n\n";
	    return;
	}
	if(checkFull())
	{
	    cout << "Tie\n\n";
	}
	input = keyInput(player1Turn);
	if (input == 'q')
	{
	    return;
	}
	player1Turn = !player1Turn;
    }
}

void help()
{
    clearConsole();
    //cout << "\n\n\nYardim\n\nSingleplayer:\nIn Singleplayermode you play against the Computer\n\nMultiplayer:\nIn Multiplayermode you play against a second player. Input switches between X and O. You can also play this mode if you want to test new tactics or just want to play against yourself.\n\nControls:\nTo choose a field you must enter a number between 1 and 9. The first field is in the top left. the second right next to it etc.\n\n";
    cout << "\n\n\nYardim\n\nOyun Mantigi:\nBilgisayara karsi oynarsiniz\n\nKontroller:\nAlan secmek icin 1 ve 9 arasinda sayi girin. Sol ust satir 1, sag en alt 9 olacak sekilde.\n\n";
	return;
}

char keyInput(bool x)
{
    while(true)
    {
	cout << "\n\nAlan secin: ";
	char input = ' ';
	cin >> input;
	int inputNumber = input - '0';
	if(inputNumber > 9 || inputNumber < 1)
	{
	    if(input == 'q')
		return input;
	    else
		cout << "\nYanlis secim!";
	}
	else if(field[inputNumber] != ' ')
	{
	    cout << "\nZaten bu alan kullaniliyor";
	}
	else
	{
	    if(x)
		field[inputNumber] = 'X';
	    else
		field[inputNumber] = 'O';
	    return input;
	}
    }
}

bool checkWin(char sign)
{
    if (field[1] == sign && field[2] == sign && field[3] == sign || field[1] == sign && field[4] == sign && field[7] == sign || field[1] == sign && field[5] == sign && field[9] == sign || field[2] == sign && field[5] == sign && field[8] == sign || field[3] == sign && field[6] == sign && field[9] == sign || field[3] == sign && field[5] == sign && field[7] == sign || field[4] == sign && field[5] == sign && field[6] == sign || field[7] == sign && field[8] == sign && field[9] == sign)
    {
	return true;
    }
    return false;
}

bool checkFull()
{
    for(int i = 1; i <= 9; i++)
    {
	if(field[i] == ' ')
	{
	    return false;
	}
    }
    return true;
}

void AI(int difficulty)
{
    if(checkFull())
    {
	return;
    }
    
    srand(time(nullptr));
    
    if(difficulty == 1)
    {
	int check = rand() % 3;
	if(check != 1)
	{
	    for(int i = 1; i < 10; i++)
	    {
		if(field[i] == ' ')
		{
		    field[i] = 'O';
		    if(checkWin('O'))
		    {
			return;
		    }
		    else
		    {
			field[i] = ' ';
		    }
		}
	    }
	}
	else if(check != 2)
	{
	    for(int i = 1; i < 10; i++)
	    {
		if(field[i] == ' ')
		{
		    field[i] = 'X';
		    if(checkWin('X'))
		    {
			field[i] = 'O';
			return;
		    }
		    else
		    {
			field[i] = ' ';
		    }
		}
	    }
	}
	while (true)
	{
	    int i = rand() % 9 + 1;
	    if (field[i] == ' ')
	    {
		field[i] = 'O';
		return;
	    }
	}
    }
    else if(difficulty == 2)
    {
	int check = rand() % 5 + 1;
	if(check != 3)
	{
	    for(int i = 1; i < 10; i++)
	    {
		if(field[i] == ' ')
		{
		    field[i] = 'O';
		    if(checkWin('O'))
		    {
			return;
		    }
		    else
		    {
			field[i] = ' ';
		    }
		}
	    }
	}
	else if(check != 4)
	{
	    for(int i = 1; i < 10; i++)
	    {
		if(field[i] == ' ')
		{
		    field[i] = 'X';
		    if(checkWin('X'))
		    {
			field[i] = 'O';
			return;
		    }
		    else
		    {
			field[i] = ' ';
		    }
		}
	    }
	}
	while (true)
	{
	    int i = rand() % 9 + 1;
	    if (field[i] == ' ')
	    {
		field[i] = 'O';
		return;
	    }
	}
    }
    else if(difficulty == 3)
    {
	//Hard
	//Check if AI can win
	for(int i = 1; i < 10; i++)
	{
	    if(field[i] == ' ')
	    {
		field[i] = 'O';
		if(checkWin('O'))
		{
		    return;
		}
		else
		{
		    field[i] = ' ';
		}
	    }
	}
	
	//Check if Player can win and stop it ;)
	for(int i = 1; i < 10; i++)
	{
	    if(field[i] == ' ')
	    {
		field[i] = 'X';
		if(checkWin('X'))
		{
		    field[i] = 'O';
		    return;
		}
		else
		{
		    field[i] = ' ';
		}
	    }
	}
	
	//Set to field in the middle with a chance when it is still free
	int middle = rand() % 4;
	if(field[5] == ' ' && middle != 1)
	{
	    field[5] = 'O';
	    return;
	}
	
	//Select random field
	while(true)
	{
	    srand(time(nullptr));
	    int i = rand() % 9 + 1;
	    if(field[i] == ' ')
	    {
		field[i] = 'O';
		return;
	    }
	}
    }
    else
    {
	return;
    }
}

int startTictactoeGame(){
	int sayii = 0;
	srand(time(nullptr));
	cout << "Sanki kapinin arkasinda birden fazla birbiriyle oynayan , neseli cocuk vardi. Bulut ve Boncuk kapiyi acmaya calisirlar. Kapiyi acmak onlari biraz zorlamistir.\n"
		<< "Kapi bir cocugun acabilecegi agirligin cok cok uzerindedir. Kapiyi zar zor da olsa acarlar ve icerisi tam da tahmin ettikleri gibi kendi yaslarinda cocuklarin oldugu beklemedikleri kadar buyuk bir oyun odasidir.\n"
		<< " Iceride her turden oyuncak vardir. Ilk defa onlarin yasina uygun bir odaya denk gelmislerdir. Bu oda onlarin o kadar ilgisini cekmistir ki hic gitmemeyi bile dusunmuslerdir.\n"
		<< "Gozlerine kestirdikleri bir oyuncagin yanina giderler. Bu oyuncak oltayla balik tutma oyunudur. Kedinin de fazlaca dikkatini cekmistir.\n"
		<< "Bir suru balik tutarlar ve bundan sikilarak diger oyuncaklara bakinirlar. Etrafta o kadar guzel seyler vardir ki neyle oynayacaklarini sasirmislardir.\n"
		<< "Odanin ortalarina gittiklerinde bu sefer karsilarinda bir oyuncak yoktur. Birden fazla cocugun birlikte oynadigi mendil kapmaca oyunu vardir.\n"
		<< "Yanlarina giderler ve biz de oynayabilir miyiz diye sorarlar. Cogunlugunun cok sevecen oldugunu dusundukleri bu cocuklar hemen Bulut ve Boncuk'u oyuna kabul ederler.\n"
		<< "En son gelen kisi Bulut oldugu icin ebe o olmustur. Mendili onceki ebeden alir. Oynamaya hazirlardir. Bu oyunun ana mantigi yerde daire seklinde oturan cocuklarin arkalarinda ebe gezinirken birisinin arkasina mendili birakmasidir.\n"
		<< "Eger arkasina mendil konulan kisi ebeyi onun yerine oturmadan yakalayabilirse ebe ebelik yapmaya devam eder, yakalayamazsa artik yeni ebe kendisidir.\n"
		<< "Oyunu bu sekilde oynamalari gerekmektedir. Bulut yeni tanistigi sari sacli mavi gozlu isminin ela oldugu bir kizin arkasina mendili koyar ve Ela Bulut'u yakalayamaz. Yeni ebe Ela olmustur.\n"
		<< "Bir sure bu sekilde oyunu oynarlar. Oyun bittikten sonra ayni ekip hep birlikte biraz ileride olan masanin basina XOX oynamak icin otururlar.\n"
		<< "Bulut mendil kapmaca oynarken de olan biriyle eslesmistir. Ikisi birlikte oyun oynamaya baslarlar.\n";
    sayii = menu();

	cout << "Oyun bittikten sonra Bulut'un dikkatini cocukta olan bir sey ceker. Cocugun elindeki mendil, mendil kapmacadaki mendildir ama daha once oyun oynarken o adrenalinle mendilin uzerindeki Saturn cizimi dikkatlerini cekmemistir.\n"
		<< "Gordukleri gibi nasil alacagini dusunurler. Ilk izlenim olarak elinde mendil olan cocuk bencil birisine benziyordur. Mendili almak onlar icin zor olacaktir.\n"
		<< "Akillarina kendilerinde olan bir oyuncakla degis tokus yapma fikri gelir fakat yanlarindaki tek oyuncak Bulut'un evden ayrilirken yaninda olan oyuncagidir.\n"
		<< "Bir secim yapmak zorundadir ya buradan cikamayacaklardir ya da onun icin cok degerli olan oyuncagini verip evlerine ulasmak icin bir adim daha atmis olacaklardir.\n"
		<< "Tabi ki de oyuncagini vermeyi secer. Oyuncagi Gorkem isimli cocuga uzatir.Gorkem'in Bulut'un elindeki oyuncak oldukca ilgisini ceker ve Bulut'un sundugu teklifi hemen kabul eder.\n"
		<< "Artik burada durmalari icin bir neden kalmamistir. Her ne kadar burayi cok sevmis olsalar da bir an once evlerine donmek istemektedirler.\n"
		<< "Geldikleri o kocaman kapiyi itmelerine gerek kalmamistir. Kendiliginden acilmistir ve gecide donusmustur. Kapidan gecerek diger bolume gecis yaparlar.\n";
	return sayii;
}

#endif