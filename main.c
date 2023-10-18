#include <stdio.h>
#include <stdlib.h>

void diziYazdir(int elemanSayisi, int *dizi)
{
    printf("\nolusan dizi : ");

    for(int i=0; i<elemanSayisi; i++)
    {
        printf("%d ", dizi[i]);
    }
}


void pointerYazdir(int *sayiptr)
{
    printf("\nx degiskeninin adresi : %p\n", sayiptr);
    printf("Ptr gosterdigi deger  : %d\n", *sayiptr);
}


struct Liste
{
    int data;
    struct Liste* next;
};

struct Liste* yeniStructOlustur(int data) {
    struct Liste* yeniListe = (struct Liste*)malloc(sizeof(struct Liste));
    yeniListe->data = data;
    yeniListe->next = NULL;
    return yeniListe;
}



int main()
{
    for(int i=0;;i++)
    {
        printf("hosgeldiniz...\n1 - dizi\n2 - pointer\n3 - struct\n0 - cikis\n");

        int secim;
        printf("secim yapiniz : ");
        scanf("%d", &secim);

        if(secim==1)
        {
            int elemansayisi;
            printf("\neleman sayisi giriniz : ");
            scanf("%d", &elemansayisi);
            int dizi[elemansayisi];

            for(int i=0; i<elemansayisi; i++)
            {
                printf("eleman %d giriniz : ", i+1);
                scanf("%d", &dizi[i]);
            }

            diziYazdir(elemansayisi,dizi);

        }
        else if(secim==2)
        {
            int sayi, *sayiPtr;
            printf("\nx sayisini giriniz : ");
            scanf("%d", &sayi);

            sayiPtr = &sayi;

            pointerYazdir(sayiPtr);

        }
        else if(secim==3)
        {
            struct Liste* ilk = NULL;
            struct Liste* mevcut = NULL;

            printf("\n");
            int a=0;

            for (int i = 1; ; i++)
            {
                a++;
                printf("%d. degeri gir: ", a);
                int deger;
                scanf("%d", &deger);

                struct Liste* yeni = yeniStructOlustur(deger);

                if (ilk == NULL)
                {
                    ilk = yeni;
                    mevcut = yeni;
                }

                else
                {
                    mevcut->next = yeni;
                    mevcut = yeni;
                }

                if(i>4)
                {
                    printf("baska deger girmek icin Y, devam icin herhangi tus: ");
                    char sor;
                    sor = getche();

                    if(sor=='y' || sor=='Y')
                    {
                        printf("\n");
                        i=0;
                        continue;
                    }

                    else
                        break;
                }

            }


            struct Liste* gecici = ilk;

            printf("\nkacinci degeri istersiniz? : ");
            int i=1, sira;
            scanf("%d", &sira);

            while (i!=sira)
            {
                gecici = gecici->next;
                i++;
            }

            printf("Deger %d: %d\n", sira, gecici->data);



        }
        else if(secim==0)
        {
            printf("\niyi gunler :)\n");
            break;
        }
        else
        {
            printf("hatali giris. tekrar deneyiniz.\n\n");
            continue;
        }

        printf("\n\nBaska islem yapmak istiyor musunuz?\nEvet icin Y, Hayir icin herhangi bir tusa basin : ");

        char tamamDevam;
        tamamDevam = getche();

        if(tamamDevam=='y' || tamamDevam=='Y')
        {
            system("cls");
            printf("tekrar ");
            continue;
        }
        else
        {
            printf("\n\niyi gunler :)\n");
            break;
        }


    }



    return 0;
}
