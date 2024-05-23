#include <iostream>
#include <vector>
#include <unordered_set>
#include <ctime>
#include <algorithm>
#include <random>
#include <iterator>
#include <utility>
#include <functional>
#include <map>
#include "snake_game/snake.h"
#include "math_room/math.h"
#include "tictactoe_game/tictactoe.h"
#include "tetris_game/tetris.h"
#include "blackjack_game/blackjack.h"
#include "maze_game/maze.h"
#include "word_game/word.h"
#include "desert_game/desert.h"
#include "espri_room/espri.h"
#include "laboratory_room/lab.h"
#include "kitchen_room/kitchen.h"
#include "funfair_room/funfair.h"
#include "hippodrome_room/hippodrome.h"
#include "island_room/island.h"
#include "database/database.h"
#include "costume_room/costume.h"
#include "graveyard_room/graveyard.h"
#include "lake_room/lake.h"
#include "parking_room/parking.h"
#include "quarry_room/quarry.h"
#include "horror_room/horror.h"
#include "sarmasik_room/sarmasik.h"
#include "wasp_room/wasp.h"
#include "forest_room/forest.h"
#include "mountain_room/mountain.h"
#include "gravity_room/gravity.h"


using namespace std;
using json = nlohmann::json;

// Tetris Oyunu Baslatma - Kaybetmeden once kac line patlattiysa o sayiyi donuyor.
int preStartTetrisGame(){
    auto returnvalue = startTetrisGame();
    return returnvalue;
}

// YerCekimsiz Oda bi olayi yok
int preStartTGravityGame(){
    auto returnvalue = startGravityGame();
    return returnvalue;
}

// Buyulu Orman Baslatma - Kaybederse 5 cani azaliyor.
int preStartForestGame(){
    auto returnvalue = startForestGame();
    return returnvalue;
}

// Dag oyunu Baslatma - Hatasayisi donuyor.
int preStartMountainGame(){
    auto returnvalue = startMountainGame();
    return returnvalue;
}

// Ari Kovani Oyunu Baslatma - Eve Zamaninda gidemezse 10 cani azalir.
int preStartWaspGame(){
    auto returnvalue = startWaspGame();
    return returnvalue;
}

// Korku Evi Baslatma - Her yanlis bildigi icin 2 cani gidiyor.
int preStartHorrorGame(){
    auto returnvalue = startHorrorGame();
    return returnvalue;
}

//Sarmasik Odasi Baslatma - Yanlis malzeme seciminde cani 4 gidiyor.
int preStartSarmasikGame(){
    auto returnvalue = startSarmasikGame();
    return returnvalue;
}

// Gol Oyunu Baslatma - Hata sayisi doner
int preStartLakeGame(){
    auto returnvalue = startLakeGame();
    return returnvalue;
}

// Otopark Oyunu Baslatma - 0 veya 25 doner 25 gecti 0 kaldi
int preStartParkingGame(){
    auto returnvalue = startParkingGame();
    return returnvalue;
}

// Mezarlik Oyunu Baslatma - her turlu gecer
int preStartGraveyardGame(){
    auto returnvalue = startGraveyardGame();
    return returnvalue;
}

// Kostum Oyunu Baslatma - Hata sayisi doner
int preStartCostumeGame(){
    auto returnvalue = startCostumeGame();
    return returnvalue;
}

// Ada Oyunu Baslatma - Hata sayisi doner
int preStartIslandGame(){
    auto returnvalue = startIslandGame();
    return returnvalue;
}

// Mutfak Odasi Oyunu Baslatma - Hata sayisi donuyor
int preStartKitchenGame(){
    auto returnvalue = startKitchenGame();
    return returnvalue;
}

// Lunapark Odasi Oyunu Baslatma - Hata sayisi donuyor
int preStartFunfairGame(){
    auto returnvalue = startFunfairGame();
    return returnvalue;
}

// Hipodrom Odasi Oyunu Baslatma - Hata sayisi donuyor
int preStartHippodromeGame(){
    auto returnvalue = startHippodromeGame();
    return returnvalue;
}

// Espri Oyunu Baslatma - Kac hata yaptiysa onu doner
int preStartEspriGame(){
    auto returnvalue = startEspriGame();
    return returnvalue;
}

// Laboratuvar Oyunu Baslatma - Cikacaksa 25, kaybettiyse 0 doner
int preStartLaboratoryGame(){
    auto returnvalue = startLaboratoryGame();
    return returnvalue;
}

// Desert Oyunu Baslatma - Kac hata yaptiysa onu doner
int preStartDesertGame(){
    auto returnvalue = startDesertGame();
    return returnvalue;
}

// Maze Oyunu Baslatma - 25 donuyor.
int preStartMazeGame(){
    auto returnvalue = startMazeGame();
    return returnvalue;
}

// Word Oyunu Baslatma - Kac kez hata yaptiysa onu donuyor ve 25 donuyor.
int preStartWordGame(){
    auto returnvalue = startWordGame();
    return returnvalue;
}

// Blackjack Oyunu Baslatma - Oyuncu kazanirsa 25 kaybederse 0 berabere 13 donuyor
int preStartBlackjackGame(){
    auto returnvalue = startBlackjackGame();
    return returnvalue;
}

// TripleX Oyunu Baslatma - Hata sayisini int olarak donuyor.
int preStartMathGame(){
    auto returnvalue = startMathGame();
    return returnvalue;
}

// Snake Oyunu Baslatma - Hatasayisi donuyor. 100+ skor yapamazsa +1 hata
int preStartSnakeGame(){
    auto returnvalue = startSnakeGame();
    return returnvalue;
}

// Maden Oyunu Baslatma - Hatasayisi donuyor.
int preStartQuarryGame(){
    auto returnvalue = startQuarryGame();
    return returnvalue;
}

// Tictactoe Oyunu Baslatma - Hata sayisini doner
int preStartTictactoeGame(){
    auto returnvalue = startTictactoeGame();
    return returnvalue;
}

const int MAP_ROWS = 7;
const int MAP_COLS = 9;

class Item {
    private:
        string name;
        string type;
    public:
        
        virtual ~Item() {} // Sanal bir yikici ekleyerek Item sinifini polimorfik hale getiriyoruz
        virtual bool isEdible() const { return false; } // Sanal bir fonksiyon ekliyoruz

        string getItemName()const{return name;}

        json to_json() {
            // ornek bir Item sinifina sahip olmadigimiz icin burada varsayilan degerler kullaniyoruz.
            return json{{"name", this->getItemName()}, {"type", this->getItemType()}};
        }

        void from_json(json j) {
            j.at("name").get_to(this->name);
            j.at("type").get_to(this->type);
        }

        Item(string itemName, string itemType) : name(itemName), type(itemType) {}
        Item() {}

        string getItemType() const {return type;}
};

// Items
Item kalem = Item("Kalem","None"); Item harita = Item("Harita","None"); Item kamera = Item("Kamera","None"); Item araba = Item("Araba","None");
Item kitap = Item("Kitap","None"); Item cuzdan = Item("Cuzdan","None"); Item ayakkabi = Item("Ayakkabi","None"); Item balta = Item("Balta","None");
Item telefon = Item("Telefon","None"); Item sandalye = Item("Sandalye","None"); Item gozluk = Item("Gozluk","None"); Item sapka = Item("Sapka","None"); 
Item anahtarlik = Item("Anahtarlik","None"); Item masa = Item("Masa","None"); Item cakmak = Item("Cakmak","None"); Item tabak = Item("Tabak","None");
Item bardak = Item("Bardak","None"); Item bilgisayar = Item("Bilgisayar","None"); Item fare = Item("Fare","None"); Item havlu = Item("Havlu","None");
Item canta = Item("Canta","None"); Item catal = Item("Catal","None"); Item saat = Item("Saat","None"); Item tavuk = Item("Tavuk","None"); Item oyuncak=Item("Gemi maketi","None");
Item buyulu_kilic = Item("Buyulu Kilic","None"); Item ayi=Item("Oyuncak ayi","None"); Item bebek=Item("Oyuncak Bebek","None"); Item kilit=Item("Asma Kilit","None");
Item orman = Item("Meyve","None"); Item orman1=Item("Tahta Kalem","None"); Item kagit=Item("Kagit","None"); Item maden=Item("Kazma","True"); Item maden2=Item("Fener","None");
Item sikke=Item("Sikke","None"); Item kostek=Item("Kostekli Saat","None"); Item matara=Item("Matara","None"); Item inci=Item("Inci","None"); Item hipo=Item("At Nali","None"); 
Item kostum=Item("Maske","None"); Item mezarlik=Item("Kuru Kafa","None"); Item yer=Item("Cali Meyvesi","None"); Item yer1=Item("Anahtar","None"); Item yer2=Item("Makas","None");
Item hayvan=Item("Kleopatra Yumurtasi","None"); Item mutfak=Item("Sef Sapkasi","None"); Item lunapark=Item("Tarot Karti","None"); Item mafya=Item("Yuzuk","None"); Item dag=Item("Tas","None");
Item mat=Item("Yapboz Parcasi","None"); Item oyun=Item("Mendil","None"); Item gazino=Item("Kart","None"); Item sarmasik=Item("Yuzuk","None");

// EdibleItem sinifi
class EdibleItem : public Item, public Entity {
private:
    int healthValue;
public:
    EdibleItem(string itemName,string itemType, int hv) : Item(itemName, itemType), healthValue(hv) {}

    bool isEdible() const override { return true; }
    int getHealthValue() const { return healthValue; }

    // JSON serilestirme fonksiyonu
    json to_json() override {
        return json{{"name", getItemName()}, {"type", getItemType()}, {"healthValue", healthValue}};
    }

    // JSON deserializasyon fonksiyonu
    void from_json(json j) override {
        Item::from_json(j); // ust sinifin from_json fonksiyonunu cagir
        j.at("healthValue").get_to(healthValue);
    }
};

// Edible Items
EdibleItem apple("Apple","Edible", 20);

// CraftableItem sinifi
class CraftableItem : public Item, public Entity {
public:
    CraftableItem(string itemName, string itemType) : Item(itemName, itemType) {}

    // JSON serilestirme fonksiyonu
    json to_json() override {
        return json{{"name", getItemName()}, {"type", getItemType()}};
    }

    // JSON deserializasyon fonksiyonu
    void from_json(json j) override {
        Item::from_json(j); // ust sinifin from_json fonksiyonunu cagir
    }
};

// Craftable Items
CraftableItem balta_sapi = CraftableItem("Balta Sapi","Craftable");
CraftableItem cubuk = CraftableItem("Cubuk","Craftable");
CraftableItem kilic = CraftableItem("Kilic","Craftable");
CraftableItem buyu = CraftableItem("Buyu Kitabi","Craftable");

class Room {
private:
    int ID;
    string welcomeMsg;
    mutable vector<std::pair<Item,bool>> items; // mutable olarak degistirilebilir hale getirildi
    string question;
    string answer;
    string preGameFunctionName; // İslevin adini saklayan bir degisken
    
    static int nextID;

    static int getNextID() {
        return ++nextID;  
    }

public:

    function<int()> preGameFunction; // onceden belirlenmis bir oyun baslatma fonksiyonu

    Room() {
        ID = getNextID();
        welcomeMsg = "Welcome to the room!";
        question = "What would you like to do?";
        answer = "";
        preGameFunction = NULL;
        preGameFunctionName = "Yok";
    }

    Room(int a, const string& msg, const vector<std::pair<Item,bool>>& itemList, const string& questionText, const string& answerText, function<int()> preGameFunc, string funcName) {
        ID = a;
        welcomeMsg = msg;
        items = itemList;
        question = questionText;
        answer = answerText;
        preGameFunction = preGameFunc;
        preGameFunctionName = funcName;
    }

    string getPreGameFunctionName() const { return preGameFunctionName; }
    void setPreGameFunctionName(const string& functionName) { preGameFunctionName = functionName; }

    int executePreGameFunction() {
        int control = 0;
        if (preGameFunction != nullptr) {
            control = preGameFunction();
        }
        return control;
    }

    int getID() { return ID; }
    void setID(int id) { ID = id; }

    string getAnswer() const { return answer; }
    void setAnswer(const string& ans) { answer = ans; }

    std::string getWelcomeMsg() const { return welcomeMsg; }
    void setWelcomeMsg(const std::string& msg) { welcomeMsg = msg; }

    const vector<std::pair<Item,bool>>& getItems() const { return items; }
    vector<std::pair<Item,bool>>& getMutableItems() { return items; } // Esyalarin degistirilebilir bir referansini dondur

    std::string getQuestion() const { return question; }
    void setQuestion(const std::string& questionText) { question = questionText; }

    void addItem(const Item& newItem) {items.emplace_back(newItem, true);}
};

int Room::nextID = 0;

bool isCoordinateInVector(const vector<pair<int, int>>& coordinates, pair<int, int> target) {
    for (const auto& coord : coordinates) {
        if (coord == target) {
            return true;  // Hedef koordinat vektorde bulundu
        }
    }
    return false;  // Hedef koordinat vektorde bulunamadi
}

class Character : public Entity{
private:
    string name;
    int health;
    vector<Item*> inventory;

public:
    Character(string charName, int charHealth) : name(charName), health(charHealth) {}

    string getFileName() override{
        return "character.json";
    } 

    void from_json(json j) override {
        j.at("health").get_to(health);
        json inventoryJson = j.at("inventory");

        inventory.clear();

        for (const auto& itemJson : inventoryJson) {
            string itemType = itemJson.at("type").get<string>();
            Item* item = nullptr;

            // Esya turune gore uygun alt sinifi olustur
            if (itemType == "Craftable") {
                item = new CraftableItem("", "Craftable");
            } else if (itemType == "Edible") {
                item = new EdibleItem("","Edible", 0);
            } else if(itemType == "None"){
                item = new Item();
            } else if(itemType == "Requirement"){
                item = new Item();
            }
            // Esya turu eklemek istedigimizde buraya ekle

            // JSON'dan Item'e donusturme islemi
            if (item) {
                item->from_json(itemJson);
                inventory.push_back(item);
            }
        }
    }

    json to_json() override {
        json inventoryJson;
        for (const auto& item : inventory) {
            inventoryJson.push_back(item->to_json());
        }
        return json{{"health", health}, {"inventory", inventoryJson}};
    }

    string getName() const { return name; }
    int getHealth() const { return health; }
    void setHealth(int newHealth) { health = newHealth; }

    vector<Item*>& getInventory(){return inventory;}

    void addItemToInventory(Item& newItem) {inventory.push_back(&newItem);}

    int getInventorySize() const {
        return inventory.size();
    }

    int checkIfItemInInventory(){
        int a = 0;
        const vector<Item*>& inventory = getInventory();
        const vector<string>& itemsToCheck = {"Oyuncak Bebek","Meyve","Tahta Kalem","Yuzuk","Maske","Inci","Kostekli Saat","Matara","Kuru Kafa","Kagit","Kleopatra Yumurtasi","Tarot Karti","Gemi maketi","Yapboz Parcasi","Mendil","Cali Meyvesi","Anahtar","Makas","Gozluk","Sef Sapkasi","Tas","Yuzuk","Oyuncak ayi","Kitap","Kazma","Fener","Asma Kilit","Sikke","Kart","At Nali"};

        for (const string& itemName : itemsToCheck) {
            bool found = false;
            for (const Item* item : inventory) {
                if (item->getItemName() == itemName) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                if(a == 0){
                    cout << "\nFinal room ama esyalarin hepsi yok\n";
                    a++;
                }else{}
                return 0; // Esya envanterde bulunamadi
            }
        }
        //cout << "\nEsyalar bulundu\n";
        return 1; // Tum esyalar envanterde bulundu
    }

    void showCharacterInfo() const {
        cout << "Karakter Adi: " << name << endl;
        cout << "Can: " << health << endl;
        cout << "Envanter:" << endl;
        for (const auto& item : inventory) {
            cout << "- " << item->getItemName() << " (" << item->getItemType() << ")" << endl;
        }
    }

    void useItem(Item* item, int id){
        EdibleItem* ead = dynamic_cast<EdibleItem*>(item);
        if (ead != nullptr) {
            cout << ead->getItemName() << " kullaniyorsun...\n";
            setHealth(getHealth() + ead->getHealthValue());
            cout << "Karakterinin cani arttirildi. Guncel can: " << getHealth() << endl;

            // Envanterden kullanilan esyayi cikar
            inventory.erase(inventory.begin() + id);
        } else {
            cout << "Esya envanterde bulunamadi veya yenilebilir bir esya degil!" << endl;
        }
    }
};

class Map : public Entity {
private:
    vector<vector<char>> layout;
    int playerRow, playerCol;
    unordered_set<int> usedRoomIDs;

    vector<pair<int, int>> obstacles = {
        {0, 0},{0, 1},{0, 2},{0, 3},{0, 4},{0, 5},{0, 6},{0, 7},{0, 8},
        {6, 0},{6, 1},{6, 2},{6, 3},{6, 4},{6, 5},{6, 6},{6, 7},{5, 8},
        {1, 0},{2, 0},{3, 0},{4, 0},{1, 8},{2, 8},{3, 8},{4, 8},{6, 8},
        {1, 7},{2, 7},{4, 7},{5, 7},{1, 1},{2, 1},{4, 1},{5, 1},{5, 0},
    };

    vector<pair<int, int>> roomCoordinates = {
        {1, 2},{1, 3},{1, 4},{1, 5},{1, 6},
        {2, 2},{2, 3},{2, 4},{2, 5},{2, 6},
        {3, 2},{3, 3},{3, 4},{3, 5},{3, 6},
        {4, 2},{4, 3},{4, 4},{4, 5},{4, 6},
        {5, 2},{5, 3},{5, 4},{5, 5},{5, 6},
    };

    pair<int,int> finalRoom = {3,7};

    bool isPassable(int row, int col) {
        for (const auto& obstacle : obstacles) {
            if (row == obstacle.first && col == obstacle.second) {
                return false;
            }
        }
        return true;
    }

    bool isRoom(pair<int, int> coordinate) {
        for (const auto& roomCoord : roomCoordinates) {
            if (coordinate == roomCoord) {
                return true;
            }
        }
        return false;
    }

public:
    string getFileName() override{
        return "location.json";
    } 

    json to_json() override {
        json j;

        // Oyuncu konumunu kaydet
        j["playerRow"] = playerRow;
        j["playerCol"] = playerCol;

        return j;
    }

    void rooms_json(){
        // Odalari JSON nesnelerine donusturmek
        json rooms_json;
        for (int i = 0; i < 25; ++i) {
            json room_json;
            room_json["ID"] = rooms[i].getID();
            room_json["welcomeMsg"] = rooms[i].getWelcomeMsg();
            room_json["items"] = json::array();
            for (const auto& item : rooms[i].getItems()) {
                json item_json;
                item_json["name"] = item.first.getItemName();
                item_json["available"] = item.second;
                room_json["items"].push_back(item_json);
            }
            room_json["question"] = rooms[i].getQuestion();
            room_json["answer"] = rooms[i].getAnswer();
            room_json["preGameFunctionName"] = rooms[i].getPreGameFunctionName();
            rooms_json.push_back(room_json);
        }

        // JSON verisini dosyaya yazma
        std::ofstream output_file("roomData.json");
        output_file << std::setw(4) << rooms_json << std::endl;

        std::cout << "Dosya roomData.json'a kaydedildi." << std::endl;
    }

    void deserialize_rooms_json(const json& rooms_json, Room rooms[]) {
        // JSON nesnesinden odalari cikar
        int index = 0;
        for (const auto& room_json : rooms_json) {
            Room temp;
            temp.setID(room_json["ID"]);
            temp.setWelcomeMsg(room_json["welcomeMsg"]);
            for (const auto& item_json : room_json["items"]) {
                std::string name = item_json["name"];
                bool available = item_json["available"];
                // Item ve available bilgileri burada islenir
                if(available == true){
                    if(name == "Kamera"){
                        temp.addItem(kamera);
                    }else if(name == "Harita"){
                        temp.addItem(harita);
                    }else if(name == "Gemi maketi"){
                        temp.addItem(oyuncak);
                    }else if(name == "Kalem"){
                        temp.addItem(kalem);
                    }else if(name == "Araba"){
                        temp.addItem(araba);
                    }else if(name == "Kitap"){
                        temp.addItem(kitap);
                    }else if(name == "Asma Kilit"){
                        temp.addItem(kilit);
                    }else if(name == "Cuzdan"){
                        temp.addItem(cuzdan);
                    }else if(name == "Meyve"){
                        temp.addItem(orman);
                    }else if(name == "Oyuncak Bebek"){
                        temp.addItem(bebek);
                    }else if(name == "Tahta Kalem"){
                        temp.addItem(orman1);
                    }else if(name == "Ayakkabi"){
                        temp.addItem(ayakkabi);
                    }else if(name == "Kagit"){
                        temp.addItem(kagit);
                    }else if(name == "Kazma"){
                        temp.addItem(maden);
                    }else if(name == "Fener"){
                        temp.addItem(maden2);
                    }else if(name == "Sikke"){
                        temp.addItem(sikke);
                    }else if(name == "Kostekli Saat"){
                        temp.addItem(kostek);
                    }else if(name == "Matara"){
                        temp.addItem(matara);
                    }else if(name == "Inci"){
                        temp.addItem(inci);
                    }else if(name == "At Nali"){
                        temp.addItem(hipo);
                    }else if(name == "Maske"){
                        temp.addItem(kostum);
                    }else if(name == "Oyuncak ayi"){
                        temp.addItem(ayi);
                    }else if(name == "Kuru Kafa"){
                        temp.addItem(mezarlik);
                    }else if(name == "Cali Meyvesi"){
                        temp.addItem(yer);
                    }else if(name == "Anahtar"){
                        temp.addItem(yer1);
                    }else if(name == "Makas"){
                        temp.addItem(yer2);
                    }else if(name == "Balta"){
                        temp.addItem(balta);
                    }else if(name == "Telefon"){
                        temp.addItem(telefon);
                    }else if(name == "Sandalye"){
                        temp.addItem(sandalye);
                    }else if(name == "Gozluk"){
                        temp.addItem(gozluk);
                    }else if(name == "Sapka"){
                        temp.addItem(sapka);
                    }else if(name == "Anahtarlik"){
                        temp.addItem(anahtarlik);
                    }else if(name == "Masa"){
                        temp.addItem(masa);
                    }else if(name == "Cakmak"){
                        temp.addItem(cakmak);
                    }else if(name == "Tabak"){
                        temp.addItem(tabak);
                    }else if(name == "Bardak"){
                        temp.addItem(bardak);
                    }else if(name == "Bilgisayar"){
                        temp.addItem(bilgisayar);
                    }else if(name == "Fare"){
                        temp.addItem(fare);
                    }else if(name == "Havlu"){
                        temp.addItem(havlu);
                    }else if(name == "Canta"){
                        temp.addItem(canta);
                    }else if(name == "Catal"){
                        temp.addItem(catal);
                    }else if(name == "Saat"){
                        temp.addItem(saat);
                    }else if(name == "Tavuk"){
                        temp.addItem(tavuk);
                    }else if(name == "Kleopatra Yumurtasi"){
                        temp.addItem(hayvan);
                    }else if(name == "Sef Sapkasi"){
                        temp.addItem(mutfak);
                    }else if(name == "Tarot Karti"){
                        temp.addItem(lunapark);
                    }else if(name == "Yuzuk"){
                        temp.addItem(mafya);
                    }else if(name == "Tas"){
                        temp.addItem(dag);
                    }else if(name == "Yapboz Parcasi"){
                        temp.addItem(mat);
                    }else if(name == "Mendi"){
                        temp.addItem(oyun);
                    }else if(name == "Kart"){
                        temp.addItem(gazino);
                    }else if(name == "Yuzuk"){
                        temp.addItem(sarmasik);
                    }else if(name == "Buyulu Kilic"){
                        temp.addItem(buyulu_kilic);
                    }else if(name == "Apple"){
                        temp.addItem(apple);
                    }else if(name == "Balta Sapi"){
                        temp.addItem(balta_sapi);
                    }else if(name == "Cubuk"){
                        temp.addItem(cubuk);
                    }else if(name == "Kilic"){
                        temp.addItem(kilic);
                    }else if(name == "Buyu Kitabi"){
                        temp.addItem(buyu);
                    }else{}
                }
            }
            temp.setQuestion(room_json["question"]);
            temp.setAnswer(room_json["answer"]);
            temp.setPreGameFunctionName(room_json["preGameFunctionName"]);
            // Fonksiyonu atama
            string functionName = temp.getPreGameFunctionName();
            function<int()> preGameFunction = nullptr;

            if(functionName == "preStartDesertGame"){
                temp.preGameFunction = preStartDesertGame;
            }else if(functionName == "preStartTetrisGame"){
                temp.preGameFunction = preStartTetrisGame;
            }else if(functionName == "preStartTGravityGame"){
                temp.preGameFunction = preStartTGravityGame;
            }else if(functionName == "preStartForestGame"){
                temp.preGameFunction = preStartForestGame;
            }else if(functionName == "preStartWaspGame"){
                temp.preGameFunction = preStartWaspGame;
            }else if(functionName == "preStartMountainGame"){
                temp.preGameFunction = preStartMountainGame;
            }else if(functionName == "preStartHorrorGame"){
                temp.preGameFunction = preStartHorrorGame;
            }else if(functionName == "preStartSarmasikGame"){
                temp.preGameFunction = preStartSarmasikGame;
            }else if(functionName == "preStartGraveyardGame"){
                temp.preGameFunction = preStartGraveyardGame;
            }else if(functionName == "preStartCostumeGame"){
                temp.preGameFunction = preStartCostumeGame;
            }else if(functionName == "preStartIslandGame"){
                temp.preGameFunction = preStartIslandGame;
            }else if(functionName == "preStartKitchenGame"){
                temp.preGameFunction = preStartKitchenGame;
            }else if(functionName == "preStartHippodromeGame"){
                temp.preGameFunction = preStartHippodromeGame;
            }else if(functionName == "preStartEspriGame"){
                temp.preGameFunction = preStartEspriGame;
            }else if(functionName == "preStartFunfairGame"){
                temp.preGameFunction = preStartFunfairGame;
            }else if(functionName == "preStartLaboratoryGame"){
                temp.preGameFunction = preStartLaboratoryGame;
            }else if(functionName == "preStartMazeGame"){
                temp.preGameFunction = preStartMazeGame;
            }else if(functionName == "preStartWordGame"){
                temp.preGameFunction = preStartWordGame;
            }else if(functionName == "preStartBlackjackGame"){
                temp.preGameFunction = preStartBlackjackGame;
            }else if(functionName == "preStartMathGame"){
                temp.preGameFunction = preStartMathGame;
            }else if(functionName == "preStartQuarryGame"){
                temp.preGameFunction = preStartQuarryGame;
            }else if(functionName == "preStartSnakeGame"){
                temp.preGameFunction = preStartSnakeGame;
            }else if(functionName == "preStartTictactoeGame"){
                temp.preGameFunction = preStartTictactoeGame;
            }else if(functionName == "preStartLakeGame"){
                temp.preGameFunction = preStartLakeGame;
            }else if(functionName == "preStartParkingGame"){
                temp.preGameFunction = preStartParkingGame;
            }else{
                temp.preGameFunction = NULL;
            }

            rooms[index++] = temp;
        }
    }

    void load_rooms_back(){
        // JSON dosyasini okuma
        std::ifstream input_file("roomData.json");
        json rooms_json;
        input_file >> rooms_json;

        // Odalari yerlestirme
        deserialize_rooms_json(rooms_json, rooms);

    }

    void from_json(json j) override {
        j.at("playerRow").get_to(playerRow);
        j.at("playerCol").get_to(playerCol);
        if(getCurrentLocation() != make_pair(3,1)){
            layout[playerRow][playerCol] = 'P'; // Oyuncu pozisyonu
            layout[3][1] = '-'; // Oyuncu pozisyonu
        }
    }

    // Rooms
    Room rooms[25] = {
        {1, "Korku Evi", {{bebek,true}} , "1-0 ?", "1", preStartHorrorGame , "preStartHorrorGame"},// // //
        {2, "Buyulu Orman", {{orman,true},{orman1, true}}, "", "", preStartForestGame, "preStartForestGame"},// // //
        {3, "Possible Maskeli Balo", {{kostum,true}}, "", "", preStartCostumeGame, "preStartCostumeGame"},// // //
        {4, "Gol", {{inci,true}}, "", "", preStartLakeGame, "preStartLakeGame"},// // //
        {5, "Teleporttan dustugu anda kendini simsicak issiz bir colun ortasinda bulur.", {{kostek,true},{matara, true}}, "", "", preStartDesertGame, "preStartDesertGame"},// // //
        {6, "Mezarlik", {{mezarlik,true}}, "", "", preStartGraveyardGame, "preStartGraveyardGame"},// // //
        {7, "Labirent", {{kagit,true}}, "", "", preStartMazeGame , "preStartMazeGame"},// // //
        {8, "Hayvanat Bahcesi", {{hayvan,true}}, "Duvarda ne yaziyor ?", "Berhan", preStartSnakeGame, "preStartSnakeGame"},// // //
        {9, "Lunapark", {{lunapark,true}}, "", "", preStartFunfairGame, "preStartFunfairGame"},// // //
        {10, "Ada", {{oyuncak,true}}, "", "", preStartIslandGame, "preStartIslandGame"},// // //
        {11, "Matematik Odasi", {{mat,true}}, "", "",preStartMathGame, "preStartMathGame"},// // //
        {12, "Sarmasikli Oda", {{sarmasik,true}}, "", "", preStartSarmasikGame, "preStartSarmasikGame"},// // //
        {13, "Oyun Odasi", {{oyun, true}}, "", "", preStartTictactoeGame, "preStartTictactoeGame"},// // //
        {14, "Yercekimsiz Oda", {{yer,true},{yer1, true},{yer2, true}}, "", "", preStartTGravityGame, "preStartTGravityGame"},// // //
        {15, "Espri Odasi", {{gozluk,true}}, "", "", preStartEspriGame, "preStartEspriGame"},// // //
        {16, "Mutfak", {{mutfak,true}}, "", "", preStartKitchenGame, "preStartKitchenGame"},// // //
        {17, "Volkanik Dag", {{dag,true}}, "", "", preStartMountainGame, "preStartMountainGame"},// // //
        {18, "Otopark", {{mafya,true}}, "", "", preStartParkingGame, "preStartParkingGame"},// // //
        {19, "Agac Ev", {{ayi,true}}, "", "", preStartTetrisGame, "preStartTetrisGame"},// // //
        {20, "Kelime Odasi", {{kitap,true}}, "", "", preStartWordGame, "preStartWordGame"},// // //
        {21, "Maden Ocagi", {{maden,true},{maden2, true}}, "", "", preStartQuarryGame, "preStartQuarryGame"},// // //
        {22, "Ari Kovani", {{kilit,true}}, "", "", preStartWaspGame, "preStartWaspGame"},// // //
        {23, "Bulut ve Boncuk kendilerini kocaman bir okulun koridorunda bulurlar.", {{sikke,true}}, "", "", preStartLaboratoryGame, "preStartLaboratoryGame"},// // //
        {24, "Gazino", {{gazino,true}}, "", "", preStartBlackjackGame, "preStartBlackjackGame"},// // //
        {25, "Hipodrom", {{hipo,true}}, "", "", preStartHippodromeGame, "preStartHippodromeGame"}// // //
    };

    void roomTransformation() {
        srand(static_cast<unsigned int>(time(nullptr)));
        for (int i = 0; i <25; i++){
            int rIndex=rand() % 25;
            Room temp=rooms[i];
            rooms[i]=rooms[rIndex];
            rooms[rIndex]=temp;   
        }   
    }

    Map() {
        // Haritayi baslangic degerleriyle olustur
        layout = vector<vector<char>>(MAP_ROWS, vector<char>(MAP_COLS, '-'));

        // Engellerin konumlarini haritada "X" olarak isaretle
        for (const auto& obstacle : obstacles) {
            layout[obstacle.first][obstacle.second] = '#';
        }

        // Oyuncuyu ilk odada baslat
        playerRow = 3;
        playerCol = 1;
        layout[playerRow][playerCol] = 'P'; // Oyuncu pozisyonu

        // Odalari rastgele olarak haritaya yerlestir
        placeRoomsRandomly();
    }

    void placeRoomsRandomly() {
        srand(time(0));
        shuffle(roomCoordinates.begin(), roomCoordinates.end(), std::default_random_engine());

        for (int i = 0; i < roomCoordinates.size(); ++i) {
            int roomIndex = rand() % 25;
            while (usedRoomIDs.count(roomIndex + 1) > 0) {
                roomIndex = rand() % 25;
            }
            usedRoomIDs.insert(roomIndex + 1);

            int row = roomCoordinates[i].first;
            int col = roomCoordinates[i].second;
            layout[row][col] = '-';
        }
    }

    void printMap() {
        cout << "Harita Durumu:" << endl;
        for (int i = 0; i < MAP_ROWS; ++i) {
            for (int j = 0; j < MAP_COLS; ++j) {
                cout << layout[i][j];
            }
            cout << endl;
        }
    }

    int checkEndRoom(pair<int, int> nextPos, Character bulut) {
        int sayi = 0;
        int control = 5;
        if (nextPos == finalRoom) {
            sayi = 1;
            control = bulut.checkIfItemInInventory();
        }
        if(sayi == 1){
            if(control == 1){
                cout<<"cikis odasi olan bu odaya geldiklerinde butun tilsimli esyalari alip basarili bir sekilde zorlu gorevleri tamamlamislardir. Zaman zaman ac kalmislardir , bazen oyundan\ncikamayacaklarini dusunup umutsuzluga kapilmislardir . cogu zaman bir kedinin ve cocugun bu yasta yapmayacaklari seyleri "
               "yapmak zorunda kalmislardir fakat en sonunda ikisi\nbirlik olup butun zorluklari atlatmislardir. Bu odaya gelmek onlari bir hayli heyecanlandirmaktadir. cunku en sonunda o cok ozledikleri ailesine kavusmak uzerelerdir. cantalari,aldiklari esyalar ile iyice dolmus ve agirlasmistir. Bir an once esyalari"
               "kasaya koyup basarili bir sekilde evlerine donmek istemektelerdir. Bu geldikleri son odada iceride\nsadece kocaman bir kasa vardir. cikis kapisina benzer bir sey olmayisi onlari oldukca tedirgin etmistir. onceki bolumler gibi bir gecit cikacagini umarlar ve cantasinda olan\nesyalardan tilsimli olanlari" 
               "cikartirlar , tek tek kasanin icine koyarlar. Artik tek yapmalari gereken sey kapagi acik olan bu kasanin kapagini kapatip tam tur cevirmeleridir.\ncevirdiklerinde buyuk bir sesle yana dogru kayan kasanin arkasindan nerede oldugunu bulamadiklari cikis kapisi gorunur. Buradan gecerek bir anda ilk basta" 
               "olan bembeyaz, sesin\nkonustugu odaya gelmislerdir. Bu ses tekrardan konusmaya baslar ve bu sefer guzel seyler soyluyordur. Bu odaya sorunsuz bir sekilde gelip artik cikisa ulasmaya bir adim\nkaldigini soyler. Bu cok mutlu edici bir haberdir. Oyuncaklarini kaybeden kizin Bulut ve Boncuk'a tesekkurlerini" 
               "iletir. Soracaklari bir sey var mi diye sorar . Fakat artik\nkonusulacak bir sey kalmamistir. Sesin ilk basta oldugu gibi bu bembeyaz olan odadan cikmalari icin butona basmalari gerektigini soyler ve karsilarina cikan butona basarak oyunu\ntamamlamis olarak geldikleri ilk bastaki agacin oraya isinlanirlar."
               "Butun zorluklar bitmistir. Artik evlerine gidebilirlerdir. Bulut ve Boncuk cok guzel bir takim olmuslardir ve asla bir daha ayrilmak istemezler . Bulut eve gidip her seyi ailesine anlatinca annesi kedilerin cocuguna yaptigi fedakarligin ve gosterilen sefkatin karsiliginda onlar\nevlerinin bahcelerinde cok" 
               "guzel bir yuva yaparlar .Boncuk ve ailesi burada yasayarak hep birlikte bir aile olurlar."<<endl;
                exit(0);
                return 2;
            }else if(control == 0){
                cout << "Butun Esyalari Getirmeden Evine Donemezsin!!!!!!\n";
                return 1;
            }
        }
        return 0; // finalRoom'a ulasilmadi
    }

    pair <int,int> getCurrentLocation(){
        pair <int,int> loc = {playerRow,playerCol};
        return loc;
    }

    void movePlayer(char direction, Character& character) { // , pair<int, int> currentRoomCoordinate
    // Gecici olarak oyuncunun konumunu sakla
    
        int tempRow = playerRow;
        int tempCol = playerCol;
        int control = 0, control2 = 0, can = 0;

        // Yeni konumu hesapla
        int newRow = playerRow;
        int newCol = playerCol;

        switch (direction) {
            case 'W': newRow = max(0, playerRow - 1); break;
            case 'S': newRow = min(MAP_ROWS - 1, playerRow + 1); break;
            case 'A': newCol = max(0, playerCol - 1); break;
            case 'D': newCol = min(MAP_COLS - 1, playerCol + 1); break;
            default: cout << "Yanlis secim!" << endl; return;
        }

        // Yeni konum gecilebilir mi kontrol et
        if (isPassable(newRow, newCol)) {
            pair<int, int> currentPos = { playerRow, playerCol };
            pair<int, int> nextPos = { newRow, newCol };

            // Eger yeni konum bir oda ise ve bu odanin koordinati kullanicinin bulundugu oda ile ayni ise
            if (isRoom(currentPos)) {
                // Oda indeksini al
                int roomIndex = -1;
                for (int i = 0; i < roomCoordinates.size(); ++i) {
                    if (currentPos == roomCoordinates[i]) {
                        roomIndex = i;
                        break;
                    }
                }

                // Oda bulundu ise
                if (roomIndex != -1) {
                    // Oda nesnesine eris
                    const Room& currentRoom = rooms[roomIndex];

                    if(currentRoom.preGameFunction != nullptr){
                        control = rooms[roomIndex].executePreGameFunction(); // Duruma gore hata sayisi veya 25 - 0 donduruyor.
                        if(rooms[roomIndex].getPreGameFunctionName() == "preStartBlackjackGame"){
                            if(control == 0){
                                cout << "Kaybettin, hareket iptal edildi ve 5 canini kaybettin.\n";
                                control2 = 25;
                                character.setHealth(character.getHealth() - 5);
                            }else if(control == 13){
                                cout << "Berabere!, bir kere daha oynamalisin" << endl;
                                control2 = 99;
                            }else{
                                cout << "Kazandin!" << endl;
                                if(checkEndRoom(nextPos,character) == 2){ // final odasi kontrolu
                                }else if(checkEndRoom(nextPos,character) == 1){
                                    control2 = 10;
                                }else{}
                            }
                        }else if(rooms[roomIndex].getPreGameFunctionName() == "preStartTetrisGame"){
                            if(control < 2){
                                cout << "Kaybettin, hareket iptal edildi ve 10 canini kaybettin.\n";
                                control2 = 25;
                                character.setHealth(character.getHealth() - 10);
                            }else{
                                cout << "Kazandin!";
                                if(checkEndRoom(nextPos,character) == 2){ // final odasi kontrolu
                                }else if(checkEndRoom(nextPos,character) == 1){
                                    control2 = 10;
                                }else{}
                            }
                        }else if(rooms[roomIndex].getPreGameFunctionName() == "preStartParkingGame"){
                            if(control == 0){
                                cout << "Kaybettin, hareket iptal edildi ve 5 canini kaybettin.";
                                control2 = 25;
                                character.setHealth(character.getHealth() - 5);
                            }else{
                                cout << "Kazandin!";
                                if(checkEndRoom(nextPos,character) == 2){ // final odasi kontrolu
                                }else if(checkEndRoom(nextPos,character) == 1){
                                    control2 = 10;
                                }else{}
                            }
                        }else if(rooms[roomIndex].getPreGameFunctionName() == "preStartMathGame"){
                            if(control == 0){
                                cout << "Hatasiz kazandin!! Tebrikler..." << endl;
                            }else{
                                cout << "Kazandin ama" << control*5 <<" canini " << control << " hatandan dolayi kaybettin" << endl;
                                character.setHealth(character.getHealth() - control*5);
                            }
                            if(checkEndRoom(nextPos,character) == 2){ // final odasi kontrolu
                            }else if(checkEndRoom(nextPos,character) == 1){
                                control2 = 10;
                            }else{}
                        }else if(rooms[roomIndex].getPreGameFunctionName() == "preStartGravityGame"){
                            if(control == 0){
                                cout << "Hatasiz kazandin!! Tebrikler..." << endl;
                            }else{
                                cout << "Kazandin ama" << control*5 <<" canini " << control << " hatandan dolayi kaybettin" << endl;
                                character.setHealth(character.getHealth() - control*5);
                            }
                            if(checkEndRoom(nextPos,character) == 2){ // final odasi kontrolu
                            }else if(checkEndRoom(nextPos,character) == 1){
                                control2 = 10;
                            }else{}
                        }else if(rooms[roomIndex].getPreGameFunctionName() == "preStartQuarryGame"){
                            if(control == 0){
                                cout << "Hatasiz kazandin!! Tebrikler......" << endl;
                            }else{
                                cout << "Kazandin ama" << control*10 <<" canini " << control << " hatandan dolayi kaybettin" << endl;
                                character.setHealth(character.getHealth() - control*10);
                            }
                            if(checkEndRoom(nextPos,character) == 2){ // final odasi kontrolu
                            }else if(checkEndRoom(nextPos,character) == 1){
                                control2 = 10;
                            }else{}  
                        }else if(rooms[roomIndex].getPreGameFunctionName() == "preStartSarmasikGame"){
                            if(control == 0){
                                cout << "Hatasiz kazandin!! Tebrikler......" << endl;
                            }else{
                                cout << "Kazandin ama" << control*4 <<" canini " << control << " hatandan dolayi kaybettin" << endl;
                                character.setHealth(character.getHealth() - control*4);
                            }
                            if(checkEndRoom(nextPos,character) == 2){ // final odasi kontrolu
                            }else if(checkEndRoom(nextPos,character) == 1){
                                control2 = 10;
                            }else{}  
                        }else if(rooms[roomIndex].getPreGameFunctionName() == "preStartHorrorGame"){
                            if(control == 0){
                                cout << "Hatasiz kazandin!! Tebrikler......" << endl;
                            }else{
                                cout << "Kazandin ama" << control*5 <<" canini " << control << " hatandan dolayi kaybettin" << endl;
                                character.setHealth(character.getHealth() - control*5);
                            }
                            if(checkEndRoom(nextPos,character) == 2){ // final odasi kontrolu
                            }else if(checkEndRoom(nextPos,character) == 1){
                                control2 = 10;
                            }else{}  
                        }else if(rooms[roomIndex].getPreGameFunctionName() == "preStartWaspGame"){
                            if(control == 0){
                                cout << "Hatasiz kazandin!! Tebrikler......" << endl;
                            }else{
                                cout << "Kazandin ama" << control*4 <<" canini " << control << " hatandan dolayi kaybettin" << endl;
                                character.setHealth(character.getHealth() - control*4);
                            }
                            if(checkEndRoom(nextPos,character) == 2){ // final odasi kontrolu
                            }else if(checkEndRoom(nextPos,character) == 1){
                                control2 = 10;
                            }else{}  
                        }else if(rooms[roomIndex].getPreGameFunctionName() == "preStartForestGame"){
                            if(control == 0){
                                cout << "Hatasiz kazandin!! Tebrikler......" << endl;
                            }else{
                                cout << "Kazandin ama" << control*4 <<" canini " << control << " hatandan dolayi kaybettin" << endl;
                                character.setHealth(character.getHealth() - control*4);
                            }
                            if(checkEndRoom(nextPos,character) == 2){ // final odasi kontrolu
                            }else if(checkEndRoom(nextPos,character) == 1){
                                control2 = 10;
                            }else{}  
                        }else if(rooms[roomIndex].getPreGameFunctionName() == "preStartMountainGame"){
                            if(control == 0){
                                cout << "Hatasiz kazandin!! Tebrikler......" << endl;
                            }else{
                                cout << "Kazandin ama" << control*15 <<" canini " << control << " hatandan dolayi kaybettin" << endl;
                                character.setHealth(character.getHealth() - control*15);
                            }
                            if(checkEndRoom(nextPos,character) == 2){ // final odasi kontrolu
                            }else if(checkEndRoom(nextPos,character) == 1){
                                control2 = 10;
                            }else{}  
                        }else if(rooms[roomIndex].getPreGameFunctionName() == "preStartSnakeGame"){
                            if(control == 0){
                                cout << "Kazandin!" << endl;
                            }else{
                                cout << "Kazandin ama " << control*4 << " canini kaybettin" << endl;
                                character.setHealth(character.getHealth() - control*4);
                            }
                            if(checkEndRoom(nextPos,character) == 2){ // final odasi kontrolu
                            }else if(checkEndRoom(nextPos,character) == 1){
                                control2 = 10;
                            }else{}
                        }else if(rooms[roomIndex].getPreGameFunctionName() == "preStartTictactoeGame"){
                            if(control == 0){
                                cout << "Kazandin!" << endl;
                            }else{
                                cout << "Kazandin ama " << control*10 << " canini kaybettin" << endl;
                                character.setHealth(character.getHealth() - control*10);
                            }
                            if(checkEndRoom(nextPos,character) == 2){ // final odasi kontrolu
                            }else if(checkEndRoom(nextPos,character) == 1){
                                control2 = 10;
                            }else{}
                        }else if(rooms[roomIndex].getPreGameFunctionName() == "preStartMazeGame"){
                            cout << "Kazandin!";
                            if(checkEndRoom(nextPos,character) == 2){ // final odasi kontrolu
                            }else if(checkEndRoom(nextPos,character) == 1){
                                control2 = 10;
                            }else{}
                        }else if(rooms[roomIndex].getPreGameFunctionName() == "preStartWordGame"){
                            if(control == 0){
                                cout << "Kazandin!" << endl;
                            }else{
                                cout << "Kazandin ama " << control*6 << " canini kaybettin" << endl;
                                character.setHealth(character.getHealth() - control*6);
                            }
                            if(checkEndRoom(nextPos,character) == 2){ // final odasi kontrolu
                            }else if(checkEndRoom(nextPos,character) == 1){
                                control2 = 10;
                            }else{}
                        }else if(rooms[roomIndex].getPreGameFunctionName() == "preStartLakeGame"){
                            if(control == 0){
                                cout << "Kazandin!" << endl;
                            }else{
                                cout << "Kazandin ama " << control*4 << " canini kaybettin" << endl;
                                character.setHealth(character.getHealth() - control*4);
                            }
                            if(checkEndRoom(nextPos,character) == 2){ // final odasi kontrolu
                            }else if(checkEndRoom(nextPos,character) == 1){
                                control2 = 10;
                            }else{}
                        }else if(rooms[roomIndex].getPreGameFunctionName() == "preStartDesertGame"){
                            if(control == 0){
                                cout << "Kazandin!" << endl;
                            }else{
                                cout << "Kazandin ama " << control*5 << " health" << endl;
                                character.setHealth(character.getHealth() - control*5);
                            }
                            if(checkEndRoom(nextPos,character) == 2){ // final odasi kontrolu
                            }else if(checkEndRoom(nextPos,character) == 1){
                                control2 = 10;
                            }else{}
                        }else if(rooms[roomIndex].getPreGameFunctionName() == "preStartEspriGame"){
                            if(control == 0){
                                cout << "Kazandin!" << endl;
                            }else{
                                cout << "Kazandin ama " << control*4 << " canini kaybettin" << endl;
                                character.setHealth(character.getHealth() - control*4);
                            }
                            if(checkEndRoom(nextPos,character) == 2){ // final odasi kontrolu
                            }else if(checkEndRoom(nextPos,character) == 1){
                                control2 = 10;
                            }else{}
                        }else if(rooms[roomIndex].getPreGameFunctionName() == "preStartLaboratoryGame"){
                            if(control == 25){
                                cout << "Kazandin!";
                                if(checkEndRoom(nextPos,character) == 2){ // final odasi kontrolu
                                }else if(checkEndRoom(nextPos,character) == 1){
                                    control2 = 10;
                                }else{}
                            }else{
                                cout << "Kaybettin. Kaybettigin icin 5 canin azaltildi.\n";
                                character.setHealth(character.getHealth() - 5);
                                control2 = 25;
                            }
                        }else if(rooms[roomIndex].getPreGameFunctionName() == "preStartKitchenGame"){
                            if(control == 0){
                                cout << "Kazandin!" << endl;
                            }else{
                                cout << "Kazandin ama " << control*5 << " canini kaybettin" << endl;
                                character.setHealth(character.getHealth() - control*5);
                            }
                            if(checkEndRoom(nextPos,character) == 2){ // final odasi kontrolu
                            }else if(checkEndRoom(nextPos,character) == 1){
                                control2 = 10;
                            }else{}
                        }else if(rooms[roomIndex].getPreGameFunctionName() == "preStartIslandGame"){
                            if(control == 0){
                                cout << "Kazandin!" << endl;
                            }else{
                                cout << "Kazandin ama " << control*5 << " canini kaybettin" << endl;
                                character.setHealth(character.getHealth() - control*5);
                            }
                            if(checkEndRoom(nextPos,character) == 2){ // final odasi kontrolu
                            }else if(checkEndRoom(nextPos,character) == 1){
                                control2 = 10;
                            }else{}
                        }else if(rooms[roomIndex].getPreGameFunctionName() == "preStartFunfairGame"){
                            if(control == 0){
                                cout << "Kazandin!" << endl;
                            }else{
                                cout << "Kazandin ama " << control*10 << " canini kaybettin" << endl;
                                character.setHealth(character.getHealth() - control*10);
                            }
                            if(checkEndRoom(nextPos,character) == 2){ // final odasi kontrolu
                            }else if(checkEndRoom(nextPos,character) == 1){
                                control2 = 10;
                            }else{}
                        }else if(rooms[roomIndex].getPreGameFunctionName() == "preStartCostumeGame"){
                            if(control == 0){
                                cout << "Kazandin!" << endl;
                            }else{
                                cout << "Kazandin ama " << control*5 << " canini kaybettin" << endl;
                                character.setHealth(character.getHealth() - control*5);
                            }
                            if(checkEndRoom(nextPos,character) == 2){ // final odasi kontrolu
                            }else if(checkEndRoom(nextPos,character) == 1){
                                control2 = 10;
                            }else{}
                        }else if(rooms[roomIndex].getPreGameFunctionName() == "preStartHippodromeGame"){
                            if(control == 0){
                                cout << "Kazandin!" << endl;
                            }else{
                                cout << "Kazandin ama " << control*4 << " canini kaybettin" << endl;
                                character.setHealth(character.getHealth() - control*4);
                            }
                            if(checkEndRoom(nextPos,character) == 2){ // final odasi kontrolu
                            }else if(checkEndRoom(nextPos,character) == 1){
                                control2 = 10;
                            }else{}
                        }else if(rooms[roomIndex].getPreGameFunctionName() == "preStartGraveyardGame"){
                            cout << "Kazandin!";
                            if(checkEndRoom(nextPos,character) == 2){ // final odasi kontrolu
                            }else if(checkEndRoom(nextPos,character) == 1){
                                control2 = 10;
                            }else{}
                        }else{
                            cout << "UNUTULMUS BIR YER VAR!! HABERLESELIM\n\n";
                        }
                    }else{
                        // Oda cikis sorusunu sor
                        cout << "Odadan cikis sorusu: " << currentRoom.getQuestion() << endl;

                        // Kullanicidan cevabi al
                        string userAnswer;
                        cout << "Cevap: ";
                        cin >> userAnswer;

                        // Dogru cevabi kontrol et
                        if (userAnswer == currentRoom.getAnswer()) {
                            //cout << "Correct answer! Proceeding..." << endl;
                            if(checkEndRoom(nextPos,character) == 2){ // final odasi kontrolu
                            }else if(checkEndRoom(nextPos,character) == 1){
                                control2 = 10;
                            }else{}
                        } else {
                            cout << "Yanlis cevap! Hareket iptal edildi." << endl;
                            // Gecisi iptal et
                            layout[playerRow][playerCol] = '-';
                            playerRow = tempRow;
                            playerCol = tempCol;
                            layout[playerRow][playerCol] = 'P';
                            newRow = playerRow;
                            newCol = playerCol;
                            printMap();
                            return;
                        }
                    }
                }
            }
            int roomIndex2 = -1;
                for (int j = 0; j < roomCoordinates.size(); ++j) {
                    if (nextPos == roomCoordinates[j]) {
                        roomIndex2 = j;
                        break;
                    }
                }
            if(control2 == 0){
                layout[playerRow][playerCol] = '-'; // Eski konumu bosalt
                playerRow = newRow;
                playerCol = newCol;
                layout[playerRow][playerCol] = 'P'; // Yeni konumu isaretle
                if(roomIndex2 == -1){
                    //cout << "You moved to a new location." << endl;
                }else{
                    cout << rooms[roomIndex2].getWelcomeMsg() << "\n";
                }
                printMap();
            }else if(control2 == 25){
                cout << "\nOyunda basarisiz oldugundan dolayi gecemezsin\n";
                printMap();
                newRow = playerRow;
                newCol = playerCol;
            }else if(control2 = 99){
                printMap();
                newRow = playerRow;
                newCol = playerCol;
            }
        } else {
            cout << "Bu yone dogru gidemezsin!" << endl;
            newRow = playerRow;
            newCol = playerCol;
        }
    }

    bool isThereItem(int roomIndex)const{
        const auto& items = rooms[roomIndex].getItems();
        for (const auto& item: items){
            if(item.second == true)
                return true;
        }
        return false;
    }

    void craftItems(Character& character) {
        cout << "Envanter:" << endl;
        auto& inventory = character.getInventory();
        for (int i = 0; i < inventory.size(); ++i) {
            cout << i + 1 << ". " << inventory[i]->getItemName() << " (" << inventory[i]->getItemType() << ")" << endl;
        }

        int firstChoice, secondChoice;
        cout << "Birlestirmek istedigin iki esyanin numaralarini sec. (Ornegin, '1 2'): ";
        cin >> firstChoice >> secondChoice;

        if (firstChoice < 1 || firstChoice > inventory.size() || secondChoice < 1 || secondChoice > inventory.size()) {
            cout << "Yanlis Secim!" << endl;
            return;
        }

        Item* firstItem = inventory[firstChoice - 1];
        Item* secondItem = inventory[secondChoice - 1];

        // İlk secilen esyanin cubuk, ikincisinin balta_sapi olup olmadigini kontrol et
        if ((firstItem->getItemName() == "Cubuk" && secondItem->getItemName() == "Balta Sapi") || (firstItem->getItemName() == "Balta Sapi" && secondItem->getItemName() == "Cubuk")) {
            cout << "Birlestirme basarili! Balta olusturuldu." << endl;

            // Esyalari envanterden sil
            inventory.erase(inventory.begin() + max(firstChoice, secondChoice) - 1);
            inventory.erase(inventory.begin() + min(firstChoice, secondChoice) - 1);

            // Yeni esyayi envantere ekle
            character.addItemToInventory(balta);
        }else if((firstItem->getItemName() == "Kilic" && secondItem->getItemName() == "Buyu Kitabi") || (firstItem->getItemName() == "Buyu Kitabi" && secondItem->getItemName() == "Kilic")){
            cout << "Birlestirme basarili! Buyulu Kilic olusturuldu." << endl;

            // Esyalari envanterden sil
            inventory.erase(inventory.begin() + max(firstChoice, secondChoice) - 1);
            inventory.erase(inventory.begin() + min(firstChoice, secondChoice) - 1);

            // Yeni esyayi envantere ekle
            character.addItemToInventory(buyulu_kilic);
        } else {
            cout << "Bu esyalarla bir esya olusturamazsin!\nOlusturulabilir Esyalar:\nBalta = Balta Sapi + Cubuk\nBuyulu Kilic = Buyu Kitabi + Kilic" << endl;
        }
    }


    void pickupItem(Character& character) {
        pair<int, int> currentPos = { playerRow, playerCol };

        // Mevcut konumun bir oda olup olmadigini kontrol et
        bool isRoom = false;
        int roomIndex = -1;
        for (int i = 0; i < roomCoordinates.size(); ++i) {
            if (currentPos == roomCoordinates[i]) {
                isRoom = true;
                roomIndex = i;
                break;
            }
        }

        if (isRoom) {
            // Odada esya var mi kontrol et
            auto& items = rooms[roomIndex].getMutableItems(); // Esyalarin gercek referansini al

            if (isThereItem(roomIndex)) {
                cout << "Yerde birkac esya buldun!" << endl;
                cout << "Yerdeki esyalar:";
                
                for (int i = 0; i < items.size(); ++i) {
                    if(items[i].second == true){
                        cout << " " << i+1 << ". " << items[i].first.getItemName() << ",";
                    }
                }
                cout << "\n";

                // Kullanicidan almak istedigi esyanin numarasini iste
                int choice;
                cout << "Hangi esyayi almak istersin? Numarasini sec: ";
                cin >> choice;

                // Secilen esyayi envantere ekle ve odadan kaldir
                if (choice >= 1 && choice <= items.size() && items[choice - 1].second == true) {
                    Item& selectedItem = items[choice - 1].first;
                    character.addItemToInventory(selectedItem);
                    cout << "Esyayi aldin: " << selectedItem.getItemName() << " ve esya envanterine eklendi." << endl;
                    
                    items[choice - 1].second = false;
                } else {
                    cout << "Yanlis secim. Herhangi bir esya alinmadi." << endl;
                }
            } else {
                cout << "Odada alinabilecek bir esya yok." << endl;
            }
        } else {
            cout << "Bu odada esya yok." << endl;
        }
    }

    void useInventoryItem(Character& character) {
        cout << "Envanterin:" << endl;
        auto& inventory = character.getInventory();
        for (int i = 0; i < inventory.size(); ++i) {
            cout << i + 1 << ". " << inventory[i]->getItemName() << " (" << inventory[i]->getItemType() << ")" << endl;
        }

        int choice;
        cout << "Hangi esyayi kullanmak istedigini sec: ";
        cin >> choice;

        if (choice >= 1 && choice <= character.getInventorySize()) {
            Item* selectedItem = inventory[choice - 1];

            // Check if the selected item is edible
            //const EdibleItem* edibleItem = dynamic_cast<const EdibleItem*>(&selectedItem);
            if (selectedItem->isEdible()) {
                // If the item is edible, use it
                character.useItem(selectedItem, choice - 1);
            } else {
                cout << "Sectigin esya kullanilamaz!" << endl;
            }
        } else {
            cout << "Yanlis secim!" << endl;
        }
    }

};

void helpMenu(){
    cout << "\n==Yardim==\n\nOyun Mantigi:\nBulut 100 can ile hikayeye baslar ve canini 0in uzerinde tutmasi gerekir. Eger cani 0in altina duserse tum gelismeleri sifirlanir ve oyunun basina doner.\n"
        << "Ilk ve son odalar disinda karsiniza rastgele 25 adet oda gelecek. Bu odalarin her birinin farkli farkli oyunlari bulunmakta ve bu oyunlarda yaptiginiz hatalara gore caniniz azalmaktadir.\n"
        << "Caninizi yenileyebileceginiz bazi esyalar bulunur. Ornegin Elma, elma 20 can yeniler ve 1 kere kullanilabilir. Bu esyalari oyunda bulup kullanabilirsiniz.\n"
        << "Envanterinizde bazi esyalar olacaktir. Bazi esyalarin herhangi bir turu bulunmazken bazi esyalarin ise turleri bulunur. Bu turler; Birlestirilebilir Esyalar, Yenilebilir Esyalar ve Gereklilikler'dir\n"
        << "Yenilebilir esyalar caninizi arttirir.\n"
        << "Gerekli esyalar son odaya gecis icin gereklidir ve yaninizda olmazsa son odaya gecemezsiniz!\n"
        << "Birlestirilebilir esyalar ise 2 esyayi birlestirip yeni bir esya olusturabilmenizi saglar.\n\n"
        << "Oyun Kayit/Ice Aktarma Mantigi:\n"
        << "Oyunu yalnizca kaydettiginizde kayit guncellenir. Otomatik kayit soz konusu degildir! Kaydetmeden cikis yaparsaniz son kaydiniz kalir ve oradan baslayabilirsiniz.\n"
        << "Oyunu ice aktarirken tam olarak kaydinizin kaldigi yerden oyununuz baslar. Envanterinizdeki esyalar, odalarin konumu, odalarin esyalari, kaldiginiz yer ve caniniz geri yuklenir.\n\n"
        << "Oyunda herhangi bir odaya girdiginiz zaman , o odadan toplayacaginiz esyalari odanin oyunu baslamadan toplayiniz. \n "
        << "Oyunda herhangi bir odadayken , odanin oyunu girmeden önce bir sonraki bolumde hangi yöne gideceginizi secmeniz gerekmektedir.\n";
 }

void saveGame(Map& gameMap, Character bulut){
    gameMap.saveToDatabase();
    bulut.saveToDatabase();
    gameMap.rooms_json();
}

int startGame(){
    Map gameMap;
    Entity db;
    Character bulut("Bulut", 100);

    bulut.addItemToInventory(apple);
    bulut.addItemToInventory(apple);
    bulut.addItemToInventory(kalem);
    bulut.addItemToInventory(kitap);
    bulut.addItemToInventory(cubuk);
    bulut.addItemToInventory(balta_sapi);
    bulut.addItemToInventory(kilic);
    bulut.addItemToInventory(buyu);
    bulut.addItemToInventory(balta);

    int i=0;

    gameMap.roomTransformation();  //Odalari rastgele degistirme fonksiyonu.
    
    // Ana menu dongusu
    while (true) {
        std::cout << "== Ana Menu ==" << std::endl;
        std::cout << "1. Oyuna Basla" << std::endl;
        std::cout << "2. Yardim" << std::endl;
        std::cout << "3. Dosyalari Ice Aktar" << std::endl;
        std::cout << "4. Cikis" << std::endl;

        int choice;
        std::cout << "Yapmak istedigin secenegi sec: ";
        while (true)
        {
            std::cin>>choice;
            if (cin.fail())
            {
                cout<<"Hatali Giris Yaptiniz!!!Tekrar Deneyin:"<<endl;
                cin.clear();
                cin.ignore(10000,'\n');
            }else{
                break;
            }
            
        }
        switch (choice) {
            case 1:
                system("cls");
                if(gameMap.getCurrentLocation() == make_pair(3,1))
                    cout << "Bulut sari sacli ela gozlu 8 yasinda hayvansever bir cocuktur. Baharin gelip gunesin kendini gosteremesiyle etrafta cicekler acmistir.\n"
                        << "Ormanin yakinlarinda bulunan kucuk kutu gibi ahsap evinin kocaman yesilliklerle dolu bir bahcesi vardir.\n"
                        << "Bir gun evinin camindan disariyi seyrederken bahcenin ne kadar guzel oldugunu dusunur ve bahceye oyun oynamaya cikar. Bahcede kendi kendine top oynamaya baslar.\n"
                        << "Topla bir sure oynadiktan sonra topa sertce vurur ve top evin bahcesinden disari cikar. Top, dallarinin tamami rengarenk ciceklerle dolu olan bir agacin yaninda durur.\n"
                        << "Bulut topunu almak icin evin bahcesinden disari cikar ve agacin yanina kosar. Tam egilip topu alirken caliliklarin arasindan sesler gelir. Bulut ilk basta bu sesten korkar sonra sesin kaynagini merak etmeye baslar.\n"
                        << "Bulutun bu meraki onu, sesin kaynagina gitmeye yoneltir. Caliliklara yaklastigi sirada orada yesilliklerin arasindaki bembeyaz minicik boncuk gibi gozleri olan bir kedi gorur.\n"
                        << "Kediyi gordugu anda oyun arkadasinin bu kedi olmasini ister. Kediye yaklasmaya baslar fakat bulut kediye yaklastikca kedi uzaklasmaya baslar. Kedi uzaklastikca da bulut onu takip eder.\n"
                        << "Boylece kedi ve bulut arasinda bir kovalamaca baslar. Bu kovalamaca sirasinda uzun uzun agaclarin oldugu sik bir ormanin icine dogru devam eder. Bu yolun sonunda kedi, Bulutu farkinda olmadan kendi ailesinin yanina getirir.\n"
                        << "Bulut orada birden fazla kedi oldugunu gorur. Kovaladigi kedi ve oradaki kediler aralarinda oyun oynamaya baslarlar. Bunu goren Bulut da onlarin oyununa dahil olmak ister fakat kediler buna izin vermezler.\n"
                        << "Kendini yalniz hisseden bulut orada bulunan kayanin uzerine oturur ve aglamaya baslar. Bulutun agladigini goren boncuk cocugun yanina gelir. Buluta ne oldugunu sorar. Bulut yalniz kaldigini ve onunla oyun oynamak istedigini soyler.\n"
                        << "Boncuk ve Bulut sohbet etmeye baslar. Boncuk ve bulut artik kaynasmistir. Boncuk Buluta guvenir ve ondan korkmamaya baslar. Beraber ormanin icinde oyun oynarlar. Bulut kacar boncuk kovalar.\n"
                        << "Bu kovalamaca oyununu tasli, toprakli, engebeli yollarda oynarken Bulutun ayagi birden bir agacin kokune takilir. Onundeki gorkemli agaca carpacagini dusunerek gozlerini kapatir, carpamayi bekler fakat bekledigi gibi olmaz.\n"
                        << "Agaca carpamamistir.(:O) Gozlerini bu saskinlikla acar. Carpamadigi icin sevinir fakat daha buyuk bir sorun vardir. Artik ormanda degillerdir. Etrafi bembeyaz olan bir yere gelmislerdir.\n"
                        << "Bu yerde Bulut ve Boncuktan baska kimse yoktur fakat odanin icinde yankilanan bir ses vardir. Sanki hoparlorden birisi konusuyormus gibi ses gelmektedir.\n"
                        << "Bu ses onlarin neyi bekledigini anlatmaya baslamistir. Sesin dedigine gore onlari macera dolu 25 oda bekliyor olacaktir. Bu odalarin her birinin icinde gecmeleri gereken zorlu gorevler ve her bir odadan toplamalari gereken esyalar olacaktir.\n"
                        << "Bu esyalarin hangisi oldugunu anlamak icin uzerlerine bir imge cizilmistir. Bu imge Saturn gezegenidir. Onlara verilen belirli sayida bir can hakki vardir. Eger oyunlarda basarisiz olur da canlari biterse en bas odaya doneceklerdir.\n"
                        << "Bu aciklamalari yaptiktan sonra ses susar. Bulut ve Boncuga mantiksiz gelen bir sey vardir. O da neden bu esyalari toplamalari gerektigidir. Ses sanki onlari duyuyormus gibi tekrardan konusmaya baslar.\n"
                        << "Bu esyalarin baska bir cocugun kaybolan oyuncaklari oldugunu ve toplayip en son 25 odanin sonundaki kasaya hepsini birakmalari gerektigini soylar. Eger eksik bir esya olursa bu oyundan cikamayacaklardir.\n"
                        << "Eksiksiz olarak getirirlerse de oyunu basarili bir sekilde tamamlayip son odadaki cikis kapisindan geldikleri ormana cikacaklardir.\n"
                        << "Son olarak ses onlara aslinda secilmis kisiler olmadiklarini soylar. Buraya onlardan once agaca baskasi carpmissa onlarin burada olmalarina gerek kalmayacagini ve karsilarinda beliren butona basildigi anda carptiklari agactan ilk odaya isinlanacaklarini da ekler.\n"
                        << "Her iki tarafin da soyleyecek bir seyi kalmamistir ve sans eseri girdikleri bu oyuna baslamak icin hazirlardir. Butonunun karsilarinda belirmesiyle butona basarlar ve oyunun ilk odasina isinlanirlar.\n";
                    //std::cout << "\nBulut sari sacli ela gozlu 8 yasinda hayvansever bir cocuktur. Baharin gelip gunesin kendini gostermesiyle etrafta cicekler acmistir.\nOrmanin yakinlarinda bulunan kucuk kutu gibi ahsap evinin kocaman yesilliklerle dolu bir bahcesi vardir.\nBir gun evinin camindan disariyi seyrederken bahcenin ne kadar guzel oldugunu dusunur ve bahceye oyun oynamaya cikar. Bahcede kendi kendine top oynamaya baslar.\nTopla bir sure oynadiktan sonra topa sertce vurur ve top evin bahcesinden disari cikar. Top ,dallarinin tamami rengarenk ciceklerle dolu olan bir agacin yaninda durur.\nBulut topunu almak icin evin bahcesinden disari cikar ve agacin yanina kosar.Tam egilip topu alirken caliliklarin arasindan sesler gelir. \nBulut ilk basta bu sesten korkar sonra sesin kaynagini merak etmeye baslar. Bulutun bu meraki onu ,sesin kaynagina gitmeye yoneltir. \nCaliliklara yaklastigi sirada orada yesilliklerin arasindaki bembeyaz minicik boncuk gibi gozleri olan bir kedi gorur. Kediyi gordugu anda oyun arkadasinin bu kedi olmasini ister. \nKediye yaklasmaya baslar fakat bulut kediye yaklastikca kedi uzaklasmaya baslar. Kedi uzaklastikca da bulut onu takip eder. \nBoylece kedi ve bulut arasinda bir kovalamaca baslar. Bu kovalamaca sirasinda uzun uzun agaclarin oldugu bir ormanin icine dogru devam ederler. \nBu yolun sonunda kedi, bulutu farkinda olmadan kendi ailesinin yanina getirir. Bulut orada birden fazla kedi oldugunu gorur. \nKovaladigi kedi ve oradaki kediler aralarinda oyun oynamaya baslarlar. Bunu goren Bulut da onlarin oyununa dahil olmak ister fakat kediler buna izin vermezler. \nKendini yalniz hisseden bulut orada bulunan kayanin uzerine oturur ve aglamaya baslar. Bulutun agladigini goren boncuk cocugun yanina gelir. \nBuluta ne oldugunu sorar. Bulut yalniz kaldigini ve onunla oyun oynamak istedigini soyler. Boncuk ve Bulut sohbet etmeye baslar. Boncuk ve bulut artik kaynasmistir. \nBoncuk Buluta guvenir ve ondan korkmamaya baslar. Beraber ormanin icinde oyun oynarlar. Bulut kacar boncuk kovalar. \nBu kovalamaca oyununu tasli, toprakli, engebeli yollarda oynarken Bulutun ayagi birden bir agacin kokune takilir. \nOnundeki gorkemli agaca carpacagini dusunerek gozlerini kapatir , carpmayi bekler fakat bekledigi gibi olmaz. Agaca carpmamistir.(:O) \nGozlerini bu saskinlikla acar. Carpmadigi icin sevinir fakat daha buyuk bir sorun vardir. Artik ormanda degildir.(:O) Sanki carpacagi agacta buyulu bir gecit ile baska bir yere isinlanmistir.\n" << std::endl;
                char move, info, temp;
                while (true) {
                    if(bulut.getHealth()<=0){
                        cout << "Ama yine de iyi ilerledin";
                        return 0;
                    }
                    if (std::cin.get() == 'P') {
                    } else {
                        for(i;i<1;i++)
                            gameMap.printMap();
                        std::cout << "Ne yapmak istersin (W: Yukari, S: Asagi, A: Sola, D: Saga, C: Karakter Bilgileri, P: Yerden Esya Al, U: Esya Kullan, T: Esya Birlestirme, E: Oyunu Kaydet): ";
                        std::cin >> temp;
                        if (temp == 'W' || temp == 'S' || temp == 'D' || temp == 'A') {
                            move = temp;
                            gameMap.movePlayer(move, bulut);
                        } else if (temp == 'C') {
                            bulut.showCharacterInfo();
                        } else if (temp == 'P') {
                            gameMap.pickupItem(bulut);
                        } else if (temp == 'U') {
                            gameMap.useInventoryItem(bulut);
                        } else if (temp == 'T') {
                            gameMap.craftItems(bulut);
                        } else if (temp == 'E') {
                            saveGame(gameMap,bulut);
                        } else {
                            std::cout << "Yanlis Secim." << std::endl;
                        }
                    }
                }
                break;
            case 2:
                //std::cout << "Help menu." << std::endl;
                helpMenu();
                // Help menusu islemleri
                break;
            case 3:
                // Dosya ice aktarma menusu islemleri
                std::cout << "Kayitli Save Dosyalari Oyuna Entegre Edildi.\n" << std::endl;
                gameMap.loadFromDatabase();
                bulut.loadFromDatabase();
                gameMap.load_rooms_back();
                break;
            case 4:
                std::cout << "Oyun kapatiliyor." << std::endl;
                exit(0); // Programi sonlandir
                break;
            default:
                std::cout << "Yanlis Secim." << std::endl;
                break;
        }
    }

    return 0;
};

int main() {
    return startGame();
}