hw2: BinaryNode.o BinarySearchTree.o Queue.o main.o
	g++ BinaryNode.o BinarySearchTree.o Queue.o main.o -o hw2

BinaryNode.o: BinaryNode.cpp
	      g++ -c BinaryNode.cpp

BinarySearchTree.o: BinarySearchTree.cpp
		    g++ -c BinarySearchTree.cpp

Queue.o: Queue.cpp
	g++ -c Queue.cpp 

main.o: main.cpp
	g++ -c main.cpp