#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

void writeStringToJsonFile(string fileName, const string& inputString) {
    // Open file named "data.json" for writing
    ofstream outputFile(fileName);

    // Check if the file is opened successfully
    if (!outputFile.is_open()) {
        cerr << "Hata: Dosya acilamadi." << endl;
        return;
    }

    // Write the input string to the file
    outputFile << inputString;

    // Close the file
    outputFile.close();

    cout << "Dosya "<< fileName << "'a basariyla kaydedildi." << endl;
}

string readJsonFileToString(string fileName) {
    // Open file named "data.json" for reading
    ifstream inputFile(fileName);

    // Check if the file is opened successfully
    if (!inputFile.is_open()) {
        cerr << "Hata: Dosya acilamadi." << endl;
        return "";
    }

    // Create a string stream to hold the file contents
    stringstream buffer;
    buffer << inputFile.rdbuf();

    // Close the file
    inputFile.close();

    // Return the file contents as a string
    return buffer.str();
}

class Entity {
    private:
        //pair <int,int> location;
        //int healthValue;
    public:
        void loadFromDatabase(){
            string json_string = readJsonFileToString(getFileName());
            json j = json::parse(json_string);
            from_json(j);
        }

        virtual void from_json(json j){
            //j.at("location").get_to(this->location);
            //j.at("healthValue").get_to(this->healthValue);
        }

        void saveToDatabase(){
            json j = to_json();
            writeStringToJsonFile(getFileName(),j.dump());
        }

        virtual string getFileName(){
            return "entity.json";
        }

        // JSON serileştirme fonksiyonu
        virtual json to_json() {
            return NULL;
        }
};

#endif