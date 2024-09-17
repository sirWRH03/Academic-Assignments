clc
clear
home

total = input("whats the total cost of the house? ");
downPayment = input("what's the down payment? ");
p = total - downPayment;
interest = input("what is your interest rate (in percent form)? ");
r = interest/100;
paymentPeriod = input("what is your payment period in years? ");
y = paymentPeriod;
yM = paymentPeriod*12;
months = paymentPeriod * 12;
m = (p*(r/12))/(1-(1+(r/12))^(-12*y));
t = m * yM;
d = t-p;

fprintf('For a %g year payment plan on a $%g principal loan at 3.25%% interest, the monthly payment will be $%f',y, p, m)
disp(' ') % determining outputs
fprintf('The total cost of the loan is %f which is %f more than your principal',t,d)
disp(' ')