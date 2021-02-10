class Solution:
    def intToRoman(self, num: int) -> str:
        table = {
            1   : 'I',
            5   : 'V',
            10  : 'X',
            50  : 'L',
            100 : 'C',
            500 : 'D',
            1000: 'M',
            
            4   : 'IV',
            9   : 'IX',
            40  : 'XL',
            90  : 'XC',
            400 : 'CD',
            900 : 'CM'
        }
        skeys=sorted(table, reverse=True)
        return helper(num, table, skeys)

def helper(num, table, skeys):
    if num==0:
        return ''
    b = extract_biggest(num, table, skeys)
    return table[b] + helper(num-b, table, skeys)

def extract_biggest(num, table, skeys):
    for b in skeys:
        if b <= num:
            return b
