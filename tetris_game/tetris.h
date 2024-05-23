#ifndef TETRIS_H
#define TETRIS_H

#include<vector>
#include<iostream>
#include<string>
#include<random>
#include<cctype>
using namespace std;
int sayac = 0;

struct Point {
	private: int x, y;
	public:
		void print() {
			cout << x << ", " << y << endl;
		}
		Point operator + (Point p) {
			return Point(x + p.x, y + p.y);
		}
		Point operator - (Point p) {
			return Point(x - p.x, y - p.y);
		}
		
		Point(int X, int Y) : x(X), y(Y) {}
		int GetX() {
			return x;
		}
		int GetY() {
			return y;
		}
};
class Block {
	protected:
		vector<Point> points;
	public:
		void print() {
			int size = 20;
			int center = size/2;
			vector<vector<bool> > grid(size, vector<bool>(size, false));
			for(int i = 0; i < points.size(); i++) {
				Point p = points[i];
				grid[center + p.GetY()][center + p.GetX()] = true;
			}
			
			for(int y = size - 1; y > -1; y--) {
				for(int x = 0; x < size; x++) {
					cout << (grid[y][x] ? 'X' : '.');
				}
				cout << endl;
			}
		}
		void RotateCW(Point pivot) {
			for(int i = 0; i < points.size(); i++) {
				Point *p = &points[i];
				Point displacement = *p - pivot;
				//2, 5 -> 5, -2
				*p = pivot + Point(displacement.GetY(), -displacement.GetX());
			}
		}
		void RotateCCW(Point pivot) {
			for(int i = 0; i < points.size(); i++) {
				Point *p = &points[i];
				Point displacement = *p - pivot;
				//5, -2 -> 2, 5
				*p = pivot + Point(-displacement.GetY(), displacement.GetX());
			}
		}
		void Displace(Point displacement) {
			for(int i = 0; i < points.size(); i++) {
				points[i] = points[i] + displacement;
			}
		}
		void Descend() {
			Displace(Point(0, -1));
		}
		void Right() {
			Displace(Point(1, 0));
		}
		void Left() {
			Displace(Point(-1, 0));
		}
		vector<Point> GetPoints() {
			return points;
		}
		Block() {}
		Block(vector<Point> p) {
			points = p;
		}
};
class Tetromino : public Block {
	public: Tetromino(Point p1, Point p2, Point p3, Point p4) {
		points.push_back(p1);
		points.push_back(p2);
		points.push_back(p3);
		points.push_back(p4);
	}
};
Tetromino T() {
	return Tetromino(Point(0, 0), Point(0, 1), Point(-1, 1), Point(1, 1));
}
Tetromino O() {
	return Tetromino(Point(0, 0), Point(0, 1), Point(1, 0), Point(1, 1));
}
Tetromino I() {
	return Tetromino(Point(0, 0), Point(0, 1), Point(0, 2), Point(0, 3));
}
Tetromino L() {
	return Tetromino(Point(0, 2), Point(0, 1), Point(0, 0), Point(1, 0));
}
Tetromino J() {
	return Tetromino(Point(0, 2), Point(0, 1), Point(0, 0), Point(-1, 0));
}
Tetromino S() {
	return Tetromino(Point(-1, 0), Point(0, 0), Point(0, 1), Point(1, 1));
}
Tetromino Z() {
	return Tetromino(Point(-1, 1), Point(0, 1), Point(0, 0), Point(1, 0));
}
Tetromino GetRandomBlock() {
	Tetromino blocks[] = {T(), O(), I(), L(), J(), S(), Z()};
	return blocks[rand()%7];
}
void print(vector< vector<bool> > grid) {
	for(int y = grid.size() - 1; y > -1; y--) {
		for(int x = 0; x < grid[y].size(); x++) {
			cout << (grid[y][x] ? 'X' : '.');
		}
		cout << endl;
	}
}
void AddBlockToGrid(vector< vector<bool> > &grid, Tetromino t);
bool IsValid(const vector< vector<bool> > &grid, Point p);
bool CanOccupy(vector< vector<bool> > &grid, Tetromino t);
int ClearLines(vector< vector<bool> > &grid);
bool IsLost(vector< vector<bool> > &grid);
/*int main() {
	cout	<< "Cetris!" << endl
			<< "CONTROLS" << endl
			<< "A   Move left" << endl
			<< "S   Move down" << endl
			<< "D   Move right" << endl
			<< "Q   Spin counterclockwise" << endl
			<< "E   Spin clockwise" << endl
			<< "_   Wait" << endl;
	cout << "Enter 'S' to start." << endl;
	char c;
	do {
		cin >> c;
	} while(toupper(c) != 'S');
	int width = 10;
	int height = 20;
	vector< vector<bool> > grid(height, vector<bool>(width, false));
	Tetromino current = GetRandomBlock();
	current.Displace(Point(width/2, height-4));
	bool active = true;
	while(active) {
		//Create a copy of the grid displaying the block
		vector< vector<bool> > gridWithBlock = grid;
		AddBlockToGrid(gridWithBlock, current);
		system("cls");
		print(gridWithBlock);
		
		//cin >> c;
		string s;
		getline(cin, s);
		char c;
		if(s.size() > 0) {
			c = toupper(s[0]);
		} else {
			c = ' ';
		}
		if(c == 'A') {
			Tetromino left = current;
			left.Left();
			if(CanOccupy(grid, left)) {
				current = left;
			}
		} else if(c == 'D') {
			Tetromino right = current;
			right.Right();
			if(CanOccupy(grid, right)) {
				current = right;
			}
		} else if(c == 'S') {
			Tetromino down = current;
			down.Descend();
			if(CanOccupy(grid, down)) {
				current = down;
			}
		} else if(c == 'Q') {
			Tetromino ccw = current;
			ccw.RotateCCW(ccw.GetPoints()[1]);
			if(CanOccupy(grid, ccw)) {
				current = ccw;
			}
		} else if(c == 'E') {
			Tetromino cw = current;
			cw.RotateCW(cw.GetPoints()[1]);
			if(CanOccupy(grid, cw)) {
				current = cw;
			}
		} else if(c == ' ') {
			
		}
		
		Tetromino moved = current;
		moved.Descend();
		if(CanOccupy(grid, moved)) {
			current = moved;
		} else {
			AddBlockToGrid(grid, current);
			current = GetRandomBlock();
			current.Displace(Point(width/2, height-4));
			ClearLines(grid);
			if(IsLost(grid)) {
				cout << "Game Over!" << endl;
				active = false;
			}
		}
	}
}*/
bool IsLost(vector< vector<bool> > &grid) {
	for(int y = grid.size()-4; y < grid.size(); y++) {
		for(int x = 0; x < grid[y].size(); x++) {
			if(grid[y][x]) {
				
				return true;
			}
		}
	}
	return false;
}
int ClearLines(vector< vector<bool> > &grid) {
	for(int y = 0; y < grid.size();) {
		bool cleared = true;
		for(int x = 0; x < grid[y].size(); x++) {
			if(!grid[y][x]) {
				cleared = false;
				break;
			}
		}
		if(cleared) {
			//Clear this line
			for(int x = 0; x < grid[y].size(); x++) {
				grid[y][x] = false;
			}
			//Descend all the other lines
			for(int y2 = y; y2 + 1 < grid.size(); y2++) {
				for(int x = 0; x < grid[y2].size(); x++) {
					grid[y2][x] = grid[y2+1][x];
				}
			}
			sayac++;
		} else {
			y++;
		}
	}
	return sayac;
}
bool CanOccupy(vector< vector<bool> > &grid, Tetromino t) {
	vector<Point> points = t.GetPoints();
	for(int i = 0; i < points.size(); i++) {
		Point p = points[i];
		if(!IsValid(grid, p) || grid[p.GetY()][p.GetX()]) {
			return false;
		}
	}
	return true;
}
void AddBlockToGrid(vector< vector<bool> > &grid, Tetromino t) {
	vector<Point> points = t.GetPoints();
	for(int i = 0; i < points.size(); i++) {
		Point p = points[i];
		if(IsValid(grid, p)) {
			grid[p.GetY()][p.GetX()] = true;;
		}
	}
}
bool IsValid(const vector< vector<bool> > &grid, Point p) {
	return -1 < p.GetY() && p.GetY() < grid.size() && -1 < p.GetX() && p.GetX() < grid[p.GetY()].size();
}


int oyunn(){
	int sayacc = 0;
	cout	<< "Tetris!!" << endl;
	cout	<< "Amacin minimum 2 sira patlatabilmek. Eger patlatamazsan tekrar baslarsin!" << endl
			<< "Kontroller" << endl
			<< "A   Sola Hareket Ettir" << endl
			<< "S   Asagiya Hareket Ettir" << endl
			<< "D   Saga Hareket Ettir" << endl
			<< "Q   Saat Yonunun Tersine Cevir" << endl
			<< "E   Saat Yonunde Cevir" << endl
			<< "_   Bekle" << endl;
	cout << "Baslamak icin 'S' basin." << endl;
	char c;
	do {
		cin >> c;
	} while(toupper(c) != 'S');
	int width = 10;
	int height = 20;
	vector< vector<bool> > grid(height, vector<bool>(width, false));
	Tetromino current = GetRandomBlock();
	current.Displace(Point(width/2, height-4));
	bool active = true;
	while(active) {
		//Create a copy of the grid displaying the block
		vector< vector<bool> > gridWithBlock = grid;
		AddBlockToGrid(gridWithBlock, current);
		system("cls");
		print(gridWithBlock);
		
		//cin >> c;
		string s;
		getline(cin, s);
		char c;
		if(s.size() > 0) {
			c = toupper(s[0]);
		} else {
			c = ' ';
		}
		if(c == 'A') {
			Tetromino left = current;
			left.Left();
			if(CanOccupy(grid, left)) {
				current = left;
			}
		} else if(c == 'D') {
			Tetromino right = current;
			right.Right();
			if(CanOccupy(grid, right)) {
				current = right;
			}
		} else if(c == 'S') {
			Tetromino down = current;
			down.Descend();
			if(CanOccupy(grid, down)) {
				current = down;
			}
		} else if(c == 'Q') {
			Tetromino ccw = current;
			ccw.RotateCCW(ccw.GetPoints()[1]);
			if(CanOccupy(grid, ccw)) {
				current = ccw;
			}
		} else if(c == 'E') {
			Tetromino cw = current;
			cw.RotateCW(cw.GetPoints()[1]);
			if(CanOccupy(grid, cw)) {
				current = cw;
			}
		} else if(c == ' ') {
			
		}
		
		Tetromino moved = current;
		moved.Descend();
		if(CanOccupy(grid, moved)) {
			current = moved;
		} else {
			AddBlockToGrid(grid, current);
			current = GetRandomBlock();
			current.Displace(Point(width/2, height-4));
			sayacc = ClearLines(grid);
			if(IsLost(grid)) {
				cout << "Oyun Bitti!" << endl;
				active = false;
			}
		}
	}

	return sayac;
}

int startTetrisGame(){
	cout << "Buranin ne oldugunu anlamak icin gordukleri kapiyi acarlar ve disari bakmak isterler. Bulut tam adim atacakken boncuk onu son anda pacasindan tutup ceker.\n"
		<< "Cunku adim atsa bosluga dusecektir. Burasi bir agac evdir. Hem de upuzun bir agacin tepesinde olan bir agac evdir.\n"
		<< "Bu evin ne bir merdiveni vardir ne bir ip. Asagi inemezler. Bu sebeple evin icinde baska ipuclari aramaya baslarlar.\n"
		<< "Iki odali olan bu agac ev eskiden bir kucuk cocugun hayalini gerceklestirmis gibi duruyordur. Burasi bir tane ana girisi bulunan ve arkada da bir tane daha odasi olan bir agac evdir.\n"
		<< "Ana giriste bir koltuk ve ufak bir masa vardir. Masanin ustunde duran not kagitlarindan birkac tane cantasina atar.Herhangi bir ipucu gozukmedigi icin arka odaya gecerler.\n"
		<< "Arka odasi sanki bir cocugun oyun odasi gibi bir yerdir. Yerde bir oyuncak sepeti var ve bu sepetin icerisinde eskimis durmaktan tozlanmis bir suru oyuncak vardir.\n"
		<< "Odanin icinde ayni zamanda kucuk bir okuma kosesi bile mevcuttur. Bulut bu agac eve bayilir. Burasi tam da onun istedigi gibi bir ortamdir.\n"
		<< "Eve gidince annesine bundan istedigini soylemeye karar verir. Kedi ile beraber oyuncaklarla oynamaya baslarlar.\n"
		<< "Bir sure oynadiktan sonra oyuncak sepetinin en dibinde bir tetris oyuncagi gorurler. Bu oyun Bulut'un en sevdigi oyundur. Hemen oynamaya baslarlar.\n";
	
	cout << "\nOyunu baslatmak icin herhangi bir tusa basin...\n";
    {
        string a; 
        cin >> a;
    }
	int aa = oyunn();
	while(aa < 2){
		aa = oyunn();
	}
	cout << "Oyunu cok basarili bir sekilde cabucak bitirir. Oyunu bitirdigi an tetrisin arka kapagi duser. Bozuldugu icin cok uzulurler fakat uzulmeye vakit kalmadan boncuk kapagin dustugu yerde yazan sifreyi gorur.\n"
	<< "Bu sifrenin ne ise yarayacagini dusunurler ve onemli bir sey oldugunu tahmin ederek unutmamak icin cantasindan kalem cikarip koluna sifreyi yazar.\n"
	<< "Bulut bu sifreyi girebilecek herhangi bir yer arar. Kucuk kitapliga bakarken kitaplarin arka kisminda bir bosluk oldugunu fark eder.\n"
	<< "Kitaplari kenara koyup tekrar baktiginda burada bir kasa oldugunu gorur ve tam da aradiklari gibi bu kasanin sifreyi girecek bir kismi vardir."
	<< "Kolundan okudugu sifreyi kasaya girer ve kasa acilir. Kasanin icinden kiyafetinde Saturn simgesi olan bir oyuncak ayi cikar.\n"
	<< "Cok sevinmislerdir simgeyi bulduklari icin. Simdi sirada diger oda vardir. Gecit acilir...";
	return aa;
}

#endif