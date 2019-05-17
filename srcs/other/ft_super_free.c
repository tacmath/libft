#include <stdarg.h>
#include <stdlib.h>

int ft_super_free(int nb_arg, ...)
{
	va_list	ap;
	
	va_start(ap, nb_arg);
	while (nb_arg--)
		free(va_arg(ap, void*));
	va_end(ap);
	return (0);
}
