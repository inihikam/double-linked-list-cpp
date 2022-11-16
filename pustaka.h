#include <iostream>
#include <conio.h>

using namespace std;

//Deklarasi Double Linked List
struct mahasiswa{
    string nama;
    int nilai;
    mahasiswa *prev;
    mahasiswa *next;
};

mahasiswa *head, *tail;

bool isEmpty(){
    if (head == NULL && tail == NULL){
        return true;
    } else {
        return false;
    }
}

void insertFront(string data1, int data2){
    mahasiswa *baru;
    baru = new mahasiswa;
    baru->nama = data1;
    baru->nilai = data2;
    baru->prev = NULL;
    baru->next = NULL;
    if (head == NULL){
        head = baru;
        tail = baru;    
    } else {
        baru->next = head;
        head->prev = baru;
        head = baru;
    }
    cout << "\nData " << data1 << " " << data2 << " berhasil masuk!\n";
}

void insertMiddle(string data1, int data2){
    int pilih;
    mahasiswa *baru;
    mahasiswa *bantu;
    baru = new mahasiswa;
    baru->nama = data1;
    baru->nilai = data2;
    baru->prev = NULL;
    baru->next = NULL;

    system("cls");
    cout << "=================================";
    cout << "======= Pilih Mode Insert =======";
    cout << "= 1. Insert Before              =";
    cout << "= 2. Insert After               =";
    cout << "=================================";
    cout << "Pilih : ";cin>>pilih;
    switch (pilih){
        case 1: system("cls");{
            string before;
            bantu = head;
            bool find = false;
            if (head == NULL){
                head = baru;
                tail = baru;
                find = true;
                cout << "Data " << data1 << " " << data2 << " berhasil masuk!\n";
            } else {
                cout << "Masukkan sebelum data : ";
                cin >> before;
                do{
                    if (before == bantu->nama){
                        baru->prev = bantu->prev;
                        bantu->prev->next = baru;
                        bantu->prev = baru;
                        baru->next = bantu;
                        find = true;
                        cout << "\nData " << data1 << " " << data2 << " berhasil masuk!\n";
                    }
                    bantu = bantu->next;
                } while (bantu != NULL);
            }
            
            if (find == false){
                cout << "\nData yang dicari tidak ditemukan!\n";
            }

            break;
        }
        case 2: system("cls");{
            string after;
            bantu = head;
            bool find = false;
            if (head == NULL){
                head = baru;
                tail = baru;
                find = true;
                cout << "Data " << data1 << " " << data2 << " berhasil masuk!\n";
            } else {
                cout << "Masukkan setelah data : ";
                cin >> after;
                do{
                    if (after == bantu->nama){
                        baru->prev = bantu;
                        bantu->next->prev = baru;
                        baru->next = bantu->next;
                        bantu->next = baru;
                        find = true;
                        cout << "\nData " << data1 << " " << data2 << " berhasil masuk!\n";
                    }
                    bantu = bantu->next;
                } while (bantu != NULL);
            }
            
            if (find == false){
                cout << "Data yang dicari tidak ditemukan!\n";
            }

            break;
        }
        default: system("cls");{
            cout << "\nMaaf pilihan tidak ada!";
            break;
        }
    }
}

void insertEnd(string data1, int data2){
    mahasiswa *baru;
    baru = new mahasiswa;
    baru->nama = data1;
    baru->nilai = data2;
    baru->prev = NULL;
    baru->next = NULL;

    if (head == NULL){
        head = baru;
        tail = baru;
    } else {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }
    
    cout << "\nData " << data1 << " " << data2 << " berhasil masuk!\n";
}

void deleteFront(){
    mahasiswa *hapus;
    hapus = head;
    if (isEmpty() == true){
        system("cls");
        cout << "Maaf data kosong!\n";
    } else {
        system("cls");
        if (head == tail){
            head = NULL;
            tail = NULL;
            cout << "\nData " << hapus->nama << " " << hapus->nilai << " berhasil dihapus!\n";
            delete hapus;
        } else {
            head = head->next;
            head->prev = NULL;
            hapus->next = NULL;
            cout << "\nData " << hapus->nama << " " << hapus->nilai << " berhasil dihapus!\n";
            delete hapus;
        }
    }
}

void deleteMiddle(){
    string data1;
    mahasiswa *hapus;
    hapus = head;
    bool success = false;
    if (isEmpty() == true){
        system("cls");
        cout << "Maaf Data Kosong!\n";
    } else {
        system("cls");
        if (head == tail){
            head = NULL;
            tail = NULL;
            cout << "Data " << hapus->nama << " " << hapus->nilai << " berhasil dihapus!\n";
            success = true;
            delete hapus;
        } else {
            cout << "Masukkan data nama mahasiswa yang ingin dihapus : ";
            cin >> data1;
            do{
                if (data1 == hapus->nama){
                    hapus->prev->next = hapus->next;
                    hapus->next->prev = hapus->prev;
                    cout << "\nData " << hapus->nama << " " << hapus->nilai << " berhasil dihapus!\n";
                    success == true;
                    delete hapus;
                }
                hapus = hapus->next;
            } while (hapus != NULL);
        }
        
        if (success == false){
            cout << "\nMaaf Data tidak ditemukan!\n";
        }
    }
}

void deleteEnd(){
    mahasiswa *hapus;
    hapus = tail;
    if (isEmpty() == true){
        system("cls");
        cout << "Maaf data kosong!\n";
    } else {
        system("cls");
        if (head == tail){
            head = NULL;
            tail = NULL;
            cout << "Data " << hapus->nama << " " << hapus->nilai << " berhasil dihapus!\n";
            delete hapus;
        } else {
            tail = hapus->prev;
            tail->next = NULL;
            cout << "Data " << hapus->nama << " " << hapus->nilai << " berhasil dihapus!\n";
            delete hapus;
        }
    }
}

void searchData(){
    string cari;
    mahasiswa *list;
    list = head;
    bool find = false;
    if (isEmpty() == true){
        find = true;
        system("cls");
        cout << "Maaf data kosong!\n";
    } else {
        system("cls");
        cout << "Masukkan nama mahasiswa yang ingin dicari : ";
        cin >> cari;
        do{
            if (cari == list->nama){
                cout << "\nData " << list->nama << " " << list->nilai << " berhasil ditemukan!\n";
                find = true;
            }
            list = list->next;
        } while (list != NULL);
    }

    if (find == false){
        cout << "\nMaaf data tidak ditemukan\n";
    }
}

void showData(){
    mahasiswa *list;
    list = head;
    int i = 1;
    if (isEmpty() == true){
        system("cls");
        cout << "Maaf data kosong!\n";
    } else {
        system("cls");
        cout << "List Mahasiswa : \n";
        while (list != NULL){
            cout << i << ". " << list->nama << " " << list->nilai << "\n";
            i++;
            list = list->next;
        }
    }
}

void clearData(){
    mahasiswa *list;
    mahasiswa *hapus;
    list = head;
    do{
        hapus = list;
        list = list->next;
        delete hapus;
    } while (list != NULL);
    head = NULL;
    tail = NULL;
    system("cls");
    cout << "Data berhasil dibersihkan!\n";
}