def A(h):
    myMax = 0
    a = 0
    b = len(h)-1
    while a < b:
        if (b-a)*min(h[b], h[a]) > myMax:
            myMax = (b-a)*min(h[b], h[a])

        if h[b]>h[a]:
            a += 1
        else:
            b -= 1
    return myMax
