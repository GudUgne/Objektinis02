main: Fun.o
	g++ -o main Source.cpp Fun.o
fun:
	g++ -c Fun.cpp
clean:
	rm *.o main