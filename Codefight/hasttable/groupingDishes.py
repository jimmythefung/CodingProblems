def groupingDishes(dishes):
    table = {}
    for entry in dishes:
        key = entry[0]
        value = entry[1:]
        table[key] = value

    reverseTable = {}
    for dish, ingreds in table.items():
        for i in ingreds:
            reverseTable.setdefault(i, set()).add( dish )

    # Construct result lexicographically sorted
    result = []
    for k in sorted(reverseTable.keys()):
        entry = [k] + sorted( reverseTable[k] )
        if len(entry) > 2: # solution only care an ingredient maps to multiples dishes
            result.append( entry )

    return result

dishes = [["Salad", "Tomato", "Cucumber", "Salad", "Sauce"],
            ["Pizza", "Tomato", "Sausage", "Sauce", "Dough"],
            ["Quesadilla", "Chicken", "Cheese", "Sauce"],
            ["Sandwich", "Salad", "Bread", "Tomato", "Cheese"]]

r = groupingDishes(dishes)
for e in r:
    print(e)
