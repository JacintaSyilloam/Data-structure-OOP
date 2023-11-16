#include <iostream>
#include <list>
#include <string>
#include <stack>
#include <math.h>
#include <stdio.h>

using namespace std;

class Titik
{
public:
    int id;
    string nama_tempat;
    double x;
    double y;

    Titik() : id(0), nama_tempat(""), x(0.0), y(0.0) {}

    Titik(int id, string nama_tempat, double x, double y)
    {
        this->id = id;
        this->nama_tempat = nama_tempat;
        this->x = x;
        this->y = y;
    }
};

// Mendefinisikan "Class" Peta yang mengimplementasikan struktur data "Graph"
// Ini "Class Peta"
class Peta
{

private:
    // Property list
    int jumlah_titik;
    list<int> *adjacency_list;

    // Property matrix
    int **adjacency_matrix;
    Titik *titik_array;

public:
    // Constructor
    Peta(int jumlah_titik)
    {
        this->jumlah_titik = jumlah_titik;
        adjacency_list = new list<int>[jumlah_titik];

        inisialisasiAdjMatrix(jumlah_titik);
        titik_array = new Titik[jumlah_titik];
    }

    // Destructor
    ~Peta()
    {
        delete[] adjacency_list;
        for (int i = 0; i < jumlah_titik; i++)
        {
            delete[] adjacency_matrix[i];
        }
        delete[] adjacency_matrix;
        delete[] titik_array;
    }

    void inisialisasiAdjMatrix(int jumlah_titik)
    {
        adjacency_matrix = new int *[jumlah_titik];
        for (int i = 0; i < jumlah_titik; i++)
        {
            adjacency_matrix[i] = new int[jumlah_titik];
            for (int j = 0; j < jumlah_titik; j++)
            {
                adjacency_matrix[i][j] = 0;
            }
        }
    }

    // Fungsi untuk menambahkan koneksi dari titik awal ke tujuan
    void tambahLintasan(int asal, int tujuan)
    {
        adjacency_list[asal].push_back(tujuan);

        adjacency_matrix[asal][tujuan] = 1;
        adjacency_matrix[tujuan][asal] = 1;
    }

    // Fungsi untuk menampilkan adjacency list
    void tampilkanAdjList()
    {
        list<int>::iterator i;

        for (int v = 0; v < jumlah_titik; v++)
        {
            cout << v + 1 << " -> ";
            for (i = adjacency_list[v].begin(); i != adjacency_list[v].end(); ++i)
            {
                cout << (*i);
                if (next(i, 1) != adjacency_list[v].end())
                {
                    cout << " -> ";
                }
            }
            cout << endl;
        }
    }

    void tampilkanAdjMatrix()
    {
        for (int i = 0; i < jumlah_titik; i++)
        {
            for (int j = 0; j < jumlah_titik; j++)
            {
                cout << adjacency_matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void tambahTitik(int id, string nama_tempat, double x, double y)
    {
        titik_array[id - 1] = Titik(id, nama_tempat, x, y);
    }

    void tampilkanTitik()
    {
        for (int i = 0; i < jumlah_titik; i++)
        {
            cout << "Titik: " << titik_array[i].id << endl;
            cout << "Nama Tempat: " << titik_array[i].nama_tempat << endl;
            cout << "Koordinat (x, y): (" << titik_array[i].x << ", " << titik_array[i].y << ")" << endl;
            cout << endl;
        }
    }

    double hitungJarak(int titik_awal, int titik_tujuan)
    {
        if (titik_awal < 1 || titik_awal > jumlah_titik || titik_tujuan < 1 || titik_tujuan > jumlah_titik)
        {
            cout << "ID titik tidak valid." << endl;
            return -1.0; // Nilai negatif menunjukkan kesalahan
        }

        double x1 = titik_array[titik_awal - 1].x;
        double y1 = titik_array[titik_awal - 1].y;
        double x2 = titik_array[titik_tujuan - 1].x;
        double y2 = titik_array[titik_tujuan - 1].y;

        // Menghitung jarak dengan rumus Euclidean distance
        double jarak = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

        return jarak;
    }
};

int main()
{
    int asal, tujuan;
    int choice;

    cout << "Peta Rumah" << endl;
    int jumlah_titik = 10;

    // Ini "Object petaKu"
    // Object adalah instansiasi dari Class
    Peta petaKu(jumlah_titik);

    // Mendefinisikan data untuk graf Peta
    petaKu.tambahLintasan(0, 1); // dari titik 0 ke 1
    petaKu.tambahLintasan(0, 4); // dari titik 0 ke 4
    petaKu.tambahLintasan(1, 2);
    petaKu.tambahLintasan(1, 4);
    petaKu.tambahLintasan(1, 5);
    petaKu.tambahLintasan(2, 3);
    petaKu.tambahLintasan(4, 6);
    petaKu.tambahLintasan(3, 8);
    petaKu.tambahLintasan(6, 9);
    petaKu.tambahLintasan(6, 7);
    petaKu.tambahLintasan(7, 9);
    petaKu.tambahLintasan(7, 8);
    petaKu.tambahLintasan(5, 4);
    petaKu.tambahLintasan(5, 1);
    petaKu.tambahLintasan(4, 1);
    petaKu.tambahLintasan(4, 0);
    petaKu.tambahLintasan(6, 4);
    petaKu.tambahLintasan(7, 6);
    petaKu.tambahLintasan(9, 6);
    petaKu.tambahLintasan(9, 7);
    petaKu.tambahLintasan(8, 7);

    petaKu.tambahTitik(0, "Universitas Widya Kartika", 0.0, 5.0);
    petaKu.tambahTitik(1, "Spectrum", 1.0, 3.0);
    petaKu.tambahTitik(2, "Mcd", 1.0, 2.0);
    petaKu.tambahTitik(3, "SAS", 0.0, 2.0);
    petaKu.tambahTitik(4, "Home", 3.0, 5.0);
    petaKu.tambahTitik(5, "Mulyosari Tengah", 3.0, 3.0);
    petaKu.tambahTitik(6, "San Antonio", 5.0, 4.0);
    petaKu.tambahTitik(7, "San Diego", 6.0, 2.0);
    petaKu.tambahTitik(8, "Palem Cinde", 7.0, 1.0);
    petaKu.tambahTitik(9, "Hokky", 8.0, 5.0);

    cout << endl;
    cout << "Adjacency List" << endl;
    petaKu.tampilkanAdjList();

    cout << endl;
    cout << "Adjacency Matrix" << endl;
    petaKu.tampilkanAdjMatrix();

    cout << endl;
    cout << "Informasi Titik" << endl;
    petaKu.tampilkanTitik();

    while (true)
    {
        cout << endl;
        cout << "=== MENU ===" << endl;
        cout << "1. Find distance between two places" << endl;
        cout << "2. Exit program" << endl;
        cout << "Input Choice: ";
        cin >> choice;
        if (choice == 1)
        {
            cout << "ID of origin: ";
            cin >> asal;
            cout << "ID of destination: ";
            cin >> tujuan;
            double jarak = petaKu.hitungJarak(asal, tujuan);
            if (jarak >= 0)
            {
                cout << "Distance between " << asal << " and " << tujuan << " is " << jarak << " units." << endl;
            }
        }
        else if (choice == 2)
        {
            cout << "Exiting the program..." << endl;
            break; 
        }
        else
        {
            cout << "Pilihan tidak valid. Silakan pilih 1 atau 2." << endl;
        }
    }
}