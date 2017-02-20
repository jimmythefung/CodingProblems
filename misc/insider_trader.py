def parse(data):
    lines = data.split("\n")
    output = []
    for line in lines:
        output.append(line)
    return output


def find_insider(datafeed):
    window = 3
    insiderAmount = 5000000
    insider = dict()
    flagSet = set()
    
    stock_prices = dict()
    transactions = dict()
    
    price_entrys = []
    transaction_entrys = []
    output = []
    
    for line in datafeed:
        line = line.split("|")
        if len(line) == 2:
            day = int(line[0])
            price = int(line[1])
            stock_prices[day] = price
            price_entrys.append([day, price])
        else:
            (day, trader, types, amount) = line
            day = int(day)
            amount = int(amount)
            transactions[day] = [day, trader, types, amount]
            transaction_entrys.append( [day, trader, types, amount] )
     
    for (today, today_price) in price_entrys:
        for previous_date in range(today-window, today):
            if previous_date in transactions:
                (day, trader, types, amount) = transactions[previous_date]
                if types == "BUY":              
                    for p_d in sorted(stock_prices):
                        if p_d <= previous_date:
                            previous_date = p_d

                    profit = (today_price - stock_prices[previous_date]) * amount
                    if profit >= insiderAmount:

                        # add to insider
                        if trader not in flagSet:
                            if day not in insider:
                                insider[day] = []
                            insider[day].append(trader)
                            flagSet.add(trader)


                if types == "SELL":
                    for p_d in sorted(stock_prices):
                        if p_d <= previous_date:
                            previous_date = p_d
                            break
                    prevented = (stock_prices[previous_date] - today_price) * amount
                    if prevented >= insiderAmount:
                        # add to insider
                        if trader not in flagSet:
                            if day not in insider:
                                insider[day] = []
                            insider[day].append(trader)
                            flagSet.add(trader)                            

        
    sortedDays = sorted(insider)
    for d in sortedDays:
        for t in sorted(insider[d]):
            output.append("|".join([str(d), str(t)]))
            
        
   

    return output


            
    
feed1 = """0|1000
0|Shilpa|BUY|30000
0|Will|BUY|50000
0|Tom|BUY|40000
0|Kristi|BUY|15000
1|Kristi|BUY|11000
1|Tom|BUY|1000
1|Will|BUY|19000
1|Shilpa|BUY|25000
2|1500
2|Will|SELL|7000
2|Shilpa|SELL|8000
2|Kristi|SELL|6000
2|Tom|SELL|9000
3|500
38|1000
78|Shilpa|BUY|30000
79|Kristi|BUY|60000
80|1100
81|1200"""
 
feed2 = """0|20
0|Kristi|SELL|3000
0|Will|BUY|5000
0|Tom|BUY|50000
0|Shilpa|BUY|1500
1|Tom|BUY|1500000
3|25
5|Shilpa|SELL|1500
8|Kristi|SELL|600000
9|Shilpa|BUY|500
10|15
11|5
14|Will|BUY|100000
15|Will|BUY|100000
16|Will|BUY|100000
17|25"""


print find_insider(parse(feed1))
print find_insider(parse(feed2))
