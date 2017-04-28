def binarySearch(arr, start, end, t):
##    # for regular search, return index
##    if start > end:
##        return -1
##    if start == end:
##        if arr[start] == t:
##            return start
##        else:
##            return -1
    
    # return index left to target, if not found
    if start >= end:
        return end

    m = (end-start)/2 + start

    if arr[m] == t:
        return m
    elif t < arr[m]:
        return binarySearch(arr, start, m-1, t)
    else:
        return binarySearch(arr, m+1, end, t)

def getMed(arr):
    ind = len(arr)/2
    if len(arr)%2==1:
        return arr[ind]
    else:
        return (float(arr[ind-1]) + float(arr[ind]))/2 
        

# arr1 is longer than arr2 and they are disjointed range
def case1(arr1, arr2):
    # arr1 must be longer than arr2
    a = len(arr1)-1
    b = len(arr2)-1

    if b > a:
        return case1(arr2, arr1)

    delta = a-b

    if delta == 0:
        return getMed([arr1[a], arr2[0]])
    else:
        return getMed(arr1[a-delta+1:])

# arr1 is longer than arr2 and they are overlapped on oppose ends
# arr1 = [1, 3, 5, 7, 9]
# arr2 = [6, 8, 10]
def case2(arr1, arr2):
    l1 = len(arr1)-1
    l2 = len(arr2)-1
    end = binarySearch(arr1, 0, len(arr1)-1, arr2[0])

    delta = l1 - end
    ejectLeft = arr1[end:]
    ejectRight = arr2[delta:]

    print delta, ejectLeft, ejectRight



def merge(arr1, arr2):
    i = 0
    j = 0
    result = []
    while i < len(arr1) and j < len(arr2):
        if arr1[i] > arr2[j]:
            result.append(arr2[j])
            j = j + 1
        else:
            result.append(arr1[i])
            i = i + 1

    if i < len(arr1):
        while i < len(arr1):
            result.append(arr1[i])
            i = i + 1
    else:
        while j < len(arr2):
            result.append(arr2[j])
            j = j + 1
    return result
        
            
    


def median(arr1, arr2):
    a1_start = arr1[0]
    a1_end = arr1[-1]
    a2_start = arr2[0]
    a2_end = arr2[-1]

    # case 1: disjoint arrays
    if a2_start > a1_end or a1_start > a2_end:
        pass


    # case 2: embedded
    elif a2_start > a1_start and a2_end < a1_end:
        pass

    
a1 = [2, 3, 4, 5, 6]
a2 = [7, 8]
b1 = [2, 3]
b2 = [7, 8]
c1 = [1, 2, 3, 5, 7, 9, 11, 13]
c2 = [8, 9, 10, 11, 12]

arr1 = [1, 3, 5, 7, 9]
arr2 = [6, 8, 10, 11]
case2(arr1, arr2)
print merge(arr1, arr2)
