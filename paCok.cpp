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

string menuAdmin(){
    return "1. Tambah Kamera\n"
    "2. Lihat Kamera\n"
    "3. Hapus Kamera\n"
    "4. Edit Kamera\n"
    "5. Log out\n"
    "6. Exit\n";
}

void erorInput(){
    cout << "PILIHAN TIDAK DITEMUKAN!!!"<< endl;
}


void tambahKameraAdmin(){
    string nama;
    string konfirmasi;
    int harga;
    cin.ignore();
    cout << "Masukkan nama kamera: ";
    getline(cin, nama);
    cout << "Masukkan harga kamera(per minggu): ";
    cin >> harga;
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

void lihatKameraAdmin(){
    if (jmlKamera == 0){
        cout << "Tidak ada data kamera" << endl;
    }else{
        for (int i =0; i< jmlKamera;i++){
            cout << i+1 << ". nama : " << kmr[i].kamera << endl;
            cout << "harga : Rp. " << kmr[i].harga << endl;
            if (kmr[i].sewa == "Tersedia"){
                cout << "status : Tersedia"<< endl;
                cout << endl;
            }else{
                cout << "status : Disewakan oleh "<< kmr[i].sewa << endl;
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
        cout << "Masukkan indeks kamera yang ingin di hapus: ";
        cin >> idx;
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
            }else{
                cout << "Kamera tersebut sedang disewakan, tidak dapat dihapus" << endl;
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
        cout << "Masukkan indeks kamera yang ingin di edit: ";
        cin >> idx;
        if (idx > jmlKamera || idx < 1){
            cout << "Indeks kamera tidak ditemukan" << endl;
        }else{
            //belum selesai
        }    
    }
}

void admin(){
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
        }else if(pilihMenu == "6"){
            return;
        }else{
            erorInput();
        }
    }     
}

void menuUser(){
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
        }else if(pilihMenu == "6"){
            return;
        }else{
            erorInput();
        }
    }     
}

void loginAdmin(){
    string username;
    string password;
    cout << "Masukkan username: ";
    cin >> username;
    cout << "Masukkan password: ";
    cin >> password;
    if (username == "admin" && password == "admin"){
        cout << "Login berhasil" << endl;
        admin();
    }else{
        cout << "Login gagal" << endl;
    }
}

void loginUser(){
    string username;
    string password;
    cout << "Masukkan username: ";
    cin >> username;
    cout << "Masukkan password: ";
    cin >> password;
    if (username == usr->nama && password == usr->password){
        cout << "Login berhasil" << endl;
        menuUser();
    }
    else{
        cout << "Login gagal" << endl;
    }
}

void registerUser(){
    if (jmlUser < 100) {
        cout << "Masukkan username: ";
        getline(cin, usr[jmlUser].nama);
        cout << "Masukkan password: ";
        getline(cin, usr[jmlUser].password);
        cout << "Register berhasil " << endl;
        jmlUser++;
        loginUser();
    }else{
        cout << "Penuh" << endl;
    }
}

int main(){
    registerUser();
    return 0;
}

