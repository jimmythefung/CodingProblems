class graph:
    V = []
    def __init__(self, *args):
        for vertice in args:
            self.V.append(vertice)
    def show(self):
        output = ""
        for v in self.V:
            print v

class node:
    visited  = 0
    name     = ""
    neighbor = []

    def __init__(self, vName):
        self.name = vName
    def __str__(self):
        output = self.name+": "
        for v in self.neighbor:
            output += v.name+" "
        return output
    

v1 = node("1")
v2 = node("2")
v3 = node("3")
v4 = node("4")
v5 = node("5")
v6 = node("6")
v1.neighbor = [v2,v5]
v2.neighbor = [v3,v5,v1]
v3.neighbor = [v4,v2]
v4.neighbor = [v3,v5,v6]
v5.neighbor = [v1,v2,v4]
v6.neighbor = [v4]

g = graph(v1,v2,v3,v4,v5,v6)
g.show()
