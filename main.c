#include "ft_printf.h"
#include <stdio.h>

void test_pr(va_list *ap)
{
	printf("%d\n",va_arg(*ap,int));
}

void test(int n,...)
{
	va_list ap;
	va_start(ap,n);
	for(int i=0;i<n;i++){
		test_pr(&ap);
	}
	va_end(ap);
}

int main(){
	//char *str = "asdf 1234";
	int n= 214748364;
	int m =  ft_printf("\09");
	printf("%d\n",m);
	return (0);
}