#ifndef DRIVER_H
#define DRIVER_H

#include <iostream>
#include <string>
#include <stdlib.h>
//#include <unordered_map>

using namespace std;

/* ------ Start of the header file driver.h ------ */
#define SUCCESS	1;

typedef enum {

    LessThan = 0,

    LessThanEquals = 1,

    Equals = 2,

    GreaterThanEquals = 3,

    GreaterThan = 4

} SearchType;

 

typedef enum {

    NotFound=0,

    FoundExact,

    FoundGreater,

    FoundLess

} SearchResult;

/* Hash map to store the existing result*/
//unordered_map KeyMap<int,int*>;
		
SearchResult Search(

    const int * const items,

    const int n_items,

    const int ascending,

    const int key,

    const SearchType type,

    int* const index);

void SearchTest(
                
    const int * const items,
                
    const int n_items,
                
    const int ascending,
                
    const int key,
                
    const SearchType type,
                
    int* const index,
                
    const SearchResult answer,
            
    int * const index_answer);


/* ------ End of the header file driver.h ------ */
#endif
