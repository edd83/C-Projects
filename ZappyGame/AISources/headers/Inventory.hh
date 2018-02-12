//
// Inventory.hh for zappy in /home/ovoyan_s/rendu/PSU_2013_zappy/AISources
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Thu Jun 19 11:27:13 2014 ovoyan_s
// Last update Fri Jul 11 00:58:46 2014 ovoyan_s
//

#ifndef				INVENTORY_HH_
# define			INVENTORY_HH_

/*
**				GENERAL INCLUDES
*/

# include			<iostream>
# include			<string>

/*
**				MY INCLUDES
*/

# include			"Ressource.hh"

class				Inventory
{
private:
  unsigned int			inventory[7];
public:
  Inventory();

  Inventory			&operator=(const Inventory &inventoryToSet);
  void				takeRessource(const RessourceNS::ressourceType &typeOfRessource,
					      unsigned int quantity);
  bool				putRessource(const RessourceNS::ressourceType &typeOfRessource,
					     unsigned int quantity);
  void				setRessource(const RessourceNS::ressourceType &typeOfRessource,
					     unsigned int quantity);
  unsigned int			getRInfo(const RessourceNS::ressourceType &typeOfRessource) const;
  void				showInventory();

  ~Inventory();
};

#endif				/*	INVENTORY_HH_	*/
