//
// Egg.cpp for Egg in /home/volpe_p/rendu/Zappy/PSU_2013_zappy/graphicClientSources
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Sat Jul  5 21:45:24 2014 volpe
// Last update Thu Jul 10 23:23:30 2014 volpe
//

#include	"../headers/Egg.hh"

Egg::Egg(int id, int id_player, int x, int y)
{
  this->id = id;
  this->id_player = id_player;
  this->x = x;
  this->y = y;
  this->state = CREATED;
}

Egg::~Egg()
{
}

void		Egg::setX(int x)
{
  this->x = x;
}

void		Egg::setY(int y)
{
  this->y = y;
}

void		Egg::setId(int id)
{
  this->id = id;
}

void		Egg::setIdPlayer(int idplayer)
{
  this->id_player = idplayer;
}

int		Egg::getX() const
{
  return (this->x);
}

int		Egg::getY() const
{
  return (this->y);
}

int		Egg::getId() const
{
  return (this->id);
}

int		Egg::getIdPlayer() const
{
  return (this->id_player);
}

void		Egg::hatch()
{
  this->state = HATCHED;
  std::cout << "L'oeuf d'id :" << this->id << " éclos !!!!" << std::endl;
}

void	       Egg::die()
{
  this->state = DIED;
  std::cout << "L'oeuf est mort :'(" << std::endl;
}
