class Solution:
    def romanToInt(self, s: str) -> int:
        table = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000,
            'IV': 4,
            'IX': 9,
            'XL': 40,
            'XC': 90,
            'CD': 400,
            'CM': 900,
        }
        return helper(s, table)

def helper(s, table):
    result = 0
    i = 0
    while i < len(s):
        if look_ahead(s[i], s, i):
            char = s[i:i+2]
            if char in table:
                result += table[char]
                i+=2
                continue
        char = s[i]
        result += table[char]
        i+=1
    return result

                            
def look_ahead(char, s, ind):
    if char in ['I', 'X', 'C']:
        if ind+1 <= len(s)-1:
            return True
    return False
