/* Selection Sort 
	In-place sorting algorithm (no additional space required)
	Easy to implement
	O(n2)
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

void selection_sort(int array[],int n){
	int i,j,min;
	for(i=0;i<n;i++){
		min = i;
		for(j=i+1;j<n;j++){
			if(array[j]<array[min])
				min = j;
		}
		swap(&array[i],&array[min]);
	}
}

int main(void) {
	int i,k,n,arr[50];
	printf("Enter the value of n : \t");
	scanf("%d",&n);
	printf("Enter the array : ");
	read_array(arr,n);
	selection_sort(arr,n);
	display_array(arr,n);
	return 0;
}
