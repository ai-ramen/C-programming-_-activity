#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define SIZE 11

typedef struct {
   int elem[SIZE];
   int lastNdx;  
}List,Heap;


void quickSort(Heap *H,int left,int right);
int partition(Heap *H,int left,int right);
void displayList(Heap H);

int main()
{
	List L;
	Heap H;
	int x,elem[SIZE]={10,80,30,90,40,50,70,-1};
	
	H.lastNdx=-1;
	for(x=0;elem[x]!=-1;x++){
		H.elem[x]=elem[x];
		H.lastNdx++;
	}
	
	displayList(H);
	
	
	quickSort(&H,0,H.lastNdx);//leftmostIndex,rightmosrtIndex
	puts("\nQuickSort");
	displayList(H);
	puts("\n");
	
	
}

void swap(int *a,int *b)
{
	int swap;
	swap=*a;
	*a=*b;
	*b=swap;
}

void quickSort(Heap *H,int left,int right)
{
	int pivot;
	
	if(left<right){
		pivot=partition(H,left,right);
		quickSort(H,left,pivot-1);
		quickSort(H,pivot,right);
	}
}



int partition(Heap *H,int left,int right){
	int pivot,x,small;
	pivot = H->elem[right];
	
	for(x=small=left;x<right;x++){
		if(H->elem[x]<=pivot){
			swap(&H->elem[x],&H->elem[small++]);
		}
	}
	swap(&H->elem[small],&H->elem[right]);
	return small;//next pivot index
}

void displayList(Heap H)
{
	int x;
	for(x=0;x<=H.lastNdx;x++){
		printf("%d,",H.elem[x]);
	}
}

void insert(Heap *H, int elem)
{
	int child,parent;
	
	
	if(H->lastNdx<SIZE-1){
		child=++H->lastNdx;
		parent=(child-1)/2;
		
		while(child>0&&H->elem[parent]>elem){
			H->elem[child]=H->elem[parent];
			child=parent;
			parent=(child-1)/2;
		}
		H->elem[child]=elem;
	}
}
