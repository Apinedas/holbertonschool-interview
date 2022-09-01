#include "sandpiles.h"

int check_unstable(int grid1[3][3])
{
    int i = 0, j = 0;

    while (i < 3)
    {
        while (j < 3)
        {
            if (grid1[i][j] > 3)
                return 1;
            j++;
        }
        i++;
        j = 0;
    }
    return 0;
}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
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
    int i = 0, j = 0;

    if (check_unstable(grid1))
    {
        printf("=\n");
        print_grid(grid1);
        while (j < 3)
        {
            while (i < 3)
            {
                if (grid1[i][j] > 3)
                {
                    grid1[i][j] -= 4;
                    if (i - 1 >= 0)
                        grid1[i - 1][j] += 1;
                    if (i + 1 < 3)
                        grid1[i + 1][j] += 1;
                    if (j - 1 >= 0)
                        grid1[i][j - 1] += 1;
                    if (j + 1 < 3)
                        grid1[i][j + 1] += 1;
                }
                i++;
            }
            j++;
            i = 0;
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
