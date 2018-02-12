#ifndef __HUD_HH__
#define __HUD_HH__

#include	<iostream>
#include	<SFML/Graphics.hpp>
#include	<SFML/Window.hpp>
#include	<SFML/System.hpp>
#include	"Object.hh"
#include	"GraphClient.hh"

class Hud
{
private:
  int						_width;
  int						_height;
  std::string					_level;
  std::string					_unity;
  std::string					_team;
  std::string					_name;
  std::string					_msg;
  std::string					_food;
  std::string					_deraumere;
  std::string					_linemate;
  std::string					_sibur;
  std::string					_phiras;
  std::string					_thystame;
  std::string					_mendiane;
  bool						_drawInventory;
  std::map<objectType, sf::Sprite*>		objectSprites;
  std::vector<std::string>			_inventaires;
public:
  Hud();
  ~Hud();

  void draw(sf::RenderWindow &window);
  void loadOneBitmap(objectType type, const char *file);
  void setPositionSprite();
  void drawText(const sf::Font &font, sf::RenderWindow &window) const;
  void fillInventory(const std::vector<std::string> & arg);
  void drawInventory(const sf::Font &font, sf::RenderWindow &window) const;	
  void setLevel(const std::string &);
  void setUnity(const std::string &);
  void setTeam(const std::string &);
  void setName(const std::string &);
  void setMsg(const std::string &);
  void setRes(const std::string &, const std::string &, const std::string &, const std::string &, const std::string &, const std::string &, const std::string &);
};

#endif
