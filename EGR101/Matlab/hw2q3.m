pos = input('What number in the sequence would you like to know? '); %input to establish what number in the sequence a user wants
seq = [0 1]; %establishes first 2 numbers of the fibonacci sequence

for i = 3:1:pos %loop to get to where the person wants in the sequence
    seq(i) = seq(i-2)+seq(i-1);
end

fprintf('The %g (-st,-nd,-rd,-th)number in the Fibonacci Sequence is %g \n', pos, seq(pos)) %print statement