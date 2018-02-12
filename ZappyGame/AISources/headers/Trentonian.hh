//
// Trentonian.hh for zappy in /home/ovoyan_s/rendu/PSU_2013_zappy/AISources
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Thu Jun 19 11:38:30 2014 ovoyan_s
// Last update Sat Jul 19 13:37:14 2014 ovoyan_s
//

#ifndef				TRENTONIAN_HH_
# define			TRENTONIAN_HH_

/*
**				Trentonian is each player, each client.
**				He is the simulation protagonist
*/

/*
**				GENERAL INCLUDES
*/

# include			<iostream>
# include			<list>
# include			<string>

/*
**				MY INCLUDES
*/

# include			"Containers.hpp"
# include			"Namespaces.hh"
# include			"ParsingMessage.hh"
# include			"Ressource.hh"
# include			"TrentonianActions.hh"

class				TrentonianActions;

class				Trentonian
{
private:
  unsigned int				fieldOfView; // The intensity level of the field
  unsigned int				level; // The level
  std::string				teamName;
  bool					align;
  std::list<Trentonian*>                encountredTrentonians; // List of encountred trentonians
  std::list<Ressource*>                 encountredRessources; // List of encountred ressources 
  TrentonianActions			*trentonianActions;
  bool					(Trentonian::*methPtr[15])(const MyString&);
  unsigned int				isFirst;
  std::string				trentonianName;
  std::list<int*>			seenCases;
  unsigned int				voiceCounter;
  void					(Trentonian::*deplacementFuncPtr[4])();

public:
  Trentonian();
  ~Trentonian();

  //					Setters

  void                                  setEncountredTrentonians(const std::list<Trentonian*>
                                                                 &listToSet);
  void                                  setEncountredRessources(const std::list<Ressource*> &listToSet);
  void					setFieldOfView(unsigned int fieldOfViewToSet);
  void					setLevel(unsigned int levelToSet);
  void					setTeamName(const std::string &teamNameToSet);
  void					setTrentonianActions(const TrentonianActions *taToSet);

  //					Getters

  std::list<Trentonian*>                &getEncountredTrentonians() const;
  std::list<Ressource*>                 &getEncountredRessources() const;
  unsigned int				getFieldOfView() const;
  unsigned int				getLevel() const;
  std::string				getTeamName() const;
  TrentonianActions			*getTrentonianActions() const;
  std::list<RessourceNS::ressourceType>	typeOfRessourcesInCase(int coordX, int coordY,
							       std::list<Ressource*> &list);
  std::string				getName() const;

  //					Expulsion

  void					deplacementUp();
  void					deplacementRight();
  void					deplacementDown();
  void					deplacementLeft();

  //					Actions Of Trentonian

  bool					conditionSearchTrentonian();
  bool					isLevelOne(const MyString &strToAnalyse);
  bool					isLevelTwo(const MyString &strToAnalyse);
  bool					advanceAction(const MyString &strToAnalyse);
  bool					turnLeftAction(const MyString &strToAnalyse);
  bool					turnRightAction(const MyString &strToAnalyse);
  bool					lookAction(const MyString &strToAnalyse);
  bool					lookInventoryAction(const MyString &strToAnalyse);
  bool					pushPlayerAction(const MyString &strToAnalyse);
  bool					incantationAction(const MyString &strToAnalyse);
  bool					forkAction(const MyString &strToAnalyse);
  bool					connectNbAction(const MyString &strToAnalyse);
  bool					broadcastTextAction(const MyString &strToAnalyse);
  bool					takeObjectAction(const MyString &strToAnalyse);
  bool					putObjectAction(const MyString &strToAnalyse);
  bool					endOfPrimaryAction(const MyString&);
  bool					deadAction(const MyString &strToAnalyse);

  bool					hearAction(const MyString &strToAnalyse);

  //					Levelling of trentonian

  bool					evolve();
  bool					levelUp();

  //					General actions

  bool					actionToDo(const MyString &strToAnalyse,
						   std::string &answerToDo);
  bool					modificationsOfTrentonian(const MyString &strToAnalyse);
  void					nettoyage();

  //					Communication with other trentonians

  void					scream(const std::string &messageToScream);
  void					hear();

  void					reproduction();
  void					push();

  void					showRessources();
  void					showSeenCases();
};

#endif				/*	TRENTONIAN_HH_	*/
