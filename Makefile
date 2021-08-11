all: compile link

test: compile link run

compile:
	g++ -c *.cpp

link:
	g++ *.o -o bubblesort -lsfml-graphics -lsfml-window -lsfml-system

clean:
	del *.o

run:
	bubblesort.exe