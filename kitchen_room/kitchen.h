#ifndef KITCHEN_H
#define KITCHEN_H

#include <iostream>
#include <string>

using namespace std;

int startKitchenGame(){
    int mistakeCount = 0;
    int answer;
    bool correctAnswer = false;

    // Questions and correct answers
    string questions[9] = {
        "Malzemeleri sec 1- Bulgur 2- Pirinc 3- Sehriye",
        "Malzemeleri sec 1- Buz 2- Su 3- Soda",
        "Malzemeleri sec 1- Salca 2- Ketcap 3- Aci sos",
        "Malzemeleri sec 1- Sogan 2- Maydanoz 3- Nane",
        "Malzemeleri sec 1- Sarimsak 2- Zencefil 3- Kekik",
        "Malzemeleri sec 1- Isot 2- Kajun Baharati 3- Doritos",
        "Malzemeleri sec 1- Limon 2- Limon Tuzu 3- Tuz",
        "Malzemeleri sec 1- Misir Yagi 2- Zeytinyagi 3- Motor Yagi",
        "Malzemeleri sec 1- Nar Eksisi 2- Meyan Koku 3- Bal"
    };

    int correctAnswers[9] = {1, 2, 1, 1, 1, 1, 1, 2, 1};

    cout << "Bulut ve Boncugun burunlarina bir suredir gelmeyen yemek kokusu bu odada gelmistir. Dustukleri ilk anda bu mutfagin normal bir ev mutfagi olmadigini anlamislardir.\n"
        << "Burasi bir restoranin mutfagi gibidir. Yemek kokularina bakilirsa onlardan biraz once burada yemek yapilmistir. Fakat garip olan sey ise mutfakta kimsenin olmayisidir.\n"
        << "Restoranin mutfagindan iceriye dogru gittiklerinde iceride bir suru yemegini bekleyen musteri ve yapilan yemekleri goturmeyi bekleyen garson oldugunu gorurler.\n"
        << "Garsonlardan birisi onlari gordugu gibi yanlarina gelir. Insanlarin yemek bekledigini ve Bulut'un elini cabuk tutup yemek yapmasi gerektigini soyler.\n"
        << "Bulut bu duruma anlam veremez daha oncesin hic yemek yapmak gibi bir deneyimi olmamistir. Garsonun dediklerinin saskinligiyla ikisi birden mutfaga donerler.\n"
        << "Ne yani daha oncesinde yemek yapmakla alakasi olmayan bulut yemek mi yapacakti? Tam olarak da oyle olur ve onlerinde yazan gunun menusunu gorurler.\n"
        << "Birkacinin yaninda tik isareti konulmustur. Sadece bir tanesinin yaninda isaret yoktur. Buradan mantik yuruterek onu yapmalari gerektigini dusunurler.\n"
        << "Ve yemeklerin arasinda yapacaklari yemek olarak sayilamayacak olan ama listede bulunan cigkoftenin tarifini bulurlar. Ilk once gereken malzemeleri yabanci olduklari bu mutfagin neresinde olduklarini bulmalari gerekmektedir.\n"
        << "Boncuk eliyle koymus gibi hepsini tezgaha getirir. Ama Bulut'un gordugu kadariyla burada fazla malzemeler de vardir. Bulut'un onlari tarife gore ayirmasi gerekmektedir.\n\n";

    for (int i = 0; i < 9; i++) {
        correctAnswer = false;
        while (!correctAnswer) {
            cout << questions[i] << endl;
           while (true)
           {
             cin>>answer;
             if (cin.fail())
             {
                cout<<"Hatali Giris Yaptiniz Tekrar Deneyin!!!"<<endl;
                cin.clear();
                cin.ignore(10000,'\n');
             }else{
                break;
             }
             
           }
            if (answer > 3 || answer < 1) {
                cout << "Yanlis karakter!" << endl;
            }else if(answer == correctAnswers[i]){
                cout << "Dogru secim!" << endl;
                correctAnswer = true;
            }else {
                cout << "Yanlis secim. Tekrar Dene." << endl;
                mistakeCount++;
            }
        }
    }

    cout << "\nGereken butun malzemeleri sectiklerinde geriye onlari birlestirmek kalmistir. Bulut nasil yoguracagini dusunurken karsisindaki cigkofte yogurma aletini gorur. Bu geldikleri odada isler cok gariptir.\n"
        << "Hem kendileri sef saniliyordur hem de teknoloji cok gelismistir. Cigkoftenin malzemelerini makinanin icerisine koyarlar. Makine yogurmaya baslamistir bile.\n"
        << "Boncuk azcik bir parca alarak tadi baktiginda limonunun az oldugunu soyler ve Bulut''tan habersiz biraz daha limon ekler. Bulut tadi baktiginda ise limonunun fazla oldugunu ve bunu ancak isot baharatinin dengeleyecegini soyleyerek fazlaca isot ekler.\n"
        << "Cigkofte yapma yuzunden aralarinda ilk defa bir anlasmazlik yasanmistir. En sonunda olusan cigkoftenin icerisinde fazlaca isot ve limon olmasina ragmen servis edilmeye hazirdir.\n"
        << "Garsonlar gelip once yapilan yemeklerle birlikte cigkofteyi de bir tabakta sunarlar. Ve icerideki musterilere gotururler. Bir sure mutfakta oyalandiktan sonra garsonlardan bir tanesi gelir ve onlara bir musterinin kendilerinin cagirdiklarini soyler.\n"
        << "Bulut ve Boncuk yaptiklari cigkofteden memnun kalinmadigi icin cagirildiklarini dusunurken musteri cigkofteyi cok begendigini soyler. Ikisi birden cok sasirirlar megerse musteri tam olarak da boyle bir cigkofte istiyormus.\n"
        << "Onlara bu guzel tadin karsiliginda bir hediye vermek istedigini belirtir ,yanindaki cantadan uzerinde Saturn simgesi olan iki tane sef sapkasi cikarir ve hem kediye hem de cocuga takar yaninda da kendi kartvizitini verir.\n"
        << "Aslinda bu kisinin baska bir restoranin sahibi ve onlari kendi restoraninda cigkofte yapmak icin cagiran birisi oldugunu anlarlar.\nCok guzel bir teklif olsa da bunu kabul edemeyeceklerini bildikleri icin teklifi reddedip hediyeyi kabul eden Bulut ve Boncuk mutfaga dogru yonelirler. Iceri girdikleri anda kendilerini bir portalda bulurlar.\n";
    return mistakeCount;
}

#endif