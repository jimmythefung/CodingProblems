## Method 1: Brute force - O(n)
Iteratively examine and count set bit, then compute counts mod 2.

## Method 2: Bit manipulation O(s); s is number of set bits
Use y = x & ~(x - 1).  
1. This sets bit in y only at the position corresponding to the right most occurance of set bit in x.  
2. Then take the x = y XOR x, which removes the right most set bit in x.  
3. Repeat and count until all set bits in x are removed.  
