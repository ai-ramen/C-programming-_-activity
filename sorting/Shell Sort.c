#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define SIZE 5

typedef struct {
   int elem[SIZE];
   int lastNdx;  
}Heap;


void ShellSort(Heap *H);
void displayList(Heap H);
void insertionSort(Heap *H,int gap);

int main()
{
	Heap H;
//	int x,elem[SIZE]={4,9,10,12,18,7,5,2,3,11,6};
	int x,elem[SIZE]={4,9,10,2,18};
	
	H.lastNdx=-1;
	for(x=0;x<SIZE;x++){
		H.elem[x]=elem[x];
		H.lastNdx++;
	}

	displayList(H);
	
	
	ShellSort(&H);
	puts("\nShell Sort");
	displayList(H);
	
}


void ShellSort(Heap *H)
{
	int x;
	for(x=(H->lastNdx)/2;x>0;x/=2){
		insertionSort(H,x);
	}
}

void insertionSort(Heap *H,int gap)
{
	int x,y,key;
	
	for(x=gap;x<=H->lastNdx;x++){
		key=H->elem[x];
		for(y=x-gap;y>=0&&H->elem[y]>key;y-=gap){
			H->elem[y+gap]=H->elem[y];		
		}
		H->elem[y+gap]=key;		
	}
}

void displayList(Heap H)
{
	int x;
	for(x=0;x<=H.lastNdx;x++){
		printf("%d,",H.elem[x]);
	}
}

