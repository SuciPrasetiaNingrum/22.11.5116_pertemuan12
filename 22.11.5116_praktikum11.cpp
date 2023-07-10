#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> data;
    string line;

    // Membaca isi file
    ifstream is("C:\\data.txt");
    if (!is.is_open())
    {
        cout << "Tidak dapat membuka file\n";
        return 1;
    }

    while (getline(is, line))
    {
        data.push_back(line);
    }

    is.close();

    // Menampilkan isi file
    cout << "Isi file sebelum diedit:\n";
    for (size_t i = 0; i < data.size(); ++i)
    {
        cout << "[" << i + 1 << "] " << data[i] << endl;
    }

    // Menambahkan atau menghapus data
    cout << "\nPilih opsi:\n";
    cout << "1. Tambah data baru\n";
    cout << "2. Hapus data\n";
    cout << "Pilihan: ";
    int option;
    cin >> option;
    cin.ignore();

    if (option == 1)
    {
        cout << "\nMasukkan data baru :\n";
        while (getline(cin, line))
        {
            if (line == "")
                break;
            data.push_back(line);
        }
    }
    else if (option == 2)
    {
        cout << "\nPilih nomor data yang akan dihapus (1 - " << data.size() << "): ";
        int index;
        cin >> index;
        cin.ignore();

        if (index >= 1 && index <= data.size())
        {
            data.erase(data.begin() + index - 1);
        }
        else
        {
            cout << "Nomor data tidak valid\n";
            return 1;
        }
    }
    else
    {
        cout << "Opsi tidak valid\n";
        return 1;
    }

    
    ofstream os("C:\\data.txt");


    for (const auto& d : data)
    {
        os << d << endl;
    }

    os.close();

    cout << "\nIsi file setelah diedit:\n";
    for (size_t i = 0; i < data.size(); ++i)
    {
        cout << "[" << i + 1 << "] " << data[i] << endl;
    }

    return 0;
}

