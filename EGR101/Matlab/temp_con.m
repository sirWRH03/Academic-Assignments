function [degreesC,kelvin] = temp_con(degreesF)
    %finds the conversions for a degree value in Farenheit
        %this program converts a Farenheit Degree value into a Celcius and
        %Kelvin degree value
        %
    %Arguements
        %
        % degreesF (input) A Degree value in Farenheit
        %
        % degreesC (output) the converted Farenheit degree value
        %                   into degrees Celcius
        %
        % kelvin (output) the converted Farenheit degree value
        %                 into Kelvin
    degreesC = (degreesF - 32)*(5/9);
    kelvin = degreesC + 273.15; %bullshit conversion math