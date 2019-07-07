/**
 * t7test.c
 * Sample test program for Task 7
 *
 * To compile with your implementation:
 * gcc t7test.c editor2.c -o t7test
 *
 * If successful, executable file t7test should have been
 * created.
 */

#include <stdio.h>
#include "editor2.h"


/**
*Count the number of lines in buffer given.
*Everytime that it reaches a '\n' character incease count
*/

int editor_count_lines( const char * buffer, int size) {
        char *ptr = (char *) buffer;
        int count = 0;
        for(int i = 0; i<size;i++) {
                char c = *ptr;
                if(c == '\n') {
                        count++;
                }
                ptr++;
        }
        return count;
}


/**
*Count the number of word in buffer. Record the number of the word and where the word starts.
*/
int editor_search_multiple( const char *buffer, int size, char *string, int *positions, int sizeArray) {
        int count = 0;
        char * ptr = (char *) buffer;
        char *sptr = string;
        for(int i =0; i<size;i++) {
                char c = *ptr;
                if(c == *sptr) { //If the first characters match
                        int increase = 1;
                        ptr++;
                        sptr++;
                        for(int j =1;j<sizeof(string);j++) { // Compare the rest
                                char c = *ptr;
                                char s = *sptr;
                                if(c!=s) {
                                        ptr = ptr-increase;//If they don't match put the pointers back to where they were before
                                        sptr = sptr-increase;
                                        break;
                                }

                        }
                        positions[count] = i;//Record position if it matches
                        count++;

                }
                ptr++;
        }
        return count;
}
