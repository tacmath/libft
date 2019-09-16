/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error_free.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mtaquet <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/16 12:45:26 by mtaquet      #+#   ##    ##    #+#       */
/*   Updated: 2019/09/16 12:46:26 by mtaquet     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		error_strdel(void **mem, int error)
{
	if (mem && *mem)
	{
		free(*mem);
		*mem = 0;
	}
	return (error);
}

int		error_free(void *mem, int error)
{
	free(mem);
	return (error);
}
