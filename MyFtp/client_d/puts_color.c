/*
** puts_color.c for putscolor in /home/lardet_e/TP/my_ftp/begin/client
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Fri Apr 11 17:49:58 2014 lardet
** Last update Sun Apr 13 23:22:02 2014 lardet
*/

#include "client.h"

void	puts_color(char *s, char *color)
{
  write(1, color, strlen(color));
  write(1, s, strlen(s));
  write(1, WHITE, strlen(WHITE));
}
