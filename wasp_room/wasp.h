#ifndef WASP_H
#define WASP_H

#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
int ac=0;

const int HARITA_BOYUTU = 5;
const int SURE_LIMI = 10; // cocugun evine ulasmasi icin sure siniri (saniye cinsinden)

// Haritayi ekrana yazdiran fonksiyon
void haritayiYazdir(char harita[HARITA_BOYUTU][HARITA_BOYUTU], int boyut)
{
    for (int y = 0; y < boyut; y++)
    {
        for (int x = 0; x < boyut; x++)
        {
            cout << harita[y][x] << " ";
        }
        cout << endl;
    }
}
void sg1(){
    cout<<"Bulut ve boncuk portaldan gectikleri an yemyesil bir alana duserler. Burasi yayla gibi bir yerdir. cevre tamamen yemyesildir, birden cok cicek turuyle bezenmis bu yesillik etrafa mis kokular yayiyordur. Mis gibi doganin\nkokusunu iclerine cekerler ve yorulduklari icin cimlerin ustune yatip bu ortamin tadini cikartmak isterler." 
    "Bir sure cimlerin uzerinde huzurlu huzurlu yatip dinlenirler. Hafif hafif esen ruzgar guzel bir mayisiklik yaratir.\nBulut'un uykusu gelir ve kisa bir sureligine uykuya dalar. Ruyasinda annesini gorur, onun gunes isiginda parlayan guzel saclarini animsar. Bulut annesini cok ozlemistir. Bu ozlem onun buradan kurtulma istegini gittikce\narttirir."
    "Daha sonra kulagina gelen bir vizilti onu tatli uykusundan uyandirir. Viziltinin kaynaginin bir ari oldugunu anlar. Burada ari olmasi cok dogaldir cunku birbirinden guzel bir suru cicek vardir . Ama gozlerini actigi zamanarinin sadece bir tane olmadigini fark eder. Bir kovan dolusu ari tepesindedir. Megerse Bulut uyurken boncuk yakinlarda duran ari kovaniyla" 
    "ugrasmis ve arilari bir hayli sinirlendirmistir. cok sinirlenen arilar onu\nkovalamaya baslamistir. Tabi boncuk da Bulut'un yanina sigindigi icin Bulut'un etrafini arilar sarmistir. Ne yapacaklarini bilemezler ve bir o tarafa bir bu tarafa kosusturmaya baslarlar. Boncuk ilerideki evi fark eder.\nBulut'a soyler ve oraya dogru kosmaya baslarlar. Eger 10 saniye icinde"
    "eve ulasirlarsa ikisine de bir sey olmaz ama gec kalirlarsa arilar onlari sokacaktir."<<endl;
}
void sg2(){
    cout<<"Evin kapisindan iceriye kendilerini zor atarlar. Kacmaktan ikisinin de nefesi kesilmistir. Biraz nefeslendikten sonra evin icinde dolasmaya baslarlar. Bulut yururken ayagi yerdeki bir seye takilir ve duser. Ayaga kalkip\ntoparlandiginda yerde ne olduguna donup bakar. Yerde bir kapi tutamaci gibi bir sey vardir. Onu tutup yerdeki kapiyi actiginda gizli bir yer alti odasi oldugunu fark eder."
    "Burada hem bir oda hem de bir tunel vardir. Tunelden\ndevam edebilmek icin onlerinde demirden bir kapi daha vardir. Bu kapinin uzerinde bir asma kilit vardir ve acilmaz. Asma kilidi acmaya calisirken uzerindeki Saturn simgesini fark ederler. Bir an once buradan kurtulmak icin\nanahtaribulup asma kilidi acmalari gerekiyordur Odanin icinde anahtar ararlar. Ve sonunda anahtari bulurlar. Asma kilidi bulduklari anahtar ile acarlar." 
    "Asma kilidi de cantalarina atip kapidan gecerler. Gectikleri an da diger odada bulurlar kendilerini."<<endl;
}
void game(){
    char harita[HARITA_BOYUTU][HARITA_BOYUTU] = {
        {'.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.'}};

    // Engellerin konumlari
    harita[0][HARITA_BOYUTU - 1] = 'X'; // Sag ust kose
    harita[HARITA_BOYUTU - 1][0] = 'X'; // Sol alt kose

    cout << "Arilar tarafindan kovalaniyorsunuz! Ev koordinatlarina ulasmaya calisin." << endl;

    // Oyuncunun baslangic konumu (kovanin yaninda)
    int cocukX = 0;
    int cocukY = 0;

    // Bal petegi alindi mi kontrolu
    bool balPetegiAlindi = false;

    // Oyun dongusu
    auto baslangicZamani = chrono::steady_clock::now();
    while (true)
    {
        // Sure kontrolu
        auto simdikiZaman = chrono::steady_clock::now();
        int gecenSure = chrono::duration_cast<chrono::seconds>(simdikiZaman - baslangicZamani).count();
        if (gecenSure >= SURE_LIMI)
        {
            cout << "Zamaminda Kacamadiginiz Icin Arilar Sizi Soktular Ve 10 Canininiz Azalacak!!!" << endl;
            cout<<"Ama sokulmalarina ragmen sonunda eve varirlar."<<endl;
            sg2();
            ac++;
            break;
        }

        // Haritayi guncelle ve yazdir
        system("cls"); // Linux/Unix icin
        // system("cls"); // Windows icin
        for (int i = 0; i < HARITA_BOYUTU; ++i)
        {
            for (int j = 0; j < HARITA_BOYUTU; ++j)
            {
                if (harita[i][j] == 'C')
                {
                    harita[i][j] = '.';
                }
            }
        }
        if (!balPetegiAlindi)
        {
            harita[0][0] = 'K'; // Kovan
        }
        harita[cocukY][cocukX] = 'C';
        harita[HARITA_BOYUTU - 1][HARITA_BOYUTU - 1] = 'E';
        haritayiYazdir(harita, HARITA_BOYUTU);

       balPetegiAlindi=true;
        // Yon secimi sadece bal petegi alindiktan sonra
        if (balPetegiAlindi)
        {
            char yon='\0';
            cout << "Yon secin (w: yukari, a: sola, s: asagi, d: saga): ";
        while (true)
        {
        cout << "Yon secin (w: yukari, a: sola, s: asagi, d: saga): ";
        cin>>yon;
        if (cin.peek()=='\n')
        {
            if (yon=='a'|| yon=='A')
            {
                break;
            }else if (yon=='s'|| yon=='S')
            {
                break;
            }else if (yon=='d'|| yon=='D')
            {
                break;
            }else if (yon=='w'|| yon=='W')
            {
                break;
            }else{
                cout<<"Hatali Yon Girdiniz Tekrar Deneyin!!!!"<<endl;
            }       
        }else{
            cout<<"Hatali Yon Girdiniz Tekrar Deneyin!!!"<<endl;
            cin.clear();
            cin.ignore(100000,'\n');
        }
        }
            switch (yon)
            {
            case 'w':
                if (cocukY > 0)
                    cocukY--;
                break;
            case 'a':
                if (cocukX > 0)
                    cocukX--;
                break;
            case 's':
                if (cocukY < HARITA_BOYUTU - 1)
                    cocukY++;
                break;
            case 'd':
                if (cocukX < HARITA_BOYUTU - 1)
                    cocukX++;
                break;
            default:
                cout << "Gecersiz yon! Tekrar deneyin." << endl;
                continue;
            }

            // Arilarla carpisma kontrolu (kovanin yani)
            if (cocukX == 0 && cocukY == 0)
            {
                cout << "Arilar sizi yakaladi ve soktular! 10 canininiz azalacak!!!!" << endl;
                ac++;
                break;
            }

            // Evde olma kontrolu
            if (cocukX == HARITA_BOYUTU - 1 && cocukY == HARITA_BOYUTU - 1)
            {
                cout << "Ve sonunda eve varirlar."<< endl;
                sg2();
                break;
            }

            // Engel kontrolu
            if (harita[cocukY][cocukX] == 'X')
            {
                cout << "Engel var! Farkli bir yol deneyin." << endl;
                continue;
            }
        }

        // Kucuk bir bekleme suresi ekleyelim, oyunun akisini duzgun gormek icin
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}

int startWaspGame()
{
    sg1();
    cout<<"Kacmaya Baslamak Icin 'k' tusuna basin"<<endl;
    char k='\0';
    while (true)
    {
        cin>>k;
        if (cin.peek()=='\n')
        {
            if (k=='k' || k=='K')
            {
                break;
                break;
            }else{
                cout<<"hatali Giris Yaptin Tekrar Dene!!!"<<endl;
            }      
        }else{
            cout<<"Hatali Giris Yaptiniz Tekrar Deneyin!!!"<<endl;
            cin.clear();
            cin.ignore(100000,'\n');
        }
    }
    game();
    return ac;
}

#endif