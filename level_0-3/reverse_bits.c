#include <unistd.h>

unsigned char	reverse_bits(unsigned char b)
{
	unsigned char r;
	unsigned			l;

	r = 0;
	l = 8;
	while (l--)
	{
		r = (r<<1) | (b & 1);
		b >>= 1;
	}
	return (r);
}