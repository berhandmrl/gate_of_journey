#ifndef FUNFAIR_H
#define FUNFAIR_H

#include <iostream>
#include <string>
#include <map>
using namespace std;
void salam(){
    cout<<"Bu odaya giris kapisi, los isiklarla kapli, arkadan calan hafif antik misir tarzindaki muzigin ,burunlarina gelen tutsu kokusunun geldigi yer bir falci cadiridir. Burasi onlara cok garip gelmistir.Onlara yaklasan bir ses duyarlar.\nBu yanlarina dogru gelen cingirakli bir yilanin sesidir. Yilanin arkasindan gelen bir de ayak sesi duyulur. Bu sesin sahibi ise falciya aittir. Falci onlara fal baktirip\nbaktirmamak istediklerini sorar ama bu soruya hayir cevabini verme sanslari yok gibi gorunuyordur. Kadin cevaplarini beklemeden tarot kartlarina dogru yonelir. Onlara 4 tane kart cekmeleri gerektigini soyler." 
    "Bulut madem bunu\nyapmak zorundayiz hissederek yapalim diye dusunur ve kartlari secer. Falci Bulut'un sectigi kartlari acar ve gorduklerine cok sasirir. Bulut'a gorduklerini anlatir ve neredeyse son zamanlarda yasadiklarinin hepsini dogru\nbilmistir. En son olarak falci bir kart daha secmelerini ister. Kartlar ters bir sekilde masanin uzerinde dizili dururken gozlerine bir kart carpar . Arkasindaki resim Saturn'un on planda oldugu arka planda ise yildizlarin\n,mor, lacivert renklerin oldugu bir karttir bu. Tabi ki de bu karti sececeklerdir. Falci bu kartin yorumu olarak onlara cikis yolunun bu kart oldugunu soyler "
    "ve hediye olarak karti onlara verir. Gercekten de bu bolumden cikis yolunu\nbulmuslardir. cadirdan cikmalarina izin verilir. ciktiklarinda gordukleri sey kocaman bir lunaparkin icinde olduklaridir. Oysa ki en basta  bu cadirin lunaparkin icindeki daha once ailelerinin girmelerine izin\nvermedikleri yer oldugunu bilmiyorlardi. cadirin onunde bir sure nereye gideceklerini bilemez bir sekilde dururlar. Etrafta bir ipucu ararken onlerinde gecen bes kisilik arkadas grubunu gorurler. Onlarda Bulut'a yakin\ngelen bir sey vardir. Etraflarindaki seyleri umursamadan sadece kendi eglencelerine bakiyorlardir. Ve kendi iclerinde "
    "o kadar uyumlu ve mutlu gorunuyorlardir ki Bulut onlara cok ozenmistir. Onlarin izinden gitmeye baslarlar.\nTakip ettikleri arkadaslar kendi aralarinda neye binsek diye konusuyorlardir. Neye binmek istediklerine bir turlu karar veremiyorlardir. Iclerinde kamikaze , gondol, korku treni ve roller coaster dan korkan oldugu icin hepsi birlikte birseye binemiyorlardir. Uzun bir tartismadan sonra lunaparktaki en guvenli oyuncak olan donme dolaba\nbinmeye karar verirler. Bulut ve Boncuk da onlarin pesinden giderler. Onlar da donme dolaba binmek isterler fakat gorevli\nkediyi alamayacagini soyleyerek kedinin girmesine izin vermez. "
    "Bulut'un biraz once sahit oldugu durum aklina gelir. 5'li arkadaslar birbirinden ayri bir sey yapmayi kabul etmemislerdi. Bulut da kedisini birakmayi kabul etmez ve birlikte cimlere otururlar . Ikisi birlikte digerlerini izlerken hemen yanlarinda birisinin  telefonunu unutmus ve gitmis oldugunu gorurler. Telefonu alirlar (al komutu) ve kime verebiliriz diye etraflarina bakarlarken\ntelefona bir mesaj gelir. Bu mesaj onlara telefondaki oyunu oynamalari gerektigini soyluyordur. sifresiz olan bu telefonu acarlar. Karsilarindaki oyunda biraz once gordukleri arkadaslarin resimleri ve onlarin donme dolaba\nbilmeleriyle ilgili sorular vardir."<<endl;
}

int startFunfairGame(){
    salam();
    int secim,sayac=0, hatasayisi = 0;
    map<string, int> friends;
    friends["Deniz"] = 17;
    friends["Nihal"] = 2;
    friends["Berhan"] = 14;
    friends["Batu"] = 4;
    friends["Busra"] = 13;
    int poz[5]={8,5,-7,-5,4};
    int alici[5];
    cout<<"Baslangictaki konumlar:"<<endl;
    cout<<"Busra: 13\nBerhan: 14\nDeniz: 17\nBatuhan: 4\nNihal: 2"<<endl;
    cout<<"Herkesin 9.Kabine gore konumlarini giriniz:"<<endl;
    while (1)
    {
        sayac = 0;
        cout<<"Deniz'in Konumu:"<<endl;
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
        alici[0]=secim;
        cout<<"Berhan'in Konumu:"<<endl;
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
        alici[1]=secim;
        cout<<"Nihal'in Konumu:"<<endl;
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
        alici[2]=secim;
        cout<<"Batuhan'in Konumu"<<endl;
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
        alici[3]=secim;
        cout<<"Busra'nin Konumu:"<<endl;
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
        alici[4]=secim;
        for (int i = 0; i <5; i++)
       {
        if (poz[i]==alici[i])
        {
            sayac++;
        }
       }
       if (sayac>=4)
       {
        cout<<"Tebrikler"<<endl;
        break;
       }else{
        cout<<"Konumlar Hatali Bastan Dene"<<endl;
        hatasayisi++;
       }
       
    }
    cout<<"Bu oyunu gectikten sonra gorevli Bulut'a seslenir kedinin Bulutla birlikte donme dolabina binebilecegini soyler ve gecis icin ellerindeki falcidan\naldiklari karti okutmalarini ister.\n" 
          "En tepeye geldiklerinde birlikte bindikleri kabinde bir kapi acilir ve bu bolumu basariyla tamamlamis olurlar "<<endl;

    return hatasayisi;
}

#endif