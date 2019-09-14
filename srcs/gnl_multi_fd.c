/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 11:54:58 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/13 17:04:03 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*strjoin(char *s1, char *s2, int total, int ret)
{
	char	*str;
	int		n;

	if (!(s1 && s2) || !(str = malloc(sizeof(char) * (total + 1))))
	{
		free(s1);
		return (0);
	}
	n = -1;
	ft_strcpy(str, s1);
	while (s2[++n])
		str[total - ret + n] = s2[n];
	str[total - ret + n] = '\0';
	free(s1);
	return (str);
}

static int	get_all(const int fd, char **mem)
{
	int		ret;
	int		total;
	char	buf[BUFF_SIZE + 1];

	total = -1;
	while (mem[fd][++total])
		if (mem[fd][total] == '\n')
			return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		total += ret;
		if (!(mem[fd] = strjoin(mem[fd], buf, total, ret)))
			return (0);
		total -= ret;
		while (mem[fd][total])
			if (mem[fd][total++] == '\n')
				return (1);
	}
	return (1);
}

int		error_strdel(void **mem, int error)
{
	if (mem && *mem)
	{
		free(*mem);
		*mem = 0;
	}
	return (error);
}

int			gnl_multi_fd(const int fd, char **line)
{
	static char	*mem[4864];
	int			n;
	char		*tmp;

	if (BUFF_SIZE < 1 || read(fd, 0, 0) < 0 || !line || fd < 0)
		return (error_strdel((void**)&mem[fd], -1));
	if (!mem[fd])
		mem[fd] = ft_memalloc(1);
	if (!get_all(fd, mem))
			return (-1);
	n = -1;
	while (mem[fd][++n] != '\n' && mem[fd][n] != '\0')
		;
	if (n == 0 && mem[fd][n] == '\0')
		return (error_strdel((void**)&mem[fd], 0));
	mem[fd][n] = 0;
	if (!(*line = ft_strdup(mem[fd])))
		return (error_strdel((void**)&mem[fd], -1));
	tmp = mem[fd];
	if (!(mem[fd] = ft_strdup(&tmp[n + 1])))
		return (error_strdel((void**)&tmp, -1));
	free(tmp);
	return (1);
}
