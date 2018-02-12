//
// ParsingMessage.hh for zappy in /home/ovoyan_s/rendu/PSU_2013_zappy/AISources
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Sat Jul  5 17:32:48 2014 ovoyan_s
// Last update Sat Jul 19 11:40:05 2014 ovoyan_s
//

#ifndef				PARSING_HH_
# define			PARSING_HH_

/*
**				MY INCLUDES
*/

# include			"Communication.hh"
# include			"Containers.hpp"
# include			"InventoryActions.hh"
# include			"ExternInteractions.hh"
# include			"Namespaces.hh"
# include			"Ressource.hh"
# include			"Trentonian.hh"

class				Trentonian;

class				ParsingMessage
{
private:
  MyStringArray			ressourceNames;
  void				(ParsingMessage::*meth[4])(const std::string&, std::list<Ressource*>&,
							   std::list<Trentonian*>&, std::list<int*>&,
							   int, int, int);
  bool				_rscs_set[7];

public:
  ParsingMessage();

  bool				parseMessage(MyString &strToAnalyse,
					     Communication &communicationToChange,
					     ExternInteractions &externalInteractionsToChange);

  void				setItemLoop(InventoryActions &inventoryActions, MyString &strNature);
  void				set_items(MyStringArray &tab, InventoryActions &inventoryActions);
 
  void				parseSeenInventory(MyString &strToAnalyse,
						   InventoryActions& inventoryActions);

  //				See functions

  void				setSee(const std::string &seenRessources,
				       std::list<Ressource*> &ressourcesList,	
				       std::list<Trentonian*> &trentonianList,
				       std::list<int*> &countRess, MoveNS::eDirection &direction,
				       int coordX, int coordY, int level);
  void				setSeeRight(const std::string &seenRessources,
					    std::list<Ressource*> &ressourcesList,
					    std::list<Trentonian*> &trentonianList,
					    std::list<int*> &countRess,
					    int coordX, int coordY, int level);
  void				setSeeLeft(const std::string &seenRessources,
					   std::list<Ressource*> &ressourcesList,
					   std::list<Trentonian*> &trentonianList,
					    std::list<int*> &countRess,
					   int coordX, int coordY, int level);
  void				setSeeUp(const std::string &seenRessources,
					 std::list<Ressource*> &ressourcesList,
					 std::list<Trentonian*> &trentonianList,
					    std::list<int*> &countRess,
					 int coordX, int coordY, int level);
  void				setSeeDown(const std::string &seenRessources,
					   std::list<Ressource*> &ressourcesList,
					   std::list<Trentonian*> &trentonianList,
					    std::list<int*> &countRess,
					   int coordX, int coordY, int level);

  void				addList(const std::string &strToAdd, int coordX, int coordY,
					std::list<Ressource*> &ressourcesList,
					std::list<Trentonian*> &trentonianList,
					std::list<int*> &countRess);
  void				addOne(const RessourceNS::ressourceType &type, int coordX, int coordY,
				       std::list<Ressource*> &ressourcesList,
				       std::list<int*> &countRess, int coords[100][3]);
  bool				coordinatesExists(int coordX, int coordY, int coords[100][3]);
  void				addOneTrentonian(int coordX, int coordY,
						 std::list<Trentonian*> &trentonianList);

  ~ParsingMessage();
};

#endif				/*	PARSING_HH_	*/
