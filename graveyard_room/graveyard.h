#ifndef GRAVEYARD_H
#define GRAVEYARD_H

#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
#include <cctype>

using namespace std;

void konusma1(){
    cout<<"Portaldan gectigi anda kendisini karanlik bir mezarligin icinde bulur. Etrafta birden cok mezar , uzun uzun agaclar ve ruzgarin korkunc ugultusu vardir. Ortam zifiri karanliktir bu yuzden hicbir sey goremez.\n"
    "Goremedigi icin korkar ve hareket edemez. Zamanla gozleri karanliga alismaya baslar.O sirada kedisinin yaninda olmadigini fark eder ve korkuya kapilir. Boncugu cagirmaya baslar . Bir sure sonra boncuk agzinda fenerle bulutun yanina gelir."
    "\nBoncuk uzaklardan gidip fener bulup getirmistir. Bulut boncuktan feneri alir. Feneri yakarlar ve etrafi detaylica incelerler. Yerler aralikli taslarla kaplidir bu yuzden yurumek cok zordur.\nBir yandan da cevrede yuzlerce eski mezar gorurler. Bazilarinin icleri bostur.\n" 
    "Etrafta bir suru orumcek ve orumcek aglari vardir. orumcek aglarinin fazlasiyla donattigi bir mezar tasi gorurler. Bu mezar sanki digerlerinden farklidir. Bulut ve boncugun dikkatini ceker bu mezar.\nYanina gittiklerinde mezarin icinde bir iskelet gorurler.Iskeletin ustunde tam da aradiklari imgeyle karsilasirlar.\n"
    "Boncuk ve Bulut birbirlerine ayni anda caresiz bir bakis atarlar . Kara kara dusunmeye baslarlar cunku hem mezara girmek cok korkunc bir durum hem de o kadar cok orumcek agi vardir ki bu cok igrenctir.\n"
    "Tam dusunurlerken bir anda karsilarinda bekci belirir.Ikisi de korkudan ciglik atarlar. Karanlikta bekci adam ne ara gelmistir oraya...Bekci sorar:\n"
    "-Bekci: Siz kimsiniz ve bu saatte burada ne ariyorsunuz.\n"
    "-Bulut : Biz buraya yanlislikla dustuk. Kedim ve ben uzerinde imge olan esyalari bulmaya calisiyoruz. Tam aradigimiz sey de bu mezarin icerisinde.\n"
    "-Bekci : Sizin gibi yanlislikla bu oyuna dusup bir seyler arayanlar cok oluyor burada sizin aradiginiz nedir ki tam olarak.\n"
    "-Bulut : su mezarin icerisindeki kurukafayi goruyor musun?\n"
    "-Bekci : Evet gordum ne varmis ki bunda burada bir suru oylesi kafatasi olur zaten burasi bir mezarlik.\n"
    "-Bulut : Iste onu digerlerinden farkli kilan bir sey var. uzerindeki imge onu tam olarak bizim aradigimiz sey yapiyor. Bizim mezarin icerisine girip onu almamiz gerekiyor.\nAma orasi cok korkunc oldugu icin ikimiz de girmek istemiyoruz aramizda karar vermeye calisiyoruz.\n"
    "-Bekci : O zaman size biraz yardim edeyim. Size bir bilmece soracagim. Eger bilmece bilinirse bulut mezara girip alacak bilmece bilinemezse boncuk mezara girip alacak.\n"<<endl;
}

void Bilmece(){
    string cevap1;
    string bilmece="Bir odada bir lamba, bir soba ve bir de mum var. once lambayi yakiyorlar, sonra sobayi. Sonra da mumu. Ama hangisi once sonuyor?";
    cout<<"Iyi dusun cunku tek bir cevap verme hakkin var!!!"<<endl;
    cout<<bilmece<<endl;
    string cevap="mum";
    cin>>cevap1;
    transform(cevap1.begin(),cevap1.end(),cevap1.begin(), :: tolower);
    if (cevap1==cevap)
    {
        cout << "Bulut mezarin icerisine girer,kafatasini uzun ugraslar sonucu en sonunda bulur ve mezarliktan geri cikar."<<endl;
    }else{
        cout<<"Boncuk mezarin icerisine girer,kedi olmasinin avantajiyla kafatasini kolayca bulur ve mezarliktan cikar. "<<endl;
    }
}

int startGraveyardGame(){
    konusma1();
    Bilmece();
    cout<<"-Bekci : Sizin gibi yanlislikla oyuna girenlerin buradan cikis yollarini gordum. Sizi oraya gotureyim … \n"
    "-Bulut:Bizim gibi baskalari da derken...Acaba bu oyunun amaci ne ve neden bizde secildik Boncuk?\n"
    "-Boncuk:Her seyi bu kadar detayli dusunme Bulut.Simulasyon hata vermistir :)\n"
    "(Bekci adam kedi ve cocugu cikis kapisina dogru goturur…)\n"
    "Bulut ve boncuk ellerindeki kuru kafa ile bekcinin gosterdigi kapidan bir sonraki odaya gecerler."<<endl;
    return 0;
}

#endif