#ifndef FOREST_H
#define FOREST_H
#include<iostream>
#include<algorithm>
#include <ctime>

using namespace std;

int be=0;
void tasKagit(){
     cout << "Oyun Basladi!!!!" << endl;

    int oyuncuSkor = 0;
    int bilgisayarSkor = 0;
    int tur = 1;

    while (oyuncuSkor < 3 && bilgisayarSkor < 3) {
        cout << "\nTur " << tur << endl;

        
        int oyuncuSecimi;
        bool gecerliSecim = false;
        while (!gecerliSecim) {
            cout << "Seciminizi yapin (1: Tas, 2: Kagit, 3: Makas): ";
            while (true)
            {
                cin>>oyuncuSecimi;
                if (cin.fail())
                {
                    cout<<"Hatali Giris Yaptiniz Tekrar Deneyin"<<endl;
                    cin.clear();
                    cin.ignore(10000,'\n');
                }else{
                    break;
                }
                
            }
            if (oyuncuSecimi >= 1 && oyuncuSecimi <= 3) {
                gecerliSecim = true;
            } else {
                cout << "Gecersiz secim! Lutfen 1, 2 veya 3 girin." << endl;
            }
        }

        // Agacin secimini belirle (rastgele)
        srand(time(0) + tur); // Her tur icin farkli bir tohum kullan
        int bilgisayarSecimi = rand() % 3 + 1; // 1, 2 veya 3 arasinda rastgele bir sayi sec

        // Oyuncunun secimini ekrana yazdir
        switch (oyuncuSecimi) {
            case 1:
                cout << "Oyuncunun Secimi: Tas" << endl;
                break;
            case 2:
                cout << "Oyuncunun Secimi: Kagit" << endl;
                break;
            case 3:
                cout << "Oyuncunun Secimi: Makas" << endl;
                break;
        }

        // Agacin secimini ekrana yazdir
        switch (bilgisayarSecimi) {
            case 1:
                cout << "Agacin Secimi: Tas" << endl;
                break;
            case 2:
                cout << "Agacin Secimi: Kagit" << endl;
                break;
            case 3:
                cout << "Agacin Secimi: Makas" << endl;
                break;
        }

        // Kazanani belirle
        if (oyuncuSecimi == bilgisayarSecimi) {
            cout << "Berabere!" << endl;
        } else if ((oyuncuSecimi == 1 && bilgisayarSecimi == 3) ||
                   (oyuncuSecimi == 2 && bilgisayarSecimi == 1) ||
                   (oyuncuSecimi == 3 && bilgisayarSecimi == 2)) {
            cout << "Oyuncu Kazandi!" << endl;
            oyuncuSkor++;
        } else {
            cout << "Ulu Cinar Kazandi!" << endl;
            bilgisayarSkor++;
        }

        // Tur sonu
        tur++;
    }

    // Sonuclari ekrana yazdir
    cout << "\n--- SONUC ---" << endl;
    cout << "Oyuncu Skoru: " << oyuncuSkor << endl;
    cout << "Ulu Cinar'in Skoru: " << bilgisayarSkor << endl;
    if (oyuncuSkor > bilgisayarSkor) {
        cout<<"Oyunu Bulut kazanir ve Saturn simgesi olan kalemi alir. Boncuk ile beraber cinar adamla vedalasip geldikleri agac kovuguna giderler. Kovuk artik gecit kapisi olmustur ve diger odaya gecerler… "<<endl;
    } else if (bilgisayarSkor > oyuncuSkor) {
        cout<<"Bulut oyunu kaybeder ancak Ulu Cinar onlarla oynadigi icin yine de Saturn simgesi olan kalemi verir ama kaybettikleri icin canlari azalacaktir. Boncuk ile beraber cinar adamla vedalasip geldikleri agac kovuguna giderler. Kovuk artik gecit kapisi olmustur ve diger odaya gecerler…"<<endl;
        be++;
    } else {
        cout << "Berabere!" << endl;
    }
}
void y1(){
    cout<<"Bulut ve boncugun dustukleri yer bu sefer bir ormandir. Burasi oyunun icine yanlislikla dustukleri ormanin icine cok benziyordur. Burada uzun uzun gogu kaplayan agaclar vardir. Etraftaki agaclardan baska hicbir sey gozukmuyordur. Evlerine dondukleri icin\ncok sevinirler. Evlerini bulmak icin etrafta gezinmeye baslarlar. Ormanin icinde ilerledikce sesler duymaya baslarlar. Sesin nereden geldigini anlamaya calisirlar." 
    "Ne tarafa bakarlarsa baksinlar bir insan goremezler. Madem insan yoksa bu ses nereden geliyordur ?Sesin kaynagini bulamayan bulut ve boncuk ilerlemeye devam ederler. Ilerideki agacin meyvelerini gorurler ve cok canlari ceker. Gidip biraz meyve toplarlar ve cantaya atarlar."<<endl;
    cout<<"Cantaya eklemek icin 'e' ye bas."<<endl;
    char cevap='\0';
    while (true)
    {
        cin>>cevap;
        if (cin.peek()=='\n')
        {
            if (cevap=='e' || cevap=='E')
            {
                break;
            }else{
                cout<<"Cantaya Ekleme Yapmadiniz"<<endl;
            }
            
        }else{
            cout<<"Hatali Giris Yaptiniz Tekrar Deneyin"<<endl;
            cin.clear();
            cin.ignore(10000,'\n');
        }       
    }
    
    
    }
void y2(){
    cout<<"Daha sonra oturup o agacin dibinde dinlenmeye baslarlar tam o sirada dibine oturduklari agac arkasini doner ve konusmaya baslar.\n"
    "-Agac:Siz ne yaptiginizi saniyorsunuz burada!\n"
    "Bulut ve boncuk bir anda cok sasirir  ve ciglik atarlar.(AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA)\n"
    "-Bulut: NEEEE ? BIR AgAc NASIL KONUsABILIR ? \n" 
    "-Agac: Burasi buyulu bir orman bilmiyor musunuz siz? Buradaki agaclar hem konusurlar hem de hareket ederler. Yururken yonunuze dikkat edin cunku agaclar yer degistirince bir anda kaybolabilirsiniz.\n" 
    "-Bulut: Iyi de biz buradan nasil cikacagiz yaaa ?\n"
    "-Agac: Siz ne ariyorsunuz ki ?\n"
    "-Bulut: Biz bir oyunun icinde sikisip kaldik. Tilsimli esyalari bulmaya calisiyoruz. Kayboldugumuz yer de tam olarak buraya benziyordu. Tam kurtulduk sanmistik fakat bitmemis. Lutfen bize yardimci olur musun o esyayi bulmamiz gerekiyor.\n" 
    "-Agac: Nasil bir esyaymis bu?\n"
    "-Bulut: uzerinde Saturn simgesi olan bir esya . Biz de ne oldugunu bilmiyoruz. Her odada rastgele buluyoruz aslinda."
    "-Agac: Himmmm, anladim sizi. Galiba size yardimci olabilecek birini taniyorum, o ormanin en buyuk ve kudretli agacidir.Onunla konusurken cok\nsaygili olup onu kizdirmamaniz gerekli cunku biraz huysuz bir agactir. Ama aradiginiz seyin onda olduguna eminim.\n"
    "Bulut ve boncuk agaci takip ederler. Agac onlari ulu cinarin yanina goturur.Bulut cinarin karsisina gecmistir. Sonra aniden ulu cinar sakinlesmis ve sasirmistir. Yillar sonra ilk defa insan goruyordur burada. cocuga altindaki kovuktan girmesini istemistir.\nBulut ulu cinarin kocaman kovugundan iceri girmistir. Iceride 100e yakin merdiven vardir. Bu merdiven ahsaptan donen bir merdivendir. Sanki hic saglam degil de curuk gibi olan\n"
    "merdivenlerden buyuk bir endiseyle hepsini sabirla tirmanir. Bir de ne gorsun .Aslinda ulu cinari kontrol eden bir insandir.Burada yalniz kalmaktan huysuzlasmis bir insan. Sonrasinda aralarinda konusmaya baslarlar."
    "-Agac: Ben bu ormani yoneten agaclarin huzurunusaglayan kisiyim siz de kimsiniz yillardir buradan hic insan gecmedi .Burasi buyulu bir orman oldugu icin korkuyorlar.\n" 
    "-Bulut: Buraya biz de yanlislikla dustuk. Saturn simgeli esyayi bulup buradan cikmak istiyoruz. Yuruyen agac bizi size getirdi ve bilginizin oldugunu soyledi.\n"
    "-Agac: Evet galiba aradiginiz seyi biliyorum. Yillardir masamda duran bu tahta kalemin uzerinde Saturn simge var. Bende hep dusunurdum neden boyle bir simge oldugunu. Ama bunu size boyle kolay vermem. Ancak benimle tas kagit makas\noynarsaniz verebilirim ama\nkaybederseniz canininiz azalir haberiniz olsun. Burada cok sikiliyorum sizinle biraz eglenme zamani"<<endl;
}
int startForestGame() {
   y1();
   y2();
   tasKagit();

    return be;
}

#endif