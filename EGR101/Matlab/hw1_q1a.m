clc
clear
home

t = 120000;
p = 110000; %setting variables
r = .0325;
y1 = 15; %different years
y2 = 30;
m1 = (p*(r/12))/(1-(1+(r/12))^(-12*y1)); %different equations for different years
m2 = (p*(r/12))/(1-(1+(r/12))^(-12*y2));
t1 = m1*(y1*12);
t2 = m2*(y2*12);
d1 = t1-p;
d2 = t2-p;

fprintf('For a %g year payment plan on a $%g principal loan at 3.25%% interest, the monthly payment will be $%f',y1, p, m1)
disp(' ') % determining outputs
fprintf('The total cost of the loan is %f which is %f more than your principal',t1,d1)
disp(' ')
fprintf('For a %g year payment plan on a $%g principal loan at 3.25%% interest, the monthly payment will be $%f',y2, p, m2)
disp(' ')
fprintf('The total cost of the loan is %f which is %f more than your principal',t2,d2)
disp(' ')