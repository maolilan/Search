#include "driver.h"

void SearchTest(const int *const items, const int n_items, 
    const int ascending, const int key,
    const SearchType type, int *const index, 
    const SearchResult answer, int *const index_answer) {
	
	/* Output string for testing */
	string SRString[FoundLess + 1]={"Not Found","Found Exact",
		"Found Greater", "Found Less"};
		
	SearchResult result = Search(items, n_items, ascending, 
		key, type, index);

	if(result != answer) {
		cout << "The Search Result should be: "<< SRString[answer]<<"\n"
		     << "But the Test Result is: " << SRString[result] <<".\n";
	}
	else {
		cout << "The Search Result is correct: " 
		     << SRString[result]<<".\n";
	}
		

	if(*index != *index_answer) {
		cout << "The index should be: " << *index_answer << "\n"
		     << "But the function return index:" << *index << ".\n";
	}
	else {
		cout << "The index is correct: " << *index_answer<<".\n";
	}
}
	
