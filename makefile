wordsearch.exe: wordsearch.c wordsearch.o
	gcc -Wall -ansi -pedantic -c wordsearch.c
	gcc -o wordsearch.exe wordsearch.o
