BinaryTree.o: BinaryTree.h BinaryTree.c
	gcc -c BinaryTree.c

.PHONY: clean 

clean: 
	rm -f BinaryTree.o
