//
// InventoryActions.cpp for zappy in /home/ovoyan_s/rendu/PSU_2013_zappy/AISources
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Wed Jul  2 11:38:38 2014 ovoyan_s
// Last update Sat Jul 12 19:33:23 2014 ovoyan_s
//

/*
**			MY INCLUDES
*/

#include		"InventoryActions.hh"

InventoryActions::InventoryActions()
{
  this->methPtr[0] = &InventoryActions::putFood;
  this->methPtr[1] = &InventoryActions::putLinemate;
  this->methPtr[2] = &InventoryActions::putDeraumere;
  this->methPtr[3] = &InventoryActions::putSibur;
  this->methPtr[4] = &InventoryActions::putMendiane;
  this->methPtr[5] = &InventoryActions::putPhiras;
  this->methPtr[6] = &InventoryActions::putThystame;

  this->transformPtr[0] = &InventoryActions::transformFood;
  this->transformPtr[1] = &InventoryActions::transformLinemate;
  this->transformPtr[2] = &InventoryActions::transformDeraumere;
  this->transformPtr[3] = &InventoryActions::transformSibur;
  this->transformPtr[4] = &InventoryActions::transformMendiane;
  this->transformPtr[5] = &InventoryActions::transformPhiras;
  this->transformPtr[6] = &InventoryActions::transformThystame;
  unsigned int			counter;

  counter = 0;
  while (counter < 7)
    this->inventory.setRessource(static_cast<RessourceNS::ressourceType>(counter++), 0);
}

InventoryActions::~InventoryActions()
{

}

InventoryActions	&InventoryActions::operator=(const InventoryActions &iaToSet)
{
  this->setInventory(iaToSet.getInventory());
  return (*this);
}

//-------------------------------------------------------------------------------
//------------------------------------ 25 % -------------------------------------

/*
**  The IA eats when he gathers food  100 % finished
*/


bool			InventoryActions::eat()
{
  if (this->inventory.getRInfo(RessourceNS::food) == 0)
    return (false);

  this->inventory.takeRessource(RessourceNS::food, 1);
  return (true);
}

//-------------------------------------------------------------------------------
//------------------------------- 10 % ------------------------------------------

/*
**  The IA looks in her inventory
**  10 % finished : client part to do and the linkage with trentonian
*/

void			InventoryActions::lookInventory()
{

}

/*
**  The IA takes an object on the ground
**  The item on the ground dissappears, and the item is added
**  in inventory (+1 for his ressource type)
**  10 % finished : client part to do and the linkage with trentonian
*/

void			InventoryActions::takeObject(const RessourceNS::ressourceType &ressourceType)
{
  this->inventory.takeRessource(ressourceType, 1);
}

/*
**  The IA puts an object on the ground
**  The item on the ground appears, and the item is deleted
**  in inventory (-1 for his ressource type)
**  10 % finished : client part to do and the linkage with trentonian
*/

void			InventoryActions::putObject(const RessourceNS::ressourceType &ressourceType)
{
  if (this->inventory.putRessource(ressourceType, 1) == false)
    throw MyException ("Take Object failure");    
}

void			InventoryActions::setInventory(const Inventory &inventoryToSet)
{
  this->inventory = inventoryToSet;
}

void	InventoryActions::putTakeRessourceList(const RessourceNS::ressourceType &type,
					       std::list<std::string> &listOfStrings)
{
  if (type >= 0 && type <= 6)
    listOfStrings.push_front((this->*methPtr[static_cast<int>(type)])());
}

int	InventoryActions::transformRessource(const MyString &strToTransform)
{
  unsigned int			counter;

  counter = 0;
  while (counter < 7)
    {
      if ((this->*transformPtr[counter])(strToTransform) == true)
	return (counter);
      ++counter;
    }
  return (-1);
}

bool				InventoryActions::transformFood(const MyString &strToTransform)
{
  if (strToTransform == "nourriture")
    return (true);
  return (false);
}

bool				InventoryActions::transformLinemate(const MyString &strToTransform)
{
  if (strToTransform == "linemate")
    return (true);
  return (false);  
}

bool				InventoryActions::transformDeraumere(const MyString &strToTransform)
{
  if (strToTransform == "deraumere")
    return (true);
  return (false);
}

bool				InventoryActions::transformSibur(const MyString &strToTransform)
{
  if (strToTransform == "sibur")
    return (true);
  return (false);
}

bool				InventoryActions::transformMendiane(const MyString &strToTransform)
{
  if (strToTransform == "mendiane")
    return (true);
  return (false);
}

bool				InventoryActions::transformPhiras(const MyString &strToTransform)
{
  if (strToTransform == "phiras")
    return (true);
  return (false);
}

bool				InventoryActions::transformThystame(const MyString &strToTransform)
{
  if (strToTransform == "thystame")
    return (true);
  return (false);
}

std::string			InventoryActions::convertRessource(const RessourceNS::ressourceType
								   &ressourceType)
{
  return ((this->*methPtr[static_cast<int>(ressourceType)])());
}

std::string			InventoryActions::putFood()
{
  return ("nourriture");
}

std::string			InventoryActions::putLinemate()
{
  return ("linemate");
}

std::string			InventoryActions::putDeraumere()
{
  return ("deraumere");
}

std::string			InventoryActions::putSibur()
{
  return ("sibur");
}

std::string			InventoryActions::putMendiane()
{
  return ("mendiane");
}

std::string			InventoryActions::putPhiras()
{
  return ("phiras");
}

std::string			InventoryActions::putThystame()
{
  return ("thystame");
}

Inventory			&InventoryActions::getInventory() const
{
  return (const_cast<Inventory&>(this->inventory));
}
