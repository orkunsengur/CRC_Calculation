#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <inttypes.h>


uint64_t next_perm(uint64_t v)
{
	uint64_t t,w;
    t = (v | ( v - 1)) + 1;
    w = t | ((((t & -t) / (v & -v)) >> 1) - 1);
    return w;
}



unsigned char degree(uint64_t a)
{
	unsigned char i=0;
	if(a==0 || a==1)
	return 0;

	while(a!=1)
	{
		a=a>>1;
		i++;
	}
	return i;
}

uint64_t xor_add(uint64_t divident, uint64_t divisior)
{
	unsigned char i=0,j=0;
    
    i=degree(divident);
    j=degree(divisior);
	
	divisior=divisior<<(i-j);

	return divisior^divident;
}

uint64_t division(uint64_t divident, uint64_t divisior)
{
	uint64_t remainder;
	
	remainder=divident;
	
	while(degree(remainder)>=degree(divisior) && remainder!=0)
	{
		remainder=xor_add(remainder,divisior);
	}
	
	return remainder;
}

int main()

{
	uint64_t next=1;
	uint64_t a;
	uint64_t b=0;
	uint64_t polynomial=0x139;  // msbit-first representation 0x101=0x01
	uint64_t remainder;
	uint64_t divident;
	divident=next;
	a=(uint64_t)pow(2,56);
	
	


										
	while(next<a)
	{
		
		
		remainder=division(next,polynomial);
		if(remainder==0)
		{
			b++;
		}
		     	
	//	printf("%" PRIu64 "\n", next);
	//	printf("%" PRIu64 "\n", remainder);
		next=next_perm(next);	
		
	}
	printf("%" PRIu64 "\n", b);

}


