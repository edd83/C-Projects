//
// Inventory.cpp for zappy in /home/ovoyan_s/rendu/PSU_2013_zappy/AISources
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Thu Jun 19 11:41:59 2014 ovoyan_s
// Last update Sat Jul 12 16:55:43 2014 ovoyan_s
//

/*
**			MY INCLUDES
*/

# include		"Inventory.hh"

Inventory::Inventory()
{
  unsigned int			counter;

  counter = 0;
  while (counter < 7)
    this->inventory[counter++] = 0;
}

/*
**				To equalize two inventories
*/

Inventory			&Inventory::operator=(const Inventory &inventoryToSet)
{
  int			counter;

  counter = 0;
  while (counter < 7)
    {
      this->setRessource(static_cast<RessourceNS::ressourceType>(counter),
			 inventoryToSet.getRInfo(static_cast<RessourceNS::ressourceType>(counter)));
      counter = counter + 1;
    }
  return (*this);
}

/*
**				We take a QUANTITY (number) TYPE OF RESSOURCE (ressources) of inventory
*/

void				Inventory::takeRessource(const RessourceNS::ressourceType
							 &typeOfRessource, unsigned int quantity)
{
  this->inventory[typeOfRessource] = this->inventory[typeOfRessource] + quantity;
}

/*
**				We put a QUANTITY (number) TYPE OF RESSOURCE (ressources) of inventory
*/

bool				Inventory::putRessource(const RessourceNS::ressourceType
							&typeOfRessource, unsigned int quantity)
{
  int			ressourceNumber;
  int			quantityStat;

  ressourceNumber = this->inventory[typeOfRessource];
  quantityStat = quantity;
  if (ressourceNumber < 0)
    return (false);
  if (ressourceNumber - quantityStat < 0)
    return (false);
  this->inventory[typeOfRessource] = ressourceNumber - quantity;
  return (true);
}

/*
**				Setting a certain ressource (which is represented by ressourceType
*/

void				Inventory::setRessource(const RessourceNS::ressourceType
							&typeOfRessource, unsigned int quantity)
{
  this->inventory[typeOfRessource] = quantity;
}

/*
**				We get the number of the ressource represented by ressourceType
*/

unsigned int			Inventory::getRInfo(const RessourceNS::ressourceType
							    &typeOfRessource) const
{
  return (this->inventory[typeOfRessource]);
}

void				Inventory::showInventory()
{
  std::cout << "Nourriture : " << this->inventory[0] << std::endl;
  std::cout << "Linemate   : " << this->inventory[1] << std::endl;
  std::cout << "Deraumere  : " << this->inventory[2] << std::endl;
  std::cout << "Sibur      : " << this->inventory[3] << std::endl;
  std::cout << "Mendiane   : " << this->inventory[4] << std::endl;
  std::cout << "Phiras     : " << this->inventory[5] << std::endl;
  std::cout << "Thystame   : " << this->inventory[6] << std::endl;
}

Inventory::~Inventory()
{

}
