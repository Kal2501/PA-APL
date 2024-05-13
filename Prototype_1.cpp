#include <iostream>

using namespace std;

struct kamera
{
	string nama;
	int harga;
	bool sewa;
};
struct user
{
	string nama;
	string pasword;
	kamera user[1]; //buat nyimpan data kamera yang disewakan user
};
int jml = 0;

kamera kmr[15];

kamera swa[15];

void tampilkan(string nama, int harga, bool data, int n){
	cout<< n+1 << ".\tNama: \t" << nama << endl;
	cout << "\tHarga: \t" << harga << endl;
	cout << "\tHarga: \t" << data << endl;
}

void tambahData(){
	cin.ignore();
	cout << "Masukkan nama\t:";
	getline(cin, kmr[jml].nama);
	cout << "Masukkan harga\t:";
	cin >> kmr[jml].harga;
	kmr[jml].sewa = true;
	jml++;
}

void tampilkanList(){
	if (jml == 0){
	cout << "Belum ada data kamera" << endl;
	}else{
		for (int i = 0; i< jml; i++){
			if (kmr[i].sewa == true){
				tampilkan(kmr[i].nama, kmr[i].harga, kmr[i].sewa, i);
			}
		}	
	}	
}

void sewa(){
	tampilkanList();
	int idx;
	cout<< "Pilih indeks yang ingin disewa: \t";
	cin >> idx;
	kmr[idx-1].sewa = false;
}

void awal(){
	cout << "1. Tambah\n"
	"2. lihat\n"
	"3. Sewa\n";
	
	string pilih;
	cout << "Masukkan pilihan: \t";
	cin >> pilih;
	if(pilih == "1"){
		tambahData();
	}else if(pilih == "2"){
		tampilkanList();
	}else if (pilih == "3"){
		sewa();
	}else{
		cout << "Pilihan tidak ada"<< endl;
	}
}

int main(){
	while (jml< 5){
		awal();
	}
}
