#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int* generator(int );

main(){
	int num, i;
	printf("How many numbers do u want ?\n");
	scanf("%d", &num);
	int *p=generator(num);
	int *temp = p;
	for(i=0; i<num; i++){
		printf("%d ", *p++ );
	}
	free(temp);
}

int* generator(int n){
	int i, j;
	int *array = (int *)malloc(n*sizeof(int));
	srand(time(NULL));
	*(array)=rand()%11;
	for(i=1; i<n; i++){
		*(array+i)=rand()%11;
		for(j=0; j<i; j++){
			while( *(array+i) == *(array+j) ){
				*(array+i)=rand()%11;
			}
		}
	}
	return array;
}
