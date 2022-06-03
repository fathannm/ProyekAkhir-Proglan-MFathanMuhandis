# ProyekAkhir-Proglan-MFathanMuhandis
Proyek Akhir Semester - Pemograman Lanjutan - Kelas 01
Judul : E-News Management
Anggota :
    1. Muhammad Cavan Naufal Azizi
    2. Muhammad Aqil Muzakky
    3. Muhammad Fathan Muhandis

Penjelasan :
1. loginUser(struct loginUser *head)
Fungsi ini digunakan untuk masuk ke dalam halaman berita bagi pengguna, program akan membuka file login.txt sebagai database. Ketika user memasukkan username atau password yang tidak ada, maka program akan meminta kembali username dan password.

2. registration(struct loginUser *head)
Fungsi ini bertujuan untuk mendaftarkan akun  yang belum terdaftar dimana program akan meminta nama pengguna, username, dan password yang akan daftarkan. Program akan memasukkan data data tersebut ke dalam database (login.txt).

3. listUser(struct loginUser *head)
Fungsi ini bertujuan untuk menampilkan list akun pengguna yang telah terdaftar pada menu admin.

4. transferDataUser(struct loginUser *head)
Fungsi ini digunakan untuk memindahkan file yang ada pada database ke struct user atau linked list.

5. insert(struct loginUser **head, struct loginUser *l)
Fungsi ini berguna untuk menyalin data pada file handling ke linked list.

6. printList(struct loginUser *head)
Fungsi ini berguna untuk menyetak list user yang ada pada pointer temp.

7. deleteUser(struct loginUser *head) 
Fungsi yang digunakan oleh admin untuk menghapus akun pengguna yang telah terdaftar atau masuk kedalam database.

8. deletePosition(struct loginUser **head, int n)
Fungsi untuk menghapus data user yang dipilih pada fungsi deleteUser sebelumnya.

9. savePrintList(struct loginUser *head)
Fungsi ini berguna untuk save list terbaru yang sudah dihapus ke dalam file login.txt.