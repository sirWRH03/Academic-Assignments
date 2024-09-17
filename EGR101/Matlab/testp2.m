%% Will Humphrey
% Matlab Programming Problem 2
clc
clear
home

x = [ -3 -17 4 -1 5 8 6 -19 -18 -7];

pos_even = [];
neg_num = [];
left = [];

for i = 1:length(x)
    if x(i) > 0 && mod(x(i),2) == 0
        pos_even = [pos_even x(i)];
    elseif x(i) < 0
        neg_num = [neg_num x(i)];
    else
        left = [left x(i)];
    end
end

disp(pos_even)
disp(neg_num)
disp(left)