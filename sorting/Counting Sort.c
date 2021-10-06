#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define SIZE 7

typedef struct {
   int elem[SIZE];
   int lastNdx;  
}Heap;


void CountSort(Heap *H);
int findMax(Heap *H);
void displayList(Heap H);

int main()
{
	Heap H;
//	int x,elem[SIZE]={4,9,10,12,18,7,5,2,3,11,6};
	int x,elem[SIZE]={1,4,1,2,7,5,2};
	
	H.lastNdx=-1;
	for(x=0;x<SIZE;x++){
		H.elem[x]=elem[x];
		H.lastNdx++;
	}

	displayList(H);
	
	
	CountSort(&H);
	puts("\nCount Sort");
	displayList(H);
	
}

int findMax(Heap *H)
{
	int ret=H->elem[0],x;
	for(x=1;x<=H->lastNdx;x++){
		if(H->elem[x]>ret){
			ret=H->elem[x];
		}
	}
	return ret;
}

void CountSort(Heap *H)
{
	int x,y,max,temp[10],result[SIZE];
	
	max=findMax(H);
	
	// Initialize count array with all zeros.
	for (x=0;x<=max;x++) {
    	temp[x]=0;
	}
	
	// Store the count of each element
	for(x=0;x<SIZE;x++){
		temp[H->elem[x]]++;
	}
	
	//modify the count array by adding the previous counts
	for(x=1;x<=max;x++){
		temp[x]+=temp[x-1];
	}
	
	// Find the index of each element of the original array in count array, and
	// place the elements in output array	
	for(x=0;x<=H->lastNdx;x++){
		result[temp[H->elem[x]]-1]=H->elem[x];
		temp[H->elem[x]]--;
	}
	
	memcpy(H->elem,result,sizeof(int)*SIZE);
}


void displayList(Heap H)
{
	int x;
	for(x=0;x<=H.lastNdx;x++){
		printf("%d,",H.elem[x]);
	}
}

