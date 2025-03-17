#include <iostream>
#include <string>
using namespace std;

int main() {
    // Array untuk menyimpan album
    string albums[5] = {"Pink Venom - Blackpink", "Rosie - Rose", "Ruby - Jennie", "Alter Ego - Lisa", "Amortage - Jiso"};
    int jumlahAlbum = 5;

    // Array untuk menyimpan user dan password
    const int MAX_USERS = 100;
    string users[MAX_USERS][2]; // [username, password]
    int jumlahUser = 0;

    // Array untuk menyimpan pesanan user
    string pesanan[MAX_USERS][10]; // Setiap user bisa memiliki maksimal 10 pesanan

    int pilihan;
    string username, password;

    do {
        // Menu Utama
        cout << "\nMenu Utama:\n";
        cout << "1. Login\n";
        cout << "2. Buat Akun\n";
        cout << "3. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            // Login
            cout << "Masukkan username: ";
            cin >> username;
            cout << "Masukkan password: ";
            cin >> password;

            bool loginBerhasil = false;

            // Cek login admin
            if (username == "admin" && password == "admin") {
                loginBerhasil = true;
                cout << "Login sebagai admin berhasil!\n";

                // Menu Admin
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

                    if (pilihanAdmin == 1) {
                        // Tambah Album
                        if (jumlahAlbum >= 10) {
                            cout << "Maaf, kapasitas album penuh.\n";
                        } else {
                            string namaAlbum;
                            cout << "Masukkan nama album: ";
                            cin.ignore();
                            getline(cin, namaAlbum);
                            albums[jumlahAlbum] = namaAlbum;
                            jumlahAlbum++;
                            cout << "Album berhasil ditambahkan!\n";
                        }
                    } else if (pilihanAdmin == 2) {
                        // Hapus Album
                        int index;
                        cout << "Masukkan nomor album yang ingin dihapus: ";
                        cin >> index;
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
                        // Lihat Daftar Album
                        cout << "\nDaftar Album:\n";
                        for (int i = 0; i < jumlahAlbum; i++) {
                            cout << i + 1 << ". " << albums[i] << endl;
                        }
                    } else if (pilihanAdmin == 4) {
                        // Lihat User yang Memesan Album
                        cout << "\nUser yang Memesan Album:\n";
                        for (int i = 0; i < jumlahUser; i++) {
                            cout << "User: " << users[i][0] << endl;
                            for (int j = 0; j < 10; j++) {
                                if (!pesanan[i][j].empty()) {
                                    cout << " - " << pesanan[i][j] << endl;
                                }
                            }
                        }
                    } else if (pilihanAdmin == 5) {
                        // Kembali ke Menu Utama
                        cout << "Kembali ke menu utama.\n";
                    } else {
                        cout << "Pilihan tidak valid.\n";
                    }
                } while (pilihanAdmin != 5);
            } else {
                // Cek login user
                for (int i = 0; i < jumlahUser; i++) {
                    if (users[i][0] == username && users[i][1] == password) {
                        loginBerhasil = true;
                        cout << "Login sebagai user berhasil!\n";

                        // Menu User
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

                            if (pilihanUser == 1) {
                                // Lihat Album
                                cout << "\nDaftar Album:\n";
                                for (int i = 0; i < jumlahAlbum; i++) {
                                    cout << i + 1 << ". " << albums[i] << endl;
                                }
                            } else if (pilihanUser == 2) {
                                // Pesan Album
                                int index;
                                cout << "Masukkan nomor album yang ingin dipesan: ";
                                cin >> index;
                                if (index >= 1 && index <= jumlahAlbum) {
                                    for (int i = 0; i < jumlahUser; i++) {
                                        if (users[i][0] == username) {
                                            for (int j = 0; j < 10; j++) {
                                                if (pesanan[i][j].empty()) {
                                                    pesanan[i][j] = albums[index - 1];
                                                    cout << "Album berhasil dipesan!\n";
                                                    break;
                                                }
                                            }
                                            break;
                                        }
                                    }
                                } else {
                                    cout << "Nomor album tidak valid.\n";
                                }
                            } else if (pilihanUser == 3) {
                                // Lihat Pesanan
                                cout << "\nPesanan Anda:\n";
                                for (int i = 0; i < jumlahUser; i++) {
                                    if (users[i][0] == username) {
                                        for (int j = 0; j < 10; j++) {
                                            if (!pesanan[i][j].empty()) {
                                                cout << j + 1 << ". " << pesanan[i][j] << endl;
                                            }
                                        }
                                        break;
                                    }
                                }
                            } else if (pilihanUser == 4) {
                                // Hapus Pesanan
                                int index;
                                cout << "Masukkan nomor pesanan yang ingin dihapus: ";
                                cin >> index;
                                for (int i = 0; i < jumlahUser; i++) {
                                    if (users[i][0] == username) {
                                        if (index >= 1 && index <= 10 && !pesanan[i][index - 1].empty()) {
                                            pesanan[i][index - 1] = "";
                                            cout << "Pesanan berhasil dihapus!\n";
                                        } else {
                                            cout << "Nomor pesanan tidak valid.\n";
                                        }
                                        break;
                                    }
                                }
                            } else if (pilihanUser == 5) {
                                // Kembali ke Menu Utama
                                cout << "Kembali ke menu utama.\n";
                            } else {
                                cout << "Pilihan tidak valid.\n";
                            }
                        } while (pilihanUser != 5);
                        break;
                    }
                }
                if (!loginBerhasil) {
                    cout << "Login gagal. Username atau password salah.\n";
                }
            }
        } else if (pilihan == 2) {
            // Buat Akun
            if (jumlahUser >= MAX_USERS) {
                cout << "Maaf, kapasitas user penuh.\n";
            } else {
                string usernameBaru, passwordBaru;
                cout << "Masukkan username: ";
                cin >> usernameBaru;
                cout << "Masukkan password: ";
                cin >> passwordBaru;
                users[jumlahUser][0] = usernameBaru;
                users[jumlahUser][1] = passwordBaru;
                jumlahUser++;
                cout << "Akun berhasil dibuat!\n";
            }
        } else if (pilihan == 3) {
            // Keluar
            cout << "Keluar dari program.\n";
        } else {
            cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 3);

    return 0;
}
