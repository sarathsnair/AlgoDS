/*Insertion sort

	In-Place sorting algorithm
	Easy to implement
	Stable sort - Maintains relative order of input data if the keys are same
	Online - insertion sort can sort the list as it receives it
	
	Worst case - O(n2)
	Average case - O(n2)
	Best case - O(n2)
*/


#include<stdio.h>

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

void insertion_sort(int array[],int n){
	int i,j,ele;
	for(i=1;i<n;i++){
		ele = array[i];
		j=i;
		while(j>0 && array[j-1] > ele){
			array[j]= array[j-1];
			j--;
		}
		
		array[j] = ele;
	}
}

int main(){
	int i,k,n,arr[50];
	printf("Enter the value of n : \t");
	scanf("%d",&n);
	printf("Enter the array : ");
	read_array(arr,n);	
	insertion_sort(arr,n);
	display_array(arr,n);
}