def nonOverLap(s):
    i=1
    final_solution_set = []
    while i < len(s):
        sL = s[0:i]
        sR = s[i:]
        solution_set = solve(sR)
        for a_solution in solution_set:
            newSolution = [sL] + a_solution
            final_solution_set = final_solution_set + [newSolution]
        i+=1
        
    last_solution = [s]
    final_solution_set += [last_solution]
    return final_solution_set

def solve(s):
    if len(s)==1:
        a_solution = [s[0]]
        return [a_solution]

    solution_set = solve(s[1:])
    solution_set_new = []
    for a_solution in solution_set:
        newSolution = [s[0]] + a_solution
        solution_set_new = solution_set_new + [newSolution]

    last_solution = [s]
    solution_set_new += [last_solution]
    return solution_set_new

def AtoS(A):
    s=""
    for i in A:
        s=s+str(i)
    return s

def printNonOverLap(solution_set):
    for solution in solution_set:
        for e in solution:
            print "("+e+")",
        print ""

def main():
    A = [1,2,3,4,5]
    s = AtoS(A)
    solution_set = nonOverLap(s)
    printNonOverLap(solution_set)

if __name__ == "__main__":
    main()
