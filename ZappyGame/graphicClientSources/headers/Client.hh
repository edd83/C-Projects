//
// client.hh for client in /home/lardet_e/rendu/cpp_plazza/lardet_e/server
// 
// Made by lardet
// Login   <lardet_e@epitech.net>
// 
// Started on  Thu Apr 17 14:28:18 2014 lardet
// Last update Sun Jul 20 14:57:42 2014 volpe
//

#ifndef			_CLIENT_HH_
# define		_CLIENT_HH_

/*
**			This is the client class who manages
**			the communications with server
*/

/*
**		        GENERAL INCLUDES
*/

# include		<string>
# include		<vector>
# include		<iostream>
# include		<fstream>
# include		<sstream>
# include		<iomanip>

/*
**			MY INCLUDES
*/

# include		"Socket.hh"
# include		"Select.hh"
# include		"GraphClient.hh"
# include		"Containers.hpp"
# include		"Parsing.hh"

class			GraphClient;

class			Parsing;

class			Client
{
  Socket		sock;
  Select		slct;
  int			port;
  std::string		ipAddress;
  MyString	        actualAction;
  MyString	        receivedAnswer;
  MyStringArray		receivedCommandsArray;
  GraphClient		*game;
  Parsing		*parser;
  bool			isFirstTime;
  int			counter;

public:
  Client();
  Client(char **av);
  ~Client();

  MyString			&getCommand() const;
  void                          setCommand(const std::string &commandToSet);
  bool				reception(int *counter);
  void				placeCommandsInTab(const MyString &strToUse);
  void				rearrangeList();
  bool				isGoodElevationMention(const std::string &strToUse);
  void				placeTheString(const MyString &strToUse);

  //				Client Functions

  bool				launcher(const std::string &ipAddress, int port);
  bool				checkInits(int *counter, MyString &buffer);
  bool				commandWelcome(int *counter, MyString &buffer);
  bool				update();
  void				sendTimeUnit(int);

  //                            Primordial checks
 
  bool                          checkPort(const MyStringArray &arrayToCheck);
  bool                          checkHostName(const MyStringArray &arrayToCheck);
  MyStringArray                 tfAvToMyStrArray(char **av);
};

#endif			/*	_CLIENT_HH_	*/
