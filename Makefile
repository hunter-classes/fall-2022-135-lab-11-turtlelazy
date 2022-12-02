main: main.o funcs.o profile.o network.o
	g++ -o main main.o funcs.o profile.o network.o

tests: tests.o funcs.o profile.o network.o
	g++ -o tests tests.o funcs.o profile.o network.o

funcs.o: funcs.cpp funcs.h
	g++ -c -std=c++11 funcs.cpp

profile.o: profile.cpp profile.h
	g++ -c -std=c++11 profile.cpp
network.o: network.cpp network.h
	g++ -c -std=c++11 network.cpp
main.o: main.cpp funcs.h profile.h
	g++ -c -std=c++11 main.cpp

tests.o: tests.cpp doctest.h funcs.h profile.h
	g++ -c -std=c++11 tests.cpp

clean:
	rm -f main.o funcs.o tests.o profile.o network.o main tests
