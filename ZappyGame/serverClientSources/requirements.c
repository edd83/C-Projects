/*
** requirements.c for zappy in /home/casoni_f/Projets/PSU_2013_zappy/serverClientSources
** 
** Made by Fabien Casoni
** Login   <casoni_f@epitech.net>
** 
** Started on  Wed Jul  9 12:09:35 2014 Fabien Casoni
** Last update Wed Jul  9 12:10:14 2014 Fabien Casoni
*/

#include	"server.h"

int		set_lvl_requirements(t_server *serv)
{
  serv->lvl_req[0][0] = 1;
  serv->lvl_req[0][1] = 1;
  serv->lvl_req[0][2] = 0;
  serv->lvl_req[0][3] = 0;
  serv->lvl_req[0][4] = 0;
  serv->lvl_req[0][5] = 0;
  serv->lvl_req[0][6] = 0;
  serv->lvl_req[1][0] = 2;
  serv->lvl_req[1][1] = 1;
  serv->lvl_req[1][2] = 1;
  serv->lvl_req[1][3] = 1;
  serv->lvl_req[1][4] = 0;
  serv->lvl_req[1][5] = 0;
  serv->lvl_req[1][6] = 0;
  serv->lvl_req[2][0] = 2;
  serv->lvl_req[2][1] = 2;
  serv->lvl_req[2][2] = 0;
  serv->lvl_req[2][3] = 1;
  serv->lvl_req[2][4] = 0;
  serv->lvl_req[2][5] = 2;
  serv->lvl_req[2][6] = 0;
  set_lvl_requirements2(serv);
  return (0);
}

void		set_lvl_requirements2(t_server *serv)
{
  serv->lvl_req[3][0] = 4;
  serv->lvl_req[3][1] = 1;
  serv->lvl_req[3][2] = 1;
  serv->lvl_req[3][3] = 2;
  serv->lvl_req[3][4] = 0;
  serv->lvl_req[3][5] = 1;
  serv->lvl_req[3][6] = 0;
  serv->lvl_req[4][0] = 4;
  serv->lvl_req[4][1] = 1;
  serv->lvl_req[4][2] = 2;
  serv->lvl_req[4][3] = 1;
  serv->lvl_req[4][4] = 3;
  serv->lvl_req[4][5] = 0;
  serv->lvl_req[4][6] = 0;
  serv->lvl_req[5][0] = 6;
  serv->lvl_req[5][1] = 1;
  serv->lvl_req[5][2] = 2;
  serv->lvl_req[5][3] = 3;
  serv->lvl_req[5][4] = 0;
  serv->lvl_req[5][5] = 1;
  serv->lvl_req[5][6] = 0;
  set_lvl_requirements3(serv);
}

void		set_lvl_requirements3(t_server *serv)
{
  serv->lvl_req[6][0] = 6;
  serv->lvl_req[6][1] = 2;
  serv->lvl_req[6][2] = 2;
  serv->lvl_req[6][3] = 2;
  serv->lvl_req[6][4] = 2;
  serv->lvl_req[6][5] = 2;
  serv->lvl_req[6][6] = 1;
}
