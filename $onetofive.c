#include <stdio.h>

int main() {
	int k = 1;
	char dollar = '$'; 
	for (k = 1; k <= 5;k++) {
		for (int i = 1; i <= k; i++) {
			printf("%c", dollar);
			
		}
		printf("\n");
		
	}
}


/*	  //F
	    FD
	    FED
	    FEDC
	    FEDCB
	    
#include <stdio.h>
int main() {
	int k = 1;
	int dollar = 70; 
	for (k = 1; k <= 5;k++) {
		for (int i = 1; i <= k; i++) {
			printf("%c", dollar);
			dollar = dollar - 1;
		}
		printf("\n");
		dollar = 70;
	}

}*/
