//
// Trentonian.cpp for Trentonian in /home/volpe_p/rendu/Zappy/PSU_2013_zappy/graphicClientSources
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Sat Jul  5 12:03:08 2014 volpe
// Last update Mon Jul 21 11:47:53 2014 volpe
//

#include	"../headers/Trentonian.hh"

Trentonian::Trentonian()
{
  this->_id = 0;
  this->_x = 0;
  this->_y = 0;
  this->_dir = static_cast<eDir>(1);
  this->_level = 0;
  this->_teamName = "";
  this->setBag(new Inventory(0, 0, 0, 0, 0, 0, 0));
  this->pixelX = 0;
  this->pixelY = 0;
  this->msg = "";
}

Trentonian::Trentonian(int id, int x, int y, int orientation, int level, std::string teamName)
{
  this->_id = id;
  this->_x = x;
  this->_y = y;
  this->_dir = static_cast<eDir>(orientation);
  this->_level = level;
  this->_teamName = teamName;
  this->setBag(new Inventory(0, 0, 0, 0, 0, 0, 0));
  this->msg = "";
}

Trentonian::~Trentonian()
{
}

// Debut -- Getters & Setters

void		Trentonian::setMsg(const std::string &msg)
{
  this->msg = msg;
}

std::string	Trentonian::getMsg() const
{
  return (this->msg);
}

void		Trentonian::setPixelX(int pixelX)
{
  this->pixelX = pixelX;
}

void		Trentonian::setPixelY(int pixelY)
{
  this->pixelY = pixelY;
}

Inventory	*Trentonian::getBag() const
{
  return (this->_bag);
}

void		Trentonian::setBag(Inventory *bag)
{
  this->_bag = bag;
}

int		Trentonian::getId() const
{
  return (this->_id);
}

int		Trentonian::getX() const
{
  return (this->_x);
}

int		Trentonian::getY() const
{
  return (this->_y);
}

eDir		Trentonian::getDir() const
{
  return (this->_dir);
}

int		Trentonian::getLevel() const
{
  return (this->_level);
}

std::string	Trentonian::getTeamName() const
{
  return (this->_teamName);
}

void		Trentonian::setId(int id)
{
  this->_id = id;
}

void		Trentonian::setX(int x)
{
  this->_x = x;
}

void		Trentonian::setY(int y)
{
  this->_y = y;
}

void		Trentonian::setDir(int dir)
{
  this->_dir = static_cast<eDir>(dir);
}

objectType	Trentonian::getObjectType() const
{
  if (this->_dir == N)
    return (PLAYER_N);
  else if (this->_dir == E)
    return (PLAYER_E);
  else if (this->_dir == S)
    return (PLAYER_S);
  else
    return (PLAYER_O);
}
void		Trentonian::setLevel(int level)
{
  this->_level = level;
}

void		Trentonian::setTeamName(std::string teamName)
{
  this->_teamName = teamName;
}


// Fin -- Getters && Setters

void		Trentonian::showInventory()
{
  std::cout << "Nourriture du joueur " << this->_id  << " :" << this->_bag->getFood() << std::endl;
  std::cout << "Linemate du joueur " << this->_id  << " :" << this->_bag->getLinemate() << std::endl;
  std::cout << "Deraumere du joueur " << this->_id  << " :" << this->_bag->getDeraumere() << std::endl;
  std::cout << "Sibur du joueur " << this->_id  << " :" << this->_bag->getSibur() << std::endl;
  std::cout << "Mendiane du joueur " << this->_id  << " :" << this->_bag->getMendiane() << std::endl;
  std::cout << "Phiras du joueur " << this->_id  << " :" << this->_bag->getPhiras() << std::endl;
  std::cout << "Thystame du joueur " << this->_id  << " :" << this->_bag->getThystame() << std::endl;
}

void	        Trentonian::expulse()
{
  std::cout << "Le joueur " << this->_id << " expluse tous les joueurs dans la direction " << this->_dir << " !"  << std::endl;
}

void		Trentonian::startCast()
{
  std::cout << "Le joueur " << this->_id << "lance l'incantation pour tous les joueurs se trouvant en " << this->_x << "/" << this->_y << " !" << std::endl;
}
