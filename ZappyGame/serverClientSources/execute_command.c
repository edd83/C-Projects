/*
** execute_command.c for execute_command in /home/lardet_e/PSU_2013_zappy/serverClientSources
** 
** Made by lardet
** Login   <lardet_e@epitech.net>
** 
** Started on  Mon Jul  7 16:38:06 2014 lardet
** Last update Fri Jul 18 13:43:01 2014 Fabien Casoni
*/

#include "server.h"

t_execute		*init_command()
{
  static t_execute	command;

  command.id[0] = 1;
  command.id[1] = 2;
  command.id[2] = 3;
  command.id[3] = 4;
  command.id[4] = 5;
  command.id[5] = 6;
  command.id[6] = 7;
  command.id[7] = 8;
  command.id[8] = 9;
  command.id[9] = 10;
  command.id[10] = 11;
  command.func_ptr[0] = &avance_exec;
  command.func_ptr[1] = &left_exec;
  command.func_ptr[2] = &right_exec;
  command.func_ptr[3] = &see_exec;
  command.func_ptr[4] = &inventory_exec;
  command.func_ptr[5] = &take_exec;
  command.func_ptr[6] = &put_exec;
  command.func_ptr[7] = &expulse_exec;
  command.func_ptr[8] = &broadcast_exec;
  command.func_ptr[9] = &lvl_up_exec;
  command.func_ptr[10] = &eggs_exec;
  return (&command);
}

void			execute_command(int id, t_player *player, t_server *serv)
{
  t_execute		*command;
  int			i;
  int			ok;

  ok = -1;
  i = 0;
  command = init_command();
  while (i < 11)
    {
      if (command->id[i] == id)
	ok = (*(command->func_ptr[i]))(player, serv);
      i++;
    }
  (void)ok;
  (void)serv;
}

int			eggs_exec(t_player *player, t_server *serv)
{
  int			len;
  int			len2;
  int			nb;
  char			buff[4096];
  char			buff2[4096];

  nb = add_eggs(serv, player->x, player->y);
  len = sprintf(buff, "ok\n");
  len2 = sprintf(buff2, "enw %d %d %d %d\n", nb,
		 (int)player->id, (int)player->x, (int)player->y);
  if (send(player->fd, buff, len, 0) == -1 ||
      send(serv->fd_graphic, buff2, len2, 0) == -1)
    return (-1);
  return (0);
}
