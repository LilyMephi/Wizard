#Makefile for Wizard

wizard: main.o libMap.so libView.so
	g++ main.o -o game -Wall -lsfml-graphics -L. -lsfml-window -lsfml-system -Wl,-rpath,. -lMap -lView
main.o:
	g++ -c main.cpp
libMap.so:Map.o
	g++ -shared -o libMap.so Map.o -lsfml-window -lsfml-system -Wall
libView.so:View.o
	g++ -shared -o libView.so View.o -lsfml-window -lsfml-system 	
Map.o:
	g++ -c -fPIC Map.cpp -Wall
View.o:
	g++ -c -fPIC View.cpp	

clean:
	rm -f *.o *.so game
