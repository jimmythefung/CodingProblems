def containsDuplicates(a):
    s = set()
    for x in a:
        if x in s:
            return True
        else:
            s.add(x)
    return False
    
