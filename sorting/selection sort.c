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
void selectionSort(Heap *H);
void swap(int *a,int *b);

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
	
	
	selectionSort(&H);
	puts("\nSelection Sort");
	displayList(H);
	
}

void selectionSort(Heap *H)
{
	int x,y,min;
	
	for(x=0;x<H->lastNdx;x++){
		min=x;
		for(y=x+1;y<=H->lastNdx;y++){
			if(H->elem[min]>H->elem[y]){
				min=y;
			}
		}
		swap(&H->elem[min],&H->elem[x]);
	}
}

void displayList(Heap H)
{
	int x;
	for(x=0;x<=H.lastNdx;x++){
		printf("%d,",H.elem[x]);
	}
}

void swap(int *a,int *b)
{
	int swap;
	swap=*a;
	*a=*b;
	*b=swap;
}

