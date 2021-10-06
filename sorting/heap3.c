#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define SIZE 11

typedef struct {
   int elem[SIZE];
   int lastNdx;  
}List,Heap;


void maxHeapSort(Heap *H);
int deleteMin(Heap *H);
void swap(int *a,int *b);
void insert(Heap *H, int elem);
void displayList(Heap H);

int main()
{
	List L;
	Heap H;
	int x,elem[SIZE]={2,3,9,6,4,9,10,10,18,7,5};
	
	H.lastNdx=-1;
	for(x=0;x<SIZE;x++){
		H.elem[x]=elem[x];
		H.lastNdx++;
	}
	
	displayList(H);
	
	
	maxHeapSort(&H);
	puts("\nmaxHeapSort");
	displayList(H);
	puts("\n");
	
	
}


void maxHeapSort(Heap *H)
{
	int x,temp,oldLast;
	
	oldLast=H->lastNdx;
	
	H->lastNdx=-1;
	
	//Insert all elements in an initially empty POT.  
	for(x=0;x<=oldLast;x++){
		insert(H,H->elem[x]);
	}
	
	//delete min until empty
	while(H->lastNdx!=-1){
		temp=deleteMin(H);
		H->elem[H->lastNdx+1]=temp;
	}
	
	H->lastNdx=oldLast;
}



int deleteMin(Heap *H)
{
	int child,parent,ret;
	ret=H->elem[0];
	H->elem[0]=H->elem[H->lastNdx--];

	parent=0;
	child=1;
	
	while(child<=H->lastNdx){
		if((child+1)<=H->lastNdx&&H->elem[child]>H->elem[child+1]){
			child++;
		}
		
		if(H->elem[child]<H->elem[parent]){
			swap(&H->elem[child],&H->elem[parent]);
		}
		parent=child;
		child=2*parent+1;
	}
	return ret;
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
