#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Fungsi untuk menemukan determinan matriks 2x2
int determinant(int key[2][2]) {
    return (key[0][0] * key[1][1] - key[0][1] * key[1][0]);
}

// Fungsi untuk mencari invers dari determinan modulo 26
int modInverse(int det, int mod) {
    det = det % mod;
    for (int x = 1; x < mod; x++) {
        if ((det * x) % mod == 1)
            return x;
    }
    return -1;
}

// Fungsi untuk mencari invers dari kunci matriks
void inverseKey(int key[2][2], int inverseKey[2][2]) {
    int det = determinant(key);
    int detInverse = modInverse(det, 26);

    if (detInverse == -1) {
        cout << "Tidak ada invers untuk kunci matriks ini." << endl;
        return;
    }

    // Menghitung invers matriks
    inverseKey[0][0] = (key[1][1] * detInverse) % 26;
    inverseKey[1][1] = (key[0][0] * detInverse) % 26;
    inverseKey[0][1] = (-key[0][1] * detInverse) % 26;
    inverseKey[1][0] = (-key[1][0] * detInverse) % 26;

    // Menghindari nilai negatif
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (inverseKey[i][j] < 0)
                inverseKey[i][j] += 26;
        }
    }
}

// Fungsi untuk melakukan enkripsi
string encrypt(string message, int key[2][2]) {
    string cipherText = "";
    int vector[2];
    for (int i = 0; i < message.length(); i += 2) {
        vector[0] = message[i] - 'A';
        vector[1] = message[i + 1] - 'A';

        cipherText += char((key[0][0] * vector[0] + key[0][1] * vector[1]) % 26 + 'A');
        cipherText += char((key[1][0] * vector[0] + key[1][1] * vector[1]) % 26 + 'A');
    }
    return cipherText;
}

// Fungsi untuk melakukan dekripsi
string decrypt(string cipherText, int key[2][2]) {
    string plainText = "";
    int inverseKeyMatrix[2][2];
    inverseKey(key, inverseKeyMatrix);

    int vector[2];
    for (int i = 0; i < cipherText.length(); i += 2) {
        vector[0] = cipherText[i] - 'A';
        vector[1] = cipherText[i + 1] - 'A';

        plainText += char((inverseKeyMatrix[0][0] * vector[0] + inverseKeyMatrix[0][1] * vector[1]) % 26 + 'A');
        plainText += char((inverseKeyMatrix[1][0] * vector[0] + inverseKeyMatrix[1][1] * vector[1]) % 26 + 'A');
    }
    return plainText;
}

int main() {
    int key[2][2];
    int choice;
    string message;

    cout << "Program Hill Cipher" << endl;
    cout << "1. Enkripsi\n2. Dekripsi\n3. Cari Invers Kunci\n";
    cout << "Pilih menu: ";
    cin >> choice;

    cout << "Masukkan kunci (2x2 matriks): " << endl;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            cin >> key[i][j];

    switch (choice) {
        case 1:
            cout << "Masukkan pesan (huruf besar, jumlah karakter genap): ";
            cin >> message;
            cout << "Teks terenkripsi: " << encrypt(message, key) << endl;
            break;
        case 2:
            cout << "Masukkan teks terenkripsi (huruf besar, jumlah karakter genap): ";
            cin >> message;
            cout << "Teks terdekripsi: " << decrypt(message, key) << endl;
            break;
        case 3: {
            int inverseKeyMatrix[2][2];
            inverseKey(key, inverseKeyMatrix);
            cout << "Invers kunci adalah: " << endl;
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    cout << inverseKeyMatrix[i][j] << " ";
                }
                cout << endl;
            }
            break;
        }
        default:
            cout << "Pilihan tidak valid." << endl;
            break;
    }

    return 0;
}
