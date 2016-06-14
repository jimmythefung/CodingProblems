# The Dutch National Flag Problem  
The Dutch national flag problem is about a modification to the "PARTITION(A, p, r)" routine used in quicksort, so that pivot values are always preceeded by elements smaller than pivots.  
(PARTITION() does not require so - elements equal or smaller than pivot just have to preceed elements bigger than pivot).

So a partition(), quicksort(), swap() are first implemented as review/warm up.  
Then a **dutchPartition()** is implemented.

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

## dutchPartition(A, pivot_index)  
Brute force:  
1. O(n) space O(n) time - Do two pass: first pass move all less-than elements, second pass move all greater-than elements.  
2. O(1) space O(n^2) time - use nested iteration similar to insertion sort to swap elements into regions.  

**O(n) time, O(1) space - idea:**  
Any partitioning related problem generally manages work according to "regions".  

In PARTITION given by CLRS, there are 3 regions: A = [ (less than pivot)--> (greater than pivot)--> (to be checked) ].  
  
In EPI, the author suggests checked regions be grow from the ends: A = [(less than pivot)--> (to be checked) <--(greater pivot)].  
In either case, two indice (i.e. i, j) are needed to keep track of the boundaries.  
  
For the dutch partition, there are 3 insights:  
    1. Trying to manage elements=pivot using hueristic movements, while keeping 3 regions, doesn't work.  
    2. Use 4 regions A = [(less than pivot) --> (to be checked) <-- (equal to pivot) <-- (greater than pivot)]  
    3. Consequently  Use 3 indice to keep track of boundaries.  

Loop Invariants (regions in array A):  
    - Less than pivot:       [0 to i]  
    - Unclassified:          [i+1 to j-1]  
    - Equal to pivot:        [j to k]  
    - Greater than pivot:    [k+1 to A.size()-1]  
  
  
Note a stinky corner case where the given array A begins and end with the value of the pivot, the initialization of the "equal to pivot" region takes some careful treatment.  
See main.cpp
