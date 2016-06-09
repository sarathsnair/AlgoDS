/*
	Bubble Sort
	
	Best Case - O(n) {If the array is already sorted}
	Average Case - O(n2)
	Worst Case - O(n2)
	
	Basic bubble sort algorithm can be improved by adding a flag. Which cause the inner loop to stop when the input
	array is already sorted.
*/

#include <stdio.h>


void swap(int *a, int *b){
	int temp;
	temp = *a;
	*a=*b;
	*b=temp;
}

void display_array(int array[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d\t",array[i]);
	}
}

void read_array(int array[],int n){
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&array[i]);
	}
}


void bubble_sort(int array[], int n){
	int i, k;
	for(i=0;i<n-1;i++){
		for(k=0;k<n-i-1;k++){
			if(array[k]>array[k+1]){
				swap(&array[k],&array[k+1]);
			}
		}
	}
}

void bubble_sort_optimized(int array[], int n){
	int i, k,_flag=1;
	for(i=0;i<n-1;i++){
		_flag=0;
		for(k=0;k<n-i-1;k++){
			if(array[k]>array[k+1]){
				swap(&array[k],&array[k+1]);
				_flag=1;
			}
		}
		
		if(_flag==0)
			break;
	}
}

int main(void) {
	int arr[10],n,i,temp,k;
	scanf("%d",&n);
	read_array(arr,n);
	bubble_sort_optimized(arr,n);
	display_array(arr,n);	
	return 0;
}
