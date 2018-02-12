//
// GraphClient.cpp for GraphClient in /home/volpe_p/rendu/Zappy/PSU_2013_zappy/graphicClientSources
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Wed Jun 25 12:54:25 2014 volpe
// Last update Mon Jul 21 11:58:36 2014 volpe
//

#include	"../headers/GraphClient.hh"

GraphClient::GraphClient()
{
  this->_width = 0;
  this->_length = 0;
  this->map = new Map (10, 10);
  this->_listTeam = new std::list<Team *>;
}

GraphClient::~GraphClient()
{
}

// Debut -- Getters && Setters

int			GraphClient::getNbEgg() const
{
  return (this->getListEgg().size());
}

void			GraphClient::setMapWidth(int width)
{
  this->_width = width;
}

void			GraphClient::setMapLength(int length)
{
  this->_length = length;
}

int			GraphClient::getMapWidth() const
{
  return (this->_width);
}

int			GraphClient::getMapLength() const
{
  return (this->_length);
}

void			GraphClient::setTimeUnit(int timeUnit)
{
  this->_timeUnit = timeUnit;
}

int			GraphClient::getTimeUnit() const
{
  return (this->_timeUnit);
}

Egg			*GraphClient::getEggById(int idEgg) const
{
  for (std::list<Egg *>::iterator it = this->getListEgg().begin(); it != this->getListEgg().end(); it++)
    {
      if ((*it)->getId() == idEgg)
	return ((*it));
    }
  return (NULL);
}

Map			&GraphClient::getMap() const
{
  return (*(this->map));
}

Trentonian		*GraphClient::getPlayerById(int idPlayer)
{
  if (this->getListPlayer().size() == 1)
      return (*(this->getListPlayer().begin()));
  for (std::list<Trentonian *>::iterator it = this->getListPlayer().begin(); it != this->getListPlayer().end(); it++)
    {
      if ((*it)->getId() == idPlayer)
	return (*it);
    }
  return (NULL);
}

std::list<Team *>	&GraphClient::getListTeam()
{
  return (*(this->_listTeam));
}

std::list<Egg *>	&GraphClient::getListEgg() const
{
  return (const_cast<std::list<Egg *> & >(this->_listEgg));
}

std::list<Trentonian *>	&GraphClient::getListPlayer() const
{
  return (const_cast<std::list<Trentonian *> & >(this->_listPlayer));
}

// Fin -- Getters && Setters

// Debut -- Fonctions ajouts

void			GraphClient::addTeam(const std::string &teamName)
{
  Team			*newTeam = new Team(teamName);

  this->_listTeam->push_back(newTeam);
}

bool				GraphClient::addPlayerToTeam(Trentonian &player, std::string teamName)
{
  for (std::list<Team *>::iterator it = this->getListTeam().begin(); it != this->getListTeam().end(); it++)
    {
      if ((*it)->getName() == teamName)
	{
	  (*it)->addPlayer(player);
	  return (true);
	}
    }
  return (false);
}

// Fin -- Fonctions ajouts

// Debut -- Fonctions Show

void				GraphClient::showEgg()
{
  // for (std::list<Egg *>::iterator it = this->getListEgg().begin(); it != this->getListEgg().end(); it++)
  //   {
  //     std::cout << "Id de l'oeuf :" << (*it)->getId() << std::endl;
  //     std::cout << "Coord X/Y :" << (*it)->getX() << "/" << (*it)->getY() << std::endl;
  //     std::cout << "id du joueur :" << (*it)->getIdPlayer() << std::endl;
  //   }
}

void				GraphClient::showTeam()
{
  for (std::list<Team *>::iterator it = this->getListTeam().begin(); it != this->getListTeam().end(); it++)
    {
      std::cout << (*it)->getName() << std::endl;
    }
}

void				GraphClient::showPlayer()
{
  for (std::list<Team *>::iterator it = this->getListTeam().begin(); it != this->getListTeam().end(); it++)
    {
      std::cout << "Equipe :" << (*it)->getName() << std::endl;
      (*it)->showPlayer();
    }
}

void					GraphClient::showSquare()
{
  for (std::list<Square *>::iterator it = this->getMap().getListSquare().begin(); it != this->getMap().getListSquare().end(); it++)
    {
      std::cout << "Case X/Y :" << (*it)->getX() << "/" << (*it)->getY() << std::endl;
      std::cout << "  FOOD =" << (*it)->getFood() << std::endl;
      std::cout << "  LINEMATE =" << (*it)->getLinemate() << std::endl;
      std::cout << "  DERAUMERE =" << (*it)->getDeraumere() << std::endl;
      std::cout << "  SIBUR =" << (*it)->getSibur() << std::endl;
      std::cout << "  MENDIANE =" << (*it)->getMendiane() << std::endl;
      std::cout << "  PHIRAS =" << (*it)->getPhiras() << std::endl;
      std::cout << "  THYSTAME =" << (*it)->getThystame() << std::endl;
    }
}

void					GraphClient::showPlayerInventory()
{
  for (std::list<Trentonian *>::iterator it = this->getListPlayer().begin(); it != this->getListPlayer().end(); it++)
    (*it)->showInventory();
}

// Fin -- Fonctions show

// Debut -- Fonctios ajouts

void				GraphClient::addEgg(std::list<int> &listToken)
{
  // int				t[4];
  // std::list<int>::iterator	it = listToken.begin();

  // for (int i = 0; i < 4; i++)
  //   {
  //     t[i] = (*it);
  //     it++;
  //   }
  // this->_listEgg.push_back(new Egg(t[0], t[1], t[2], t[3]));
}

void				GraphClient::createEgg(std::list<int> &listToken)
{
  // std::list<int>::iterator	it = listToken.begin();
  // int				idPlayer = (*it);
  // int				x = this->getPlayerById(idPlayer)->getX();
  // int				y = this->getPlayerById(idPlayer)->getY();

  // this->getListEgg().push_back(new Egg(this->getNbEgg() + 1, idPlayer, x, y));
}

// Fin -- Fonctions ajouts

// Debut -- Fonctions de mise à jour

void					GraphClient::updateSquare(std::list<int> &listToken)
{
  std::list<int>::iterator		it = listToken.begin();
  Trentonian				*player = this->getPlayerById((*it));

  player->getBag()->delRes(++(*it));
  this->getMap().addRes((*it), player->getX(), player->getY());
}

void					GraphClient::updateInventoryPlayer(std::list<int> &listToken)
{
  int					t[10];
  std::list<Trentonian *>::iterator	itPlayer;
  std::list<int>::iterator		it = listToken.begin();

  for (int i = 0; i < 10; i++)
    {
      t[i] = (*it);
      it++;
    }
  for (itPlayer = this->getListPlayer().begin(); itPlayer != this->getListPlayer().end(); itPlayer++)
    {
      if ((*itPlayer)->getId() == t[0])
	{
	  (*itPlayer)->setX(t[1]);
	  (*itPlayer)->setY(t[2]);
	  (*itPlayer)->setBag(new Inventory(t[3], t[4], t[5], t[6], t[7], t[8], t[9]));
	}
    }
}

void				GraphClient::updatePlayer(std::list<int> &listToken)
{
  int				tab[4];
  std::list<int>::iterator	it = listToken.begin();

  for (int i = 0; i < 4; i++)
    {
      tab[i] = (*it);
      it++;
    }
  for (std::list<Trentonian *>::iterator it = this->getListPlayer().begin(); it != this->getListPlayer().end(); it++)
    {
      if ((*it)->getId() == tab[0])
	{
	  (*it)->setX(tab[1]);
	  (*it)->setY(tab[2]);
	  (*it)->setDir(tab[3]);
	  (*it)->setMsg("");
	}
    }
}

void				GraphClient::updateMsgPlayer(std::list<int> &listToken, const std::string &msg)
{
  std::list<int>::iterator	it = listToken.begin();
  Trentonian			*player = this->getPlayerById((*it));

  player->setMsg(msg);
}


void				GraphClient::updateLevelPlayer(std::list<int> &listToken)
{
  int				tab[2];
  std::list<int>::iterator	it = listToken.begin();

  for (int i = 0; i < 4; i++)
    {
      tab[i] = (*it);
      it++;
    }
  for (std::list<Trentonian *>::iterator it = this->getListPlayer().begin(); it != this->getListPlayer().end(); it++)
    {
      if ((*it)->getId() == tab[0])
	(*it)->setLevel(tab[1]);
    }
}

void                    GraphClient::playerDie(std::list<int> &id)
{
  std::list<int>::iterator              it = id.begin();
  int                                   idPlayer = (*it);
  std::list<Trentonian *>::iterator     player = this->getListPlayer().begin();
  std::list<Trentonian *>::iterator     playerSave;
  std::string				teamName;
  std::list<Team *>::iterator           itTeam = this->getListTeam().begin();
  bool					erase = false;
  
  while (player != this->getListPlayer().end())
    {
      if ((*player)->getId() == idPlayer)
	{
	  teamName = (*player)->getTeamName();
	  playerSave = player;
	  erase = true;
	}
      player++;
    }
  if (erase == true)
    this->getListPlayer().erase(playerSave);
  while (itTeam != this->getListTeam().end())
    {
      if ((*itTeam)->getName() == teamName)
	(*itTeam)->delPlayer(idPlayer);
      itTeam++;
    }
}

void				GraphClient::playerPickupRessource(std::list<int> &listToken)
{
  int				t[2];
  std::list<int>::iterator	it = listToken.begin();
  int				idPlayer;

  for (int i = 0; i < 2; i++)
    {
      t[i] = (*it);
      it++;
    }
  idPlayer = t[0];
  Trentonian *player = this->getPlayerById(idPlayer);
  player->getBag()->addRes(t[1]);
  this->getMap().delRes(t[1], player->getX(), player->getY());
}

void				GraphClient::hatchingEgg(std::list<int> &listToken)
{
  int				idEgg = (*listToken.begin());

   // this->getEggById(idEgg)->hatch();
}

void				GraphClient::playerConnect(std::list<int> &listToken)
{
  // int				id_player = (*listToken.begin());
  // int				x = this->getEggById(id_player)->getX();
  // int				y = this ->getEggById(id_player)->getY();
  // std::string			teamName = this->getPlayerById(this->getEggById(id_player)->getIdPlayer())->getTeamName();
  // Trentonian			*new_player = new Trentonian(id_player, x, y, 0, 0, teamName);

  // this->getListPlayer().push_back(new_player);
  // this->addPlayerToTeam(*new_player, teamName); 
}

void				GraphClient::eggDie(std::list<int> &listToken)
{
  // int				id_egg = (*listToken.begin());
  // std::list<Egg *>::iterator	itEgg;
  // std::list<Egg *>::iterator	save_egg;
  // bool				erase = false;

  // this->getEggById(id_egg)->die();
  // for (itEgg = this->getListEgg().begin(); itEgg != this->getListEgg().end(); itEgg ++)
  //   {
  //     if ((*itEgg)->getId() == id_egg)
  // 	{
  // 	  save_egg = itEgg;
  // 	  erase = true;
  // 	}
  //   }
  // if (erase == true)
  //   this->getListEgg().erase(save_egg);
}

void				GraphClient::playerExpulse(std::list<int> &listToken)
{
  // int				idPlayer = (*listToken.begin());

  // this->getPlayerById(idPlayer)->expulse();
}

void				GraphClient::startCast(std::list<int> &listToken)
{
  std::list<int>::iterator	it = listToken.begin();
  // int				x = (*it);
  it++;
  // int				y = (*it);
  it++;
  // int				level = (*it);
  it++;
  int				idPlayer = (*it);

  this->getPlayerById(idPlayer)->startCast();
}

void				GraphClient::endCast(std::list<int> &listToken)
{
  std::list<int>::iterator	it = listToken.begin();
  int				x = (*it);
  it++;
  int				y = (*it);
  it++;
  int				res = (*it);
  std::list<Trentonian *>::iterator	itPlayer = this->getListPlayer().begin();

  if (res == 1)
    {
      if (this->getListPlayer().size() > 1)
	{
	  for (itPlayer; itPlayer != this->getListPlayer().end(); it++)
	    {
	      if ((*itPlayer)->getX() == x && (*itPlayer)->getY() == y)
		{
		  std::cout << "Level Up !!!" << std::endl; 
		  (*itPlayer)->setLevel((*itPlayer)->getLevel() + 1);
		}
	    }
	}
      else
	{
	  if ((*itPlayer)->getX() == x && (*itPlayer)->getY() == y)
	    {
	      std::cout << "Level Up !!!" << std::endl; 
	      (*itPlayer)->setLevel((*itPlayer)->getLevel() + 1);
	    }
	}
      this->getMap().getSquare(x, y).setContentCase(0, 0, 0, 0, 0, 0, 0);
    }
}

// Fin -- Fonctions de mises à jour


// Debut -- Annonces

void                    GraphClient::putSrvMsg(std::string msg)
{
  std::cout << "incoming message from the server: " << msg << std::endl;
}

void                    GraphClient::putWinner(std::string winner)
{
  std::cout << "The winner is: " << winner << std::endl;
}

// Fin -- Annonces
void			GraphClient::start(Client &network)
{
  Window	*window = new Window(*this);

  window->create(network);
}
