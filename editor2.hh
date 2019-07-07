/**
 * editor.hh
 */

#ifndef __EDITOR_HH__
#define __EDITOR_HH__

#include <iostream>
#include <cstring>

//using namespace std;
namespace editor2
{
    class EditorUtilities
    {
    public:
        //Function Prototypes
        static int countWords( const char * editingBuffer, int size);
        static int searchMultipleNoCase( const char *buffer, int size, std::string str, int *positions, int sizeArray);
    };
}


#endif /* __EDITOR_HH__ */
