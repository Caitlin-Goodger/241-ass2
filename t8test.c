/**
 * t8test.c
 * Sample test program for Task 8
 *
 * To compile with your implementation:
 * gcc t8test.c editor2.c -o t8test
 *
 * If successful, executable file t8test should have been
 * created.
 */

#include <stdio.h>
#include "editor2.h"

#define TEST_STRING "The good, the bad and the lucky."

int editor_search_multiple( const char *buffer, int size, char *string, int *positions, int sizeArray) {
        int count = 0;
        char * ptr = (char *) buffer;
        char *sptr = string;
        for(int i =0; i<size;i++) {
                char c = *ptr;
                if(c == *sptr) {
                        int increase = 1;
                        ptr++;
                        sptr++;
                        for(int j =1;j<sizeof(string);j++) {
                                char c = *ptr;
                                char s = *sptr;
                                if(c!=s) {
                                        ptr = ptr-increase;
                                        sptr = sptr-increase;
                                        break;
                                }

                        }
                        positions[count] = i;
                        count++;

                }
                ptr++;
        }
        return count;
}

int main(void)
{
  char buffer[] = TEST_STRING;
  int positions[20];
  int *pp = positions;

  printf("Buffer contents: %s", buffer);
  int r = editor_search_multiple(buffer, sizeof(buffer), "the", positions, 20);
  printf("\nOutput of editor_search_multiple(): %d\n", r);
  printf("Positions: { ");
  for(int i=0; i<r; i++) { printf("%d ", *pp); pp++; }
  printf("}\nActual number of occurrences in buffer of 'the': 2\n");
  printf("Positions: { 10 22 }\n");

  return 0;
}
