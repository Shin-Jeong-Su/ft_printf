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
	char *str = "asdf 1234";
	int n= 214748364;
	int n= 0;
	// test(n,1,3,5);
	// printf("%p\n",&n);
	// ft_putaddr_fd(&n,1);
	// printf("%x\n",n);
	// ft_puthex_fd(n,1);
	ft_printf("asdfasdf %u\n",n);
	printf("asdfasdf %u\n",n);
	return (0);
}