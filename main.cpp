#include "driver.h"

int main(void) {	
    /* initialize all the values */
    /*
	int TestArray[5] = {0,2,4,6,8};
	int ascending = 1;
	int key[6] = {-1,0,0,1,2,2};
	SearchType type[6] = {LessThanEquals, LessThan, Equals, Equals,
		GreaterThanEquals, GreaterThan};
	int index[6] = {0, 0, 0, 0, 0, 0};
	*/
	
	/* answer */
	/*
	int index_answer[6] = {-1, -1, 0, -1, 1, 2};
	SearchResult answer[6] = {NotFound, NotFound, FoundExact, NotFound,
		FoundExact, FoundGreater};
	*/
		
	/* initialize all the values */
	int TestArray[5] = {8,6,4,2,0};
	int ascending = 0;
	int key[6] = {-1,4,8,5,2,9};
	SearchType type[6] = {LessThan, LessThanEquals, Equals, 
		GreaterThanEquals, GreaterThanEquals, GreaterThan};
	int index[6] = {0, 0, 0, 0, 0, 0};
	
	/* answer */
	int index_answer[6] = {-1, 2, 0, 1, 3, -1};
	SearchResult answer[6] = {NotFound, FoundExact, FoundExact, 
		FoundGreater, FoundExact, NotFound};
	
	for (int i=0; i<6; i++)
	SearchTest(TestArray, 5, ascending, key[i], 
		type[i], index+i, answer[i], index_answer+i);

	return SUCCESS;
}
