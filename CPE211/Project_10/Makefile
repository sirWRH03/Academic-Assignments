# #!/bin/bash
# make file for class Date
Project_10:  Project_10.o  Project_10_main.o
	g++ -std=c++11   Project_10.o Project_10_main.o -o Project_10

Project_10.o: Project_10.cpp Project_10.h
	g++ -std=c++11   -c  Project_10.cpp

Project_10_main.o:  Project_10.h  Project_10_main.cpp
	g++ -std=c++11   -c  Project_10_main.cpp
clean:
	rm *.o Project_10

