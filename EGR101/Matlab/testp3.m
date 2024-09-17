%% Will Humphrey
% Matlab Programming Problem 3
clc
clear
home

numberPair = [0 0]; %establishes an array to determine the last 2 picked marbles
draws = 0; %number of draws so far
stop = 0; %variable to know when to stop

while stop == 0 %while loop
    toDraw = randi(5); %determines which marble out of 5 is drawn
    
    if toDraw == 1 %big conditional statement to determine which marble is drawn
        draws = draws + 1; %adds to the draw count
        numberPair = [numberPair(length(numberPair)) 1]; %updates the array
    elseif toDraw == 2
        draws = draws + 1;
        numberPair = [numberPair(length(numberPair)) 2];
    elseif toDraw == 3
        draws = draws + 1;
        numberPair = [numberPair(length(numberPair)) 3];
    elseif toDraw == 4
        draws = draws + 1;
        numberPair = [numberPair(length(numberPair)) 4];
    else
        draws = draws + 1;
        numberPair = [numberPair(length(numberPair)) 5];
    end
    if numberPair(1) == numberPair(2) %determines when the last two picked marbles are the same
        fprintf('I picked marble number %g twice in a row on the pick number %g', toDraw, draws) %print statment for which marble was picked twice in a row and which pick it was on
        stop = 1; % stops the loop
    end
end