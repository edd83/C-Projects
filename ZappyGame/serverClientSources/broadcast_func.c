/*
** broadcast_func.c for Zappy in /home/casoni_f/Projets/PSU_2013_zappy/serverClientSources
** 
** Made by Fabien Casoni
** Login   <casoni_f@epitech.net>
** 
** Started on  Sun Jul 20 15:57:42 2014 Fabien Casoni
** Last update Sun Jul 20 19:58:19 2014 Fabien Casoni
*/

#include	"server.h"

int		west(int sendX, int sendY, int recvX, int recvY)
{
  float		res;

  if (sendX < recvX)
    {
      res = ((float)sendY - (float)recvY) / ((float)sendX - (float)recvX);
      if (res <= 0.5 && res >= -0.5)
	return (_TRUE_);
    }
  return (_FALSE_);
}

int		south_west(int sendX, int sendY, int recvX, int recvY)
{
  float		res;

  if (sendY < recvY && sendX < recvX)
    {
      res = ((float)sendY - (float)recvY) / ((float)sendX - (float)recvX);
      if (res < 2 && res > 0.5)
	return (_TRUE_);
    }
  return (_FALSE_);
}

int		south(int sendX, int sendY, int recvX, int recvY)
{
  float		res;

  if (sendY < recvY)
    {
      res = ((float)sendY - (float)recvY) / ((float)sendX - (float)recvX);
      if (res >= 2 || res <= -2)
	return (_TRUE_);
    }
  return (_FALSE_);
}

int		south_east(int sendX, int sendY, int recvX, int recvY)
{
  float		res;

  if (sendY < recvY && sendX > recvX)
    {
      res = ((float)sendY - (float)recvY) / ((float)sendX - (float)recvX);
      if (res > -2 && res < -0.5)
	return (_TRUE_);
    }
  return (_FALSE_);
}

int		east(int sendX, int sendY, int recvX, int recvY)
{
  float		res;

  if (sendX > recvX)
    {
      res = ((float)sendY - (float)recvY) / ((float)sendX - (float)recvX);
      if (res <= 0.5 && res >= -0.5)
	return (_TRUE_);
    }
  return (_FALSE_);
}
