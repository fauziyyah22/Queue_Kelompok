#include <iostream>
#include <string>
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

// menampilkan informasi tentang pembuat program
void member(){
    cout << "\nProgram dibuat oleh :\n";
    cout << "1. Delia Nur Ilmi Salam   (2310631170069)\n";
    cout << "2. Nabiilah Nur Fauziyyah (2310631170105)\n";
    cout << "3. Zahra Fadhilatusyifa   (2310631170159)\n";
    cout << "================================================\n";

    cout << endl;
}

int main(){
    Queue q;
    initQueue(&q);
    int jml;

    system("cls");
    cout << "===========================================================\n";
    cout << "    \tProgram Menentukan Apakah Sebuah Kata     \n";
    cout << "  Polindrome atau Bukan Polindrome Menggunakan Linkedlist  \n";
    cout << "===========================================================\n";
    cout << "Masukkan jumlah data : ";
    cin >> jml;

    for (int i = 0; i < jml; i++){
        char data;
        cout << "Masukkan data : ";
        cin >> data;
        enqueue(&q, data); // menambahkan karakter ke Queue
    }

    // menentukan apakah kata dalam Queue merupakan palindrome atau bukan, dan menampilkan hasilnya
    if (isPalindrome(&q)){
        cout << "\n Merupakan Palindrome\n";
        cout << "================================================\n";

    } else {
        cout << "\nBukan merupakan Palindrome\n";
        cout << "================================================\n";

    }

    member();
    return 0;
}
