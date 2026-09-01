#ifndef FTPRINTF
#define FTPRINTF

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int ft_printf(const char *, ...);
int ft_ctoa(char);
int	ft_atoa(char *);
int	ft_itoa(int);
int	ft_utoa(unsigned int);
int	ft_xtoa(unsigned int);
int	ft_Xtoa(unsigned int);
int	ft_ptoa(void *);
int	ft_percenttoa(void);

#endif
