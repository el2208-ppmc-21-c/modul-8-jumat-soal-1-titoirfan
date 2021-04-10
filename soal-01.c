/*EL2208 Praktikum Pemecahan Masalah dengan C 2020/2021
*Modul            : 8
*Percobaan        : -
*Hari dan Tanggal : Minggu, 4 April 2021
*Nama (NIM)       : -
*Asisten (NIM)    : Dismas Widyanto (13218065)
*Nama File        : -
*Deskripsi        : Program untuk mencari hamilton path pada suatu graph
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Node{//tipe data node
    int data;
    struct Node *next;
};

void getvertex(int  *vertex,FILE* fp){//fungsi untuk mengambil banyak vertex pada file
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

void push(struct Node** head,int data){// fungsi push
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));

    newnode->data=data;
    newnode->next=*head;

    *head=newnode;
}

void pop(struct Node** head){// fungsi pop
    struct Node* temp;

    if(*head==NULL){
        return;
    }
    else{
        temp=*head;
        temp=temp->next;
        free(*head);
        *head=temp;
    }
}

void enqueue(struct Node** head, int data){// fungsi enqueue
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));

    struct Node* temp=*head;//data baru
    newnode->data=data;
    newnode->next=NULL;

    if(*head == NULL){
        *head=newnode;
        return;
    }
    while(temp->next!= NULL){//traverse
        temp=temp->next;
    }
    temp->next=newnode;//tambahkan data baru ke queue
}

int count(struct Node* head){//fungsi untuk menghitung banyak data pada stack
    struct Node* temp=head;
    int jumlah=0;
    while(temp!=NULL){//traverse
        temp=temp->next;
        jumlah+=1;
    }
    return jumlah;//banyak data
}

void ishamiltonpath(int NODE,int graph[NODE][NODE], struct Node* travel, int visit[NODE]){
    struct Node* path;
    struct Node* current;
    int i=0;

    push(&path,0);

    while(path!=NULL){
        current->data=path->data;
        pop(&path);
        enqueue(&travel,current->data);
        visit[current->data]=1;


        if(count(travel)==NODE){
            while(travel!=NULL){
                printf("%d ",travel->data);
                travel=travel->next;
            }
        }

        for(int i=NODE-1;i>=0;i--){
            if(graph[current->data][i]==1 && visit[i]!=1){
                push(&path,i);
            }
        }
    }
}

int main(){
    int NODE;
    struct Node* hamiltonpath=NULL;
    char filename [20];

    FILE *fp;

    printf("Masukkan nama file : ");
	scanf("%s", filename);
	fp = fopen( filename, "r");

    getvertex(&NODE,fp);

    int graph[NODE][NODE];
    int visit[NODE], sol[NODE];
    for(int i=0;i<NODE;i++){
        visit[i]=0;
    }

    generatematriks(NODE, graph, fp);

    fclose(fp);

    printf("Hamilton Path: ");
    ishamiltonpath(NODE,graph,hamiltonpath,visit);
    return 0;
}
