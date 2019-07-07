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

using namespace editor2;
using namespace std;

/**
*Count the number of words in buffer
*/
int EditorUtilities::countWords(const char *buffer, int size) {
        int count = 0;
        bool last = true;
        char *ptr = (char*)buffer;
        for(int i = 0; i<size;i++) {
                char c = *ptr;
                if(c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r') { //If c is a special character
                        if(last == false) { //It counts as a word if the last character wasn't a special character as well
                                count++;
                                last = true;
                        }
                } else {
                        last = false;
                }
                ptr++;
        }
        if(last == false) {//If last character wasn't a special character then add another word
                count++;
        }
        return count;
}

/**
*Count the number of word in the buffer, ignoring the case. Record the number of the word and where the word starts.
*/
int EditorUtilities::searchMultipleNoCase( const char *buffer, int size, string str, int *positions, int sizeArray) {
        int count =0;
        char * ptr = (char *) buffer;
        for(int i =0; i<size;i++) {
                char c = *ptr;
                if(tolower(c) == tolower(str.at(0))) {//Makes it all lower so that if they are the same letter then they will be equal regardless of case
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
