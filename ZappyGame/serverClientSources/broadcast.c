/*
** broadcast.c for Zappy in /home/casoni_f/Projets/PSU_2013_zappy/serverClientSources
** 
** Made by Fabien Casoni
** Login   <casoni_f@epitech.net>
** 
** Started on  Sun Jul 20 15:59:40 2014 Fabien Casoni
** Last update Sun Jul 20 19:57:53 2014 Fabien Casoni
*/

#include	"server.h"

void		init_ptr(int (*dPtr[9])(int, int, int, int))
{
  dPtr[0] = &center;
  dPtr[1] = &north;
  dPtr[2] = &north_west;
  dPtr[3] = &west;
  dPtr[4] = &south_west;
  dPtr[5] = &south;
  dPtr[6] = &south_east;
  dPtr[7] = &east;
  dPtr[8] = &north_east;
}

int		direction_broadcast(int *coord, int direction)
{
  int		(*dPtr[9])(int, int, int, int);
  unsigned int	counter;
  unsigned int	ct;

  init_ptr(dPtr);
  counter = -1;
  if (coord[0] < 0 || coord[1] < 0 || coord[2] < 0 || coord[3] < 0)
    return (_FALSE_);
  while (++counter < 9)
    {
      if (dPtr[counter](coord[0], -coord[1], coord[2], -coord[3]) == _TRUE_)
	{
	  if (counter != 0)
	    {
	      ct = counter;
	      counter = (counter + (2 * (direction))) % 8;
	      if (ct != 0 && direction != 0 && counter == 0)
		counter = 8;
	    }
	  return (counter);
	}
    }
  return (_FALSE_);
}

int		center(int sendX, int sendY, int recvX, int recvY)
{
  if (sendX == recvX && sendY == recvY)
    return (_TRUE_);
  return (_FALSE_);
}

int		north(int sendX, int sendY, int recvX, int recvY)
{
  float		res;

  if (sendY > recvY)
    {
      res = ((float)sendY - (float)recvY) / ((float)sendX - (float)recvX);
      if (res >= 2 || res <= -2)
	return (_TRUE_);
    }
  return (_FALSE_);
}

int		north_west(int sendX, int sendY, int recvX, int recvY)
{
  float		res;

  if (sendY > recvY && sendX < recvX)
    {
      res = ((float)sendY - (float)recvY) / ((float)sendX - (float)recvX);
      if (res > -2 && res < -0.5)
	return (_TRUE_);
    }
  return (_FALSE_);
}
