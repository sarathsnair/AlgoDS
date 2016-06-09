/*
	Merge Sort - Divide and Conquer
	
	-> MergeSort is QuickSort's complement
	-> Complexity - nLogn
	
	
	Both Iterative and Recursive method given
	
*/

#include<stdio.h>
#define MAX 50

void display_array(int [], int);
void read_array(int [], int);
void merge_sort_recursion(int [],int, int);
void merge_sort_iterative(int [],int);
void merge(int [],int ,int , int);
int min(int,int);

int main(){
	int i,k,n,arr[MAX];
	printf("Enter the value of n : \t");
	scanf("%d",&n);
	printf("Enter the array : ");
	read_array(arr,n);	
	//merge_sort_recursion(arr,0,n-1);
	merge_sort_iterative(arr,n);
	display_array(arr,n);
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

void merge_sort_recursion(int array[],int low, int high){
	int mid;
	if(low<high){
		mid	= (low+high)/2;
		merge_sort_recursion(array,low,mid);
		merge_sort_recursion(array,mid+1,high);
		merge(array,low,mid,high);
	}
}

void merge_sort_iterative(int array[],int n){
	int curr_size, left_start;
	for(curr_size=1; curr_size<n; curr_size=curr_size*2){
		for(left_start=0;left_start<n;left_start+=2*curr_size){
			int mid = left_start+curr_size-1;
			int right_end = min(left_start+2*curr_size-1, n-1);
			merge(array,left_start,mid,right_end);
		}		
	}
}

void merge(int array[],int low, int mid, int high){
	int i, j, k;
	int n1 = mid-low+1;
	int n2 = high-mid;
	
	int L[n1], R[n2];
	
	for(i=0;i<n1;i++){
		L[i] = array[low+i];
	}
	for(j=0;j<n2;j++){
		R[j] = array[mid+j+1];
	}
	
	i=0,j=0,k=low;
	
	while(i<n1 && j<n2){
		if(L[i]<=R[j]){
			array[k] = L[i];
			i++;
		}
		else{
			array[k] = R[j];
			j++;
		}
		k++;
	}
	
	while(i<n1){
		array[k] = L[i];
		i++;
		k++;
	}
	while(j<n2){
		array[k] = R[j];
		j++;
		k++;
	}
	
}

int min(int a, int b){
	return (a<b)?a:b;
}