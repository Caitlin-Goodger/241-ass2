/**
 * editor2.h
 */

#ifndef __EDITOR_H__
#define __EDITOR_H__

//Function Prototypes
int editor_count_lines(const char * editingBuffer, int size);

int editor_search_multiple(const char *editingBuffer, int size, char * string, int * positions,int siezArray);

#endif /* __EDITOR_H__ */
