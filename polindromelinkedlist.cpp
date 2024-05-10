#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

// definisi struktur Node untuk simpul dalam linked list 
struct Node {
    char data;  
    Node* next; 
};

// definisi struktur Queue untuk merepresentasikan antrian 
struct Queue { 
    Node* front;
    Node* rear;
};

// inisialisasi queue dengan mengatur pointer depan dan belakang ke nullptr
void initQueue(Queue* q) {
    q -> front = q -> rear = nullptr;
}

// Memeriksa apakah queue kosong dengan memeriksa apakah kedua pointer depan dan belakang menunjuk ke nullptr
bool isEmpty(Queue* q){
    return (q -> front == nullptr && q -> rear == nullptr);
}

// enqueue data ke dalam queue
void enqueue(Queue* q, char data){
    // membuat simpul baru untuk data yang akan ditambahkan 
    Node* newNode = new Node;
    newNode -> data = data;
    newNode -> next = nullptr;
    
    // jika Queue kosong, simpul baru menjadi simpul depan dan belakang
    if(isEmpty(q)){
        q -> front = q -> rear = newNode;
    } else {
        // jika Queue tidak kosong, simpul baru ditambahkan di belakang dan pointer belakang diperbarui 
        q -> rear -> next = newNode;
        q -> rear = newNode;
    }
    cout << "Data berhasil ditambahkan\n";
}

// fungsi untuk menentukan apakah sebuah kata Palindrome atau bukan palindrome
bool isPalindrome(Queue* q){
    Node* frontPtr = q -> front;
    Node* rearPtr = q -> rear;

    // membandingkan karakter awal dan akhir 
    while (frontPtr != nullptr && rearPtr != nullptr){
        if(frontPtr -> data != rearPtr -> data){
            return false; //mengembalikan false jika ada perbedaan karakter
        }
        frontPtr = frontPtr -> next;
        rearPtr = rearPtr -> next;
    }
    return true; // mengembalikan true jika tidak ada perbedaan karakter, artinya merupakan palindrome
}

void line(){
    for (int i = 0; i < 62; i++){
        cout << "=";
    }
    cout << endl;
}

// menampilkan informasi tentang pembuat program
void member(){
    cout << "Program dibuat oleh :\n";
    cout << "1. Delia Nur Ilmi Salam   (2310631170069)\n";
    cout << "2. Nabiilah Nur Fauziyyah (2310631170105)\n";
    cout << "3. Zahra Fadhilatusyifa   (2310631170159)\n";
}

int main(){
    Queue q;
    initQueue(&q);
    int jml;
    char pil;

    do{
        line();
        cout << "\t        Program Menentukan Sebuah Kata\n";
        cout << "      Polindrome Atau Bukan Menggunakan Queue Linkedlist\n";
        line();
        cout << "Pilihan menu : \n";
        cout << "1. Cek Palindrome\n";
        cout << "2. Keluar\n";
        line();
        cout << "Masukkan Pilihan Anda : ";
        cin >> pil;

        system("cls");

        switch(pil){ 
            case '1' : { // case jika pengguna memilih 1 yaitu menu cek palindrome
                line();
                cout << "Masukkan jumlah data(huruf) dari kata yang ingin di cek : ";
                cin >> jml;
                cout << "Masukkan data(huruf) satu persatu!\n";

                // looping untuk menyimpan data (huruf) sebanyak variabel jml
                for (int i = 0; i < jml; i++){
                    char data;
                    cout << "Masukkan data ke- " << i + 1 << " : " ;
                    cin >> data;
                    enqueue(&q, data); // menambahkan karakter ke Queue
                }

                // menentukan apakah kata dalam Queue merupakan palindrome atau bukan, dan menampilkan hasilnya
                if (isPalindrome(&q)){
                cout << "\n Merupakan Palindrome\n";
                } else {
                cout << "\nBukan merupakan Palindrome\n";
                }

                line();
                cout << " Tekan enter untuk kembali ke menu!";
                getch();
                system("cls");
            break;
        }
        case '2' : // case memilih keluar dari program
            line();
            cout << "Terima kasih telah menggunakan program ini. sampai jumpa lagi! \n";
            line();
            member();
            line();
            return false; // keluar dari looping do-while

        default :  // jika input selain 1 atau 2 
            cout << "Pilihan tidak valid. Silahkan pilih 1 atau 2.\n";
            break;
        }
    } while (true); // looping akan terus berjalan selama kondisinya true

    return 0;

}

    
    
    

    

    
    