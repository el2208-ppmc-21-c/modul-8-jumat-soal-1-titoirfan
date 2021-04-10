/*EL2208 Praktikum Pemecahan Masalah dengan C 2020/2021
*Modul            : 8
*Percobaan        : -
*Hari dan Tanggal : -
*Nama (NIM)       : -
*Asisten (NIM)    : -
*Nama File        : -
*Deskripsi        : -
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Node{//tipe data node
    int data;
    struct Node *next;
};

void getvertex(int *vertex,FILE* fp){//fungsi untuk mengambil banyak vertex pada file
    char temp[10];
    int baris;

    fgets(temp, sizeof(temp), fp);
	sscanf(temp, "%d", &baris);
	*vertex=baris;

}

void generatematriks(int vertex, int matriks[vertex][vertex], FILE* fp){//fungsi untuk membuat matriks dari graph
    int i,j;
    char temp[20];
    char* token;

	for(j=0; j<vertex ; j++){
		fgets(temp, sizeof(temp), fp);//baca baris
		i=0;
		token=strtok(temp,",");//pisahkan data
		while(token!=NULL){
            matriks[j][i] = atoi(token);//ubah menjadi integer dan masukkan ke array
            i+=1;
            token=strtok(NULL,",");
		}
	}

}


void ishamiltonpath(int NODE,int graph[NODE][NODE], struct Node* travel, int visit[NODE]){
    //isi dengan kode anda
}

int main(){
    char filename [10];
    FILE *fp;

    printf("Masukkan nama file : ");//input nama file
	gets(filename);
	fp = fopen( filename, "r");

    getvertex(&NODE,fp);//ambil jumlah bertex

    int graph[NODE][NODE];

    generatematriks(NODE, graph, fp);//buat matriks

    fclose(fp);

    printf("Hamilton Path: ");
    ishamiltonpath(...);
    return 0;
}
