#include <stdio.h>
#include "function.c"

int main(){	
	//fungsi opening
	struct loginUser *head;
    opening();
	mainMenu(head);

	return 0;
}