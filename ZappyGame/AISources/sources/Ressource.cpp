//
// Ressource.cpp for zappy in /home/ovoyan_s/rendu/PSU_2013_zappy/AISources
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Thu Jun 19 12:02:54 2014 ovoyan_s
// Last update Fri Jul 18 14:28:21 2014 ovoyan_s
//

/*
**			MY INCLUDES
*/

#include		"Ressource.hh"

Ressource::Ressource()
{
  this->coordX = 0;
  this->coordX = 0;
  this->typeOfRessource = RessourceNS::food;
  this->isInAction = false;
}

Ressource::Ressource(const Ressource &ressourceToSet)
{
  this->setCoordX(ressourceToSet.getCoordX());
  this->setCoordY(ressourceToSet.getCoordY());
  this->setRessourceType(ressourceToSet.getRessourceType());
  this->setIsInAction(ressourceToSet.getIsInAction());
}

void				Ressource::setCoordX(int coordToSetX)
{
  this->coordX = coordToSetX;
}

void				Ressource::setCoordY(int coordToSetY)
{
  this->coordY = coordToSetY;
}

void				Ressource::setRessourceType(const RessourceNS::ressourceType
							    &ressourceToSet)
{
  this->typeOfRessource = ressourceToSet;
}

void				Ressource::setIsInAction(const bool &isInAction)
{
  this->isInAction = isInAction;
}

int				Ressource::getCoordX() const
{
  return (this->coordX);
}

int				Ressource::getCoordY() const
{
  return (this->coordY);
}

RessourceNS::ressourceType	Ressource::getRessourceType() const
{
  return (this->typeOfRessource);
}

bool				Ressource::getIsInAction() const
{
  return (this->isInAction);
}

Ressource::~Ressource()
{

}
