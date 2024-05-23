#ifndef MOUNTAIN_H
#define MOUNTAIN_H

#include <iostream>
#include <vector>

using namespace std;

// Haritayı temsil etmek için 2D vektör kullanacağız
vector<vector<int>> oo = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0, 1, 3, 0},
    {0, 1, 0, 1, 0, 1, 0, 0},
    {0, 1, 0, 1, 0, 1, 0, 0},
    {0, 1, 0, 1, 0, 1, 0, 0},
    {0, 1, 0, 1, 1, 1, 0, 0},
    {0, 2, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

// Hareketleri tutmak için enum kullanacağız
enum Hareketler { YUKARI, ASAGI, SOL, SAG };

// Oyuncunun konumunu tutacak sınıf
class Oyuncu {
public:
    int x, y; // Oyuncunun koordinatları

    // Oyuncunun başlangıç konumunu belirle
    Oyuncu(int baslangicX, int baslangicY) : x(baslangicX), y(baslangicY) {}

    // Yeni konumu güncelle, hata sayısını kontrol et
    void konumuGuncelle(int newX, int newY, int& zz) {
        // Yeni konum geçerli mi kontrol et
        if (oo[newX][newY] == 0) {
            cout << "Lavlara mi gideceksin? Delirdin mi sen??" << endl;
            zz++;
        } else {
            x = newX;
            y = newY;
        }
    }
};

int startMountainGame() {
    Oyuncu oyuncu(6, 1); // Oyuncunun başlangıç konumu

    int zz = 0; // Hata sayısı

    cout<<"Etraftaki kavurucu sicak onlari fazlasiyla rahatsiz eder. Onlarin etrafinda küçük, yesillikler içindeki bir köy vardir.."
    <<"Buradaki evlerin hepsi tek katlidir ve hepsinin onunde tarim yaptiklari arazileri vardir. \nBu koy yakin zaman once terk edilmis gibi duruyordur. Koylulerin ektikleri seyler buyumustur ama etrafta kimse yoktur. Anlamadiklari sey ise koylulerin"
    <<"bu sicakta nasil yasadiklari ve sicagin nereden geldigidir. \nArkalarini donduklerinde koskocaman bir dag gorurler. Bu dagin icinden fokurdama sesleri geliyordur. Ilk once ne oldugunu anlayamazlar. Sonra gordukleri"
    <<"bir yapboz parcasi gibi yerine oturur. \nBurada bu kadar cok tarim arazisinin olmasi, su anda kimsenin burada olmayisi, dagin icinden gelen sesler ve yuzlerine vuran sicak havanin tek bir aciklamasi vardir. \nO da yanlarindaki"
    <<"dagin aktif bir volkanik dag oldugu ve az sonra patlayacagidir. Onlar icin zaman cok kisitlidir. \nBir an once yuksek bir yere cikmalari gerekir. Dagin etrafi oldukca duzluk bir araziden olusuyordur. Onlarin cikabilecegi sadece yuksek bir kayalik vardir. \nVakit"
    <<"kaybetmeden oraya dogru giderler. Yanardaginin patlamasina az zaman kalmistir. Bulut ve Boncuk zar zor sivri kayanin tepesine cikarlar. \nOrada bir magara oldugunu gorurler. Magarada koylulerin onceden gelip biraktiklari bir kac esya vardir."
    <<"(?) Kisa bir sure sonra yanardaginin patlamasiyla tam zamaninda ciktiklarini dusunurler. \nHala bir sorun vardir. Ates kirmizisi lavlar onlarin oldugu yukseklige dogru geliyordur. Ne yapacaklarini bilmiyorlardir. Kedi korkudan Bulutun ustune atlar"
    <<"Bulut ise kacabilecekleri baska bir yer var mi diye etrafina bakinir.\nLavlar onlarin oldugu yukseklige iyice yaklasmistir. Bu oyundan cikamayacaklarini dusunurler ve olacaklara razi olup korkudan gozlerini kapatirlar."
    <<"Ta ki yer altindan cikan yuksek kayalarin cikardigi gurultulu sesleri duyana kadar. \nBir mucize olmustur. Yitirdikleri umutlari tekrardan yesermeye baslamistir. Bu uzun kayalar sayesinde lavlarin olmadigi yere gecebileceklerdir. Taslarin uzerinden git ve lavlara degme!!\n\n";


    cout << "Map:\n";
    while (true) {
        // Haritayı ekrana yazdır
        for (int i = 0; i < oo.size(); i++) {
            for (int j = 0; j < oo[i].size(); j++) {
                if (oyuncu.x == i && oyuncu.y == j) {
                    cout << "P "; // Oyuncu konumu
                } else if (oo[i][j] == 0) {
                    cout << "# "; // Gidilemeyen yol
                } else if (oo[i][j] == 1) {
                    cout << "- "; // Gidilebilen yol
                } else if (oo[i][j] == 3) {
                    cout << "E "; // Gidilebilen yol
                } else if (oo[i][j] == 2) {
                    cout << "S "; // Gidilebilen yol
                }
            }
            cout << endl;
        }

        // Hareket isteği al
        cout << "\nHareket seciniz (W: Yukari, S: Asagi, A: Sol, D: Sag):\n";
        char hareket;
        cin >> hareket;

        // Oyuncunun yeni konumunu belirle
        int newX = oyuncu.x, newY = oyuncu.y;
        switch (hareket) {
            case 'w': newX--; break;
            case 'W': newX--; break;
            case 's': newX++; break;
            case 'S': newX++; break;
            case 'a': newY--; break;
            case 'A': newY--; break;
            case 'd': newY++; break;
            case 'D': newY++; break;
            default: cout << "Gecersiz hareket!" << endl; continue;
        }

        // Yeni konumu güncelle
        oyuncu.konumuGuncelle(newX, newY, zz);

        // Eğer oyuncu bitiş noktasına ulaştıysa oyunu bitir
        if (oo[oyuncu.x][oyuncu.y] == 3) {
            cout<<"Zorlu bir gecisten sonra nihayet lavlarin olmadigi kisma gecmislerdir. Iclerindeki korku bir nebze olsun azalmistir. O sirada volkanizmanin puskurttugu lavlar iyice azalmistir ama yerler hala lavlarla doludur.\nCaresizce ne yapacaklarini dusunurken uzaklardan bir ses duyarlar\n"
            <<"Onlara seslenen bir koyludur bu kisi. Demek ki az da olsa burada kalan koylulerin oldugunu dusunurler .Koylu onlari yanina cagiriyordur. Baska careleri yoktur.\nMecburen yanina gitmek zorundalardir. Koylunun yanina vardiklarinda aralarinda bir konusma gecer.\n"
            <<"-Koylu ( isim)=siz galiba su oyuna dusen kisilerden birisiniz. Onlar disinda buraya gelip giden olmaz zaten.\n"
            <<"-Bulut = Evet onun icin buradayiz ama nasil cikacagimizi bilmiyoruz. Sizin bildiginiz bir sey var mi?\n"
            <<"-Koylu= Evet tabi ki var . Ben bu koyun dedikoducu teyzeleri gibiyim benden bir sey kacmaz . :) simdi size bir sey verecegim bu cihaza bastiginizda  buradaki butun lavlar kalkacak ve eski haline donecek. \nLavlarin kalkmasiyla  hem lavlarin"
            << "arasinda olan sizin cikisiniz icin gerekli esyayi bulacaksiniz  hem de dagin icindeki acilacak gecitten gecmenizi saglayacak.\n"
            <<"-Bulut=Tesekkur ederiz abi sen de olmasan gecemeyecektik bu bolumu. Cihazi alirlar.\n\n";
            cout << "\nCihazi almak icin herhangi bir tusa basin...\n";
            {
                string a; 
                cin >> a;
            }
            cout << "Cihazin tusuna basarlar ve adamin dedigi gibi butun lavlar bir anda ortadan kalkar. Etraflarina bakinirlar yerde tek bir esya vardir. \nOnu alirlar ve dagin tepesine tirmanirlar. Tepeye geldiklerinde gecidin acik oldugunu gorurler ve icine atlamalariyla bir sonraki bolume gecmis olurlar.\n";
            break;
        }
    }

    return zz;
}

#endif