/*
** my_fprintf.c for my_printf in /home/volpe_p/rendu/malloc
** 
** Made by volpe
** Login   <volpe_p@epitech.net>
** 
** Started on  Wed Feb 12 12:41:55 2014 volpe
** Last update Sun Feb 16 15:17:16 2014 lardet
*/

#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdarg.h>
#include "malloc.h"

static int	my_putchar(int fd, char c)
{
  int	x;

  x = write(fd, &c, 1);
  return (x);
}

static void	my_putnbr(int fd, int nb)
{
  int	beg;
  int	end;

  if (nb < 0)
    {
      my_putchar(fd, '-');
      my_putnbr(fd, -nb);
    }
  else
    {
      end = nb % 10;
      beg = nb / 10;
      if (beg != 0)
	my_putnbr(fd, beg);
      my_putchar(fd, end + '0');
    }
}

static int	my_putstr(int fd, char *str)
{
  int	x;

  x = write(fd, str, strlen(str));
  return (x);
}

static void	my_putnbr_base(int fd, int nbr)
{
  int		beg;
  int		end;
  int		p;
  char		*base;

  p = 16;
  base = "0123456789ABCDEF";
  if (nbr < 0)
    {
      my_putchar(fd, '-');
      my_putnbr_base(fd, -nbr);
    }
  else
    {
      end = nbr % p;
      beg = (nbr - end) / p;
      if (beg != 0)
	my_putnbr_base(fd, beg);
      my_putchar(fd, base[end]);
    }
}

int		my_printf(const int fd, char *src, ...)
{
  va_list	ap;

  va_start(ap, src);
  while (*src != '\0')
    {
      if (*src == '%')
	{
	  src++;
	  if (*src == 'd')
	    my_putnbr(fd, va_arg(ap, int));
	  else if (*src == 'c')
	    my_putchar(fd, va_arg(ap, int));
	  else if (*src == 's')
	    my_putstr(fd, va_arg(ap, char *));
	  else if (*src == 'x')
	    my_putnbr_base(fd, va_arg(ap, int));
	}
      else
	my_putchar(fd, *src);
      src++;
    }
  return (0);
}
