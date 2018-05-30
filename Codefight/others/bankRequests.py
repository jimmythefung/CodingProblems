def bankRequests(accounts, requests):
    requestNumber = 0
    for r in requests:
        requestNumber += 1
        instruction = parseRequest(r)
        if requestIsValid(instruction, accounts):
            processRequest(instruction, accounts)
        else:
            return [-1*requestNumber]
    return accounts

def processRequest(instruction, accounts):
    op = instruction[0]
    i = instruction[1]-1
    j = instruction[-2]-1
    amount = instruction[-1]
    if op=="transfer":
        accounts[i] -= amount
        accounts[j] += amount

    if op=="deposit":
        accounts[i] += amount

    if op=="withdraw":
        accounts[i] -= amount


def requestIsValid(instruction, accounts):
    op = instruction[0]
    
    # invalid account
    i = instruction[1]
    if i > len(accounts) or i < 1:
        return False
    if op=="transfer":
        j = instruction[-2]
        if j > len(accounts) or j < 1:
            return False

    # overdrawn
    if op=="transfer" or op=="withdraw":
        amount = instruction[-1]
        if accounts[i-1] < amount:
            return False

    return True
        
def parseRequest(r):
    instruction = r.split(" ")
    i = 1
    while i < len(instruction):
        instruction[i] = int( instruction[i] )
        i+=1
    return instruction

accounts = [10, 100, 20, 50, 30]
requests = ["withdraw 2 10", "transfer 5 1 20", "deposit 5 20", "transfer 3 4 15"]

##accounts = [20, 1000, 500, 40, 90]
##requests = ["deposit 3 400", "transfer 1 2 30", "withdraw 4 50"]

print(accounts)
accounts = bankRequests(accounts, requests)
print(accounts)
