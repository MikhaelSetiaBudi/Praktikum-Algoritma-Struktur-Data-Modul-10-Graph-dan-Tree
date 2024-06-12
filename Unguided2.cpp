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