//
// Map.hh for Map in /home/volpe_p/rendu/Zappy/PSU_2013_zappy/graphicClientSources/headers
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Tue Jun 24 11:01:14 2014 volpe
// Last update Sat Jul 19 16:10:59 2014 volpe
//

#ifndef		MAP_HH_
#define		MAP_HH_

#include	<algorithm>
#include	<iostream>
#include	<list>
#include	<SFML/Graphics.hpp>
#include	<map>
#include	"Square.hh"
#include	"Object.hh"
#include	"Trentonian.hh"

class Map
{
private:
  int			_width;
  int			_length;
  std::list<Square *>	_listSquare;
  std::map<objectType, sf::Sprite *> objectSprites;
public:
  Map(int, int);
  ~Map();

  Map			&operator=(Map &);

  // Getters & Setters
  int			getWidth() const;
  int			getLength() const;
  std::list<Square *>	&getListSquare() const;
  Square	        &getSquare(int, int);
  int			getNbCase();
  void			setWidth(int);
  void			setLength(int);
  void			setCaseContent(std::list<int> &listToken);

  //
  void			loadImg(objectType, const char *);
  void			testFunc(Square *);
  void			create();
  void			drawMap(int, int, float, sf::RenderWindow &);
  void			drawPlayer(std::list<Trentonian *> &, int, int, float, sf::RenderWindow &);
  // Mise à jour
  void				addRes(int, int, int);
  void				delRes(int, int, int);
};

#endif
