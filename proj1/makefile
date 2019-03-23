# Specifiy the target
all:	predictors

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
predictors: Predictor.o AlwaysTaken.o AlwaysNotTaken.o BimodalSingleBit.o BimodalDoubleBit.o Gshare.o Tournament.o main.o
	g++ Predictor.o AlwaysTaken.o AlwaysNotTaken.o BimodalSingleBit.o BimodalDoubleBit.o Gshare.o Tournament.o main.o -o predictors

# Specify how the object files should be created from source files
Predictor.o: Predictor.cpp
	g++ -g -Wall -c Predictor.cpp

AlwaysTaken.o: AlwaysTaken.cpp
	g++ -g -Wall -c AlwaysTaken.cpp

AlwaysNotTaken.o: AlwaysNotTaken.cpp
	g++ -g -Wall -c AlwaysNotTaken.cpp

BimodalSingleBit.o: BimodalSingleBit.cpp
	g++ -g -Wall -c BimodalSingleBit.cpp

BimodalDoubleBit.o: BimodalDoubleBit.cpp
	g++ -g -Wall -c BimodalDoubleBit.cpp

Gshare.o: Gshare.cpp
	g++ -g -Wall -c Gshare.cpp

Tournament.o: Tournament.cpp
	g++ -g -Wall -c Tournament.cpp

main.o:	main.cpp
	g++ -g -Wall -c main.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o predictors

