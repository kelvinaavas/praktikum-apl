#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Album {
    string nama;
};

struct User {
    string username;
    string password;
    Album pesanan[10];
    int jumlahPesanan = 0;
};

const int MAKSIMUM_USER = 100;
const int MAKSIMUM_ALBUM = 10;
Album daftarAlbum[MAKSIMUM_ALBUM];
User daftarUser[MAKSIMUM_USER];
int totalAlbum = 5;
int totalUser = 0;

void tampilkanDaftarAlbum() {
    cout << "\nDaftar Album:\n";
    for (int i = 0; i < totalAlbum; i++) {
        cout << i + 1 << ". " << daftarAlbum[i].nama << endl;
    }
}

void tambahAlbum() {
    if (totalAlbum >= MAKSIMUM_ALBUM) {
        cout << "Kapasitas album penuh.\n";
        return;
    }
    cout << "Masukkan nama album: ";
    cin.ignore();
    getline(cin, daftarAlbum[totalAlbum].nama);
    totalAlbum++;
    cout << "Album berhasil ditambahkan!\n";
}

void hapusAlbum() {
    int indeks;
    cout << "Masukkan nomor album yang ingin dihapus: ";
    cin >> indeks;
    if (indeks >= 1 && indeks <= totalAlbum) {
        for (int i = indeks - 1; i < totalAlbum - 1; i++) {
            daftarAlbum[i] = daftarAlbum[i + 1];
        }
        totalAlbum--;
        cout << "Album berhasil dihapus!\n";
    } else {
        cout << "Nomor album tidak valid.\n";
    }
}

void lihatUserDanPesanannya() {
    cout << "\nUser yang Memesan Album:\n";
    for (int i = 0; i < totalUser; i++) {
        cout << "User: " << daftarUser[i].username << endl;
        for (int j = 0; j < daftarUser[i].jumlahPesanan; j++) {
            cout << " - " << daftarUser[i].pesanan[j].nama << endl;
        }
    }
}

void menuAdmin() {
    int pilihanAdmin;
    do {
        cout << "\nMenu Admin:\n";
        cout << "1. Tambah Album\n2. Hapus Album\n3. Lihat Daftar Album\n4. Lihat User yang Memesan Album\n5. Kembali\nPilihan: ";
        cin >> pilihanAdmin;

        switch (pilihanAdmin) {
            case 1: tambahAlbum(); break;
            case 2: hapusAlbum(); break;
            case 3: tampilkanDaftarAlbum(); break;
            case 4: lihatUserDanPesanannya(); break;
        }
    } while (pilihanAdmin != 5);
}

void pesanAlbum(User &user) {
    int indeks;
    cout << "Masukkan nomor album yang ingin dipesan: ";
    cin >> indeks;
    if (indeks >= 1 && indeks <= totalAlbum) {
        user.pesanan[user.jumlahPesanan] = daftarAlbum[indeks - 1];
        user.jumlahPesanan++;
        cout << "Album berhasil dipesan!\n";
    } else {
        cout << "Nomor album tidak valid.\n";
    }
}

void lihatPesanan(const User &user) {
    cout << "\nPesanan Anda:\n";
    for (int i = 0; i < user.jumlahPesanan; i++) {
        cout << i + 1 << ". " << user.pesanan[i].nama << endl;
    }
}

void hapusPesanan(User &user) {
    int indeks;
    cout << "Masukkan nomor pesanan yang ingin dihapus: ";
    cin >> indeks;
    if (indeks >= 1 && indeks <= user.jumlahPesanan) {
        for (int i = indeks - 1; i < user.jumlahPesanan - 1; i++) {
            user.pesanan[i] = user.pesanan[i + 1];
        }
        user.jumlahPesanan--;
        cout << "Pesanan berhasil dihapus!\n";
    } else {
        cout << "Nomor pesanan tidak valid.\n";
    }
}

void menuUser(User &user) {
    int pilihanUser;
    do {
        cout << "\nMenu User:\n";
        cout << "1. Lihat Album\n2. Pesan Album\n3. Lihat Pesanan\n4. Hapus Pesanan\n5. Kembali\nPilihan: ";
        cin >> pilihanUser;
        switch (pilihanUser) {
            case 1: tampilkanDaftarAlbum(); break;
            case 2: pesanAlbum(user); break;
            case 3: lihatPesanan(user); break;
            case 4: hapusPesanan(user); break;
        }
    } while (pilihanUser != 5);
}

void login(string username, string password) {
    if (username == "kelvin" && password == "2409106094") {
        cout << "Login sebagai admin berhasil!\n";
        menuAdmin();
    } else {
        bool loginBerhasil = false;
        for (int i = 0; i < totalUser; i++) {
            if (daftarUser[i].username == username && daftarUser[i].password == password) {
                loginBerhasil = true;
                cout << "Login sebagai user berhasil!\n";
                menuUser(daftarUser[i]);
                break;
            }
        }
        if (!loginBerhasil) {
            cout << "Login gagal. Username atau password salah.\n";
        }
    }
}

void buatAkun() {
    if (totalUser >= MAKSIMUM_USER) {
        cout << "Kapasitas user penuh.\n";
        return;
    }
    cout << "Masukkan username baru: ";
    cin >> daftarUser[totalUser].username;
    cout << "Masukkan password baru: ";
    cin >> daftarUser[totalUser].password;
    totalUser++;
    cout << "Akun berhasil dibuat! Silakan login.\n";
}

int main() {
    daftarAlbum[0] = {"Pink Venom - Blackpink"};
    daftarAlbum[1] = {"Rosie - Rose"};
    daftarAlbum[2] = {"Ruby - Jennie"};
    daftarAlbum[3] = {"Alter Ego - Lisa"};
    daftarAlbum[4] = {"Amortage - Jiso"};

    int pilihan;
    string username, password;

    do {
        cout << "\nMenu Utama:\n1. Login\n2. Buat Akun\n3. Keluar\nPilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan username: ";
                cin >> username;
                cout << "Masukkan password: ";
                cin >> password;
                login(username, password);
                break;
            case 2:
                buatAkun();
                break;
        }
    } while (pilihan != 3);

    return 0;
}
