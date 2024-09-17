clc
clear
home

stock_1=[10 16 10 17 27 21 13 15 21 28 30 24 10 10 23 18 30 25 27 12 19 12 26 23 13 28 20 15 23 29 21 25 28 25 27 29 25 13 30 24 21 20 23 16 23 22 19 20 17 12];
stock_2=[18 24 14 12 30 26 27 24 24 14 10 22 25 12 25 18 10 14 18 16 29 28 12 11 22 25 11 15 21 18 30 26 27 18 11 21 25 12 30 24 23 24 15 16 24 14 19 22 20 11];
stock_3=[19 19 17 10 30 26 25 21 15 15 24 12 28 13 15 25 30 16 10 28 17 30 15 16 23 22 27 19 23 19 17 22 12 12 25 18 29 30 24 25 25 11 25 25 29 23 14 11 21 12];

answer_a = []; %establishing an array for length determination
answer_b = [];
answer_c = [];

for i = 1:1:30
    if stock_1(i) > stock_2(i) && stock_3(i)
        answer_a = [answer_a, stock_1(i)];
    elseif stock_1(i) > stock_2(i) || stock_3(i)
        answer_b = [answer_b, stock_1(i)];
    elseif stock_1(i) > stock_2(i) && stock_1(i) < stock_3(i)
        answer_c = [answer_c, stock_1(i)];
    end
end % data parsing algorithim

a_length = length(answer_a); %determines the length aka the number of days
b_length = length(answer_b);
c_length = length(answer_c);

fprintf('The price of stock 1 was greater than both stock 2 and stock 3 for %g days', a_length)
disp(' ') % output statements for a-c
fprintf('The price of stock 1 was greater than stock 2 or stock 3 for %g days', b_length)
disp(' ')
fprintf('The price of stock 1 was greater than stock 2 but less than stock 3 for %g days', c_length)