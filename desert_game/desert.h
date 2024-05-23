#ifndef DESERT_H
#define DESERT_H

#include <iostream>
#include <cstdlib> // srand, rand
#include <ctime> // time

using namespace std;

int startDesertGame(){
    
    // Senaryonun baslangici
    cout << "Teleporttan dustugu anda  kendini simsicak issiz bir cölün ortasinda bulur\n"
         << "caresizce yürümeye baslar ve herhangi bir sey bulmak icin uzun bir süre yürür.\n"
         << "Tam tepedeki yakici günes, yerdeki kizgin kumlar onu cok susatmistir.\n";
    cout << "Tam pes etmek üzereyken ilerdeki  kayanin yaninda basibos bir  deve görür. Ona dogru bitkin bir sekilde  ilerler ve yanina ulastiginda  onun üstündeki hali desenine benzer motifli eyere biner \n";
    // Kullaniciya deveye binmek icin herhangi bir tusa basmasi gerektigini söyle
    cout << "\nDeveye binmek icin herhangi bir tusa basin...\n";
    {
        string a; 
        cin >> a;
    }

    // Deveye bindikten sonra senaryonun geri kalani  
    cout << "Eyerin her iki taraftaki ceplerini kontrol eder . Bir cebinde matara bulur.\n"
         << "Mataranin ici bostur ama yine de cantasina alir.\n"
         << "Diger cebinde ise altin renginde eski  bir anahtar bulur. \n"
         << "Bununla ne yapacagini bilmese de isine yarayacagini düsünüp yanina alir. \n"
         << "Daha sonra deve bulutun kontrolü disinda ilerlemeye baslar Deve onu bir vahanin yakinlarina getirir.\n";

    // Su birikintileri kismi
    cout << "Bulut sicaktan serap gordugunu dusunur. Cunku onunde 5 farkli su birikintisi gormektedir.\n"
         << "Ama bu su birikintilerinden sadece biri gercektir. Hangisinin gercek oldugunu bulmak icin secmen gerekir.\n\n";

    // Dogru su birikintisini belirleyelim (örnegin 3. su birikintisi dogru olsun)
    srand(time(0)); // Rastgelelik icin zamani kullan
    int dogruBirikinti = 5; // 1 ile 5 arasinda rastgele bir sayi sec

    int secim;
    int hatasayisi = 0;

    do {
        cout << "Hangi su birikintisini sececeksin (1-5 arasi bir rakam girin): ";
        while (true)
            {
                cin>>secim;
                if (cin.fail())
                {
                    cout<<"Hatali giris Yaptiniz Tekrar Deneyin"<<endl;
                    cin.clear();
                    cin.ignore(10000,'\n');
                }else{
                    break;
                }
                
            }

        if (secim == dogruBirikinti) {
            cout << "Tebrikler! Dogru su birikintisini buldun.\n\n";
            break; // Dogru su birikintisini bulduysa döngüyü kir
        } else {
            cout << "Yanlis su birikintisini sectin. Lutfen tekrar dene.\n\n";
            hatasayisi++; // Yanlis cevap aldigimizda hatasayisi'ni arttir
        }
    } while (hatasayisi < 100000);

    // Dogru su birikintisini bulduysa senaryonun geri kalanini yazdir
    cout << "Suyu icip kendine geldiginde adeta gozu acilir.\n"
         << "Onceden fark etmedigi seyleri simdi fark etmeye baslar...\n"
         << "Aslinda en basindan beri suyun yaninda duran kahverengi sandik gorur ve anahtar girisi oldugunu fark eder.\n"
         << "Cantasina koydugu anahtari cikartip uyup uymayacagini merak eder ve anahtari sandigin kilit yerine sokar.\n"
         << "Anahtar sandigin kilidini acar. Aradigi seyin icinde oldugunu fark eder.\n"
         << "Sandigin icinden uzerinde Saturn imgesi bulunan kostekli saati bulur.\n"
         << "Esyayi buldugu icin cok mutlu olur cunku hem susuz kalmanin verdigi yorgunluk hem de gunesin tepede olusu onu cok bunaltmistir.\n"
         << "Ve bir an once bu odadan gitmek ister...\n"
         << "Kostekli saati actigi an portal belirir ve diger odaya gecebilirsin.\n";
    

    return hatasayisi;
}

#endif