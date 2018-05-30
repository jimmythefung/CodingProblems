def rotateImage(a):
    rS = 0			# row start
    rE = len(a)-1	# row end
    cS = rS			# column start
    cE = rE			# column end

    while rE>rS:
        i = 0
        while i < rE-rS:
            t = a[rS+i][cE]           # B to temp
            a[rS+i][cE] = a[rS][cS+i] # A to B
            a[rS][cS+i] = a[rE-i][cS] # D to A
            a[rE-i][cS] = a[rE][cE-i] # C to D
            a[rE][cE-i] = t           # temp to C
            i+=1
        rS+=1
        rE-=1
        cS+=1
        cE-=1
        
    return a

    


a = [[1, 2, 3],
     [4, 5, 6],
     [7, 8, 9]]
a = [[10,9,6,3,7], 
 [6,10,2,9,7], 
 [7,6,3,8,2], 
 [8,9,7,9,9], 
 [6,8,6,8,2]]

print("Input")
for r in a:
    print(r)
    
rotateImage(a)

print("\nOutput")
for r in a:
    print(r)
