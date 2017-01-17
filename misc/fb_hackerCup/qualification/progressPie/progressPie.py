import math

def getDegrees(x,y):
    rad = math.acos(x / math.sqrt((x**2+y**2)))
    deg = rad*360/(2*math.pi)
    if (x<=0 and y<=0) or (x>=0 and y<=0):
        deg = 360 - deg

    # Return clockwised angle
    return ((-deg+360)+90)%360

def getColor(percent, x, y):
    # center the circle at origin
    x = float(x)-50
    y = float(y)-50
    if x==0 and y==0:
        return "black"
    
    # polar coordinate of progress pie
    r = 50
    deg = float(percent)/100*360

    # polar coordinate of point p
    p_r = math.sqrt((x**2+y**2))
    p_deg = getDegrees(x,y)

    if p_r < r and p_deg < deg:
        return "black"
    else:
        return "white"

def readFromStdin():
    n = int(raw_input())
    for i in range(n):
        args = raw_input().strip().split(" ")
        print "Case #"+str(i+1)+":", getColor(float(args[0]), float(args[1]), float(args[2])) 

def readFromFile(fname):
    fin = open(fname, 'r')
    n = int(fin.readline())
    for i in range(n):
        args = fin.readline().strip().split(" ")
        print "Case #"+str(i+1)+":", getColor(float(args[0]), float(args[1]), float(args[2]))     

if __name__ == "__main__":
    readFromStdin()
    #readFromFile("fbTests.txt")

        
