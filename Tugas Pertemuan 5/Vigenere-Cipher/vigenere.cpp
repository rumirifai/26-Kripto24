#include <iostream>
#include <string>

using namespace std;

// Fungsi untuk mengenkripsi teks menggunakan rumus (P_i + K_i) % 26
string encrypt(string text, string key)
{
    string result = "";
    int keyIndex = 0;

    // Proses tiap karakter dari teks
    for (int i = 0; i < text.length(); i++)
    {
        char letter = text[i];

        if (isalpha(letter))
        {
            char base = isupper(letter) ? 'A' : 'a'; // Tentukan basis huruf besar/kecil

            // Enkripsi menggunakan rumus (P_i + K_i) % 26
            result += ((letter - base) + (toupper(key[keyIndex]) - 'A')) % 26 + base;

            // Update indeks kunci
            keyIndex = (keyIndex + 1) % key.length();
        }
        else
        {
            result += letter; // Jika bukan huruf, tidak dienkripsi
        }
    }

    return result;
}

// Fungsi untuk mendekripsi teks menggunakan rumus (C_i - K_i + 26) % 26
string decrypt(string text, string key)
{
    string result = "";
    int keyIndex = 0;

    // Proses tiap karakter dari ciphertext
    for (int i = 0; i < text.length(); i++)
    {
        char letter = text[i];

        if (isalpha(letter))
        {
            char base = isupper(letter) ? 'A' : 'a'; // Tentukan basis huruf besar/kecil

            // Dekripsi menggunakan rumus (C_i - K_i + 26) % 26
            result += ((letter - base) - (toupper(key[keyIndex]) - 'A')) % 26 + base;

            // Update indeks kunci
            keyIndex = (keyIndex + 1) % key.length();
        }
        else
        {
            result += letter; // Jika bukan huruf, tidak didekripsi
        }
    }

    return result;
}

int main()
{
    string text, key;

    cout << "Masukkan teks yang ingin dienkripsi: ";
    getline(cin, text);

    cout << "Masukkan kunci: ";
    getline(cin, key);

    // Enkripsi teks
    string encrypted = encrypt(text, key);
    cout << "Teks terenkripsi: " << encrypted << endl;

    // Dekripsi teks
    string decrypted = decrypt(encrypted, key);
    cout << "Teks setelah dekripsi: " << decrypted << endl;

    return 0;
}
