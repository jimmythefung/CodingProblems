class Solution:
    def isPalindrome(self, x: int) -> bool:
        n = x
        if n < 0:
            return False
        elif n == 0:
            return True
        
        stack = []
        while n != 0:
            digit = n%10
            n = n//10
            stack.append(digit)
        
        left = 0
        right = len(stack) - 1
        while left <= right:
            if stack[left] != stack[right]:
                return False
            left += 1
            right -= 1
        return True
