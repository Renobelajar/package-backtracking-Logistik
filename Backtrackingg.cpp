#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// Variabel global untuk menghitung jumlah solusi yang ditemukan
int solution_count = 0;

// Fungsi rekursif Backtracking untuk mencari subset yang jumlahnya pas dengan target
void findPackagesBacktracking(const vector<int>& packets, int target, int index, 
                               int current_weight, vector<int>& current_combination) {
    
    // Base Case 1: Jika berat saat ini pas dengan target (300 kg)
    if (current_weight == target) {
        solution_count++;
        cout << "Solusi " << solution_count << ": [ ";
        for (int weight : current_combination) {
            cout << weight << " kg ";
        }
        cout << "]" << endl;
        return;
    }

    // Base Case 2: Jika berat melebihi target ATAU semua paket sudah diperiksa
    if (current_weight > target || index == packets.size()) {
        return; // Hentikan cabang ini dan lakukan Backtrack
    }

    // Opsi 1: AMBIL paket saat ini
    current_combination.push_back(packets[index]);
    findPackagesBacktracking(packets, target, index + 1, current_weight + packets[index], current_combination);

    // Opsi 2: JANGAN AMBIL paket saat ini (Proses Backtrack dilakukan di sini)
    current_combination.pop_back(); // Menghapus paket terakhir yang dimasukkan untuk mencoba jalur lain
    findPackagesBacktracking(packets, target, index + 1, current_weight, current_combination);
}

int main() {
    // Data Input sesuai studi kasus logistik
    vector<int> packets = {50, 80, 100, 120, 150, 170};
    int target_weight = 300; // Target berat pas 300 kg
    
    vector<int> current_combination;

    cout << "==================================================" << endl;
    cout << "   PENCARIAN KOMBINASI PAKET (BACKTRACKING)       " << endl;
    cout << "   Target Berat: " << target_weight << " kg" << endl;
    cout << "==================================================" << endl;

    // Jalankan fungsi backtracking dimulai dari indeks paket ke-0 dan berat awal 0
    findPackagesBacktracking(packets, target_weight, 0, 0, current_combination);

    if (solution_count == 0) {
        cout << "Tidak ditemukan kombinasi paket yang pas 300 kg." << endl;
    } else {
        cout << "==================================================" << endl;
        cout << "Total ditemukan " << solution_count << " kombinasi yang valid." << endl;
    }

    return 0;
}