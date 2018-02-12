/*
** main.c for main in /home/lardet_e/TP/my_script
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Sun Mar  2 21:21:30 2014 lardet
** Last update Sun Mar  2 22:02:43 2014 lardet
*/

#include <termios.h>
#include <unistd.h>

int	main(int ac, char **av)
{
  struct termios attr;
  char	buffer[4096];

  printf("Please enter your password : ");
  if (tcgetattr(0 ,&attr) != 0)
    return (-1);

  attr.c_lflag &= (ICANON|ECHOE);

  attr.c_cc[VMIN] = 1;
 
  attr.c_cc[VTIME] = 0;
 
  if (tcsetattr (0, TCSADRAIN, &attr) == -1)
    return(-1);

  read(0, buffer, 50);

  printf("%s", buffer);

  attr.c_lflag |= ICANON;
  attr.c_lflag |= ECHO;

  if (tcsetattr (0, TCSADRAIN, &attr) == -1)
    return (-1);
  return (0);
}
