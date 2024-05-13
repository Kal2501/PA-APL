#include <iostream>
using namespace std;

struct kamera{
    string kamera;
    int harga;
    string sewa;
};
struct user{
    string nama;
    string password;
    kamera kmrUser[1]; //Buat nyimpan kamera yang disewa
};

user usr[100];

user *akun = usr;

kamera kmr[100];
int jmlKamera = 0;
int jmlUser = 0;
int idxUser;

string menuAdmin(){
    return "1. Tambah Kamera\n"
    "2. Lihat Kamera\n"
    "3. Hapus Kamera\n"
    "4. Edit Kamera\n"
    "5. Log out\n";
}
string menuUser(){
	return "1. Lihat Kamera\n"
	"2. Cari Kamera\n"
	"3. Sewa Kamera\n"
	"4. Kembalikan Kamera\n"
	"5. Log out\n";
}

void erorInput(){
    cout << "PILIHAN TIDAK DITEMUKAN!!!"<< endl;
}

//============Bubble Sort================
void swap(kamera &a, kamera &b) {
    kamera temp = a;
    a = b;
    b = temp;
}
void bubbleSort(kamera arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].kamera > arr[j + 1].kamera) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
//++++++++++++++++++++++++++++++++++++++

//============Binary Search=============
//?????????????????????????????????????
//++++++++++++++++++++++++++++++++++++++

//=============Fitur Admin==============
void tambahKameraAdmin(){
    if(jmlKamera < 100){
        string nama;
        string konfirmasi;
        int harga;
        cin.ignore();
        cout << "Masukkan nama kamera: ";
        getline(cin, nama);
        while(true){
            cout << "Masukkan harga kamera(per minggu): ";
            cin >> harga;
            if(cin.fail()|| harga < 0){
                cout<<"Input tidak valid atau harga kurang dari sama dengan 0"<<endl;
                cin.clear();
                cin.ignore(1000,'\n');
            }else{
                while (true){
                cout << "Kamera\t\t:" << nama << endl;
                cout << "Harga sewa\t: Rp. " << harga << endl;
                cout << "Apakan ingin menambahkan data tersebut(y/n)?";
                cin >> konfirmasi;
                if (konfirmasi == "y" || konfirmasi == "Y"){
                    kmr[jmlKamera].kamera = nama;
                    kmr[jmlKamera].harga = harga;
                    kmr[jmlKamera].sewa = "Tersedia";
                    jmlKamera++;
                    return;
                }else if (konfirmasi == "n" || konfirmasi == "N"){
                    return;
                }else{
                    erorInput();
                }
            }
            }
        }
    }else{
        cout << "Tidak dapat menambahkan kamera" << endl;
    }
}

void lihatKameraAdmin(){
    if (jmlKamera == 0){
        cout << "Tidak ada data kamera" << endl;
    }else{
    	bubbleSort(kmr, jmlKamera);
        for (int i =0; i< jmlKamera;i++){
            cout << i+1 << ".\tnama : " << kmr[i].kamera << endl;
            cout << "\tharga : Rp. " << kmr[i].harga << endl;
            if (kmr[i].sewa == "Tersedia"){
                cout << "\tstatus : Tersedia"<< endl;
                cout << endl;
            }else{
                cout << "\tstatus : Disewakan oleh "<< kmr[i].sewa << endl;
                cout << endl;
            }
        }
    }
}
void hapusKameraAdmin(){
    if (jmlKamera == 0){
        cout << "Tidak ada data kamera" << endl;
    }else{
        int idx;
        lihatKameraAdmin();
        while(true){
            cout << "Masukkan indeks kamera yang ingin di hapus: ";
            cin >> idx;
            if(cin.fail()){
                cout<<"Input tidak valid!"<<endl;
                cin.clear();
                cin.ignore(1000,'\n');
            }else{
                if (idx > jmlKamera || idx < 1){
                cout << "Indeks kamera tidak ditemukan" << endl;
                }else{
                    if(kmr[idx-1].sewa == "Tersedia"){
                        string konfirmasi;
                        while(true){
                            cout << "Kamera\t\t:" << kmr[idx-1].kamera << endl;
                            cout << "Harga sewa\t: Rp. " << kmr[idx-1].harga << endl;
                            cout << "Apakan ingin menghapus data tersebut(y/n)?";
                            cin >> konfirmasi;
                            if (konfirmasi == "y" || konfirmasi == "Y"){
                                for (int i = idx-1; i< jmlKamera;i++){
                                    kmr[i] = kmr[i+1];
                                    jmlKamera--;
                                }
                                break;
                            }else if (konfirmasi == "n" || konfirmasi == "N"){
                                break;
                            }else{
                                erorInput();
                            }
                        }
                        break;
                    }else{
                        cout << "Kamera tersebut sedang disewakan, tidak dapat dihapus" << endl;
                    }
                }
            }
        }
    }
}

void editKameraAdmin(){
    if (jmlKamera == 0){
        cout << "Tidak ada data kamera" << endl;
    }else{
        int idx;
        lihatKameraAdmin();
        while(true){
            cout << "Masukkan indeks kamera yang ingin di edit: ";
            cin >> idx;
            if(cin.fail()){
                cout<<"Input tidak valid!"<<endl;
                cin.clear();
                cin.ignore(1000,'\n');
            }else{
                if (idx > jmlKamera || idx < 1){
                    cout << "Indeks kamera tidak ditemukan" << endl;
                }else{
                    if (kmr[idx-1].sewa == "Tersedia"){
                        string nama, konfirmasi;
                        int harga;
                        cout << "Kamera\t\t:" << kmr[idx-1].kamera << endl;
                        cout << "Harga sewa\t: Rp. " << kmr[idx-1].harga << endl;
                        cin.ignore();
                        cout << "Masukkan nama yang baru: ";
                        getline(cin, nama);
                        while(true){
                            cout << "Masukkan harga yang baru: ";
                            cin >> harga;
                            if(cin.fail() || harga < 0 ){
                                 cout<<"Input tidak valid atau harga kurang dari sama dengan 0"<<endl;
                                 cin.clear();
                                 cin.ignore(1000,'\n');
                            }else{
                                while (true){
                                    cout << "Kamera\t\t:" << kmr[idx-1].kamera << " Menjadi: " << nama << endl;
                                    cout << "Harga sewa\t: Rp. " << kmr[idx-1].harga << " Menjadi: Rp. " << harga << endl;
                                    cout << "Apakan ingin mengubah data tersebut(y/n)?";
                                    cin >> konfirmasi;
                                    if (konfirmasi == "y" || konfirmasi == "Y"){
                                        kmr[idx-1].kamera = nama;
                                        kmr[idx-1].harga = harga;
                                        break;
                                    }else if (konfirmasi == "n" || konfirmasi == "N"){
                                        break;
                                    }else{
                                        erorInput();
                                    }
                                }
                                break;
                            }
                        }
                    }else{
                        cout << "Kamera sedang disewakan, tidak dapat merubah data!!!"<< endl;
                    }
                }
            break;
            }
        }
    }
}

void tampilanAdmin(){
    while (true){
        string pilihMenu;
        cout << menuAdmin() ;
        cout << "Masukkan pilihan: ";
        cin >> pilihMenu;
        if(pilihMenu == "1"){
            tambahKameraAdmin();
        }else if(pilihMenu == "2"){
            lihatKameraAdmin();
        }else if(pilihMenu == "3"){
            hapusKameraAdmin();
        }else if(pilihMenu == "4"){
            editKameraAdmin();
        }else if(pilihMenu == "5"){
            break;
        }else{
            erorInput();
        }
    }     
}
//++++++++++++++++++++++++++++++++++++

//=============Fitur User=============

void lihatKameraUser(){
    if (jmlKamera == 0){
        cout << "Tidak ada data kamera" << endl;
    }else{
    	bubbleSort(kmr, jmlKamera);
        for (int i =0; i< jmlKamera;i++){
            cout << i+1 << ".\tnama : " << kmr[i].kamera << endl;
            cout << "\tharga : Rp. " << kmr[i].harga << endl;
            if (kmr[i].sewa == "Tersedia"){
                cout << "\tstatus : Tersedia"<< endl;
                cout << endl;
            }else{
                cout << "\tstatus : Tidak dapat disewakan"<< endl;
                cout << endl;
            }
        }
    }
}
// pipis
void sewaKameraUser(){
    if (jmlKamera == 0){
        cout << "Tidak ada data kamera" << endl;
    }else{
        int idx;
        string konfirmasi;
        while(true){
            lihatKameraUser();
            cout << "Masukkan indeks kamera yang ingin disewakan: ";
            cin >> idx;
            if(cin.fail()){
                cout<<"Input tidak valid!"<<endl;
                cin.clear();
            }else if(kmr[idx-1].sewa == "Tersedia"){
                cout << "Kamera sedang tersedia, tidak dapat disewakan!!!"<< endl;
            }else{
                while(true){
                    cout << "\tnama : " << kmr[idx-1].kamera << endl;
                    cout << "\tharga : Rp. " << kmr[idx-1].harga << endl;
                    cout << "Apakah anda ingin menyewa kamera tersebut(y/n)?";
                    cin >> konfirmasi;
                    if (konfirmasi == "y" || konfirmasi == "Y"){
                        cout << "Kamera berhasil disewakan" << endl;
                        usr[idxUser].kmrUser[0] = kmr[idx-1];
                        kmr[idx-1].sewa = usr[idxUser].nama;
                        return;
                    }else if (konfirmasi == "n" || konfirmasi == "N"){
                        cout << "Sewa dibatalkan" << endl;
                        return;
                    }else{
                        erorInput();
                    }
                }
            }
        }
    }
}

void tampilanUser(){
    while (true){
        string pilihMenu;
        //cout <<"Indeks: "<<  idxUser<< endl;
        cout << menuUser();
        cout << "Masukkan pilihan: ";
        cin >> pilihMenu;
        if(pilihMenu == "1"){
            lihatKameraUser();
        }else if(pilihMenu == "2"){
            //lihatKameraAdmin();
        }else if(pilihMenu == "3"){
            //hapusKameraAdmin();
        }else if(pilihMenu == "4"){
            //editKameraAdmin();
        }else if(pilihMenu == "5"){
            break;
        }else{
            erorInput();
        }
    }     
}
//++++++++++++++++++++++++++++++++++++++

//=====Fitur Login & Registrasi=========
int loginUser(string username, string password){
    for (int i=0; i<jmlUser; i++){
    	if (usr[i].nama == username && usr[i].password == password){
    		idxUser = i;
    		return 1;	
		}
		return -1;
	}
}

void login(){
	string username;
	string password;
	cin.ignore();
	cout << "Username: ";
	getline(cin, username);
	cout << "Password: ";
	getline(cin, password);
	if (username == "admin" && password == "admin"){
		tampilanAdmin();
	}else if (loginUser(username, password) == 1){
		tampilanUser();
	}else{
		cout << "Username atau password salah!!!" << endl;
	}
}

void registerUser(){
    if (jmlUser < 100) {
    	cin.ignore();
        cout << "Masukkan username: ";
        getline(cin, usr[jmlUser].nama);
        cout << "Masukkan password: ";
        getline(cin, usr[jmlUser].password);
        cout << "Register berhasil " << endl;
        jmlUser++;
    }else{
        cout << "Penuh" << endl;
    }
}
//+++++++++++++++++++++++++++++++

void menuAwal(){
	while (true){
		cout << "1. Login\n"
		"2. Registrasi\n"
		"3. Keluar\n";
		string pilih;
		cout << "Masukkan pilihan: ";
		cin >> pilih;
		if (pilih == "1"){
			login();
		}else if (pilih == "2"){
			registerUser();
		}else if (pilih == "3"){
			return;
		}else{
			erorInput();
		}
	}
}

int main(){
    menuAwal();
    return 0;
}

