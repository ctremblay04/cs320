# Specifiy the target
all:	predictors

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
predictors: Predictor.o Perceptron.o main.o
	g++ Predictor.o Perceptron.o main.o -o predictors

# Specify how the object files should be created from source files
Predictor.o: Predictor.cpp
	g++ -g -Wall -c Predictor.cpp

Perceptron.o: Perceptron.cpp
	g++ -g -Wall -c Perceptron.cpp

main.o:	main.cpp
	g++ -g -Wall -c main.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o predictors

