#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
//Aziz Yelbay 170201046-Onur Kus 170201030
struct yol
{
    char yol;
    char aracsayisi[5];
}
giris[2],cikis[2],arayol[5];
BITMAP *resimc;
void BirinciHaritaIslemleri();
void IkinciHaritaIslemleri();
void MatriseYerlestir();
int esittirbul();
void HaritaCiz();
int main()
{

    allegro_init();
    install_keyboard();
    set_color_depth(16);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,520,0,0);
    set_window_title("Harita");

    int harita;
    resimc=load_bitmap("haritasecimi.bmp",0);
    draw_sprite(screen,resimc,0,0);
    while(1)
    {
        printf("Haritayi seciniz (1/2) =");
        scanf("%d",&harita);
        if(harita==1 || harita==2)
            break;
    }
    printf("\nHaritayi gormek icin Harita ekranina tiklayiniz...\n");
    clear_bitmap(screen);

    if(harita==1)
    {
        BirinciHaritaIslemleri();
    }
    else if(harita==2)
    {
        IkinciHaritaIslemleri();
    }

    readkey();
    destroy_bitmap(resimc);
    return 0;
}
END_OF_MAIN();

void BirinciHaritaIslemleri()
{

    char denklem[5][50];
    int i;
    int sayac=1;
    arayol[0].yol='a',arayol[1].yol='b',arayol[2].yol='c',arayol[3].yol='d';
    char baslangic[4];// 0,1=a     2,3=b   4,5=c   6,7=d   8,9=e
    char yonu[4];
    resimc=load_bitmap("harita1.bmp",0);
    draw_sprite(screen,resimc,0,0);
    fflush(stdin);
    printf("x y z t yollarindan ikisi giris ikisi cikis olmali.\n");
    printf("1. Giris yolunu giriniz=");
    scanf("%c",&giris[0].yol);
    fflush(stdin);
    printf("2. Giris yolunu giriniz=");
    scanf("%c",&giris[1].yol);
    fflush(stdin);
    printf("1. Cikis yolunu giriniz=");
    scanf("%c",&cikis[0].yol);
    fflush(stdin);
    printf("2. Cikis yolunu giriniz=");
    scanf("%c",&cikis[1].yol);
    fflush(stdin);
    printf("x ve t yollarindan biri baslangic noktasi digeri yonu olmali.\n");
    printf("a yolunun Baslangic Noktasi=");
    scanf("%c",&baslangic[0]);
    fflush(stdin);
    printf("a yolunun Yonu=");
    scanf("%c",&yonu[0]);
    fflush(stdin);
    printf("x ve y yollarindan biri baslangic noktasi digeri yonu olmali.\n");
    printf("b yolunun Baslangic Noktasi=");
    scanf("%c",&baslangic[1]);
    fflush(stdin);
    printf("b yolunun Yonu=");
    scanf("%c",&yonu[1]);
    fflush(stdin);
    printf("t ve z yollarindan biri baslangic noktasi digeri yonu olmali.\n");
    printf("c yolunun Baslangic Noktasi=");
    scanf("%c",&baslangic[2]);
    fflush(stdin);
    printf("c yolunun Yonu=");
    scanf("%c",&yonu[2]);
    fflush(stdin);
    printf("z ve y yollarindan biri baslangic noktasi digeri yonu olmali.\n");
    printf("d yolunun Baslangic Noktasi=");
    scanf("%c",&baslangic[3]);
    fflush(stdin);
    printf("d yolunun Yonu=");
    scanf("%c",&yonu[3]);
    printf("\nGirdiginiz degerlere gore haritayi gormek icin Harita ekranina tiklayin...\n");
    HaritaCiz(yonu);
    printf("\nArac sayisi bilinmiyorsa -1 giriniz.\n");

    for(i=0; i<2; i++)
    {
        printf("%c yolundan gecen arac sayisi=",giris[i].yol);
        scanf("%s",&giris[i].aracsayisi[0]);
        if(!strcmp(&giris[i].aracsayisi[0],"-1"))
        {
            sprintf(&giris[i].aracsayisi[0],"k%d",sayac);
            sayac++;
        }
    }
    for(i=0; i<2; i++)
    {
        printf("%c yolundan gecen arac sayisi=",cikis[i].yol);
        scanf("%s",&cikis[i].aracsayisi[0]);
        if(!strcmp(&cikis[i].aracsayisi[0],"-1"))
        {
            sprintf(&cikis[i].aracsayisi[0],"k%d",sayac);
            sayac++;
        }
    }


    for(i=0; i<4; i++)
    {
        printf("%c yolundan gecen arac sayisi=",arayol[i].yol);
        scanf("%s",&arayol[i].aracsayisi[0]);
        if(!strcmp(&arayol[i].aracsayisi[0],"-1"))
        {
            sprintf(&arayol[i].aracsayisi[0],"k%d",sayac);
            sayac++;
        }
    }
    printf("\n-1 girilen degerlere gore bilinmeyenler olusturuldu....\n");
    printf("\n%c yolundan gecen arac sayisi=%s",giris[0].yol,&giris[0].aracsayisi[0]);
    printf("\n%c yolundan gecen arac sayisi=%s",giris[1].yol,&giris[1].aracsayisi[0]);
    printf("\n%c yolundan gecen arac sayisi=%s",cikis[0].yol,&cikis[0].aracsayisi[0]);
    printf("\n%c yolundan gecen arac sayisi=%s",cikis[1].yol,&cikis[1].aracsayisi[0]);
    printf("\n%c yolundan gecen arac sayisi=%s",arayol[0].yol,&arayol[0].aracsayisi[0]);
    printf("\n%c yolundan gecen arac sayisi=%s",arayol[1].yol,&arayol[1].aracsayisi[0]);
    printf("\n%c yolundan gecen arac sayisi=%s",arayol[2].yol,&arayol[2].aracsayisi[0]);
    printf("\n%c yolundan gecen arac sayisi=%s",arayol[3].yol,&arayol[3].aracsayisi[0]);

//-------------------------------------------------------------------DENKLEM OLUSTURMA-----------------------------------------------------------------------------------
    printf("\n\nTotal Giris-Cikis denklemi %s + %s = %s + %s\n",&giris[0].aracsayisi[0],&giris[1].aracsayisi[0],&cikis[0].aracsayisi[0],&cikis[1].aracsayisi[0]);
    sprintf(denklem[0]," %s + %s = %s + %s ",&giris[0].aracsayisi[0],&giris[1].aracsayisi[0],&cikis[0].aracsayisi[0],&cikis[1].aracsayisi[0]);

    //yonu[0]=a için  yonu[1]=b  için yonu[2]=c için  yonu[3]=d için yonu[4]=e için
    //arayol.yol[0]=a arayol.yol[1]=b arayol.yol[2]=c arayol.yol[3]=d  arayol.yol[4]=e

    //  K Kesimi icin
    if(giris[0].yol=='x')
    {
        if(yonu[0]=='x' && yonu[1]== 'x')
        {
            printf("\nK kesimi denklemi %s + %s + %s \n",&giris[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[1].aracsayisi[0]);
            sprintf(denklem[1]," %s + %s + %s ",&giris[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[1].aracsayisi[0]);
        }
        if(yonu[0]=='t' && yonu[1]== 'y')
        {
            printf("\nK kesimi denklemi %s=%s + %s \n",&giris[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[1].aracsayisi[0]);
            sprintf(denklem[1]," %s = %s + %s ",&giris[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[1].aracsayisi[0]);
        }
        if(yonu[0]=='x' && yonu[1]== 'y')
        {
            printf("\nK kesimi denklemi %s + %s=%s \n",&giris[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[1].aracsayisi[0]);
            sprintf(denklem[1]," %s + %s = %s ",&giris[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[1].aracsayisi[0]);
        }
        if(yonu[0]=='t' && yonu[1]== 'x')
        {
            printf("\nK kesimi denklemi %s + %s = %s \n",&giris[0].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[0].aracsayisi[0]);
            sprintf(denklem[1]," %s + %s = %s ",&giris[0].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[0].aracsayisi[0]);
        }
    }
    if(giris[1].yol=='x')
    {
        if(yonu[0]=='x' && yonu[1]== 'x')
        {
            printf("\nK kesimi denklemi %s + %s + %s \n",&giris[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[1].aracsayisi[0]);
            sprintf(denklem[1]," %s + %s + %s ",&giris[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[1].aracsayisi[0]);
        }
        if(yonu[0]=='t' && yonu[1]== 'y')
        {
            printf("\nK kesimi denklemi %s = %s + %s \n",&giris[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[1].aracsayisi[0]);
            sprintf(denklem[1]," %s = %s + %s ",&giris[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[1].aracsayisi[0]);
        }
        if(yonu[0]=='x' && yonu[1]== 'y')
        {
            printf("\nK kesimi denklemi %s + %s = %s \n",&giris[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[1].aracsayisi[0]);
            sprintf(denklem[1]," %s + %s = %s ",&giris[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[1].aracsayisi[0]);
        }
        if(yonu[0]=='t' && yonu[1]== 'x')
        {
            printf("\nK kesimi denklemi %s + %s = %s \n",&giris[1].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[0].aracsayisi[0]);
            sprintf(denklem[1]," %s + %s = %s ",&giris[1].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[0].aracsayisi[0]);
        }
    }
    if(cikis[0].yol=='x')
    {
        if(yonu[0]=='x' && yonu[1]== 'x')
        {
            printf("\nK kesimi denklemi %s = %s + %s \n",&cikis[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[1].aracsayisi[0]);
            sprintf(denklem[1]," %s = %s + %s ",&cikis[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[1].aracsayisi[0]);
        }
        if(yonu[0]=='t' && yonu[1]== 'y')
        {
            printf("\nK kesimi denklemi %s+%s + %s \n",&cikis[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[1].aracsayisi[0]);
            sprintf(denklem[1]," %s + %s + %s ",&cikis[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[1].aracsayisi[0]);
        }
        if(yonu[0]=='x' && yonu[1]== 'y')
        {
            printf("\nK kesimi denklemi %s + %s=%s \n",&cikis[0].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[0].aracsayisi[0]);
            sprintf(denklem[1]," %s + %s = %s ",&cikis[0].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[0].aracsayisi[0]);
        }
        if(yonu[0]=='t' && yonu[1]== 'x')
        {
            printf("\nK kesimi denklemi %s + %s = %s \n",&cikis[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[1].aracsayisi[0]);
            sprintf(denklem[1]," %s + %s = %s ",&cikis[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[1].aracsayisi[0]);
        }
    }
    if(cikis[1].yol=='x')
    {
        if(yonu[0]=='x' && yonu[1]== 'x')
        {
            printf(denklem[1],"\nK kesimi denklemi %s =%s + %s \n",&cikis[1].aracsayisi[0],&arayol[0],&arayol[1].aracsayisi[0]);
            sprintf(" %s = %s + %s ",&cikis[1].aracsayisi[0],&arayol[0],&arayol[1].aracsayisi[0]);
        }
        if(yonu[0]=='t' && yonu[1]== 'y')
        {
            printf("\nK kesimi denklemi %s + %s + %s \n",&cikis[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[1].aracsayisi[0]);
            sprintf(denklem[1]," %s + %s + %s ",&cikis[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[1].aracsayisi[0]);
        }
        if(yonu[0]=='x' && yonu[1]== 'y')
        {
            printf("\nK kesimi denklemi %s + %s = %s \n",&cikis[1].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[0].aracsayisi[0]);
            sprintf(denklem[1]," %s + %s = %s ",&cikis[1].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[0].aracsayisi[0]);
        }
        if(yonu[0]=='t' && yonu[1]== 'x')
        {
            printf("\nK kesimi denklemi %s + %s = %s \n",&cikis[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[1].aracsayisi[0]);
            sprintf(denklem[1]," %s + %s = %s ",&cikis[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[1].aracsayisi[0]);
        }
    }


    //yonu[0]=a için  yonu[1]=b  için yonu[2]=c için  yonu[3]=d için yonu[4]=e için
    //arayol.yol[0]=a arayol.yol[1]=b arayol.yol[2]=c arayol.yol[3]=d  arayol.yol[4]=e

    //  L Kesimi icin

    if(giris[0].yol=='y')
    {
        if(yonu[1]=='y' && yonu[3]== 'y')
        {
            printf("\nL kesimi denklemi %s + %s + %s \n",&giris[0].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0]);
            sprintf(denklem[2]," %s + %s + %s ",&giris[0].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0]);
        }
        if(yonu[1]=='x' && yonu[3]== 'z')
        {
            printf("\nL kesimi denklemi %s = %s + %s \n",&giris[0].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0]);
            sprintf(denklem[2]," %s = %s + %s ",&giris[0].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0]);
        }
        if(yonu[1]=='x' && yonu[3]== 'y')
        {
            printf("\nL kesimi denklemi %s + %s = %s \n",&giris[0].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[1].aracsayisi[0]);
            sprintf(denklem[2]," %s + %s = %s ",&giris[0].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[1].aracsayisi[0]);
        }
        if(yonu[1]=='y' && yonu[3]== 'z')
        {
            printf("\nL kesimi denklemi %s + %s = %s \n",&giris[0].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0]);
            sprintf(denklem[2]," %s + %s = %s ",&giris[0].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0]);
        }
    }
    if(giris[1].yol=='y')
    {
        if(yonu[1]=='y' && yonu[3]== 'y')
        {
            printf("\nL kesimi denklemi %s + %s + %s \n",&giris[1].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0]);
            sprintf(denklem[2]," %s + %s + %s ",&giris[1].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0]);
        }
        if(yonu[1]=='x' && yonu[3]== 'z')
        {
            printf("\nL kesimi denklemi %s=%s + %s \n",&giris[1].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0]);
            sprintf(denklem[2]," %s = %s + %s ",&giris[1].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0]);
        }
        if(yonu[1]=='x' && yonu[3]== 'y')
        {
            printf("\nL kesimi denklemi %s + %s = %s \n",&giris[1].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[1].aracsayisi[0]);
            sprintf(denklem[2]," %s + %s = %s ",&giris[1].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[1].aracsayisi[0]);
        }
        if(yonu[1]=='y' && yonu[3]== 'z')
        {
            printf("\nL kesimi denklemi %s + %s = %s \n",&giris[1].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0]);
            sprintf(denklem[2]," %s + %s = %s ",&giris[1].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0]);
        }
    }
    if(cikis[0].yol=='y')
    {
        if(yonu[1]=='y' && yonu[3]== 'y')
        {
            printf("\nL kesimi denklemi %s + %s =%s \n",&arayol[3].aracsayisi[0],&arayol[1].aracsayisi[0],&cikis[0].aracsayisi[0]);
            sprintf(denklem[2]," %s + %s = %s ",&arayol[3].aracsayisi[0],&arayol[1].aracsayisi[0],&cikis[0].aracsayisi[0]);
        }
        if(yonu[1]=='x' && yonu[3]== 'z')
        {
            printf("\nL kesimi denklemi %s + %s + %s \n",&cikis[0].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0]);
            sprintf(denklem[2]," %s + %s + %s ",&cikis[0].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0]);
        }
        if(yonu[1]=='x' && yonu[3]== 'y')
        {
            printf("\nL kesimi denklemi %s + %s=%s \n",&cikis[0].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0]);
            sprintf(denklem[2]," %s + %s = %s ",&cikis[0].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0]);
        }
        if(yonu[1]=='y' && yonu[3]== 'z')
        {
            printf("\nL kesimi denklemi %s + %s = %s \n",&cikis[0].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[1].aracsayisi[0]);
            sprintf(denklem[2]," %s + %s = %s ",&cikis[0].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[1].aracsayisi[0]);
        }
    }
    if(cikis[1].yol=='y')
    {
        if(yonu[1]=='y' && yonu[3]== 'y')
        {
            printf("\nL kesimi denklemi %s + %s =%s \n",&arayol[3].aracsayisi[0],&arayol[1].aracsayisi[0],&cikis[1].aracsayisi[0]);
            sprintf(denklem[2]," %s + %s = %s ",&arayol[3].aracsayisi[0],&arayol[1].aracsayisi[0],&cikis[1].aracsayisi[0]);
        }
        if(yonu[1]=='x' && yonu[3]== 'z')
        {
            printf("\nL kesimi denklemi %s + %s + %s \n",&cikis[1].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0]);
            sprintf(denklem[2]," %s + %s + %s ",&cikis[1].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0]);
        }
        if(yonu[1]=='x' && yonu[3]== 'y')
        {
            printf("\nL kesimi denklemi %s + %s = %s \n",&cikis[1].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0]);
            sprintf(denklem[2]," %s + %s = %s ",&cikis[1].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0]);
        }
        if(yonu[1]=='y' && yonu[3]== 'z')
        {
            printf("\nL kesimi denklemi %s + %s = %s \n",&cikis[1].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[1].aracsayisi[0]);
            sprintf(denklem[2]," %s + %s = %s ",&cikis[1].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[1].aracsayisi[0]);
        }
    }

    //yonu[0]=a için  yonu[1]=b  için yonu[2]=c için  yonu[3]=d için yonu[4]=e için
    //arayol.yol[0]=a arayol.yol[1]=b arayol.yol[2]=c arayol.yol[3]=d  arayol.yol[4]=e

    //  M Kesimi icin
    if(giris[0].yol=='z')
    {
        if(yonu[2]=='z' && yonu[3]== 'z')
        {
            printf("\nM kesimi denklemi %s + %s + %s \n",&giris[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[3].aracsayisi[0]);
            sprintf(denklem[3]," %s + %s + %s ",&giris[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[3].aracsayisi[0]);
        }
        if(yonu[2]=='t' && yonu[3]== 'y')
        {
            printf("\nM kesimi denklemi %s=%s + %s \n",&giris[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[3].aracsayisi[0]);
            sprintf(denklem[3]," %s = %s + %s ",&giris[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[3].aracsayisi[0]);
        }
        if(yonu[2]=='z' && yonu[3]== 'y')
        {
            printf("\nM kesimi denklemi %s + %s=%s \n",&giris[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[3].aracsayisi[0]);
            sprintf(denklem[3]," %s + %s = %s ",&giris[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[3].aracsayisi[0]);
        }
        if(yonu[2]=='t' && yonu[3]== 'z')
        {
            printf("\nM kesimi denklemi %s + %s = %s \n",&giris[0].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[2].aracsayisi[0]);
            sprintf(denklem[3]," %s + %s = %s ",&giris[0].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[2].aracsayisi[0]);
        }
    }
    if(giris[1].yol=='z')
    {
        if(yonu[2]=='z' && yonu[3]== 'z')
        {
            printf("\nM kesimi denklemi %s + %s + %s \n",&giris[1].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[3].aracsayisi[0]);
            sprintf(denklem[3]," %s + %s + %s ",&giris[1].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[3].aracsayisi[0]);
        }
        if(yonu[2]=='t' && yonu[3]== 'y')
        {
            printf("\nM kesimi denklemi %s = %s + %s \n",&giris[1].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[3].aracsayisi[0]);
            sprintf(denklem[3]," %s = %s + %s ",&giris[1].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[3].aracsayisi[0]);
        }
        if(yonu[2]=='z' && yonu[3]== 'y')
        {
            printf("\nM kesimi denklemi %s + %s=%s \n",&giris[1].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[3].aracsayisi[0]);
            sprintf(denklem[3]," %s + %s = %s ",&giris[1].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[3].aracsayisi[0]);
        }
        if(yonu[2]=='t' && yonu[3]== 'z')
        {
            printf("\nM kesimi denklemi %s + %s = %s \n",&giris[1].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[2].aracsayisi[0]);
            sprintf(denklem[3]," %s + %s = %s ",&giris[1].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[2].aracsayisi[0]);
        }
    }
    if(cikis[0].yol=='z')
    {
        if(yonu[2]=='z' && yonu[3]== 'z')
        {
            printf("\nM kesimi denklemi %s + %s = %s \n",&arayol[2].aracsayisi[0],&arayol[3].aracsayisi[0],&cikis[0].aracsayisi[0]);
            sprintf(denklem[3]," %s + %s = %s ",&arayol[2].aracsayisi[0],&arayol[3].aracsayisi[0],&cikis[0].aracsayisi[0]);
        }
        if(yonu[2]=='t' && yonu[3]== 'y')
        {
            printf("\nM kesimi denklemi %s+ %s + %s \n",&cikis[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[3].aracsayisi[0]);
            sprintf(denklem[3]," %s + %s + %s ",&cikis[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[3].aracsayisi[0]);
        }
        if(yonu[2]=='z' && yonu[3]== 'y')
        {
            printf("\nM kesimi denklemi %s + %s = %s \n",&cikis[0].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[2].aracsayisi[0]);
            sprintf(denklem[3]," %s + %s = %s ",&cikis[0].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[2].aracsayisi[0]);
        }
        if(yonu[2]=='t' && yonu[3]== 'z')
        {
            printf("\nM kesimi denklemi %s + %s = %s \n",&cikis[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[3].aracsayisi[0]);
            sprintf(denklem[3]," %s + %s = %s ",&cikis[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[3].aracsayisi[0]);
        }
    }
    if(cikis[1].yol=='z')
    {
        if(yonu[2]=='z' && yonu[3]== 'z')
        {
            printf("\nM kesimi denklemi %s + %s = %s \n",&arayol[2].aracsayisi[0],&arayol[3].aracsayisi[0],&cikis[1].aracsayisi[0]);
            sprintf(denklem[3]," %s + %s = %s ",&arayol[2].aracsayisi[0],&arayol[3].aracsayisi[0],&cikis[1].aracsayisi[0]);
        }
        if(yonu[2]=='t' && yonu[3]== 'y')
        {
            printf("\nM kesimi denklemi %s + %s + %s \n",&cikis[1].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[3].aracsayisi[0]);
            sprintf(denklem[3]," %s + %s + %s ",&cikis[1].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[3].aracsayisi[0]);
        }
        if(yonu[2]=='z' && yonu[3]== 'y')
        {
            printf("\nM kesimi denklemi %s + %s=%s \n",&cikis[1].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[2].aracsayisi[0]);
            sprintf(denklem[3]," %s + %s = %s ",&cikis[1].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[2].aracsayisi[0]);
        }
        if(yonu[2]=='t' && yonu[3]== 'z')
        {
            printf("\nM kesimi denklemi %s + %s = %s \n",&cikis[1].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[3].aracsayisi[0]);
            sprintf(denklem[3]," %s + %s = %s ",&cikis[1].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[3].aracsayisi[0]);
        }
    }

    //yonu[0]=a için  yonu[1]=b  için yonu[2]=c için  yonu[3]=d için yonu[4]=e için
    //arayol.yol[0]=a arayol.yol[1]=b arayol.yol[2]=c arayol.yol[3]=d  arayol.yol[4]=e

    //  N Kesimi icin
    if(giris[0].yol=='t')
    {
        if(yonu[0]=='t' && yonu[2]== 't')
        {
            printf("\nN kesimi denklemi %s + %s + %s \n",&giris[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0]);
            sprintf(denklem[4]," %s + %s + %s ",&giris[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0]);
        }
        if(yonu[0]=='x' && yonu[2]== 'z')
        {
            printf("\nN kesimi denklemi %s=%s + %s \n",&giris[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0]);
            sprintf(denklem[4]," %s = %s + %s ",&giris[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0]);
        }
        if(yonu[0]=='x' && yonu[2]== 't')
        {
            printf("\nN kesimi denklemi %s + %s=%s \n",&giris[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[0].aracsayisi[0]);
            sprintf(denklem[4]," %s + %s = %s ",&giris[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[0].aracsayisi[0]);
        }
        if(yonu[0]=='t' && yonu[2]== 'z')
        {
            printf("\nN kesimi denklemi %s + %s = %s \n",&giris[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0]);
            sprintf(denklem[4]," %s + %s = %s ",&giris[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0]);
        }
    }
    if(giris[1].yol=='t')
    {
        if(yonu[0]=='t' && yonu[2]== 't')
        {
            printf("\nN kesimi denklemi %s + %s + %s \n",&giris[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0]);
            sprintf(denklem[4]," %s + %s + %s ",&giris[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0]);
        }
        if(yonu[0]=='x' && yonu[2]== 'z')
        {
            printf("\nN kesimi denklemi %s=%s + %s \n",&giris[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0]);
            sprintf(denklem[4]," %s = %s + %s ",&giris[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0]);
        }
        if(yonu[0]=='x' && yonu[2]== 't')
        {
            printf("\nN kesimi denklemi %s + %s=%s \n",&giris[1].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[0].aracsayisi[0]);
            sprintf(denklem[4]," %s + %s = %s ",&giris[1].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[0].aracsayisi[0]);
        }
        if(yonu[0]=='t' && yonu[2]== 'z')
        {
            printf("\nN kesimi denklemi %s + %s = %s \n",&giris[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0]);
            sprintf(denklem[4]," %s + %s = %s ",&giris[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0]);
        }
    }
    if(cikis[0].yol=='t')
    {
        if(yonu[0]=='t' && yonu[2]== 't')
        {
            printf("\nN kesimi denklemi %s + %s = %s \n",&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0],&cikis[0].aracsayisi[0]);
            sprintf(denklem[4]," %s + %s = %s ",&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0],&cikis[0].aracsayisi[0]);
        }
        if(yonu[0]=='x' && yonu[2]== 'z')
        {
            printf("\nN kesimi denklemi %s + %s + %s \n",&cikis[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0]);
            sprintf(denklem[4]," %s + %s + %s ",&cikis[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0]);
        }
        if(yonu[0]=='x' && yonu[2]== 't')
        {
            printf("\nN kesimi denklemi %s + %s = %s \n",&cikis[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0]);
            sprintf(denklem[4]," %s + %s = %s ",&cikis[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0]);
        }
        if(yonu[0]=='t' && yonu[2]== 'z')
        {
            printf("\nN kesimi denklemi %s + %s = %s \n",&cikis[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0]);
            sprintf(denklem[4]," %s + %s = %s ",&cikis[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0]);
        }
    }
    if(cikis[1].yol=='t')
    {
        if(yonu[0]=='t' && yonu[2]== 't')
        {
            printf("\nN kesimi denklemi %s + %s = %s \n",&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0],&cikis[1].aracsayisi[0]);
            sprintf(denklem[4]," %s + %s = %s ",&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0],&cikis[1].aracsayisi[0]);
        }
        if(yonu[0]=='x' && yonu[2]== 'z')
        {
            printf("\nN kesimi denklemi %s + %s + %s \n",&cikis[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0]);
            sprintf(denklem[4]," %s + %s + %s ",&cikis[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0]);
        }
        if(yonu[0]=='x' && yonu[2]== 't')
        {
            printf("\nN kesimi denklemi %s + %s = %s \n",&cikis[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0]);
            sprintf(denklem[4]," %s + %s = %s ",&cikis[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0]);
        }
        if(yonu[0]=='t' && yonu[2]== 'z')
        {
            printf("\nN kesimi denklemi %s + %s = %s \n",&cikis[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0]);
            sprintf(denklem[4]," %s + %s = %s ",&cikis[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0]);
        }
    }

    MatriseYerlestir(denklem,sayac);

}

void IkinciHaritaIslemleri()
{

    char denklem[5][50];
    int sayac=1;
    arayol[0].yol='a',arayol[1].yol='b',arayol[2].yol='c',arayol[3].yol='d',arayol[4].yol='e';
    int i;
    char baslangic[5];
    char yonu[5];
    resimc=load_bitmap("harita2.bmp",0);
    draw_sprite(screen,resimc,0,0);
    fflush(stdin);
    printf("x y z t yollarindan ikisi giris ikisi cikis olmali.\n");
    printf("1. Giris yolunu giriniz=");
    scanf("%c",&giris[0].yol);
    fflush(stdin);
    printf("2. Giris yolunu giriniz=");
    scanf("%c",&giris[1].yol);
    fflush(stdin);
    printf("1. Cikis yolunu giriniz=");
    scanf("%c",&cikis[0].yol);
    fflush(stdin);
    printf("2. Cikis yolunu giriniz=");
    scanf("%c",&cikis[1].yol);
    fflush(stdin);
    printf("x ve t yollarindan biri baslangic noktasi digeri yonu olmali.\n");
    printf("a yolunun Baslangic Noktasi=");
    scanf("%c",&baslangic[0]);
    fflush(stdin);
    printf("a yolunun Yonu=");
    scanf("%c",&yonu[0]);
    fflush(stdin);
    printf("x ve y yollarindan biri baslangic noktasi digeri yonu olmali.\n");
    printf("b yolunun Baslangic Noktasi=");
    scanf("%c",&baslangic[1]);
    fflush(stdin);
    printf("b yolunun Yonu=");
    scanf("%c",&yonu[1]);
    fflush(stdin);
    printf("t ve z yollarindan biri baslangic noktasi digeri yonu olmali.\n");
    printf("c yolunun Baslangic Noktasi=");
    scanf("%c",&baslangic[2]);
    fflush(stdin);
    printf("c yolunun Yonu=");
    scanf("%c",&yonu[2]);
    fflush(stdin);
    printf("z ve y yollarindan biri baslangic noktasi digeri yonu olmali.\n");
    printf("d yolunun Baslangic Noktasi=");
    scanf("%c",&baslangic[3]);
    fflush(stdin);
    printf("d yolunun Yonu=");
    scanf("%c",&yonu[3]);
    fflush(stdin);
    printf("t ve y yollarindan biri baslangic noktasi digeri yonu olmali.\n");
    printf("e yolunun Baslangic Noktasi=");
    scanf("%c",&baslangic[4]);
    fflush(stdin);
    printf("e yolunun Yonu=");
    scanf("%c",&yonu[4]);
    printf("\nGirdiginiz degerlere gore haritayi gormek icin Harita ekranina tiklayin...\n");
    HaritaCiz(yonu);
    if(yonu[4]=='y')
    {
        resimc=load_bitmap("tdenyye.bmp",0);
        draw_sprite(screen,resimc,277,229);
    }
    else
    {
        resimc=load_bitmap("ydentye.bmp",0);
        draw_sprite(screen,resimc,277,229);
    }

    printf("\nArac sayisi bilinmiyorsa -1 giriniz.\n");
    for(i=0; i<2; i++)
    {
        printf("%c yolundan gecen arac sayisi=",giris[i].yol);
        scanf("%s",&giris[i].aracsayisi[0]);
        if(!strcmp(&giris[i].aracsayisi[0],"-1"))
        {
            sprintf(&giris[i].aracsayisi[0],"k%d",sayac);
            sayac++;
        }
    }
    for(i=0; i<2; i++)
    {
        printf("%c yolundan gecen arac sayisi=",cikis[i].yol);
        scanf("%s",&cikis[i].aracsayisi[0]);
        if(!strcmp(&cikis[i].aracsayisi[0],"-1"))
        {
            sprintf(&cikis[i].aracsayisi[0],"k%d",sayac);
            sayac++;
        }
    }

    for(i=0; i<5; i++)
    {
        printf("%c yolundan gecen arac sayisi=",arayol[i].yol);
        scanf("%s",&arayol[i].aracsayisi[0]);
        if(!strcmp(&arayol[i].aracsayisi[0],"-1"))
        {
            sprintf(&arayol[i].aracsayisi[0],"k%d",sayac);
            sayac++;
        }
    }
    printf("\n-1 girilen degerlere gore bilinmeyenler olusturuldu....\n");
    printf("\n\n\n%c yolundan gecen arac sayisi=%s",giris[0].yol,&giris[0].aracsayisi[0]);
    printf("\n%c yolundan gecen arac sayisi=%s",giris[1].yol,&giris[1].aracsayisi[0]);
    printf("\n%c yolundan gecen arac sayisi=%s",cikis[0].yol,&cikis[0].aracsayisi[0]);
    printf("\n%c yolundan gecen arac sayisi=%s",cikis[1].yol,&cikis[1].aracsayisi[0]);
    printf("\n%c yolundan gecen arac sayisi=%s",arayol[0].yol,&arayol[0].aracsayisi[0]);
    printf("\n%c yolundan gecen arac sayisi=%s",arayol[1].yol,&arayol[1].aracsayisi[0]);
    printf("\n%c yolundan gecen arac sayisi=%s",arayol[2].yol,&arayol[2].aracsayisi[0]);
    printf("\n%c yolundan gecen arac sayisi=%s",arayol[3].yol,&arayol[3].aracsayisi[0]);
    printf("\n%c yolundan gecen arac sayisi=%s",arayol[4].yol,&arayol[4].aracsayisi[0]);

//-----------------------------------------------------------------------DENKLEM OLUSTURMA-------------------------------------------------------------
    printf("\n\nTotal Giris-Cikis denklemi %s + %s = %s + %s\n",&giris[0].aracsayisi[0],&giris[1].aracsayisi[0],&cikis[0].aracsayisi[0],&cikis[1].aracsayisi[0]);
    sprintf(denklem[0]," %s + %s = %s + %s ",&giris[0].aracsayisi[0],&giris[1].aracsayisi[0],&cikis[0].aracsayisi[0],&cikis[1].aracsayisi[0]);
    //yonu[0]=a için  yonu[1]=b  için yonu[2]=c için  yonu[3]=d için yonu[4]=e için
    //arayol.yol[0]=a arayol.yol[1]=b arayol.yol[2]=c arayol.yol[3]=d  arayol.yol[4]=e
    //  K Kesimi icin
    if(giris[0].yol=='x')
    {
        if(yonu[0]=='x' && yonu[1]== 'x')
        {
            printf("\nK kesimi denklemi %s + %s + %s \n",&giris[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[1].aracsayisi[0]);
            sprintf(denklem[1]," %s + %s + %s ",&giris[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[1].aracsayisi[0]);
        }
        if(yonu[0]=='t' && yonu[1]== 'y')
        {
            printf("\nK kesimi denklemi %s = %s + %s \n",&giris[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[1].aracsayisi[0]);
            sprintf(denklem[1]," %s = %s + %s ",&giris[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[1].aracsayisi[0]);
        }
        if(yonu[0]=='x' && yonu[1]== 'y')
        {
            printf("\nK kesimi denklemi %s + %s = %s \n",&giris[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[1].aracsayisi[0]);
            sprintf(denklem[1]," %s + %s = %s ",&giris[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[1].aracsayisi[0]);
        }
        if(yonu[0]=='t' && yonu[1]== 'x')
        {
            printf("\nK kesimi denklemi %s + %s = %s \n",&giris[0].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[0].aracsayisi[0]);
            sprintf(denklem[1]," %s + %s = %s ",&giris[0].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[0].aracsayisi[0]);
        }
    }
    if(giris[1].yol=='x')
    {
        if(yonu[0]=='x' && yonu[1]== 'x')
        {
            printf("\nK kesimi denklemi %s + %s + %s \n",&giris[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[1].aracsayisi[0]);
            sprintf(denklem[1]," %s + %s + %s ",&giris[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[1].aracsayisi[0]);
        }
        if(yonu[0]=='t' && yonu[1]== 'y')
        {
            printf("\nK kesimi denklemi %s = %s + %s \n",&giris[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[1].aracsayisi[0]);
            sprintf(denklem[1]," %s = %s + %s ",&giris[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[1].aracsayisi[0]);
        }
        if(yonu[0]=='x' && yonu[1]== 'y')
        {
            printf("\nK kesimi denklemi %s + %s = %s \n",&giris[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[1].aracsayisi[0]);
            sprintf(denklem[1]," %s + %s = %s ",&giris[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[1].aracsayisi[0]);
        }
        if(yonu[0]=='t' && yonu[1]== 'x')
        {
            printf("\nK kesimi denklemi %s + %s = %s \n",&giris[1].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[0].aracsayisi[0]);
            sprintf(denklem[1]," %s + %s = %s ",&giris[1].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[0].aracsayisi[0]);
        }
    }
    if(cikis[0].yol=='x')
    {
        if(yonu[0]=='x' && yonu[1]== 'x')
        {
            printf("\nK kesimi denklemi %s = %s + %s \n",&cikis[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[1].aracsayisi[0]);
            sprintf(denklem[1]," %s = %s + %s ",&cikis[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[1].aracsayisi[0]);
        }
        if(yonu[0]=='t' && yonu[1]== 'y')
        {
            printf("\nK kesimi denklemi %s + %s + %s \n",&cikis[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[1].aracsayisi[0]);
            sprintf(denklem[1]," %s + %s + %s ",&cikis[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[1].aracsayisi[0]);
        }
        if(yonu[0]=='x' && yonu[1]== 'y')
        {
            printf("\nK kesimi denklemi %s + %s = %s \n",&cikis[0].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[0].aracsayisi[0]);
            sprintf(denklem[1]," %s + %s = %s ",&cikis[0].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[0].aracsayisi[0]);
        }
        if(yonu[0]=='t' && yonu[1]== 'x')
        {
            printf("\nK kesimi denklemi %s + %s = %s \n",&cikis[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[1].aracsayisi[0]);
            sprintf(denklem[1]," %s + %s = %s ",&cikis[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[1].aracsayisi[0]);
        }
    }
    if(cikis[1].yol=='x')
    {
        if(yonu[0]=='x' && yonu[1]== 'x')
        {
            printf("\nK kesimi denklemi %s = %s + %s \n",&cikis[1].aracsayisi[0],&arayol[0],&arayol[1].aracsayisi[0]);
            sprintf(denklem[1]," %s = %s + %s ",&cikis[1].aracsayisi[0],&arayol[0],&arayol[1].aracsayisi[0]);
        }
        if(yonu[0]=='t' && yonu[1]== 'y')
        {
            printf("\nK kesimi denklemi %s + %s + %s \n",&cikis[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[1].aracsayisi[0]);
            sprintf(denklem[1]," %s + %s + %s ",&cikis[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[1].aracsayisi[0]);
        }
        if(yonu[0]=='x' && yonu[1]== 'y')
        {
            printf("\nK kesimi denklemi %s + %s = %s \n",&cikis[1].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[0].aracsayisi[0]);
            sprintf(denklem[1]," %s + %s = %s ",&cikis[1].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[0].aracsayisi[0]);
        }
        if(yonu[0]=='t' && yonu[1]== 'x')
        {
            printf("\nK kesimi denklemi %s + %s = %s \n",&cikis[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[1].aracsayisi[0]);
            sprintf(denklem[1]," %s + %s = %s ",&cikis[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[1].aracsayisi[0]);
        }
    }
    //yonu[0]=a için  yonu[1]=b  için yonu[2]=c için  yonu[3]=d için yonu[4]=e için
    //arayol.yol[0]=a arayol.yol[1]=b arayol.yol[2]=c arayol.yol[3]=d  arayol.yol[4]=e

    // L Kesimi için

    if(giris[0].yol=='y')
    {
        if(yonu[1]=='y' && yonu[3]== 'y' && yonu[4]=='y')
        {
            printf("\nL kesimi denklemi %s + %s + %s + %s \n",&giris[0].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[4].aracsayisi[0]);
            sprintf(denklem[2]," %s + %s + %s + %s ",&giris[0].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[4].aracsayisi[0]);
        }
        if(yonu[1]=='y' && yonu[3]== 'y' && yonu[4]=='t')
        {
            printf("\nL kesimi denklemi %s + %s + %s = %s \n",&giris[0].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[4].aracsayisi[0]);
            sprintf(denklem[2]," %s + %s + %s = %s ",&giris[0].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[4].aracsayisi[0]);
        }
        if(yonu[1]=='x' && yonu[3]== 'z' && yonu[4]=='y')
        {
            printf("\nL kesimi denklemi %s + %s=%s + %s \n",&arayol[4].aracsayisi[0],&giris[0].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0]);
            sprintf(denklem[2]," %s + %s = %s + %s ",&arayol[4].aracsayisi[0],&giris[0].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0]);
        }
        if(yonu[1]=='x' && yonu[3]== 'z' && yonu[4]=='t')
        {
            printf("\nL kesimi denklemi %s = %s + %s + %s \n",&giris[0].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0]);
            sprintf(denklem[2]," %s = %s + %s + %s ",&giris[0].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0]);
        }
        if(yonu[1]=='x' && yonu[3]== 'y' && yonu[4]=='y')
        {
            printf("\nL kesimi denklemi %s + %s + %s = %s \n",&giris[0].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[1].aracsayisi[0]);
            sprintf(denklem[2]," %s + %s + %s = %s ",&giris[0].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[1].aracsayisi[0]);
        }
        if(yonu[1]=='x' && yonu[3]== 'y' && yonu[4]=='t')
        {
            printf("\nL kesimi denklemi %s + %s = %s + %s \n",&giris[0].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[1].aracsayisi[0]);
            sprintf(denklem[2]," %s + %s = %s + %s ",&giris[0].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[1].aracsayisi[0]);
        }
        if(yonu[1]=='y' && yonu[3]== 'z' && yonu[4]=='y')
        {
            printf("\nL kesimi denklemi %s + %s + %s = %s \n",&giris[0].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0]);
            sprintf(denklem[2]," %s + %s + %s = %s ",&giris[0].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0]);
        }
        if(yonu[1]=='y' && yonu[3]== 'z' && yonu[4]=='t')
        {
            printf("\nL kesimi denklemi %s + %s = %s + %s \n",&giris[0].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[3].aracsayisi[0]);
            sprintf(denklem[2]," %s + %s = %s + %s ",&giris[0].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[3].aracsayisi[0]);
        }

    }
    if(giris[1].yol=='y')
    {
        if(yonu[1]=='y' && yonu[3]== 'y' && yonu[4]=='y')
        {
            printf("\nL kesimi denklemi %s + %s + %s + %s \n",&giris[1].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[4].aracsayisi[0]);
            sprintf(denklem[2]," %s + %s + %s + %s ",&giris[1].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[4].aracsayisi[0]);
        }
        if(yonu[1]=='y' && yonu[3]== 'y' && yonu[4]=='t')
        {
            printf("\nL kesimi denklemi %s + %s + %s = %s \n",&giris[1].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[4].aracsayisi[0]);
            sprintf(denklem[2]," %s + %s + %s = %s ",&giris[1].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[4].aracsayisi[0]);
        }
        if(yonu[1]=='x' && yonu[3]== 'z' && yonu[4]=='y')
        {
            printf("\nL kesimi denklemi %s + %s = %s + %s \n",&arayol[4].aracsayisi[0],&giris[1].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0]);
            sprintf(denklem[2]," %s + %s = %s + %s ",&arayol[4].aracsayisi[0],&giris[1].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0]);
        }
        if(yonu[1]=='x' && yonu[3]== 'z' && yonu[4]=='t')
        {
            printf("\nL kesimi denklemi %s = %s + %s + %s \n",&giris[1].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0]);
            sprintf(denklem[2]," %s = %s + %s + %s ",&giris[1].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0]);
        }
        if(yonu[1]=='x' && yonu[3]== 'y' && yonu[4]=='y')
        {
            printf("\nL kesimi denklemi %s + %s + %s=%s \n",&giris[1].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[1].aracsayisi[0]);
            sprintf(denklem[2]," %s + %s + %s = %s ",&giris[1].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[1].aracsayisi[0]);
        }
        if(yonu[1]=='x' && yonu[3]== 'y' && yonu[4]=='t')
        {
            printf("\nL kesimi denklemi %s + %s = %s + %s \n",&giris[1].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[1].aracsayisi[0]);
            sprintf(denklem[2]," %s + %s = %s + %s ",&giris[1].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[1].aracsayisi[0]);
        }
        if(yonu[1]=='y' && yonu[3]== 'z' && yonu[4]=='y')
        {
            printf("\nL kesimi denklemi %s + %s + %s = %s \n",&giris[0].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0]);
            sprintf(denklem[2]," %s + %s + %s = %s ",&giris[0].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0]);
        }
        if(yonu[1]=='y' && yonu[3]== 'z' && yonu[4]=='t')
        {
            printf("\nL kesimi denklemi %s + %s = %s + %s \n",&giris[0].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[3].aracsayisi[0]);
            sprintf(denklem[2]," %s + %s = %s + %s ",&giris[0].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[3].aracsayisi[0]);
        }

    }
    if(cikis[0].yol=='y')
    {
        if(yonu[1]=='y' && yonu[3]== 'y' && yonu[4]=='y')
        {
            printf("\nL kesimi denklemi %s + %s + %s = %s \n",&arayol[4].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[1].aracsayisi[0],&cikis[0].aracsayisi[0]);
            sprintf(denklem[2]," %s + %s + %s = %s ",&arayol[4].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[1].aracsayisi[0],&cikis[0].aracsayisi[0]);
        }
        if(yonu[1]=='y' && yonu[3]== 'y' && yonu[4]=='t')
        {
            printf("\nL kesimi denklemi %s + %s  = %s + %s \n",&arayol[4].aracsayisi[0],&cikis[0].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[1].aracsayisi[0]);
            sprintf(denklem[2]," %s + %s = %s + %s ",&arayol[4].aracsayisi[0],&cikis[0].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[1].aracsayisi[0]);
        }
        if(yonu[1]=='x' && yonu[3]== 'z' && yonu[4]=='y')
        {
            printf("\nL kesimi denklemi %s+ %s + %s = %s \n",&cikis[0].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[4].aracsayisi[0]);
            sprintf(denklem[2]," %s + %s + %s = %s ",&cikis[0].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[4].aracsayisi[0]);
        }
        if(yonu[1]=='x' && yonu[3]== 'z' && yonu[4]=='t')
        {
            printf("\nL kesimi denklemi %s + %s + %s + %s \n",&cikis[0].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[4].aracsayisi[0]);
            sprintf(denklem[2]," %s + %s + %s + %s ",&cikis[0].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[4].aracsayisi[0]);
        }
        if(yonu[1]=='x' && yonu[3]== 'y' && yonu[4]=='y')
        {
            printf("\nL kesimi denklemi %s + %s = %s + %s \n",&cikis[0].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[4].aracsayisi[0]);
            sprintf(denklem[2]," %s + %s = %s + %s ",&cikis[0].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[4].aracsayisi[0]);
        }
        if(yonu[1]=='x' && yonu[3]== 'y' && yonu[4]=='t')
        {
            printf("\nL kesimi denklemi %s + %s + %s = %s \n",&cikis[0].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[3].aracsayisi[0]);
            sprintf(denklem[2]," %s + %s + %s = %s ",&cikis[0].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[3].aracsayisi[0]);
        }
        if(yonu[1]=='y' && yonu[3]== 'z' && yonu[4]=='y')
        {
            printf("\nL kesimi denklemi %s + %s = %s + %s \n",&cikis[0].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[4].aracsayisi[0]);
            sprintf(denklem[2]," %s + %s = %s + %s ",&cikis[0].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[4].aracsayisi[0]);
        }
        if(yonu[1]=='y' && yonu[3]== 'z' && yonu[4]=='t')
        {
            printf("\nL kesimi denklemi %s + %s + %s = %s \n",&cikis[0].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[1].aracsayisi[0]);
            sprintf(denklem[2]," %s + %s + %s = %s ",&cikis[0].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[1].aracsayisi[0]);
        }
    }
    if(cikis[1].yol=='y')
    {
        if(yonu[1]=='y' && yonu[3]== 'y' && yonu[4]=='y')
        {
            printf("\nL kesimi denklemi %s + %s + %s = %s \n",&arayol[4].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[1].aracsayisi[0],&cikis[1].aracsayisi[0]);
            sprintf(denklem[2]," %s + %s + %s = %s \n",&arayol[4].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[1].aracsayisi[0],&cikis[1].aracsayisi[0]);
        }
        if(yonu[1]=='y' && yonu[3]== 'y' && yonu[4]=='t')
        {
            printf("\nL kesimi denklemi %s + %s = %s + %s \n",&arayol[4].aracsayisi[0],&cikis[1].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[1].aracsayisi[0]);
            sprintf(denklem[2]," %s + %s = %s + %s ",&arayol[4].aracsayisi[0],&cikis[1].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[1].aracsayisi[0]);
        }
        if(yonu[1]=='x' && yonu[3]== 'z' && yonu[4]=='y')
        {
            printf("\nL kesimi denklemi %s + %s + %s = %s \n",&cikis[1].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[4].aracsayisi[0]);
            sprintf(denklem[2]," %s + %s + %s = %s ",&cikis[1].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[4].aracsayisi[0]);
        }
        if(yonu[1]=='x' && yonu[3]== 'z' && yonu[4]=='t')
        {
            printf("\nL kesimi denklemi %s + %s + %s + %s \n",&cikis[1].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[4].aracsayisi[0]);
            sprintf(denklem[2]," %s + %s + %s + %s ",&cikis[1].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[4].aracsayisi[0]);
        }
        if(yonu[1]=='x' && yonu[3]== 'y' && yonu[4]=='y')
        {
            printf("\nL kesimi denklemi %s + %s = %s + %s \n",&cikis[1].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[4].aracsayisi[0]);
            sprintf(denklem[2]," %s + %s = %s + %s ",&cikis[1].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[4].aracsayisi[0]);
        }
        if(yonu[1]=='x' && yonu[3]== 'y' && yonu[4]=='t')
        {
            printf("\nL kesimi denklemi %s + %s + %s = %s \n",&cikis[1].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[3].aracsayisi[0]);
            sprintf(denklem[2]," %s + %s + %s = %s ",&cikis[1].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[3].aracsayisi[0]);
        }
        if(yonu[1]=='y' && yonu[3]== 'z' && yonu[4]=='y')
        {
            printf("\nL kesimi denklemi %s + %s = %s + %s \n",&cikis[1].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[4].aracsayisi[0]);
            sprintf(denklem[2]," %s + %s = %s + %s ",&cikis[1].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[1].aracsayisi[0],&arayol[4].aracsayisi[0]);
        }
        if(yonu[1]=='y' && yonu[3]== 'z' && yonu[4]=='t')
        {
            printf("\nL kesimi denklemi %s + %s + %s = %s \n",&cikis[1].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[1].aracsayisi[0]);
            sprintf(denklem[2]," %s + %s + %s = %s ",&cikis[1].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[1].aracsayisi[0]);
        }
    }
    //yonu[0]=a için  yonu[1]=b  için yonu[2]=c için  yonu[3]=d için yonu[4]=e için
    //arayol.yol[0]=a arayol.yol[1]=b arayol.yol[2]=c arayol.yol[3]=d  arayol.yol[4]=e

    // M Kesimi için
    if(giris[0].yol=='z')
    {
        if(yonu[2]=='z' && yonu[3]== 'z')
        {
            printf("\nM kesimi denklemi %s + %s + %s \n",&giris[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[3].aracsayisi[0]);
            sprintf(denklem[3]," %s + %s + %s ",&giris[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[3].aracsayisi[0]);
        }
        if(yonu[2]=='t' && yonu[3]== 'y')
        {
            printf("\nM kesimi denklemi %s = %s + %s \n",&giris[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[3].aracsayisi[0]);
            sprintf(denklem[3]," %s = %s + %s ",&giris[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[3].aracsayisi[0]);
        }
        if(yonu[2]=='z' && yonu[3]== 'y')
        {
            printf("\nM kesimi denklemi %s + %s = %s \n",&giris[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[3].aracsayisi[0]);
            sprintf(denklem[3]," %s + %s = %s ",&giris[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[3].aracsayisi[0]);
        }
        if(yonu[2]=='t' && yonu[3]== 'z')
        {
            printf("\nM kesimi denklemi %s + %s = %s \n",&giris[0].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[2].aracsayisi[0]);
            sprintf(denklem[3]," %s + %s = %s ",&giris[0].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[2].aracsayisi[0]);
        }
    }
    if(giris[1].yol=='z')
    {
        if(yonu[2]=='z' && yonu[3]== 'z')
        {
            printf("\nM kesimi denklemi %s + %s + %s \n",&giris[1].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[3].aracsayisi[0]);
            sprintf(denklem[3]," %s + %s + %s ",&giris[1].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[3].aracsayisi[0]);
        }
        if(yonu[2]=='t' && yonu[3]== 'y')
        {
            printf("\nM kesimi denklemi %s = %s + %s \n",&giris[1].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[3].aracsayisi[0]);
            sprintf(denklem[3]," %s = %s + %s ",&giris[1].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[3].aracsayisi[0]);
        }
        if(yonu[2]=='z' && yonu[3]== 'y')
        {
            printf("\nM kesimi denklemi %s + %s = %s \n",&giris[1].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[3].aracsayisi[0]);
            sprintf(denklem[3]," %s + %s = %s ",&giris[1].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[3].aracsayisi[0]);
        }
        if(yonu[2]=='t' && yonu[3]== 'z')
        {
            printf("\nM kesimi denklemi %s + %s = %s \n",&giris[1].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[2].aracsayisi[0]);
            sprintf(denklem[3]," %s + %s = %s ",&giris[1].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[2].aracsayisi[0]);
        }
    }
    if(cikis[0].yol=='z')
    {
        if(yonu[2]=='z' && yonu[3]== 'z')
        {
            printf("\nM kesimi denklemi %s + %s = %s \n",&arayol[2].aracsayisi[0],&arayol[3].aracsayisi[0],&cikis[0].aracsayisi[0]);
            sprintf(denklem[3]," %s + %s = %s ",&arayol[2].aracsayisi[0],&arayol[3].aracsayisi[0],&cikis[0].aracsayisi[0]);
        }
        if(yonu[2]=='t' && yonu[3]== 'y')
        {
            printf("\nM kesimi denklemi %s + %s + %s \n",&cikis[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[3].aracsayisi[0]);
            sprintf(denklem[3]," %s + %s + %s ",&cikis[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[3].aracsayisi[0]);
        }
        if(yonu[2]=='z' && yonu[3]== 'y')
        {
            printf("\nM kesimi denklemi %s + %s = %s \n",&cikis[0].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[2].aracsayisi[0]);
            sprintf(denklem[3]," %s + %s = %s ",&cikis[0].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[2].aracsayisi[0]);
        }
        if(yonu[2]=='t' && yonu[3]== 'z')
        {
            printf("\nM kesimi denklemi %s + %s = %s \n",&cikis[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[3].aracsayisi[0]);
            sprintf(denklem[3]," %s + %s = %s ",&cikis[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[3].aracsayisi[0]);
        }
    }
    if(cikis[1].yol=='z')
    {
        if(yonu[2]=='z' && yonu[3]== 'z')
        {
            printf("\nM kesimi denklemi %s + %s = %s \n",&arayol[2].aracsayisi[0],&arayol[3].aracsayisi[0],&cikis[1].aracsayisi[0]);
            sprintf(denklem[3]," %s + %s = %s ",&arayol[2].aracsayisi[0],&arayol[3].aracsayisi[0],&cikis[1].aracsayisi[0]);
        }
        if(yonu[2]=='t' && yonu[3]== 'y')
        {
            printf("\nM kesimi denklemi %s + %s + %s \n",&cikis[1].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[3].aracsayisi[0]);
            sprintf(denklem[3]," %s + %s + %s ",&cikis[1].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[3].aracsayisi[0]);
        }
        if(yonu[2]=='z' && yonu[3]== 'y')
        {
            printf("\nM kesimi denklemi %s + %s = %s \n",&cikis[1].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[2].aracsayisi[0]);
            sprintf(denklem[3]," %s + %s = %s ",&cikis[1].aracsayisi[0],&arayol[3].aracsayisi[0],&arayol[2].aracsayisi[0]);
        }
        if(yonu[2]=='t' && yonu[3]== 'z')
        {
            printf("\nM kesimi denklemi %s + %s = %s \n",&cikis[1].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[3].aracsayisi[0]);
            sprintf(denklem[3]," %s + %s = %s ",&cikis[1].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[3].aracsayisi[0]);
        }
    }

    //yonu[0]=a için  yonu[1]=b  için yonu[2]=c için  yonu[3]=d için yonu[4]=e için
    //arayol.yol[0]=a arayol.yol[1]=b arayol.yol[2]=c arayol.yol[3]=d  arayol.yol[4]=e

    // N Kesisimi  için
    if(giris[0].yol=='t')
    {
        if(yonu[0]=='t' && yonu[2]== 't' && yonu[4]== 'y')
        {
            printf("\nN kesimi denklemi %s + %s + %s = %s \n",&giris[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[4].aracsayisi[0]);
            sprintf(denklem[4]," %s + %s + %s = %s ",&giris[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[4].aracsayisi[0]);
        }
        if(yonu[0]=='t' && yonu[2]== 't' && yonu[4]== 't')
        {
            printf("\nN kesimi denklemi %s + %s + %s + %s \n",&giris[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[4].aracsayisi[0]);
            sprintf(denklem[4]," %s + %s + %s + %s ",&giris[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[4].aracsayisi[0]);
        }
        if(yonu[0]=='x' && yonu[2]== 'z' && yonu[4]== 'y')
        {
            printf("\nN kesimi denklemi %s = %s + %s + %s \n",&giris[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[4].aracsayisi[0]);
            sprintf(denklem[4]," %s = %s + %s + %s ",&giris[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[4].aracsayisi[0]);
        }
        if(yonu[0]=='x' && yonu[2]== 'z' && yonu[4]== 't')
        {
            printf("\nN kesimi denklemi %s + %s = %s + %s \n",&giris[0].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0]);
            sprintf(denklem[4]," %s + %s = %s + %s ",&giris[0].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0]);
        }
        if(yonu[0]=='x' && yonu[2]== 't' && yonu[4]== 'y')
        {
            printf("\nN kesimi denklemi %s + %s = %s + %s \n",&giris[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[4].aracsayisi[0]);
            sprintf(denklem[4]," %s + %s = %s + %s ",&giris[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[4].aracsayisi[0]);
        }
        if(yonu[0]=='x' && yonu[2]== 't' && yonu[4]== 't')
        {
            printf("\nN kesimi denklemi %s + %s + %s = %s \n",&giris[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[0].aracsayisi[0]);
            sprintf(denklem[4]," %s + %s + %s = %s ",&giris[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[0].aracsayisi[0]);
        }
        if(yonu[0]=='t' && yonu[2]== 'z' && yonu[4]== 'y')
        {
            printf("\nN kesimi denklemi %s + %s = %s + %s \n",&giris[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[4].aracsayisi[0]);
            sprintf(denklem[4]," %s + %s = %s + %s ",&giris[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[4].aracsayisi[0]);
        }
        if(yonu[0]=='t' && yonu[2]== 'z' && yonu[4]== 't')
        {
            printf("\nN kesimi denklemi %s + %s + %s = %s \n",&giris[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[2].aracsayisi[0]);
            sprintf(denklem[4]," %s + %s + %s = %s ",&giris[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[2].aracsayisi[0]);
        }
    }
    if(giris[1].yol=='t')
    {
        if(yonu[0]=='t' && yonu[2]== 't' && yonu[4]== 'y')
        {
            printf("\nN kesimi denklemi %s + %s + %s = %s \n",&giris[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[4].aracsayisi[0]);
            sprintf(denklem[4]," %s + %s + %s = %s ",&giris[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[4].aracsayisi[0]);
        }
        if(yonu[0]=='t' && yonu[2]== 't' && yonu[4]== 't')
        {
            printf("\nN kesimi denklemi %s + %s + %s + %s \n",&giris[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[4].aracsayisi[0]);
            sprintf(denklem[4]," %s + %s + %s + %s ",&giris[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[4].aracsayisi[0]);
        }
        if(yonu[0]=='x' && yonu[2]== 'z' && yonu[4]== 'y')
        {
            printf("\nN kesimi denklemi %s = %s + %s + %s \n",&giris[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[4].aracsayisi[0]);
            sprintf(denklem[4]," %s = %s + %s + %s ",&giris[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[4].aracsayisi[0]);
        }
        if(yonu[0]=='x' && yonu[2]== 'z' && yonu[4]== 't')
        {
            printf("\nN kesimi denklemi %s + %s = %s + %s \n",&giris[1].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0]);
            sprintf(denklem[4]," %s + %s = %s + %s ",&giris[1].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0]);
        }
        if(yonu[0]=='x' && yonu[2]== 't' && yonu[4]== 'y')
        {
            printf("\nN kesimi denklemi %s + %s = %s + %s \n",&giris[1].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[4].aracsayisi[0]);
            sprintf(denklem[4]," %s + %s = %s + %s ",&giris[1].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[4].aracsayisi[0]);
        }
        if(yonu[0]=='x' && yonu[2]== 't' && yonu[4]== 't')
        {
            printf("\nN kesimi denklemi %s + %s + %s = %s \n",&giris[1].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[0].aracsayisi[0]);
            sprintf(denklem[4]," %s + %s + %s = %s ",&giris[1].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[0].aracsayisi[0]);
        }
        if(yonu[0]=='t' && yonu[2]== 'z' && yonu[4]== 'y')
        {
            printf("\nN kesimi denklemi %s + %s = %s + %s \n",&giris[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[4].aracsayisi[0]);
            sprintf(denklem[4]," %s + %s = %s + %s ",&giris[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[4].aracsayisi[0]);
        }
        if(yonu[0]=='t' && yonu[2]== 'z' && yonu[4]== 't')
        {
            printf("\nN kesimi denklemi %s + %s + %s = %s \n",&giris[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[2].aracsayisi[0]);
            sprintf(denklem[4]," %s + %s + %s = %s ",&giris[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[2].aracsayisi[0]);
        }
    }
    if(cikis[0].yol=='t')
    {
        if(yonu[0]=='t' && yonu[2]== 't' && yonu[4]== 'y')
        {
            printf("\nN kesimi denklemi %s + %s = %s + %s \n",&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0],&cikis[0].aracsayisi[0],&arayol[4].aracsayisi[0]);
            sprintf(denklem[4]," %s + %s = %s + %s ",&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0],&cikis[0].aracsayisi[0],&arayol[4].aracsayisi[0]);
        }
        if(yonu[0]=='t' && yonu[2]== 't' && yonu[4]== 't')
        {
            printf("\nN kesimi denklemi %s + %s + %s = %s \n",&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[4].aracsayisi[0],&cikis[0].aracsayisi[0]);
            sprintf(denklem[4]," %s + %s + %s = %s ",&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[4].aracsayisi[0],&cikis[0].aracsayisi[0]);
        }
        if(yonu[0]=='x' && yonu[2]== 'z' && yonu[4]== 'y')
        {
            printf("\nN kesimi denklemi %s + %s + %s + %s \n",&cikis[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[4].aracsayisi[0]);
            sprintf(denklem[4]," %s + %s + %s + %s ",&cikis[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[4].aracsayisi[0]);
        }
        if(yonu[0]=='x' && yonu[2]== 'z' && yonu[4]== 't')
        {
            printf("\nN kesimi denklemi %s + %s + %s + %s \n",&cikis[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[4].aracsayisi[0]);
            sprintf(denklem[4]," %s + %s + %s + %s ",&cikis[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[4].aracsayisi[0]);
        }
        if(yonu[0]=='x' && yonu[2]== 't' && yonu[4]== 'y')
        {
            printf("\nN kesimi denklemi %s + %s + %s = %s \n",&cikis[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[2].aracsayisi[0]);
            sprintf(denklem[4]," %s + %s + %s = %s ",&cikis[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[2].aracsayisi[0]);
        }
        if(yonu[0]=='x' && yonu[2]== 't' && yonu[4]== 't')
        {
            printf("\nN kesimi denklemi %s + %s = %s + %s \n",&cikis[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[2].aracsayisi[0]);
            sprintf(denklem[4]," %s + %s = %s + %s ",&cikis[0].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[2].aracsayisi[0]);
        }
        if(yonu[0]=='t' && yonu[2]== 'z' && yonu[4]== 'y')
        {
            printf("\nN kesimi denklemi %s + %s + %s = %s \n",&cikis[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[0].aracsayisi[0]);
            sprintf(denklem[4]," %s + %s + %s = %s ",&cikis[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[0].aracsayisi[0]);
        }
        if(yonu[0]=='t' && yonu[2]== 'z' && yonu[4]== 't')
        {
            printf("\nN kesimi denklemi %s + %s = %s + %s \n",&cikis[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[0].aracsayisi[0]);
            sprintf(denklem[4]," %s + %s = %s + %s ",&cikis[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[0].aracsayisi[0]);
        }
    }
    if(cikis[1].yol=='t')
    {
        if(yonu[0]=='t' && yonu[2]== 't' && yonu[4]== 'y')
        {
            printf("\nN kesimi denklemi %s + %s = %s + %s \n",&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0],&cikis[1].aracsayisi[0],&arayol[4].aracsayisi[0]);
            sprintf(denklem[4]," %s + %s = %s + %s ",&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0],&cikis[1].aracsayisi[0],&arayol[4].aracsayisi[0]);
        }
        if(yonu[0]=='t' && yonu[2]== 't' && yonu[4]== 't')
        {
            printf("\nN kesimi denklemi %s + %s + %s = %s \n",&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[4].aracsayisi[0],&cikis[1].aracsayisi[0]);
            sprintf(denklem[4]," %s + %s + %s = %s ",&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[4].aracsayisi[0],&cikis[1].aracsayisi[0]);
        }
        if(yonu[0]=='x' && yonu[2]== 'z' && yonu[4]== 'y')
        {
            printf("\nN kesimi denklemi %s + %s + %s + %s \n",&cikis[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[4].aracsayisi[0]);
            sprintf(denklem[4]," %s + %s + %s + %s ",&cikis[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[4].aracsayisi[0]);
        }
        if(yonu[0]=='x' && yonu[2]== 'z' && yonu[4]== 't')
        {
            printf("\nN kesimi denklemi %s + %s + %s + %s \n",&cikis[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[4].aracsayisi[0]);
            sprintf(denklem[4]," %s + %s + %s + %s ",&cikis[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[4].aracsayisi[0]);
        }
        if(yonu[0]=='x' && yonu[2]== 't' && yonu[4]== 'y')
        {
            printf("\nN kesimi denklemi %s + %s + %s = %s \n",&cikis[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[2].aracsayisi[0]);
            sprintf(denklem[4]," %s + %s + %s = %s ",&cikis[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[2].aracsayisi[0]);
        }
        if(yonu[0]=='x' && yonu[2]== 't' && yonu[4]== 't')
        {
            printf("\nN kesimi denklemi %s + %s = %s + %s \n",&cikis[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[2].aracsayisi[0]);
            sprintf(denklem[4]," %s + %s = %s + %s ",&cikis[1].aracsayisi[0],&arayol[0].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[2].aracsayisi[0]);
        }
        if(yonu[0]=='t' && yonu[2]== 'z' && yonu[4]== 'y')
        {
            printf("\nN kesimi denklemi %s + %s + %s = %s \n",&cikis[1].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[0].aracsayisi[0]);
            sprintf(denklem[4]," %s + %s + %s = %s ",&cikis[1].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[0].aracsayisi[0]);
        }
        if(yonu[0]=='t' && yonu[2]== 'z' && yonu[4]== 't')
        {
            printf("\nN kesimi denklemi %s + %s = %s + %s \n",&cikis[1].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[0].aracsayisi[0]);
            sprintf(denklem[4]," %s + %s = %s + %s ",&cikis[1].aracsayisi[0],&arayol[2].aracsayisi[0],&arayol[4].aracsayisi[0],&arayol[0].aracsayisi[0]);
        }
    }

    MatriseYerlestir(denklem,sayac);
}
void MatriseYerlestir(char denklem[5][50],int sayac)
{
    int  i,j, k, l, m, d, p,deger;
    int kontrol=0;
    int bilinmeyen=sayac-1;
    char s[2];

    int matris[5][6] = {0};

    for (d=0; d<5; d++)
    {
        //denklemlerin katsayilarini matrise yazdırma
        for (i=0 ; i<bilinmeyen; i++)
        {
            for (j = 0 ; j<esittirbul(denklem[d]) ; j++)
            {
                s[0] = denklem[d][j+1];
                deger = atoi(s);
                if  ((denklem[d][j] == 'k') && (deger == i+1))
                {
                    matris[d][i] = 1;
                }
            }
            for (j = esittirbul(denklem[d]) +1 ; j<strlen(denklem[d]) ; j++)
            {
                s[0] = denklem[d][j+1];
                deger = atoi(s);
                if  ((denklem[d][j] == 'k') && (deger == i+1))
                {
                    matris[d][i] = -1;
                }
            }
        }

// Denklemin sabit sayisini matrise yazdirma
        int x=0;
        int toplam = 0;
        char sayi[5] = "";
        for (i = 0 ; i<esittirbul(denklem[d]) ; i++)
        {
            if (denklem[d][i] == ' ' && isdigit(denklem[d][i+1]))
            {
                for(j=i; isdigit(denklem[d][j+1]); j++)
                {
                    sayi[x] = denklem[d][j + 1];
                    x++;
                }
                x=0;
                toplam -= atoi(sayi);
                sayi[1]=' ';
                sayi[2]=' ';
                sayi[3]=' ';
            }
        }
        for (i = esittirbul(denklem[d]) +1 ; i<strlen(denklem[d]) ; i++)
        {
            if (denklem[d][i] == ' ' && isdigit(denklem[d][i+1]))
            {
                for(j=i; isdigit(denklem[d][j+1]); j++)
                {
                    sayi[x] = denklem[d][j + 1];
                    x++;
                }
                x=0;
                toplam += atoi(sayi);
                sayi[1]=' ';
                sayi[2]=' ';
                sayi[3]=' ';
            }
        }
        matris[d][bilinmeyen] = toplam;
    }


    //// Matris son hali
    printf("\n\nDenklemlere gore olusturulan matris..\n\n");

    for(i=0; i<bilinmeyen; i++)
    {
        printf("  k%d",i+1);
    }
    printf("\n\n");
    for (i = 0; i<5 ; i++)
    {
        for (j= 0; j<(bilinmeyen+1) ; j++)
        {
            printf("%3d ",matris[i][j]);
        }
        printf("\n");
    }


    ////BİLİNMEYEN BULMA
    for (i = 0; i<5 ; i++)
    {
        kontrol=0;
        for (j= 0; j<bilinmeyen ; j++)
        {
            if(matris[i][j]!=0)
            {
                kontrol++;
                p=j;


            }
        }
        if(kontrol==1)
        {
            printf("\nk%d=%d\n",(p+1),matris[i][bilinmeyen]/matris[i][p]);

        }
    }

}
int esittirbul(char *denklem)
{
    int i;
    for (i=0 ; i<strlen(denklem); i++)
    {
        if  (denklem[i] == '=')
        {
            break;
        }
    }
    return i;
}
void HaritaCiz(char yonu[4])
{
    if(yonu[0]=='x')
    {
        resimc=load_bitmap("tdenxe.bmp",0);
        draw_sprite(screen,resimc,0,0);
    }
    else
    {
        resimc=load_bitmap("xtentye.bmp",0);
        draw_sprite(screen,resimc,0,0);
    }
    if(yonu[1]=='y')
    {
        resimc=load_bitmap("xtenyye.bmp",0);
        draw_sprite(screen,resimc,400,0);
    }
    else
    {
        resimc=load_bitmap("ydenxe.bmp",0);
        draw_sprite(screen,resimc,400,0);
    }
    if(yonu[2]=='t')
    {
        resimc=load_bitmap("zdentye.bmp",0);
        draw_sprite(screen,resimc,0,260);
    }
    else
    {
        resimc=load_bitmap("tdenzye.bmp",0);
        draw_sprite(screen,resimc,0,260);
    }
    if(yonu[3]=='z')
    {
        resimc=load_bitmap("ydenzye.bmp",0);
        draw_sprite(screen,resimc,400,260);
    }
    else
    {
        resimc=load_bitmap("zdenyye.bmp",0);
        draw_sprite(screen,resimc,400,260);
    }

    if(giris[0].yol=='x' || giris[1].yol=='x')
    {
        resimc=load_bitmap("xgiris.bmp",0);
        draw_sprite(screen,resimc,344,12);
    }
    if(giris[0].yol=='y' || giris[1].yol=='y')
    {
        resimc=load_bitmap("ygiris.bmp",0);
        draw_sprite(screen,resimc,562,223);
    }
    if(giris[0].yol=='z' || giris[1].yol=='z')
    {
        resimc=load_bitmap("zgiris.bmp",0);
        draw_sprite(screen,resimc,344,404);
    }
    if(giris[0].yol=='t' || giris[1].yol=='t')
    {
        resimc=load_bitmap("tgiris.bmp",0);
        draw_sprite(screen,resimc,93,222);
    }

    if(cikis[0].yol=='x' || cikis[1].yol=='x')
    {
        resimc=load_bitmap("xcikis.bmp",0);
        draw_sprite(screen,resimc,344,12);
    }
    if(cikis[0].yol=='y' || cikis[1].yol=='y')
    {
        resimc=load_bitmap("ycikis.bmp",0);
        draw_sprite(screen,resimc,562,223);
    }
    if(cikis[0].yol=='z' || cikis[1].yol=='z')
    {
        resimc=load_bitmap("zcikis.bmp",0);
        draw_sprite(screen,resimc,344,404);
    }
    if(cikis[0].yol=='t' || cikis[1].yol=='t')
    {
        resimc=load_bitmap("tcikis.bmp",0);
        draw_sprite(screen,resimc,93,222);
    }

}

