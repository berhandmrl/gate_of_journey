#ifndef ISLAND_H
#define ISLAND_H

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int BOARD_SIZE = 4;
const int NUM_SHIPS = 5;
const int MAX_ATTEMPTS = 12;

char board[BOARD_SIZE][BOARD_SIZE];
int shipLocations[BOARD_SIZE][BOARD_SIZE] = {0};

int shipsRemaining = NUM_SHIPS;
int attemptsRemaining = MAX_ATTEMPTS;

void initializeBoard() {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            board[i][j] = '-';
        }
    }
}

void placeShips() {
    srand(time(NULL));
    for (int i = 0; i < NUM_SHIPS; ++i) {
        int x = rand() % BOARD_SIZE;
        int y = rand() % BOARD_SIZE;
        if (shipLocations[x][y] != 1) {
            shipLocations[x][y] = 1;
        } else {
            --i;
        }
    }
}

void printBoard() {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == '-' && shipLocations[i][j] == 1) {
                cout << "-";
            } else {
                cout << board[i][j];
            }
            cout << " ";
        }
        cout << endl;
    }
}

int startIslandGame(){
    char choice;
    int hatasayisi = 0;

    cout << "Gokyuzunun mavisi ve denizin seffafligi birlesince mukemmel bir goruntu olusturuyordu. Ortam cok issiz ama bir o kadar da huzurluydu. Sicak kumlarda denizin kenarinda yavas yavas yurumeye baslarlar.\n"
        << "Yururken sol taraflarinda bir sandik bulurlar. Sandik bayagi eski yillardan kalma bir sandiga benziyordur. Kahverengi olan bu sandik tozlanmaktan griye donusmustur ve uzerini orumcek aglari kaplamistir.\n"
        << "Onemli bir sey oldugunu dusunurler ve acmaya calisirlar fakat sandigin kilit kismi bir hayli sikismistir. Cevrede bunu acabilecek bir sey olup olmadigina bakarlar. Boncuk uzaktan bir tane odun getirir.\n"
        << "Bulut da sahil kenarinda gezinirken bir demir parcasi bulur. Bu demir parcasi tipki bir cekic ucuna benziyordur. Ikisinin de buldugu esyalar bu sandigi acmak icin elverisli olabilir. Bulut bir ip bulur ve demir ile odunu birbirine baglar.\n";

    cout << "Birlestirmek icin herhangi bir tusa basin...\n";
    {
        string a; 
        cin >> a;
    }

    cout << "Artik ellerinde bir cekic vardir. Bu cekici kullanarak sandigin kilidini zorlarlar ve acarlar. Sandigin icinde eski korsan esyalari bulurlar.\n"
        << "Bir tane korsan sapkasi, durbun ve bir tane de pili bitmis bir oyuncak ekrani bulurlar.Sonra kutunun icine biraz daha baktiklarinda pil bulurlar ve oyuncaga takarlar.\n"
        << "Oyuncak birden gurultuyle calismaya baslar. Ekranda amiral batti oyunu vardir. Oyunu oynamaya baslarlar...\n\n";

    do {
        initializeBoard();
        shipsRemaining = NUM_SHIPS;
        attemptsRemaining = MAX_ATTEMPTS;
        placeShips();

        cout << "Amiral Batti Oyununa Hosgeldin!!" << endl;
        cout << NUM_SHIPS << " gemiyi batirmak icin " << attemptsRemaining << " hakkin var! " << endl;

        while (attemptsRemaining > 0 && shipsRemaining > 0) {
            printBoard();
            int x, y;
            cout << "Satir ve sutun girin (0 dan " << BOARD_SIZE - 1 << "): ";
            while (true)
            {
                cin >> x >> y;
                if (cin.fail())
                {
                    cout<<"Hatali Giris Yaptiniz Tekrar Deneyin"<<endl;
                    cin.clear();
                    cin.ignore();
                }else{
                    break;
                }
                
            }
            if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
                cout << "Yanlis secim. Tekrar dene." << endl;
                continue;
            }

            if (board[x][y] == '-' && shipLocations[x][y] == 1) {
                cout << "Tebrikler! Bir gemiyi batirdin." << endl;
                board[x][y] = 'G';
                --shipsRemaining;
                if (shipsRemaining > 0) {
                    cout << "Kalan gemi sayisi: " << shipsRemaining << endl;
                } else {
                    printBoard();
                    cout << "\nOyunu kazandiklari anda oyuncagin uzerinden ozel bir bolme acilir. Bu bolmenin icerisinde ufak bir korsan gemisi oyuncagi vardir. Bulut gemiyi eline alip inceler.\n"
                    << "Tam da tahmin ettigi gibi geminin uzerinde Saturn simgesi vardir. Gemiyi de cantaya atip yola koyulurlar. Karsilarina bir gecit acilir ve gecide girerler...";
                    return hatasayisi;
                }
            } else {
                cout << "Kacirdin." << endl;
                if (board[x][y] == '-') {
                    board[x][y] = 'X';
                }
            }

            --attemptsRemaining;
            cout << "Kalan hak: " << attemptsRemaining << endl;
        }

        if (shipsRemaining > 0) {
            cout << "Haklarin bitti. Kaybettin!! Sansini tekrar dene!!" << endl << endl << endl;
            hatasayisi++;
        }

    } while (true);
}

#endif