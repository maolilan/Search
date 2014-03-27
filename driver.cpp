#include "driver.h"

/* 
 * Find three index: left, middle, right. such as:
 * items[left] is the greatest value less than key
 * items[middle] is the value equal to key
 * items[right] is the smallest value greater than key
 * Also, if the index does not exist, we set it to -1;
 */

int* FindTuple (const int *const items, const int n_items, 
    const int ascending, const int key) {

	int left=0, middle=0, right=0;
	int index=0;

	if (ascending)
		while (items[index]<=key && index<n_items) index++;
	else
		while (items[index]>=key && index<n_items) index++;

	if (!index) {
		left = -1;
		middle = -1;
		right = 0;
	}

	else if (index == n_items) {
		right = -1;
		if (items[index-1] == key) {
			middle = index-1;
			left = index>1?index-2:-1;
		}
		else {
			middle = -1;
			left = index - 1;
		}
	}

	else {
		right = index;
		if (index>0) {
			if (items[index-1] == key) {
				middle = index - 1;
				left = index>1?index-2:-1;
			}
			else {
				middle = -1;
				left = index - 1;
			}
		}
		else {
			middle = -1;
			left = -1;
		}

	}

	int *result = new int[3];

	if (ascending) {
		result[0]=left; 
		result[1]=middle; 
		result[2]=right;
	}

	else {
		result[0]=right;
		result[1]=middle;
		result[2]=left;
	}

	return result;	
}


SearchResult Search (const int *const items, const int n_items, 
    const int ascending, const int key, 
    const SearchType type, int *const index)
{
	int *TupleValue;
    
	/*
	if (KeyMap.Find(key)!=KeyMap.end()) {
		TupleValue = KeyMap[key];
	} 
	else {
		TupleValue = FindTuple(items, n_items, ascending, key);
	}
	*/

	TupleValue = FindTuple(items, n_items, ascending, key);
	SearchResult result = NotFound;
	int left = TupleValue[0];
	int middle = TupleValue[1];
	int right = TupleValue[2];

	switch (type)
	{
	    case (LessThan):
		*index = left;
	    	result = left==-1?NotFound:FoundLess;
		break;
	    case (LessThanEquals):
		if (middle!=-1) {
			*index = middle;
			result = FoundExact;
		}
		else if(left!=-1) {
			*index = left;
			result = FoundLess;
		}
		else {
			*index = left;
			result = NotFound;
		}
		break;
	    case (Equals):
		*index = middle;
        	result = middle==-1?NotFound:FoundExact;
		break;
	    case (GreaterThanEquals):
		if (middle!=-1) {
			*index = middle;
			result = FoundExact;
		}
		else if(right!=-1) {
			*index = right;
			result = FoundGreater;
		}
		else {
			*index = right;
			result = NotFound;
		}
		break;
	    case (GreaterThan):
		*index = right;
        	result = right==-1?NotFound:FoundGreater;
		break;
	    default:
		*index = -1;
		cout << "Invalid search type!\n";
		break;
	}
	
	return result;
}
