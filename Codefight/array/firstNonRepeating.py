def firstNotRepeatingCharacter(s):
    sExist = set()
    sDup = set()
    rep = dict()

    for ind, val in enumerate(s):
        # Construct representation of an element - using its index
        if val not in rep:
            rep[val] = ind

        # Construct existence and duplication sets
        if rep[val] not in sExist:
            sExist.add( rep[val] )
        else:
            sDup.add( rep[val] )

    # Reduce element with unique occurances
    sUnique = sExist.difference( sDup )

    if len( sUnique ) > 0:
        print( sorted( sUnique ) )
        return s[sorted( sUnique )[0]]
    else:
        return "_"


s = "abacabad"
print( firstNotRepeatingCharacter(s) )
