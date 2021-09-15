#include "printUtil.h"



void printArr (int *a, int len) {
	int i;
	for (i=0; i<len; i++) {
		printf ("%d ",a[i]);
	}
	printf ("\n");
}
