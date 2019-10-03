/*
Write a function who takes two unsigned int as parameters and returns the
computed LCM of those parameters.

LCM (Lowest Common Multiple) of two non-zero integers is the smallest postive
integer divisible by the both integers.

A LCM can be calculated in two ways:

- You can calculate every multiples of each integers until you have a common
multiple other than 0

- You can use the HCF (Highest Common Factor) of these two integers and
calculate as follows:

    LCM(x, y) = | x * y | / HCF(x, y)

 | x * y | means "Absolute value of the product of x by y"

If at least one integer is null, LCM is equal to 0.

Your function must be prototyped as follows:

 unsigned int    lcm(unsigned int a, unsigned int b);
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

unsigned int    lcm(unsigned int a, unsigned int b)
{
	unsigned int i;

	if (!a || !b)
		return (0);
	i = (a > b) ? a : b;

	while (i != a * b)
	{
		if (!(i % a) && !(i % b))
			return (i);
		i++;
	}
	return (i);
}

int main(int ac, char **av)
{
	int a;
	int b;

	if (ac == 3)
	{
		a = atoi(av[1]);
		b = atoi(av[2]);
		printf("%d\n", lcm(a, b));
	}
	return (0);
}