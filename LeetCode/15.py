def threeSumHelper(arr, mySum, depth, solution):
    for i in range(len(arr)):
        pick = arr[i]
        new_arr = arr[:i]+arr[i+1:]
        mySum += pick
        
        if depth==3:
            s = []
            s.append(pick)
            return s if mySum==0 else []
        else:
            s = threeSumHelper(new_arr, mySum, depth+1, solution)
            if len(s)==0:
                return []
            else:
                s.append(pick)
                if depth!=1:
                    return s
                else:
                    solution.append(s)
def threeSum(arr):
    solution = []
    s = threeSumHelper(arr, 0, 1, solution)
    print solution

S = [-1, 0, 1, 2, -1, -4]
threeSum(S)
            
