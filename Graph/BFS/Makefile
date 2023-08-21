output: bfsUsingMatrix.o adjacencyMatrix.o
	g++ bfsUsingMatrix.o adjacencyMatrix.o -o output
	
bfsUsingMatrix.o: bfsUsingMatrix.cpp
	g++ -c bfsUsingMatrix.cpp
	
adjacencyMatrix.o: adjacencyMatrix.cpp
	g++ -c adjacencyMatrix.cpp
	
clean:
	rm *.o output

