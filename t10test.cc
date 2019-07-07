/**
 * t10test.cc
 * Sample test program for Task 10
 *
 * To compile with your implementation:
 * g++ t10test.cc editor2.cc -o t10test
 *
 * If successful, executable file t10test should have been
 * created.
 */

#include <iostream>
#include "editor2.hh"

#define TEST_STRING "Alice\topened the\n\ndoor\t and   found that it\n\n led into"

using namespace editor2;
using namespace std;

int EditorUtilities::countWords(const char *buffer, int size) {
        int count = 0;
        bool last = true;
        char *ptr = (char*)buffer;
        for(int i = 0; i<size;i++) {
                char c = *ptr;
                if(c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r') {
                        if(last == false) {
                                count++;
                                last = true;
                        }
                } else {
                        last = false;
                }
                ptr++;
        }
        if(last == false) {
                count++;
        }
        return count;
}


int main(void)
{
  char buffer[] = TEST_STRING;
  cout << "Buffer contents: " << buffer << endl;
  int r = EditorUtilities::countWords(buffer, sizeof(buffer));
  cout << "Output of EditorUtilities::countWords(): " << r << endl;
  cout << "Actual number of words in buffer       : 10" << endl;
  return 0;
}
