def houseRobber(nums):
    cache = {}
    return greedyRob(nums, 0, cache)

def greedyRob(arr, start, cache):
    # Base cases
    if start in cache:
        return cache[start]
    if start==len(arr)-1:
        return arr[-1]
    if start>len(arr)-1:
        return 0
    # Greedy algorithm idea:
    # Optimal solution either rob the next house, or, rob the current + next+1 house
    choice1 = greedyRob(arr, start+1, cache)
    choice2 = arr[start] + greedyRob(arr, start+2, cache)
    cache[start] = max(choice1, choice2)
    return cache[start]
    

nums = [1, 1, 1]
print(houseRobber(nums))
