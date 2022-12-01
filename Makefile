main: main.o funcs.o profile.o
	g++ -o main main.o funcs.o profile.o

tests: tests.o funcs.o profile.o
	g++ -o tests tests.o funcs.o profile.o

funcs.o: funcs.cpp funcs.h
	g++ -c -std=c++11 funcs.cpp

profile.o: profile.cpp profile.h
	g++ -c -std=c++11 profile.cpp

main.o: main.cpp funcs.h profile.h
	g++ -c -std=c++11 main.cpp

tests.o: tests.cpp doctest.h funcs.h profile.h
	g++ -c -std=c++11 tests.cpp

clean:
	rm -f main.o funcs.o tests.o main tests
