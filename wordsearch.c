/*

Name:  Josh Heyer
Email: joshuaray83@gmail.com

Program Description: This program takes an NxN matrix of letters and searches
for the words hidden within. It then outputs the NxN matrix but only the
key words that it searched for and found.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int num_of_words = 0;
/*
char file [5][5] =  {{'C', 'A', 'T', 'B', 'U'},
                    {'O', 'G', 'O', 'D', 'E'},
                    {'S', 'F', 'I', 'Q', 'N'},
                    {'T', 'R', 'F', 'P', 'O'},
                    {'S', 'L', 'N', 'V', 'D'}};

char word2[5] = "COSTS";
char word3[4] = "DONE";
char word4[3] = "OFF";
char word5[3] = "TBU";
char word6[3] = "CAT";
*/

char word1[50];
char words[100][50];
int x = 0, y = 0, z = 0, N = 0, c;
char file_in[100][100];
char file_out[100][100];

/*
    This is a recursive function that searches for the word passed in.
    The search starts at 0,0 and goes left, right, up, down, etc. based upon
    whether or not the next letter in the word matches the next location to
    search.
    The function then edits the file_out array and returns 0 if the word was
    found.
*/
int search_for_word (int a, int b, char word_array[100][100], char word[], int length, int count) {

    if (word[count] == word_array[a][b] && length == count) {
        printf("I'm searching.");
        file_out[a][b] = word[count];
        return c = 0;
    }
    else if (word[count] == word_array[a][b] && a > 0 && word[count+1] == word_array[a-1][b]) {
        c = search_for_word (a-1, b, word_array, word, length, ++count); /* Search up*/
    }
    else if (word[count] == word_array[a][b] && a < 5 && word[count+1] == word_array[a+1][b]) {
        c = search_for_word (a+1, b, word_array, word, length, ++count); /* Search down*/
    }
    else if (word[count] == word_array[a][b] && b > 0 && word[count+1] == word_array[a][b-1]) {
        c = search_for_word (a, b-1, word_array, word, length, ++count); /* Search left*/
    }
    else if (word[count] == word_array[a][b] && b < 5 && word[count+1] == word_array[a][b+1]) {
        c = search_for_word (a, b+1, word_array, word, length, ++count); /* Search right*/
    }
    else if (word[count] == word_array[a][b] && a > 0 && b > 0 && word[count+1] == word_array[a-1][b-1]) {
        c = search_for_word (a-1, b-1, word_array,  word, length, ++count); /* Search up-left*/
    }
    else if (word[count] == word_array[a][b] && a > 0 && b < 5 && word[count+1] == word_array[a-1][b+2]) {
        c = search_for_word (a-1, b+1, word_array, word, length, ++count); /* Search up-right*/
    }
    else if (word[count] == word_array[a][b] && a < 5 && b > 0 && word[count+1] == word_array[a+1][b-1]) {
        c = search_for_word (a+1, b-1, word_array, word, length, ++count); /* Search down-left*/
    }
    else if (word[count] == word_array[a][b] && a < 5 && b < 5 && word[count+1] == word_array[a+1][b+1]) {
        c = search_for_word (a+1, b+1, word_array, word, length, ++count); /* Search down-right*/
    }
    else {
        return c = -1;
    }
}

/*
   This function prints the output array with only the found words from the
   2D array of letters.
*/
void print_file_out () {

    for (x = 0; x < N; x++) {
        for (y = 0; y < N; y++) {
            if (file_out[x][y] != '.') {
                printf("%c ", file_out[x][y]);
            }
        }
        printf("\n");
    }
}

/*
    This function reads in the array of letters and puts it into a 2D array.
    If it sees a space, it ignores it.
*/
void read_array () {

    for (x = 0; x < 50; x++) {
        if (x > N) {
            break;
        }
        for (y = 0; y < 50; y++) {

            scanf ("%c", &file_in[x][y]);
            if (file_in[x][y] == ' ') {
                y--;
            }
            if (file_in[x][y] == '\n') {
                if (x == 0) {
                    N = y;
                }
                break;
            }
        }
    }
}

/*
    This function reads in the words input into the program and puts them
    into another 2D array seperate from the array of letters
*/
void read_words () {

    for (x = 0; x < 100; x++) {
        for (y = 0; y < 50; y++) {
            words[x][y] = getchar();
            if (words[x][y] == '\n') {
                break;
            }
            if (words[x][y] == EOF) {
                x = 101;
            }
        }
        num_of_words++;
    }
}

/* 
    This function initializes the output array that will print out only the
    words that were found in the 2D array.
*/
void initialize_file_out () {

    for (x = 0; x < 100; x++) {
        for (y = 0; y < 100; y++) {
            file_out[x][y] = '.';
        }
    }
}

/*
    This function simply prints the inputted array. It is for testing.
*/
void print_array () {

    for (x = 0; x < N; x++) {
        for (y = 0; y < N; y++) {

           printf ("%c", file_in[x][y]);
        }
        printf ("\n");
    }
}

/*
    This function prints the inputted words. It is for testing.
*/
void print_words () {

    for (x = 0; x < num_of_words - 1; x++) {
        for (y = 0; y < 50; y++) {
            printf ("%c", words[x][y]);
        }
    }
}

int main () {

    read_array();
    read_words();
    initialize_file_out();
    for (x = 0; x < N; x++) {
        for (y = 0; y < N; y++) {
            for (x = 0; x < num_of_words; x++) {
                for (y = 0; y < 50; y++) {
                    word1[y] = words[x][y];
                    if (!isalpha(word1[y])) {
                    word1[y] = '\0';
                    break;
            }
        }
                c = search_for_word (0, 0, file_in, words[z], 3, 0);
                /*printf ("C = %d\n", c);*/
        }
    }


    if (c == 0) {
            printf ("SUCCESS!\n");
    }
    else {
        printf ("BOOOOOO!\n");
    }
    print_file_out();
            
        /*printf ("The word we're searching for is: %s\n", word1);
        search_for_word(word1);*/
    }

    /*print_array();
    print_words();*/

    return 0;
}
