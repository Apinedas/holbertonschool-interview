#include "sandpiles.h"

/**
 * check_unstable - Checks if a 3x3 grid is unstable
 * @grid1: 3x3 grid
 * Return: 1 for unstable, 0 for stable
 */

int check_unstable(int grid1[3][3])
{
	int i = 0, j = 0;

	while (i < 3)
	{
		while (j < 3)
		{
			if (grid1[i][j] > 3)
				return (1);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * sandpiles_toppling - Sandpile topping
 * @grid1: First sandpile
 */

void sandpiles_toppling(int grid1[3][3])
{
	int i = 0, j = 0, k = 0, l = 0, copy_grid[3][3];

	if (check_unstable(grid1))
	{
		while (i < 3)
		{
			while (j < 3)
			{
				copy_grid[i][j] = grid1[i][j];
				j++;
			}
			i++;
			j = 0;
		}
		printf("=\n");
		print_grid(grid1);

		while (k < 3)
		{
			while (l < 3)
			{
				if (grid1[k][l] > 3 && copy_grid[k][l] > 3)
				{
					grid1[k][l] -= 4;
					if (k - 1 >= 0)
						grid1[k - 1][l] += 1;
					if (k + 1 < 3)
						grid1[k + 1][l] += 1;
					if (l - 1 >= 0)
						grid1[k][l - 1] += 1;
					if (l + 1 < 3)
						grid1[k][l + 1] += 1;
				}
				l++;
			}
			k++;
			l = 0;
		}
		sandpiles_toppling(grid1);
	}
}

/**
 * sandpiles_sum - Sums 2 sandpiles
 * @grid1: First sandpile
 * @grid2: Second sandpile
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i = 0, j = 0;

	while (i < 3)
	{
		while (j < 3)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
			j++;
		}
		i++;
		j = 0;
	}
	sandpiles_toppling(grid1);
}
