#include <iostream>
#include <windows.h>
#include <conio.h>
#include <bitset> // Untuk konversi ke biner

using namespace std;

// Fungsi untuk mengubah warna teks di konsol
void chgcolor(unsigned short color) {
    HANDLE sCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(sCon, color);
}

// Fungsi untuk opsi Biodata
void Biodata() {
    system("cls");
    string nama, tempat, kuliah, kelas, hobi;
    chgcolor(14);
    cout << "=========== ISI BIODATA ============\n\n";
    chgcolor(15);
    cin.ignore();
    cout << "Nama Lengkap: ";
    getline(cin, nama);
    cout << "Tempat Lahir: ";
    getline(cin, tempat);
    cout << "Fakultas: ";
    getline(cin, kuliah);
    cout << "Prodi: ";
    getline(cin, kelas);
    cout << "Hobi: ";
    getline(cin, hobi);
    cout << endl;

    chgcolor(14);
    cout << "========== OUTPUT ==============\n\n";
    chgcolor(15);
    cout << "Nama Lengkap: " << nama << endl;
    cout << "Tempat Lahir: " << tempat << endl;
    cout << "Kuliah: " << kuliah << endl;
    cout << "Kelas: " << kelas << endl;
    cout << "Hobi: " << hobi << endl;
    cout << "\nTerima Kasih telah mengisi biodata\n";
    cin.get();
}

// Fungsi untuk menampilkan deret angka
void Deret() {
    system("cls");
    int n;
    cout << "======= PROGRAM DERET ========" << endl;
    cout << "Masukkan nilai: ";
    cin >> n;
    cin.ignore();
    cout << "\n======== OUTPUT ==========" << endl;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << "=========================" << endl;
    cin.get();
}

// Fungsi untuk animasi berjalan
void animasi() {
    string text = "Institut Teknologi Budi Utomo";
    char tombol;

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int lebar_layar = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    cout << "=== Animasi Tulisan Berjalan ===" << endl;
    cout << "Tekan tombol Enter untuk kembali ke menu utama.\n" << endl;

    while (true) {
        for (int i = 0; i <= lebar_layar; i++) {
            system("cls");
            for (int j = 0; j < i; j++) cout << " "; 
            cout << text << endl;
            Sleep(100); 

            if (_kbhit()) { 
                tombol = _getch(); 
                if (tombol == '\r') { 
                    return; 
                }
            }
        }
    }
}

// Fitur Nilai
void Nilai() {
    system("cls");
    int nilai;
    cout << "======= PROGRAM NILAI ========" << endl;
    cout << "Masukkan nilai Anda: ";
    cin >> nilai;
    cout << "\n======== HASIL ==========" << endl;
    if (nilai >= 70) {
        cout << "LULUS" << endl;
    } else {
        cout << "TIDAK LULUS" << endl;
    }
    cin.get(); cin.get();
}

// Fitur Luas Segitiga
void LuasSegitiga() {
    system("cls");
    float alas, tinggi;
    cout << "======= LUAS SEGITIGA ========" << endl;
    cout << "Masukkan panjang alas: ";
    cin >> alas;
    cout << "Masukkan tinggi: ";
    cin >> tinggi;
    cout << "\n======== HASIL ==========" << endl;
    cout << "Luas segitiga adalah: " << (0.5 * alas * tinggi) << endl;
    cin.get(); cin.get();
}

// Fitur Konversi Biner
void KonversiBiner() {
    system("cls");
    string input;
    cout << "======= KONVERSI BINER ========" << endl;
    cout << "Masukkan teks: ";
    cin.ignore();
    getline(cin, input);
    cout << "\n======== HASIL ==========" << endl;

    // Menggunakan loop biasa untuk kompatibilitas C++98
    for (size_t i = 0; i < input.length(); i++) {
        char c = input[i];
        cout << bitset<8>(c) << " ";
    }
    cout << endl;
    cin.get();
}

// Fungsi utama program
int main() {
    int pilihan;
    do {
        system("cls");
        cout << "=== MENU PROGRAM ===" << endl;
        cout << "1. Biodata" << endl;
        cout << "2. Deret Bilangan" << endl;
        cout << "3. Animasi Berjalan" << endl;
        cout << "4. Nilai" << endl;
        cout << "5. Luas Segitiga" << endl;
        cout << "6. Konversi Biner" << endl;
        cout << "7. Keluar" << endl;
        cout << "=====================" << endl;
        cout << "Pilih menu (1-7): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: Biodata(); break;
            case 2: Deret(); break;
            case 3: animasi(); break;
            case 4: Nilai(); break;
            case 5: LuasSegitiga(); break;
            case 6: KonversiBiner(); break;
            case 7: cout << "Keluar dari program. Terima kasih!" << endl; break;
            default: cout << "Pilihan tidak valid!" << endl; cin.get(); cin.get();
        }
    } while (pilihan != 7);

    return 0;
}

