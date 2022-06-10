#include <iostream>
#define MAX 5
using namespace std;

struct queue {
	int front, rear, data[MAX];
}q;

bool isFull() {
	return q.rear == MAX;
}

bool isEmpty() {
	return q.rear == 0;
}

void printqueue() {
	if (isEmpty()) {
    cout << " Antrian kosong "<<endl;
	}
	else {
		cout << "queque : ";
		for (int i = q.front; i < q.rear; i++)
			cout << q.data[i] << ((q.rear-1 == i) ? "" : ",");
		cout << endl;
  }
}

void enqueue() {
	if (isFull())
	{
		cout << " Antrian penuh ! "<<endl;
	}
	else {
		int data;
		cout << "Masukkan Data : ";cin >> data;
		q.data[q.rear] = data;
		q.rear++;
		cout << "Data ditambahkan\n";
		printqueue();
	}
}

void dequeue() {
	if (isEmpty())
	{
		cout << " Antrian kosong "<<endl;
	}
	else{
		cout << "Mengambil data \"" << q.data[q.front] << "\"..." << endl;
		for (int i = q.front; i < q.rear; i++)
			q.data[i] = q.data[i + 1];
		q.rear--;
		printqueue();
	}
}

int main() {
	int choose;
	do
	{
		cout << "==================\n"
			<< "   Menu \n"
			<< "====================\n"
			<< " 1. Menambahkan Data (Enqueue) \n"
			<< " 2. Mengambil Data (Dequeue) \n"
			<< " 3. Keluar \n\n"
			<< "======================\n"
			<< "Masukkan pilihan : "; cin >> choose;
		switch (choose)
		{
		case 1:
			enqueue();
			break;
		case 2:
			dequeue();
			break;
		default:
			cout << "Pilihan tidak tersedia";
			break;
		}
	} while (choose !=3);
	return 0;
}
