//
// Team.cpp for Team in /home/volpe_p/rendu/Zappy/PSU_2013_zappy/graphicClientSources
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Sat Jul  5 16:34:13 2014 volpe
// Last update Mon Jul  7 10:42:50 2014 volpe
//

#include	"../headers/Team.hh"

Team::Team(std::string name)
{
  this->_name = name;
}

Team::~Team()
{
}

// Debut -- Getters && setters

void				Team::setName(std::string name)
{
  this->_name = name;
}

std::string			Team::getName() const
{
  return (this->_name);
}

std::list<Trentonian *>		&Team::getListPlayer() const
{
  return (const_cast<std::list<Trentonian *> & >(this->_listPlayer));
}

// Fin -- Getters && Setters

void				Team::addPlayer(Trentonian &player)
{
  this->_listPlayer.push_back(&player);
}

void				Team::delPlayer(int id)
{
  std::list<Trentonian *>::iterator	itPlayer = this->getListPlayer().begin(); 
  std::list<Trentonian *>::iterator     playerSave;
  bool					erase = false;
  
  while (itPlayer != this->getListPlayer().end())
    {
      if ((*itPlayer)->getId() == id)
	{
	  playerSave = itPlayer;
	  erase = true;
	}
      itPlayer++;
    }
  if (erase == true)
    this->getListPlayer().erase(playerSave);
}

void				Team::showPlayer()
{
  for (std::list<Trentonian *>::iterator it = this->getListPlayer().begin(); it != this->getListPlayer().end(); it++)
    {
      std::cout << "Id du Trentonian :" << (*it)->getId() << std::endl;
      std::cout << "Coord X/Y du Trentonian :" << (*it)->getX() << "/" << (*it)->getY() << std::endl;
      std::cout << "Dir du Trentonian :" << (*it)->getDir() << std::endl;
      std::cout << "Level du Trentonian :" << (*it)->getLevel() << std::endl;
    }

}
