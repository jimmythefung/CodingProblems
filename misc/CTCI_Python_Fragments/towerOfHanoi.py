def moveTower(src, dst, hlp, n):
    if n==1:
        dst.append(src.pop())
        return

    moveTower(src, hlp, dst, n-1)
    print "tower A", A
    print "tower B", B
    print "tower C", C
    print ""
    moveTower(src, dst, hlp, 1)
    print "tower A", A
    print "tower B", B
    print "tower C", C
    print ""
    moveTower(hlp, dst, src, n-1)
    print "tower A", A
    print "tower B", B
    print "tower C", C
    print ""





n = 5
A = []
B = []
C = []

i=n
while i != 0:
    A.append(i)
    i = i - 1

print "tower A", A
print "tower B", B
print "tower C", C

print "moving tower of size n =", n
moveTower(A,B,C, len(A))

print "tower A", A
print "tower B", B
print "tower C", C
