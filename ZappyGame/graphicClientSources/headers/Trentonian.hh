//
// Trentonian.hh for Trentonian in /home/volpe_p/rendu/Zappy/PSU_2013_zappy/graphicClientSources
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Sat Jul  5 12:03:28 2014 volpe
// Last update Mon Jul 21 11:49:17 2014 volpe
//

#ifndef		TRENTONIAN_HH_
# define	TRENTONIAN_HH_

#include	<string>
#include	<iostream>
#include	"Inventory.hh"
#include	"Object.hh"

enum	eDir
  {
    N = 1,
    E,
    S,
    O
  };

class Trentonian
{
private:
  int		_id;
  int		_x;
  int		_y;
  int		pixelX;
  int		pixelY;
  eDir		_dir;
  int		_level;
  std::string	_teamName;
  std::string	msg;
  Inventory	*_bag;

public:
  Trentonian();
  Trentonian(int, int, int, int, int, std::string);
  ~Trentonian();

  // Getters & Setters

  int		getId() const;
  int		getX() const;
  int		getY() const;
  eDir		getDir() const;
  int		getLevel() const;
  std::string	getTeamName() const;
  Inventory	*getBag() const;
  objectType	getObjectType() const;
  std::string	getMsg() const;

  void		setMsg(const std::string &);
  void		setId(int);
  void		setX(int);
  void		setY(int);
  void		setDir(int);
  void		setLevel(int);
  void		setTeamName(std::string);
  void		setBag(Inventory *);
  void		setPixelX(int);
  void		setPixelY(int);

  void		showInventory();
  void		expulse();
  void		startCast();
};
#endif
