//
// View.hh for View in /home/volpe_p/rendu/Zappy/PSU_2013_zappy/graphicClientSources
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Fri Jun 27 14:38:33 2014 volpe
// Last update Fri Jun 27 15:02:46 2014 volpe
//

#ifndef		MYVIEW_HH_
# define	MYVIEW_HH_

#include	"Map.hh"

class	View
{
private:
  sf::View	_mainView;
  sf::View	_minimapView;

public:
  MyView();
  ~MyView();

  // Getters
  sf::View	getMinimapView() const;
  sf::View	getMainView()	const;

  // Initialisation
  void		initialize(const Map &map);
};
#endif
