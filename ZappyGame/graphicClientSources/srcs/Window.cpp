//
// Window.cpp for Window in /home/volpe_p/rendu/Zappy/PSU_2013_zappy/graphicClientSources/SFML
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Mon Jun 23 17:43:06 2014 volpe
// Last update Mon Jul 21 11:51:04 2014 volpe
//

#include	"../headers/Window.hh"
#include	<unistd.h>

Window::Window(GraphClient &game) : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_LENGTH), "Zappy"), posCamX(0), posCamY(0), zoomLevel(1),game(game), thread(&Window::madeRequest, this), playerNext(0)
{
  this->timeUnit = this->game.getTimeUnit();
  this->timeChanged = false;
  this->hud = new Hud();
}

Window::~Window()
{
}

// Debut - Getters & Setters

void			Window::setCenter(sf::Vector2f center)
{
  this->_center = center;
}

sf::RenderWindow	&Window::getWindow()
{
  return (const_cast<sf::RenderWindow &>(this->window));
}

int			Window::getPosCamX() const
{
  return (this->posCamX);
}

int			Window::getPosCamY() const
{
  return (this->posCamY);
}

void			Window::setPosCamX(int x)
{
  this->posCamX = x;
}

void			Window::setPosCamY(int y)
{
  this->posCamY = y;
}
// Fin -- Getters & Setters

// Debut -- Helpers
std::string	Window::intToString(int i)
{
  std::ostringstream oss;

  oss << i;
  return (oss.str());
}
// Fin -- Helpers

void	Window::create(Client &network)
{
  sf::Event event;

  this->network = &network;  
  this->thread.launch();
  this->refreshDisplay();
  while (this->window.isOpen())
    {
      while (this->window.pollEvent(event))
	{
	  this->timeChanged = false;   
	  switch (event.type)
	    {
	    case sf::Event::Closed:
	      window.close();
	      exit(0);
	      break;
	    case sf::Event::KeyPressed:
	      switch (event.key.code)
		{
		case sf::Keyboard::Left:
		  this->posCamX += MOVE_BY;
		  this->refreshDisplay();
		  break;
		case sf::Keyboard::Right:
		  this->posCamX -= MOVE_BY;
		  this->refreshDisplay();
		  break;
		case sf::Keyboard::Up:
		  this->posCamY += MOVE_BY;;
		  this->refreshDisplay();
		  break;
		case sf::Keyboard::Down:
		  this->posCamY -= MOVE_BY;
		  this->refreshDisplay();
		  break;
		case sf::Keyboard::Add:
		  this->increaseTimeUnit();
		  this->refreshDisplay();
		  break;
		case sf::Keyboard::Subtract:
		  this->decreaseTimeUnit();
		  this->refreshDisplay();
		  break;
		case sf::Keyboard::Space:
		  this->selectPlayer();
		  this->refreshDisplay();
		  break;
		}
	      break;
	    }
	  this->refreshDisplay();
	  window.display();
	}
    }
}

void			Window::selectPlayer()
{
  int	listSize = this->game.getListPlayer().size();

  if (listSize == 0)
    {
      this->hud->setLevel("");
      this->hud->setTeam("");
      this->hud->setName("");
      this->hud->setRes("", "", "", "", "", "", "");
      this->hud->setMsg("");
      return ;
    }
  else
    {
      std::list<Trentonian *>::iterator	it = this->game.getListPlayer().begin();
      if (listSize > 1)
 	{
	  if (listSize <= this->playerNext)
	    this->playerNext = 0;
	  else
	    {
	      int	cpt = this->playerNext;
	      if (cpt == 0)
		cpt++;
	      while (cpt > 0)
		{
		  it++;
		  cpt--;
		}
	      this->playerNext++;
	    }
	}
      this->hud->setMsg((*it)->getMsg());
      this->hud->setLevel(intToString((*it)->getLevel()));
      this->hud->setTeam((*it)->getTeamName());
      this->hud->setName(intToString((*it)->getId()));
      this->hud->setRes(intToString((*it)->getBag()->getFood()), intToString((*it)->getBag()->getLinemate()), intToString((*it)->getBag()->getDeraumere()), intToString((*it)->getBag()->getSibur()), intToString((*it)->getBag()->getMendiane()), intToString((*it)->getBag()->getPhiras()), intToString((*it)->getBag()->getThystame()));
    }
}

void			Window::refreshDisplay()
{
  window.clear();
  this->draw();
}

void			Window::draw()
{
  this->mapMutex.lock();
  this->game.getMap().drawMap(this->posCamX, this->posCamY, this->zoomLevel, this->window);
  this->hud->setUnity(intToString(this->game.getTimeUnit()));
  this->game.getMap().drawPlayer(game.getListPlayer(), this->posCamX, this->posCamY, this->zoomLevel, this->window);
  this->hud->draw(window);
  this->mapMutex.unlock();
}

void			Window::increaseTimeUnit()
{
  this->timeChanged = true;
  if (this->game.getTimeUnit() >= 5)
    {
      if (this->game.getTimeUnit() < 1000)
        this->game.setTimeUnit(this->game.getTimeUnit() + ((this->game.getTimeUnit() * 20) / 100));
    }
  else
    this->game.setTimeUnit(this->game.getTimeUnit() + 1);
  if (this->game.getTimeUnit() > 1000)
    this->game.setTimeUnit(1000);
  this->network->sendTimeUnit(this->game.getTimeUnit());	
}

void			Window::decreaseTimeUnit()
{
  this->timeChanged = true;
  if (this->game.getTimeUnit() >= 5)
    {
      this->game.setTimeUnit(this->game.getTimeUnit() - ((this->game.getTimeUnit() * 20) / 100));
      if (this->game.getTimeUnit() < 1)
	this->game.setTimeUnit(1);
    }
  else if (this->game.getTimeUnit() > 1)
    this->game.setTimeUnit(this->game.getTimeUnit() - 1);
  if (this->game.getTimeUnit() < 1)
    this->game.setTimeUnit(1);
  this->network->sendTimeUnit(this->game.getTimeUnit());	
}

void		Window::madeRequest()
{
  while (1)
    this->network->update();
}
