class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        return paren(n)
    
    
def paren(n):
    if n==0:
        return ['']
    
    elif n==1:
        return ['()']
    
    else:
        output = []
        sol = paren(n-1)
        i = 0
        while i < len(sol)-1:
            appendHelper(output, sol[i])
            i+=1

        # Last one is symmetric. (e.g. '()()')
        s = sol[i]
        output.append('('+s+')')
        output.append(s+'()')

        return output
    

def appendHelper(output, s):
    output.append('('+s+')')
    output.append(s+'()')
    output.append('()'+s)
    
