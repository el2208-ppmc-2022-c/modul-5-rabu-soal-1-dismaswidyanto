/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 5 - Recursion
*Percobaan        : -
*Hari dan Tanggal : Rabu, 23 Maret 2022
*Nama (NIM)       : -
*Asisten (NIM)    : -
*Nama File        : soal-01.c
*Deskripsi        : -
*/

#include <stdio.h>
#include <stdlib.h>


int countRec(int uang, int hargaBaru, int hargaBekas, int *tahun);
int countGpu(int uang, int hargaBaru, int hargaBekas, int *tahun);

int main(){  

	int uang, hargaBaru, hargaBekas;
	int tahun = 0; 

	// user input
	printf("Masukkan jumlah uang: ");
	scanf("%d", &uang);
	printf("Masukkan harga beli 1 GPU: ");
	scanf("%d", &hargaBaru);
	printf("Masukkan harga jual 1 GPU: ");
	scanf("%d", &hargaBekas);

	// exit program jika harga baru > uang awal
	if (hargaBaru > uang){
		printf("\nUang awal harus lebih besar dari harga beli");
		return 0;
	}
	
	// exit program jika harga jual > harga baru
	if (hargaBekas > hargaBaru){
		printf("\nHarga beli harus lebih besar dari harga jual");
		return 0;
	}

	// panggil fungsi untuk menghitung gpu
	int gpu = countGpu(uang, hargaBaru, hargaBekas, &tahun);

	// print output
	printf("\nTotal GPU yang bisa dibeli: %d buah\n", gpu);
	printf("Waktu yang dibutuhkan: %d tahun", tahun);
}

int countGpu(int uang, int hargaBaru, int hargaBekas, int *tahun){
	int gpuCount = uang / hargaBaru;
	int sisaUang = (uang % hargaBaru) + gpuCount*hargaBekas; 

	// panggil fungsi rekursif
	return gpuCount + countRec(sisaUang, hargaBaru, hargaBekas, tahun); 
}


int countRec(int uang, int hargaBaru, int hargaBekas, int *tahun){ 
	// final state
	if (uang < hargaBaru){
		return 0;
	}
	
	// recursive state
	*tahun = *tahun + 2; 
	int gpuCount = uang / hargaBaru;
	int sisaUang = (uang % hargaBaru) + gpuCount*hargaBekas; 

	return gpuCount + countRec(sisaUang, hargaBaru, hargaBekas, tahun); 
}
