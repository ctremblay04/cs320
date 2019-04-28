# Specifiy the target
all:	clean cache

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
cache: Cache.o Direct.o SetAssoc.o SetAssocNoWrite.o FullyAssoc.o LRUApprox.o SetAssocPrefetch.o SetAssocPrefetchNoWrite.o main.o
	g++ Cache.o Direct.o SetAssoc.o SetAssocNoWrite.o FullyAssoc.o LRUApprox.o SetAssocPrefetch.o SetAssocPrefetchNoWrite.o main.o -o cache-sim

# Specify how the object files should be created from source files

Cache.o: Cache.cpp
	g++ -g -Wall -c Cache.cpp

Direct.o: Direct.cpp
	g++ -g -Wall -c Direct.cpp

SetAssoc.o: SetAssoc.cpp
	g++ -g -Wall -c SetAssoc.cpp

FullyAssoc.o: FullyAssoc.cpp
	g++ -g -Wall -c FullyAssoc.cpp

LRUApprox.o: LRUApprox.cpp
	g++ -g -Wall -c LRUApprox.cpp

SetAssocNoWrite.o: SetAssocNoWrite.cpp
	g++ -g -Wall -c SetAssocNoWrite.cpp

SetAssocPrefetch.o: SetAssocPrefetch.cpp
	g++ -g -Wall -c SetAssocPrefetch.cpp

SetAssocPrefetchNoWrite.o: SetAssocPrefetchNoWrite.cpp
	g++ -g -Wall -c SetAssocPrefetchNoWrite.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o cache-sim

