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