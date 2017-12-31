class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        return sumABC(nums)

def sumABC(arr):
    freq = build_frequency_map(arr)
    solutions = set()
    for c in arr: 
        freq[c] -= 1
        aplusb = -1*c   # Note: a + b = -c <=> a + b + c = 0
        solutions |= twoSum(freq, aplusb)
        freq[c] += 1
    return [list(item) for item in sorted(solutions)]

    
def twoSum(freq, target): # testVal + pickedVal = target
    solSet = set()
    for pickedVal in freq.keys():
        if freq[pickedVal] > 0: #because pickedVal could have been picked by twoSum's caller
            freq[pickedVal] -= 1
            testVal = target - pickedVal
            if (testVal in freq) and (freq[testVal]>0):
                zeroSumSol = tuple( sorted([pickedVal, testVal, -1*target]) )
                solSet.add(zeroSumSol)
            freq[pickedVal] += 1
    return solSet


def build_frequency_map(S):
    freq = dict()
    for item in S:
        if item not in freq:
            freq[item] = 1
        else:
            freq[item] += 1
    return freq
