def grocery_cost(food_list, user_stock, prices):
    total = 0 # running sum of the cost of items purchased
    
    from datetime import datetime # gives date/time for receipt
    
    grocery_list = food_list
    
    # build receipt and cost simultaneously
    print('\n'*4)
    print('-'*50)
    print('Thanks for shopping at Python Groceries!!\n\n')
    now = datetime.now()
    now = now.replace(microsecond=0)
    print(now)
    
    for item in grocery_list:
        price = prices[item]
        
        # if the amount the shopper wants is in stock
        if int(user_stock[item]) >= int(grocery_list[item]):
            i_total = price * int(grocery_list[item])
            total += price * int(grocery_list[item])
            user_stock[item] -= int(grocery_list[item])
    
        # if the store has stock, but not as much as wanted by shopper
        elif user_stock[item] > 0:
            print('Sorry, we only have', user_stock[item], 'of', item, 'in stock.')
            print('Those have been added to the cart.')
            grocery_list[item] = user_stock[item]
            i_total = price * grocery_list[item]
            total += price * grocery_list[item]
            user_stock[item] -= grocery_list[item]
        
        # if there is no stock
        else:
            print("Sorry, we don't have any", item, 'in stock.')
            i_total = 0
    
        print('%15s \t %12s \t %4.2f' % (item, grocery_list[item], i_total))
    
    # finish the receipt
    print('\nCart Total: \t\t\t $%5.3f' % total)
    tax = 0.008*total
    print('\n8%% Sales Tax: \t\t\t $%5.2f' % tax)
    final = total+tax
    print('\nTotal Bill: \t\t\t $%5.2f' % final)

    print('\n')
    print('-' * 50)
    return final

def stock_check(user_stock, size, prices):
    """Update groc_catalog after each purchase and create order requests for you
    buyers"""
    
    from datetime import datetime
    now = datetime.now()
    now = str(now.replace(microsecond=0))
    
    # write a text file to order more stock
    text_file = open('stock_update.txt', 'w')
    text_file.write(now)
    text_file.write('\n')
    
    for a in user_stock:
        if user_stock[a] < 5:
            text_file.write('%s is at %g, please reorder.\n' % (a, user_stock[a]))
    
    text_file.close()
    
    # update the groc_catalog
    update_catalog = open('groc_catalog.txt', 'w+')
    
    for b in user_stock:
        update_catalog.write('%s, %s, %g, %.2f \n' % (b, size[b], user_stock[b],prices[b]))
        update_catalog.close()
