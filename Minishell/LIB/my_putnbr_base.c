/*
** my_putnbr_base.c for my putnbr base in /home/volpe_p/rendu/Piscine-C-Jour_06/ex_15
** 
** Made by volpe
** Login   <volpe_p@epitech.net>
** 
** Started on  Wed Oct  9 12:34:15 2013 volpe
** Last update Sun Nov 24 19:48:47 2013 lardet
*/

int	my_putnbr_base(int nbr, char *base)
{
  int	i;

  i = 0;
  i = my_strlen(base);
  if (nbr < 0)
    {
      my_putchar('-');
      nbr = nbr * -1;
    }
  if (nbr >= i)
    {
      my_putnbr_base(nbr / i, base);
      my_putnbr_base(nbr % i, base);
    }
  else
    my_putchar(base[nbr]);
}
