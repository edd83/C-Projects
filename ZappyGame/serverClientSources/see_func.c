/*
** see_func.c for zappy in /home/casoni_f/Projets/PSU_2013_zappy/serverClientSources
** 
** Made by Fabien Casoni
** Login   <casoni_f@epitech.net>
** 
** Started on  Fri Jul  4 11:55:37 2014 Fabien Casoni
** Last update Sun Jul 13 19:13:26 2014 Fabien Casoni
*/

#include "server.h"

int		see(char *buff, int fd, t_server *serv)
{
  t_player	*player;

  (void)buff;
  if ((player = search_player_by_fd(fd, serv)) == NULL)
    return (-1);
  fill_timeout(player, 7, serv, 4);
  return (0);
}

void		see_north(t_player *player, char *buff, t_server *serv)
{
  int		level;
  int		i;
  int		coord[2];

  level = 0;
  while (++level <= (int)player->level)
    {
      i = (-1 * level) - 1;
      while (++i <= level)
	{
	  coord[0] = player->x + i;
	  coord[1] = player->y - level;
	  check_ress_cli(player->x + i, player->y - level, buff, serv);
	  check_player_cli(coord, player->id, buff, serv);
	  if ((i + 1) <= level || (level + 1) <= (int)player->level)
	    sprintf(buff, "%s,", buff);
	}
    }
}

void		see_south(t_player *player, char *buff, t_server *serv)
{
  int		level;
  int		i;
  int		coord[2];

  level = 0;
  while (++level <= (int)player->level)
    {
      i = level + 1;
      while (--i >= (-1 * level))
	{
	  coord[0] = player->x + i;
	  coord[1] = player->y + level;
	  check_ress_cli(player->x + i, player->y + level, buff, serv);
	  check_player_cli(coord, player->id, buff, serv);
	  if ((i + 1) <= level || (level + 1) <= (int)player->level)
	    sprintf(buff, "%s,", buff);
	}
    }
}

void		see_east(t_player *player, char *buff, t_server *serv)
{
  int		level;
  int		i;
  int		coord[2];

  level = 0;
  while (++level <= (int)player->level)
    {
      i = (-1 * level) - 1;
      while (++i <= level)
	{
	  coord[0] = player->x + level;
	  coord[1] = player->y + i;
	  check_ress_cli(player->x + level, player->y + i, buff, serv);
	  check_player_cli(coord, player->id, buff, serv);
	  if ((i + 1) <= level || (level + 1) <= (int)player->level)
	    sprintf(buff, "%s,", buff);
	}
    }
}

void		see_west(t_player *player, char *buff, t_server *serv)
{
  int		level;
  int		i;
  int		coord[2];

  level = 0;
  while (++level <= (int)player->level)
    {
      i = level + 1;
      while (--i >= (-1 * level))
	{
	  coord[0] = player->x - level;
	  coord[1] = player->y + i;
	  check_ress_cli(player->x - level, player->y + i, buff, serv);
	  check_player_cli(coord, player->id, buff, serv);
	  if ((i + 1) <= level || (level + 1) <= (int)player->level)
	    sprintf(buff, "%s,", buff);
	}
    }
}
