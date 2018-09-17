reverse: reverse.c
	clang reverse.c file_utils.c -o reverse

test: test1
test1:
	./reverse input.txt out
	./reverse out out2
	diff input.txt out2
