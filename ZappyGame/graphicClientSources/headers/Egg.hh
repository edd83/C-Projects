//
// Egg.hh for Egg in /home/volpe_p/rendu/Zappy/PSU_2013_zappy/graphicClientSources
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Sat Jul  5 21:45:41 2014 volpe
// Last update Thu Jul 10 23:23:21 2014 volpe
//

#ifndef		EGG_HH_
# define	EGG_HH_

#include	<iostream>

enum	eState
  {
    CREATED,
    HATCHED,
    DIED,
  };

class Egg
{
private:
  int		id;
  int		id_player;
  int		x;
  int		y;
  eState	state;
public:
  Egg(int, int, int, int);
  ~Egg();

  // Getters && Setters

  int		getId() const;
  int		getIdPlayer() const;
  int		getX() const;
  int		getY() const;
  void		setId(int);
  void		setIdPlayer(int);
  void		setX(int);
  void		setY(int);

  void		hatch();
  void		die();
};
#endif
