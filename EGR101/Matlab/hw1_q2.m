clc
clear
home

x = [-5:.1:5]; % determining x values
y1 = sin(2*pi*x)/(2*x);
y2 = (x.^2)/cos(2*pi*x); %determining y values
y3 = 4*(x.^2);
y4 = -4*(x.^2);

plot(x,y1,'Color','r','LineStyle','-')
hold on
plot(x,y2,'Color','b','LineStyle','--')
hold on
plot(x,y3,'Color','y','LineStyle',':') %determining the plots
hold on
plot(x,y4,'Color','g','LineStyle','-.')
hold on
title('Graphs')
xlabel('x values')
ylabel('y values') %setting labels
legend('Plot 1','Plot 2','Plot 3','Plot 4')