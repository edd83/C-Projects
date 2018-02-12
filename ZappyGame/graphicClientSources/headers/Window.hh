//
// Window.hh for Window in /home/volpe_p/rendu/Zappy/PSU_2013_zappy/graphicClientSources/SFML
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Mon Jun 23 17:41:44 2014 volpe
// Last update Sun Jul 20 15:00:02 2014 volpe
//

#ifndef WINDOW_HH_
#define WINDOW_HH_

#include	<iostream>
#include	<string>
#include	<sstream>
#include	<SFML/Graphics.hpp>
#include	<SFML/System.hpp>
#include	"Map.hh"
#include	"Hud.hh"
#include	"GraphClient.hh"
#include	"Client.hh"

#define		WINDOW_WIDTH 1280
#define		WINDOW_LENGTH 720

class GraphClient;

class Client;

class Hud;

class Window
{
private:
  sf::RenderWindow	window;
  sf::Vector2f		_center;
  sf::Mutex		mapMutex;
  sf::Thread		thread;
  Client		*network;
  Hud			*hud;
  int			posCamX;
  int			posCamY;
  float			zoomLevel;
  int			timeUnit;
  GraphClient		&game;
  int			playerNext;
  bool			timeChanged;

public:
  Window(GraphClient &game);
  ~Window();

  // Getters & Setters
  void			setCenter(sf::Vector2f);
  sf::RenderWindow	&getWindow();
  int			getPosCamX() const;
  int			getPosCamY() const;
  void			setPosCamX(int);
  void			setPosCamY(int);

  // Helpers
  std::string	intToString(int);

  // Fonctions d'initialisation
  void	create(Client &network);
  void	selectPlayer();

  // Fonctions de mise à jour
  void	refreshDisplay();
  void	increaseTimeUnit();
  void	decreaseTimeUnit();

  // Fonctions d'affichage
  void	draw();
  void	madeRequest();
};
#endif
