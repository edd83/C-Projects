//
// Inventory.cpp for Inventory in /home/volpe_p/rendu/Zappy/PSU_2013_zappy/graphicClientSources
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Sun Jul  6 05:04:23 2014 volpe
// Last update Sat Jul 19 16:08:25 2014 volpe
//

#include        "../headers/Inventory.hh"
#include	<iostream>

Inventory::Inventory()
{
  this->food = 0;
  this->linemate = 0;
  this->deraumere = 0;
  this->sibur = 0;
  this->mendiane = 0;
  this->phiras = 0;
  this->thystame = 0;
}

Inventory::Inventory(int food, int linemate, int deraumere, int sibur, int mendiane, int phiras, int thystame)
{
  this->food = food;
  this->linemate = linemate;
  this->deraumere = deraumere;
  this->sibur = sibur;
  this->mendiane = mendiane;
  this->phiras = phiras;
  this->thystame = thystame;
}

Inventory::~Inventory()
{
}

// Debut -- Getters && Setters

int		Inventory::getFood() const
{
  return (this->food);
}

int		Inventory::getLinemate() const
{
  return (this->linemate);
}

int		Inventory::getDeraumere() const
{
  return (this->deraumere);
}

int		Inventory::getSibur() const
{
  return (this->sibur);
}

int		Inventory::getMendiane() const
{
  return (this->mendiane);
}

int		Inventory::getPhiras() const
{
  return (this->phiras);
}

int	       Inventory::getThystame() const
{
  return (this->thystame);
}

void		Inventory::setFood(int food)
{
  this->food = food;
}

void		Inventory::setLinemate(int linemate)
{
  this->linemate = linemate;
}

void		Inventory::setDeraumere(int deraumere)
{
  this->deraumere = deraumere;
}

void		Inventory::setSibur(int sibur)
{
  this->sibur = sibur;
}

void		Inventory::setMendiane(int mendiane)
{
  this->mendiane = mendiane;
}

void		Inventory::setPhiras(int phiras)
{
  this->phiras = phiras;
}

void		Inventory::setThystame(int thystame)
{
  this->thystame = thystame;
}

// Fin -- Getters && Setters

void		Inventory::addRes(int id)
{
  switch (id)
    {
    case 0:
      this->setFood(this->food + 1);
      break;
    case 1:
      this->setLinemate(this->linemate + 1);
      break;
    case 2:
      this->setDeraumere(this->deraumere + 1);
      break;
    case 3:
      this->setSibur(this->sibur + 1);
      break;
    case 4:
      this->setMendiane(this->mendiane + 1);
      break;
    case 5:
      this->setPhiras(this->phiras + 1);
      break;
    case 6:
      this->setThystame(this->thystame + 1);
      break;
    }
}

void		Inventory::delRes(int id)
{
  switch (id)
    {
    case 0:
      this->setFood(this->getFood() -1);
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
