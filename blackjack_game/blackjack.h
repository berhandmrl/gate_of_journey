#ifndef BLACKJACK_H
#define BLACKJACK_H

//include space
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<process.h>

//defining symbols
#define spade 06 //Used to print spade symbol
#define club 05  //Used to print club symbol
#define diamond 04 //Used to print diamond symbol
#define heart 03 //Used to print heart symbol

using namespace std;

//glbal variables
int i; //to switch between player and dealer
int a; //for 1 to 13 of player
int b; //for 1 to 4 of player
int c; //for 1 to 13 of dealer
int d; // for 1 to 4 of dealer
int tot1; //total for player
int tot2; //total for dealer
int final1; //total of player for stand
int final2; //total of dealer after player stands
char play_ch; //choose between hit or stand 

//functions used
int choices();
void num_cards_player(int su1);
void face_cards_player(int ca1);
void num_cards_dealer(int su2);
void face_cards_dealer(int ca2);
void rules();
int play();

int choices()
{
		printf("Oynamaya Haziz Misin?\n\n");
		char cho; //Choice to start or exit
		int aa;
		scanf("%c",&cho);
    	aa = play();
		return aa;
}
void num_cards_player(int su1)
{
	if(su1==1)
	{
		printf("-------\n");
    	printf("|%c    |\n", heart); 
    	printf("|  %d  |\n", a);
    	printf("|    %c|\n", heart);
    	printf("-------\n");
		printf("Kupa %d cektin \n",a);
	}
	else if(su1==2)
	{
	printf("-------\n");
    printf("|%c    |\n", diamond);
    printf("|  %d  |\n", a);
    printf("|    %c|\n", diamond);
    printf("-------\n");
	printf("Karo %d cektin \n",a);	
	}
	else if(su1==3)
	{
	printf("-------\n");
    printf("|%c    |\n", spade);
    printf("|  %d  |\n", a);
    printf("|    %c|\n", spade);
    printf("-------\n");
	printf("Maca %d cektin \n",a);
	}
	else if(su1==4)
	{
	printf("-------\n");
    printf("|%c    |\n", club);
    printf("|  %d  |\n", a);
    printf("|    %c|\n", club);
    printf("-------\n");
	printf("Sinek %d cektin \n",a);
	}
}
void face_cards_player(int ca1)
{
	if(ca1==11)
	{
		if(b==1)
		{
		printf("-------\n");
    	printf("|%c    |\n", heart);
    	printf("|  J  |\n");
    	printf("|    %c|\n", heart);
    	printf("-------\n");
		printf("Kupa J cektin\n");
		a=10;}
		else if(b==2)
		{
		printf("-------\n");
    	printf("|%c    |\n", diamond);
    	printf("|  J  |\n");
    	printf("|    %c|\n", diamond);
    	printf("-------\n");
		printf("Karo J cektin\n");
		a=10;}
		else if(b==3)
		{
		printf("-------\n");
    	printf("|%c    |\n", spade);
    	printf("|  J  |\n");
    	printf("|    %c|\n", spade);
    	printf("-------\n");
		printf("Maca J cektin\n");
		a=10;}
		else if(b==4)
		{
		printf("-------\n");
    	printf("|%c    |\n", club);
    	printf("|  J  |\n");
    	printf("|    %c|\n", club);
    	printf("-------\n");
		printf("Sinek J cektin\n");
		a=10;}
	}
	else if(ca1==12)
	{
		if(b==1)
		{
		printf("-------\n");
    	printf("|%c    |\n", heart);
    	printf("|  Q  |\n");
    	printf("|    %c|\n", heart);
    	printf("-------\n");
		printf("Kupa Q cektin\n");
		a=10;}
		else if(b==2)
		{
		printf("-------\n");
    	printf("|%c    |\n", diamond);
    	printf("|  Q  |\n");
    	printf("|    %c|\n", diamond);
    	printf("-------\n");
		printf("Karo Q cektin\n");
		a=10;}
		else if(b==3)
		{
		printf("-------\n");
    	printf("|%c    |\n", spade);
    	printf("|  Q  |\n");
    	printf("|    %c|\n", spade);
    	printf("-------\n");
		printf("Maca Q cektin\n");
		a=10;}
		else if(b==4)
		{
		printf("-------\n");
    	printf("|%c    |\n", club);
    	printf("|  Q  |\n");
    	printf("|    %c|\n", club);
    	printf("-------\n");
		printf("Sinek Q cektin\n");
		a=10;}
	}
	else if(ca1==13)
	{
		if(b==1)
		{
		printf("-------\n");
    	printf("|%c    |\n", heart);
    	printf("|  K  |\n");
    	printf("|    %c|\n", heart);
    	printf("-------\n");
		printf("Kupa K cektin\n");
		a=10;}
		else if(b==2)
		{
		printf("-------\n");
    	printf("|%c    |\n", diamond);
    	printf("|  K  |\n");
    	printf("|    %c|\n", diamond);
    	printf("-------\n");
		printf("Karo K cektin\n");
		a=10;}
		else if(b==3)
		{
		printf("-------\n");
    	printf("|%c    |\n", spade);
    	printf("|  K  |\n");
    	printf("|    %c|\n", spade);
    	printf("-------\n");
		printf("Maca K cektin\n");
		a=10;}
		else if(b==4)
		{
		printf("-------\n");
    	printf("|%c    |\n", club);
    	printf("|  K  |\n");
    	printf("|    %c|\n", club);
    	printf("-------\n");
		printf("Sinek K cektin\n");
		a=10;}
	}
}
void num_cards_dealer(int su2)
{
	if(su2==1)
	{
	printf("-------\n");
    printf("|%c    |\n", heart); 
    printf("|  %d  |\n", c);
    printf("|    %c|\n", heart);
    printf("-------\n");
	printf("Kurpiyer Kupa %d cekti \n",c);}
	else if(su2==2)
	{
	printf("-------\n");
    printf("|%c    |\n", diamond);
    printf("|  %d  |\n", c);
    printf("|    %c|\n", diamond);
    printf("-------\n");
	printf("Kurpiyer Karo %d cekti \n",c);}
	else if(su2==3)
	{
	printf("-------\n");
    printf("|%c    |\n", spade);
    printf("|  %d  |\n", c);
    printf("|    %c|\n", spade);
    printf("-------\n");
	printf("Kurpiyer Maca %d cekti \n",c);}
	else if(su2==4)
	{
	printf("-------\n");
    printf("|%c    |\n", club);
    printf("|  %d  |\n", c);
    printf("|    %c|\n", club);
    printf("-------\n");
	printf("Kurpiyer Sinek %d cekti \n",c);}
}
void face_cards_dealer(int ca2)
{
	if(ca2==11)
	{
		if(d==1)
		{
		printf("-------\n");
    	printf("|%c    |\n", heart);
    	printf("|  J  |\n");
    	printf("|    %c|\n", heart);
    	printf("-------\n");
		printf("Kurpiyer Kupa J cekti\n");
		c=10;}
		else if(d==2)
		{
		printf("-------\n");
    	printf("|%c    |\n", diamond);
    	printf("|  J  |\n");
    	printf("|    %c|\n", diamond);
    	printf("-------\n");
		printf("Kurpiyer Karo J cekti\n");
		c=10;}
		else if(d==3)
		{
		printf("-------\n");
    	printf("|%c    |\n", spade);
    	printf("|  J  |\n");
    	printf("|    %c|\n", spade);
    	printf("-------\n");
		printf("Kurpiyer Maca J cekti\n");
		c=10;}
		else if(d==4)
		{
		printf("-------\n");
    	printf("|%c    |\n", club);
    	printf("|  J  |\n");
    	printf("|    %c|\n", club);
    	printf("-------\n");
		printf("Kurpiyer Sinek J cekti\n");
		c=10;}
	}
	else if(ca2==12)
	{
		if(d==1)
		{
		printf("-------\n");
    	printf("|%c    |\n", heart);
    	printf("|  Q  |\n");
    	printf("|    %c|\n", heart);
    	printf("-------\n");
		printf("Kurpiyer Kupa Q cekti\n");
		c=10;}
		else if(d==2)
		{
		printf("-------\n");
    	printf("|%c    |\n", diamond);
    	printf("|  Q  |\n");
    	printf("|    %c|\n", diamond);
    	printf("-------\n");
		printf("Kurpiyer Karo Q cekti\n");
		c=10;}
		else if(d==3)
		{
		printf("-------\n");
    	printf("|%c    |\n", spade);
    	printf("|  Q  |\n");
    	printf("|    %c|\n", spade);
    	printf("-------\n");
		printf("Kurpiyer Maca Q cekti\n");
		c=10;}
		else if(d==4)
		{
		printf("-------\n");
    	printf("|%c    |\n", club);
    	printf("|  Q  |\n");
    	printf("|    %c|\n", club);
    	printf("-------\n");
		printf("Kurpiyer Sinek Q cekti\n");
		c=10;}
	}
	else if(ca2==13)
	{
		if(d==1)
		{
		printf("-------\n");
    	printf("|%c    |\n", heart);
    	printf("|  K  |\n");
    	printf("|    %c|\n", heart);
    	printf("-------\n");
		printf("Kurpiyer Kupa K cekti\n");
		c=10;}
		else if(d==2)
		{
		printf("-------\n");
    	printf("|%c    |\n", diamond);
    	printf("|  K  |\n");
    	printf("|    %c|\n", diamond);
    	printf("-------\n");
		printf("Kurpiyer Karo K cekti\n");
		c=10;}
		else if(d==3)
		{
		printf("-------\n");
    	printf("|%c    |\n", spade);
    	printf("|  K  |\n");
    	printf("|    %c|\n", spade);
    	printf("-------\n");
		printf("Kurpiyer Maca K cekti\n");
		c=10;}
		else if(d==4)
		{
		printf("-------\n");
    	printf("|%c    |\n", club);
    	printf("|  K  |\n");
    	printf("|    %c|\n", club);
    	printf("-------\n");
		printf("Kurpiyer Sinek K cekti\n");
		c=10;}
	}
}
void rules()
{
	printf("\n           BLACKJACK KURALLARI");
     printf("\n          ---------------------------");
     printf("\nI.");
     printf("\n     Bu oyunun olasiliklarini sorgulamayacaksin.");
     printf("\n      %c Bu program kartlari rastgele olusturur.", spade);
     printf("\n      %c Eger surekli kaybediyorsan, cok sanssizsin!\n", diamond);
      
     printf("\nII.");
     printf("\n     Her kartin bir degeri vardir.");
     printf("\n      %c 1'den 10'a kadar olan sayi kartlari, numaralarinin degerine sahiptir.", spade);
     printf("\n      %c J, Q ve K kartlari 10 degerindedir.", diamond);
     printf("\n      %c As kartlari 11 degerindedir", club);
     printf("\n     Bu oyunun amaci, kartlarin toplam degerinin 21 olmasina ulasmaktir.\n");
      
     printf("\nIII.");
     printf("\n     Ilk iki kart dagitildiktan sonra, DEVAM ETMEK veya DURMAK zorundasin.");
     printf("\n      %c Durmak seni guvende tutar, devam etmek bir kart ekler.", spade);
     printf("\n     cunku saticiya karsi yarisiyorsun, onun elini yenmek zorundasin.");
     printf("\n     ANCAK DIKKAT ET!.");
     printf("\n      %c Eger toplamin 21'i gecerse, KAYBEDERSIN!.", diamond);
     printf("\n     Ama dunya sonu degil, cunku her zaman tekrar oynayabilirsin.\n");
     printf("\n\n");
}

int play()
{	
	int sayi = 0;
	tot1=0;
	tot2=0;
	srand(time(0));
	while(tot1<21 && tot2<21)
	{
		printf("Kart Mi Cekmek İstersin yoksa Beklemek Mi Istersin\n");
        printf("Cekme(H),Bekleme(S)");
		scanf("%s",&play_ch);
		a=rand() % 13 + 1;
		b=rand()% 4 + 1;
		c=rand() % 13 + 1;
		d=rand()% 4 + 1;
		if(play_ch=='H' || play_ch=='h')
		{
			if(tot2<17)
			{
				if(a<=10)
				{
					num_cards_player(b);
				}
				else
				{
					face_cards_player(a);
				}
				if(c<=10)
				{
					num_cards_dealer(d);
				}
				else
				{
					face_cards_dealer(c);
				}
				tot1+=a;
				tot2+=c;
				system("pause");
				printf("Elindeki Sayi: %d\n",tot1);
				system("pause");
				printf("Kurpiyerin Elindeki Sayi: %d\n",tot2);
				system("pause");
			}
			else if(tot2>=17)
			{
				if(a<=10)
				{
					num_cards_player(b);
				}
				else
				{
					face_cards_player(a);
				}
				tot1+=a;
				system("pause");
				printf("Elindeki Sayi: %d\n",tot1);
				system("pause");
				printf("Kurpiyerin Elindeki Sayi: %d\n",tot2);
				system("pause");
			}
			final1=tot1;
			final2=tot2;
		}
		else if(play_ch=='S' || play_ch=='s')
		{
			if(tot2>17)
			{
				final1=tot1;
				final2=tot2;
				system("pause");
				printf("Elindeki Sayi: %d\n",final1);
				system("pause");
				printf("Kurpiyerin Elindeki Sayi: %d\n",final2);
				system("pause");
			}
			else if(tot2<17)
			{
				final1=tot1;
				while(tot2<17)
				{
					system("pause");
					printf("Kurpiyerin Eli 17'nin Altinda Oldugu İcin Cekmeye Devam Ediyor...\n");
					printf("Elindeki Sayi:%d\n",final1);
					c=rand() % 13 + 1;
					d=rand()% 4 + 1;
					if(c<=10)
					{
						num_cards_dealer(d);
					}
					else
					{			
						face_cards_dealer(c);
					}
					tot2+=c;
					system("pause");
					printf("Kurpiyerin Elindeki Sayi: %d\n",tot2);
					system("pause");
				}
				final2=tot2;
				system("pause");
				printf("Elindeki Sayi:%d\n",final1);
//				printf("Kurpiyerin Elindeki Sayi: %d\n",final2);
			}
			break;
		}
	}
	if(final1>21 && final2<21)
	{
		system("cls");
		printf("Uzgunum\n");
		printf("21'i Gectiniz\n");
		printf("Kaybettiniz\n");
		sayi = 0;
	}
	else if(final2>21 && final1<21)
	{
		system("cls");
		printf("Tebrikler\n");
		printf("Kurpiyer 21' Gecti\n");
		printf("Kazandiniz\n");
		sayi = 25;
	}
	else if(final1>21 && final2>21)
	{
		system("cls");
		printf("YAAY!!\n");
		printf("Kurpiyer 21' Gecti\n");
		printf("Kanazdiniz\n");
		sayi = 25;
	}
	else if(final1<21 && final2<21 &&final1>final2)
	{
		system("cls");
		printf("YAAY!!\n");
		printf("Elindeki Sayi Kurpiyerden Daha Fazla\n");
		printf("Kazandiniz\n");
		sayi = 25;
	}
	else if(final1<21 && final2<21 &&final1<final2)
	{
		system("cls");
		printf("Aw Snap!\n");
		printf("Elindeki Sayi Kurpiyerden Daha Az\n");
		printf("Kaybettiniz\n");
		sayi = 0;
	}
	else if(final1==21)
	{
		system("cls");
		printf("Vay Canina!!\n");
		printf("21'e Ulastiniz\n");
		printf("Kazandiniz\n");
		sayi = 25;
	}
	else if(final2==21)
	{
		system("cls");
		printf("Aw Snap!\n");
		printf("Kurpiyer 21 Oldu\n");
		printf("Kaybettiniz\n");
		sayi = 0;
	}
	printf("\n\n");
	printf("Oyun Bitti\n");
	return 13;
	
}
void rg1(){
	printf("Bulut ve boncuk gecitten gectikten sonra cok tuhaf bir yere duserler. Burasi renkli isiklarla aydinlatilmis cok yuksek sesler olan bir mekandir. Neresi oldugunu anlamaya calisirlar. Iceride biraz gezindiklerinde burada bazi insanlarin cok uzgun bazi insanlarinise cok mutlu oldugunu gorurler. uzgun olanlar milyonlarini kaybetmislerdir bu sebepten dolayi cok uzgunlerdir. Mutlu olanlar ise tek bir oyunla milyonlar kazanmistir. En son duvara baktiklarinda yaziyi okurlar ve burasinin bir kumarhane oldugunu anlarlar.\nBurasi kucuk bir cocuk ve kedi icin tehlikeli bir yere benziyordur. Bir an once uzaklasmak isterler fakat tilsimli esyayi bulmadan buradan kurtulamayacaklarini biliyorlardir. Tilsimli esyayi aramaya baslarlar ama ne aradiklarini dahi bilmiyorlardir. Oradaki\nbir guvenlik Bulut'u gorur ve yanina gelir.\n" 
 "-Guvenlik: Siz buraya nasil girdiniz?\n" 
 "-Bulut: Biz buraya isinlandik bilincli olarak girmedik. Lutfen bize yardim edin bir an once cikmak istiyoruz.\n"
 "-Guvenlik: Ne yapmami istiyorsunuz?\n"
 "-Bulut: uzerinde Saturn simgesi olan bir esya bulmamiz gerekli ama ne bulmamiz gerektigini biz de bilmiyoruz. Sizin gozunuze hic boyle bir sey carpti mi?\n"
 "-Guvenlik: Galiba gordum boyle  bir sey. su karsidaki krupiyeyi goruyor musun? Iste onun elindeki kartlardan birisinin uzerinde Saturn simgesi oldugunu fark ettim gibi. Isterseniz gidip onunla bir konusun.\n"
 "Bulut ve Boncuk krupiye ile konusmak icin yanlarina giderler. Dertlerini anlatirlar … .Krupiye bu kartin onda oldugunu soyler fakat bir sartla onlara verecegini ekler. Bulut ile karsilikli bir kagit oyunu oynayacagini teklif eder. Bulut teklifi kabul eder ve oyunu oynamaya baslarlar.");
}

void rg2(){
    printf("Oyun sonunda bitmistir. Bulut oyunu kazanmistir ve karti almistir. Artik buradan cikis vakti gelmistir. Gecit acilir ve diger odaya gecerler.");
}


int startBlackjackGame(){
    rg1();

	int sayi = 0;	
	int choice=-1; 
    while(choice != 1 || choice != 2 || choice != 3)
    {
		printf("\nBlackJack Oyununa Hosgeldin");
		printf("\nOyunu Baslatmak Icin 1'e Bas");
    	printf("\nKurallari Goruntulemek Icin 2'ye Bas");
    	printf("\nSecimini Yap:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:{
				system("cls");
				sayi = play();
				printf("SAYI DEGISKENI %d!!\n" ,sayi);
				return sayi;
				break;
			}
			case 2:{
				system("cls");
				rules();
				sayi = 0;
				sayi = choices();
				
				return sayi;
				break;
			}
			default:{
				printf("Yanlis Giris Yaptiniz Tekrar Deneyin!!!!!\n");
				break;
			}
		}
	}
    rg2();
	return sayi;
}

#endif