#ifndef MATH_H
#define MATH_H

#include <iostream>
#include <ctime>
#include <tuple>

void PrintIntroduction(int Difficulty)
{
    std::cout << "\n\nSoru " << Difficulty;
    std::cout << " Asagidaki soruyu cevaplayin...\n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    // Generate Code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;
    
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;


    // Print CodeSum and CodeProduct to the terminal
    std::cout << "+ Bu soruda 3 tane sayimiz var";
    std::cout << "\n+ Toplamlari: " << CodeSum;
    std::cout << "\n+ Carpimlari: " << CodeProduct << std::endl;
    std::cout << "\nSayilar nelerdir?\n" << std::endl;

    // Store player guess
    int GuessA, GuessB, GuessC;
    while (true)
    {
       std::cin >> GuessA >> GuessB >> GuessC;
       if (std::cin.fail())
       {
         std::cout<<"Hatali Sayi girdiniz Tekrar Giriniz!!!!Butun Sayilari Bastan Giriniz:"<<std::endl;
         std::cin.clear();
         std::cin.ignore(10000,'\n');
       }else{
        break;
       }
       
    }
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if the players guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n*** Tebrikler! Soruyu dogru yaptin. ***";
        return true;
    }
    else
    {
        std::cout << "\n*** Cevap Yanlis! Dikkatli ol! Tekrar Dene! ***";
        return false;
    }
}

int startMathGame(){
    int hatasayisi = 0;
    srand(time(NULL)); // create new random sequence based on time of day
    
    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;

    std::cout << "Bu universiteye giris icin kartinin olup okutulmasi gerekmektedir fakat ne Bulut'ta ne de Boncuk'ta bu kart vardir. Giris icin olusan kalabaliga bir bakarlar.\n"
        << "Buraya girmenin tek sansi kalabaligin arasina kaynayip guvenlikler fark etmeden gecmektir. Oyle de yaparlar, iceriye girmeyi basarmislardir. Ilk defa boylarinin kisa olmasi bir ise yaramistir.\n"
        << "Nereye gideceklerini bilmezken ondekilerin konusmasina tanik olurlar. Yeni bir matematik profesorunun geldigini ve bugun isteyen kisilerin gidebilecegi bir ders oldugunu konusurlar.\n"
        << "Bulut'un en sevdigi dersin matematik olmasi dolayisiyla merak edip derse girmek isterler. Bundan sonra dersin oldugunu duyduklari kisilerin pesine takilirlar. \nAsansorlere dogru yonelen gencler asansore binmislerdir fakat yer kalmadigi icin Bulut ve Boncuk binememistir.\n"
        << "Neyse ki asansorun dugmesinde kacinci katin basili oldugunu gormuslerdir. Bir sonraki asansor geldiginde sadece ikisi binerek 3. kata basmislardir.";

    std::cout << "\nAsansorun dugmesine basmak icin herhangi bir tusa basin...\n";
    {
        std::string a; 
        std::cin >> a;
    }

    std::cout << "Geldikleri katta bir suru derslik vardir. Hangisine gideceklerini bilmezler ve kalabaligin onlarin dersi oldugu sinifa goturecegini dusunerek peslerine takilip giderler.\n"
        << "Tam da dusundukleri gibi olmustur. O herkesin konustugu sinifa gelmislerdir. Gerci buraya sinif demek haksizlik olurdu. Burasi koskocaman bir amfiydi.\n"
        << "Ustten alcalarak gelen oturma yerleri sayesinde herkes hocayi net bir sekilde gorebiliyordu. Butun ogrenciler gibi Bulut'la Boncuk da bir yere otururlar.\n"
        << "Dersin hocasi konusmaya basladigi gibi herkes bir anda sessizlesir. Hoca kendini tanitip sonrasinda bir sinav yapacagini soyleyerek herkesi hayal kirikligina ugratir.\n"
        << "Onlerine kagit geldiginde cozmeye calisirlar. Boyle bir sinava hazirliksiz olduklari icin cantalarinda ne silgi ne de kalem vardir. Yanlarinda oturan kizdan fazla kalem ve silgi alirlar sonrasinda sinavi cozmeye baslarlar.\n";

    while (LevelDifficulty <= MaxDifficulty) // Loop game until all levels completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete) 
        {
            ++LevelDifficulty;
        }else{
            ++hatasayisi;
        }
    }
    std::cout << "\nSinav tamamlandiktan sonra herkesin kagidi birer birer toplanir ve derse katilim sagladiklari icin bir hediye verilir. Bu hediye ustunde Saturn simgesi olan yapboz parcalarindan olusmaktadir\n"
        << "Bunu eve goturebilmeleri icin ilk once yapbozu yapmalari gerekmektedir. Derse ara verildiginde yapbozu alip okulun bol yesillikli bahcesine cikarlar. Orada oturup yapbozu tamamlarlar fakat bir butun halinde durmasi icin bant gerekmektedir.\n"
        << "Yanlarinda onlar gibi yapbozu yapan kisilerin oldugunu gorunce bant vardir diye bir ihtimal onlara sorarlar. Sans eseri 3. sorduklari kiside bant vardir ve alip yapistirirlar.\n"
        << "Yapboz tamamdir ama ya gecit nerededir? Ellerinde yapboz olan insanlarin girdigi bir cadir vardir. Bulut ve Boncuk onlari takip ederek iceri girerler. Normal insanlar yapbozu tamamlanmis resmini cadirdaki sisteme yukediginde +10 puan veriyodur.\n"
        << "Fakat bunu Bulut yaptiginda bir sonraki odaya gecmelerine yarayan gecit acilmaktadir...";

    return hatasayisi;
}

#endif