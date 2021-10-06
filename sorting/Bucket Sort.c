#include<stdio.h>
#include<stdlib.h>

#define MAX 10

typedef struct cell{
	float elem;
	struct cell *link;
}*List;

typedef List Bucket[MAX];

void initBucket(Bucket A);
void insertBucket(Bucket A, float elem);
void displayBucket(float[15]);
int hash(int elem);
void bucketToArray(Bucket A,float[15]);

int main (void){
	
	Bucket A;
	int x;
	float elem[15]={9.8 , 0.6 , 10.1 , 1.9 , 3.07 , 3.04 , 5.0 , 8.0 , 4.8 , 7.68,-1};
	
	initBucket(A);
	
	for(x=0;elem[x]!=-1;x++){
		insertBucket(A,elem[x]);
	}
	
	bucketToArray(A,elem);

	displayBucket(elem);
	
	return 0;
}

int hash(int elem){
	return (elem>=10)?9:elem%10;
}

void initBucket(Bucket A){
	int x;
	for(x = 0; x < MAX; x++){
		A[x] =  NULL;
	}
}

void insertBucket(Bucket A, float elem){
	List temp, *trav;
	int ndx;
	
	ndx = hash(elem);
	
	for(trav=&A[ndx]; *trav!=NULL  && (*trav)->elem < elem; trav = &(*trav)->link){}
	
	
	if(*trav == NULL || (*trav)->elem!=elem){
		temp = (List)malloc(sizeof(struct cell));
		if(temp!=NULL){
			temp->elem = elem;
			temp->link = *trav;
			*trav = temp;
		}
	}
}

void displayBucket(float elem[15]){
	
	int x;
	for(x=0; elem[x]!=-1; x++){
		printf("%.1f\n",elem[x]);
	}
}

void bucketToArray(Bucket A,float elem[15])
{
	List *trav;
	int x,y=0;
	for(x=0; x<MAX; x++){
		for(trav=&A[x]; *trav!=NULL; trav=&(*trav)->link){
			elem[y++]= (*trav)->elem;
		}
	}
	elem[y]=-1;
}

