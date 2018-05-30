def game(n, scores):
    cost = dict()
    pi = dict()
    sub(n, scores, cost, pi)

    sol = []
    uniq = set()
    rprint(n, sol, pi, uniq)
    print(uniq)


def sub(n, scores, cost, pi):
    if n==0:
        return True
    if n<0:
        return False
    if n in cost:
        return cost[n]

    atLeastOnePath = False
    for x in scores:
        if sub(n-x, scores, cost, pi):
            atLeastOnePath = True
            if n not in pi:
                pi[n] = set()
            pi[n].add( n-x )
            
    cost[n] = atLeastOnePath
    return cost[n]
            
def rprint(n, sol, pi, uniq):
    if n==0:
        uniq.add( tuple( sorted(sol) ))
        return

    for x in pi[n]:
        sol.append( n-x )
        rprint(x, sol, pi, uniq)
        sol.pop()
        
                
n = 20
scores = [3,5,10]
game(n, scores)
