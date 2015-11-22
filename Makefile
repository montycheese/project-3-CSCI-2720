all: sort.cpp DataGenerator.cpp
	g++ -o sort sort.cpp
	g++ -o DataGenerator DataGenerator.cpp
	

clean:
	rm -f sort
	rm -f DataGenerator