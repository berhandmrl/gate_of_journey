#ifndef GRAVITY_H
#define GRAVITY_H

#include<iostream>
#include<string>
using namespace std;

void gs1(){
cout<<"Bol tasli olan bu odaya dusmek biraz zorlu olmustur. Yerdeki sivri taslarin ustune dusmek Bulut'un canini bir hayli acitmistir. Kolunda bir islaklik hisseder. Ne olduguna baktiginda kedinin kanayan kolunu yaladigini gorur. O anin\npsikolojisi ile kolunun kanadigini bile hissetmemistir."
"Koluna sarabilecek bir sey var mi diye etrafina  bakinir fakat dustukleri yerde bolca tastan , biraz calidan baska hicbir sey yoktur. Burada bir sey bulamayinca cantasindaki\nmalzemelerin onun isini  gorebilecegini dusunur. Elinde olanlara bakar . Icerisinden sargi bezini alir"<<endl;
cout<<"Sargi Bezini Almak Icin 'a' ya basiniz:"<<endl;
char a='\0';
tolower(a);
 while (true) {
        cin >> a;
        // Fazladan girilen karakterleri kontrol et
        if (cin.peek() == '\n') { // Yalnizca tek bir karakter girildi mi kontrol et
            if (a == 'a' || a=='A') { // Girilen karakter 'a' mi kontrol et
                break; // Evetse donguden cik
            } else {
                cout << "Hatali Giris Yaptiniz Tekrar Deneyin!!!" << endl;
            }
        } else {
            // Kullanici birden fazla karakter girdi
            cout << "Hatali Giris Yaptiniz Tekrar Deneyin!!!" << endl;
            cin.clear(); // Hata durumunu temizle
            cin.ignore(10000, '\n'); // Tamponu temizle
        }
    }
    cout<<"makasla keser ve yarasi icin kullanir. Dusmenin verdigi hasar onu cok halsizlestirmistir. Bu yuzden cantasindaki enerji icecegini de icme karari alir"<<endl;
    cout<<"Icmek icin e'ye basiniz:"<<endl;
    char e='\0';
    tolower(e);
 while (true) {
        cin >> e;
        // Fazladan girilen karakterleri kontrol et
        if (cin.peek() == '\n') { // Yalnizca tek bir karakter girildi mi kontrol et
            if (e == 'e' || e=='E') { // Girilen karakter 'a' mi kontrol et
                break; // Evetse donguden cik
            } else {
                cout << "Hatali Giris Yaptiniz Tekrar Deneyin!!!" << endl;
            }
        } else {
            // Kullanici birden fazla karakter girdi
            cout << "Hatali Giris Yaptiniz Tekrar Deneyin!!!" << endl;
            cin.clear(); // Hata durumunu temizle
            cin.ignore(10000, '\n'); // Tamponu temizle
        }
    }


}
void gs2(){
    cout<<"ve icecegi ictikten sonra enerjisini toplar. Kedinin yaninda olmadigini fark eder ve ismiyle ona seslenerek arar. Boncuk ismini duydugu gibi caliliklarin arasindan Bulut'a gorunur. Bulut kedinin yanina gider ve agziyla ona cali meyvesi\ntopladigini gorur. Bu kirmizi meyve Bulutlarin evininin bahcesinde olan bir meyvedir. Kedi topladigi meyveyi yere birakir ve Bulut onlari alip yerken boyle bir arkadas"
     "sectigi icin hem cok duygulanir hem de cok mutlu olur. Doymadiklari\nicin biraz daha meyve toplarken Bulut'un gozune bir yansima carpar. Yansimanin nereden geldigini anlamak icin daha dikkatli bir sekilde etrafina bakinmaya baslar. Hemen biraz ilerideki calilarin arasinda parlayan cismi gorurler. Bu bir\nanahtardir ve de uzerindeki Saturn simgesi bu odadan cikmaya yarayacak esyanin tam kendisi oldugunu kanitlar."
     "Fakat nereyi acacagini hic bilmiyorlardir. Nereye uyabilecegini arastirirlarken gecitten dustukleri yere geri gelirler. Kedi\nbirden orada bir seye odak kesilir. Bulut ne oldugunu anlamak icin kedinin baktigi yere dogru bakar ve orada bir kus gorur. Kedi, acligini yakalamayi planladigi bir kusla gidermeyi dusunuyordur. Boncuk'un  beceriksiz davranisi sonucunda kus kacar ve tepeye gider. Daha once kafalarini  kaldirip" 
     "yukariya bakmadiklari icin kusun gittigi tepeyi gormemislerdir. Aslinda Boncuk'un bu basarisiz denemesi onlara cikis kapisinin nerede oldugunu gostermistir. Geriye kalan tek sorun oraya nasil cikacaklaridir. Bulut'un elindeki anahtar Boncuk'un baska bir kus avlama denemesinin sonucu anahtara carpmasiyla yere ters bir sekilde duser. Bulut kediye hic yardimci olmadigi icin cok sinirlenir ama anahtari almak icin\negildiginde" 
     " arkasindaki daha once fark etmedigi kucuk kirmizi dugmeyi gorur. Aslinda Boncuk bilmeden ona cok yardimci olmustur. O dugmeye bastiginda ise bir anda her sey onlar gibi ucmaya baslar. Yer cekimi sifirlanmistir.Artik o\ncikamayacaklarini dusundukleri tepenin yani kapinin tam onune gelmislerdir. Anahtari kapinin deligine sokmalari ile kapi acilir ve gecit orada gorunur. Kapidan gecerek bu bolumu de bitirirler ve diger odaya isinlanirlar."<<endl;
}
int startGravityGame(){
    gs1();
    gs2();
    return 0;
}

#endif