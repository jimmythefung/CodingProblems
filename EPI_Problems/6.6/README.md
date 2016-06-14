## Buy and Sell a Stock Once  
Straght forward O(n) complexity, O(1) space implementation exists. Usually arrived at after gaining the insight from trying out divide and conqure.  
The insight is that keeping track of the minimum seen so far and the best profit obtained so far will yield answer in 1 pass of input.  

## Reference note: this relates to the CLRS's section 4.1, p.68, "The maximum subarray problem".  
Although not the simpler solution, this is a good exercise to review divide and conqure technique, and solving continous valued liked problems.
The Maximum subarray problem is about finding the greatest sum in a continous interval of a subarray.  
**The solution of greatest sum is only relavent** when the prices of stocks each day are converted to delta of prices, and so the input become the latter.  

