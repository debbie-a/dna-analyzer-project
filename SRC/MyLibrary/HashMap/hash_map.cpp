#include "hash_map.h"

size_t defaultHashFunc(const std::string &key, size_t hashSize)
{
	size_t size = key.size(), sumAll = 0, evenMult = 1, oddMult = 1;
        for (size_t i = 0; i < size; i++) 
	{
                sumAll += key[i];

                if (i % 2 == 0)
		{
                        evenMult *= key[i];
		}
                else
                {
			oddMult *= key[i];
		}
        }

        return (size * sumAll * (evenMult + oddMult)) % hashSize;
}

bool isPrime(size_t num)
{
	if (num == 1)
		return false;

	for (size_t i = 2; i * i <= num; i++)
	{
		if ((num % i) == 0)
		{
			return false;
		}
	}

	return true;
}

size_t getClosestBigEnoughPrime(size_t num)
{
	size_t i = 0;
	while (true)
	{
		if (isPrime(num + i))
		{
			return num + i;
		}
		i++;
	}

	return 0;
}

