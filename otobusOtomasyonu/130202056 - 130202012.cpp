/* Mertcan Yýlmaz 130202056 Volkan Uður ARSLAN 130202012 - Otobüs Sefer ve Bilet Ýþlemleri Programý - */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
main()
{
	struct OTOBUS{
	char no[5];
	char guzergah[20];
	char tarih[11];
	char saat[6];
	int kapasite;
	char plaka[10];
	char kaptan[20];
	int fiyat;
	char kapasite_adres[20];
	struct OTOBUS *next,*last;
    };
    
    struct YOLCU{
    	char ad[10];
    	char soyad[10];
    	char kimlik_no[13];
    	char yolcu_sefer_no[5];
    	int yolcu_koltuk_no;
    	struct YOLCU *next,*last;
    }*yolcu;
    
    char gecici_tarih[11];
    char gecici_guzergah[20];
	int secim=0,secim_sefer=0;
	char sefer_tarihi[11];
	char sefer_guzergahi[20];
	char sefer_no[5];
	char sefer_adres[20];
	int secilen_koltuk=0;
	int otobus_kapasite=0;
	char otobus_adres[20];
	FILE *sefer;
	FILE *kapasite;
	FILE *kayit;
	FILE *logumuz;
	
	if ((logumuz = fopen ("log.txt", "a+"))==NULL )
	    printf("Dosya acilamadi!");
	fprintf (logumuz, "Program baslatilmisitir.\n");
	printf("OTOBUS UYGULAMASINA HOSGELDINIZ!\n");

	while(1)
	{
		printf("\n\nMENU:\n1.Sefer islemleri.\n2.Bilet islemleri.\n3.Cikis.\n");
		printf("Lutfen secim yapiniz:\t");
		scanf("%d",&secim);
		
		if(secim==1)
	{
	
			fprintf (logumuz, "Sefer islemlerine girilmistir.");
			SEFER_ISLEM:
				{
					printf("\n1.Sefer ekleme.\n2.Sefer silme.\n3.Kaptan degistirme.\n4.Sefer gelir hesaplama.\n5.Sefer listeleme.\n6.Gecmis seferleri listeleme.\n7.Tüm sefer sayisi.\n8.Geri gelme.\n");
					printf("Lutfen secim yapiniz:\t");
					scanf("%d",&secim_sefer);
					
					if(secim_sefer==1)
					{
							  fprintf (logumuz, "Sefer eklemeye girilmistir.");
						      FILE *seferler;
                              char gecici_adres[20]="sefer_";
                              char gecici_sefer_no[20];
	                          char cevir[10];
                              struct OTOBUS *ilk=NULL,*son=NULL,*gecici=NULL,*ekle=NULL;
    
	                          if((seferler=fopen("seferler.txt","r+"))==NULL)
                              {
    	                           printf("Dosyaniz acilamadi!");
                              }
    
                              ekle=(OTOBUS *)malloc(sizeof(OTOBUS));
                              printf("Lutfen eklemek istediginiz seferle ilgili bilgileri doldurunuz.\n");
                              printf("Lutfen sefer numarasini giriniz:\t");
                              scanf("%s",ekle->no);
                              fflush(stdin);
                              printf("Lutfen sefer tarihini gg.aa.yyyy seklinde giriniz:\t");
                              scanf("%s",ekle->tarih);
                              fflush(stdin);
	                          printf("Lutfen (Kocaeli-Istanbul seklinde) guzergah giriniz:\t");
                              scanf("%s",ekle->guzergah);
                              fflush(stdin);
	                          printf("Lutfen sefer saatini ss:dd seklinde giriniz:\t");
                              scanf("%s",ekle->saat);
                              fflush(stdin);
	                          printf("Lutfen otobus kapasitesini giriniz:\t");
                              scanf("%d",&ekle->kapasite);
                              fflush(stdin);
                              printf("Lutfen otobus plakasini bosluk birakmadan giriniz:\t");
                              scanf("%s",ekle->plaka);
                              fflush(stdin);
	                          printf("Lutfen otobus kaptaninin adini ve soyadini araya - koyarak giriniz:\n");
                              scanf("%s",ekle->kaptan);
                              fflush(stdin);
	                          printf("Lutfen bilet fiyatini giriniz:\t");
                              scanf("%d",&ekle->fiyat);
    							fprintf (logumuz, " Sefer no : %s \n Sefer tarihi : %s \n Sefer Guzergahi : %s \n Sefer saati : %s \n Kapesitesi : %d \n Plakasi : %s \n Kaptanin adi : %s Bilet fiyati : %d \t olacak sekilde girilmistir.", ekle->no, ekle->tarih, ekle->guzergah, ekle->saat, ekle->kapasite,ekle->plaka,ekle->kaptan,ekle->fiyat );
                              strcpy(gecici_sefer_no,ekle->no);
	                          strcat(gecici_sefer_no,".txt");
                              strcat(gecici_adres,gecici_sefer_no);
                              strcpy(ekle->kapasite_adres,gecici_adres);
    						    fprintf (logumuz, "Bilgileri girilen sefer eklenmistir..");
                              while(!feof(seferler))
                              {
                                   if(ilk==NULL) 	/* http://turgayozgur.com/cde-bagli-liste-ile-kayit-fonksiyonlari.html adresinden alýntýdýr. */
	                               {
                                        ilk = (OTOBUS *) malloc(sizeof(OTOBUS));
                                        fscanf(seferler,"%s   %s   %s   %s   %d   %s   %s   %d   %s\n",ilk->no,ilk->tarih,ilk->guzergah,ilk->saat,&ilk->kapasite,ilk->plaka,ilk->kaptan,&ilk->fiyat,ilk->kapasite_adres);
                                        ilk->last = NULL;
                                        son = ilk;
                                   }
                                   else if(son == ilk)
	                               {
   
                                        son = (OTOBUS *) malloc(sizeof(OTOBUS));
                                        fscanf(seferler,"%s   %s   %s   %s   %d   %s   %s   %d   %s\n",son->no,son->tarih,son->guzergah,son->saat,&son->kapasite,son->plaka,son->kaptan,&son->fiyat,son->kapasite_adres);
                                        ilk->next = son;
                                        son->next = NULL;
                                        son->last = ilk;
                                   }
                                   else
	                               {
                                        gecici = (OTOBUS *) malloc(sizeof(OTOBUS));
                                        fscanf(seferler,"%s   %s   %s   %s   %d   %s   %s   %d   %s\n",gecici->no,gecici->tarih,gecici->guzergah,gecici->saat,&gecici->kapasite,gecici->plaka,gecici->kaptan,&gecici->fiyat,gecici->kapasite_adres);
                                        son->next = gecici;
                                        gecici->last = son;

                                        son = gecici;
                                        son->next = NULL;
          		
                                   }  
                              }
                              gecici=ilk;
    				          while(gecici!=NULL)
    				          {
    				          	  if(strcmp(gecici->no,ekle->no)==0)
    				          	  {
    				          	  	printf("Girdiginiz sefer numarasi ile ayni numarada bir sefer bulunmaktadir.Sefer islemlerine donuluyor..\n");
    				          	  	fprintf(logumuz,"Hatali sefer girisi yapildi!.Sefer islemlerine donuldu.\n");
    				          	  	goto SEFER_ISLEM;
    				          	  }
    				          	  gecici=gecici->next;
    				          }
                              
                              son->next=ekle;
                              ekle->last=son;
                              ekle->next=NULL;

                              fclose(seferler);
                              FILE *seferler2;
                              FILE *sefer_kayit;
                              if((seferler2=fopen("seferler.txt","w+"))==NULL)
                              {
    	                            printf("Dosyaniz acilamadi.");
                              }
                              
                              gecici=ilk;
                              while(gecici!=NULL)
                              {
    	                            fprintf(seferler2,"%s   %s   %s   %s   %d   %s   %s   %d   %s\n",gecici->no,gecici->tarih,gecici->guzergah,gecici->saat,gecici->kapasite,gecici->plaka,gecici->kaptan,gecici->fiyat,gecici->kapasite_adres);
									gecici=gecici->next;       
                              }
                              fclose(seferler2);
    
                              if((sefer_kayit=fopen(ekle->kapasite_adres,"w+"))==NULL)
                                   printf("Dosya acilamadi!");
        
                              for(int i=0;i<ekle->kapasite;++i)
	                          {
		                           fprintf(sefer_kayit,"%d   b\n",i+1);
	                          }    
	                          fclose(sefer_kayit);
                              printf("Ekleme isleminiz basariyla gerceklesmistir.Ana menuye gecis yapiliyor..\n");
                              fprintf (logumuz , "Sefer ekleme islemi basariyla gerceklestirilmistir.\n");
					}
					else if(secim_sefer==2)
					{
								fprintf (logumuz , "Sefer silme islemine girilmisitir.");
						      FILE *seferler;
                              struct OTOBUS *ilk=NULL,*son=NULL,*gecici=NULL,*yazdir=NULL;
    
                              if((seferler=fopen("seferler.txt","r+"))==NULL)
                              {
    	                            printf("Dosya acilamadi.");
                              }
    
                              while(!feof(seferler))
                              {
                                     if(ilk==NULL)  /* http://turgayozgur.com/cde-bagli-liste-ile-kayit-fonksiyonlari.html adresinden alýntýdýr. */
	                                 {
                                              ilk = (OTOBUS *) malloc(sizeof(OTOBUS));
                                              fscanf(seferler,"%s   %s   %s   %s   %d   %s   %s   %d   %s\n",ilk->no,ilk->tarih,ilk->guzergah,ilk->saat,&ilk->kapasite,ilk->plaka,ilk->kaptan,&ilk->fiyat,ilk->kapasite_adres);
                                              ilk->last = NULL;
                                              son = ilk;
                                     }
                                     else if(son == ilk)
	                                 {
                                              son = (OTOBUS *) malloc(sizeof(OTOBUS));
                                              fscanf(seferler,"%s   %s   %s   %s   %d   %s   %s   %d   %s\n",son->no,son->tarih,son->guzergah,son->saat,&son->kapasite,son->plaka,son->kaptan,&son->fiyat,son->kapasite_adres);
                                              ilk->next = son;
                                              son->next = NULL;
                                              son->last = ilk;
                                     }
                                     else
	                                 {
                                              gecici = (OTOBUS *) malloc(sizeof(OTOBUS));
                                              fscanf(seferler,"%s   %s   %s   %s   %d   %s   %s   %d   %s\n",gecici->no,gecici->tarih,gecici->guzergah,gecici->saat,&gecici->kapasite,gecici->plaka,gecici->kaptan,&gecici->fiyat,gecici->kapasite_adres);
                                              son->next = gecici;
                                              gecici->last = son;

                                              son = gecici;
                                              son->next = NULL;
          		
                                     }  
                              }
                              fclose(seferler);
                              char aranan_sefer_no[5];
                              printf("Lutfen silmek istediginiz sefer numarasini giriniz:\t");
                              scanf("%s",aranan_sefer_no);
    						  gecici = ilk;
    						  fprintf (logumuz , "Silinmesi istenen sefer numarasi ( %s ) girilmistir.\n", aranan_sefer_no );
                              while(strcmp(gecici->no,aranan_sefer_no))/* http://turgayozgur.com/cde-bagli-liste-ile-kayit-fonksiyonlari.html adresinden alýntýdýr. */
	                          {
                                              fscanf(seferler,"%s   %s   %s   %s   %d   %s   %s   %d   %s\n",gecici->no,gecici->tarih,gecici->guzergah,gecici->saat,&gecici->kapasite,gecici->plaka,gecici->kaptan,&gecici->fiyat,gecici->kapasite_adres);
                                              gecici=gecici->next;
                              }
                              
    
   							 remove(gecici->kapasite_adres);
    
                              if(gecici->next == NULL)
	                          {
                                             son = son->last;
                                             son->next = NULL;
                                             free(gecici);
                              }

                              else if(gecici->last == NULL)
	                          {
                                             ilk = ilk->next;
                                             ilk->last = NULL;
                                             free(gecici);
                              }

                              else
	                         {
                                             struct OTOBUS *temp1, *temp2;
                                             temp1 = gecici;
                                             temp2 = temp1->last;
                                             temp1 = temp1->next;
                                            
                                             temp2->next = temp1;
                                             temp1->last = temp2;
                                             free(gecici);
                             }
    
                            if((seferler=fopen("seferler.txt","w+"))==NULL)
                            {
    	                                    printf("Dosyaniz acilamadi.");
                            }
    
                            yazdir=ilk;
                            while(yazdir!=NULL)
                            {
    	                               fprintf(seferler,"%s   %s   %s   %s   %d   %s   %s   %d   %s \n",yazdir->no,yazdir->tarih,yazdir->guzergah,yazdir->saat,yazdir->kapasite,yazdir->plaka,yazdir->kaptan,yazdir->fiyat,yazdir->kapasite_adres);
    	                               yazdir=yazdir->next;       
                            }
                            fclose(seferler);
                            printf("Silme isleminiz basariyla tamamlanmistir. Ana menuye donuluyor..");
                        	fprintf (logumuz , "Yazilan sefer basariyla silinmistir. \n");

					}
					else if(secim_sefer==3)
					{
						    FILE *seferler;
                            struct OTOBUS *ilk=NULL,*son=NULL,*gecici=NULL,*yazdir=NULL;
    						fprintf (logumuz , "Kaptan degistirme islemine girilmistir. \n");

                            if((seferler=fopen("seferler.txt","r+"))==NULL)
                            {
    	                          printf("Dosyaniz acilamadi.");
                            }
    
                            while(!feof(seferler))
                            {
                                  if(ilk==NULL)	/* http://turgayozgur.com/cde-bagli-liste-ile-kayit-fonksiyonlari.html adresinden alýntýdýr. */
	                              {
                                         ilk = (OTOBUS *) malloc(sizeof(OTOBUS));
                                         fscanf(seferler,"%s   %s   %s   %s   %d   %s   %s   %d   %s\n",ilk->no,ilk->tarih,ilk->guzergah,ilk->saat,&ilk->kapasite,ilk->plaka,ilk->kaptan,&ilk->fiyat,ilk->kapasite_adres);
                                         ilk->last = NULL;
                                         son = ilk;
                                  }
                                  else if(son == ilk)
	                              {
   
                                         son = (OTOBUS *) malloc(sizeof(OTOBUS));
                                         fscanf(seferler,"%s   %s   %s   %s   %d   %s   %s   %d   %s\n",son->no,son->tarih,son->guzergah,son->saat,&son->kapasite,son->plaka,son->kaptan,&son->fiyat,son->kapasite_adres);
                                         ilk->next = son;
                                         son->next = NULL;
                                         son->last = ilk;
                                  }
                                  else
	                              {
                                         gecici = (OTOBUS *) malloc(sizeof(OTOBUS));
                                         fscanf(seferler,"%s   %s   %s   %s   %d   %s   %s   %d   %s\n",gecici->no,gecici->tarih,gecici->guzergah,gecici->saat,&gecici->kapasite,gecici->plaka,gecici->kaptan,&gecici->fiyat,gecici->kapasite_adres);
                                         son->next = gecici;
                                         gecici->last = son;

                                         son = gecici;
                                         son->next = NULL;
          		
                                  }  
                            }
                            fclose(seferler);
                            char kaptan_degistir_sefer[5];
                            printf("Lutfen kaptani degistirmek istediginiz sefer numarasini giriniz:\t");
                            scanf("%s",kaptan_degistir_sefer);
    						fprintf (logumuz , "%s sefer numarali otobusun kaptani belirtilmistir. \n");
	                        gecici=ilk;
                            while(strcmp(gecici->no,kaptan_degistir_sefer))/* http://turgayozgur.com/cde-bagli-liste-ile-kayit-fonksiyonlari.html adresinden alýntýdýr. */
	                        {
                                     fscanf(seferler,"%s   %s   %s   %s   %d   %s   %s   %d   %s\n",gecici->no,gecici->tarih,gecici->guzergah,gecici->saat,&gecici->kapasite,gecici->plaka,gecici->kaptan,&gecici->fiyat,gecici->kapasite_adres);
                                     gecici=gecici->next;
                            }
    						fprintf (logumuz , "Onceki Kaptanin Adi : %s \n", gecici->kaptan);
                            printf("Lutfen kaptanin adini ve soyadini araya - koyarak giriniz:\n");
                            scanf("%s",gecici->kaptan);
    						fprintf (logumuz , "Yeni Kaptanin Adi : %s \n", gecici->kaptan);
                            if((seferler=fopen("seferler.txt","w+"))==NULL)
                            {
    	                            printf("Dosya acilamadi.");
                            }
    
                            yazdir=ilk;
                            while(yazdir!=NULL)
                            {
    	                            fprintf(seferler,"%s   %s   %s   %s   %d   %s   %s   %d   %s \n",yazdir->no,yazdir->tarih,yazdir->guzergah,yazdir->saat,yazdir->kapasite,yazdir->plaka,yazdir->kaptan,yazdir->fiyat,yazdir->kapasite_adres);
    	                            yazdir=yazdir->next;       
                            }
                            fclose(seferler);
                            printf("Kaptan degistirme isleminiz tamamlanmistir. Ana menuye donuluyor..");
                            fprintf (logumuz , "Kaptan degistirme islemi basariyla tamamlanmistir.\n");
					}
					else if(secim_sefer==4)
					{
						fprintf (logumuz , "Sefer gelir hesaplama secimine girilmistir. \n");
						FILE *seferler;
    					char gelir_hesapla_no[5];
    					int sayac=0;
    					int bilet_fiyati=0;
   				 		int gelir=0;
    
    					struct OTOBUS *ilk=NULL,*son=NULL,*gecici=NULL,*ekle=NULL;
    
						if((seferler=fopen("seferler.txt","r+"))==NULL)
    					{
    						printf("Dosya acilamadi.");
    					}
    
    				printf("Lutfen gelir hesaplamak istediginiz sefer numarasini giriniz:\t");
    				scanf("%s",gelir_hesapla_no);
    				fprintf (logumuz , "Istenilen Sefer numarasi (%s) girilmistir. \n",gelir_hesapla_no);
    				while(!feof(seferler))
    				{
      				if(ilk==NULL)	/* http://turgayozgur.com/cde-bagli-liste-ile-kayit-fonksiyonlari.html adresinden alýntýdýr. */
	  				{
          				ilk = (OTOBUS *) malloc(sizeof(OTOBUS));
          				fscanf(seferler,"%s   %s   %s   %s   %d   %s   %s   %d   %s\n",ilk->no,ilk->tarih,ilk->guzergah,ilk->saat,&ilk->kapasite,ilk->plaka,ilk->kaptan,&ilk->fiyat,ilk->kapasite_adres);
          				ilk->last = NULL;
          				son = ilk;
       				}
       				else if(son == ilk)
	  			 	{
   
       					son = (OTOBUS *) malloc(sizeof(OTOBUS));
       					fscanf(seferler,"%s   %s   %s   %s   %d   %s   %s   %d   %s\n",son->no,son->tarih,son->guzergah,son->saat,&son->kapasite,son->plaka,son->kaptan,&son->fiyat,son->kapasite_adres);
       					ilk->next = son;
      			 		son->next = NULL;
       					son->last = ilk;
       				}
       				else
	   				{
       					gecici = (OTOBUS *) malloc(sizeof(OTOBUS));
       					fscanf(seferler,"%s   %s   %s   %s   %d   %s   %s   %d   %s\n",gecici->no,gecici->tarih,gecici->guzergah,gecici->saat,&gecici->kapasite,gecici->plaka,gecici->kaptan,&gecici->fiyat,gecici->kapasite_adres);
       					son->next = gecici;
       					gecici->last = son;

       					son = gecici;
       					son->next = NULL;
          		
       				}  
    				}
    				fclose(seferler);
    				gecici = ilk;

    				while(strcmp(gecici->no,gelir_hesapla_no))/* http://turgayozgur.com/cde-bagli-liste-ile-kayit-fonksiyonlari.html adresinden alýntýdýr. */
					{
         				gecici = gecici->next;
    				}

    				bilet_fiyati=gecici->fiyat;
    				FILE *otobus_durumu;
    				int koltuk_no[gecici->kapasite];
    				char koltuk_durum[gecici->kapasite];
    
    				if((otobus_durumu=fopen(gecici->kapasite_adres,"r+"))==NULL)
    				{
    					printf("Dosya acilamadi!");
    				}
   			 		for(int x=0;x<gecici->kapasite;++x)
    				{
    					fscanf(otobus_durumu,"%d   %c\n",&koltuk_no[x],&koltuk_durum[x]);
    					if(koltuk_durum[x]=='d')
    	   				++sayac;
    				}
    				gelir=bilet_fiyati*sayac;
    				printf("%s Sefer numarali otobuse ait gelir : \t%d TL\n",gecici->no,gelir);
    				fprintf (logumuz , "%s sefer numarali otobüsün geliri : %s\n",gecici->no,gelir);
    				fclose(otobus_durumu);
					}
					else if(secim_sefer==5)
					{
						FILE *seferler;
    				struct OTOBUS *ilk=NULL,*son=NULL,*gecici=NULL;
    				fprintf (logumuz , "Sefer listeleme secenegine girilmistir.\n");
					if((seferler=fopen("seferler.txt","r+"))==NULL)
    				{
    					printf("Dosya acilamadi.");
    				}
    
    				while(!feof(seferler))
    				{
      					if(ilk==NULL)	/* http://turgayozgur.com/cde-bagli-liste-ile-kayit-fonksiyonlari.html adresinden alýntýdýr. */
	  					{
          				ilk = (OTOBUS *) malloc(sizeof(OTOBUS));
          				fscanf(seferler,"%s   %s   %s   %s   %d   %s   %s   %d   %s\n",ilk->no,ilk->tarih,ilk->guzergah,ilk->saat,&ilk->kapasite,ilk->plaka,ilk->kaptan,&ilk->fiyat,ilk->kapasite_adres);
          				ilk->next = NULL;
          				son = ilk;
       					}
       				else if(son == ilk)
	   				{
   
       					son = (OTOBUS *) malloc(sizeof(OTOBUS));
       					fscanf(seferler,"%s   %s   %s   %s   %d   %s   %s   %d   %s\n",son->no,son->tarih,son->guzergah,son->saat,&son->kapasite,son->plaka,son->kaptan,&son->fiyat,son->kapasite_adres);
       					ilk->next = son;
       					son->next = NULL;
       					son->last = ilk;
       				}
       				else
	   				{
       					gecici = (OTOBUS *) malloc(sizeof(OTOBUS));
      	 				fscanf(seferler,"%s   %s   %s   %s   %d   %s   %s   %d   %s\n",gecici->no,gecici->tarih,gecici->guzergah,gecici->saat,&gecici->kapasite,gecici->plaka,gecici->kaptan,&gecici->fiyat,gecici->kapasite_adres);
       					son->next = gecici;
       					gecici->last = son;

       					son = gecici;
       					son->next = NULL;
          		
       				}  
    				}
    				fclose(seferler);
    
    				gecici=ilk;
    				while(gecici!=NULL)
    				{
    					printf("Sefer no:%s Tarihi:%s Guzergahi:%s Saati:%s\nKapasitesi:%d Plakasi:%s Kaptan:%s Fiyati:%d TL\n\n",gecici->no,gecici->tarih,gecici->guzergah,gecici->saat,gecici->kapasite,gecici->plaka,gecici->kaptan,gecici->fiyat);
						fprintf (logumuz , "Sefer no:%s Tarihi:%s Guzergahi:%s Saati:%s\nKapasitesi:%d Plakasi:%s Kaptan:%s Fiyati:%d TL\n\n",gecici->no,gecici->tarih,gecici->guzergah,gecici->saat,gecici->kapasite,gecici->plaka,gecici->kaptan,gecici->fiyat);     	
						gecici=gecici->next;  
    				}
    				
    				printf("\n\nButun seferler basariyla listelenmistir.Ana menuye donuluyor..");
    				fprintf (logumuz, " Butun seferler basariyla listelenmistir. \n");
					}
					else if(secim_sefer==6)
					{
						fprintf (logumuz, "Gecmis seferleri listeleme secenegine tiklanmistir. \n");
						FILE *seferler;
    					char girilen_tarih[15];
    					struct OTOBUS *ilk=NULL,*son=NULL,*gecici=NULL;
    
						if((seferler=fopen("seferler.txt","r+"))==NULL)
    					{
    						printf("Dosya acilamadi.");
    					}
    
    				while(!feof(seferler))
   		 			{
      					if(ilk==NULL)	/* http://turgayozgur.com/cde-bagli-liste-ile-kayit-fonksiyonlari.html adresinden alýntýdýr. */
	  					{
          				ilk = (OTOBUS *) malloc(sizeof(OTOBUS));
          				fscanf(seferler,"%s   %s   %s   %s   %d   %s   %s   %d   %s\n",ilk->no,ilk->tarih,ilk->guzergah,ilk->saat,&ilk->kapasite,ilk->plaka,ilk->kaptan,&ilk->fiyat,ilk->kapasite_adres);
          				ilk->last = NULL;
       	   				son = ilk;
       					}
       				else if(son == ilk)
	   				{
   
       					son = (OTOBUS *) malloc(sizeof(OTOBUS));
       					fscanf(seferler,"%s   %s   %s   %s   %d   %s   %s   %d   %s\n",son->no,son->tarih,son->guzergah,son->saat,&son->kapasite,son->plaka,son->kaptan,&son->fiyat,son->kapasite_adres);
       					ilk->next = son;
       					son->next = NULL;
       					son->last = ilk;
       				}
       				else
	   				{
       					gecici = (OTOBUS *) malloc(sizeof(OTOBUS));
       					fscanf(seferler,"%s   %s   %s   %s   %d   %s   %s   %d   %s\n",gecici->no,gecici->tarih,gecici->guzergah,gecici->saat,&gecici->kapasite,gecici->plaka,gecici->kaptan,&gecici->fiyat,gecici->kapasite_adres);
       					son->next = gecici;
       					gecici->last = son;

       					son = gecici;
       					son->next = NULL;
          		
       				}  
    				}
    				fclose(seferler);
    
    				printf("Hangi tarihten onceki seferlerin siralanmasini istiyorsunuz?\nLutfen tarihi gg.aa.yyyy seklinde giriniz:\n");
    				scanf("%s",girilen_tarih);
    				fprintf (logumuz, "%s tarihinden onceki seferlerin siralanmasi istenmistir. \n" , girilen_tarih);
    				gecici=ilk;
    				while(gecici!=NULL)	
    				{
    				if(strcmp(gecici->tarih,girilen_tarih)<0)
    	   				printf("Sefer no:%s Tarihi:%s Guzergahi:%s Saati:%s\nKapasitesi:%d Plakasi:%s Kaptan:%s Fiyati:%d TL\n\n",gecici->no,gecici->tarih,gecici->guzergah,gecici->saat,gecici->kapasite,gecici->plaka,gecici->kaptan,gecici->fiyat);
						fprintf (logumuz, "Sefer no:%s Tarihi:%s Guzergahi:%s Saati:%s\nKapasitesi:%d Plakasi:%s Kaptan:%s Fiyati:%d TL\n\n",gecici->no,gecici->tarih,gecici->guzergah,gecici->saat,gecici->kapasite,gecici->plaka,gecici->kaptan,gecici->fiyat);  
						gecici=gecici->next;    
   					}
    				printf("\n\nGecmis seferler basariyla listelenmistir.Ana menuye donuluyor..");
    				fprintf(logumuz, "Gecmis seferler basariyla listelenmistir. \n");
					}
					
					else if(secim_sefer==7)
					{
						FILE *seferler;
						fprintf(logumuz, "Tum sefer sayisi secenegine tiklanmistir. \n");

    					int toplam_sefer=0;
    					struct OTOBUS *ilk=NULL,*son=NULL,*gecici=NULL;
    
						if((seferler=fopen("seferler.txt","r+"))==NULL)
    					{
    						printf("Dosya acilamadi!");
    					}
    
    					while(!feof(seferler))	
    					{
      					++toplam_sefer;
      					if(ilk==NULL)
	  					{
          					ilk = (OTOBUS *) malloc(sizeof(OTOBUS));
          					fscanf(seferler,"%s   %s   %s   %s   %d   %s   %s   %d   %s\n",ilk->no,ilk->tarih,ilk->guzergah,ilk->saat,&ilk->kapasite,ilk->plaka,ilk->kaptan,&ilk->fiyat,ilk->kapasite_adres);
          					ilk->last = NULL;
          					son = ilk;
       					}
      			 		else if(son == ilk)
	   					{
   
       						son = (OTOBUS *) malloc(sizeof(OTOBUS));
       						fscanf(seferler,"%s   %s   %s   %s   %d   %s   %s   %d   %s\n",son->no,son->tarih,son->guzergah,son->saat,&son->kapasite,son->plaka,son->kaptan,&son->fiyat,son->kapasite_adres);
       						ilk->next = son;
       						son->next = NULL;
       						son->last = ilk;
					    }
					    else
	   					{
       						gecici = (OTOBUS *) malloc(sizeof(OTOBUS));
       						fscanf(seferler,"%s   %s   %s   %s   %d   %s   %s   %d   %s\n",gecici->no,gecici->tarih,gecici->guzergah,gecici->saat,&gecici->kapasite,gecici->plaka,gecici->kaptan,&gecici->fiyat,gecici->kapasite_adres);
       						son->next = gecici;
      						gecici->last = son;

       						son = gecici;
       						son->next = NULL;
          		
      					}  
    					}
    				fclose(seferler);
    				printf("Kayitli bulunan sefer sayisi=\t%d\nAna menuye donuluyor..",toplam_sefer);
    				fprintf (logumuz , "Kayitli seferler basariyla yazdirilmistir. \n");
					}
					
					else if(secim_sefer==8)
					   continue;
					else
					{
					   printf("Hatali giris yaptiniz! Tekrar deneyiniz.");goto SEFER_ISLEM;   
					   fprintf (logumuz, "Hatali giris yapilmistir. \n ");
					}
				}
		}
		else if(secim==2)
		{
			fprintf(logumuz, "Bilet islemleri secenegine gidilmistir. \n");

			BILET_ISLEM:
				{
					printf("Lutfen sefer tarihini (gg.aa.yyyy seklinde) giriniz :\n");
					scanf("%s",sefer_tarihi);
					fprintf(logumuz, "sefer tarihi (%s) girilmistir. \n", sefer_tarihi);
					
					printf("Lutfen guzergahi giriniz (Ornegin Kocaeli-Istanbul) :\n");
					scanf("%s",sefer_guzergahi);
					fprintf(logumuz, "Guzergah (%s) girilmistir. \n", sefer_guzergahi);
					
					if((sefer=fopen("seferler.txt","r+"))==NULL)
                	{
		                 printf("Dosya acilamadi!");
	                }
	                
					int sayac=1;
					
					while(!feof(sefer))
					{
						struct OTOBUS *seferler=(struct OTOBUS *)malloc(sizeof(struct OTOBUS));
						fscanf(sefer,"%s   %s   %s   %s   %d   %s   %s   %d   %s\n",seferler->no,seferler->tarih,seferler->guzergah,seferler->saat,&seferler->kapasite,seferler->plaka,seferler->kaptan,&seferler->fiyat,seferler->kapasite_adres);
						strcpy(gecici_tarih,seferler->tarih);
						strcpy(gecici_guzergah,seferler->guzergah);
						if(strcmp(gecici_tarih,sefer_tarihi)==0 && strcmp(gecici_guzergah,sefer_guzergahi)==0)
						{
							printf("\n%d.Sefer No:%s   Tarih:%s   Guzergah:%s   Saat:%s",sayac,seferler->no,seferler->tarih,seferler->guzergah,seferler->saat);
							sayac++;
							fprintf(logumuz, "\n%d.Sefer No:%s   Tarih:%s   Guzergah:%s   Saat:%s \n",sayac,seferler->no,seferler->tarih,seferler->guzergah,seferler->saat);
						}			
						seferler=seferler->next;
						fprintf (logumuz, "Seferler listelenmistir.\n");	
					}
					
					fclose(sefer);
					
					printf("\nLutfen sectiginiz seferin numarasini giriniz:\t");
					scanf("%s",sefer_no);
					fprintf(logumuz, "Listelenen seferlerden (%s) secilmistir.  \n",sefer_no);
					if((sefer=fopen("seferler.txt","r+"))==NULL)
                	{
		                 printf("Dosya acýlamadi!");
	                }
	                
	                while(!feof(sefer))
	                {
							struct OTOBUS *ara=(OTOBUS *)malloc(sizeof(OTOBUS));
	                	    otobus_kapasite=0;
	                	    fscanf(sefer,"%s   %s   %s   %s   %d   %s   %s   %d   %s\n",ara->no,ara->tarih,ara->guzergah,ara->saat,&ara->kapasite,ara->plaka,ara->kaptan,&ara->fiyat,ara->kapasite_adres);
						    otobus_kapasite=ara->kapasite;
						    strcpy(otobus_adres,ara->kapasite_adres);
						    ara=ara->next;
	
						    
					}  
	                	
					fclose(sefer);
					if((kapasite=fopen(otobus_adres,"r+"))==NULL)
                	{
		                 printf("Dosya acýlamadi!!");
	                }
	                
	                int koltuk_numarasi[otobus_kapasite];
					char koltuk_durumu[otobus_kapasite];
					int k=0;
					int secim=0;
	                for(k=0;!feof(kapasite);++k)
	                {
	                	fscanf(kapasite,"%d   %c\n",&koltuk_numarasi[k],&koltuk_durumu[k]);
	                }
	                fclose(kapasite);
	                for(int i=0;i<k;++i)
	                {
	                	printf("\nKoltuk numarasi:%d   Koltuk durumu:%c",koltuk_numarasi[i],koltuk_durumu[i]);
	                }
	                
	                printf("\nb:Bos\td:Dolu\tr:Rezerve");
	                fprintf (logumuz, "Otobus plani listelenmistir.\n");	

	                SECIM:
	                	{
	                		printf("\n\nLutfen secmek istediginiz koltuk numarasini giriniz:\t");
	                        scanf("%d",&secilen_koltuk);
	                       	fprintf (logumuz, "%d numarali koltuk secilmistir.\n",secilen_koltuk);	

	                		printf("\nYapmak istediginiz islemi seciniz:\n1.Bilet satin almak.\n2. Bilet rezerve.\n3.Bilet satis iptali. \n4.Geri.");
	                		printf("\nSecim:\t");
	                		fprintf (logumuz, " \n");
	                        scanf("%d",&secim);
	                        if(secim==1)
	                        {
	                        	fprintf (logumuz, "satin alma islemi secilmistir. \n");
	                        	for(int i=0;i<otobus_kapasite;++i)
	                        	{
	                        		if(secilen_koltuk==koltuk_numarasi[i] && koltuk_durumu[i]== 'b' )
	                        		{
	                        			yolcu = (YOLCU *)malloc(sizeof(YOLCU));
	                        			printf("\nLutfen adinizi giriniz:\t");
	                        			scanf("%s",yolcu->ad);
	                        			fflush(stdin);
	                        			fprintf (logumuz, "yolcunun adi (%s) girilmistir. \n",yolcu->ad);
	                        			printf("Lutfen soyadinizi giriniz:\t");
	                        			scanf("%s",yolcu->soyad);
	                        			fflush(stdin);
	                        			fprintf (logumuz, "yolcunun soyadi (%s) girilmistir. \n",yolcu->soyad);
	                        			printf("Lutfen kimlik numaranizi giriniz:\t");
	                        			scanf("%s",yolcu->kimlik_no);
	                        			fflush(stdin); 
	                        			fprintf (logumuz, "Yolcunun kimlik numarasi (%s) girilmistir. \n",yolcu->kimlik_no);
	                        			strcpy(yolcu->yolcu_sefer_no,sefer_no);
	                        			yolcu->yolcu_koltuk_no=secilen_koltuk;
	                        			koltuk_durumu[i]='d';
	                        			fprintf (logumuz, "Secilen koltuk dolu duruma donusturulmustur. \n");
	                        			if((kapasite=fopen(otobus_adres,"w+"))==NULL)
                	                    {
		                                    printf("Dosya acýlamadi!!");
	                                    }
	                        			for(int q=0;q<otobus_kapasite;++q)
	                        			{	
	                                        fprintf(kapasite,"%d   %c\n",koltuk_numarasi[q],koltuk_durumu[q]);
	                        			}
	                        			fclose(kapasite);
	                        			if((kayit=fopen("kayit.txt","a+"))==NULL)
	                        			{
	                        				printf("Dosya acilamadi!");
	                        			}
	                        			fprintf(kayit,"%s   %s   %s   %s   %d\n",yolcu->yolcu_sefer_no,yolcu->ad,yolcu->soyad,yolcu->kimlik_no,yolcu->yolcu_koltuk_no);
	                        			fclose(kayit);
										printf("\nKayit isleminiz tamamlanmistir. Ana menuye geciliyor..\n");
										fprintf (logumuz, "Kayit islemi tamamlanmistir. \n");
	                        		}
	                        		else if(secilen_koltuk==koltuk_numarasi[i] && koltuk_durumu[i]=='d')
										{
											printf("Secmis oldugunuz koltuk dolu! Lutfen tekrar secim yapiniz!");
											fprintf (logumuz, "Dolu veya rezerve olan koltuk secilmistir, tekrar secilmesi istenmistir.\n");
											goto SECIM;
										}
	                        	}
	                        }
	                        else if(secim==2)
	                        {
	                        	fprintf (logumuz, "rezerve islemi secilmistir. \n");
	                        	for(int i=0;i<otobus_kapasite;++i)
	                        	{
	                        		if(secilen_koltuk==koltuk_numarasi[i] && koltuk_durumu[i]== 'b' )
	                        		{
	                        			
	                        			yolcu = (YOLCU *)malloc(sizeof(YOLCU));
	                        			printf("\nLutfen adinizi giriniz:\t");
	                        			scanf("%s",yolcu->ad);
	                        			fflush(stdin);
	                        			fprintf (logumuz, "yolcunun adi (%s) girilmistir. \n",yolcu->ad);
	                        			printf("Lutfen soyadinizi giriniz:\t");
	                        			scanf("%s",yolcu->soyad);
	                        			fflush(stdin);
	                        			fprintf (logumuz, "yolcunun soyadi (%s) girilmistir. \n",yolcu->soyad);
	                        			printf("Lutfen kimlik numaranizi giriniz:\t");
	                        			scanf("%s",yolcu->kimlik_no);
	                        			fflush(stdin); 
	                        			fprintf (logumuz, "Yolcunun kimlik numarasi (%s) girilmistir. \n",yolcu->kimlik_no);
	                        			strcpy(yolcu->yolcu_sefer_no,sefer_no);
	                        			yolcu->yolcu_koltuk_no=secilen_koltuk;
	                        			koltuk_durumu[i]='r';
	                        			fprintf (logumuz, "Secilen koltuk rezerve duruma donusturulmustur. \n");
	                        			if((kapasite=fopen(otobus_adres,"w+"))==NULL)
                	                    {
		                                    printf("Dosya acýlamadi!!");
	                                    }
	                        			for(int q=0;q<otobus_kapasite;++q)
	                        			{	
	                                        fprintf(kapasite,"%d   %c\n",koltuk_numarasi[q],koltuk_durumu[q]);
	                        			}
	                        			fclose(kapasite);
	                        			if((kayit=fopen("kayit.txt","a+"))==NULL)
	                        			{
	                        				printf("Dosya acilamadi!");
	                        			}
	                        			fprintf(kayit,"%s   %s   %s   %s   %d\n",yolcu->yolcu_sefer_no,yolcu->ad,yolcu->soyad,yolcu->kimlik_no,yolcu->yolcu_koltuk_no);
	                        			fclose(kayit);
										printf("\nRezerve isleminiz tamamlanmistir. Ana menuye geciliyor..\n");
										fprintf (logumuz, "Rezerve islemi tamamlanmistir. \n");
	                        		}
	                        		else if(secilen_koltuk==koltuk_numarasi[i] && koltuk_durumu[i]=='d')
										{
											printf("Secmis oldugunuz koltuk dolu! Lutfen tekrar secim yapiniz!");
											fprintf (logumuz, "Dolu veya rezerve olan koltuk secilmistir, tekrar secilmesi istenmistir.\n");
											goto SECIM;
										}
	                        	}
	                        }
	                        else if(secim==3)
	                        {
	                        	struct YOLCU *ilk=NULL,*son=NULL,*gecici=NULL,*basla=NULL;
	                        	fprintf (logumuz, "Bilet iptali secilmistir. \n");
	                        	for(int i=0;i<otobus_kapasite;++i)
	                	        {
	                	        	if(secilen_koltuk==koltuk_numarasi[i] && koltuk_durumu[i]=='d')
	                	        	{
	                	        		koltuk_durumu[i]='b';
	                	        		fprintf (logumuz, "Koltuk dolu durumdan bos duruma donusturulmustur. \n");
	                	        	}
	                	        }
	                	        
	                	        if((kapasite=fopen(otobus_adres,"w+"))==NULL)
                	            {
		                                    printf("Dosya acilamadi!!");
	                            }
	                                    
	                            for(int q=0;q<otobus_kapasite;++q)
	                        	{	
	                                        fprintf(kapasite,"%d   %c\n",koltuk_numarasi[q],koltuk_durumu[q]);
	                        	}        
	                	        fclose(kapasite);
	                        	
	                	        if((kayit=fopen("kayit.txt","r+"))==NULL)
	                	        {
	                	        	printf("Dosya acilamadi!");
	                	        }
	                	        while(!feof(kayit))/* http://turgayozgur.com/cde-bagli-liste-ile-kayit-fonksiyonlari.html adresinden alýntýdýr. */
	                	        {
	                	        	if(ilk==NULL)
								    {
                                         ilk = (YOLCU *) malloc(sizeof(YOLCU));
                                         fscanf(kayit,"%s   %s   %s   %s   %d\n",ilk->yolcu_sefer_no,ilk->ad,ilk->soyad,ilk->kimlik_no,&ilk->yolcu_koltuk_no);
                                         ilk->next = NULL;
                                         ilk->last = NULL;
                                         son = ilk;
                                         
                                        
                                    } 

                                    else if(son == ilk)
								    {
                                         son = (YOLCU *) malloc(sizeof(YOLCU));
                                         fscanf(kayit,"%s   %s   %s   %s   %d\n",son->yolcu_sefer_no,son->ad,son->soyad,son->kimlik_no,&son->yolcu_koltuk_no);
                                         ilk->next = son;
                                         son->next = NULL;
                                         son->last = ilk;
                                         
                                         
                                    }

                                    else
								    {
                                         gecici = (YOLCU *) malloc(sizeof(YOLCU));
										 
                                         fscanf(kayit,"%s   %s   %s   %s   %d\n",gecici->yolcu_sefer_no,gecici->ad,gecici->soyad,gecici->kimlik_no,&gecici->yolcu_koltuk_no);
                                         son->next = gecici;
                                         gecici->last = son;

                                         son = gecici;
                                         son->next = NULL;
                                         
                                    }
	                	        }
	                	        fclose(kayit);
	                	        int k=0;
	                	        gecici=ilk;
	                	            
								while (strcmp(gecici->yolcu_sefer_no,sefer_no) || !(secilen_koltuk == gecici->yolcu_koltuk_no))
	                	        {
								gecici = gecici->next;
								k++;
								/* http://turgayozgur.com/cde-bagli-liste-ile-kayit-fonksiyonlari.html adresinden alýntýdýr. */
								}

                                if(gecici->next == NULL)
								{

                                       son = son->last;
                                       son->next = NULL;
                                       free(gecici);
                                }

                                else if(gecici->last == NULL)
                                {

                                       ilk = ilk->next;
                                       ilk->last = NULL;
                                       free(gecici);
                                }

                                else
								{

                                       struct YOLCU *temp1, *temp2;

                                       temp1 = gecici;
                                       temp2 = temp1->last;
                                       temp1 = temp1->next;


                                       temp2->next = temp1;
                                       temp1->last = temp2;

                                       free(gecici);
                                }
                                if((kayit=fopen("kayit.txt","w+"))==NULL)
	                	        {
	                	        	printf("Dosya acilamadi!");
	                	        }
                                basla=(YOLCU *)malloc(sizeof(YOLCU));
                                basla=ilk;
                                while(basla != NULL)
								{
					
                                      fprintf(kayit,"%s   %s   %s   %s   %d\n",basla->yolcu_sefer_no,basla->ad,basla->soyad,basla->kimlik_no,basla->yolcu_koltuk_no);
                                      basla = basla->next;
                                }
                                fclose(kayit);
                                
	                	        
	                        	printf("Silme isleminiz tamamlanmistir. Ana menuye geciliyor..\n");	
	                        	fprintf (logumuz, "Silme islemi tamamlanmistir. \n");
	                        }
	                        else if(secim==4)
	                        {
	                	        continue;
	                	        fprintf (logumuz, "Sistemde geri gelinmistir. \n");
	                        }
	                        else
	                            {
	                            	printf("Hatali giris yaptiniz! Lutfen tekrar secim yapiniz!");
	                            	fprintf (logumuz, "Hatali giris yapilmistir. Secimlere geri donulmustur. \n");
									goto SECIM;
	                            }
	                
	                	}
	                
				}
		}
	
		else if(secim==3)
		{
			fprintf (logumuz, "Menude geri gelinmistir. \n");
			break;
		}
		   
		else
		{
			fprintf (logumuz, "Hatali secim yapilmistir. Tekrar secmesi istenmistir. \n");
			printf("Hatali giris yaptiniz! Lutfen tekrar deneyiniz!\n");continue; 
		}
		     
	}
	fprintf (logumuz, "Program kapatilmistir. \n");
	fclose (logumuz);
	return 0;
}
