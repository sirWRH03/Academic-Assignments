clc
clear
home

sum = 1;
integer = 1; %all variables account for the positive integer 1
terms = 1;

while sum < 5000000 %loop that establishes the endpoint of the program
    integer = integer + 2; %odd integer + 2 = odd integer
    sum = sum + integer^2; %updates the sum by adding the square of an integer
    terms = terms + 1; %accounts for the number of terms
end

fprintf('This took %g terms and the final sum is %g \n', terms, sum) %print statement for results.