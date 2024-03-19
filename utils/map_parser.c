/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:48:33 by ysemlali          #+#    #+#             */
/*   Updated: 2024/03/19 03:06:40 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "get_next_line.h"

int	map_rules(char **map)
{
	t_map	map_info;
	int		i;

	i = 0;
	map_info.p_count = 0;
	map_info.c_count = 0;
	map_info.e_count = 0;
	while (map[i] != NULL)
	{
		count_characters(map[i], &map_info);
		i++;
	}
	printf("%d %d %d\n", map_info.p_count, map_info.c_count, map_info.e_count);
	if (map_info.p_count != 1 || map_info.c_count < 1 || map_info.e_count != 1)
		return (printf("Error\n"), exit(1), 0);
	return (1);
}

int	valid_border(const char **s, int l_count, int l_length)
{
	int	i;

	i = 0;
	if (s == NULL && *s == NULL)
		return (printf("Error\n"), exit(1), 0);
	if ((ft_strrchr(s[0], '1') != -1) || (ft_strrchr(s[l_count], '1') != -1))
		return (printf("Error\n"), exit(1), 0);
	while (s[i] != NULL)
	{
		if (s[i][0] != '1' || s[i][l_length] != '1')
			return (printf("Error\n"), exit(1), 0);
		i++;
	}
	return (1);
}

int	map_parser(int fd, int line_count)
{
	t_map	map_info;
	int		i;
	char	*map;
	char	**map_lines;

	i = 0;
	map_info.l_len = 0;
	map_lines = malloc(line_count * sizeof(char *));
	map = get_next_line(fd);
	while (map != NULL)
	{
		map[ft_strspn(map, '\n')] = '\0';
		if (map_info.l_len == 0)
			map_info.l_len = ft_strlen(map);
		else if ((size_t)map_info.l_len != ft_strlen(map))
			return (printf("Error\n"), exit(1), 0);
		map_lines[i] = map;
		map = get_next_line(fd);
		i++;
	}
	map_lines[i] = NULL;
	valid_border((const char **)map_lines, line_count - 1, map_info.l_len - 1);
	map_rules(map_lines);
	return (printf("Success\n"), 1);
}

int	main(void)
{
	int		line_count;
	char	*map;
	int		fd;

	line_count = 0;
	fd = open("../map/map.ber", O_RDONLY);
	if (fd == -1)
		return (printf("Error No such file\n"), 0);
	map = get_next_line(fd);
	while (map != NULL)
	{
		line_count++;
		free(map);
		map = get_next_line(fd);
	}
	close(fd);
	fd = open("../map/map.ber", O_RDONLY);
	if (fd == -1)
		return (printf("Error No such file\n"), 0);
	map_parser(fd, line_count);
	close(fd);
}
