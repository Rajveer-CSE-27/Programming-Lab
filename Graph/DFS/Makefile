output: dfsUsingList.o adjacencyList.o
	g++ dfsUsingList.o adjacencyList.o -o output
	
dfsUsingList.o: dfsUsingList.cpp
	g++ -c dfsUsingList.cpp

adjacencyList.o: adjacencyList.cpp
	g++ -c adjacencyList.cpp
	
clean:
	rm *.o output
