#ifndef COSTUME_H
#define COSTUME_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Kostum
{
public:
    string ust;
    string alt;
    string pelerin;
    string aksesuar;
    string esya;
    string ayakkabi;
    Kostum() {}
    Kostum(string u, string a, string p, string ak, string es, string s) : ust(u), alt(a), pelerin(p), aksesuar(ak), esya(es), ayakkabi(s) {}
};

void BulutEsya(Kostum k[])
{
    k[0] = Kostum("Gomlek", "Pantolon", "Uzun Pelerin", "Vampir Tilsimi", "Vampir Disi", "Kundura");
    k[1] = Kostum("Tulum", "Etek", "Kisa Pelerin", "Cadi sapkasi", "Buyucu Degnegi", "Kedi Kulagi Bandi");
    k[2] = Kostum("Ceket", "sort", "Kisa Pelerin", "Kaptan sapkasi", "Gemi Dumeni", "Denizci Botu");
    k[3] = Kostum("Gomlek", "Kot Pantolon", "Kisa Pelerin", "Kovboy sapkasi", "Kovboy Silahi", "Cizme");
    k[4] = Kostum("Elbise", "Bol PaCa Pantolon", "Uzun Pelerin", "Cadi sapkasi", "Buyucu Degnegi", "Peri Kanatlari");
    k[5] = Kostum("Takim Elbise", "Kisa Etek", "Ceket", "Gozluk", "Dedektif Cantasi", "Ayakkabi");
    k[6] = Kostum("Tisort", "Esofman Alti", "Kisa Pelerin", "Super Kahraman Maskesi", "Super Kahraman Kalkani", "Super Kahraman Botu");
    k[7] = Kostum("Gomlek", "Pantolon", "Uzun Pelerin", "Viking Kaski", "KiliC", "Viking Botu");
    k[8] = Kostum("Tulum", "Tayt", "Kisa Pelerin", "Prenses Taci", "Sihirli Asa", "Balerin Ayakkabisi");
    k[9] = Kostum("Ceket", "Etek", "Kisa Pelerin", "Korsan Bandanasi", "Korsan Kilici", "Bot");
}

void bulutEsyaGoster(Kostum k[])
{
    for (int i = 0; i < 10; i++)
    {
        cout << i + 1 << ". Konsept:" << endl;
        cout << "Ust: " << k[i].ust << endl;
        cout << "Alt: " << k[i].alt << endl;
        cout << "Pelerin: " << k[i].pelerin << endl;
        cout << "Aksesuar: " << k[i].aksesuar << endl;
        cout << "ESya: " << k[i].esya << endl;
        cout << "Sapka: " << k[i].ayakkabi << endl;
        cout << "************************************" << endl;
    }
}

void hayvanEsya(Kostum he[])
{
    he[6] = Kostum("Kedi Pelerini", "Cizme", "Koruyucu Armasi", "Tuylu Fotr Sapka", "Oyuncak Kilic", "Cizme");
    he[1] = Kostum("Kopek Kiyafeti", "Kemik Desenli Etek", "Kemik Bandana", "Kopek Kulaklari Bandi", "Oyuncak Top", "Kemik Ayakkabi");
    he[2] = Kostum("Panda Tulum", "Bambu Desenli Pantolon", "Bambu Pelerin", "Bambu Bandana", "Bambu Cubuk", "Patik");
    he[3] = Kostum("Ayi Kiyafeti", "Tutunma Desenli Pantolon", "Bal Pelerini", "Bal Kabi Sapka", "Oyuncak Bal", "Ayakkabi");
    he[4] = Kostum("Zebra Elbisesi", "Cizgili Etek", "Cizgili Pelerin", "Cizgili Sapka", "Oyuncak Zebra", "Terlik");
    he[5] = Kostum("TavSan Tulum", "HavuC Desenli Etek", "TavSan Kulaklari Bandi", "HavuC Sapka", "Oyuncak HavuC", "Ayakkabi");
    he[0] = Kostum("Aslan Pijamasi", "Post Desenli Pantolon", "Aslan Kafasi Bandana", "Aslan Kuyruk", "Oyuncak Aslan", "Patik");
    he[7] = Kostum("Kaplan Kiyafeti", "Cizgili Pantolon", "Kaplan Kuyruk", "Kaplan BaSli Bandana", "Oyuncak Fare", "Ayakkabi");
    he[8] = Kostum("Timsah Elbisesi", "Timsah Derisi Desenli Elbise", "Timsah DiSi Bandana", "Timsah Kuyruk", "Oyuncak Timsah", "Sandalet");
    he[9] = Kostum("KuS Kostumu", "Tuy Desenli Kiyafet", "KuS Kanatlari", "KuS BaSli Bandana", "Oyuncak Yumurta", "Patik");
}

void hayvanEsyaYazdir(Kostum he[])
{
    for (int i = 0; i < 10; i++)
    {
        cout << i + 1 << ". Hayvan Konsepti:" << endl;
        cout << "Ust: " << he[i].ust << endl;
        cout << "Alt: " << he[i].alt << endl;
        cout << "Pelerin: " << he[i].pelerin << endl;
        cout << "Aksesuar: " << he[i].aksesuar << endl;
        cout << "ESya: " << he[i].esya << endl;
        cout << "Sapka: " << he[i].ayakkabi << endl;
        cout <<"************************************************"<<endl;
    }
}

void yazi1()
{
    cout << "Gecidin cikis kapisi kostum partisinin yapildigi sik, eski donemlerden kalma gibi gorunen bir sato onune acilir. Burada olduklarina ikisi de inanamazlar."
            "satonun kudretli goruntusu karsisinda agizlari acik kalir.\n"
            "U seklinde olan yerlesimiyle,"
            "ust kismindaki mavi ile altin renginin uyumu onlara muhtesem gozukur.Sonunda satodan gozlerini ayirabildiklerinde etrafindaki herkesin tam da konsepte uygun bir sekilde giyindigini fark ederler.\nFakat Bulut 'un ustunde ev kiyafetleri vardir."
            "Iceri bu sekilde alinmayacagini dusunurken icerden gelen muzigin kisik sesini duyar. Bulut' a bu muzik bir yerden tanidik gelir.Muzige dikkat kesilir.\ncalan muzigi annesinin ona eskiden dinlettigi muzik oldugunu hatirlar.Ailesinden uzak kalmanin "
            "verdigi ozlemle hayallere dalar.Kedinin pacasindan cekistirmesi ile dusuncelerinden uzaklasir.Yanlarina bir guvenlik gelmistir.\n"
            "- Guvenlik : Bu kiyafetlerle partiye giremezsiniz.\n"
            "- Bulut : Ama bizim yanimizda baska kiyafetimiz yok ki.\n"
            "- Guvenlik : satonun icerisinde esya odasi var size de kedinize de bir konsept secebilirsiniz.\n"
            "Artik nereden giyineceklerini biliyorlardir.Esya odasina geldiklerinde bir suru kiyafet ve esya gorurler.Bulut en sevdigi vampir karakterinin kostumlerini giymek, Boncuk'u ise cizmeli kedi yapmak ister.\nTek yapmasi gereken gerekli esyalari bulmasidir."
         << endl;
}
void yazi2()
{
    cout << "Artik bu devasa partiye girebilmek icin vampir temali bir sekilde giyinmistir fakat bir tek vampir sapkasini bulamamistir. Yine de maskeli balonun girisine  giderler.\n"
    "Onlari odaya gonderen guvenlik , giysilerini gorup iceri alir. Icerisi adeta filmlerden firlamiscasina insanlar ve onlarin evcil hayvanlariyla doludur.\n"
    "Hala aradiklari esyayi bulamamanin verdigi caresizlikle bos bos etrafi seyrederler."
    "Bulut satonun duvarlarini incelerken ust taraflarda bir ok fark eder. Onu takip ettiginde devaminda baska oklarin da oldugunu gorur.\n"
    "Oklarin gosterdigi sey odada bulamadigi vampir sapkasidir.Onu orada gorunce cok sasirir.Bunun bir isaret oldugunu dusunurler bir sekilde oraya ulasmalari lazimdir.\n"
    "Bulut tepeye cikamaz, kediyi sapkayi almasi icin gonderir. Boncuk merdivenlerin gittigi yere kadar merdivenlerle cikar sonrasinda ise upuzun sallanan avizelerden tirmanarak sapkaya ulasir.ciktigi gibi geri Bulut'un yanina\n"
    "doner.Tam da tahmin ettikleri gibi aradiklari esya o sapkanin icindedir. ustunde bir suru Saturn cizimi olan maskeyi oradadir.\n" 
    "Bulut'un maskeyi takmasi ile gecit acilir. Acilan gecitten gecerek bir sonraki bolume gecerler." << endl;
}

int startCostumeGame(){
    Kostum bulut[10];
    BulutEsya(bulut);
    Kostum boncuk[10];
    hayvanEsya(boncuk);
    int secim, secim1, hatasayisi =0;
    yazi1();

    while (true)
    {
        cout << "Once Bulut Mu Giyinecek Yoksa Boncuk Mu?" << endl;
        cout << "(1)Bulut\n"
                "(2)Boncuk"
             << endl;
         while (true)
            {
                cin>>secim;
                if (cin.fail())
                {
                    cout<<"Hatali Giris Yaptiniz Tekrar Deneyin"<<endl;
                    cin.clear();
                    cin.ignore(10000,'\n');
                }else{
                    break;
                }
                
            }
        if (secim == 1)
        {
            cout << "Bulut icin hangi konsepti sececeksiniz?" << endl;
            cout << "(ornegin 1.kosepti secmek istiyorsaniz 1'e basiniz.)" << endl;
            while (true)
            {
             bulutEsyaGoster(bulut);
                while (true)
             {
                cin>>secim1;
                if (cin.fail())
                {
                    cout<<"Hatali Giris Yaptiniz Tekrar Deneyin"<<endl;
                    cin.clear();
                    cin.ignore(10000,'\n');
                }else{
                    break;
                }    
             }
                if (secim1 != 1)
                {
                    cout << "Bulut Vampir Kostumu Istemisti:( Lutfen Tekrar Deneyin!!" << endl;
                    hatasayisi++;
                }
                else
                {
                    cout << "Bulut Vampir Kostumunu Giydi..." << endl;
                    break;
                }
            }

            cout << "Boncuk icin hangi konsepti sececeksiniz?" << endl;
            hayvanEsyaYazdir(boncuk);
            while (true)
            {
                cin>>secim1;
                if (cin.fail())
                {
                    cout<<"Hatali Giris Yaptiniz Tekrar Deneyin"<<endl;
                    cin.clear();
                    cin.ignore(10000,'\n');
                }else{
                    break;
                }
                
            }
            if (secim1 != 6)
            {
                while (true)
                {
                    cout << "Boncuk Cizmeli Kedi Olmak istemisti :( Lufen Tekrar deneyin" << endl;
                    hatasayisi++;
                    hayvanEsyaYazdir(boncuk);
                while (true)
                {
                cin>>secim1;
                if (cin.fail())
                {
                    cout<<"Hatali Giris Yaptiniz Tekrar Deneyin"<<endl;
                    cin.clear();
                    cin.ignore(10000,'\n');
                }else{
                    break;
                }
                
                }
                    if (secim1 != 6)
                    {
                        continue;
                    }
                    else
                    {
                        cout << "Boncuk Cizmeli Kedi Kostumunu Giydi..." << endl;
                        break;
                    }
                }
            }
            else
            {
                cout<<"Boncuk Cizmeli Kedi Kostumunu Giydi..."<<endl;
                break;
            }
            break;
        }
        else if (secim == 2)
        {
            cout << "Boncuk icin hangi konsepti sececeksiniz?" << endl;
            cout << "(ornegin 1.kosepti secmek istiyorsaniz 1'e basiniz.)" << endl;
            while (true)
            {
                hayvanEsyaYazdir(boncuk);
            while (true)
            {
                cin>>secim1;
                if (cin.fail())
                {
                    cout<<"Hatali Giris Yaptiniz Tekrar Deneyin"<<endl;
                    cin.clear();
                    cin.ignore(10000,'\n');
                }else{
                    break;
                }
                
            }
                if (secim1 != 6)
                {
                    cout << "Boncuk Cizmeli Kedi Olmak Istemisti :( Tekrar Deneyin." << endl;
                    hatasayisi++;
                    continue;
                }
                else
                {
                    cout << "Boncuk Cizmeli Kedi Kostumunu Giydi..." << endl;
                    break;
                }
            }
            cout << "Bulut icin hangi konsepti sececeksiniz?" << endl;
            while (true)
            {
                bulutEsyaGoster(bulut);
            while (true)
            {
                cin>>secim1;
                if (cin.fail())
                {
                    cout<<"Hatali Giris Yaptiniz Tekrar Deneyin"<<endl;
                    cin.clear();
                    cin.ignore(10000,'\n');
                }else{
                    break;
                }
                
            }
                if (secim1 != 1)
                {
                    cout << "Bulut Vampir Kostumu Istemisti:( Lutfen Tekrar Deneyin!!" << endl;
                    hatasayisi++;
                }
                else
                {
                    cout << "Bulut Vampir Kostumunu Giydi..."<< endl;
                    break;
                }
            }
            break;
        }
        else
        {
            cout << "Yanlis Secim Yaptiniz!!! Tekrar Deneyin." << endl;
        }
    }
    yazi2();
    return hatasayisi;
}

#endif