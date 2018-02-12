//
// client.hh for client in /home/lardet_e/rendu/cpp_plazza/lardet_e/server
// 
// Made by lardet
// Login   <lardet_e@epitech.net>
// 
// Started on  Thu Apr 17 14:28:18 2014 lardet
// Last update Sun Jul 13 01:34:41 2014 volpe
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

# include		"Communication.hh"
# include		"NbMath.hh"
# include		"Socket.hh"
# include		"Select.hh"
# include		"Trentonian.hh"

class			Client
{
  Socket		sock;
  Select		slct;
  Trentonian		*player;
  int			port;
  std::string		ipAddress;
  MyString	        actualAction;
  MyString	        receivedAnswer;
  MyStringArray		receivedCommandsArray;

  void			(Client::*funcPtr[9])();
  void			(Client::*funcStrPtr[3])(const std::string &);

public:
  Client();
  Client(char **av);
  ~Client();

  MyString			&getCommand() const;
  void                          setCommand(const std::string &commandToSet);
  bool                          analyseCommand();
  bool				reception(int *counter, bool *beginIsGood);
  void				placeCommandsInTab(const MyString &strToUse);
  void				rearrangeList();
  bool			isGoodElevationMention(const std::string &strToUse);
  void				placeTheString(const MyString &strToUse);

  //				Client Functions

  bool				launcher(const std::string &ipAddress, int port);
  bool				checkInits(int *counter, MyString &buffer);
  bool				commandWelcome(int *counter, MyString &buffer);
  bool				commandOne(int *counter, MyString &buffer);
  bool				commandTwo(int *counter, MyString &buffer);

  //                            Primordial checks
 
  bool                          checkTeamName(const MyStringArray &arrayToCheck);
  bool                          checkPort(const MyStringArray &arrayToCheck);
  bool                          checkHostName(const MyStringArray &arrayToCheck);
  MyStringArray                 tfAvToMyStrArray(char **av);

  //				Functions To send

  void                          sendAvance();
  void                          sendTurnRight();
  void                          sendTurnLeft();
  void                          sendLook();
  void                          sendLookInventory();
  void                          sendPushPlayer();
  void                          sendIncantation();
  void                          sendFork();
  void                          sendConnectNb();

  void                          sendBroadcastText(const std::string &textToSend);
  void                          sendTakeObject(const std::string &objectToTake);
  void                          sendPutObject(const std::string &objectToPut);
};

#endif			/*	_CLIENT_HH_	*/
