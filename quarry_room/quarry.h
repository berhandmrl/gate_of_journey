#ifndef QUARRY_H
#define QUARRY_H

#include <iostream>
#include <chrono>
#include <thread>
#include <conio.h>
#include<string>
using namespace std;
int aaaaaaaaaaaa = 0;

void aa1(){
    cout<<"Bulut ve kedi bir anda kendini magaranin onunde bulur. Etrafta sadece daglik kayalik yerler vardir. Gidecek baska yer olmadigini fark ederler. Sonra Boncuk magaranin icine dogru ilerler ve Bulut da onu takip etmeye baslar. Artik ikisi demagaranin icine girmistir."
    <<"Icerisi hem karanlik hem de pusludur. Bulut, ""Kimse var mi?"" diye bagirdiginda magaranin girisi sesten etkilenir ve buyuk bir gurultuyle coker. Ikisi de cok korkar cunku her yer kapkaranlik olur. Eskiden biraz da olsa gorunen magaranin ici simdi tamamen zifiri karanlik olmustur."
    <<"Bulut titremeye baslar. Boncuk, Bulut'u sakinlestirmeye calisir. Orada beklerken nefes almakta zorlanmaya baslarlar ve ilerlemek zorunda kaldiklarini fark ederler.Yavas\nyavas dagli tasli engebeli yollarda ilerlerler.Ilerlerken sans eseri el feneri bulurlar ve hemen onu alirlar." 
    <<"El fenerini actiklari anda birden yarasalar ucusuverir, egilmek zorunda kalirlar"<<endl;
}
void bb1(){
    cout<<"Egildiklerinde yarasalarin ustlerinden gectiklerini gorurler. Ilerlemek zorunda olan Bulut ve Boncuk irkile irkile yurumeye devam ederler. Ilerlerken birden ileride ne gorsunler, rayin ustunde ustu acik kucuk eski kahverengi bir madenci vagonu duruyor. Vagona yaklastiklarinda baska" 
    "gidebilecekleri bir yol goremezler. Geriye donme sanslarinin da olmadigini dusunurler cunku orada oksijen seviyesi asiri dusuktur nefes alamazlar . Sonra vagona binerler.Ani bir frenle Bulut\nvagonun frenini ceker, ""carrttt"" diye. Vagondan indikten sonra ilerlemeye devam ederler. Bir de ne gorsunler," 
    "yolun sonuna gelmislerdir, cikis kapalidir. Bulut ne yapacagini dusunurken, kapali duvarin yan taraflarinda TNT'lerin oldugunu\nfark eder. Buraya onceden madencilerin geldigini anlar. O yuzden el fenerinin sans eseri olmadigini dusunur ve duvarin yanindaki TNT leri alip cantasina atar "<<endl;

}
void bb1else(){
     cout<<"Ilerlemek zorunda olan Bulut ve Boncuk irkile irkile yurumeye devam ederler. Ilerlerken birden ileride ne gorsunler, rayin ustunde ustu acik kucuk eski kahverengi bir madenci vagonu duruyor. Vagona yaklastiklarinda baska" 
    "gidebilecekleri bir yol goremezler. Geriye donme sanslarinin da olmadigini dusunurler cunku orada oksijen seviyesi asiri dusuktur nefes alamazlar . Sonra vagona binerler.Ani bir frenle Bulut\nvagonun frenini ceker, ""carrttt"" diye. Vagondan indikten sonra ilerlemeye devam ederler. Bir de ne gorsunler," 
    "yolun sonuna gelmislerdir, cikis kapalidir. Bulut ne yapacagini dusunurken, kapali duvarin yan taraflarinda TNT'lerin oldugunu\nfark eder. Buraya onceden madencilerin geldigini anlar. O yuzden el fenerinin sans eseri olmadigini dusunur ve duvarin yanindaki TNT leri alip cantasina atar "<<endl;

}
void Canta(){
    cout<<"Dinamiti cantaya koymak icin 1'e basiniz."<<endl;
    int sayi;
    while (true)
    {
       cin>>sayi;
       if (cin.fail())
       {
         cout<<"Dinamiti Almadan Gidemezsin!!!!"<<endl;
         cin.clear();
         cin.ignore(10000,'\n');
       }else{
        break;
       }
       
    }
    cout<<"Artik maden vagonunun gidebilecegi bir yol kalmamistir. Hatta sadece vagonun degil cocuk ve kedinin de gidebilecegi bir yol yoktur. Iki secenek vardir: ya yolu geri doneceklerdir. Ya da TNT ile baska bir cikis yolu arayacaklardir. "<<endl;
}
void tusaBasma() {
    int sayac = 0;
    int sure = 4000; // 4 saniye (4000 * 40 ms = 4 saniye)
    cout << "Egilmek icin E tusuna 4 saniye basili tut yoksa yarasalar sana carpacak.Eger elini tustan cekersen yine carpacak!!! Ve 10 canin azalacak!!!" << endl;
    cout << "Tusa basdiginde sayac acilacak." << endl;

    auto baslangic = chrono::steady_clock::now(); // Baslangic zamani

    while (true) {
        if (_kbhit()) {
            char tus = _getch();
            if (tus == 'e' || tus == 'E') {
                sayac++;
                sure--;
                auto gecenSure = chrono::duration_cast<chrono::seconds>(chrono::steady_clock::now() - baslangic).count();
                cout << "\rGecen sure: " << gecenSure << " saniye" << flush;
                if (sayac >= 90) {
                    cout<<endl;
                    bb1();
                    break;
                }
            } else {
                sayac = 0;
                sure = 4000; 
            }
        } else {
            sayac = 0;
            sure -= 40; 
            if (sure <= 0) {
                cout<<endl;
                cout << "Egilmediginiz icin caniniz 10 azaldi!!!" << endl;
                aaaaaaaaaaaa++;
                bb1else();
                break; 
            }
        }
        this_thread::sleep_for(chrono::milliseconds(40)); 
    }
}
void donme(){
    cout<<"Bulut onundeki duvara bakar ve tnt ile duvari patlatsa bile bir ise yaramayacagini dusunur. cunku zaten madenciler buraya kadar gelmistir ama bir yere cikamamislardir. Bu yuzden de geriye donmenin daha mantikli olacagina karar verir."
    "Kediile beraber vagona binerler ve geriye donmeye baslarlar.Geri donerken yolda el fenerinin pili bitmeye baslar ve en sonunda karanlikta kalirlar. Gittikce oksijen seviyesi de duser.Orada boncuk ve bulut bayilir kalir.Oksijen azligindan dolayi 10 can daha kaybettiniz!!!"
    "Uyandiklarinda kendilerini baska bir oda da bulurlar...."<<endl;
}
void tnt(){
    cout<<"Geri donmek icin zaman kalmadigini fark ederler ve yan tarafta duran tntleri alip onlerinde duran duvari patlatmaya karar verirler. Tnt leri duvarin onune yerlestirirler. cantalarindan cikardiklari ates ile tnt yi atesleyip oradaki\nduvarin "
   " arkasina saklanirlar. Ates tnt ye ulasir ve tnt patlar. cok siddetli bir ses cikar. onlerindeki duvar yikilir. Karsilarinda tam da aradiklari seyi gorurler. uzerinde Saturn imgesi olan bir maden kazmasi bulurlar. Bunu da\nbulduklari anda gecit acilir. Sira diger odadir. "<<endl;
}

int startQuarryGame(){
    aa1();
    tusaBasma();
    Canta();
    int secim;
    cout<<"Hangi Yoldan gidecegini tercih et.Sectigin yola yapacagin seyler degisecek bunun farkinda ol..."<<endl;
    cout<<"(1)Geri Don\n"
    "(2)Yolu Patlat\n";
    while (1)
    {
        while (true)
    {
        cin>>secim;
        if (cin.fail())
        {
            cout<<"Hatali Giris Yaptiniz Tekrar Deneyin!!!"<<endl;
            cin.clear();
            cin.ignore(10000,'\n');
        }else{
            break;
        }
        
    } 
        if (secim==1)
        {
            donme();
            break;
        }else if (secim==2)
        {
            tnt();
        }else{
            cout<<"Yanlis secim yaptiniz tekrar giriniz!!!"<<endl;
            break;
        }
    }  
    return aaaaaaaaaaaa;
}


#endif