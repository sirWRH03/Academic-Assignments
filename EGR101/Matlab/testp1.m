%% Will Humphrey
% Matlab Programming Problem 1
clc
clear
home

t = (0:.01:3.5); %establishing the time variable from 0 - 3.5 seconsd
w1 = 4; %first value for w
w2 = 10; %second value for w
v1= 10+exp(-2.*t).*(8*cos(w1.*t)+4*sin(w1.*t)); %voltage over time for the first w
value
v2= 10+exp(-2.*t).*(8*cos(w2.*t)+4*sin(w2.*t)); %voltage over time for the second w
value

plot(t,v1,'Color','b','Marker','*') %plot for the first w value
hold on
plot(t,v2,'Color','r','Marker','+') %plot for second w value
hold on
title('Voltage Over Time Graph') %title of graph
xlabel('Time') %x axis label
ylabel('Voltage') %y axis label