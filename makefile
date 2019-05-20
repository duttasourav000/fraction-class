all:
	mkdir -p obj
	g++ -g -o ./obj/Fraction.o ./src/Fraction.cpp -c
	g++ -g -o main obj/Fraction.o main.cpp

clean:
	rm -rf main obj/*.o