
//
// Map.cpp for Map in /home/volpe_p/rendu/Zappy/PSU_2013_zappy/graphicClientSources/headers
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Tue Jun 24 11:03:19 2014 volpe
// Last update Sat Jul 19 16:10:23 2014 volpe
//

#include	"../headers/Map.hh"

Map::Map(int width, int length)
{
  this->_width = width;
  this->_length = length;

  loadImg(GROUND, "images/grass-low.png");
  loadImg(FOOD, "images/food.png");
  loadImg(LINEMATE, "images/linemate.png");
  loadImg(DERAUMERE, "images/deraumere.png");
  loadImg(SIBUR, "images/sibur.png");
  loadImg(MENDIANE, "images/mendiane.png");
  loadImg(PHIRAS, "images/phiras.png");
  loadImg(THYSTAME, "images/thystame.png");
  loadImg(PLAYER_N, "images/perso_top.png");
  loadImg(PLAYER_E, "images/perso_right.png");
  loadImg(PLAYER_S, "images/perso_bottom.png");
  loadImg(PLAYER_O, "images/perso_left.png");
  loadImg(EGG, "images/egg.png");
}

Map::~Map()
{
}

Map	&Map::operator=(Map &other)
{
  if (this != &other)
    {
      this->_width = other._width;
      this->_length = other._length;
    }
}

std::list<Square *>	&Map::getListSquare() const
{
  return (const_cast<std::list<Square *> & >(this->_listSquare));
}

void	Map::setCaseContent(std::list<int> &listToken)
{
  int				t[9];
  std::list<int>::iterator	it = listToken.begin();

  for (int i = 0; i < 9; i++)
    {
      t[i] = (*it);
      it++;
    }
  this->getSquare(t[0], t[1]).setContentCase(t[2], t[3], t[4], t[5], t[6], t[7], t[8]);
}

void	Map::create()
{
  for (int j = 0; j < this->_length; j++)
    {
      for (int i = 0; i < this->_width; i++)
	this->getListSquare().push_back(new Square(i, j));
    }
}

void	Map::loadImg(objectType type, const char *file)
{
  sf::Texture	*texture = new sf::Texture();
  sf::Sprite	*sprite;

  if (texture->loadFromFile(file))
    {
      texture->setSmooth(true);
      sprite = new sf::Sprite();
      sprite->setTexture(*texture);
      objectSprites[type] = sprite;
    }
  else
    {
      std::cerr << "Error : bitmap loading failed." << std::endl;
      exit(0);
    }
}

Square	&Map::getSquare(int x, int y)
{
  for (std::list<Square *>::iterator it = this->getListSquare().begin(); it != this->getListSquare().end(); it++)
    {
      if ((*it)->getX() == x && (*it)->getY() == y)
	{
	  return (*(*it));
	}
    }
}

void	Map::addRes(int idRes, int x, int y)
{
  this->getSquare(x, y).addRes(idRes);
}

void	Map::delRes(int idRes, int x, int y)
{
  this->getSquare(x, y).delRes(idRes);
}
void	Map::testFunc(Square *aSquare)
{
  std::cout << "Ma case X/Y:";
  std::cout << aSquare->getX() << "/" << aSquare->getY() << std::endl;
}

void			Map::drawPlayer(std::list<Trentonian *> &listPlayer, int camPosX, int camPosY, float zoomLevel, sf::RenderWindow &window)
{
  int	posX;
  int	posY;
  int	playerX;
  int	playerY;
  int	diffX = 101 * zoomLevel;
  int	diffY = 48 * zoomLevel;

  for (std::list<Trentonian *>::iterator it = listPlayer.begin(); it != listPlayer.end(); it++)
    {
      playerX = (*it)->getX();
      playerY = (*it)->getY();
      posX = camPosX - (playerY * (diffX / 2)) + (playerX * (diffX / 2)) - (diffX / 2);
      posY = camPosY + (playerY * (diffY / 2)) + (playerX * (diffY / 2));
      this->objectSprites[(*it)->getObjectType()]->setPosition(sf::Vector2f(posX + ((diffX / 3)), posY - (diffY / 2)));
      (*it)->setPixelX(posX);
      (*it)->setPixelY(posY - (diffY / 2));
      window.draw(*(this->objectSprites[(*it)->getObjectType()]));
    }
}

void	Map::drawMap(int camPosX, int camPosY, float zoom, sf::RenderWindow &window)
{
  int	i;
  int	nbItems;
  int	posX;
  int	posY;
  int	diffX = 101 * zoom;
  int	diffY = 48 * zoom;

  for (std::list<Square *>::iterator it = this->_listSquare.begin(); it != this->_listSquare.end(); it++)
    {
      posX = camPosX - ((*it)->getY() * (diffX / 2)) + ((*it)->getX() * (diffX / 2)) - (diffX / 2);
      posY = camPosY + ((*it)->getY() * (diffY / 2)) + ((*it)->getX() * (diffY / 2));
      // if ((*it)->getX() == 0 && (*it)->getY() == 0)
      // 	std::cout << "Case " << (*it)->getX() << "/" << (*it)->getY() << " :" << posX << "/" << posY << std::endl;
      this->objectSprites[GROUND]->setPosition(sf::Vector2f(posX, posY));
      this->objectSprites[GROUND]->setScale(zoom, zoom);
      window.draw(*(objectSprites[GROUND]));
      nbItems = (*it)->getNbItemsOnSquare();
      i = 0;
      if ((*it)->getFood() > 0)
	{
	  this->objectSprites[FOOD]->setPosition(sf::Vector2f(posX + ((i + 1) * (diffX / (nbItems) / 2)) - (((nbItems) / 2 )* (diffX / (nbItems) / 2)), posY));
	  this->objectSprites[FOOD]->setScale(zoom, zoom);
	  window.draw(*(this->objectSprites[FOOD]));
	  i++;
	}
      if ((*it)->getLinemate() > 0)
	{
	  this->objectSprites[LINEMATE]->setPosition(sf::Vector2f(posX + ((i + 1) * (diffX / (nbItems) / 2)) - (((nbItems) / 2 )* (diffX / (nbItems) / 2)), posY));
	  this->objectSprites[LINEMATE]->setScale(zoom, zoom);
	  window.draw(*(this->objectSprites[LINEMATE]));
	  i++;
	}
      if ((*it)->getDeraumere() > 0)
	{
	  this->objectSprites[DERAUMERE]->setPosition(sf::Vector2f(posX + ((i + 1) * (diffX / (nbItems) / 2)) - (((nbItems) / 2 )* (diffX / (nbItems) / 2)), posY));
	  this->objectSprites[DERAUMERE]->setScale(zoom, zoom);
	  window.draw(*(this->objectSprites[DERAUMERE]));
	  i++;
	}
      if ((*it)->getSibur() > 0)
	{
	  this->objectSprites[SIBUR]->setPosition(sf::Vector2f(posX + ((i + 1) * (diffX / (nbItems) / 2)) - (((nbItems) / 2 )* (diffX / (nbItems) / 2)), posY));
	  this->objectSprites[SIBUR]->setScale(zoom, zoom);
	  window.draw(*(this->objectSprites[SIBUR]));
	  i++;
	}
      if ((*it)->getMendiane() > 0)
	{
	  this->objectSprites[MENDIANE]->setPosition(sf::Vector2f(posX + ((i + 1) * (diffX / (nbItems) / 2)) - (((nbItems) / 2 )* (diffX / (nbItems) / 2)), posY));
	  this->objectSprites[MENDIANE]->setScale(zoom, zoom);
	  window.draw(*(this->objectSprites[MENDIANE]));
	  i++;
	}
      if ((*it)->getPhiras() > 0)
	{
	  this->objectSprites[PHIRAS]->setPosition(sf::Vector2f(posX + ((i + 1) * (diffX / (nbItems) / 2)) - (((nbItems) / 2 )* (diffX / (nbItems) / 2)), posY));
	  this->objectSprites[PHIRAS]->setScale(zoom, zoom);
	  window.draw(*(this->objectSprites[PHIRAS]));
	  i++;
	}
      if ((*it)->getThystame() > 0)
	{
	  this->objectSprites[THYSTAME]->setPosition(sf::Vector2f(posX + ((i + 1) * (diffX / (nbItems) / 2)) - (((nbItems) / 2 )* (diffX / (nbItems) / 2)), posY));
	  this->objectSprites[THYSTAME]->setScale(zoom, zoom);
	  window.draw(*(this->objectSprites[THYSTAME]));
	  i++;
	}
    }
}

int	Map::getWidth() const
{
  return (this->_width);
}

void	Map::setWidth(int width)
{
  this->_width = width;
}

void	Map::setLength(int length)
{
  this->_length = length;
}
int	Map::getLength() const
{
  return (this->_length);
}

int	Map::getNbCase()
{
  return (this->_width * this->_length);
}
