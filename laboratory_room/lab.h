#ifndef LAB_H
#define LAB_H

#include <iostream>
#include <cstdlib> // srand, rand
#include <ctime> // time

using namespace std;

int startLaboratoryGame(){
    int kontrol = 0;
    // Senaryonun başlangıcı
    std::cout << "Cevrelerinde okulda bulunan panolardan birden cok vardir. Ilerideki odanin icinden dumanlar cikiyordu.\n"
         << "Ne oldugunu anlamak icin oraya dogru yururler. Kapinin sag ust kosesinde buranin laboratuvar oldugu yaziyor.\n"
         << "Icerideki dumanin sebebi ise laboratuvarda yapilan deneydi. Birisi adeta deneyi yarida birakip kacmisti.\n"
         << "Bir an once bu deneye son vermezlerse patlayacakti. Ne yapabileceklerini dusunurler ve bir yandan da panikle oraya buraya kosustururlar.\n"
         << "Hem deneyi durdurmalari gerekmektedir hem de aradiklari esyayi bulmalari gerekir. Etrafa bakinirken karsidaki masanin uzerinde duran kagidi farkederler.\n";
 
    cout << "\nKagidi alip icerigini okumak icin bir tusa basin...\n";
    //cin.get(); // Kullanıcının herhangi bir tuşa basmasını bekleyin
    {
        string a; 
        cin >> a;
    }

    cout << "Kagidin uzerinde bu deneyin formulu ve malzemeleri yaziyordur. Bu deneyin nerede kaldigini incelerler ve kagidin uzerinde bir not kismi oldugunu farkederler.\n"
         << "Not kisminda \"Hasan iki salak osman\" yazmaktadir. Notu anlamlandirmaya calisirlar.\n"
         << "Notun bu deneyi durdurabilecek maddeye dair bilgi tasidigini anlarlar. Hemen dolaplari karistirmaya baslarlar. Bir dolapta 3 tane deney tupu vardir.\n"
         << "Deney tuplerinin uzerinde icerisinde hangi madde bulundugu yazmaktadir.\n";

    cout << "Bulut artik bir madde secmesi gerekir yoksa deney sonlanacak ve oda patlayacaktir.\n";

    // Doğru su birikintisini belirleyelim (örneğin 3. su birikintisi doğru olsun)
    srand(time(0)); // Rastgelelik için zamanı kullan
    int dogruBirikinti = 2; // 1 ile 5 arasında rastgele bir sayı seç

    int secim;
    int hatasayisi = 0;

    cout << "Hangi tupu sececeksin? (1- H2SO3, 2- H2SO4, 3- H2CO3): ";
    while (true)
    {
        cin >> secim;
        if (cin.fail())
        {
            cout<<"Hatali Giris Yaptiniz Tekrar Deneyin!!!"<<endl;
            cin.clear();
            cin.ignore(10000,'\n');
        }else{
            break;
        }
        
    }
    if (secim == dogruBirikinti) {
        cout << "Tebrikler! Dogru maddeyi buldun.\n\n";
        kontrol = 0;
    } else {
        cout << "Yanlis maddeyi sectin ve oda patladi.\n\n";
        kontrol = 25;
        return 0;
    }
        cout<< "Dumanlar dindi ve deney sona erdi!\n"
            << "Deney sonlandigi icin deney kabindaki dumanlar tamamen gectiginde kabin icerisinde bakirdan bir eski para gorurler\n"
            << "Bu tam olarak aradiklari seydir. Cunku bu eski paranin uzerinde Saturn simgesi vardir.\n"
            << "Parayi ellerine alirlar ve tam da laboratuvara giris kapisi parayi eline aldigi anda bir gecis portalina donusur.\n";
    return 25;
}

#endif