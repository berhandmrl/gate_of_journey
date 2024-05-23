#ifndef HORROR_H
#define HORROR_H
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int h = 0; 

void hj1(){
    cout<<"Gecitten gectikleri anda kendilerini kapkaranlik bir odada bulurlar . Etrafta ne oldugu gozukmuyordur. Sonra bir anda yukaridan hoparlorden bir ses gelir.\n" 
"-Ses: suanda bir korku evinin icerisindesiniz anabellanin sirriniz cozerseniz buradan\nkurtulabilirsiniz. Buradan cikmanin tek cozumu budur."
"Bulut ve boncuk cok korkmustur. cunku Bulut karanliktan cok korkan bir cocuktur ayrica anabella da kimdir? Buradan kurtulmak icin bir an once ise koyulmaya baslarlar. Bu korku evi 3\nodadan olusmaktadir.\nEn son odaya kadar sifreleri cozmeleri gerekmektedir." 
"Karanlikta beliren serit seklinde olan kirmizi isiklari takip ederek birinci odaya giderler. Bu odada anabellanin hikayesi anlatilir. Anabella zengin bir ailenin cocuguymus ve bir andaolu bulunmus. O gunden beri de onun odasindan garip sesler geliyormus ve bu" 
"odadaki tabut anabellanin tabutuymus.Tabutun tam yanindaki oyuncak bebek ise anabellanin kendisine cok benzeyen oyuncak bebegiymis. Bu hikayeyi duydukca daha da\ncok gerilirler. Odada onlardan istenen gorev tabutun yaninda duran oyuncak bebegi almalari olur. Bir" 
"tabutla ayni odada durmak bile cok korkuncken yanina gitmek cok daha korkunc bir deneyimdir. Aralarinda karar verirler ve boncuk oyuncak bebegi almaya gider. Tam boncuk gittigi an tabutun icinden zebanis onu korkutur. Kosarak bebegi almis bir sekilde Bulut'un yanina doner." 
"Yukaridan gelen ses bu odada islerinin bittigini soyler.  Ve arkada kalmayin diyerek diger odaya\ngonderirler. Ikinci odadadirlar artik. Bu oda anabellanin annesinin bu seslerden deliye donup\nkendini astigi odadir. Cidden tuyler urpertici bir ortami olan bu odada duvarlarda 'miss me'" 
"yazisi ve sayilar yazmaktadir. Yapmalari gereken sey sifreyi cozmektir. sifre duvardaki karisik sayilari belli bir oruntuye gore siraya dizmektir.Duvarda yazan sayilar 2 6 11 15 29 65 99 137  bunlardir. simdi sira Bulut ve Boncugun bu soruyu cozmesindedir."<<endl;
}
void hj2(){
    cout<<"Sonunda bu oyundan da basariyla gecerler ve sira son odadadir. Tam son oda icin tunelden gecerken zebanislerden birisi boncugu kacirir. Bulut'un bu odadaki gorevi aslinda boncugu kurtarmaktir. Yukaridan gelen ses Bulut'un en bastaki\nodaya donup tabutun icindekikagidi almasi" 
    "gerektigini soylemektedir.Eger kagidi alip sifreyi cozerse boncugu kurtarabilecektir. Bu cok zorlu bir gorevdir. Hem karanlik olmasi hem de tek basina olmasi onu cok korkutuyordur ama bunu\narkadasi icin yapmak zorundadir. Butun cesaretini\ntoplayarak birinci odaya dogru kosar. Odaya girdigi" 
    "an zebaniler is basindadir. Onu korkutmak icin buyuk bir caba sarf ediyorlardir. Ama Bulut arkadasi icin cok cesur bir sekilde tabutun icindenkagidi alir (alma komutu) ve kosarak ucuncu odaya geri doner.\nKagidin icini acar ve okumaya baslar.\n\n"
    "Gizemli koridorlarda dolasanlar kimdir,\n"
    "Izleri takip eden, karanlikta kaybolanlar,\n"
    "Zihinlerde yankilanan sirlarin pesinde,\n"
    "Esrarengiz odalarda ne ararlar,\n"
    "Maceraya atilan cesurlar,kimlerdir?\n"
    "Bu yaziyi okudugunda hicbir sey anlamaz. cunku icindeki yazi bir sifreye hic de benzemiyordur. Sonra bir sure dusunur. Yazi duzenine ve harflere iyice odaklanir. En sonunda bir anda yazinin bas harfleri dikkatini ceker.\nAslinda bu bir akrostistir. Butun\ndizelerin bas harflerini birlestirince bir kelime ortaya cikar bu bir sifredir. Hemen bu sifreyi yukaridan gelen sese soyler."<<endl;
}
void hj3(){
    cout<<"Dogru bilmistir ve boncugun oldugu odaya giden kapi acilir. Boncuk, Bulut'u gorunce cok sevinir. Artik oyunu bitirmislerdir. Son bir kez daha yukaridan bir ses gelir.\nBu ses aradiklari esyanin oyuncak bebek oldugunu soyler. Bulut karanliktan ve korkudan bunu hic fark etmemistir. Korku evinin cikis kapisina ilerlerler ve kapidan gectikleri anda diger odaya isinlanirlar."<<endl;
}
void oyun1(){
    int sayilar[8]={2,6,11,15,29,65,99,137};
    int cevap[5]={2,11,29,65,137};
    int sayac=0;
    while (true)
    {
        cout<<"Duvardaki sayilar:"<<endl;
    for (int i = 0; i<8; i++)
    {
        cout<<sayilar[i]<<" ";
    }
    int cevap_i[5];
    cout<<"Cevabinizi giriniz:"<<endl;
    for (int i = 0; i <5; i++)
    {
       while (true)
       {
         cin>>cevap_i[i];
         if (cin.fail())
         {
            cout<<"Hatali Giris Hepsini Tekrar Giriniz!!!!!"<<endl;
            cin.clear();
            cin.ignore();
         }else{
            break;

         }
       }
       
    }
    for (int i = 0; i <5; i++)
    {
        if (cevap_i[i]==cevap[i])
        {
            sayac++;
        }
    }
    
    if (sayac==5)
    {
        break;
    }else{
        cout<<"Yanlis Cevap Tekrar Dene!!!!!"<<endl;
        sayac=0;
        h++;
    }
    }  
}
void oyun2(){
    string medin="Gizemli koridorlarda dolasanlar kimdir,\n"
    "Izleri takip eden, karanlikta kaybolanlar,\n"
    "Zihinlerde yankilanan sirlarin pesinde,\n"
    "Esrarengiz odalarda ne ararlar,\n"
    "Maceraya atilan cesurlar, kimlerdir?\n";
    string cevap3="gizem";
    string cevap_c2;
    cout << medin;
    cout << "Cevabi iyi dusun her bilemediginde hayaletler gelip sana vuracak ve canini 2 azaltacaklar!!!"<<endl;
    cin >> cevap_c2;
    transform(cevap_c2.begin(),cevap_c2.end(),cevap_c2.begin(),::tolower);
    while (cevap_c2 !=cevap3)
    {
        cout<<"Yanlis Cevap verdin!!!! Tekrar deneyin\n";
        cin >> cevap_c2;
        h += 1; 
    } 
}

int startHorrorGame(){
    hj1();
    oyun1();
    hj2();
    cout<<"\n";
    oyun2();
    hj3();
    return h;
}

#endif