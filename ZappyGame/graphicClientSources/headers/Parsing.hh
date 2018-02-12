
//// Parsing.hh for Parsing in /home/volpe_p/rendu/Zappy/PSU_2013_zappy/graphicClientSources
// 
// Made by volpe
// Login   <volpe_p@epitech.net>
// 
// Started on  Mon Jun 30 16:14:13 2014 volpe
// Last update Mon Jul  7 14:57:35 2014 volpe
//

#ifndef		PARSING_HH_
# define	PARSING_HH_

#include	<string>
#include	<iostream>
#include	<stdlib.h>
#include	"Trentonian.hh"
#include	"GraphClient.hh"
#include	"ParserException.hh"

class GraphClient;

class Parsing
{
private:
  void		(Parsing::*_fct[24])(std::string message, GraphClient &Game);
  std::string		_cmd[24];
public:
  Parsing();
  ~Parsing();

  // Fonctions

  void		cleanBuffer(char *buffer, int length);
  void		execute(std::string message, GraphClient &Game);

  // Fonctions de parsing
  void		setMapSize(std::string message, GraphClient &Game);
  void		setCaseContent(std::string content, GraphClient &Game);
  void		setTeamName(std::string teamName, GraphClient &Game);
  void		setPlayer(std::string message, GraphClient &Game);
  void		setPosPlayer(std::string message, GraphClient &Game);
  void		setLvlPlayer(std::string message, GraphClient &Game);
  void		setInvPlayer(std::string message, GraphClient &Game);
  void		brcPlayer(std::string message, GraphClient &Game);
  void		startIncant(std::string message, GraphClient &Game);
  void		endIncant(std::string message, GraphClient &Game);
  void		createEgg(std::string message, GraphClient &Game);
  void		throwRes(std::string message, GraphClient &Game);
  void		takeRes(std::string message, GraphClient &Game);
  void		playerDie(std::string message, GraphClient &Game);
  void		setEgg(std::string message, GraphClient &Game);
  void		hatchingEgg(std::string message, GraphClient &Game);
  void		playerConnect(std::string message, GraphClient &Game);
  void		eggDie(std::string message, GraphClient &Game);
  void		setTimeUnit(std::string message, GraphClient &Game);
  void		endGame(std::string message, GraphClient &Game);
  void		msgSrv(std::string message, GraphClient &Game);
  void		udkCmd(std::string message, GraphClient &Game);
  void		wrParam(std::string message, GraphClient &Game);
  void		expulsePlayer(std::string message, GraphClient &Game);
  
};
#endif
