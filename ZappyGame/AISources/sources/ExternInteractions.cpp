//
// ExternInteractions.cpp for zappy in /home/ovoyan_s/rendu/PSU_2013_zappy/AISources
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Tue Jul  1 18:30:33 2014 ovoyan_s
// Last update Sat Jul 19 12:16:23 2014 ovoyan_s
//

/*
**				MY INCLUDES
*/

#include			"ExternInteractions.hh"

ExternInteractions::ExternInteractions()
{
  this->nbPlayer = 0;
  this->groupId = 0;
  this->groupLvl = 0;
  this->groupNumber = 0;
  this->focusedTrentonian = "";
  this->focusedDirection = -1;
  this->isFocused = false;
}

ExternInteractions::~ExternInteractions()
{

}

ExternInteractions		&ExternInteractions::operator=(const ExternInteractions &eaToSet)
{
  this->setNbPlayer(eaToSet.getNbPlayer());
  this->setGroupId(eaToSet.getGroupId());
  this->setGroupLvl(eaToSet.getGroupLvl());
  this->setGroupNumber(eaToSet.getGroupNumber());
  return (*this);
}

void				ExternInteractions::setNbPlayer(unsigned int nbPlayerToSet)
{
  this->nbPlayer = nbPlayerToSet;
}

void				ExternInteractions::setGroupId(unsigned int groupIdToSet)
{
  this->groupId = groupIdToSet;
}

void				ExternInteractions::setGroupLvl(unsigned int groupLvlToSet)
{
  this->groupLvl = groupLvlToSet;
}

void				ExternInteractions::setGroupNumber(unsigned int groupNumberToSet)
{
  this->groupNumber = groupNumberToSet;
}

void				ExternInteractions::setFocusedDirection(int directionToSet)
{
  this->focusedDirection = directionToSet;
}

void				ExternInteractions::setFocusedTrentonian(const std::string
									 &trentonianNameToSet)
{
  this->focusedTrentonian = trentonianNameToSet;
}

void				ExternInteractions::setIsFocused(bool varSet)
{
  this->isFocused = varSet;
}

/*
**				GETTERS
*/

unsigned int                    ExternInteractions::getNbPlayer() const
{
  return (this->nbPlayer);
}

unsigned int                    ExternInteractions::getGroupId() const
{
  return (this->groupId);
}

unsigned int                    ExternInteractions::getGroupLvl() const
{
  return (this->groupLvl);
}

unsigned int                    ExternInteractions::getGroupNumber() const
{
  return (this->groupNumber);
}

int				ExternInteractions::getFocusedDirection() const
{
  return (this->focusedDirection);
}

std::string			ExternInteractions::getFocusedTrentonian() const
{
  return (this->focusedTrentonian);
}

bool				ExternInteractions::getIsFocused() const
{
  return (this->isFocused);
}

/*                                                                                                     
**                      The IA can find ressources                                                     
**                      We put an array of ressources to search                                        
**                      The IA begins to search ressources by priority                                 
**                      More the ressource is in the begin of the array                                
**                      More it's important                                                            
**                      10 % finished : the method must be finished / client part to do                
*/

void                    ExternInteractions::findRessources(int ressourcesToSearch[7])
{
  (void)ressourcesToSearch;
}

/*                                                                                                     
**                      The IA asks how many slots are not used by his team                            
**                      10 % finished : client part to add and linkage with player to do               
*/

unsigned int            ExternInteractions::connectNbr()
{
  return (0);
}

/*                                                                                                     
**                      The IA lays an egg. An egg appears on the ground                               
**                      10 % finished : client part to do and the linkage with trentonian              
*/

void                    ExternInteractions::reproduction()
{

}
