#ifndef PARKING_H
#define PARKING_H

#include <iostream>
#include <string>
using namespace std;

void laf1() {
    cout << "Bulut portaldan gectikten sonra kendini aniden bir odanin icinde buldu ama Boncuk yaninda degildi. Gozlerini ovusturarak odanin los isiklarinda etrafina bakindi. Odanin ici, karanligin ve tehlikenin bir araya gelmis hali gibiydi. Her\nkosedebeliren golgeler, atmosferi daha da karanliklastiriyordu. Masanin basinda oturan adamin yani sira, odanin etrafinda da takim elbiseli adamlar vardi.Sag ve sol koselerde sessizce bekleyen bu adamlar,\nciddi birer tehdit gibi duruyorlardi.";
    cout << "Masanin basindaki adam, Bulut'un dikkatini cekti. Elbisesinin sag ust kosesine ilistirdigi kirmizi gul, onun kim oldugunu belirtiyordu. Saclari geriye dogru taranmis, otoriter bir hava tasiyordu.\nArkasindaki pencere ise odanin tek isik kaynagiydi; sizan isik, odanin karanligini kismen aydinlatiyordu." << endl;
    cout << "Adam, yan donerek karsisindaki kisiyle konusmayi surdururken, elindeki kediye sevgi dolu bir bakis atti. Kedi, Boncuk'tu..." << endl;
    cout << "Bulut'un ici endiseyle doluydu. Boncuk'u kurtarmak icin bir plan yapmaliydi. Ama nasil? Odanin girisi masanin karsisindaydi ve sag ve sol koselerde bekleyen adamlar onun cikisini engelliyordu. Bir yol bulmaliydi, cunku Boncuk, bu\ntehlikeli adamin elinden kurtulmak icin her seyi yapacak ve Bulut bunu engellemek icin hicbir fedakarliktan kacinmayacakti. Bulut bir plan dusunurken adamlarin konusmalarina sahit oldu:" << endl;
    cout << "- Baba: \"Luca, gun icindeki randevular nedir?\"" << endl;
    cout << "- Koruma: \"Baba, uc onemli ziyaretimiz var. Ilk olarak, Senator Nihal'le guvenlik onlemlerini gozden gecirecegiz. Sonra, Baskan Busra'yla isbirligi firsatlarini ele alacagiz. Ve en son olarak, Kumarhanelerimizin Muduru\nBerhan'la gelir stratejilerini degerlendirecegiz.\"" << endl;
    cout << "- Baba: \"Her bir gorusmede, dogrudan amaclarina odaklanmalarini sagla. Senator Nihal, mahallemizin guvenligine nasil katki saglayabilir? Baskan Busra, bizimle isbirligi yapmanin ona ne tur avantajlar saglayabilecegini dusunsun.\nKumarhanelerimizin Muduru Berhan'a gelir stratejilerimizin neler oldugunu hatirlatalim. Ve hatirla Luca, hic kimse bizim zamanimizi bosa harcayamaz.\"" << endl;
    cout << "- Koruma: \"Anlasildi Baba, hemen duzenleyecegim.\"" << endl;
    cout << "Bulut bu konusmalari duyduktan sonra daha cok korkmustu ama Boncuk'u da kurtarip buradan gitmeliydiler, cesaretini toplayarak odanin karanligina dogru adim atti. Kalbi hizlica carpiyordu, ancak kararlilikla ilerlemeye devam etti." << endl;
    cout << "cunku o, Boncuk'u kurtarmak ve evine donmek icin her seyi yapmaya hazirdi. Baba'nin gozleri Bulut'a soguk bir bakisla donusurken, odadaki diger adamlarin da dikkatle Bulut'a baktigi fark edildi. Bulut, kararlilikla durdu ve icindeki\nendise ve korkuya ragmen, Boncuk'u kurtarmak icin orada duruyordu." << endl;
    cout<<"-Bulut:Lutfen, bana sadece Boncuk'u geri verin. Onun disinda size hicbir sorun cikarmayacagim."<<endl;
    cout << "Baba'nin suratinda bir dusunce belirdi ve odadaki sessizlik Bulut'u sardi. Gozleri Boncuk'a dondu ve sonra tekrar Bulut'a bakti." << endl;
    cout<<"-Baba:Senin isteklerin hicbir onem arz etmiyor. Bu kedi,artik benim. Sana tavsiyem, artik ayrilma vakti geldi. Git, buralarda olmamalisin."<<endl;
}

bool paraVer=false;
int paraTeklifi = 0;

void tehdit(){
    cout<<"- Bulut:Baba, Boncuk'u hemen bana vermezsen, seni ve tum ceteni ifsa ederim. Mahkemede sana ne oldugunu gormek ister misin?\n";
    cout<<"Seninle birlikte tum bu kirli isleri aciga cikaririm. Bu senin son sansin, ya Boncuk'u teslim edersin ya da sonun geldi demektir.\n";
    cout<<"- Baba:Bu cocuga unutamayacagi bir ders verin...\n";
    cout<<"Baba'nin adamlarinin sana yaptiklari sey sonucu bilincini kaybettin."<<endl;
}

void para(){
    cout<<"- Bulut:Kedimi ne kadar altin karsiliginda bana geri verirsin?\n";
    cout<<"- Baba:Sence biz para icin is yapan kisilere mi benziyoruz evlat.Bu sana son uyarim,kucuk bir cocuga zarar vermek istemiyorum git buradan!!!\n";
    paraVer=true;
    paraTeklifi++;
}

void dil(){
    cout<<"Bulut Baba'ya basindan gecenleri anlatir... Baba Bulut'a uzulur, kedisini ona geri verir. Bulut kediyi geri aldiginda boynunda takili olan tasmayi fark eder.\n" 
        << "Tasmanin arkasinda Saturn simgesini gorur. Artik buradan cikis biletleri hazirdir.\n"
        << "Bu sirada Baba bir adamina Bulut'a cikis kapisina kadar ona eslik etmesi icin emir verir.\n";
    cout<<"Bulut tam kapidan cikacakken Baba ona seslenir.\n";
    cout<<"-Baba:Hey! Evlat,ailenle vakit geciriyor musun?\n";
    cout<<"-Bulut:Evet efendim\n";
    cout<<"-Baba:Guzel,cunku ailesiyle vakit gecirmeyen bir erkek asla gercek bir erkek degildir....\n";
    cout<<"Baba'nin adamlari Bulut'u cikis kapisina gotutur ve Bulut ilerlemeye devam eder.\n";
}

int startParkingGame(){
    laf1();
    int secim;
    while (true)
    {
        cout<<"Baba'ya nasil karsilik verecegini sec:"<<endl;
        cout<<"(1) Tehdit Et\n"<<"(2) Para Teklif Et\n"<<"(3) Tatli Dilini Kullan"<<endl;
        while (true)
        {
            cin>>secim;
            if (cin.fail())
            {
                cout<<"Hatali Giris Tekrar Deneyin!!!"<<endl;
                cin.clear();
                cin.ignore(10000,'\n');
            }else{
                break;
            }
            
        }
      
        if (secim==1)
        {
            tehdit();
            cout<<"Bilinci yerine Geldiginde Bulut,Kendini Baska Bir Odada Bulacaktir...."<<endl;
            return 0; 
        }else if (secim==2)
        {
            if (paraTeklifi == 0)
            {
                para();
                continue;
            }else if(paraTeklifi==1){
                cout<<"Baba'ya tekrar para teklif edersen sonu kotu olur!!!!"<<endl;
                paraTeklifi++;

                continue;
            }else{
                cout << "Sonu kotu olur demistim. Vurun su cocugu!!" << endl;
                return 0;
            }
        }else if (secim==3)
        {
            dil();
            return 25;
        }else{
            cout<<"Hatali Giris Yaptiniz!!!! Tekrar deneyin."<<endl;
        }  
    }
}

#endif