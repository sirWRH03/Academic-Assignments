clear
clc
home

replay = 2;
tries = 1;
while replay == 2
    correctAnswer = randi(10); %establishes a random number between 1 and 500
    guess = input("What is the number generated? You only get 3 tries! "); % lets the user guess
    while guess ~= correctAnswer % establishes a loop for if the number is wrong
        if tries == 3
            disp('Sorry, you couldnt guess it in the right amount of tries!')
            playAgain = input('Try again? (1 for YES 2 for NO) ');
            if playAgain == 1
                tries = 1;
                replay = 2;
            else
                replay = 1;
                disp('Thanks for playing!')
                break
            end
        end

        if guess > correctAnswer %if else statement for determining if number is
            too low or too high
            tries = tries + 1;
            disp('Incorrect! You guessed too high! ')
            guess = input('What is the number generated? '); %allows user to guess again
        elseif guess < correctAnswer
            tries = tries + 1;
            disp('Incorrect! You guessed too low! ')
            guess = input('What is the number generated? ');
        end
    end

    if guess == correctAnswer %determines if the guess is correct and tells the user
        disp('Congrats! You guessed correctly! ')
        fprintf('The correct answer was %g!', correctAnswer)
        disp(' ')
        replay = 1;
    end
end