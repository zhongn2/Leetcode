#include <iostream>
#include <iterator>
#include <vector>
#include <stdlib.h>
#include <cstdlib>



// selection srot
void selectionSort(int unsort[], int n){
	for(int i = 0; i < n; i ++){
		int min = unsort[i];
		int min_index = i;// record the position for swapping
		for(int j = i; j < n; j++){
			if( min > unsort[j]){
				min = unsort[j];
				min_index = j;
			}
		}
		// exchange the two values of i and min_index
		// in order to put the smallest number at front
		if(min_index!= i){
			int temp = unsort[i];
			unsort[i] = unsort[min_index];
			unsort[min_index] = temp;
		}
	}
}

// Time Complexity is O(n^2)
pseudocode:
for i= 0:n;
	for j =i:n;
	if (A[i] > A[j])
		swap( A[i], A[j]);

void BubbleSort(int unsort[], int n){
	for(int i = 0; i < n; i ++){// outer looper
		for( int j = 0; j < n-1-i; j ++){ // inner loop, the elements before
			if( unsort[j] > unsort[j+1]){
				// swap unsort[j] and unsort[j+1]
				int temp = unsort[j];
				unsort[j] = unsort[j+1];
				unsort[j+1] = temp;
			}
		}
	}
}
// to be continued 
// merge sort //insertion sort // quick sort - in place ??

void InsertionSort(int unsort[], int n){
	for(int i = 1; i < n; i ++){ // outter loop is to keep checking each int
		int value = unsort[i];
		int j = i - 1;
		while(j >= 0 && unsort[j] > value){ // compare each int with the formal ordered list and insert into appriproate position
			unsort[j+1] = unsort[j];
			j --; // j -- stands for iterator from right to left
			unsort[j+1] = value;
		}
	}
}



// mergesort implemented here and make sure about the inputs
// sounds like the input is stupid

void merge(int unsorted[], int first, int mid, int last, int sorted[]){
	 int i = first, j = mid, k = 0;
	 while( i < mid && j < last){
		 if(unsorted[i] < unsorted[j])
			 sorted[k++] = unsorted[i++]; // sort[k] = unsorted[j]; k ++; j ++;
		 else
			 sorted[k++] = unsorted[j++];
	 }
	 while( i < mid)
		 sorted[k++] = unsorted[i++];
	 while( j < last)
		 sorted[k++] = unsorted[j++];
		 
	 for(int m = 0; m < k; m++)
		 unsorted[first + m] = sorted[m];
}

void Merge_Sort(int unsorted[], int first, int last, int sorted[]){
	if( last > first +1){
		int mid = (first + last) /2;
		Merge_Sort(unsorted, first, mid, sorted);
		Merge_Sort(unsorted, mid, last, sorted);
		merge(unsorted, first,mid, last, sorted);
	}
}

// find partition of the array
int partition(int unsorted[], int low, int high){
	int pivot = unsorted[low];
	while( low < high){
		while( (low < high) && (unsorted[high] > pivot)) high --;
		unsorted[low] = unsorted[high];
		while( (low < high) && ( unsorted[low] <= pivot)) low ++;
		unsorted[high] = unsorted[low];
	}
	unsorted[low] = pivot;
	return low;
}


void quick_sort(int unsorted[], int low, int high){
	int p;
	if( low < high){
		p = partition(unsorted, low, high);
		quick_sort(unsorted, low, p - 1);
		quick_sort(unsorted, p + 1, high);
	}
}


int main(){
	int unsorted[6] = {5,6,3,9,7,8};
	int sorted[6];
	//selectionSort(unsorted,7);
	//BubbleSort(unsorted, 7);
	//InsertionSort(unsorted,7);
	//Merge_Sort(unsorted,0, 6, sorted);
	quick_sort(unsorted,0,5);
	std::copy(unsorted, unsorted+6, std::ostream_iterator<int> (std::cout, " "));
	std::cin.get();
	return 0;
}
