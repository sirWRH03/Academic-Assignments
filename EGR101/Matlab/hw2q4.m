clc
clear
home

p1_name=input("Enter player 1 name: ", 's');
p2_name=input("Enter player 2 name: ", 's');

teamDecide = randi(2);

p1_wins = 0;
p2_wins = 0;
p1_play=0;
p2_play=0;
sum=0;
play="y";

if teamDecide == 1
    p1 = "odds";
    p2 = "evens";
    fprintf('%s is %s and %s is %s! \n',p1_name,p1,p2_name,p2)
    
    while play == "y" || play == "Y"
        p1_play=randi([1,5], 1); %Lets player 1 choose a number
        p2_play=randi([1,5], 1); %Lets player 2 choose a number
        disp("1, 2, 3... GO! (press any key to start)")
        pause
        fprintf("%s shows %g fingers. \n", p1_name, p1_play)
        fprintf("%s shows %g fingers. \n", p2_name, p2_play)
        sum = p1_play+p2_play;
        
        if mod(sum, 2) == 0
            fprintf("The sum, %g, is even. %s wins! \n", sum, p2_name)
            p2_wins = p2_wins + 1;
        else
            fprintf("The sum, %g, is odd. %s wins! \n", sum, p1_name)
            p1_wins = p1_wins + 1;
        end

        while true
            play = input("Do you want to play again? (Y/N): ", "s");
            if play == "N" || play == "n"
                disp("Ok... See you next time!")
                break
            elseif play == "Y" || play == "y"
                break
            else
            end
        end
    end
else
    p1 = "evens";
    p2 = "odds";
    fprintf('%s is %s and %s is %s! \n',p1_name,p1,p2_name,p2)
    
    while play == "y" || play == "Y"
        p1_play=randi([1,5], 1); %Lets player 1 choose a number
        p2_play=randi([1,5], 1); %Lets player 2 choose a number
        disp("1, 2, 3... GO! (press any key to start)")

        pause

        fprintf("%s shows %g fingers. \n", p1_name, p1_play)
        fprintf("%s shows %g fingers. \n", p2_name, p2_play)

        sum = p1_play+p2_play;

        if mod(sum, 2) == 0
            fprintf("The sum, %g, is even. %s wins! \n", sum, p1_name)
            p2_wins = p1_wins + 1;
        else
            fprintf("The sum, %g, is odd. %s wins! \n", sum, p2_name)
            p1_wins = p2_wins + 1;
        end

        while true
            play = input("Do you want to play again? (Y/N): ", "s");
            
            if play == "N" || play == "n"
                disp("Ok... See you next time!")
                break
            elseif play == "Y" || play == "y"
                break
            else
            end
        end
    end
end
