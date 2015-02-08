test: red_black_tree.c test.c
	gcc -g red_black_tree.c test.c -o test

clean:
	rm test
