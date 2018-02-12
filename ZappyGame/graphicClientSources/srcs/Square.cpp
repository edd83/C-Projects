//
// Square.cpp for Square in /home/volpe_p/rendu/Zappy/PSU_2013_zappy/graphicClientSources/headers
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Tue Jun 24 11:08:04 2014 volpe
// Last update Sat Jul 19 17:05:45 2014 volpe
//

#include	"../headers/Square.hh"

Square::Square(int x, int y)
{
  this->_x = x;
  this->_y = y;
  this->_food = 0;
  this->_linemate = 0;
  this->_deraumere = 0;
  this->_sibur = 0;
  this->_mendiane = 0;
  this->_phiras = 0;
  this->_thystame = 0;
}

Square::~Square()
{
}


void	Square::setContentCase(int food, int linemate, int deraumere, int sibur, int mendiane, int phiras, int thystame)
{
  this->_food = food;
  this->_linemate = linemate;
  this->_deraumere = deraumere;
  this->_sibur = sibur;
  this->_mendiane = mendiane;
  this->_phiras = phiras;
  this->_thystame = thystame;
}

int	Square::getNbItemsOnSquare()
{
  int	i = 0;

  if (this->_food > 0)
    i++;
  if (this->_linemate > 0)
    i++;
  if (this->_deraumere > 0)
    i++;
  if (this->_sibur > 0)
    i++;
  if (this->_mendiane > 0)
    i++;
  if (this->_phiras > 0)
    i++;
  if (this->_thystame > 0)
    i++;
  return (i);
}

int	Square::getX() const
{
  return (this->_x);
}

int	Square::getY() const
{
  return (this->_y);
}

int	Square::getFood() const
{
  return (this->_food);
}

int	Square::getLinemate() const
{
  return (this->_linemate);
}

int	Square::getDeraumere() const
{
  return (this->_deraumere);
}

int	Square::getSibur() const
{
  return (this->_sibur);
}

int	Square::getMendiane() const
{
  return (this->_mendiane);
}

int	Square::getPhiras() const
{
  return (this->_phiras);
}

int	Square::getThystame() const
{
  return (this->_thystame);
}

void	Square::setFood(int food)
{
  this->_food = food;
}

void	Square::setLinemate(int linemate)
{
  this->_linemate = linemate;
}

void	Square::setDeraumere(int deraumere)
{
  this->_deraumere = deraumere;
}

void	Square::setSibur(int sibur)
{
  this->_sibur = sibur;
}

void	Square::setMendiane(int mendiane)
{
  this->_mendiane = mendiane;
}

void	Square::setPhiras(int phiras)
{
  this->_phiras = phiras;
}

void	Square::setThystame(int thystame)
{
  this->_thystame = thystame;
}

void	Square::addRes(int idRes)
{
  switch (idRes)
    {
    case 0:
      this->setFood(this->getFood() + 1);
      break;
    case 1:
      this->setLinemate(this->getLinemate() + 1);
      break;
    case 2:
      this->setDeraumere(this->getDeraumere() + 1);
      break;
    case 3:
      this->setSibur(this->getSibur() + 1);
      break;
    case 4:
      this->setMendiane(this->getMendiane() + 1);
      break;
    case 5:
      this->setPhiras(this->getPhiras() + 1);
      break;
    case 6:
      this->setThystame(this->getThystame() + 1);
      break;
    }      
}

void		Square::delRes(int id)
{
  switch (id)
    {
    case 0:
      this->setFood(this->getFood() - 1);
      break;
    case 1:
      this->setLinemate(this->getLinemate() - 1);
      break;
    case 2:
      this->setDeraumere(this->getDeraumere() - 1);
      break;
    case 3:
      this->setSibur(this->getSibur() - 1);
      break;
    case 4:
      this->setMendiane(this->getMendiane() - 1);
      break;
    case 5:
      this->setPhiras(this->getPhiras() - 1);
      break;
    case 6:
      this->setThystame(this->getThystame() - 1);
      break;
    }
}
