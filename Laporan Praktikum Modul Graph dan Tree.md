# <h1 align="center">Laporan Praktikum Modul Graph dan Tree Table</h1>
<p align="center">Mikhael Setia Budi</p>

## Dasar Teori

### Graph
Graf atau graph adalah struktur data yang digunakan untuk merepresentasikan
hubungan antara objek dalam bentuk node atau vertex dan sambungan antara node
tersebut dalam bentuk sisi atau edge.

### Tree atau Pohon
Dalam ilmu komputer, pohon/tree adalah struktur data yang sangat umum dan kuat
yang menyerupai nyata pohon. Ini terdiri dari satu set node tertaut yang terurut
dalam grafik yang terhubung, dimana setiap node memiliki paling banyak satu
simpul induk, dan nol atau lebih simpul anak dengan urutan tertentu. Struktur data
tree digunakan untuk menyimpan data-data hirarki seperti pohon keluarga, skema
pertandingan, struktur organisasi.

## Guided 

## 1. Graph

```C++
#include<iostream> 
#include<iomanip> 
using namespace std; 

string simpul[7] = {"ciamis", "Bandung","Bekasi","Tasikmalaya","cianjur","Purwokerto", "Yogyakarta"}; 

int busur [7][7] = { 
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 9, 15, 0},
    {0, 5, 0, 9, 5, 0, 0},
    {0, 0, 0, 2, 4, 0, 8},
    {3, 0, 0, 1, 0, 0, 0},
    {0, 0, 7, 0, 0, 9, 4},
    {0, 0, 0, 0, 8, 0, 0}
};

void tampilGraph(){ 
    for(int i = 0; i < 7; i++){ 
        cout<<simpul[i]<<" : "<<endl; 
        for(int j = 0; j < 7; j++){ 
            if(busur[i][j] != 0 ) 
            cout<<"-->"<<simpul[j]<<" ("<<busur[i][j]<<")"<<endl; 
        }
        cout<<endl; 
    }
}

int main(){ 
    tampilGraph(); 
    return 0; 
}
```

**Code 1**
```C++
#include<iostream> 
#include<iomanip> 
using namespace std; 
```
kode diatas digunakan untuk mendefinisikan header file iostream yang berisi definisi objek input dan output standar seperti cin, dan cout. 
include <iomanip digunakan untuk menyertakan pustaka untuk memanipulasi input-output seperti pengaturan lebar dan format output.
Menggunakan namespace std agar kita bisa menggunakan objek dan fungsi dari std

**Code 2**
```C++
int busur [7][7] = { 
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 9, 15, 0},
    {0, 5, 0, 9, 5, 0, 0},
    {0, 0, 0, 2, 4, 0, 8},
    {3, 0, 0, 1, 0, 0, 0},
    {0, 0, 7, 0, 0, 9, 4},
    {0, 0, 0, 0, 8, 0, 0}
};
```
mendeklarasikan array simpul yang digunakan untuk menyimpan nama-nama simpul dalam graf.
mendeklarasikan matriks busur yang digunakan untuk menyimpan bobot dari busur antara simpul-simpul. Jika busur[i][j] != 0, maka ada busur dari simpul i ke simpul j dengan bobot busur[i][j].

**Code 3**
```C++
void tampilGraph(){ 
    for(int i = 0; i < 7; i++){ 
        cout<<simpul[i]<<" : "<<endl; 
        for(int j = 0; j < 7; j++){ 
            if(busur[i][j] != 0 ) 
            cout<<"-->"<<simpul[j]<<" ("<<busur[i][j]<<")"<<endl; 
        }
        cout<<endl; 
    }
}
```
kode diatas merupakan fungsi tampilGraph yang digunakan untuk menampilkan graf dalam bentuk teks.

**Code 4**
```C++
int main(){ 
    tampilGraph(); 
    return 0; 
}
```
int main() merupakan fungsi utamana. dalam fungsi main terdapat kode yang digunakan untuk memanggil fungsi tampilGraph untuk menampilkan graf.

#### Output
```C++
ciamis : 
-->Bandung (7)
-->Bekasi (8)

Bandung :
-->Bekasi (5)
-->cianjur (9)
-->Purwokerto (15)

Bekasi :
-->Bandung (5)
-->Tasikmalaya (9)
-->cianjur (5)

Tasikmalaya :
-->Tasikmalaya (2)
-->cianjur (4)
-->Yogyakarta (8)

cianjur :
-->ciamis (3)
-->Tasikmalaya (1)

Purwokerto :
-->Bekasi (7)
-->Purwokerto (9)
-->Yogyakarta (4)

Yogyakarta :
-->cianjur (8)
```
menampilkan jarak dari tiap tiap kota.

#### Full Code Screenshoot
![alt text](https://github.com/MikhaelSetiaBudi/Praktikum-Algoritma-Struktur-Data-Modul-10-Graph-dan-Tree/blob/master/Modul%2010%20Alstrukdat/Code%20Guided%201%20Graph%20dan%20Tree.png?raw=true)

#### Output Screenshot
![alt text](https://github.com/MikhaelSetiaBudi/Praktikum-Algoritma-Struktur-Data-Modul-10-Graph-dan-Tree/blob/master/Output%20Modul%2010%20Alstrukdat/Output%20Guided%201%20Graph%20dan%20Tree.png?raw=true)

## 2. Tree

```C++
#include<iostream>
#include<iomanip> 
using namespace std;

struct pohon {
    pohon * kanan;
    char data;
    pohon * kiri;
};

pohon * simpul;
pohon * root;
pohon * saatIni;
pohon * helperA;
pohon * helperB;
pohon * alamat[256];

void inisialisasi(){
    root = NULL;
    saatIni = NULL;
    helperA = NULL;
    helperB = NULL;
}

void simpulBaru(char dataMasukkan){
    simpul = new pohon;
    simpul->data = dataMasukkan;
    simpul->kanan = NULL;
    simpul->kiri = NULL;
}

void simpulAkar(){
    if (root == NULL) {
        char dataAnda;
        cout << "Masukkan data akar: ";
        cin >> dataAnda;
        simpulBaru(dataAnda);
        root = simpul;
        cout << "Simpul akar berhasil dibuat...\n";
    } else {
        cout << "Simpul akar sudah ada...\n";
    }
}

void tambahSimpul() {
    if (root != NULL) {
        int i = 1, j = 1, penanda = 0;
        char dataUser;
        alamat[i] = root;

        while (penanda == 0 && j < 25) {
            cout << "Masukkan data kiri : ";
            cin >> dataUser;
            if (dataUser != '0') {
                simpulBaru(dataUser);
                saatIni = alamat[i];
                saatIni->kiri = simpul;
                j++;
                alamat[j] = simpul;
            } else {
                penanda = 1;
                j++;
                alamat[j] = NULL;
            }
            if (penanda == 0) {
                cout << "Masukkan data kanan : ";
                cin >> dataUser;
                if (dataUser != '0') {
                    simpulBaru(dataUser);
                    saatIni = alamat[i];
                    saatIni->kanan = simpul;
                    j++;
                    alamat[j] = simpul;
                } else {
                    penanda = 1;
                    j++;
                    alamat[j] = NULL;
                }
            }
            i++;
        }
    }
}

void bacaPohon(){
    if (root != NULL) {
        int i = 1, n = 1, pencacah = 0;
        cout << endl;
        while (alamat[i] != NULL){
            saatIni = alamat[i];
            if (saatIni->data < 10) {
                cout << " " << saatIni->data << " "; 
            } else {
                cout << saatIni->data << " ";
            }
            pencacah++;
            if (pencacah == n){
                cout << endl;
                n = n * 2;
                pencacah = 0;
            }
            i++;
        }
    }
}

int main(){
    inisialisasi();
    simpulAkar();
    tambahSimpul();
    bacaPohon();
    return 0;
}
```

**Code 1**
```C++
#include<iostream>
#include<iomanip> 
using namespace std;
```
kode diatas digunakan untuk mendefinisikan header file iostream yang berisi definisi objek input dan output standar seperti cin, dan cout. 
include <iomanip digunakan untuk menyertakan pustaka untuk memanipulasi input-output seperti pengaturan lebar dan format output.
Menggunakan namespace std agar kita bisa menggunakan objek dan fungsi dari std

**Code 2**
```C++
struct pohon {
    pohon * kanan;
    char data;
    pohon * kiri;
};

pohon * simpul;
pohon * root;
pohon * saatIni;
pohon * helperA;
pohon * helperB;
pohon * alamat[256];
```
mendeklarasikan struktur pohon dan variabel global. struktur pohon yang memiliki pointer kanan dan kiri serta data bertipe char.
Beberapa variabel global bertipe pohon* digunakan untuk menyimpan simpul-simpul dan membantu operasi pada pohon.
pohon *alamat[256]: Array untuk menyimpan alamat simpul-simpul pada pohon.

**Code 3**
```C++
void inisialisasi(){
    root = NULL;
    saatIni = NULL;
    helperA = NULL;
    helperB = NULL;
}
```
Fungsi inisalisasi digunakan untuk Menginisialisasi variabel-variabel global dengan NULL untuk menunjukkan bahwa pohon awalnya kosong.

**Code 4**
```C++
void simpulBaru(char dataMasukkan){
    simpul = new pohon;
    simpul->data = dataMasukkan;
    simpul->kanan = NULL;
    simpul->kiri = NULL;
}
```
kode diatas merupakan fungsi yang digunakan untuk Membuat simpul baru dengan data yang diberikan dan mengatur anak kiri dan kanannya menjadi NULL.

**Code 5**
```C++
void simpulAkar(){
    if (root == NULL) {
        char dataAnda;
        cout << "Masukkan data akar: ";
        cin >> dataAnda;
        simpulBaru(dataAnda);
        root = simpul;
        cout << "Simpul akar berhasil dibuat...\n";
    } else {
        cout << "Simpul akar sudah ada...\n";
    }
}
```
kode diatas merupakan fungsi yang digunakan untuk Membuat simpul akar jika pohon belum memiliki akar. Meminta pengguna untuk memasukkan data untuk akar dan membuat simpul akar tersebut.

**Code 6**
```C++
void tambahSimpul() {
    if (root != NULL) {
        int i = 1, j = 1, penanda = 0;
        char dataUser;
        alamat[i] = root;

        while (penanda == 0 && j < 25) {
            cout << "Masukkan data kiri : ";
            cin >> dataUser;
            if (dataUser != '0') {
                simpulBaru(dataUser);
                saatIni = alamat[i];
                saatIni->kiri = simpul;
                j++;
                alamat[j] = simpul;
            } else {
                penanda = 1;
                j++;
                alamat[j] = NULL;
            }
            if (penanda == 0) {
                cout << "Masukkan data kanan : ";
                cin >> dataUser;
                if (dataUser != '0') {
                    simpulBaru(dataUser);
                    saatIni = alamat[i];
                    saatIni->kanan = simpul;
                    j++;
                    alamat[j] = simpul;
                } else {
                    penanda = 1;
                    j++;
                    alamat[j] = NULL;
                }
            }
            i++;
        }
    }
}
```
kode diatas merupakan fungsi yang digunakan untuk Menambah simpul-simpul baru ke dalam pohon. Simpul ditambah dari kiri ke kanan. Jika pengguna memasukkan 0, penambahan simpul dihentikan.

**Code 7**
```C++
void bacaPohon(){
    if (root != NULL) {
        int i = 1, n = 1, pencacah = 0;
        cout << endl;
        while (alamat[i] != NULL){
            saatIni = alamat[i];
            if (saatIni->data < 10) {
                cout << " " << saatIni->data << " "; 
            } else {
                cout << saatIni->data << " ";
            }
            pencacah++;
            if (pencacah == n){
                cout << endl;
                n = n * 2;
                pencacah = 0;
            }
            i++;
        }
    }
}
```
kode diatas merupakan fungsi yang digunakan untuk Menampilkan data dari pohon dengan format tertentu. Menampilkan data setiap level pada baris yang berbeda.

**Code 8**
```C++
int main(){
    inisialisasi();
    simpulAkar();
    tambahSimpul();
    bacaPohon();
    return 0;
}
```
int main() merupakan Fungsi utama yang merupakan titik awal eksekusi program. Memanggil fungsi inisialisasi, simpulAkar, tambahSimpul, dan bacaPohon untuk membentuk dan menampilkan pohon.

#### Output
```C++
Masukkan data akar: 2
Simpul akar berhasil dibuat...
Masukkan data kiri : 5
Masukkan data kanan : 6
Masukkan data kiri : 3
Masukkan data kanan : 4
Masukkan data kiri : 2
Masukkan data kanan : 1
Masukkan data kiri : 7
Masukkan data kanan : 8
Masukkan data kiri : 9
Masukkan data kanan : 2
Masukkan data kiri : 4
Masukkan data kanan : 5
Masukkan data kiri : 7
Masukkan data kanan : 3
Masukkan data kiri : 1
Masukkan data kanan : 9
Masukkan data kiri : 6
Masukkan data kanan : 4
Masukkan data kiri : 2
Masukkan data kanan : 1
Masukkan data kiri : 5
Masukkan data kanan : 6
Masukkan data kiri : 7
Masukkan data kanan : 3

2
5 6
3 4 2 1
7 8 9 2 4 5 7 3
1 9 6 4 2 1 5 6 7 3
```
menampilkan tree.

#### Full Code Screenshoot
![alt text](https://github.com/MikhaelSetiaBudi/Praktikum-Algoritma-Struktur-Data-Modul-10-Graph-dan-Tree/blob/master/Modul%2010%20Alstrukdat/Code%20Guided%202%20Graph%20dan%20Tree.png?raw=true)

#### Output Screenshot
![alt text](https://github.com/MikhaelSetiaBudi/Praktikum-Algoritma-Struktur-Data-Modul-10-Graph-dan-Tree/blob/master/Output%20Modul%2010%20Alstrukdat/Output%20Guided%202%20Graph%20dan%20Tree.png?raw=true)

## Unguided 

### 1. Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.

```C++
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> kota; 
vector<vector<int>> busur;
unordered_map<string, int> kotaIndex;

void isiKota(int jumlahSimpul) { 
    string namaKota;
    cout << "Masukkan nama-nama kota:" << endl;
    for (int i = 0; i < jumlahSimpul; i++) {
        cout << "Nama kota " << i + 1 << ": ";
        cin >> namaKota;
        kota.push_back(namaKota);
        kotaIndex[namaKota] = i; 
    }
    busur.resize(jumlahSimpul, vector<int>(jumlahSimpul, 0));
}

void isiJarak() {
    int jarak;
    cout << "Masukkan jarak antar kota (0 jika tidak ada jalur langsung):" << endl;
    for (size_t i = 0; i < kota.size(); i++) { 
        for (size_t j = 0; j < kota.size(); j++) {
            if (i != j) {
                cout << "Jarak dari " << kota[i] << " ke " << kota[j] << ": ";
                cin >> jarak;
                busur[i][j] = jarak;
            }
        }
    }
}

void tampilGraph() {
    cout << "Kota Asal | ";
    for (const auto& kota : kota) {  
        cout << kota << " | ";
    }
    cout << endl;

    for (size_t i = 0; i < kota.size(); i++) { 
        cout << kota[i] << " | "; 
        for (size_t j = 0; j < kota.size(); j++) {
            cout << busur[i][j] << " | ";
        }
        cout << endl;
    }
}

int hitungJarak(const vector<string>& perjalanan) {
    int totalJarak = 0;
    for (size_t i = 0; i < perjalanan.size() - 1; i++) {
        int asal = kotaIndex[perjalanan[i]];
        int tujuan = kotaIndex[perjalanan[i + 1]];
        totalJarak += busur[asal][tujuan];
    }
    return totalJarak;
}

int main() {
    int jumlahSimpul;
    cout << "Masukkan jumlah kota: ";
    cin >> jumlahSimpul;

    isiKota(jumlahSimpul); 
    isiJarak();
    tampilGraph();

    int jumlahPerjalanan;
    cout << "Masukkan jumlah kota dalam perjalanan: ";
    cin >> jumlahPerjalanan;
    vector<string> perjalanan(jumlahPerjalanan);
    cout << "Masukkan nama-nama kota dalam perjalanan:" << endl;
    for (int i = 0; i < jumlahPerjalanan; i++) {
        cout << "Kota " << i + 1 << ": ";
        cin >> perjalanan[i];
    }

    int jarakTotal = hitungJarak(perjalanan);
    cout << "Jarak total perjalanan: ";
    for (const auto& kota : perjalanan) {
        cout << kota << " ";
    }
    cout << "adalah " << jarakTotal << " km" << endl;
    return 0;
}


// Mikhael Setia Budi
// 2311110033
// copyright@MikhaelS.B
```

**Code 1**
```C++
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
```
menyertakan pustaka standar yang diperlukan dan menggunakan namespace std.

**Code 2**
```C++
vector<string> kota; 
vector<vector<int>> busur;
unordered_map<string, int> kotaIndex;
```
mendeklarasikan variabel global untuk menyimpan daftar nama kota. variabel matriks digunakan untuk menyimpan jarak antara kota.
unordered_map digunakan untuk menyimpan indeks setiap kota berdasarkan nama kota

**Code 3**
```C++
void isiKota(int jumlahSimpul) { 
    string namaKota;
    cout << "Masukkan nama-nama kota:" << endl;
    for (int i = 0; i < jumlahSimpul; i++) {
        cout << "Nama kota " << i + 1 << ": ";
        cin >> namaKota;
        kota.push_back(namaKota);
        kotaIndex[namaKota] = i; 
    }
    busur.resize(jumlahSimpul, vector<int>(jumlahSimpul, 0));
}
```
Meminta pengguna untuk memasukkan nama kota dan menyimpan dalam vektor kota. Setiap nama kota diberikan indeks yang disimpan dalam kotaIndex.
Mengatur ukuran matriks busur sesuai jumlah kota dan menginisialisasi dengan 0.

**Code 4**
```C++
void isiJarak() {
    int jarak;
    cout << "Masukkan jarak antar kota (0 jika tidak ada jalur langsung):" << endl;
    for (size_t i = 0; i < kota.size(); i++) { 
        for (size_t j = 0; j < kota.size(); j++) {
            if (i != j) {
                cout << "Jarak dari " << kota[i] << " ke " << kota[j] << ": ";
                cin >> jarak;
                busur[i][j] = jarak;
            }
        }
    }
}
```
Meminta pengguna untuk memasukkan jarak antara setiap pasangan kota. Jarak antara kota yang sama tidak diminta (dianggap 0).
Matriks busur diisi dengan jarak yang diberikan.

**Code 5**
```C++
void tampilGraph() {
    cout << "Kota Asal | ";
    for (const auto& kota : kota) {  
        cout << kota << " | ";
    }
    cout << endl;

    for (size_t i = 0; i < kota.size(); i++) { 
        cout << kota[i] << " | "; 
        for (size_t j = 0; j < kota.size(); j++) {
            cout << busur[i][j] << " | ";
        }
        cout << endl;
    }
}
```
Menampilkan tabel jarak antar kota. Header tabel berisi nama-nama kota.
Setiap baris menunjukkan jarak dari kota asal ke setiap kota tujuan.

**Code 6**
```C++
int hitungJarak(const vector<string>& perjalanan) {
    int totalJarak = 0;
    for (size_t i = 0; i < perjalanan.size() - 1; i++) {
        int asal = kotaIndex[perjalanan[i]];
        int tujuan = kotaIndex[perjalanan[i + 1]];
        totalJarak += busur[asal][tujuan];
    }
    return totalJarak;
}
```
Menghitung total jarak untuk perjalanan yang diberikan. Menggunakan peta kotaIndex untuk mendapatkan indeks kota dalam matriks busur.
Menjumlahkan jarak antar kota dalam perjalanan.

**Code 7**
```C++
int main() {
    int jumlahSimpul;
    cout << "Masukkan jumlah kota: ";
    cin >> jumlahSimpul;

    isiKota(jumlahSimpul); 
    isiJarak();
    tampilGraph();

    int jumlahPerjalanan;
    cout << "Masukkan jumlah kota dalam perjalanan: ";
    cin >> jumlahPerjalanan;
    vector<string> perjalanan(jumlahPerjalanan);
    cout << "Masukkan nama-nama kota dalam perjalanan:" << endl;
    for (int i = 0; i < jumlahPerjalanan; i++) {
        cout << "Kota " << i + 1 << ": ";
        cin >> perjalanan[i];
    }

    int jarakTotal = hitungJarak(perjalanan);
    cout << "Jarak total perjalanan: ";
    for (const auto& kota : perjalanan) {
        cout << kota << " ";
    }
    cout << "adalah " << jarakTotal << " km" << endl;
    return 0;
}
```
Meminta input jumlah kota dan memanggil isiKota untuk mengisi nama kota.Memanggil isiJarak untuk mengisi jarak antar kota.
Memanggil tampilGraph untuk menampilkan graf.Meminta input jumlah kota dalam perjalanan dan nama-nama kota dalam perjalanan.
Memanggil hitungJarak untuk menghitung jarak total perjalanan.Menampilkan hasil jarak total perjalanan.

#### Output:
```C++
Masukkan jumlah kota: 3
Masukkan nama-nama kota:
Nama kota 1: Banyumas
Nama kota 2: Sokaraja
Nama kota 3: Purwokerto
Masukkan jarak antar kota (0 jika tidak ada jalur langsung):
Jarak dari Banyumas ke Sokaraja: 2
Jarak dari Banyumas ke Purwokerto: 3
Jarak dari Sokaraja ke Banyumas: 2
Jarak dari Sokaraja ke Purwokerto: 1
Jarak dari Purwokerto ke Banyumas: 3
Jarak dari Purwokerto ke Sokaraja: 1
Kota Asal | Banyumas | Sokaraja | Purwokerto |
Banyumas | 0 | 2 | 3 |
Sokaraja | 2 | 0 | 1 |
Purwokerto | 3 | 1 | 0 |
Masukkan jumlah kota dalam perjalanan: 3
Masukkan nama-nama kota dalam perjalanan:
Kota 1: Banyumas
Kota 2: Sokaraja
Kota 3: Purwokerto
Jarak total perjalanan: Banyumas Sokaraja Purwokerto adalah 3 km
```
Menampilkan graph dengan 3 kota yaitu Banyumas, Sokaraja, dan Purwokerto.

#### Full code Screenshot:
![alt text](https://github.com/MikhaelSetiaBudi/Praktikum-Algoritma-Struktur-Data-Modul-10-Graph-dan-Tree/blob/master/Modul%2010%20Alstrukdat/Code%20Unguided%201%20Graph%20dan%20Tree.png?raw=true)

#### Output Screenshot
![alt text](https://github.com/MikhaelSetiaBudi/Praktikum-Algoritma-Struktur-Data-Modul-10-Graph-dan-Tree/blob/master/Output%20Modul%2010%20Alstrukdat/Output%20Unguided%201%20Graph%20dan%20Tree.png?raw=true)

### 2. Buatlah versi program Rekursif Tidak Langsung (Indirect Recursion) dari soal nomor 1 di atas!

```C++
#include<iostream>
#include<iomanip> 
using namespace std;

struct pohon {
    pohon * kanan;
    char data;
    pohon * kiri;
};

pohon * simpul;
pohon * root;
pohon * saatIni;
pohon * helperA;
pohon * helperB;
pohon * alamat[256];

void inisialisasi(){
    root = NULL;
    saatIni = NULL;
    helperA = NULL;
    helperB = NULL;
}

void simpulBaru(char dataMasukkan){
    simpul = new pohon;
    simpul->data = dataMasukkan;
    simpul->kanan = NULL;
    simpul->kiri = NULL;
}

void simpulAkar(){
    if (root == NULL) {
        char dataAnda;
        cout << "Masukkan data akar: ";
        cin >> dataAnda;
        simpulBaru(dataAnda);
        root = simpul;
        cout << "Simpul akar berhasil dibuat...\n";
    } else {
        cout << "Simpul akar sudah ada...\n";
    }
}

void tambahSimpul() {
    if (root != NULL) {
        int i = 1, j = 1, penanda = 0;
        char dataUser;
        alamat[i] = root;

        while (penanda == 0 && j < 25) {
            cout << "Masukkan data kiri : ";
            cin >> dataUser;
            if (dataUser != '0') {
                simpulBaru(dataUser);
                saatIni = alamat[i];
                saatIni->kiri = simpul;
                j++;
                alamat[j] = simpul;
            } else {
                penanda = 1;
                j++;
                alamat[j] = NULL;
            }
            if (penanda == 0) {
                cout << "Masukkan data kanan : ";
                cin >> dataUser;
                if (dataUser != '0') {
                    simpulBaru(dataUser);
                    saatIni = alamat[i];
                    saatIni->kanan = simpul;
                    j++;
                    alamat[j] = simpul;
                } else {
                    penanda = 1;
                    j++;
                    alamat[j] = NULL;
                }
            }
            i++;
        }
    }
}

void preOrder(pohon *node) {
    if (node != NULL) {
        cout << node->data << " ";
        preOrder(node->kiri);
        preOrder(node->kanan);
    }
}

void inOrder(pohon *node) {
    if (node != NULL) {
        inOrder(node->kiri);
        cout << node->data << " ";
        inOrder(node->kanan);
    }
}

void postOrder(pohon *node) {
    if (node != NULL) {
        postOrder(node->kiri);
        postOrder(node->kanan);
        cout << node->data << " ";
    }
}

void tampilPohon() {
    cout << "Pre-order: ";
    preOrder(root);
    cout << endl;
    cout << "In-order: ";
    inOrder(root);
    cout << endl;
    cout << "Post-order: ";
    postOrder(root);
    cout << endl;
}

int main(){
    inisialisasi();
    simpulAkar();
    tambahSimpul();
    tampilPohon();
    return 0;
}


// Mikhael Setia Budi
// 2311110033
// copyright@MikhaelS.B
```

**Code 1**
```C++
#include<iostream>
#include<iomanip> 
using namespace std;
```
kode diatas digunakan untuk mendefinisikan header file iostream yang berisi definisi objek input dan output standar seperti cin, dan cout. 
include <iomanip digunakan untuk menyertakan pustaka untuk memanipulasi input-output seperti pengaturan lebar dan format output.
Menggunakan namespace std agar kita bisa menggunakan objek dan fungsi dari std

**Code 2**
```C++
struct pohon {
    pohon * kanan;
    char data;
    pohon * kiri;
};
```
Struktur pohon mendefinisikan sebuah node pada pohon biner yang memiliki pointer ke anak kanan (kanan), menyimpan data (data), dan pointer ke anak kiri (kiri).

**Code 3**
```C++
pohon * simpul;
pohon * root;
pohon * saatIni;
pohon * helperA;
pohon * helperB;
pohon * alamat[256];
```
simpul merupakan pointer untuk node baru yang akan dibuat. root merupakan pointer untuk node akar pohon.
saatIni merupakan pointer untuk node saat ini dalam berbagai operasi. helperA, helperB merupakan pointer tambahan untuk membantu dalam berbagai operasi.
alamat[256] merupakan array untuk menyimpan pointer ke node dalam pohon.

**Code 4**
```C++
void inisialisasi(){
    root = NULL;
    saatIni = NULL;
    helperA = NULL;
    helperB = NULL;
}
```
Menginisialisasi semua pointer ke NULL untuk memastikan tidak ada data sampah di dalam pointer tersebut.

**Code 5**
```C++
void simpulBaru(char dataMasukkan){
    simpul = new pohon;
    simpul->data = dataMasukkan;
    simpul->kanan = NULL;
    simpul->kiri = NULL;
}
```
fungsi simpulBaru digunakan untuk membuat simpul baru dengan data yang dimasukkan oleh pengguna dan menginisialisasi anak kiri dan kanan ke NULL.

**Code 6**
```C++
void simpulAkar(){
    if (root == NULL) {
        char dataAnda;
        cout << "Masukkan data akar: ";
        cin >> dataAnda;
        simpulBaru(dataAnda);
        root = simpul;
        cout << "Simpul akar berhasil dibuat...\n";
    } else {
        cout << "Simpul akar sudah ada...\n";
    }
}
```
Jika pohon masih kosong (akar belum dibuat) maka fungsi akan meminta pengguna untuk memasukkan data akar, membuat simpul baru dengan data tersebut, dan menetapkannya sebagai akar.

**Code 7**
```C++
void tambahSimpul() {
    if (root != NULL) {
        int i = 1, j = 1, penanda = 0;
        char dataUser;
        alamat[i] = root;

        while (penanda == 0 && j < 25) {
            cout << "Masukkan data kiri : ";
            cin >> dataUser;
            if (dataUser != '0') {
                simpulBaru(dataUser);
                saatIni = alamat[i];
                saatIni->kiri = simpul;
                j++;
                alamat[j] = simpul;
            } else {
                penanda = 1;
                j++;
                alamat[j] = NULL;
            }
            if (penanda == 0) {
                cout << "Masukkan data kanan : ";
                cin >> dataUser;
                if (dataUser != '0') {
                    simpulBaru(dataUser);
                    saatIni = alamat[i];
                    saatIni->kanan = simpul;
                    j++;
                    alamat[j] = simpul;
                } else {
                    penanda = 1;
                    j++;
                    alamat[j] = NULL;
                }
            }
            i++;
        }
    }
}
```
Fungsi tambahSimpul digunakan untuk menambahkan simpul ke dalam pohon. Menggunakan array alamat untuk menyimpan node saat ini dan memandu pengguna untuk menambahkan anak kiri dan kanan.
Jika pengguna memasukkan '0', itu berarti tidak ada anak untuk posisi tersebut.

**Code 8**
```C++
void preOrder(pohon *node) {
    if (node != NULL) {
        cout << node->data << " ";
        preOrder(node->kiri);
        preOrder(node->kanan);
    }
}

void inOrder(pohon *node) {
    if (node != NULL) {
        inOrder(node->kiri);
        cout << node->data << " ";
        inOrder(node->kanan);
    }
}

void postOrder(pohon *node) {
    if (node != NULL) {
        postOrder(node->kiri);
        postOrder(node->kanan);
        cout << node->data << " ";
    }
}
```
preOrder, inOrder, dan postOrder adalah fungsi rekursif untuk melakukan traversal pre-order, in-order, dan post-order pada pohon.

**Code 9**
```C++
void tampilPohon() {
    cout << "Pre-order: ";
    preOrder(root);
    cout << endl;
    cout << "In-order: ";
    inOrder(root);
    cout << endl;
    cout << "Post-order: ";
    postOrder(root);
    cout << endl;
}
```
Fungsi

#### Output:
```C++
Masukkan data akar: 2
Simpul akar berhasil dibuat...
Masukkan data kiri : 1
Masukkan data kanan : 3
Masukkan data kiri : 4
Masukkan data kanan : 5
Masukkan data kiri : 2
Masukkan data kanan : 6
Masukkan data kiri : 7
Masukkan data kanan : 3
Masukkan data kiri : 5
Masukkan data kanan : 2
Masukkan data kiri : 9
Masukkan data kanan : 1
Masukkan data kiri : 4
Masukkan data kanan : 5
Masukkan data kiri : 3
Masukkan data kanan : 2
Masukkan data kiri : 6
Masukkan data kanan : 4
Masukkan data kiri : 7
Masukkan data kanan : 2
Masukkan data kiri : 9
Masukkan data kanan : 1
Masukkan data kiri : 5
Masukkan data kanan : 6
Pre-order: 2 1 4 7 3 2 3 6 4 5 5 7 2 2 9 1 3 2 9 5 6 1 6 4 5
In-order: 3 7 2 4 6 3 4 1 7 5 2 5 9 2 1 2 5 9 6 2 1 3 4 6 5
Post-order: 3 2 7 6 4 3 4 7 2 5 9 1 2 5 1 5 6 9 1 2 4 5 6 3 2
```
menampilakan hasil faktorial dari bilangan bulat positif 6 dengan rekursif tidak langsung

#### Full code Screenshot:
![alt text](https://github.com/MikhaelSetiaBudi/Praktikum-Algoritma-Struktur-Data-Modul-10-Graph-dan-Tree/blob/master/Modul%2010%20Alstrukdat/Code%20Unguided%202%20Graph%20dan%20Tree.png?raw=true)

#### Output Screenshot
![alt text](https://github.com/MikhaelSetiaBudi/Praktikum-Algoritma-Struktur-Data-Modul-10-Graph-dan-Tree/blob/master/Output%20Modul%2010%20Alstrukdat/Output%20Unguided%202%20Graph%20dan%20Tree.png?raw=true)

## Kesimpulan
Rekursif merupakan salah satu proses pengulangan fungsi atau prosedur yang memanggil dirinya sendiri. Kode rekursif cenderung lebih singkat dan lebih mudah dibuat dibandingkan dengan kode iteratif. Biasanya, perulangan dapat diubah menjadi fungsi rekursif saat proses kompilasi atau interpretasi. Hash table biasanya terdiri dari dua komponen utama: array (atau vektor) dan fungsi hash. Hashing adalah teknik untuk mengubah rentang nilai kunci menjadi rentang indeks array. Sistem hash table bekerja dengan cara mengambil input kunci dan memetakkannya ke nilai indeks array menggunakan fungsi hash. Kemudian, data disimpan pada posisi indeks array yang dihasilkan oleh fungsi hash.


## Referensi
[1]	I. F. Putra, M. Syafwan, M. R. Helmi, and A. Nazra, “Bentuk Eksplisit Rumus Beda Maju Dan Beda Mundur Untuk Turunan Ke-N Dengan Orde Ketelitian Ke-N Berdasarkan Deret Taylor,” J. Lebesgue  J. Ilm. Pendidik. Mat. Mat. dan Stat., vol. 4, no. 3, pp. 1675–1686, 2023, doi: 10.46306/lb.v4i3.461.
