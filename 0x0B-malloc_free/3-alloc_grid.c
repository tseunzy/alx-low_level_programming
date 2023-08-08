#include "main.h"
#include <stdlib.h>
/**
 * alloc_grid - a function that returns a pointer to a 2 dimensional array
 * @width: width input
 * @height: height input
 * Return: pointer to 2 dim. array
 */
int **alloc_grid(int width, int height)
{
	int **mee;
	int x, y;

	if (width <= 0 || height <= 0)
	{
		return (NULL);
	}

	mee = malloc(sizeof(int *) * height);

	if (mee == NULL)
	{
		return (NULL);
	}

	for (x = 0; x < height; x++)
	{
		mee[x] = malloc(sizeof(int) * width);

		if (mee[x] == NULL)
		{
			for (y = 0; y < i; y++)
			{
				free(mee[y]);
			}

			free(mee);
			return (NULL);
		}
		for (y = 0; y < width; y++)
		{
			mee[x][y] = 0;
		}
	}

	return (mee);
}

