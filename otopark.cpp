#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

int main() {
    string sehirler[82] = {
        "Bilinmeyen", "Adana", "Adiyaman", "Afyonkarahisar", "Agri", "Amasya", "Ankara", "Antalya", "Artvin", "Aydin", 
        "Balikesir", "Bilecik", "Bingol", "Bitlis", "Bolu", "Burdur", "Bursa", "Canakkale", "Cankiri", "Corum", 
        "Denizli", "Diyarbakir", "Edirne", "Elazig", "Erzincan", "Erzurum", "Eskisehir", "Gaziantep", "Giresun", "Gumushane", 
        "Hakkari", "Hatay", "Isparta", "Mersin", "Istanbul", "Izmir", "Kars", "Kastamonu", "Kayseri", "Kirklareli", 
        "Kirsehir", "Kocaeli", "Konya", "Kutahya", "Malatya", "Manisa", "Kahramanmaras", "Mardin", "Mugla", "Mus", 
        "Nevsehir", "Nigde", "Ordu", "Rize", "Sakarya", "Samsun", "Siirt", "Sinop", "Sivas", "Tekirdag", 
        "Tokat", "Trabzon", "Tunceli", "Sanliurfa", "Usak", "Van", "Yozgat", "Zonguldak", "Aksaray", "Bayburt", 
        "Karaman", "Kirikkale", "Batman", "Sirnak", "Bartin", "Ardahan", "Igdir", "Yalova", "Karabuk", "Kilis", 
        "Osmaniye", "Duzce"
    };

    string plaka;
    
    // YENÝ EKLENEN KISIM: Kullanýcýdan plaka alma
    cout << "--- OTOPARK SISTEMINE HOSGELDINIZ ---" << endl;
    cout << "Lutfen aracin plakasini girin (Orn: 42 KNK 99): ";
    getline(cin, plaka); // cin yerine getline kullandýk ki boþluklu yazarsan hata vermesin

    string plakaKoduStr = plaka.substr(0, 2); 
    int plakaKodu = atoi(plakaKoduStr.c_str());

    cout << "\nIslem yapiliyor..." << endl;
    
    if (plakaKodu > 0 && plakaKodu <= 81) {
        string sehir = sehirler[plakaKodu];
        cout << "Geldigi Sehir: " << sehir << endl;

        ofstream veritabani("otopark_log.txt", ios::app); 
        
        if (veritabani.is_open()) {
            veritabani << plaka << "," << sehir << ",Giris" << endl;
            veritabani.close();
            cout << "---> Basariyla veritabanina kaydedildi!" << endl;
        } else {
            cout << "Veritabani dosyasi acilamadi!" << endl;
        }

    } else {
        cout << "Hatali veya gecersiz plaka kodu girdiniz!" << endl;
    }

    return 0;
}
