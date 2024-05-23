#ifndef HIPPODROME_H
#define HIPPODROME_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <algorithm> 
#include <random> 
#include <ctime> 
using namespace std;

int hatasayisi1= 0;

class Atlar {
public:
    string ismi;
    int hiz;
    int popularite;
    string tur;

    Atlar(const string& isim, int hiz, int popularite, const string& tur)
        : ismi(isim), hiz(hiz), popularite(popularite), tur(tur) {}
};

void Ozellikler(vector<Atlar>& atlarListesi) {
    for (const auto& at : atlarListesi) {
        cout << "Atin Ismi: " << at.ismi << endl;
        cout << "Hizi: " << at.hiz << endl;
        cout << "Populeritesi: " << at.popularite << endl;
        cout << "Turu: " << at.tur << endl << endl;
    }
}

bool atTahmini() {
    string kupon1[6]={"busra","beyazsaray","prens","yildiz","ahmet","batu"};
    cout << "Tahminlerini yapmaya basla Bulut." << endl << endl;
    cout<<"Hatali Giris Yapma Bulut Yoksa Butun Kuponlari Bastan Doldurmak Zorunda Kalirsin!!!!"<<endl;

    string kupon[3][6];

    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ". Kuponu gir Bulut:" << endl;
        for (int j = 0; j < 6; j++) {
            cout << j + 1 << ". at" << endl;
            cin.ignore();
            while (true)
            {
                cin >> kupon[i][j];
                if (cin.fail())
                {
                    cout<<"Hatali Giris Butun Kuponlari Bastan Gir!!!"<<endl;
                    cin.clear();
                    cin.ignore(10000,'\n');
                }else{
                    break;
                }
                
            }
            transform(kupon[i][j].begin(), kupon[i][j].end(), kupon[i][j].begin(), ::tolower);
        }
    }
    
    int arr[3];


    bool enAzBirDogru = false;
    for (int i = 0; i < 3; i++) {
        int dogruSayisi = 0;
        for (int j = 0; j < 6; j++) {
            if (kupon[i][j] == kupon1[j]) {
                dogruSayisi++;
            }
        }
        arr[i]=dogruSayisi;
        dogruSayisi=0;
    }

int sayac=0;
    for (int i = 0; i <3; i++)
    {
        cout<<arr[i]<<endl;
        if (arr[i]==6)
        {
            sayac++;
        }
           
    }
    if (sayac>0)
    {
        cout<<"-Sari sacli amca : Helal olsun evlat yazdigin kupon tuttu kazandin .Simdi de kuponu kazandigin icin yan taraftan sana bir de hediye verecekler. Gidip onu almalisin.\n"
       "Bulut adamin dedigi hediyeyi almaya gider.Uzerinde onlarin aradiklari imgenin oldugu bir at nali verilir. Kalabaligin ortasindan bir gecis paneli olusur ve sira bir sonraki bolumdedir."<<endl;
        return false;
    }else{
        cout<<"Ama yine de iyi ilerledin lutfen tekrar sansini dene"<<endl;
        hatasayisi1++;
        return true;
    }
    
    
}

void replik1(){
    cout<<"Bulut ve Boncuk gecitten gectikleri gibi sert bir dusus yasarlar. Dusmenin verdigi etkiyle bir sure boyunca kendilerini toparlayamazlar fakat burunlarina keskin bir koku gelir. Bu kokudan bir hayvanin yaninda olduklarini anlarlar.\n"
    "Kendine geldiklerinde ise gozlerini acarlar ve tam da tahmin ettikleri gibi hayvan olan bir yerdedirler. Yanlarinda birden cok at vardir. Bulunduklari yeri biraz daha incelediklerinde yesil bir alanin icinde kucuk iki katli\nevlerin oldugunu gorurler.\n"
    "Evlerin onunde ise atlari yikayan, tarayan,onlarin bakimini yapan bir suru seyis gorurler.Hepsi islerini cok istekli, odakli ve ozenli yapiyor gibi duruyorlardir ki bulut ve boncugun orda oldugunu bile fark etmemislerdir.\n"
    "Bulut ve Boncuk etrafta yururken bir seyis ve jokey arasinda gecen konusmaya sahit olurlar.\n"
    "-Jokey: Bu mactan cok umitliyim .Kesinlikle kazanmamiz lazim. Atla cok guzel uyum yakaladik. Yarista da aynisini yapabilirsek kesinlikle kazaniriz.\n"
    "-Seyis: Biz de sizden cok umitliyiz. Bu ata binen onceki seyisimize karsi cok hircindi siz gelince birden sakinlesiyor.Mukemmel bir ikili oldunuz.\n"
    "-Jokey: Her seyi hazir mi yarismaya az bir zaman kaldi. Yaris alanina gitmemiz gerekiyor.\n"
    "-Seyis: Kendisi cok hazir. Araca yuklenmeyi bekliyor. Siz de hazirsaniz yukleyip gidelim.\n"
    "Bulut bu konusmadan bir at yarisi oldugunu anlar. Fakat nerede oldugunu bilmiyorlardir .Bu yuzden atin bindirildigi arabaya binmeye karar verirler...\n"
    "Ati araca yuklerler.Fakat aracin kapisini acik birakmislardir. Bundan istifade ederek gizlice arabaya binerler ve bir sure sonra kapi otomatik olarak kapanir.Aracta atla yan yana olmak onlari cok gerse de atin gozunun kapatilmis olmasi\nrahatlamalarini saglar."
    "Kisa bir sure atla birlikte yolculuk yaparlar.Sonunda araba durur ve kapi yine kendiliginden acilir.Bunu firsat bilerek kimseye yakalanmadan arabadan inerler.\n"
    "cevreye baktiklarinda ilk geldikleri yerdeki gibi yesilliklerin olmadigini , birbirinden citlerle ayrilmis yan yana yollarin, karsida ise oturma yerlerinin oldugunu gorurler.At yarisinin yapilacagi yere gelmislerdir.\n"
    "Burasi bir hipodromdur. Insanlarin olusturdugu bir kalabalik vardir. Ikisi birlikte oraya dogru giderler. Genellikle yasli amcalardan olusan bu topluluk kupon dolduruyordur .Kuponlari veren adam yogunluktan kafasini bile kaldirmadan\nkuponlari dagitir .Bulut'a da bir tane verilir. Ama nasil dolduracagini bilmiyordur. Yanindaki sari sacli amca ona seslenir.\n"
    "-Sari sacli amca: Evlat nasil dolduracagini bilmiyorsan ben sana gostereyim.\n"
    "-Bulut: Olur amca, nasil yapilacagini bilmiyorum zaten."
    " (Adam elindeki fazla kalemi Bulut'a uzatir)\n"
    "-Sari sacli amca: Tut bakayim su kalemi."
    " (Bulut kalemi alir)\n"
    "Sari sacli adam kuponu doldururken bulut da onu izler. Daha sonra amcadan ogrendikleri ile bulut kuponu doldurmaya baslar."<<endl;
}
int startHippodromeGame() {
    vector<Atlar> atlarListesi = {
        {"BeyazSaray", 60, 4, "Arap Ati"},
        {"Batu", 55, 3, "Araber"},
        {"Busra", 62, 5, "Mustang"},
        {"Sahmerdan", 58, 4, "Ingiliz"},
        {"Yildiz", 57, 4, "Endulus Ati"},
        {"Prens", 59, 4, "Ingiliz"}
    };
    replik1();
    int secim;
    cout << "Veli Efendi Hipodromun'a Hosgeldin Bulut.Umariz sansli gunundesindir!!! Bu odadan cikabilmek icin 6'li";
    cout << "Bu oyundaki amacin: 6 Atin da hangi sirayla yarisi bitirecegini tahmin edebilmek."
        "Istersen,atlarin ozelliklerini ve insanlarin bu atlar hakkinda ne dusundugunu ogrenebilirsin!!" << endl;
    cout << "Ya da direk tahminde bulunabilirsin.Sana 3 tane kupon hakki taniyacagim,bu 3 kupondan 1'i bile tutarsa odulu almaya hak kazanacaksin." << endl;
    cout << "Unutma Bulut ortada bir sans oyunu varsa icinde hile olabilir????" << endl;
    bool flag=true;
    while (flag) {
        cout << "(1) Tahmin" << endl;
        cout << "(2) Atlarin Ozellikleri" << endl;
        //cout << "(3) Cikis" << endl;
        while (true)
        {
            cin >> secim;
            if (cin.fail())
            {
                cout<<"Hatali Giris Tekrar Dene!!!!"<<endl;
                cin.clear();
                cin.ignore(10000,'\n');
            }else{
                break;
            }
            
        }      
        if (secim == 1) {
            flag=atTahmini();
        }
        else if (secim == 2) {
            Ozellikler(atlarListesi);
            flag=true;
        }
        //else if (secim == 3) {
            //flag=false;
        //}
        else {
            cout << "Hatali Giris Yaptiniz!!! Tekrar deneyin." << endl;
        }
    }


    return hatasayisi1;
}


#endif