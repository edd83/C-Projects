//
// Square.hh for Square in /home/volpe_p/rendu/Zappy/PSU_2013_zappy/graphicClientSources/headers
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Tue Jun 24 11:07:12 2014 volpe
// Last update Sat Jul 19 16:16:59 2014 volpe
//

#ifndef		SQUARE_HH_
#define		SQUARE_HH_

#include	<list>
#include	<iostream>

class Square
{
private:
  int		_x;
  int		_y;
  int		_food;
  int		_linemate;
  int		_deraumere;
  int		_sibur;
  int		_mendiane;
  int		_phiras;
  int		_thystame;
public:
  Square(int, int);
  ~Square();

  // Getters && setters
  int		getX() const;
  int		getY() const;

  int   	getFood() const;
  int		getLinemate() const;
  int		getDeraumere() const;
  int		getSibur() const;
  int		getMendiane() const;
  int		getPhiras() const;
  int		getThystame() const;
  int		getNbItemsOnSquare();

  void		setFood(int);
  void		setLinemate(int);
  void		setDeraumere(int);
  void		setSibur(int);
  void		setMendiane(int);
  void		setPhiras(int);
  void		setThystame(int);

  // Modifications des ressources
  void		addRes(int);
  void		delRes(int);
  void		setContentCase(int, int, int, int, int, int, int);
};
#endif
