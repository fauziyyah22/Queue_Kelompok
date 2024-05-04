#include <iostream>
#include <conio.h>
#include <string>
#define maks 100//Menetapkan nilai maks

using namespace std;

void line(){ //Fungsi untuk mencetak gari8s horizontal sepanjang 60
    for(int i = 0; i < 62; i++) {
        cout << "=";
    }
    cout << "\n";
}

void anggota(){// Fungsi untuk mencetak anggota kelompok
    cout << " Program dibuat oleh :\n";
    cout << " 1. Delia Nur Ilmi Salam   (2310631170069)\n";
    cout << " 2. Nabiilah Nur Fauziyyah (2310631170105)\n";
    cout << " 3. Zahra Fadhilatusyifa   (2310631170159)\n";
}

// Struktur untuk merepresentasikan queue menggunakan array
struct ArrayQueue {
    char items[maks];// Deklarasi dan inisialisasi array char items dengan panjang maks
    //yang digunakan untuk menyimpan elemen-elemen dalam queue
    int front, rear;// front menunjukkan indeks dari elemen terdepan dalam queue
    // rear menunjukkan indeks dari elemen terakhir dalam queue
};

//Mengecek apakah queue sudah penuh, fungsi akan mengembalikan nilai bool true atau false
bool isFull(const ArrayQueue& q) {// Memiliki parameter yang merujuk ke informasi tentang queue
    return q.rear == maks - 1; // Queue penuh jika q.rear atau indeks bagian belakang queue = maks - 1
}

//Mengecek apakah queue sudah kosong, fungsi akan mengembalikan nilai bool true atau false
bool isEmpty(const ArrayQueue& q){// Memiliki parameter yang merujuk ke informasi tentang queue
    return q.rear == -1;// Queue kosong jika q.rear atau indeks bagian belakang queue =
}

// Fungsi untuk menambahkan elemen ke dalam queue
void enqueue(ArrayQueue& q, char item) {//Memiliki 2 buah parameter yaitu queue yang ingin ditambah elemennya
// parameter char item yang merupakan elemen yang ingin ditambahkan ke dalam queue.
    if(isFull(q)) {// Pengkondisian jika queue sudah penuh
        cout << "Queue sudah penuh.\n";
        return;// Keluar dari fungsi
    }
    if (isEmpty(q)) {// Pengkondisian jika queue kosong
        q.front = 0;// Menginisialisasi q.front dengan 0
    }
    q.rear++;// Iterasi q.rear
    q.items[q.rear] = item;//Inisialisasi q.items dengan indeks q.rear dengan item
}

// Fungsi untuk memeriksa apakah kata adalah palindrom atau bukan
bool isPalindrome(string word) {// Fungsi memiliki 1 parameter berupa kata yang ingin di cek
    ArrayQueue q;// Deklarasi variabel q yang merupakan arrayQueue
    q.front = -1;// Inisialisasi nilai front dengan -1
    q.rear = -1;// Inisialisasi nilai rear dengan -1
    int len = word.length();// Menghitung panjang kata yang diinputkan

    // Menambahkan setiap karakter dari kata ke dalam queue
    for (int i = 0; i < len; i++) {// Looping akan berjalan sebanyak i < panjang kata
        enqueue(q, word[i]);// Pemanggilan fungsi enqueue untuk memasukkan word[i] ke dalam queue i
    }

    // Membandingkan setiap karakter dari depan dan belakang
    for (int i = 0; i < len / 2; i++) {// Looping akan berjalan sebanyak setengah panjang kata
        // Mengambil karakter dari depan dan belakang
        char frontChar = q.items[q.front + i];// Mengambil char dari depan queue
        char rearChar = q.items[q.rear - i];// Mengambil char dari belakang queue

        // Membandingkan karakter tersebut
        if (frontChar != rearChar)//Jika char depan != char belakang
            return false;// Fungsi mengembalikan nilai false atau bukan palindrome
    }
    return true;//Jika semua cocok, fungsi mengembalikan nilai true atau palindrome
}

int main() {
    char pil;// Deklarasi variabel pil bertipe data char

    do {// looping do-while agar program dijalankan sekali
        int jmlChar;// Deklarasi variabel jmlhChar yang digunakan untuk menyimpan input berupa jumlah char kata

        line();// Judul Program
        cout << " \t\tProgram Menentukan Sebuah Kata\n";
        cout << " Palindrome atau Bukan Palindrome Menggunakan Queue Array\n";
        line();
        cout << " Pilihan menu:\n";// Pilihan Menu
        cout << " 1. Cek Palindrome\n";
        cout << " 2. Keluar\n";
        line();
        cout << " Pilihan : ";// Meminta input pilihan dari user
        cin >> pil;// Input disimpan di variabel pil

        system("cls");// Membersihkan layar

        switch (pil) {// Switch dengan ekspresi variabel pil
            case '1': { // Case jika pilihan user = 1
                line ();
                cout << " Masukkan jumlah huruf dari kata yang ingin di cek : ";// Meminta user menginput jumlah huruf
                cin >> jmlChar;// Input disimpan di variabel jmlChar

                string word;// Deklarasi variabel word yang digunakan untuk menampung setiap huruf
                cout << " Masukkan huruf-hurufnya satu per satu!\n";// Perintah untuk memasukkan huruf satu per satu

                for (int i = 0; i < jmlChar; ++i) {// Looping untuk menyimpan huruf sebanyak jumlah char
                // looping berjalan dari i dan i diiterasi tiap selesai eksekusi
                    char ch;// Deklarasi variabel ch yang digunakan untuk menyimpan input huruf dari user
                    cout << " Masukkan huruf ke-" << i+1 << " : ";// Perintah untuk memasukkan huruf
                    cin >> ch;// In
                    word += ch; // Menambahkan huruf ke dalam kata
                }
                cout << " Kata yang dibentuk : " << word << "\n";

                // Memeriksa apakah kata adalah palindrome atau bukan
                if (isPalindrome(word)) { // Memanggil fungsi palindrome dengan parameter word
                    cout << " " << word << " adalah palindrome\n";
                }
                else{
                  cout << " " << word << " bukan palindrome\n";
                }
                    line();
                    cout << " Tekan enter untuk kembali ke menu !";
                    getch();
                    system("cls");
                break;
            }
            case '2':// Case jika memilih keluar dari program
                cout << "Terima kasih telah menggunakan program ini. Sampai jumpa lagi !\n";
                line();
                anggota();
                line();
                return false;// Keluar dari looping do-while

            default:// Jika input selain 1 atau 2
                cout << "Pilihan tidak valid. Silakan pilih 1 atau 2.\n" ;
                break;
        }
    } while (true);// Looping akan terus dijalankan selama kondisinya true


    return 0;
}
