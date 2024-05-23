#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <vector>

using namespace std;

// Define a class to represent the maze map
class Maze {
private:
    vector<vector<int>> map; // 2D vector to hold the maze map
    int rows, cols; // Size of the maze
public:
    pair<int, int> playerPosition; // Player's position

    // Constructor
    Maze(vector<vector<int>> map) : map(map) {
        rows = map.size();
        cols = map[0].size();
        // Set player's initial position
        playerPosition = make_pair(1, 1);
    }

    // Function to print the maze to the screen
    void printMaze() {
        cout << "Harita:\n";
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (i == playerPosition.first && j == playerPosition.second)
                    cout << "P ";
                else if (map[i][j] == 1)
                    cout << "- ";
                //else if (map[i][j] == 2)
                    //cout << "S ";
                else if (map[i][j] == 3)
                    cout << "E ";
                else if (map[i][j] == 5)
                    cout << "# ";
                else
                    cout << "X ";
            }
            cout << endl;
        }
    }

    // Function to update player's position
    void movePlayer(int newRow, int newCol) {
        if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && map[newRow][newCol] == 1) {
            playerPosition = make_pair(newRow, newCol);
            if (playerPosition.first == rows - 1 && playerPosition.second == cols - 1) {
                cout << "Tebrikler! Labirenti basariyla tamamladin." << endl;
                exit(0);
            }
        }
    }
};

int startMazeGame(){
    vector<vector<int>> map = {
        {5,5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,5},
        {5,1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 3,5},
        {5,1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1,5},
        {5,1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1,5},
        {5,0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1,5},
        {5,1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1,5},
        {5,1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1,5},
        {5,1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1,5},
        {5,1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1,5},
        {5,1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1,5},
        {5,1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1,5},
        {5,5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,5}
    };

    Maze maze(map);
    int control = 0;

    cout << "Bulut ve Boncuk burasinin ne oldugunu anlamaya calisirlar fakat en ufak bir ipucu bile yoktur. Duvarlar bulutun boyunu bir hayli asiyordur bu yuzden duvarlarin arkasinda ne olduguna bakamaz.\n"
        << "Ne yapacaklarini dusunurken Boncuk 'Beni kucagina al' der.  Bulut ne oldugunu anlamaz fakat Boncuk'u kucagina alir. Boncuk kendisini yukariya firlatmasini ister.\n"
        << "Bu sekilde yukarida ne var gorup ogreneceklerini dusunur. Bulut Boncuk'u yukariya firlatir ve Boncuk gordukleri karsisinda cok sasirir cunku onlerinde kocaman bir labirent vardir.\n"
        << "Megerse bu duvarlar da labirentin duvarlaridir. Bulut bir anda yere oturur ve aglamaya baslar. Burada kaybolacaklarini dusunur ve cok panikler. Boncuk gelip Bulut'a sarilir ve onu sakinlestirir.\n"
        << "Boncuk: Lutfen sakin ol (Mrrr..). Birlik olup bunu basarabiliriz, uzulme sen bitecek bu oyun ikimiz de annemize kavusacagiz. Hadi kalk artik bulmamiz gereken bir yol var.\n"
        << "Bulut oldugu yerden kalkar ve maceraya koyulurlar. Onlerinde baska yol olmadigi icin labirentin tek giris kapisindan iceri girerler...\n\n";

    while (true) {
        maze.printMaze();
        
        cout << "\nSecenekler (W: Yukari, A: Sola, S: Asagi, D: Saga): ";
        char move;
        cin >> move;

        int newRow = maze.playerPosition.first;
        int newCol = maze.playerPosition.second;

        switch (move) {
            case 'W': // Up
            case 'w': // Up
                newRow--;
                break;
            case 'A': // Left
            case 'a': // Left
                newCol--;
                break;
            case 'S': // Down
            case 's': // Down
                newRow++;
                break;
            case 'D': // Right
            case 'd': // Right
                newCol++;
                break;
            default:
                cout << "Yanlis secim!" << endl;
                continue;
        }

        maze.movePlayer(newRow, newCol);
        pair<int,int> position(newRow, newCol);

        if(position == pair<int,int>{7,11} && control<1){
            maze.printMaze();
            cout << "\nDuvarda asili olarak eski bir kagit bulurlar. Kagidi almak icin kagida uzanirlar.\nKagidi almak icin bir tusa basin...\n\n" << endl;
            {
                string a; 
                cin >> a;
            }
            cout << "TEBRIKLER! LABIRENTIN ORTASINA KADAR GELDINIZ. LABIRENTIN SONUNDA SIZI BIR SURPRIZ BEKLIYOR. BIR AN ONCE DOGRU YOLU BULUP LABIRENTI BITIRMEYE BAKIN VE BU KAGIDI DA YANINIZA ALMAYI UNUTMAYIN!!\n"
                << "- Bu mesaji okuyan Bulut cok sevinir ve labirentin sonundaki surprizin aradiklari esya oldugunu dusunerek buyuk bir heyecanla labirentte yollarina devam ederler...\n\n";
            control++;
        }
        
        if(position == pair<int,int>{1,20}){
            //maze.printMaze();
            cout << "\nVe artik labirentin cikisina gelmislerdir. Orada cok guzel ciceklerle dolu bir kapi onlari bekliyordur ama bir sey eksiktir. Saturn simgesini hala bulamamislardir.\n"
                << "Etrafa bakinirlar. Duvarda bir tasin uzerinde Saturn simgesinin kabartma seklinde orada oldugunu fark ederler. Ama koskoca tasi nasil alabilirlerdi ki? Dusunmeye baslarlar\n"
                << "Sonrasinda kagidin uzerindeki not akillarina gelir. Demek ki kagit da bu odadan cikmak icin gerekli bir malzemeydi. Bir anda Bulut'un kafasinda simsekler cakar ve aklina guzel bir fikir gelir.\n"
                << "Cantasindan kagidi ve kalemi cikartir. Duvardaki Saturn simgeli tasin uzerine kagidi koyar ve kalem ile karalamaya baslar. Artik Saturn simgesi bu ozel kagidin uzerindedir.\n"
                << "Ve bir anda o guzel rengarenk ciceklerle cevrili kapi gecide donusur...";
            return 25;
        }
    }
}

#endif