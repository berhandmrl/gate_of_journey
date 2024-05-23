#ifndef BAHCE_H
#define BAHCE_H

#include <iostream>
#include <cstdlib> // srand, rand
#include <ctime> // time

using namespace std;

void as1(){
    cout<<"Bu dustukleri oda bir botanik bahcedir. Tam olarak ciceklerin icine dusmuslerdir. Burasi dogal olmayan yapma bir botanik bahceye benziyordur cunku uzeri camdan kapatilmis iceriye bir gol benzeri su konulmus devasa bir\nbahceden olusmustur."
    "ciceklerin verdigi o yogun koku ilk andan beri baslarini dondurmeye baslamistir.  Kokularin verdigi o mayhosluk ile tam olarak ne yaptiklarinin bilincinde degillerdir. cicekleri tek tek incelemeye\nbaslarlar. Bir an once esyayi bulup gitmek istiyorlardir"
    "cunku bu oda onlari cok fena yapmistir. Renkli hos kokulu ciceklerin orada gozlerine carpan herhangi bir sey yoktur. Bir sonraki yere dogru ilerlerler. Ileride et yiyen\nbitkisinin oldugunu gorurler ona dogru gitmek isterler fakat Bulut'un ayagina bir sey dolanmistir." 
    "Ne olduguna baktiklarinda bunun sarmasik bitkisi oldugunu gorurler. Bulut bir an once kendisini kurtarmaya calisir ama sarmasiklar kadar\nhizli bir sekilde dolanmistir ki yerinden kipirdayamaz hale gelmistir. Etraflarina baktiklarinda aslinda bu kisma girilmez isareti"
    "konulmustur. ciceklerin etkisinden bir garip olan bulut ve boncuk su anda bunu fark\netmemenin cezasini cekiyordur. Bir sekilde Bulut'un onlardan kurtulmasi gerekmektedir. Boncuk 'un aklinda cantalarinda olan makas aklina gelir ve onu cikarip"<<endl;
    char a;
    cout<<"Cantadan almak icin 'a' ya basiniz:"<<endl;
    cin>>a;
    while (true) {
        cin >> a;
        
        if (cin.peek() == '\n') { 
            if (a == 'a' || a=='A') { 
                break; 
            } else {
                cout << "Hatali Giris Yaptiniz Tekrar Deneyin!!!" << endl;
            }
        } else {
            cout << "Hatali Giris Yaptiniz Tekrar Deneyin!!!" << endl;
            cin.clear(); 
            cin.ignore(10000, '\n'); 
        }
    }
     cout<<"Bulut'a dolanan butun sarmasiklari keser."<<endl;
     char k;
     cout<<"Kesmek icin 'k' ye basiniz:"<<endl;
     cin>>k;
    while (true) {
        cin >> k;
        if (cin.peek() == '\n') { 
            if (k == 'k' || k=='K') { 
                break; 
            } else {
                cout << "Hatali Giris Yaptiniz Tekrar Deneyin!!!" << endl;
            }
        } else {
            cout << "Hatali Giris Yaptiniz Tekrar Deneyin!!!" << endl;
            cin.clear(); 
            cin.ignore(10000, '\n'); 
        }
    }
    cout<<"Bulut nihayet sarmasiklardan kurtulmustur. Baska sarmasik sarmadan bir an once et yiyen bitkilerinin oldugu yere dogru kosarak giderler. Birden cok et yiyen bitkisi siralanmis bir sekilde burada duruyordur. Onlarin tam\nustunde ise bitkilerden birisinin"
    "agzinda olan kucuk yuzugu tahmin etmek icin olan bir dijital ekran vardir. Yan tarafta gelen misafirlerin beslemesi icin konulmus kucuk et parcaciklari duruyordur. Onlardan biraz alirlar ve\ntahminlerini ekrana girerler."<<endl;
}

int startSarmasikGame(){ 
    as1();
    srand(time(0)); 
    int dogruCicek = 3; 
    int secim;
    int ll = 0;
    do {
        cout << "Yuzuk hangi cicegin agzinda (1-6 arasi bir rakam girin): ";
        cin >> secim;

        if (secim == dogruCicek) {
            cout << "Tebrikler! Dogru cicegi buldun.\n";
            break; // Doğru su birikintisini bulduysa döngüyü kır
        } else {
            cout << "Yanlis cicegi sectin. Lutfen tekrar dene.\n\n";
            ll++; // Yanlış cevap aldığımızda hatasayisi'ni arttır
        }
    } while (ll < 100000);
    cout<<"Aradiklari esyanin bitkinin agzindaki esya olduguna o kadar cok eminlerdir ki hepsini tek tek beslerler. 6 bitkinin sadece birinden cikan bu yuzugu alirlar ve uzerindeki simgeyi gormeleriyle bir oh cekerler. Ekranda kazanan\nkisinin buyuk agaclarin tam ortasinda kalan"
    "yere gitmesi gerektigi yazmaktadir. Bulut ve Boncuk da buna uyarak oraya gider ve acilmis olan gecitten gecerek bir sonraki bolume ulasirlar."<<endl;
    return ll;
}

#endif