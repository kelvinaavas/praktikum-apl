#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Struct untuk menyimpan data album
struct Album {
    string nama;
};

// Struct untuk menyimpan data user
struct User {
    string username;
    string password;
    Album pesanan[10]; // Maksimal 10 pesanan per user
    int jumlahPesanan = 0;
};

const int MAX_USERS = 100;
const int MAX_ALBUMS = 10;
Album albums[MAX_ALBUMS];
User users[MAX_USERS];
int jumlahAlbum = 5;
int jumlahUser = 0;

int main() {
    albums[0] = {"Pink Venom - Blackpink"};
    albums[1] = {"Rosie - Rose"};
    albums[2] = {"Ruby - Jennie"};
    albums[3] = {"Alter Ego - Lisa"};
    albums[4] = {"Amortage - Jiso"};

    int pilihan;
    string username, password;
    
    do {
        cout << "\nMenu Utama:\n";
        cout << "1. Login\n";
        cout << "2. Buat Akun\n";
        cout << "3. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid. Masukkan angka: ";
            cin >> pilihan;
        }

        if (pilihan == 1) {
            cout << "Masukkan username: ";
            cin >> username;
            cout << "Masukkan password: ";
            cin >> password;

            if (username == "kelvin" && password == "2409106094") {
                cout << "Login sebagai admin berhasil!\n";
                int pilihanAdmin;
                do {
                    cout << "\nMenu Admin:\n";
                    cout << "1. Tambah Album\n";
                    cout << "2. Hapus Album\n";
                    cout << "3. Lihat Daftar Album\n";
                    cout << "4. Lihat User yang Memesan Album\n";
                    cout << "5. Kembali\n";
                    cout << "Pilihan: ";
                    cin >> pilihanAdmin;
                    
                    while (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Input tidak valid. Masukkan angka: ";
                        cin >> pilihanAdmin;
                    }
                    
                    if (pilihanAdmin == 1) {
                        if (jumlahAlbum >= MAX_ALBUMS) {
                            cout << "Kapasitas album penuh.\n";
                        } else {
                            cout << "Masukkan nama album: ";
                            cin.ignore();
                            getline(cin, albums[jumlahAlbum].nama);
                            jumlahAlbum++;
                            cout << "Album berhasil ditambahkan!\n";
                        }
                    } else if (pilihanAdmin == 2) {
                        int index;
                        cout << "Masukkan nomor album yang ingin dihapus: ";
                        cin >> index;
                        
                        while (cin.fail()) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Input tidak valid. Masukkan angka: ";
                            cin >> index;
                        }
                        
                        if (index >= 1 && index <= jumlahAlbum) {
                            for (int i = index - 1; i < jumlahAlbum - 1; i++) {
                                albums[i] = albums[i + 1];
                            }
                            jumlahAlbum--;
                            cout << "Album berhasil dihapus!\n";
                        } else {
                            cout << "Nomor album tidak valid.\n";
                        }
                    } else if (pilihanAdmin == 3) {
                        cout << "\nDaftar Album:\n";
                        for (int i = 0; i < jumlahAlbum; i++) {
                            cout << i + 1 << ". " << albums[i].nama << endl;
                        }
                    } else if (pilihanAdmin == 4) {
                        cout << "\nUser yang Memesan Album:\n";
                        for (int i = 0; i < jumlahUser; i++) {
                            cout << "User: " << users[i].username << endl;
                            for (int j = 0; j < users[i].jumlahPesanan; j++) {
                                cout << " - " << users[i].pesanan[j].nama << endl;
                            }
                        }
                    }
                } while (pilihanAdmin != 5);
            } else {
                bool loginBerhasil = false;
                for (int i = 0; i < jumlahUser; i++) {
                    if (users[i].username == username && users[i].password == password) {
                        loginBerhasil = true;
                        cout << "Login sebagai user berhasil!\n";
                        int pilihanUser;
                        do {
                            cout << "\nMenu User:\n";
                            cout << "1. Lihat Album\n";
                            cout << "2. Pesan Album\n";
                            cout << "3. Lihat Pesanan\n";
                            cout << "4. Hapus Pesanan\n";
                            cout << "5. Kembali\n";
                            cout << "Pilihan: ";
                            cin >> pilihanUser;
                            
                            while (cin.fail()) {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "Input tidak valid. Masukkan angka: ";
                                cin >> pilihanUser;
                            }

                            if (pilihanUser == 1) {
                                cout << "\nDaftar Album:\n";
                                for (int j = 0; j < jumlahAlbum; j++) {
                                    cout << j + 1 << ". " << albums[j].nama << endl;
                                }
                            } else if (pilihanUser == 2) {
                                int index;
                                cout << "Masukkan nomor album yang ingin dipesan: ";
                                cin >> index;
                                if (index >= 1 && index <= jumlahAlbum) {
                                    users[i].pesanan[users[i].jumlahPesanan] = albums[index - 1];
                                    users[i].jumlahPesanan++;
                                    cout << "Album berhasil dipesan!\n";
                                } else {
                                    cout << "Nomor album tidak valid.\n";
                                }
                            } else if (pilihanUser == 3) {
                                cout << "\nPesanan Anda:\n";
                                for (int j = 0; j < users[i].jumlahPesanan; j++) {
                                    cout << j + 1 << ". " << users[i].pesanan[j].nama << endl;
                                }
                            } else if (pilihanUser == 4) {
                                int index;
                                cout << "Masukkan nomor pesanan yang ingin dihapus: ";
                                cin >> index;
                                if (index >= 1 && index <= users[i].jumlahPesanan) {
                                    for (int j = index - 1; j < users[i].jumlahPesanan - 1; j++) {
                                        users[i].pesanan[j] = users[i].pesanan[j + 1];
                                    }
                                    users[i].jumlahPesanan--;
                                    cout << "Pesanan berhasil dihapus!\n";
                                } else {
                                    cout << "Nomor pesanan tidak valid.\n";
                                }
                            }
                        } while (pilihanUser != 5);
                    }
                }
                if (!loginBerhasil) {
                    cout << "Login gagal. Username atau password salah.\n";
                }

            }
        } else if (pilihan == 2) {
            if (jumlahUser >= MAX_USERS) {
                cout << "Kapasitas user penuh.\n";
            } else {
                cout << "Masukkan username baru: ";
                cin >> users[jumlahUser].username;
                cout << "Masukkan password baru: ";
                cin >> users[jumlahUser].password;
                jumlahUser++;
                cout << "Akun berhasil dibuat! Silakan login.\n";
            }
        }
    } while (pilihan != 3);
    
    return 0;
}

