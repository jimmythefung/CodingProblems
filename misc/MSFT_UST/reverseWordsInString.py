def main():
    s = "to glory we cheer"
    print reverseWordInString(s)
    

def reverseWordInString(s):
    # Note in python s is immutable. Though we can work with array of string, list(s)
    s = s.split(" ")
    for i in range(len(s)):
        if s[i] != " ":
            s[i] = reverse(s[i])
    return " ".join(s)
            
def reverse(s):
    s = list(s)
    A = 0
    B = len(s)-1
    while A < B:
        t = s[B]
        s[B] = s[A]
        s[A] = t
        A = A+1
        B = B-1
    return "".join(s)
        

if __name__ == "__main__":
    main()
