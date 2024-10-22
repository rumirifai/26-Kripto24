#include <iostream>
#include <string>

// Prototype Fungsi
std::string encrypt(std::string text, int s);
std::string decrypt(std::string text, int s);

int main() {
    std::string text;
    int keyshift, choice;

    std::cout << "Masukkan teks: ";
    getline(std::cin, text);

    std::cout << "Masukkan Key: ";
    std::cin >> keyshift;

    std::cout << "Mau diapain textnya?\n 1.Enkripsi bang\n 2.Dekripsiin aja bang\n Pilihan (1 atau 2): ";
    std::cin >> choice;

    // Pemilihan Kondisi
    if (choice == 1)
    {
        std::string encrypted = encrypt(text, keyshift);
        std::cout << "Teks terenkripsi: " << encrypted << std::endl;
    } else if (choice == 2)
    {
        std::string decrypted = decrypt(text, keyshift);
        std::cout << "Teks terdekripsi: " << decrypted << std::endl;
    } else {
        std::cout << "Eits, pilih salah satu aja dong";
    }

    return 0;
}

// Fungsi untuk enkripsi teks menggunakan Shift Cipher
std::string encrypt(std::string text, int s)
{
    std::string result = "";

    for (int i = 0; i < text.length(); i++)
    {
        // Enkripsi huruf besar
        if (isupper(text[i]))
            result += char(int(text[i] + s - 65) % 26 + 65);

        // Enkripsi huruf kecil
        else if (islower(text[i]))
            result += char(int(text[i] + s - 97) % 26 + 97);

        // Jika bukan huruf, tambahkan karakter asli (tanpa enkripsi)
        else
            result += text[i];
    }
    return result;
}

// Fungsi untuk dekripsi teks menggunakan Shift Cipher
std::string decrypt(std::string text, int s)
{
    std::string result = "";

    for (int i = 0; i < text.length(); i++)
    {
        // Dekripsi huruf besar
        if (isupper(text[i]))
            result += char(int(text[i] - s - 65 + 26) % 26 + 65);

        // Dekripsi huruf kecil
        else if (islower(text[i]))
            result += char(int(text[i] - s - 97 + 26) % 26 + 97);

        // Jika bukan huruf, tambahkan karakter asli (tanpa dekripsi)
        else
            result += text[i];
    }
    return result;
}
