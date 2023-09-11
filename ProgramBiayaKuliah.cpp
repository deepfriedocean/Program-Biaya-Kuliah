#include <iostream>

using namespace std;

char decision, redo;
string namaFakultas, namaMhs, userNameLog, passWordLog, userNameSign, passWordSign;
int GajiOrtu, UKT, UangPangkal, GradeUkt, GrandTotal, LogSign;

void BayarKuliah();
void Login();

// function untuk menentukan grade UKT dan total akhir dari biaya kuliah mahasiswa yang sudah dikalkulasikan
void UKTpenentu() {
   cout << "Masukkan gaji orang tua = Rp. ";
   cin >> GajiOrtu;
   if (GajiOrtu > 0 && GajiOrtu < 500000) {
      GradeUkt = 1;
      // UKT = Rp.500.000 dan Grade UKT level 1
      UKT = 500000;
      GrandTotal = UKT + GajiOrtu + UangPangkal;

   } else if (GajiOrtu > 501000 && GajiOrtu < 2000000) {
      GradeUkt = 2;
      // UKT = Rp.850.000 dan Grade UKT level 2
      UKT = 850000;
      GrandTotal = UKT + GajiOrtu + UangPangkal;

   } else if (GajiOrtu > 2001000 && GajiOrtu < 3500000) {
      // UKT = Rp.1.650.000 dan Grade UKT level 3
      GradeUkt = 3;
      UKT = 1650000;
      GrandTotal = UKT + GajiOrtu + UangPangkal;

   } else if (GajiOrtu > 3501000 && GajiOrtu < 5000000) {
      // UKT = Rp.2.750.000 dan Grade UKT level 4
      GradeUkt = 4;
      UKT = 2750000;
      GrandTotal = UKT + GajiOrtu + UangPangkal;

   } else if (GajiOrtu > 5001000 && GajiOrtu < 10000000) {
      // UKT = Rp.3.850.000 dan Grade UKT level 5
      GradeUkt = 5;
      UKT = 3850000;
      GrandTotal = UKT + GajiOrtu + UangPangkal;

   } else {
      // UKT = Rp.5.100.000 dan Grade UKT level 6
      GradeUkt = 6;
      UKT = 5100000;
      GrandTotal = UKT + GajiOrtu + UangPangkal;
   }
}

// function yang menentukan user adalah penerima beasiswa
void FreeUKT() {
   cout << "\n=======================================\n";
   cout << "Apakah anda penerima beasiswa? [Y/N] = ";
   cin >> decision;
   if (decision == 'y' || decision == 'Y') {
      system("cls");
      cout << "\n=============================\n";
      cout << "=====Universitas Harpard=====";
      cout << "\n=============================\n";
      cout << "Nama = " << namaMhs << "\n";
      cout << "Nama Fakultas = " << namaFakultas << "\n";
      cout << "Status = Anda Bebas Biaya Kuliah";
      cout << "\n=============================\n\n";
      cout << "Cek ulang ? [Y/N] : ";
      cin >> redo;

      if (redo == 'y' || redo == 'Y') {
         BayarKuliah();
      } else {
         system("cls");
         Login();
      }
   } else if (decision == 'n') {
      system("cls");
      UKTpenentu();
   } else {
      FreeUKT();
   }
}

// function untuk memilih fakultas berdasarkan inputan user
// pada function ini terdapat pengkondisian uang pangkal untuk setiap fakultas yang dipilih
void Fakultas() {
   cout << "\n===Masukkan Nama Fakultas===\n";
   cout << "List nama Fakultas\n";
   cout << "1. Fakultas Teknik (FT)\n";
   cout << "2. Fakultas Kedokteran (FK)\n";
   cout << "3. Fakultas Hukum (FH)\n";
   cout << "4. Fakultas Ekonomi dan Bisnis (FEB)\n";
   cout << "5. Fakultas Peternakan (FAPET)\n";
   cout << "6. Fakultas Keguruan dan Ilmu Pendidikan (FKIP)\n\n";
   cout << "Pilih = ";
   cin >> namaFakultas;

   if (namaFakultas == "FT" || namaFakultas == "1" || namaFakultas == "ft") {
      namaFakultas = "Fakultas Teknik";
      // Rp. 7.000.000
      UangPangkal = 7500000;

   } else if (namaFakultas == "FK" || namaFakultas == "2" || namaFakultas == "fk") {
      namaFakultas = "Fakultas Kedokteran";
      // Rp. 75.000.000
      UangPangkal = 75000000;

   } else if (namaFakultas == "FH" || namaFakultas == "3" || namaFakultas == "fh") {
      namaFakultas = "Fakultas Hukum";
      // Rp.10.000.000
      UangPangkal = 10000000;

   } else if (namaFakultas == "FEB" || namaFakultas == "4" || namaFakultas == "feb") {
      namaFakultas = "Fakultas Ekonomi dan Bisnis";
      // Rp.15.000.000
      UangPangkal = 15000000;

   } else if (namaFakultas == "FAPET" || namaFakultas == "5" || namaFakultas == "fapet") {
      namaFakultas = "Fakultas Peternakan";
      // Rp.3.500.000
      UangPangkal = 3500000;

   } else if (namaFakultas == "FKIP" || namaFakultas == "6" || namaFakultas == "fkip") {
      namaFakultas = "Fakultas Keguruan dan Ilmu Pendidikan";
      // Rp.5.000.000
      UangPangkal = 5000000;

   } else {
      cout << "\n===ERROR===\n";
      cout << "Fakultas Belum Terdaftar\n\n";
      Fakultas();
   }
}

void BayarKuliah() {
   system("cls");
   cout << "=====Program Biaya Kuliah=====\n\n";
   cout << "Masukkan Nama = ";
   getline(cin >> ws, namaMhs);
   Fakultas();

   cout << "\n\n";

   FreeUKT();

   cout << "\n=============================\n";
   cout << "=====Universitas Harpard=====";
   cout << "\n=============================\n";
   cout << "Nama = " << namaMhs << "\n";
   cout << "Nama Fakultas = " << namaFakultas << "\n";
   cout << "Grade UKT = " << GradeUkt << "\n";
   cout << "UKT = Rp. " << UKT << "\n";
   cout << "Total Biaya Kuliah = Rp. " << GrandTotal;
   cout << "\n=============================\n";

   cout << "Cek ulang ? [Y/N] : ";
   cin >> redo;

   if (redo == 'y' || redo == 'Y') {
      BayarKuliah();
   } else {
      system("cls");
      Login();
   }
}

// function untuk melakukan Sign-in dan Log-in untuk user
void Login() {
   system("cls");
   cout << "\n=============================\n";
   cout << "=====Universitas Harpard=====";
   cout << "\n=============================\n";
   cout << "[1]. Sign-In\n";
   cout << "[2]. Log-In\n";
   cout << "Pilih = ";
   cin >> LogSign;

   if (LogSign == 1) {
      system("cls");
      cout << "\n=============================\n";
      cout << "=====Universitas Harpard=====";
      cout << "\n=============================\n";
      cout << "Masukkan Username: ";
      cin >> userNameSign;
      cout << "Masukkan Password: ";
      cin >> passWordSign;
      cout << "\n";
      cout << "Tekan Enter untuk Kembali ke Main Menu";
      cin.ignore();
      cin.ignore();
      Login();
   } else if (LogSign == 2) {
      cout << "\n=============================\n";
      cout << "=====Universitas Harpard=====";
      cout << "\n=============================\n";
      cout << "Masukkan Username: ";
      cin >> userNameLog;
      cout << "Masukkan Password: ";
      cin >> passWordLog;
      cout << "\n";
      if (userNameLog == userNameSign && passWordLog == passWordSign) {
         BayarKuliah();
      // } else if (userNameLog == "" && passWordLog == "") {
      //    cout << "Username dan Password Belum Terdaftar!\n";
      //    cout << "Tekan Enter untuk Kembali ke Main Menu";
      //    cin.ignore();
      //    cin.ignore();
      //    Login();
      } else if (userNameLog != userNameSign && passWordLog != passWordSign) {
         cout << "Username dan Password Salah!\n";
         cout << "Tekan Enter untuk Kembali ke Main Menu";
         cin.ignore();
         cin.ignore();
         Login();
      } else if (userNameLog == userNameSign && passWordLog != passWordSign) {
         cout << "Password Salah!\n";
         cout << "Tekan Enter untuk Kembali ke Main Menu";
         cin.ignore();
         cin.ignore();
         Login();
      } else if (userNameLog != userNameSign && passWordLog == passWordSign) {
         cout << "Username Salah!\n";
         cout << "Tekan Enter untuk Kembali ke Main Menu";
         cin.ignore();
         cin.ignore();
         Login();
      } else {
         cout << "Username dan Password Belum Terdaftar!\n";
         cout << "Tekan Enter untuk Kembali ke Main Menu";
         cin.ignore();
         cin.ignore();
         Login();
         Login();
      }
   }
}

int main() {
   Login();
}
