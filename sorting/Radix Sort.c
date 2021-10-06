#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define SIZE 7

typedef struct {
   int elem[SIZE];
   int lastNdx;  
}Heap;


void RadixSort(Heap *H);
int findMax(Heap *H);
void displayList(Heap H);

int main()
{
	Heap H;
//	int x,elem[SIZE]={4,9,10,12,18,7,5,2,3,11,6};
	int x,elem[SIZE]={573, 25, 415, 12, 161, 6,18};
	
	H.lastNdx=-1;
	for(x=0;x<SIZE;x++){
		H.elem[x]=elem[x];
		H.lastNdx++;
	}

	displayList(H);
	
	
	RadixSort(&H);
	puts("\nRadix Sort");
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

void RadixSort(Heap *H)
{
	int m,x,y,z,max,temp[SIZE],rad[SIZE];
	max=findMax(H);
	m=1;//Šî”‚ğæ‚èo‚·Œ…
	
	while(m<=max){
		for(x=0;x<=H->lastNdx;x++){
			rad[x]=(H->elem[x]/m)%10;/* Šî”‚ğæ‚èo‚µ rad[i] ‚É•Û‘¶ */
		}
		z=0;
		for(x=0;x<=9;x++){
			for(y=0;y<=H->lastNdx;y++){
				if(rad[y]==x){
					temp[z++]=H->elem[y];
				}
			}
		}
		memcpy(H->elem,temp,sizeof(int)*SIZE);
		m*=10;
	} 
	
	
	
}

void displayList(Heap H)
{
	int x;
	for(x=0;x<=H.lastNdx;x++){
		printf("%d,",H.elem[x]);
	}
}

