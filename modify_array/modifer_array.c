#include <unistd.h>
#include <stdlib.h>

int* remove_dup_inter(int* car, int* cdr) {
	if (*car==*cdr) {
		return cdr;
	} else {
		*(cdr-1)=*car;	
		return(cdr-1);
	}
}

int* remove_dup(int* array, int length) {
	int *car,*cdr;	
	cdr=array+length-1;
	for(int i=1;i<length;i++) {
		car=array+length-1-i;
		cdr=remove_dup_inter(car,cdr);
	}	
	return cdr;
}

int main() {
	int array[]={1,1,2,4,4,5,6,7,9,10,10,10,10,10,10};
	int length=15;
	int*p;
	p=remove_dup(array,length);
	length=array+length-p;
	printf("length=%d\n",length);
	for (int i=0;i<length;i++) 	{
		printf("%d\n",*(p+i));
	}
	exit(0);
}

