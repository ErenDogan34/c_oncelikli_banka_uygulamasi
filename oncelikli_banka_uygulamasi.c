#include<conio.h>
#include<stdio.h>
#include<stdlib.h>    
#include<string.h>


struct banka 
{
    char ad[30],soyad[30];
    int oncelik;
    struct banka *next;
    
};

struct banka *front;
struct banka *rear;
struct banka*temp;

void goruntuleme()
{
    int i;
    if(front==NULL) 
    {
        printf("\nKuyrukta kimse yok!!\n\n");
        return;
    }
    
    struct banka *new=front;
    printf("\nSirada Bekleyen Musteriler:\n");
    
   printf("-----------------------------------------------");
   
    while(new!=NULL)
    {
        printf("\n\nOncelik Numarasi: %d",new->oncelik);
        printf("\n\nAdi: %s",new->ad);
        printf("\n\nSoyadi: %s",new->soyad);
     printf("\n\n-----------------------------------------------");
       	new=new->next;
    }
   
    printf("\n\n");  
   
}

    
void bank(int priority,char *isim,char *soyad)
{   
    struct banka* newNode=(struct banka*)malloc(sizeof(struct banka));
    newNode->oncelik=priority;
    
    strcpy(newNode->ad,isim);
    strcpy(newNode->soyad,soyad);


    newNode->next=NULL;
    
    struct banka *prevTemp;
    
    if(front==NULL)
        front=rear=temp=newNode;
        
        else if(newNode->oncelik>=rear->oncelik)
        {
            rear->next=newNode;
            rear=newNode;
            return;
        }
            else if(newNode->oncelik>temp->oncelik)
        {
            while(1) 
            {
                temp=temp->next;
                if(prevTemp->oncelik<newNode->oncelik && temp->oncelik>newNode->oncelik)
			    {
                    prevTemp->next=newNode;
                    newNode->next=temp;
                    temp=prevTemp=front;
                    break;
                }
                
                else if(prevTemp->oncelik<newNode->oncelik && temp->oncelik==newNode->oncelik)
				{
                    while(temp->oncelik==newNode->oncelik)
                    {
                        prevTemp=temp;
                        temp=temp->next;
                    }
                    prevTemp->next=newNode;
                    newNode->next=temp;
                    break;
                }
                else
                prevTemp=temp;
            }
            temp=prevTemp=front;
        }        
        else if(newNode->oncelik<temp->oncelik)
        {
            newNode->next=front;

            front=temp=newNode;

            return;
        }
        else if(newNode->oncelik==temp->oncelik)

        {
            while(newNode->oncelik==temp->oncelik)

            {
                prevTemp=temp;
                temp=temp->next;
            }
            prevTemp->next=newNode;
            newNode->next=temp;                                               
            temp=prevTemp=front;

            return;
        }
}

     
void musteri()
{
    if(front==NULL)
    {
    printf("Kuyruk Bos!\n");
    return;
    }
    
    else
    {
        struct banka *temp=front;
        front=front->next;
        printf("\tSiradaki Musteri \n");
       printf("-----------------------------------------------\n\n");
        printf("Oncelik Degeri: %d",temp->oncelik);
        printf("\nAdi: %s",temp->ad);
        printf("\nSoyadi:%s\n\n",temp->soyad);
       printf("-----------------------------------------------\n\n");
        free(temp);
    }
}
     

    
int main()
{
    int secim, oncelik;
    char isim[20],soyad[20];
    front=rear=NULL;
 
    do
    {

    	printf("\tBANKA OTOMASYONU\n");
        printf("-----------------------------------------------");
        printf("\n 1. Yeni Musteri Ekle");
        printf("\n 2. Kuyruktan Musteri Sil ");
        printf("\n 3. Kalan Musterileri Goruntule");
        printf("\n 4. Cikis Yap");
     
        printf("\n Lutfen Seciminizi Yapiniz :");

		scanf("%d",&secim);
        
        printf("\n\n");
     
        switch(secim)
        {
            case 1:
                printf("1-Engelli Vatandas Girisi\n");
                printf("2-60 Yas Ustu Vatandas Girisi\n");
                printf("3-Normal Giris\n");
                
                printf("\nLutfen islem yapmak icin uygun durumunuzu seciniz : ");
            	    scanf("%d",&oncelik);
            	 
                printf("Lutfen Kullanici Adinizi Giriniz: ");
                	scanf("%s",isim);
                
                printf("\nLutfen Kullanici Soyadinizi Giriniz: ");
                	scanf("%s",soyad);

                bank(oncelik,isim,soyad);
                goruntuleme();
                	
                break;
                
			case 2:
                musteri();
                break;
            case 3:
                goruntuleme();
                break;
            case 4:
                printf("Bizi Tercih Ettiginiz Icin Tesekkurler Isleminiz Sonlandirilmistir ...");
                getch();
             
        }
    }while(secim!=4);
}
