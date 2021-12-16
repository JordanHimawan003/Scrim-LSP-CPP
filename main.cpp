#include <iostream>
#include <fstream>
using namespace std;

// validasi digit angka
bool validasi (int angka) {
    bool hasil = true;
    // cek digit angka
    if (angka > 9999) {
        cout << "ERROR! Angka harus maksimal 4 digit!";
        hasil = false;
    }
    return hasil;
}

// funsi untuk eja angka
string eja (int angka) {
    // validasi digit angka
    if(!validasi(angka)) {
        return "";
    }

    // array untuk menyimpan ejaan
    string ejaan [] = {"", "Satu", "Dua", "Tiga", "Empat", "Lima", "Enam", "Tujuh", "Delapan", "Sembilan"};



    // hasil ejaan
    // satuan
    if (angka < 10 && angka > 0) {
        return ejaan[angka];
    }

    // belasan
    if (angka == 11) {
        return "Sebelas";
    } else if (angka > 10 && angka < 20) {
        return ejaan[angka-10] + " Belas";
    }

    // puluhan
    if (angka == 10) {
        return "Sepuluh";
    } else if (angka > 19 && angka < 100) {
        return ejaan[angka / 10] + " Puluh" + ejaan[angka % 10];
    }

    // satu ratusan ( kurang dari dua ratus )
    if (angka >= 100 && angka < 200) {
        return "Seratus " + eja(angka % 100);
    }

    // ratusan
    if (angka > 199 && angka < 1000) {
        return eja(angka / 100) + " Ratus " + eja(angka % 100);
    }

    // satu ribuan
    if (angka >= 1000 && angka < 2000) {
        return "Seribu " + eja(angka % 1000);
    }

    // ribuan
    if (angka > 1999) {
        return eja(angka / 1000) + " Ribu " + eja(angka % 1000);
    }

     // negatif
    if(angka < 0) {
        return "Negatif " + eja(-angka);
    }

    return "";
}

int main()
{
    // program dimulai disini
    mulai:

        cout << "=====PROGRAM EJA ANGKAAA NGAB=====" << endl;
        cout << "=====CREATED BY JORDAN STEPHAN GATES=====" << endl << endl;

        // define variabel angka
        int angka;

        // masukkan angka disini
        cout << "Masukkan angka maksimal 4 digit : ";
        cin >> angka;
        cout << endl;

        // panggil fungsi pengeja
        cout << "Ejaan angka = " << angka << ", adalah = " << eja(angka);
        string output = eja(angka);
        cout << endl << endl;

        cout << "=====ENDL=====" << endl << endl;

        // tulis file eksternal
        string filename("tmp.txt");
        fstream fileout;
        fileout.open(filename, std::ios_base::out);
        if(!fileout.is_open()) {
            cout << "Gagal membuka " << filename;
        } else {
            fileout << "Ejaan angka = " << angka << ", adalah = " << output;
            cout << "Penulisan file sukses!";
        }


        char t;
        cout << "Apakah ingin mengeja lagi? (y/n) : ";
        cin >> t;

        if(t == 'y') {
            cout << endl << endl;
            goto mulai;
        } else if (t == 'n') {
            return 0;
        }


    return 0;
}
