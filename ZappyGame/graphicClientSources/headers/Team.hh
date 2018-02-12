//
// Team.hh for Team in /home/volpe_p/rendu/Zappy/PSU_2013_zappy/graphicClientSources
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Sat Jul  5 16:30:51 2014 volpe
// Last update Sat Jul  5 17:20:40 2014 volpe
//

#ifndef		TEAM_HH_
# define	TEAM_HH_

#include	<string>
#include	<iostream>
#include	<list>
#include	"Trentonian.hh"

class Team
{
private:
  std::string			_name;
  std::list<Trentonian *>	_listPlayer;
public:
  Team(std::string name);
  ~Team();

  std::string			getName() const;
  std::list<Trentonian *>	&getListPlayer() const;

  void				setName(std::string name);
  void				addPlayer(Trentonian &player);
  void				delPlayer(int id);
  void				showPlayer();
};
#endif
