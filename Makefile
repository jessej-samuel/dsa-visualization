all: compile link

test: compile link run

compile:
	g++ -c *.cpp

link:
	g++ *.o -o main -lsfml-graphics -lsfml-window -lsfml-system

clean:
	del *.o

run:
	main.exe