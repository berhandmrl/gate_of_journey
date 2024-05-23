#ifndef ESPRI_H
#define ESPRI_H

#include <iostream>
#include<algorithm>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

void sh(){
 cout<<"Bulut ve boncuk kendilerini bembeyaz 4 duvarli kapisiz bir odada bulurlar. Burasi apaydinlik ve duvarlari bembeyaz bir odadir . Karsiya baktiklarinda onlari bekleyen birisinin oldugunu ve o kisinin yaninda da kocaman bir\nekran gorurler. Gordukleri kisi kisa boylu gozluklu bir kizdir ve komik birisine benziyordur.Ekran ise butun"
"duvari kaplayacak kadar buyuktur. Yanina giderler ve burasinin ne oldugunu onun burada ne yaptigini sorarlar.Kiz\naciklamaya baslar.\n"
"-Kiz : Burasi espri odasi.Oyununuzdan cikabilmek icin benim soracagim igrenc soguk esprilere cevap vermeniz gerekiyor. Eger sordugum 4 soruyu da dogru sekilde cevaplarsaniz size buradan cikmak icin gerekli olan\ntilsimli esyanizi verecegim.\n"
"-Bulut : Nasil yani ? Nasil sorulardan bahsediyorsun sen?\n"
"-Kiz : Sorunca anlarsin bulutcum.Sorulari duyunca bir an once buradan cikmak isteyeceksin HAHAHAHAHAHAHAHAHAHAHAHAHAHAHAAHAHAHAHAHHA (KoTuCuL KOMIK GuLus)\n"
"Bulut bu durumu kabullenir ve ne yapmalari gerektigini sorar.\n"
"-Kiz: Birazdan karsinizdaki ekranda sirayla soguk espriler gelecek. Bunlari sirayla dogru bildikce digerlerine sira gelecek. Tam 7 tane soguk esprim var size soracak. Gercekten cok heyecanliyim. Hepsi birbirinden komik\nesprilerime ne tepki vereceginizi cok merak ediyorum. Umarim eglenerek bitiririz bu oyunumuzu HAHAHAHAHAHAHHAAHAH\n"
"Bulut kizin tepkilerine cok sasirmisti. Bir espri ne kadar korkunc olabilir diye dusunuyordu.\n"
"Ama kizin o gulusu de onu suphelendiriyordu. Boncukla bir sure konustular ve oyuna baslamaya karar verdiler..Ekranda birinci espri cikar ve oyun baslamistir en az 4 esprinin dogru bilinmesi gerekiyordur.Yoksa canimiz\nazalacaktir"<<endl;
}

string get_random_question() {
    vector<string> questions = {
        "Yatakta edilen duaya ne denir?",
        "Gercek olmayan ayakkabiya ne denir?",
        "Adamin biri mahkemenin onunden gecerken ne dusmus?",
        "Ahirdan esegi kacan Italyan koylusu ne demis",
        "cope atilan erige nedenir?",
        "Siviller hangi dili konusur?",
        "Ucan kopege ne denir?",
    };
    return questions[rand() % questions.size()];
}

string get_correct_answer(string question) {
    if (question == "Yatakta edilen duaya ne denir?") {
        return "beddua";
    } else if (question == "Gercek olmayan ayakkabiya ne denir?") {
        return "bot";
    } else if (question == "Adamin biri mahkemenin onunden gecerken ne dusmus?") {
        return "dava";
    } else if (question == "Ahirdan esegi kacan Italyan koylusu ne demis") {
        return "sipagetti";
    } else if (question == "cope atilan erige nedenir?") {
        return "teleferik";
    } else if (question == "Siviller hangi dili konusur?") {
        return "sivilce";
    } else if (question == "Ucan kopege ne denir?") {
        return "havuc";
    } 
    return "";
}

int startEspriGame() {
    sh();
    srand(time(0)); 
    int error_count = 0;
    int correct = 0;
    cout << "Oyun Basladi!!!!" << endl;
    while(1){
        string question = get_random_question();
        cout << question << " "<<endl;
        string answer;
        transform(answer.begin(),answer.end(),answer.begin(),::tolower);
        cin >> answer;
        if (answer == get_correct_answer(question)) {
            cout << "Dogru Cevap" << endl;
            correct++;
            if (correct==4)
            {
                break;
            }
        } else {
            cout << "Yanlis Cevap" << endl;
            error_count++;
        }
    }
    cout << "Yanlis verilen cevap sayisi: " << error_count << endl;
    cout<<"Bulut'un sorulardan midesi bulanmistir ancak kiz hunharca gulmekten dolayi kendinden gecmistir.Daha sonra"<<endl;
    cout<<"kiz gelir yanina ve ona uzerinde Saturn simgesi olan gozlugu  verir.Bulut gozlugu taktigi an portal acilir.Bulut ve Boncuk diger oda icin yolculuga cikarlar."<<endl;
    return error_count;
}

#endif