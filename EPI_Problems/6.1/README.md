# The Dutch National Flag Problem  

The solution involves "pivoting" in a fashion similar to that used in quicksort.
So a quicksort is first implemented as review/warm up.  

## A review of Qicksort from CLRS (Chapter 7.1) - average complexity: O(nlogn)  
QUICKSORT(A, p, r)
```
if p < r
    q = PARTITION(A, p, r)
    QUICKSORT(A, p, q-1)
    QUICKSORT(A, q+1, r)

```

## PARTITION()  
The partition() does the heavy lifting. The idea is to maintain 3 regions:  
    1. left most region of array A contains elements smaller than pivot (defined to be x=A[r])
    2. followed by region contains elements bigger than pivot
    3. followed by region contains elements of yet to be compared to x  

Given an index k, p (begining of array), and r (end of array):  
Region 1 is bounded by k <= i  
Region 2 is bounded by i < k < j  
Region 3 is bounded by j < k  

PARTITION(A, p, r)  
```
x = A[r]
i = p-1
for j= p to r-1
    if A[j] <= x
        i = i + 1
        exchange A[i] with A[j]
exchange A[i+1] with A[j]
return i+1
```
