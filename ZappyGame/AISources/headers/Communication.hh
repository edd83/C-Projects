//
// Communication.hh for zappy in /home/ovoyan_s/rendu/PSU_2013_zappy/AISources
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Tue Jun 24 18:15:43 2014 ovoyan_s
// Last update Sun Jul 13 05:03:40 2014 ovoyan_s
//

#ifndef				COMMUNICATION_HH_
# define			COMMUNICATION_HH_

/*
**				The communication is the player's communication
**				he contains the heared words and the words to send
*/

/*
**				GENERAL INCLUDES
*/

# include			<iostream>
# include			<list>
# include			<string>
# include			<sstream>

/*
**				MY INCLUDES
*/

# include			"Containers.hpp"
# include			"Ressource.hh"

class				Communication
{
private:
  std::list<std::string>	*listToSend;
  std::list<std::string>	*hearedList;
  bool				(Communication::*parseFct[10])(MyStringArray &strArray);
  
public:
  Communication();
  ~Communication();

  Communication(Communication &communicationToSet);
  Communication			&operator=(Communication &communicationToSet);

  //				Getters

  std::list<std::string>	*getListToSend() const;
  std::list<std::string>	*getHearedList() const;

  //				Setters

  void				setListToSend(const std::list<std::string> *listToSendToSet);
  void				setHearedList(const std::list<std::string> *hearedListToSet);

  //				Types of Communication To Send

  void				sndAloneToAlone(const std::string &player);
  void				sndGroupToAlone(const std::string &teamName, unsigned int groupId,
					     unsigned int groupLvl, bool agreement);
  void				sndChiefForWork(const std::string &teamName, unsigned int groupId,
					     unsigned int playerId, const RessourceNS::ressourceType
					     &ressourceId);
  void				sndChiefEvolution(const std::string &teamName, unsigned int groupId,
						  int coordX, int coordY);

  void				sndMemberNeedFood(const std::string &teamName, unsigned int groupId,
						  unsigned int playerId, unsigned int x,
						  unsigned int y);
  void				sndChief1ToChief2(const std::string &teamName, unsigned int groupId,
					       unsigned int groupLvl);
  void				sndChief2ToChief1(const std::string &teamName, unsigned int groupId,
					       bool agreement);
  void				sndChiefToMembersDirection(const std::string &team,
							   unsigned int groupeId,
							   unsigned int direction);
  void				sndChief1ToChief2Come(const std::string &teamName,
						      unsigned int groupId);
  void				sndMemberHelpFood(const std::string &teamName, unsigned int groupId,
						  unsigned int playerId, unsigned int coordX,
						  unsigned int coordY);

  //				Types of Communication To Receive And To Parse

  int				parsingReceivedSentence(const MyString &strToParse, int groupLvl);
  bool				rcvAloneToAlone(MyStringArray &strArray);
  bool				rcvGroupToAlone(MyStringArray &strArray);
  bool				rcvChiefForWork(MyStringArray &strArray);
  bool				rcvChiefEvolution(MyStringArray &strArray);
  bool				rcvMemberNeedFood(MyStringArray &strArray);
  bool				rcvMemberHelpFood(MyStringArray &strArray);
  bool				rcvChief1ToChief2(MyStringArray &strArray);
  bool				rcvChief2ToChief1(MyStringArray &strArray);
  bool				rcvChiefToMembersDirection(MyStringArray &strArray);
  bool				rcvChief1ToChief2Come(MyStringArray &strArray);

};

#endif				/*	COMMUNICATION_HH_	*/
