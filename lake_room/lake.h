#ifndef LAKE_H
#define LAKE_H

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int hata = 0;

class Esya {
public:
    string esyalar;
    Esya(){}
    Esya(string a): esyalar(a) {}
};

void soz1() {
    cout << "Yemyesil agaclarin cevreledigi, hayvan sesleri disinda baska bir sesin duyulmadigi, gokyuzu ve agaclarin yansimasinin oldugu koskocaman bir goletin yaninda bulur kendini. \nEtrafina bakinmaya baslar. cevrede eskiden yapilan kamp izlerini gorur ve baskalarinin da olabilecegine umutlanir.\n" 
        << "Gozun cevresinde gezinmeye baslar. Uzakta buyuk ve yesil bir kamp gorur. Oraya dogru gider ve cadirdaki uc kisiyi gorur. (Deniz, Batu, Berhan). Bulut'un karni cok acikmistir bu sebeple onlara sorar.\n"
        << "-Merhaba ben bulut bu ormanda mahsur kaldim ve karnim cok acikti. Acaba yemeginiz var mi?\n"
        << "-Deniz: Yok be abim biz de aciz su anda. Balik tutmak icin geldik.\n" 
        << "-Bulut: Peki ya balik tutacak oltaniz hazir mi?\n"
        << "-Batu: Malzemeleri topluyorduk cubuk eksik kaldi. Bize cubuk bulabilir misin?\n";
}

void esyaBulma(Esya k[]) {
    k[0] = Esya("(1) Cubuk");
    k[1] = Esya("(2) Cam Sise");
    k[2] = Esya("(3) Metal Sise");
    k[3] = Esya("(4) Ag");
}

void dogruSecim(Esya k[]) {
    
    int secim;
    cout << "Deniz Kenarina gittin ve onunde malzemeler var. Arkadaslarin icin dogru malzemeyi sec:" << endl;
    while(true){
        for (int i = 0; i < 4; i++) {
        cout << k[i].esyalar << endl;
    }
    cout << "Seciminizi yapin (1-4):\n";
    while (true)
    {
        cin>>secim;
        if (cin.fail())
        {
            cout<<"Hatali Giris Yaptiniz Tekrar Deneyin!!"<<endl;
            cin.clear();
            cin.ignore(10000,'\n');
        }else{
            break;
        }
        
    } 
    if (secim == 1) {
        cout << "Dogru esyayi aldiniz ve arkadaslarinin yanina gidiyorsunuz." << endl;
        break;
    } else {
        cout << "Bu ihtiyaciniz olan esya degil, lutfen tekrar deneyin." << endl;
        hata++;
        continue;
    }
    }
}

void oltaYapma() {
    cout << "Arkadaslarinin yanina geldin simdi cantanizdaki esyalarla oltayi yapin" << endl;
    string esya[5] = { "(1) Misina","(2) Cubuk","(3) Kanca","(4) Tas","(5) Bicak" };
    int secim, sayac = 0;
    bool secildi[5] = { false }; // Her eşyanın seçilip seçilmediğini takip etmek için bir dizi

    while (true) {
        for (int i = 0; i < 5; i++) {
            cout << esya[i] << endl;
        }

        cout << "Oltayi yapmak icin ihtiyaciniz olan 3 adet esyayi secin." << endl;
        for (int i = 0; i < 3; i++) {
            while (true)
            {
                cin>>secim;
                if (cin.fail())
                {
                    cout<<"Hatali Giris yaptiniz Tekrar Deneyin!!!"<<endl;
                    cin.clear();
                    cin.ignore(10000,'\n');
                }else{
                    break;
                }
                
            }
            // Kullanıcının girdiği seçimin doğru bir seçim olduğunu kontrol edin
            if (secim >= 1 && secim <= 5 && !secildi[secim - 1]) {
                if(secim == 1 || secim == 2 || secim == 3){
                    sayac++;
                secildi[secim - 1] = true;
                }
            }
            else {
                cout << "Gecersiz secim veya zaten secilmis esya! Tekrar deneyin." << endl;
                break; // Hatalı giriş olduğunda döngüyü kır ve baştan başla
            }
        }

        if (sayac == 3) {
            cout << "Oltayi hazirlamak icin butun malzemeleri dogru sectiniz. Olta hazirlandi ve denize atildi." << endl;
            break;
        }
        else {
            cout << "Oltayi yapmak icin uygun esyalari secmediniz. Tekrar deneyin!!!" << endl;
            hata++;
            sayac = 0;
            // Seçilen eşyaları sıfırla
            for (int i = 0; i < 5; i++) {
                secildi[i] = false;
            }
        }
    }
}

/*void oltaYapma(){
    cout<<"Arkadaslarinin yanina geldin simdi cantanizdaki esyalarla oltayi yapin"<<endl;
    string esya[5]={"(1) Misina","(2) Cubuk","(3) Kanca","(4) Tas","(5) Bicak"};
    int secim,sayac=0;
    while (true)
    {
        for (int i = 0; i <5; i++)
        {
            cout<<esya[i]<<endl;
        }
        cout<<"Oltayi yapmak icin ihtiyaciniz olan 3 adet esyayi secin."<<endl;
        for (int i = 0; i <3; i++)
        {
            cin>>secim;
            if (secim==1) sayac++;
            if (secim==2) sayac++;
            if (secim==3) sayac++;
        }
        if (sayac==3)
        {
            cout<<"Oltayi hazirlamak icin butun malzemeleri dogru sectiniz.Olta hazirlandi ve denize atildi."<<endl;
            break;
        }else{
            cout<<"Oltayi yapmak icin esyalari dogru secmediniz.Tekrar deneyin!!!"<<endl;
            sayac = 0;
            hata++;
            continue;
        }
        
    }   
}*/

void soz2(){
    cout<<"Baligi tutarken kampcilar ve bulut arasinda guzel diyaloglar gecer.\n" 
        "-Batu: Sen buralara nirden geldin?\n"
        "-Bulut: Yanlislikla bir oyunun icine dustum ve cikamiyorum. Bu oyundan kurtulmak icin 25 tane odadan da kurtulmam gerekiyor.\n"
        "-Berhan: Sana ne lazim peki suan da.\n"
        "-Bulut: cikabilmem icin uzerinde Saturn gezegeni bulunan bir esya bulmam gerekiyor.Ama suanda cok acim oncelikle yemek yemek istiyorum.\n"
        "Tam sohbetin ortasinda oltanin ipi gerilir. Bir balik oltaya takilmistir. Yavas yavas ipi cekerler ve  kocaman isil isil lacivert govdesi olan kirmizi kuyruklu bir balik tutarlar.\n"
        "Isinmak icin etraftan topladiklari odunlarla zar zor yakilan ates, baligi pisirmek icin  hazirdir. Bulutun kampci cantasinda olan caki ile baligi temizlerler ve  icerisinde bembeyaz bir inci ciktigini gorurler.\nBulut bunu gorunce cok sasirir cunku tam aradigi sey olan Saturn isareti olan inciyi bulur.\n" 
        "Gitmesi icin geri tek kalan sey ise o inciden kolye yapip boynuna takmasidir. Kampcilarla birlikte baligi yedikten sonra donmeye hazirdir kolyeyi yapip boynuna taktigi anda karsisinda bir kapi belirir kapidan gecmeye calisir fakat\ngecemez .Karsisina gelen bilmeceyi cozmesi gerekir.\n"<<endl;
}

void soru(){
    string cevap_c;
    cout<<"Bulut'un karsisina gelen bilmece sudur:"<<endl;
    string bilmece = "Yukari cikar, asagi iner, ev ev dolasir, iz birakmaz. Nedir?";
    cout<<bilmece<<endl;
    string cevap="duman";
    cin >> cevap_c;
    transform(cevap_c.begin(),cevap_c.end(),cevap_c.begin(), :: tolower);
    while (cevap_c !=cevap)
    {
        cout<<"Hatali tahmin iyi dusun!!!"<<endl;
        hata++;
        cin>>cevap_c;
    }
    cout<<"Bulut cevabi dogru bildi ve bir sonraki portala gecis yapti..."<<endl;
}

int startLakeGame(){
    soz1();
    Esya esyalar1[4];
    esyaBulma(esyalar1);
    dogruSecim(esyalar1);
    oltaYapma();
    soz2();
    soru();
    return hata;
}

#endif