//
// InventoryActions.hh for zappy in /home/ovoyan_s/rendu/PSU_2013_zappy/AISources
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Tue Jul  1 17:40:31 2014 ovoyan_s
// Last update Sat Jul 12 16:52:45 2014 ovoyan_s
//

#ifndef				INVENTORY_ACTIONS_HH_
# define			INVENTORY_ACTIONS_HH_

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
# include			"Inventory.hh"

class				InventoryActions
{
private:
  Inventory			inventory;
  std::string			(InventoryActions::*methPtr[7])();
  bool				(InventoryActions::*transformPtr[7])(const MyString&);

public:
  InventoryActions();
  ~InventoryActions();

  InventoryActions		&operator=(const InventoryActions &iaToSet);
  bool                          eat();
  void                          lookInventory();
  void                          takeObject(const RessourceNS::ressourceType &ressourceType);
  void                          putObject(const RessourceNS::ressourceType &ressourceType);

  void				setInventory(const Inventory &inventoryToSet);
  Inventory			&getInventory() const;

  //				Methods to put the good string and the good action in the list

  void				putTakeRessourceList(const RessourceNS::ressourceType &type,
						     std::list<std::string> &listOfStrings);

  std::string			convertRessource(const RessourceNS::ressourceType &ressourceType);
  std::string			putFood();
  std::string			putLinemate();
  std::string			putDeraumere();
  std::string			putSibur();
  std::string			putMendiane();
  std::string			putPhiras();
  std::string			putThystame();

  int				transformRessource(const MyString &strToTransform);
  bool				transformFood(const MyString &strToTransform);
  bool				transformLinemate(const MyString &strToTransform);
  bool				transformDeraumere(const MyString &strToTransform);
  bool				transformSibur(const MyString &strToTransform);
  bool				transformMendiane(const MyString &strToTransform);
  bool				transformPhiras(const MyString &strToTransform);
  bool				transformThystame(const MyString &strToTransform);
};

#endif				/*	INVENTORY_ACTIONS_HH_	*/
