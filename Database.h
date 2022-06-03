#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct news{ //deklarasi struct berita
	char nomor[5];
	char judul[100]; 
	char topik[15];
	char tanggal[50];
	char penulis[50];
    char link[200];
}news;

typedef struct loginUser{ //deklarasi struct login admin
    char fname[10];
    char username[8];
    char password[8];
    struct loginUser* next;
}user;

void gudangBerita(){ //fungsi untuk menampilkan berita
    FILE *fp = NULL; //deklarasi file
    news *b; //deklarasi struct
    b = (news*)calloc(15, sizeof(news)); //alokasi memori
    fp = fopen("newsData.dat", "w"); //membuka/membuat file untuk writing

    strcpy(b[0].nomor, "001");
    strcpy(b[0].judul, "Jokowi: Transformasi Ekonomi Indonesia Tentu Tak Menyenangkan bagi yang Suka Impor-impor");
    strcpy(b[0].topik, "Nasional");
    strcpy(b[0].tanggal, "2022/03/26");
    strcpy(b[0].penulis, "Dian Erika Nugraheny");
    strcpy(b[0].link, "https://nasional.kompas.com/read/2022/03/26/18023771/jokowi-transformasi-ekonomi-indonesia-tentu-tak-menyenangkan-bagi-yang-suka");

    strcpy(b[1].nomor, "002");
    strcpy(b[1].judul, "Guru Besar IPB: 99 Persen Kebakaran Hutan dan Lahan Ulah Manusia");
    strcpy(b[1].topik, "Pendidikan");
    strcpy(b[1].tanggal, "2022/03/25");
    strcpy(b[1].penulis, "Dian Ihsan");
    strcpy(b[1].link, "https://www.kompas.com/edu/read/2022/03/25/183950071/guru-besar-ipb-99-persen-kebakaran-hutan-dan-lahan-ulah-manusia");

    strcpy(b[2].nomor, "003");
    strcpy(b[2].judul, "Membongkar Deretan Mitos TBC serta Faktanya biar Tidak Salah Kaprah Lagi");
    strcpy(b[2].topik, "Kesehatan");
    strcpy(b[2].tanggal, "2022/03/24");
    strcpy(b[2].penulis, "Hotria Mariana");
    strcpy(b[2].link, "https://health.kompas.com/read/2022/03/24/100046268/membongkar-deretan-mitos-tbc-serta-faktanya-biar-tidak-salah-kaprah-lagi");

    strcpy(b[3].nomor, "004");
    strcpy(b[3].judul, "Tujuh Jenderal Diklaim Tewas, Rusia Turunkan Ambisi dalam Serangan ke Ukraina");
    strcpy(b[3].topik, "Global");
    strcpy(b[3].tanggal, "2022/03/26");
    strcpy(b[3].penulis, "Bernadette Aderi P.");
    strcpy(b[3].link, "https://www.kompas.com/global/read/2022/03/26/183200470/tujuh-jenderal-diklaim-tewas-rusia-turunkan-ambisi-dalam-serangan-ke");

    strcpy(b[4].nomor, "005");
    strcpy(b[4].judul, "Anies: MotoGP Mandalika Sukses Harumkan Indonesia");
    strcpy(b[4].topik, "Nasional");
    strcpy(b[4].tanggal, "2022/03/20");
    strcpy(b[4].penulis, "Kristian Erdianto");
    strcpy(b[4].link, "https://megapolitan.kompas.com/read/2022/03/20/22223601/anies-motogp-mandalika-sukses-harumkan-indonesia");

    strcpy(b[5].nomor, "006");
    strcpy(b[5].judul, "15 Jurusan Kuliah UI dengan Persaingan Tertinggi di SBMPTN 2021");
    strcpy(b[5].topik, "Pendidikan");
    strcpy(b[5].tanggal, "2022/03/18");
    strcpy(b[5].penulis, "Ayunda Pininta Kasih");
    strcpy(b[5].link, "https://www.kompas.com/edu/read/2022/03/18/155505171/15-jurusan-kuliah-ui-dengan-persaingan-tertinggi-di-sbmptn-2021");

    strcpy(b[6].nomor, "007");
    strcpy(b[6].judul, "Catat, Ini 4 Tips Persiapkan Tubuh Jalani Puasa Ramadhan");
    strcpy(b[6].topik, "Kesehatan");
    strcpy(b[6].tanggal, "2022/03/25");
    strcpy(b[6].penulis, "Hisnudita Hagiworo");
    strcpy(b[6].link, "https://health.kompas.com/read/2022/03/25/190219068/catat-ini-4-tips-persiapkan-tubuh-jalani-puasa-ramadhan");

    strcpy(b[7].nomor, "008");
    strcpy(b[7].judul, "Fakta dan Misteri 137 Detik Kecelakaan Boeing 737-800 NG China Eastern Airlines MU5735");
    strcpy(b[7].topik, "Global");
    strcpy(b[7].tanggal, "2022/03/22");
    strcpy(b[7].penulis, "Palupi Annisa A.");
    strcpy(b[7].link, "https://www.kompas.com/global/read/2022/03/22/182640670/fakta-dan-misteri-137-detik-kecelakaan-boeing-737-800-ng-china-eastern");

    strcpy(b[8].nomor, "009");
    strcpy(b[8].judul, "Sekolah Didorong Gelar PTM Terbatas oleh Kemendikbud Ristek");
    strcpy(b[8].topik, "Pendidikan");
    strcpy(b[8].tanggal, "2022/03/26");
    strcpy(b[8].penulis, "Albertus Adit");
    strcpy(b[8].link, "https://www.kompas.com/edu/read/2022/03/26/122314071/sekolah-didorong-gelar-ptm-terbatas-oleh-kemendikbud-ristek");

    strcpy(b[9].nomor, "010");
    strcpy(b[9].judul, "Infrastruktur Jalan dan Air Mulai Dibangun di IKN Nusantara");
    strcpy(b[9].topik, "Nasional");
    strcpy(b[9].tanggal, "2022/03/23");
    strcpy(b[9].penulis, "Suhaiela Bahfein");
    strcpy(b[9].link, "https://www.kompas.com/properti/read/2022/03/23/194500221/infrastruktur-jalan-dan-air-mulai-dibangun-di-ikn-nusantara");
    
    strcpy(b[10].nomor, "011");
    strcpy(b[10].judul, "Daftar Game Baru April 2022, Ada Chrono Cross Versi Remaster");
    strcpy(b[10].topik, "Teknologi");
    strcpy(b[10].tanggal, "2022/04/05");
    strcpy(b[10].penulis, "Kevin Rizky Pratama");
    strcpy(b[10].link, "https://tekno.kompas.com/read/2022/04/05/13010067/daftar-game-baru-april-2022-ada-chrono-cross-versi-remaster");
    
    strcpy(b[11].nomor, "012");
    strcpy(b[11].judul, "Kanye West Mundur dari Festival Coachella 2022");
    strcpy(b[11].topik, "Global");
    strcpy(b[11].tanggal, "2022/04/05");
    strcpy(b[11].penulis, "Vincentius Mario");
    strcpy(b[11].link, "https://www.kompas.com/hype/read/2022/04/05/124659166/kanye-west-mundur-dari-festival-coachella-2022");
    
    strcpy(b[12].nomor, "013");
    strcpy(b[12].judul, "Jadwal Uji Coba Timnas U19 Indonesia pada Bulan Ramadhan");
    strcpy(b[12].topik, "Olahraga");
    strcpy(b[12].tanggal, "2022/04/03");
    strcpy(b[12].penulis, "Celvin Moniaga S.");
    strcpy(b[12].link, "https://bola.kompas.com/read/2022/04/03/21384578/jadwal-uji-coba-timnas-u19-indonesia-pada-bulan-ramadhan");
    
    strcpy(b[13].nomor, "014");
    strcpy(b[13].judul, "Perjalanan Kasus Pemerkosaan 13 Santri oleh Herry Wirawan, Kronologi hingga Vonis Mati");
    strcpy(b[13].topik, "Nasional");
    strcpy(b[13].tanggal, "2022/04/04");
    strcpy(b[13].penulis, "Candra Setia Budi");
    strcpy(b[13].link, "https://bandung.kompas.com/read/2022/04/04/225025378/perjalanan-kasus-pemerkosaan-13-santri-oleh-herry-wirawan-kronologi-hingga");
    
    strcpy(b[14].nomor, "015");
    strcpy(b[14].judul, "Begini Suasana Tarawih Ramadhan di Times Square dan Berbagai Negara");
    strcpy(b[14].topik, "Global");
    strcpy(b[14].tanggal, "2022/04/04");
    strcpy(b[14].penulis, "Alinda Hardiantoro");
    strcpy(b[14].link, "https://www.kompas.com/tren/read/2022/04/04/203000765/begini-suasana-tarawih-ramadhan-di-times-square-dan-berbagai-negara");

    int i;
    for (i = 0; i < 15; i++){ //menampilkan data
        fwrite(&b[i], sizeof(news), 1, fp); //menulis data ke file
    }
    if(fwrite != 0){ //jika berhasil menulis
    	printf("\n  newsData.dat has been restored successfully!\n\n");
        system("CLS");
	}else{ //jika gagal menulis
		printf("\n  Error writing file!\n  ");
	}
    free(b); //mengosongkan memori
    fclose(fp); //menutup file
}
