#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h> // To make spawn value more random

using namespace std;
bool gameOver;
const int width = 20;
const int height = 20;
int hatasayisi = 0;

void sw1(){
    cout<<"Yerde samanlarin, samanlarin uzerinde buyuk taslarin oldugu bu oda hayvanat bahcesindeki yilanlarin oldugu bir odadir. Buraya nerden dustukleri ise tam bir muammadir. Olduklari yerin 3 tarafi camla cevrili olup kalan diger\nkismi da gorevlilerin hayvanlarin bakimini yapmak icin girdikleri kapidan olusuyordur."
    "Nerden girdiklerine bakinirlarken tavanda girilmez isareti olan bir kapagin oldugunu gorurler. Buradan dusmus olma ihtimalleri yuksektir.\nNereden geldiklerin bulduktan sonra onlardan uzakta duran korkmus , Bulut ve Boncugu tehdit olarak algilamis olan yilana bakarlar. Sanki yilanda bir gariplik vardir. Bir sey yutmus da hareket edemiyor gibi duruyordur.\n" 
    "Gorevlilerin girip ciktigi kapiyi acarak yardim edebilecek birleri var mi diye bakarlar. Orada bir hayvan bakicisi gorurler ve bakiciya olayi anlatirlar. Adam bu endemik olan yilan turunun son ornegini kaybetmemek icin\nelinden geldigince hizli bir sekilde yilanin oldugu yere girer. Telasindan cocugun ve kedinin orada ne islerinin oldugunu bile sormayi akil edememistir." 
    "Bakici iceri girdigi gibi turunun kedi gozlu yilan oldugunu ogrendikleri yilani\nelindeki uzun sopa gibi bir aletle yakalar. Zehirli oldugunu duyduklari yilanin bitkinlikten zehrini akitacak enerjisi bile kalmamistir. Bir an once kurtarilmasi gerekiyordur. Bakicinin cabalari sonucunda yilan takili kalan parcayi\ncikarmistir. Bu bir cocuk oyuncagina benziyordur. Yumurta gibi"
    "sekli olan bu oyuncagi actiklarinda icinde bir yilan oyunu oldugunu gorurler. Buradan cikmanin yolu olarak bu oyunu gecmelerinin oldugunu dusunurler ve oynamaya baslarlar."<<endl;
}

int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;

enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirecton dir;

/*void Setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}*/
void Setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
    nTail = 0; // Yilanin uzunlugunu sifirla
}

void Draw()
{
    system("cls"); //system("clear");
    cout << endl;
    cout << " ";
    for (int i = 0; i < width+2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << " #";
            if (i == y && j == x)
                cout << "O";
            else if (i == fruitY && j == fruitX)
                cout << "F";
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print)
                    cout << " ";
            }

            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }

    cout << " ";
    for (int i = 0; i < width+2; i++)
        cout << "#";
    cout << endl;
    cout << " Score:" << score << endl;
}
void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'x':
                gameOver = true;
                break;
            default:
                break;
        }
    }
}
void Logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir)
    {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
    }
    if (x > width || x < 0 || y > height || y < 0)
      gameOver = true;
    //if (x >= width) x = 0; else if (x < 0) x = width - 1;
    //if (y >= height) y = 0; else if (y < 0) y = height - 1;

    for (int i = 0; i < nTail; i++)
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;

    if (x == fruitX && y == fruitY)
    {
        srand(time(0)); // Random seed value for rand based on time
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}

void Basla(){
       //Will make cout much faster
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int control = 0;
    
    //system("MODE con cols=24 lines=25");
    
    while(control == 0){
        Setup();
        while (!gameOver)
        {
            Draw();
            Input();
            Logic();
            Sleep(50); //sleep(10);
        }
        if(score > 100){
            control = 25;
        }else{
            hatasayisi++;
            cout << "100 skorun altinda kaldiniz. Hataniz 1 arttirildi. Yeniden oynamak icin herhangi bir tusa basin...\n";
            _getch();
        }
    }
}

void sw2(){
    cout<<"Oyunu gectiklerinde o girilmez isareti olan yukaridaki kapak acilir. Kendine gelen yilan oraya dogru yukselir ve icerisinde saklanmis gibi duran esyayi samanlarin uzerine dusurur. Bu eskiden izledigi bir filimde duydugu Kleopatra'nin yumurtalarindan birisidir. ustelik uzerinde aradiklari imge vardir. Kapak acildiginda bir"
    "diger yere dusen butona basmalariyla yukardan merdiven iner ve ona sirayla tirmanarak yukari cikarlar. Yumurtayi da alip ciktiklarinda"<<endl;
    cout<<"Cikmak icin 'e' tusuna basin."<<endl;
    char tus='\0';
    while (true)
    {
        cin>>tus;
        if (cin.peek()=='\n')
        {
            if (tus=='e' || tus=='E')
            {
                break;
            }else{
                cout<<"Hatali Giris Yaptiniz Tekrar Deneyin!!!"<<endl;
            }
            
        }else{
            cout<<"Hatali Giris yaptiniz Terkar Deneyin!!!"<<endl;
            cin.clear();
            cin.ignore(100000,'\n');
        }
        
    }
    cout<<"bir tunelde olduklarini gorurler biraz daha ilerleyip tunelin sonuna geldiklerinde tunelin sonunda bulunan kapagi acarlar ve bir sonraki odaya gecerler."<<endl;
}

int startSnakeGame(){
    sw1();
    cout<<"Oyuna Baslamak Icin Herhangi Bir Tusa Basiniz:"<<endl;
    cin.ignore();
    Basla();
    sw2();
    return hatasayisi;
}

#endif