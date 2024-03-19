#include <stdlib.h>
#include <stdio.h>
#include "t_point.h"

void	floodfill2(char **tab, char a, t_point size, t_point pos)
{
	t_point		point[4];

	point[0].x = pos.x;
	point[0].y = pos.y + 1;
	point[1].x = pos.x;
	point[1].y = pos.y - 1;
	point[2].x = pos.x + 1;
	point[2].y = pos.y;
	point[3].x = pos.x - 1;
	point[3].y = pos.y;

	if (pos.x >= 0 && pos.x < size.x && pos.y >= 0 && pos.y < size.y)
	{
		if (tab[pos.y][pos.x] == 'F' || tab[pos.y][pos.x] != a)
			return ;
		tab[pos.y][pos.x] = 'F';
		floodfill2(tab, a, size, point[0]);
		floodfill2(tab, a, size, point[1]);
		floodfill2(tab, a, size, point[2]);
		floodfill2(tab, a, size, point[3]);
	}
}

void	floodfill(char **tab, t_point size, t_point begin)
{
	char	a;

	a = tab[begin.y][begin.x];
	floodfill2(tab, a, size, begin);
}

// DO NOT DO THOS 

char		**create_tab(char area[5][5], t_point size)
{
	char	**ret;
	int	x;
	int	y;
	
	x = 0;
	y = 0;
	ret = (char **)malloc(sizeof(char *) * size.y);
	while (y < size.y)
	{
		x = 0;
		ret[y] = (char *)malloc(sizeof(char) * size.x);
		while (x < size.x)
		{
			ret[y][x] = area[y][x];
			x++;
		}
		y++;
	}
	return (ret);
}

void		print_tab(char **tab, t_point size)
{
	for (int i = 0; i < size.y; i++)
	{
		for (int j = 0; j < size.x; j++)
		{
			printf("%c", tab[i][j]);
		}
		printf("\n");
	}
}

int		main(void)
{
	char	tab[5][5] = {
		"11111",
		"10001",
		"10110",
		"00000",
		"11111"};
	char	**area;	
	
	t_point	size = {5, 5};
	t_point	begin = {1, 1};
	area = create_tab(tab, size);
	print_tab(area, size);
	floodfill(area, size, begin);
	print_tab(area, size);
	return (0);
}
