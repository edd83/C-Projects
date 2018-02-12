//
// GraphClient.hh for GraphClient in /home/volpe_p/rendu/Zappy/PSU_2013_zappy/graphicClientSources
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Wed Jun 25 12:54:54 2014 volpe
// Last update Mon Jul 21 11:48:41 2014 volpe
//

#ifndef		GRAPHCLIENT_HH_
# define	GRAPHCLIENT_HH_

#include	<string>
#include	"Window.hh"
#include	"Map.hh"
#include	"Team.hh"
#include	"Square.hh"
#include	"Egg.hh"
#include	"Client.hh"

#define		MOVE_BY 50

class Client;

class GraphClient
{
private:
  int				_width;
  int				_length;
  int				_timeUnit;
  std::list<Team *>		*_listTeam;
  std::list<Square *>		_listSquare;
  std::list<Egg *>		_listEgg;
  std::list<Trentonian *>	_listPlayer;
  Map				*map;

public:
  GraphClient();
  ~GraphClient();

  // Getters & Setters
  void				setMapWidth(int);
  void				setMapLength(int);
  void				setTimeUnit(int);
  int				getMapWidth() const;
  int				getMapLength() const;
  int				getTimeUnit() const;
  std::list<Team *>		&getListTeam();
  std::list<Egg *>		&getListEgg() const;
  std::list<Trentonian *>	&getListPlayer() const;
  Trentonian			*getPlayerById(int);
  Egg				*getEggById(int) const;
  int				getNbEgg() const;
  Map				&getMap() const;

  // Show
  void				showSquare();
  void				showEgg();
  void				showTeam();
  void				showPlayer();
  void				showPlayerInventory();

  // Updates

  void				updatePlayer(std::list<int> &listToken);
  void				updateSquare(std::list<int> &listToken);
  void				updateLevelPlayer(std::list<int> &listToken);
  void				updateInventoryPlayer(std::list<int> &listToken);
  void				updateMsgPlayer(std::list<int> &listToken, const std::string &);
  void		                playerDie(std::list<int> &id);
  void				playerPickupRessource(std::list<int> &listToken);
  void				hatchingEgg(std::list<int> &listToken);
  void				playerConnect(std::list<int> &listToken);
  void				eggDie(std::list<int> &listToken);
  void				playerExpulse(std::list<int> &listToken);
  void				startCast(std::list<int> &listToken);
  void				endCast(std::list<int> &listToken);

  // Fonctions ajouts liste
  void				addTeam(const std::string &);
  bool				addPlayerToTeam(Trentonian &player, std::string teamName);
  void				addSquare(std::list<int> &listToken);
  void				addEgg(std::list<int> &listToken);
  void				createEgg(std::list<int> &listToken);

  // Annonces
  void				putSrvMsg(std::string msg);
  void				putWinner(std::string winner);

  void				start(Client &);

};
#endif
