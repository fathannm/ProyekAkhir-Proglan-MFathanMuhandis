#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include "Database.h"

//function prototype
void opening();
void mainMenu(struct loginUser *head);
void menu_1();
void menu_2(struct loginUser *head);
void menuLoginUser();
void login();
void printBerita(int page);
int searchNews (int size, news b[], char *mstype, int type);
void cariBerita ();
void halamanSelanjutnya();
void pilihBerita(int index);
void OpenlinkWeb(int index);
void sortNews();
void urutBerita(int size, news b[], int urut);
void swap(int j, news b[]);
void readNews(int size, news b[]);
void menuTambahBerita();
void addNews(char *arr, char *cmp);
int cekDataBerita(char *arr);
int getSize();
void low (char str[], char temp[]);
void editNews();
void sortNewsData();
int cariIndexNomor(char *arr);
void restoreNews();
void panduan ();
void loginUser(void);
void registration(void);
int listUser(struct loginUser *head);
void deleteUser(struct loginUser *head);
void transferDataUser(struct loginUser *head);
void insert(struct loginUser **head, char fname[], char username[], char password[]);
void printList(struct loginUser *head);

void opening(){
	int i;
	char arr [14][300] =
		{
		   " ",
		   " ",
    	   " 	+==========================================================================================+",
		   " 	|                                     SELAMAT DATANG                                       |",
		   " 	|                                    E-NEWS MANAGEMENT                                     |",
		   " 	+==========================================================================================+",
		   " 	                                                                                            ",
		   " 	                                  MENU 1 Halaman Berita                                     ",
    	   " 	                                   MENU 2 Login Admin                                       ",
		   " 	                                     MENU 3 Panduan                                         ",
		   " 	                                      MENU 4 EXIT                                           ",
		   " ",
		   " "
		};

		for ( i = 0; i < 14; i++){ //menampilkan opening
    	printf("%s\n", arr[i]);
	}
  	printf("	Press any key to continue . . . "); 
  	getch(); 
}

void mainMenu(struct loginUser *head){
	int  stopMenu = 0, i = 0, pilihMenu = 0; 
	
	//mengecek apakah file newsData.dat ada atau tidak, jika tidak akan dibuat baru
	FILE *fp;
    if (fp = fopen("newsData.dat", "r")) 
        fclose(fp);
    else
        gudangBerita();

	do {
		system("CLS");
    	printf(	"\n\n\t+---------------------------------+\n"
    			"\t|         E-NEWS MANAGEMENT       |\n"
    			"\t|          >> MAIN MENU <<        |\n"
				"\t+---------------------------------+\n\n"
    			"\t  MENU 1 Halaman Berita              \n"
    			"\t  MENU 2 Login Admin        	        \n"
    			"\t  MENU 3 Panduan                     \n" 
				"\t  MENU 4 Exit                        \n"
    			"\t                            	        \n");
  		printf("\tPilihan anda? ");
    	pilihMenu = getch(); //mengambil inputan user
		switch(pilihMenu){ //memilih menu
      		case '1': menuLoginUser(); break; //menu 1
      		case '2': login(head); break; //menu 2
      		case '3':
	  			system("CLS");
	  			panduan(); //menu 3
	  			break;
	  		case '4' : 
			  	system("CLS");
        		printf("\n\n Terima kasih, semoga harimu menyenangkan! ^_^");
        		Sleep(200);
        		exit(0); //keluar dari program
   		 }					  
  	}while(pilihMenu != 4);
}

void menu_1(){
	int page = 0, pilihMenu = 0;
	char choose[10];
    do {
		system("CLS");
    	printBerita(page); //menampilkan berita
        printf("\n  1. Halaman Selanjutnya");
        printf("\n  2. Halaman Awal");
        printf("\n  3. Pencarian Berita");
		printf("\n  4. Pengurutan Berita");
 		printf("\n  5. Kembali ke menu utama");
  		printf("\n  Pilihan anda? ");
		scanf("%s", &choose);
		//error handling
		if(strcmp(choose,"1") == 0)
			pilihMenu = 1;
		else if(strcmp(choose,"2") == 0)
			pilihMenu = 2;
		else if(strcmp(choose,"3") == 0)
			pilihMenu = 3;
		else if(strcmp(choose,"4") == 0)
			pilihMenu = 4;
		else if(strcmp(choose,"5") == 0)
			pilihMenu = 5;
		//pilihan menu
        switch(pilihMenu){
            case 1:
            	page = (page + 1);
            	if(page > getSize()/10){
            		page = getSize()/10;
			      	}
            	printBerita(page); //menampilkan halaman berita selanjutnya
            	break;
            case 2:
            	page = (page - 1)*(page < 0); //menampilkan halaman berita sebelumnya
           		printBerita(page); 
            	break;
            case 3:
				cariBerita(); //menu mencari berita
				break;
			case 4:
				sortNews(); //menu mengurutkan berita
				break;
            case 5: //menu kembali ke menu utama
				break;
        }	
  	}while(pilihMenu != 5);
    printf("\n  Menuju halaman utama . . . ");
    Sleep(1000);
    system("CLS");
}

void menu_2(struct loginUser *head){
	int pilihMenu = 0, cek, page = 0;
	char choose[10];
	do{
		system("cls");
		printf(	" \n  +----------------------------------+\n"
				"  |         E-NEWS MANAGEMENT        |\n"
				"  |       >> EDITORIAL MENU <<       |\n"
				"  +----------------------------------+\n\n"
				"  1. Tambah Berita                 \n"
				"  2. Edit Berita                   \n"
				"  3. Restore Data                  \n"
				"  4. List User	                    \n"
				"  5. Kembali ke menu utama         \n");
		printf("\n  Pilihan anda? ");
		scanf("%s", &choose);

		//error handling
		if(strcmp(choose,"1") == 0){
			pilihMenu = 1;
		}
		else if(strcmp(choose,"2") == 0){
			pilihMenu = 2;
		}
		else if(strcmp(choose,"3") == 0){
			pilihMenu = 3;
		}
		else if(strcmp(choose,"4") == 0){
			pilihMenu = 4;
		}
		else if(strcmp(choose,"5") == 0){
			pilihMenu = 5;
		}
		//pilihan menu
		switch(pilihMenu){
			case 1 : {
				menuTambahBerita(); //menu tambah berita
				break;
			}
			case 2 : {
				editNews(); //menu edit berita
				break;
			}
			case 3 : {
				restoreNews(); //menu restore data
				break;
			}
			case 4 : {
				listUser(head);
				break;
			}
			case 5 : //menu kembali ke menu utama
			pilihMenu = 5;
			break;
			
		}	
		if (pilihMenu > 5 && pilihMenu < 0){ //error handling
			printf("\n  Invalid Menu! Ulang Kembali ");
			Sleep(500);
		}
	}while(pilihMenu != 5);
}

void menuLoginUser(){
	int option;

	system("CLS");
  	printf(	" \n  +----------------------------------+\n"
  			"  |         E-NEWS MANAGEMENT        |\n"
 			"  |       >> MENU LOGIN USER <<      |\n"
 			"  +----------------------------------+\n"
			"  1. Register User               	   \n"
			"  2. Login User				       \n");
	printf("\n  Pilihan anda? ");
    scanf("%d",&option);

    getchar();

    if(option == 1){
        system("CLS");
        registration();
    } else if(option == 2){
        system("CLS");
        loginUser();
    } else if(option > 2 || option < 1){
		printf("\n  Invalid Menu! Ulang Kembali ");
		Sleep(750);
	}
}

void login(struct loginUser *head){ 
  	char username[20], userpwd[10], pilih[3];
 	int i, salah; 
 	system("CLS");
 	printf(	" \n  +----------------------------------+\n"
 			"  |         E-NEWS MANAGEMENT        |\n"
			"  |         >> LOGIN ADMIN <<        |\n"
			"  +----------------------------------+\n");
  	printf("\n  Username: "); 
  	scanf("%s", username); 
  	printf("  Password: "); 
  	for(i = 0; i < 3; i++){ 
    	userpwd[i] = getch(); //mengambil inputan user
    	printf("*"); //menampilkan * ketika input password masuk
 	} 
  	userpwd[i]='\0';
  	if(strcmp(username, "admin") == 0){ //membandingkan username dan password
    	if(strcmp(userpwd, "123") == 0){
			printf("\n\n  Login Berhasil. Selamat datang admin!");
			menu_2(head);
    	}else{
			printf("\n\n  Password yang dimasukkan salah.");
			do{
			printf ("\n  Apakah anda ingin kembali ke menu utama (yes/no)? ");
			scanf ("%s", &pilih);
			if( strcmp( pilih, "yes") == 0 ){
				system("CLS");
				mainMenu(head);
			}else if (strcmp( pilih, "no") == 0){
				system("CLS");
				login(head);
			}else { //error handling
				printf("\n  Input yang ada masukkan tidak ada");
				salah = 1;
			}
			}while(salah == 1);
    	}
	}else { //jika username tidak sesuai
    	printf("\n\n  User tidak ditemukan.");
		do{
			printf ("\n  Apakah anda ingin kembali ke menu utama (yes/no)?");
			scanf ("%s", &pilih);
			if( strcmp( pilih, "yes") == 0 ){
				system("CLS");
				mainMenu(head);
			}else if (strcmp( pilih, "no") == 0){
				system("CLS");
				login(head);
			}else {
				printf("\n  Input yang ada masukkan tidak ada");
				salah = 1;
			}
		}while(salah == 1);
    }
}

void printBerita(int page){
	int i = page*10, end = (page+1)*10;
	sortNewsData(); //sort data berita
  	int size = getSize(); //mengambil size data berita
  	if(end > size){  //jika end lebih besar dari size maka end = size
  		end = size;
	}
  	news b[size];
  	readNews(size, b); //mengambil data berita
  	printf("\n %*s%s%*s\n\n", 60, " ", "E - N E W S   M A N A G E M E N T", 60, " ");
  	printf(" ========================================================================================");
	printf("============================================================================= \n");
  	printf(" | %-10s  %-88s  %-14s  %-16s  %-20s%7s\n","No. ", "Judul", "Topik", "Tanggal", "Penulis", "|");
  	printf(" ========================================================================================");
	printf("============================================================================= \n");
  	for(; i < end; i++){
			printf(" | %.45s  %-90s	%-15s	%-15s	%-20s%10s\n", b[i].nomor, b[i].judul, b[i].topik, b[i].tanggal, b[i].penulis, "|");
  	}
 	printf(" ========================================================================================");
	printf("============================================================================= \n");
}

void cariBerita(){
	int size = getSize();
	news b[size]; //mengambil data berita
	readNews(size, b); //mengambil data berita
	int pilihMenu = 0, found, i, page = 0;
	char choose[10];
	do {
		system("CLS");
		printBerita(page); //print berita
		printf( "\n\n  Pencarian berdasarkan: "
		   		"\n  1. Judul"
		   		"\n  2. Topik"
		   		"\n  3. Tanggal"
		    	"\n  4. Penulis"
		    	"\n  5. Kembali\n"
		   	 	"\n  Pilihan anda? ");
		scanf("%s", &choose);
		//error handling
		if(strcmp(choose,"1") == 0)
			pilihMenu = 1;
		else if(strcmp(choose,"2") == 0)
			pilihMenu = 2;
		else if(strcmp(choose,"3") == 0)
			pilihMenu = 3;
		else if(strcmp(choose,"4") == 0)
			pilihMenu = 4;
		else if(strcmp(choose,"5") == 0)
			pilihMenu = 5;
		//pilihan menu
		switch (pilihMenu){
			case 1 : 
				found = searchNews (size, b, (char *) "Judul", 1); //search berdasarkan judul
				break;
			case 2 : 
				found = searchNews (size, b, (char *) "Topik", 2); //search berdasarkan topik
				break;
			case 3 :
				found = searchNews (size, b, (char *) "Tanggal", 3); //search berdasarkan tanggal
				break;
			case 4 : 
				found = searchNews (size, b, (char *) "Penulis", 4); //search berdasarkan penulis
				break;
			case 5 : break;	
		}
		if (found == 0) {
			printf("\n  Berita tidak ditemukan!");
			printf("\n  Press any key to continue . . . "); 
  			getch();
		} 
	} while (pilihMenu != 5);
	
	if (pilihMenu != 0) { 
		printf("\n  ");
		system("pause");	
	}
}

int searchNews(int size, news b[], char *mstype, int type){
	int i;
	int found = 0;
	char key[300];
	char temp1[300], temp2[300];
	//mengambil data berita
	printf("\n\n  Masukkan %-8s >> ", mstype); //menampilkan kategori berdasarkan pencarian
	if(strcmp(mstype, "Tanggal") == 0)
    	printf("(yyyy/mm/dd) : ");

	scanf(" %70[^\n]s", &key); //mengambil data pencarian
	system("cls");
	printf(" -==============================");
	printf("\n   Result for %-8s \"%s\" :", mstype, key); //menampilkan hasil pencarian
	printf("\n -==============================\n\n");

	switch (type){
		case 1 : { //search berdasarkan judul
			for (i = 0; i < size; i++){
				low(b[i].judul, temp1);
				low(key, temp2); //mengubah huruf besar
				if (strstr(temp1, temp2) != NULL){
					found = 1; 
					OpenlinkWeb(i);
					printf("\n");
				}
			} break;
		}
		case 2 : { //search berdasarkan topik
			for (i = 0; i < size; i++){
				low(b[i].topik, temp1);
				low(key, temp2); //mengubah huruf besar
				if (strstr(temp1, temp2) != NULL){
					found = 1;
					OpenlinkWeb(i);
					printf("\n");
				}
			} break;
		}
		case 3 : { //search berdasarkan tanggal
			for (i = 0; i < size; i++){
				low(b[i].tanggal, temp1);
				low(key, temp2); //mengubah huruf besar
				if (strstr(temp1, temp2) != NULL){
					found = 1;
					OpenlinkWeb(i);
					printf("\n");
				} 
			} break;
		}
		case 4 : { //search berdasarkan penulis
			for (i = 0; i < size; i++){
				low(b[i].penulis, temp1);
				low(key, temp2); //mengubah huruf besar
				if (strstr(temp1, temp2) != NULL){
					found = 1;
					OpenlinkWeb(i);
					printf("\n");
				} 
			} break;
		}
	}
	return found;
}

void pilihBerita(int index){
	FILE *fp = fopen ("newsData.dat", "r"); //membuka file untuk reading
	int size = getSize();
	news b[size]; 
	int i;
	fseek(fp, 0, SEEK_SET); // set file pointer to the beginning of the file
	for(i = 0; i < size; i++){ //read data
		fread(&b[i], sizeof(news), 1, fp);
	}
	//Menampilkan berita
	printf("  >> Data Berita %s <<\n\n", b[index].nomor);
	printf("  Judul    : %s\n", b[index].judul);
	printf("  Topik    : %s\n", b[index].topik);
	printf("  Tanggal  : %s\n", b[index].tanggal);
	printf("  Penulis  : %s\n", b[index].penulis);
	printf("  Link     : %s\n", b[index].link);

	fclose(fp);
}

void OpenlinkWeb(int index){
	FILE *fp = fopen ("newsData.dat", "r"); //membuka file untuk reading
	int size = getSize(); //mengambil jumlah data
	news b[size]; //membuat array
	int  i, counter;
	char pilih [3];
	char temp[300];

	fseek(fp, 0, SEEK_SET); // set file pointer to the beginning of the file
	for(i = 0; i < size; i++){ //read data
		fread(&b[i], sizeof(news), 1, fp);
	}
	//Menampilkan berita
	printf("  >> Data Berita %s <<\n\n", b[index].nomor);
	printf("  Judul    : %s\n", b[index].judul);
	printf("  Topik    : %s\n", b[index].topik);
	printf("  Tanggal  : %s\n", b[index].tanggal);
	printf("  Penulis  : %s\n", b[index].penulis);
	printf("  Link     : %s\n", b[index].link);

	do{
		printf ("\n  Apakah anda ingin membukanya di website (yes/no)? ");
		//pilihan untuk membuka link di web
		scanf("%s", &pilih);
		if( strcmp( pilih, "yes") == 0 ){ //jika pilihan yes
			counter = 1;
			strcpy(temp, "start "); //mengatur command untuk membuka link di web
			strcat(temp, b[index].link); //menambahkan link yang akan dibuka
			system(temp); //membuka link di web
			break;
		}else if ( strcmp( pilih, "no") == 0){ //jika pilihan no
				counter = 2; //counter = 2 untuk menghentikan loop
				printf ("  Baik, Terima Kasih \n");
				break;
		}else
	 			printf("  Error!!!\n"); //jika pilihan tidak ada
	}while ((counter != 1) || (counter != 2)); //jika counter tidak sama dengan 1 atau 2
	fclose(fp);
}

void sortNews(){
	int i, pilihMenu;
	char choose[10];
	int size = getSize (); //mengambil size dari file
	news b[size]; //membuat array news
	readNews(size, b); //membaca data dari file
	
	do {
		system("cls");
		printf("\n %*s%s%*s\n\n", 60, " ", "E - N E W S   M A N A G E M E N T", 60, " ");
  		printf(" ========================================================================================");
		printf("============================================================================= \n");
  		printf(" | %-10s  %-88s  %-14s  %-16s  %-20s%7s\n","No. ", "Judul", "Topik", "Tanggal", "Penulis", "|");
  		printf(" ========================================================================================");
		printf("============================================================================= \n");	
		for(i = 0; i < size; i++){
			printf(" | %.45s  %-90s	%-15s	%-15s	%-20s%10s\n", b[i].nomor, b[i].judul, b[i].topik, b[i].tanggal, b[i].penulis, "|");
  		}
		printf(" ========================================================================================");
		printf("============================================================================= \n");
		printf("\n  Pengurutan berdasarkan:"
				   "\n  1. Judul"
				   "\n  2. Topik"
		    	   "\n  3. Tanggal"
				   "\n  4. Penulis"
				   "\n  5. Kembali\n"
		  		   "\n  Pilihan anda? ");
		scanf("%s", &choose);
		//error handling
		if(strcmp(choose,"1") == 0)
			pilihMenu = 1;
		else if(strcmp(choose,"2") == 0)
			pilihMenu = 2;
		else if(strcmp(choose,"3") == 0)
			pilihMenu = 3;
		else if(strcmp(choose,"4") == 0)
			pilihMenu = 4;
		else if(strcmp(choose,"5") == 0)
			pilihMenu = 5;
		//pilihan untuk mengurutkan berita
		switch (pilihMenu){
			case 1 : 
				urutBerita(size, b, 1);
				break;
			case 2 :
				urutBerita(size, b, 2);
				break;
			case 3 :
				urutBerita(size, b, 3);
				break;
			case 4 :
				urutBerita(size, b, 4);
				break;
			case 5 : break;
			default : printf("\n  Invalid Choice!");
		}
	} while(pilihMenu != 5); //jika pilihan tidak 5 maka loop akan berlanjut
}

void urutBerita(int size, news b[], int urut){
	int i, j;
	
	switch (urut){
		case 1 : { //sorting berdasarkan judul
			for (i = 0; i < size - 1; i++){
				for (j = 0; j < size-1-i; j++){
					if(strcmp(b[j].judul, b[j+1].judul) > 0) {
						swap(j, b);
					}			
				}
			}
			break;
		}
		case 2 : { // sorting berdasarkan topik
			for (i = 0; i < size - 1; i++){
				for (j = 0; j < size-1-i; j++){
					if(strcmp(b[j].topik, b[j+1].topik) > 0) {
						swap(j, b);
	    			}			
				}
			}
			break;
		}
		case 3 : { //sorting berdasarkan tanggal
			for (i = 0; i < size - 1; i++){
				for (j = 0; j < size-1-i; j++){
					if(strcmp(b[j].tanggal, b[j+1].tanggal) > 0) {
						swap(j, b);
					}			
				}
			}
			break;
		}
		case 4 : { //sorting berdasarkan penulis
			for (i = 0; i < size - 1; i++){
				for (j = 0; j < size-1-i; j++){
					if(strcmp(b[j].penulis, b[j+1].penulis) > 0) {
						swap(j, b);
					}			
				}
			}
			break;
		}	
		default : break; //jika pilihan tidak ada
	} 	
}

void swap(int j, news b[]){
	char tempNo[5], tempJdl[100], tempTpk[15], tempTgl[50], tempPen[10], tempLn[200];
	//memasukkan data ke dalam variabel temporary nomor
	strcpy(tempNo, b[j].nomor);
    strcpy(b[j].nomor, b[j+1].nomor); 
    strcpy(b[j+1].nomor, tempNo); 
    //memasukkan data ke dalam variabel temporary judul
	strcpy(tempJdl, b[j].judul); 
    strcpy(b[j].judul, b[j+1].judul); 
    strcpy(b[j+1].judul, tempJdl); 
	//memasukkan data ke dalam variabel temporary topik
	strcpy(tempTpk, b[j].topik); 
    strcpy(b[j].topik, b[j+1].topik); 
    strcpy(b[j+1].topik, tempTpk);
	//memasukkan data ke dalam variabel temporary tanggal
	strcpy(tempTgl, b[j].tanggal); 
    strcpy(b[j].tanggal, b[j+1].tanggal); 
    strcpy(b[j+1].tanggal, tempTgl); 
	//memasukkan data ke dalam variabel temporary penulis
	strcpy(tempPen, b[j].penulis); 
    strcpy(b[j].penulis, b[j+1].penulis); 
    strcpy(b[j+1].penulis, tempPen);
	//memasukkan data ke dalam variabel temporary link
	strcpy(tempLn, b[j].link); 
    strcpy(b[j].link, b[j+1].link); 
    strcpy(b[j+1].link, tempLn);	
}

void low (char str[], char temp[]){
	int i;
	//mengubah huruf besar menjadi huruf kecil
	for (i = 0; i < strlen(str); i++){
		temp[i] = tolower(str[i]); 
	}
}

void readNews(int size, news b[]){
	int i;
	FILE *fp = fopen ("newsData.dat", "r"); //membuka file untuk reading
	fseek(fp, 0, SEEK_SET);
	for (i = 0; i < size; i++){ //membaca data dari file
		fread(&b[i], sizeof(news), 1, fp);
	}
	fclose(fp);
}

int getSize(){
	FILE *fp = fopen ("newsData.dat", "r"); //membuka file untuk reading
	fseek(fp, 0, SEEK_END);
	int size = ftell(fp)/sizeof(news); //menghitung jumlah data
	fclose(fp);
	return size;
}

void menuTambahBerita(){
	int i, index;
	FILE *fp;
	fp = fopen ("newsData.dat", "a"); //membuka file dengan mode append
	index = getSize();
	char pilih;
	news b; //ditambahkan 1 per satu sehingga tidak menggunakan array
	
	do {
		system("cls");
		printf(	" \n  +----------------------------------+\n"
				"  |         E-NEWS MANAGEMENT        |\n"
				"  |      >> MENU TAMBAH BERITA <<    |\n"
				"  +----------------------------------+\n\n");
		printf("\n  Ingin tambah berita (y/n)? ");
		scanf(" %[^\n]c", &pilih);
		if(pilih == 'y'){ 
			printf("\n  Data Berita Ke-%d", index+1); 
			printf("\n  -----------------------------------\n");	
			//memasukkan data ke dalam variabel b
			addNews(b.nomor, (char *) "Nomor");
			addNews(b.judul, (char *) "Judul");
			addNews(b.topik, (char *) "Topik");
			addNews(b.tanggal, (char *) "Tanggal");
			addNews(b.penulis, (char *) "Penulis");
			addNews(b.link, (char *) "Link");
			
			int cek = fwrite(&b, sizeof(news), 1, fp); //menulis data ke file
			
			if (cek != 0)
				printf("\n  Add news success!\n  ");
				system("pause");
				index++;
			} else printf("\n  Add news failed!\n  ");
			
	} while (pilih != 'n');
	
	fclose(fp);
}

void addNews(char *arr, char *cmp){
	int cek;
	char temp[100];
	do {
		printf("  %-8s : ", cmp); //menampilkan kategori
		if(strcmp(cmp, "Tanggal") == 0)
			printf("(yyyy/mm/dd) >> ");
		scanf(" %100[^\n]s", &temp); //memasukkan data
		cek = cekDataBerita(temp); //cek apakah data sudah ada atau belum
	} while (cek == 0); //jika data sudah ada maka akan diulang
	strcpy(arr, temp);
}

int cekDataBerita(char *arr){
	//pengecekan apakah ada data buku yang sama	
	int cek = 1;
	int i;
	int size = getSize(); //mengambil jumlah data buku
	
	news b[size]; //array buku
	readNews(size, b); //membaca data buku dari file
	
	for(i = 0; i < size; i++){ //cek data buku yang sama
		if (stricmp(arr, b[i].nomor) == 0) { //
			cek = 0;
			break;	
		}
		if (stricmp(arr, b[i].judul) == 0) { //cek judul
			cek = 0;
			break;	
		}else cek = 1;	
	}
	
	if (cek == 1) return 1; //jika tidak ada yang sama
	if (cek == 0) {
		printf("  Berita sudah ada!\n"); 
		return 0; //jika ada yang sama
	}
}

void sortNewsData(){
	FILE *fp;
	int i,j;
	int size = getSize (); //mencari banyaknya buku dalam data
	news b[size];
	readNews(size, b); //membuat b dapat mengakses data
	//dilakukan sortir berdasarkan nomor berita	
	for (i = 0; i < size - 1; i++){
		for (j = 0; j < size-1-i; j++){
			if(strcmp(b[j].nomor, b[j+1].nomor) > 0) {
				swap(j, b);
	    	}			
		}
	}
	//selanjutnya data yang sudah terurut dimasukkan dalam data	
	fp = fopen("newsData.dat", "r+");
	for (i = 0; i < size; i++){
		fwrite(&b[i],sizeof(news), 1, fp);
	}
	fclose(fp);
}

void editNews(){	
	FILE *fp;
	int size = getSize();
	news b[size]; 
	readNews(size, b);
	int index = 0, i, page = 0, cek, pilihMenu;
	char temp[300], choose[10], pilih[10];
	char nomor[10]; 
	int cmp = -1; //cmp dipilih tdk 0
	do {
		system("CLS");
		printBerita(page);
		printf("\n  1. Halaman Selanjutnya"); 
        printf("\n  2. Halaman Awal");
        printf("\n  0. Lanjut Edit\n\n  >> ");
        scanf("%s", &choose);
		//error handling
		if(strcmp(choose,"0") == 0)
			pilihMenu = 0;
		else if(strcmp(choose,"1") == 0)
			pilihMenu = 1;
		else if(strcmp(choose,"2") == 0)
			pilihMenu = 2;
        //pilihan menu
        switch(pilihMenu){
        	case 0: break;
            case 1:
            	page = (page+1);
            	if(page > getSize()/10){
            		page = getSize()/10;
			      	}
            	printBerita(page);
            	break;
            case 2:
        		page = (page - 1)*(page < 0);
           		printBerita(page);
            	break;	
        }
    }while(pilihMenu != 0);
    
	do{
		printf("\n  Masukkan nomor berita (Contoh : 001, '7' Untuk kembali): ");
		scanf(" %10[^\n]s", &nomor);
		if (strcmp(nomor, "7") == 0) index = -2; //untuk back
		else index = cariIndexNomor(nomor); //mencari index berdasarkan nomor
		
		while (index != -1 && index != -2){ //-1 bila id tidak ditemukan
			system("cls");
			printf(	" \n  +----------------------------------+\n"
					"  |         E-NEWS MANAGEMENT        |\n"
					"  |       >> MENU EDIT BERITA <<     |\n"
					"  +----------------------------------+\n\n");
			pilihBerita(index);
			printf( "\n  1. Edit Nomor                   \n"
					"  2. Edit Judul                   \n"
					"  3. Edit Topik                   \n"
					"  4. Edit Tanggal                 \n"
					"  5. Edit Penulis                 \n"
					"  6. Edit Link                    \n\n"
					"  7. Kembali                      \n\n");
			printf("\n  Pilihan anda? ");
			scanf("%s", &pilih);
			//error handling
			if(strcmp(pilih,"1") == 0)
				cmp = 1;
			else if(strcmp(pilih,"2") == 0)
				cmp = 2;
			else if(strcmp(pilih,"3") == 0)
				cmp = 3;
			else if(strcmp(pilih,"4") == 0)
				cmp = 4;
			else if(strcmp(pilih,"5") == 0)
				cmp = 5;
			else if(strcmp(pilih,"6") == 0)
				cmp = 6;
			else if(strcmp(pilih,"7") == 0)
				cmp = 7;
			
			if (cmp == 7) break;
			else {
				fp = fopen ("newsData.dat", "r+"); //membuka file untuk reading dan writing
				do {
					printf("\n  Edit menjadi: ");
					scanf(" %300[^\n]s", &temp);
					cek = cekDataBerita(temp); //cek data berita apakah sudah ada
					if (cek == 1){ //jika tidak ada yang sama
						switch (cmp){ //menentukan index yang akan diubah
							case 1 : strcpy(b[index].nomor, temp); break;
							case 2 : strcpy(b[index].judul, temp); break;
							case 3 : strcpy(b[index].topik, temp); break;
							case 4 : strcpy(b[index].tanggal, temp); break;
							case 5 : strcpy(b[index].penulis, temp); break;
							case 6 : strcpy(b[index].link, temp); break;
						}	
					}		
				} while (cek == 0); //jika ada yang sama
				//selanjutnya data yang sudah terurut dimasukkan dalam data
				for (i = 0; i < size; i++){
					fwrite(&b[i],sizeof(news), 1, fp);
				}	
				//jika data berhasil diubah
				if(fwrite != 0) printf("\n  Data sudah diperbarui!\n  ");
				else printf("\n  Data gagal diperbarui!\n  ");
			}
			fclose(fp);
		}
	} while (index != -2);
}

int cariIndexNomor(char *arr){
	FILE *fp = fopen ("newsData.dat", "r"); //membuka file untuk reading
	news b;
	int cek = 0;
	int i = 0;
	
	while(fread(&b, sizeof(news), 1, fp )){ //baca file
		if(strcmp(arr, b.nomor) == 0) { //jika nomor sama
			cek = 1; //berhasil ditemukan
			break;
		}
		else i++;
	}
	
	if (cek == 1) { //jika nomor ditemukan
		fclose(fp);	
		return i;	
	}else { //jika tidak ditemukan
		printf("\n  Nomor berita tidak ditemukan!\n  ");
		system("pause");
		return -1;
		fclose(fp);		
	}
}

void restoreNews(){
	char inputKey[5]; //input kunci
	char restoreKey[] = "12345"; int cekKey = 0;
	char pilih;
	
	system("cls");
	printf(	" \n  +----------------------------------------------+\n"
			"  |               E-NEWS MANAGEMENT                 |\n"
			"  |            >> MENU RESTORE DATA <<              |\n"
			"  | Fungsi ini akan me-restore data menjadi default |\n"
			"  +-------------------------------------------------+\n\n");
	while (cekKey == 0){ //cek kunci
		printf("\n  Masukkan kunci untuk me-restore : ");
		scanf(" %8[^\n]s", &inputKey);
		
		if (strcmp(restoreKey, inputKey) == 0) cekKey = 1; //kunci benar
		else { //kunci salah
			printf("  Kata kunci salah!\n");
			Sleep(750);
			break;
		}
	}
	
	if (cekKey == 1){ //jika kunci benar akan merestore data
		do {
			printf("  Apakah anda yakin (y/n)? ");
			scanf(" %[^\n]c", &pilih);
			if (pilih == 'y') {
				gudangBerita(); //me-restore data
				printf("\n\n  "); 
				system("pause");
			}
		} while (pilih != 'y' && pilih != 'n');
	}
}

void panduan(){
	int i;
	char arr [35][300] =
	{"  >> Menu Utama <<",
	 "  1. Pilihlah menu yang diinginkan sesuai nomor ",
	 "    - Menu 1 adalah halaman kumpulan berita ",
	 "    - Menu 2 adalah halaman login untuk admin ",
	 "    - Menu 3 adalah halaman panduan program",
	 "    - Menu 4 program akan keluar ",
	 " ",
	 "  >> Menu 1 <<",
	 "  1. Pilihlah menu yang diinginkan sesuai nomor ",
	 "  2. Program akan menampilkan kumpulan berita ",
	 "  3. Terdapat fungsi untuk berpindah halaman, mencari berita, dan mengurutkan berita ",
	 "  4. Pilihlah fungsi yang diinginkan sesuai nomor ",
	 "	  - Pilihan 1 untuk berpindah halaman selanjutnya ",
	 "	  - Pilihan 2 untuk berpindah halaman sebelumnya ",
	 "	  - Pilihan 3 untuk mencari berita berdasarkan judul, topik, tanggal, dan penulis. Lalu dapat menuju link yang dituju ",
	 "	  - Pilihan 4 untuk mengurutkan (Angka-Kapital-Huruf Kecil) berita berdasarkan judul, topik, tanggal, dan penulis ",
	 "	  - Pilihan 5 untuk kembali pada menu utama ",
	 " ",
	 "  >> Menu 2 <<",
	 "  Username : admin ; Password : 123 ; Restore Key : 12345 ",
	 "  1. Program akan meminta untuk memasukkan username dan password ",
	 "  2. Jika sesuai maka akan berpindah pada halaman editorial ",
	 "  3. Terdapat 5 pilihan fungsi. Pilihlah fungsi yang diinginkan sesuai nomor ",
	 "	  - Pilihan 1 berfungsi untuk menambah berita ",
	 "	  - Pilihan 2 berfungsi untuk mengedit berita ",
	 "	  - Pilihan 3 berfungsi untuk menghapus berita ",
	 "	  - Pilihan 4 berfungsi untuk mengembalikan berita yang ada ke default ",
	 "	  - Pilihan 5 untuk kembali pada menu utama ",
	 " ",
	 "  >> Menu 3 <<",
	 "  Program akan menampilkan panduan program E-News Management",
	 " ",
	 "  >> Menu 4 <<",
	 "  Program akan keluar. ",
	};

	printf(	" \n  +----------------------------------+\n"
				"  |         E-NEWS MANAGEMENT        |\n"
				"  |         >> MENU PANDUAN <<       |\n"
				"  +----------------------------------+\n\n");

	for ( i = 0; i < 35; i++){ //output
    	printf("%s\n", arr[i]);
	}
  				
	printf("  Press any key to continue . . . "); 
  	getch(); 
}

//fungsi untuk login user
void loginUser(){
	system("cls");
    char username[8], password[8];
    FILE *log;

    log = fopen("login.txt","r");
    if (log == NULL){
        fputs("Error at opening File!", stderr);
        exit(1);
    }

    user l;

    printf("\n Silahkan masukkan data pengguna anda dengan benar di bawah ini.\n\n");
    printf(" Username: ");
    scanf("%s", &username);
    printf("\n Password: ");
    scanf("%s", &password);

    while(fread(&l, sizeof(l), 1, log)){
        if(strcmp(username,l.username)==0 && strcmp(password,l.password)==0){   
            printf("\nLogin Berhasil.\n");
			Sleep(1000);
			menu_1();
        }
    }

	if(strcmp(username,l.username)!=0 || strcmp(password,l.password)!=0){
		printf("\nLogil Gagal.\nSilahkan masukkan data anda dengan benar.\n");
		Sleep(1000);
	}

    fclose(log);
    return;
}

//fungsi untuk registrasi user baru
void registration(){
	FILE *log;
	user l;
	char username[8], password[8], fname[10];

	log = fopen("login.txt","a");
	if (log == NULL){
		fputs("Error at opening File!", stderr);
		exit(1);
	}
	
	printf("\n Note!\n 1. Nama maksimal 10 karakter\n"
			" 2. Username maksimal 8 karakter\n "
			"3. Password maksimal 8 karakter\n\n");
	// memasukkan nama penguna, username dan password
	printf(" Nama Anda: ");
	scanf(" %[^\n]c", &fname);
	printf(" Username: ");
	scanf("%s", &username);
	printf(" Password: ");
	scanf("%s", &password);

	//error handling username sudah ada di data, maka diulang
	while(fread(&l, sizeof(l), 1, log)){
		if(strcmp(username,l.username)==0){
			printf("\nUsername sudah ada, silahkan masukkan username lain\n");
			printf("\n Username: ");
			scanf("%s", &username);
		}
	}
	//menulis semua data ke file
	strcpy(l.fname, fname);
	strcpy(l.username, username);
	strcpy(l.password, password);
	
	fwrite(&l, sizeof(l), 1, log);
	fclose(log);
	
	printf("\nPendaftaran Berhasil.\n");
	Sleep(1000);
	loginUser();
}

//fungsi untuk menampilkan list user dalam bentuk tabel
int listUser(struct loginUser *head){
	system("cls");
	FILE *log;
	user l;

	int i = 0;
	int pilihMenu;
	
	log = fopen("login.txt","r");
	if (log == NULL){
		fputs("Error at opening File!", stderr);
		exit(1);
	}
	head = malloc(sizeof(user));
	if(head == NULL){
		return 1;
	}
	
	do{
		system("cls");
		//tabel list user
		printf("\n+--------------------------------------+\n");
		printf("|              LIST USER               |\n");
		printf("+--------------------------------------+\n");
		printf("| No.  |   First Name   |   Username   |\n");
		printf("+--------------------------------------+\n");
		//list user
		while(fread(&l, sizeof(l), 1, log)){
			printf("| %d.   |   %10s   |   %8s   |\n", ++i, l.fname, l.username);
		}
		printf("+--------------------------------------+\n");

		printf("\n1. Hapus User (Dalam Perbaikan)");
		printf("\n2. Kembali ke Menu Admin");
		printf("\n\nPilihan anda? ");
		scanf("%d", &pilihMenu);

		switch(pilihMenu){
			case 1:
				deleteUser(head);
				break;
			case 2:
				menu_2(head);
				break;
		}
		if (pilihMenu > 2 && pilihMenu < 0){ //error handling
			printf("\n  Invalid Menu! Ulang Kembali ");
			Sleep(500);
		}
	}while(pilihMenu != 2);
	fclose(log);
}

//fungsi untuk mengambil data-data user untuk dimasukkan ke dalam linked list
void transferDataUser(struct loginUser *head){
	FILE *log;
	user l;
	log = fopen("login.txt","r");
	if (log != NULL){
		while(fscanf(log, "%30[^\n]s", l.fname) == 1 && fscanf(log, "%30[^\n]s", l.username) == 1
		&& fscanf(log, "%30[^\n]s", l.password) == 1){
			insert(&head, l.fname, l.username, l.password);
		}
	}else{
		printf("\n  Error at reading File!");
		Sleep(1000);
	}
	fclose(log);
}

//fungsi untuk memasukkan data user ke dalam linked list
void insert(struct loginUser **head, char fname[], char username[], char password[]){
	struct loginUser *log = (struct loginUser*)malloc(sizeof(struct loginUser));
	struct loginUser *temp = *head;

	//insert data
	strcpy(log->fname, fname);
	strcpy(log->username, username);
	strcpy(log->password, password);

	// jika head kosong, maka list kosong
    if(temp == NULL)
         temp = log;
	//mencari node terakhir dan menambah node baru
    else{
        while(temp->next != NULL){ //ketika temp->next != NULL, maka temp akan berpindah ke node selanjutnya
            temp = temp->next;
        }
        temp->next = log; //node terakhir akan menjadi next dari node baru
    }
	printList(temp);
}

//fungsi untuk menampilkan list user yang sudah dihapus
void printList(struct loginUser *head){
	struct loginUser *temp = head;
    FILE *log;
		log = fopen("login.txt","w");
		if (log == NULL){
			fputs("Error at opening File", stderr);
			Sleep(1000);
			exit(1);
		}
		temp = head;
		while(temp != NULL){ //ketika temp != NULL, maka temp akan menulis data ke file
			fprintf(log, "%s\n", temp->fname); 
			fprintf(log, "%s\n", temp->username);
			fprintf(log, "%s\n", temp->password);
			temp = temp->next;
		}
		fclose(log);
		printf("\nUser berhasil dihapus!\n");
		Sleep(1000);
		listUser(temp);
}

//fungsi untuk menghapus satu user pilihan
void deleteUser(struct loginUser *head){
	system("cls");
	FILE *log;
	user l;
	int i = 0;
	log = fopen("login.txt","r");
	if (log == NULL){
		fputs("Error at opening File!", stderr);
		Sleep(1000);
		exit(1);
	}

	int option;
	//tabel list user
	printf("\n+--------------------------------------+\n");
	printf("|              LIST USER               |\n");
	printf("+--------------------------------------+\n");
	printf("| No.  |   First Name   |   Username   |\n");
	printf("+--------------------------------------+\n");
	//list user
	while(fread(&l, sizeof(l), 1, log)){
		printf("| %d.   |   %10s   |   %8s   |\n", ++i, l.fname, l.username);
	}
	printf("+--------------------------------------+\n");
	fclose(log);
	
	printf("\nPilih user yang akan dihapus sesuai nomor diatas! ");
	printf("\n\nPilihan nomor? ");
	scanf("%d", &option);
	
	//hapus user yang dipiih
	if(option > i){
		printf("\n  Invalid Menu! Ulang Kembali ");
		Sleep(500);
	}
	else{
		log = fopen("login.txt","r");
		if (log == NULL){
			fputs("Error at opening File!", stderr);
			Sleep(1000);
			exit(1);
		}
		
		struct loginUser *temp = head;
		struct loginUser *prev = NULL;
		
		int j = 0;
		while(temp != NULL){
			if(j == option-1){
				prev->next = temp->next;
				free(temp);
				break;
			}
			prev = temp;
			temp = temp->next;
			j++;
		}
		printList(temp);
	}
}