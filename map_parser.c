/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:48:33 by ysemlali          #+#    #+#             */
/*   Updated: 2024/03/15 23:24:35 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"
#include <fcntl.h>
#include <stdio.h>

// int	map_rules(char **map, int line_count)
// {
// 	t_map	map_info;
// 	int		i;
// 	int		x;

// 	i = 0;
// 	map_info.p_count = 0;
// 	map_info.c_count = 0;
// 	map_info.e_count = 0;
// 	while (map[i] != NULL)
// 	{
// 		x = 0;
// 		while (map[i][x] != '\0')
// 		{
// 			if (map[i][x] == 'P')
// 				map_info.p_count++;
// 			else if (map[i][x] == 'C')
// 				map_info.c_count++;
// 			else if (map[i][x] == 'E')
// 				map_info.e_count++;
// 			x++;
// 		}
// 		i++;
// 	}
// 	if (map_info.p_count != 1 || map_info.c_count < 1 || map_info.e_count != 1)
// 		return (0);
// 	if (map_rect(map, line_count) == 0)
// 		return (0);
// 	return (1);
// }

// int	map_rect(char **map, int line_count)
// {
// 	int	i;
// 	int	x;

// 	i = 0;
// 	x = 0;
// 	printf("%c\n", map[0][ft_strlen(map[0]) - 1]);
// 	while (map[i])
// 	{
// 		while (map[i][0] == '1' && map[ft_strlen(map[i]) - 1] == '1')
// 			i++;
// 		if (i == line_count)
// 		{
// 			while (map[i][x])
// 			{
// 				if (map[i][x] != '1' && map[line_count][x] != '1')
// 					return (0);
// 				x++;
// 			}
// 		}
// 		else
// 			return (0);
// 	}
// 	return (1);
// }

int ft_strrchr(const char *s, const char c)
{
	int i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == c)
			return (i);
	}
	return (-1);
}
int valid_border(const char **s, int line_count, int line_length)
{
	int i = 0;
	if (s != NULL && *s != NULL)
		return 0;
	
	if ((ft_strrchr(s[0], '1') != line_length - 1) || (ft_strrchr(s[line_count - 1], '1') != line_length - 1))
		return (printf("Error\n"), exit(1), 0);
	else
	{
		while(s[i] != NULL)
			{
				if  (s[i][0] != '1' || s[i][line_length] != '1')
						return (printf("Error\n"), exit(1), 0);
				else
					i++;
			}
	}
	return (1);
}

int	ft_strspn(const char *s, const char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

int	map_parser(int fd, int line_count)
{
	t_map	map_info;
	int		i;
	char	*map;
	char	**map_lines;

	i = 0;
	map_info.line_length = 0;
	map_lines = malloc(line_count * sizeof(char *));
	map = get_next_line(fd);
	while (map != NULL)
	{
		map[ft_strspn(map, '\n')] = '\0';
		printf("%s %zu\n", map, ft_strlen(map));
		if (map_info.line_length == 0)
			map_info.line_length = ft_strlen(map);
		else if (map_info.line_length != ft_strlen(map))
			return (printf("Error\n"), exit(1), 0);
		map_lines[i] = map;
		map = get_next_line(fd);
		i++;
	}
	map_lines[i] = NULL;
	printf("%d\n", ft_strrchr(map_lines[0], '1'));
	return (printf("Success\n"), 1);
}

int	main(void)
{
	t_map	map_info;
	char	*map;
	int		fd;

	map_info.line_count = 0;
	fd = open("map.ber", O_RDONLY);
	map = get_next_line(fd);
	while (map != NULL)
	{
		map_info.line_count++;
		free(map);
		map = get_next_line(fd);
	}
	close(fd);
	fd = open("map.ber", O_RDONLY);
	map_parser(fd, map_info.line_count);
	close(fd);
}
