median of two sorted arrays
//the ideas here is 
//1. we use merge sort A and B. find the middle of the new Array and cal median.the time complexcity is O(m+n)
// 2. if we need to improve the O(m+n),we can easily come up with binary search, which throws half of the array each time. the time complexcity is O(log(n))
// since we need to find kth element, we compare A[k/2] and B[k/2]
// 1. A[k/2] < B[k/2], throw A[0] - A[k/2]
// 2. A[k/2] > B[k/2], throw B[0] - B[k/2]
// we know kth elment must be in the k - k/2 

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int index = m + n;
        if(index % 2 == 0){
            return (findKth(A, m, B, n, (index / 2) + 1) + findKth(A, m, B, n, index / 2)) / 2.0;
        }
        else{
            return findKth(A, m, B, n, (index / 2)+ 1);
        }
    }
        // find kth 
        int findKth(int A[], int m, int B[], int n, int k){
            if(m > n) return findKth(B, n, A, m, k); // make sure m is less than n
            if(m == 0) return B[k -1]; // A is NULL, find kth in B
            if(k == 1) return min(A[0], B[0]); // compapare the first element in each array
            
            // divide k into two parts
            int a = min(k/2, m); // remember to check m and k/2
            int b = k - a;
            if(A[a-1] < B[b-1]){ // A is 
                return findKth(A + a, m - a, B, n, k- a);
            }
            else {
                return findKth(A, m, B + b, n - b, k - b);
            }
        }
};