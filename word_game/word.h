#ifndef WORD_H
#define WORD_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include<algorithm>
#include <tuple>

using namespace std;

// Struct to hold questions and answers
struct Question {
    string questionText;
    string answer;
};
void bh(){
    cout<<"Bulut ve boncuk kendilerini 4 duvarli bir odanin icinde bulurlar .Duvarlar acik kahverengi renginde ahsaplarla dosenmis ve ustlerinde bir suru karisik birbirinden farkli harfler bulunmaktadir. Bulut ve boncuk bu odada nasil\nbir gorevi yapmalari gerektigini ve aradiklari simgenin nerede oldugunu bulmaya calisirlar. Odanin sag kosesinde duran calisma masasinin yanina giderler. calisma masasinin iki tane cekmecesi vardir. once ustteki cekmeceyi\nacmayi denerler ve acilir .ust cekmecenin icinde 3 tane renkli kagit bulurlar."
     "Hepsinin ustunde belirli harfler vardir. Bunun bir isaret olacagini dusunerek cantaya atarlar (kagitlari cantaya at komutu konmali.).Alt cekmeceyi de acmayi denerler ama acamazlar. cekmecenin uzerinde girmeleri gereken 3 tane sifre oldugunu gorurler. Bu sifrenin ne oldugunu bulmak icin cevreyi arastirmaya devam ederler. Kafalarini kaldirdiklari anda calisma masasinin\ntam karsisinda duran kara tahtayi gorurler. Ilk basta tahtaya arkalari donuk oldugu icin fark etmemislerdir ama calisma masasina gidip yonlerini degistirince gormuslerdir."
     "Tahtanin uzerinde tebesirle yazilmis karisik harflereuzun sure bakarlar. Sonra boncugun aklina cantaya koyduklari kagitlar gelir. Bir iliskilerinin olup olamayacagini dusunurler. Kagitlari cantadan cikarirlar ve kara tahtadaki harflerle karsilastirmaya baslarlar. Bir sure\ninceledikten sonra burada 3 tane atasozu oldugunu fark ederler. Ama bu atasozlerinin harfleri karisik bir sekilde durmaktadir. Bu karisik kelimeleri duzeltip belli bir siraya koyarlarsa alt cekmecenin kilidinin acilacagini\ndusunurler. Sonra kelimeleri olusturmaya baslarlar."<<endl;
}
void bh1(){
    cout<<"Butun kelimeleri dogru yaptiniz."
         "Artik butun sifre dogru bir sekilde onlerindedir. sifreyi cekmecenin kilit kismina yazarlar ve cekmece acilir. cekmecenin icinden aradiklari imgeli bir\nkitap cikar.\nKitabin kapagini acmalari ile birlikte portal acilir ve artik bu odada da isleri bitmistir. Diger odaya gecerler."<<endl;
}
int startWordGame() {
    bh();
    vector<Question> questions = {
        {"Soru: kine say caAg giilre", "agac yas iken egilir"},
        {"Soru: siiiyin rey iylara Amurdnu", "armudun iyisini ayilar yer"},
        {"Soru: lAki stnuuudr ldnakia", "akil akildan ustundur"},
        {"Soru: iyre Aset gtuusud aakry", "ates dustugu yeri yakar"},
        {"Soru: vaA gdien vlaairn", "ava giden avlanir"}
        
    };

    int lossCount = 0; 

    srand(time(0)); 
    int sayac=0;

    cout << "Bazi atasozu sorulari kelimeleri ve kelimelerin harfleri karisik olarak verildi. Bunlari dogru sekilde birlestirmen gerek.\n";
    cout << "Soru: Aeecl aesytn sei iisarkr" << "\nCevap: Acele ise seytan karisir\nOYUN BASLIYOR!\n";

    while (sayac<4) {    
        int randomIndex = rand() % questions.size();
        Question selectedQuestion = questions[randomIndex];

       
        cout << selectedQuestion.questionText << endl;
        string userAnswer;
        cout << "Cevap: ";
        getline(cin, userAnswer);
        transform(userAnswer.begin(),userAnswer.end(),userAnswer.begin(),::tolower);
        if (userAnswer == selectedQuestion.answer) { 
            cout << "Dogru Bildin Tebrikler!!!!" << endl;
            sayac++;
        }else {
            cout << "Yanlis cevap tekrar Tekrar Dene!!!" << endl;
            lossCount++; 
        }
    }
    bh1();
    return lossCount++;
}

#endif