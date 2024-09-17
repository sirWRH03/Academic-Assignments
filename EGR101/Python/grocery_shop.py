from grocery_fun import grocery_cost, stock_check

stock = {}
prices = {}
size = {}
user_stock = {}

for line in open("groc_catalog.txt"):
    line = line.strip()
    parts = line.split(',')
    
    stock[parts[0]] = int(parts[2])
    prices[parts[0]] = float(parts[3])
    size[parts[0]] = parts[1]

print(stock)
print(prices)
print(size)
print(user_stock)

print('\n\nWelcome to Python Grocery Store! We offer the following items.')

for item in prices:
    print('%15s \t %12s \t $%4.2f' % (item, size[item], prices[item]))

print('\n')

user_stock.update(stock)

# Let a user order some groceries
groc = 0
groc_list = {} # keys = items purchased; values are the number purchased

while groc != 'done':
    groc = input('\nPlease enter an item to add to your cart or type done.')

    if groc != 'done':
        unit = input('\n how many ' + size[groc] + ' do you want?')
        groc_list[groc] = unit

    print(groc, unit)

grocery_cost(groc_list, stock, prices)
stock_check(user_stock, size, prices)
