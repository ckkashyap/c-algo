#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEFT_CHILD_INDEX(x) (((x+1)*2)-1)
#define RIGHT_CHILD_INDEX(x) (((x+1)*2))
#define PARENT_INDEX(x) ((int)(x/2))


void heapify(int *array, int i, int N) {
	int rci, lci, mini, temp;

	rci = RIGHT_CHILD_INDEX(i);
	lci = LEFT_CHILD_INDEX(i);

	mini=i;

	if (rci < N && array[i] >array[rci]) mini = rci;
	
	if (lci < N && array[mini] > array[lci]) mini = lci;
	
	if(mini != i) {
		temp = array[i];
		array[i] = array[mini];
		array[mini] = temp;
		heapify(array, mini, N);
	}
}

int buildHeap(int *array, int N) {
	int i;
	int n = (N / 2) - 1;
	for(i = n; i>= 0; i--)
		heapify(array, i, N);
}


int deleteMin(int *array, int N) {
	int v;
	v = array[0];
	array[0] = array[N-1];
	heapify(array,0, N-1);
	return v;
}

int main(int argc, char *argv[]) {
	int i,j;
	int arr[]={23,43,26,10,21,13,31,16,12,8,29,11,19,17};
	int N=sizeof(arr)/sizeof(int);
	buildHeap(arr,N);
	for(i=0;i<N;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	j=N;
	for(i=0;i<N;i++){
		printf("%d\n", deleteMin(arr, j));
		j--;
	}
	return 0;
}
