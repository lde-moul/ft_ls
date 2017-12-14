#include "../libft.h"
#include <stdio.h>

#define TEST_RETURN(f) if ((ft_ ## f) != (f))

int	main(void)
{
	char t[6];

	ft_memset(t, '\0', 6);
	ft_memset(t, '4', 5);

	printf("%s", t);

	return (0);
}
