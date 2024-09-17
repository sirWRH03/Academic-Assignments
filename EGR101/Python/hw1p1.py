## Will Humphrey
# EGR 101
# Homework 1
# Problem 1\

#introduction message
print('Thank you for useing Charger Vehicle Rental! If you would like to calculate your price, please fill out the following information. \nNote: Tax is not initially calculated into the price. This can be done at the end of the calculation.')
#input statements for the different information required
carType = input('What type of car did you rent? \nPlease type C for compact, M for midsize, L for luxury, S for SUV, or V for van: \n')
daysRented = int(input('How many days was the car rented? \n'))
odometerStart = int(input('What was the odometer reading at the start of the trip? \n'))
odometerFinish = int(input('What was the odometer reading at the end of the trip? \n'))

#makes the car type lowercase nomatter what so that the code will read it
carType = carType.lower()

#print statement to let the user know that there is cleaning fees.
print("Note: Each type of car has a $20.00 cleaning fee. SUV's are an exception and have a fee of $40.00. This fee is calculated into your price.\n")

if carType == 'c': # fee calculation for the compact car
    fee = 20.00 + ((20.00 * daysRented) + (0.25 * (odometerFinish - odometerStart)))
    print('Your final price will be: \n$' + str(fee)) # print statement
elif carType == 'm': # fee calculation for the mid-size car
    fee = 20.00 + ((29.50 * daysRented) + (0.29 * (odometerFinish - odometerStart)))
    print('Your final price will be: \n$' + str(fee)) # print statement
elif carType == 'l': # fee calculation for the luxury car
    fee = 20.00+ (( 44.25 * daysRented) + (0.48 * (odometerFinish - odometerStart)))
    print('Your final price will be: \n$' + str(fee)) # print statement
elif carType == 's': # fee calculation for suv's
    fee = 40.00+ ((40.00 * daysRented) + (0.53 * (odometerFinish - odometerStart)))
    print('Your final price will be: \n$' + str(fee)) # print statement
elif carType == 'v': # fee calculation for vans if the mileage is under 100 per day
    if ((odometerFinish - odometerStart)/daysRented) < 100:
        fee = 20.00 + (60 * daysRented)
        print('Your final price will be: \n$' + str(fee)) # print statement
    else: # fee calculation for vans if the mileage is over 100 perday
        fee = 20.00 + ((60.00 * daysRented) + (0.25 * (odometerFinish - odometerStart - 100)))
        print('Your final price will be: \n$' + str(fee)) # print statement

else:
    print("Please make sure you typed a valid car type!")
    
#i added this for funsies
calculateTax = input('Would you like to add tax to your calculation? Note: We use a 10% tax rate. (Y/N) ')

#if the user wants to calculate tax, you just find 10 percent of the price and add it to the price to get the price after tax
#i realize I could just multiply the total by 1.10, but i wanted the amount of tax to be shown.

if calculateTax.lower() == 'y':
    tax = fee * .10
    afterTax = fee + tax
    print('Your tax will be $' + str(tax) + '. Leaving your final price to be $' + str(afterTax) + '.')
    print('Thank you for using the Charger Vehicle Rental Price Calculator! Have a nice day!')
else:
    print('Thank you for using the Charger Vehicle Rental Price Clalculator! Have a nice day!')