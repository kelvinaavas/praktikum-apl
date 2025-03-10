#include <iostream>
#include <cmath>
using namespace std;

// Fungsi login
bool login() {
    string username, password;
    do {
        cout << "🔐 masukan 🔐\n";
        cout << "👮🏻‍♀️Username: ";
        getline(cin, username);
        
        cout << "🗝️ Password: ";
        getline(cin, password); // Memastikan password dibaca dengan getline

        if (username == "kelvin alviansyah" && password == "2409106094") {
            cout << "✅ Login berhasil!\n";
            return true;
        } else {
            cout << "❌ Login gagal! Silakan coba lagi.\n";
        }
    } while (true);
}
// Fungsi menghitung luas
double hitungLuas() {
    int pilihan;
    double sisi, panjang, lebar, jariJari, alas, tinggi;

    do {
        cout << "\n-- HITUNG LUAS --\n";
        cout << "1. Persegi\n";
        cout << "2. Persegi Panjang\n";
        cout << "3. Lingkaran\n";
        cout << "4. Segitiga\n";
        cout << "5. Kembali\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan sisi: ";
                cin >> sisi;
                return sisi * sisi;
            case 2:
                cout << "Masukkan panjang dan lebar: ";
                cin >> panjang >> lebar;
                return panjang * lebar;
            case 3:
                cout << "Masukkan jari-jari: ";
                cin >> jariJari;
                return 3.14 * jariJari * jariJari;
            case 4:
                cout << "Masukkan alas dan tinggi: ";
                cin >> alas >> tinggi;
                return 0.5 * alas * tinggi;
        }
    } while (pilihan != 5);
    return 0; // Kembali 0 jika tidak ada pilihan yang valid
}

// Fungsi menghitung keliling
double hitungKeliling() {
    int pilihan;
    double sisi, panjang, lebar, jariJari, sisi1, sisi2, sisi3;

    do {
        cout << "\n-- HITUNG KELILING --\n";
        cout << "1. Persegi\n";
        cout << "2. Persegi Panjang\n";
        cout << "3. Lingkaran\n";
        cout << "4. Segitiga\n";
        cout << "5. Kembali\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan sisi: ";
                cin >> sisi;
                return 4 * sisi;
            case 2:
                cout << "Masukkan panjang dan lebar: ";
                cin >> panjang >> lebar;
                return 2 * (panjang + lebar);
            case 3:
                cout << "Masukkan jari-jari: ";
                cin >> jariJari;
                return 2 * 3.14 * jariJari;
            case 4:
                cout << "Masukkan tiga sisi segitiga: ";
                cin >> sisi1 >> sisi2 >> sisi3;
                return sisi1 + sisi2 + sisi3;
        }
    } while (pilihan != 5);
    return 0; // Kembali 0 jika tidak ada pilihan yang valid
}

// Fungsi menghitung volume
double hitungVolume() {
    int pilihan;
    double sisi, panjang, lebar, tinggi, jariJari;

    do {
        cout << "\n-- HITUNG VOLUME --\n";
        cout << "1. Kubus\n";
        cout << "2. Balok\n";
        cout << "3. Bola\n";
        cout << "4. Kerucut\n";
        cout << "5. Kembali\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan sisi: ";
                cin >> sisi;
                return sisi * sisi * sisi;
            case 2:
                cout << "Masukkan panjang, lebar, dan tinggi: ";
                cin >> panjang >> lebar >> tinggi;
                return panjang * lebar * tinggi;
            case 3:
                cout << "Masukkan jari-jari: ";
                cin >> jariJari;
                return (4.0 / 3.0) * 3.14 * jariJari * jariJari * jariJari;
            case 4:
                cout << "Masukkan jari-jari dan tinggi: ";
                cin >> jariJari >> tinggi;
                return (1.0 / 3.0) * 3.14 * jariJari * jariJari * tinggi;
        }
    } while (pilihan != 5);
    return 0; // Kembali 0 jika tidak ada pilihan yang valid
}

// Fungsi utama program
int main() {
    login();
    int pilihan;

    do {
        cout << ".-----------------------------------------------------------------------.\n";
        cout << "|  SILAHKAN PILIH YA INGIN MENGHITUNG BANGUN DATAR DAN RUANG YANG MANA  |\n";
        cout << "| 1. Hitung luas                                                        |\n";
        cout << "| 2. Hitung keliling                                                    |\n";
        cout << "| 3. Hitung volume                                                      |\n";
        cout << "| 4. Logout                                                             |\n";
        cout << "|_______________________________________________________________________|\n";
        cout << "\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                double luas = hitungLuas();
                cout << "Hasil Luas: " << luas << endl;
                break;
            }
            case 2: {
                double keliling = hitungKeliling();
                cout << "Hasil Keliling: " << keliling << endl;
                break;
            }
            case 3: {
                double volume = hitungVolume();
                cout << "Hasil Volume: " << volume << endl;
                break;
            }
            case 4:
                cout << "Logout berhasil.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 4);

    return 0;
}
