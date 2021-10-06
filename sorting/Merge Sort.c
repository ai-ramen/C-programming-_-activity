#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define SIZE 11

typedef struct {
   int elem[SIZE];
   int lastNdx;  
}List,Heap;


void mergeSort(Heap *H,int left,int num);
void merge(Heap *H,int left,int mid,int num);
void displayList(Heap H);

int main()
{
	List L;
	Heap H;
	int x,elem[SIZE]={38, 27, 43, 3, 9, 82, 10,-1};
	
	H.lastNdx=-1;
	for(x=0;elem[x]!=-1;x++){
		H.elem[x]=elem[x];
		H.lastNdx++;
	}
	
	displayList(H);
	
	
	mergeSort(&H,0,H.lastNdx);//leftmostIndex,rightmosrtIndex
	puts("\nQuickSort");
	displayList(H);
	puts("\n");
	
	
}


void mergeSort(Heap *H,int left,int right)
{
	int mid;

	if(left<right){
		mid=left + (right-left)/2;
		
		mergeSort(H,left,mid);
		mergeSort(H,mid+1,right);
		
		merge(H,left,mid,right);
	}
}

void merge(Heap *H,int l,int m,int r)
{
	int x,y,z,L[SIZE],R[SIZE];
	int n1,n2;
	n1=m-l+1;
	n2=r-m;

    /* Copy data to temp arrays L[] and R[] */
    memcpy(L,H->elem+l,sizeof(int)*n1);
    memcpy(R,H->elem+m+1,sizeof(int)*n2);  
	
    z=l;
    for(x=y=0;x<n1&&y<n2;){
        if(L[x]<=R[y]){
            H->elem[z++]=L[x++];
        }else{
            H->elem[z++]=R[y++];
        }
    }
    
    if(x<n1){
        memcpy(H->elem+z,L+x,sizeof(int)*(n1-x));
    }else{
        memcpy(H->elem+z,R+y,sizeof(int)*(n2-y));
    }
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
