#include "sandpiles.h"

/**
 * print_grid - prints a 3x3 grid
 * @grid: 3x3 grid to print
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
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
 * is_stable - checks if a sandpile is stable
 * @grid: 3x3 grid to check
 *
 * Return: 1 if stable, 0 if unstable
 */
static int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}
	return (1);
}

/**
 * topple - performs one toppling round on an unstable sandpile
 * @grid: 3x3 grid to topple
 */
static void topple(int grid[3][3])
{
	int i, j;
	int temp[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				temp[i][j] -= 4;
				if (i - 1 >= 0)
					temp[i - 1][j] += 1;
				if (i + 1 < 3)
					temp[i + 1][j] += 1;
				if (j - 1 >= 0)
					temp[i][j - 1] += 1;
				if (j + 1 < 3)
					temp[i][j + 1] += 1;
			}
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid[i][j] += temp[i][j];
		}
	}
}

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: first 3x3 grid (will contain the result)
 * @grid2: second 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}

	while (!is_stable(grid1))
	{
		print_grid(grid1);
		topple(grid1);
	}
}
