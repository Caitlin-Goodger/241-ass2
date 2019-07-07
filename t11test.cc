/**
 * t11test.cc
 * Sample test program for Task 10
 *
 * To compile with your implementation:
 * g++ t11test.cc editor2.cc -o t11test
 *
 * If successful, executable file t11test should have been
 * created.
 */

#include <iostream>
#include "editor2.hh"

#define TEST_STRING "The good, the bad and the lucky."

using namespace editor2;
using namespace std;

int EditorUtilities::searchMultipleNoCase( const char *buffer, int size, string str, int *positions, int sizeArray) {
        int count =0;
        char * ptr = (char *) buffer;
        //char *sptr;
        for(int i =0; i<size;i++) {
                char c = *ptr;
                if(tolower(c) == tolower(str.at(0))) {
                        int increase = 1;
                        ptr++;
                        for(int j =1;j<sizeof(str);j++) {
                                char c = tolower(*ptr);
                                char s = tolower(str.at(j));
                                if(c!=s) {
                                        ptr = ptr-increase;
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

  cout << "Buffer contents: " << buffer << endl;
  int r = EditorUtilities::searchMultipleNoCase(buffer, sizeof(buffer), string("the"), positions, 20);
  cout << "Output of EditorUtilities::searchMultipleNoCase(): " << r << endl;
  cout << "Positions: ";
  for(int i=0; i<r; i++) { cout << *pp << " "; pp++; }
  cout << endl << "Actual number of occurrences in buffer of 'the': 3" << endl;
  cout << "Positions: 0 10 22" << endl;

  return 0;
}
