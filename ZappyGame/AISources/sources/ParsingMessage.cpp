//
// ParsingMessage.cpp for zappy in /home/ovoyan_s/rendu/PSU_2013_zappy/AISources
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Sat Jul  5 17:32:29 2014 ovoyan_s
// Last update Sun Jul 20 14:04:25 2014 ovoyan_s
//

/*
**				MY INCLUDES
*/

#include			"ParsingMessage.hh"

ParsingMessage::ParsingMessage()
{
  unsigned int			counter;

  counter = 0;
  while (counter < 7)
    {
      this->_rscs_set[counter] = false;
      ++counter;
    }

  this->ressourceNames.AddString("nourriture");
  this->ressourceNames.AddString("linemate");
  this->ressourceNames.AddString("deraumere");
  this->ressourceNames.AddString("sibur");
  this->ressourceNames.AddString("mendiane");
  this->ressourceNames.AddString("phiras");
  this->ressourceNames.AddString("thystame");
  this->meth[0] = &ParsingMessage::setSeeUp;
  this->meth[1] = &ParsingMessage::setSeeRight;
  this->meth[2] = &ParsingMessage::setSeeDown;
  this->meth[3] = &ParsingMessage::setSeeLeft;
}

ParsingMessage::~ParsingMessage()
{

}

bool				ParsingMessage::parseMessage(MyString &strToAnalyse,
							     Communication &communicationToChange,
							     ExternInteractions
							     &externInteractionsToChange)
{
  MyStringArray			strArray;
  MyString			secondStr;

  if (strToAnalyse.StrWordTab(' ', &strArray) == false)
    throw MyException ("StrWordTab failure in ParsingMessage");
  if (strArray.size() < 2)
    return (false);

  secondStr = *strArray.GetStringAt(1);

  if (secondStr.StrWordTab(',', &strArray) == false)
    throw MyException ("StrWordTab failure in ParsingMessage");

  if (externInteractionsToChange.getFocusedTrentonian() == ""
      && externInteractionsToChange.getFocusedDirection() == -1)
    {
      externInteractionsToChange.setFocusedDirection(NbMath::convertInt(*strArray.GetStringAt(0)));
      externInteractionsToChange.setFocusedTrentonian(*strArray.GetStringAt(1));
      communicationToChange.getHearedList()->push_back(static_cast<std::string>(strToAnalyse));
      return (true);
    }
  if (externInteractionsToChange.getFocusedTrentonian() == *strArray.GetStringAt(1))
    {
      communicationToChange.getHearedList()->push_back(static_cast<std::string>(strToAnalyse));
      return (true);
    }
  return (false);
}

void				ParsingMessage::parseSeenInventory(MyString &strToAnalyse,
								   InventoryActions &inventoryActions)
{
  MyStringArray     tab;
  MyString          str2;
  std::string       str3;
  int               i;

  i = 0;
  if (strToAnalyse.size() < 2 || strToAnalyse[0] != '{'
      || strToAnalyse[strToAnalyse.size() - 2] != '}')
    throw MyException ("parseSeenInventory failure");
  if (strToAnalyse.nbOfChar(',') == 6)
    {
      while (strToAnalyse[i] != '\0')
	{
          if (strToAnalyse[i] != '{' && strToAnalyse[i] != '}')
	    str3 += strToAnalyse[i];
          i++;
	}
      str2 = str3;
      if (str2.StrWordTab(',', &tab) == false)
	throw MyException ("parseSeenInventory failure");
      this->set_items(tab, inventoryActions);
    }
}

void				ParsingMessage::setSee(const std::string &seenRessources,
						       std::list<Ressource*> &ressourcesList,
						       std::list<Trentonian*> &trentonianList,
						       std::list<int*> &countRess,
						       MoveNS::eDirection &direction,
						       int coordX, int coordY, int level)
{
  (this->*meth[direction])(seenRessources, ressourcesList, trentonianList, countRess,
			   coordX, coordY, level);
}

void				ParsingMessage::setSeeUp(const std::string &seenRessources,
							 std::list<Ressource*> &ressourcesList,
							 std::list<Trentonian*> &trentonianList,
							 std::list<int*> &countRess,
							 int coordX, int coordY, int level)
{
  std::string			str2;
  int				i[8] = {1, 4, 9, 16, 25, 36, 49, 64};
  int				width, x, y, id, lvl;
  unsigned int			s;
  unsigned int			j;

  lvl = 1;
  width = x = y = id = j = 0;
  str2 = "";
  while (seenRessources[j] != ',' && seenRessources[j] != '\0')
    {
      str2 += seenRessources[j];
      j++;
    }
  ++j;
  if (str2 != "" || str2.find("{") != std::string::npos)
    this->addList(str2, x, y, ressourcesList, trentonianList, countRess);
  
  while (lvl <= level)
    {
      while (width != (i[lvl] - i[lvl - 1]))
	{
	  x = coordX + ((-lvl) + width);
	  y = coordY + lvl;
	  s = j;
	  str2 = "";
	  while (j < seenRessources.size() && seenRessources[j] != '\0' && seenRessources[j] != ',')
	    {
	      str2 += seenRessources[j];
	      j++;
	    }
	  ++j;
	  if (j != s + 1 && str2 != "")
	    this->addList(str2, x, y, ressourcesList, trentonianList, countRess);
	  width ++;
	  id ++;
	}
      lvl ++;
      width = 0;
    }
}

void				ParsingMessage::setSeeRight(const std::string &seenRessources,
							    std::list<Ressource*> &ressourcesList,
							    std::list<Trentonian*> &trentonianList,
							    std::list<int*> &countRess,
							    int coordX, int coordY, int level)
{
  std::string			str2;
  int				i[8] = {1, 4, 9, 16, 25, 36, 49, 64};
  int				width, x, y, id, lvl;
  unsigned int			s;
  unsigned int			j;

  lvl = 1;
  width = x = y = id = j = 0;
  str2 = "";
  while (seenRessources[j] != ',' && seenRessources[j] != '\0')
    {
      str2 += seenRessources[j];
      j++;
    }
  ++j;
  if (str2 != "" || str2.find("{") != std::string::npos)
    this->addList(str2, x, y, ressourcesList, trentonianList, countRess);
  while (lvl <= level)
    {
      while (width != (i[lvl] - i[lvl - 1]) )
	{
	  x = coordX + (-lvl);
	  y = coordY + (-lvl) + width;
	  s = j;
	  str2 = "";
	  while (j < seenRessources.size() && seenRessources[j] != '\0' && seenRessources[j] != ',')
	    {
	      str2 += seenRessources[j];
	      j++;
	    }
	  ++j;
	  if (j != s + 1 && str2 != "")
	    this->addList(str2, x, y, ressourcesList, trentonianList, countRess);
	  width ++;
	  id ++;
	}
      lvl ++;
      width = 0;
    }
}

void				ParsingMessage::setSeeDown(const std::string &seenRessources,
							   std::list<Ressource*> &ressourcesList,
							   std::list<Trentonian*> &trentonianList,
							   std::list<int*> &countRess,
							   int coordX, int coordY, int level)
{
  std::string			str2;
  int				i[8] = {1, 4, 9, 16, 25, 36, 49, 64};
  int				width, x, y, id, lvl;
  unsigned int			s;
  unsigned int			j;

  lvl = 1;
  width = x = y = id = j = 0;
  str2 = "";
  while (seenRessources[j] != ',' && seenRessources[j] != '\0')
    {
      str2 += seenRessources[j];
      j++;
    }
  ++j;

  if (str2 != "" || str2.find("{") != std::string::npos)
    this->addList(str2, x, y, ressourcesList, trentonianList, countRess);

  while (lvl <= level)
    {
      while (width != (i[lvl] - i[lvl - 1]))
	{
	  x = coordX + ((-lvl) + width);
	  y = coordY - lvl;
	  s = j;
	  str2 = "";
	  while (j < seenRessources.size() && seenRessources[j] != '\0' && seenRessources[j] != ',')
	    {
	      str2 += seenRessources[j];
	      j++;
	    }
	  ++j;
	  if (j != s + 1 && str2 != "")
	    this->addList(str2, x, y, ressourcesList, trentonianList, countRess);

	  width ++;
	  id ++;
	}
      lvl ++;
      width = 0;
    }
}

void				ParsingMessage::setSeeLeft(const std::string &seenRessources,
							   std::list<Ressource*> &ressourcesList,
							   std::list<Trentonian*> &trentonianList,
							   std::list<int*> &countRess,
							   int coordX, int coordY, int level)
{
  std::string			str2;
  int				i[8] = {1, 4, 9, 16, 25, 36, 49, 64};
  int				width, x, y, id, lvl;
  unsigned int			s;
  unsigned int			j;

  lvl = 1;
  width = x = y = id = j = 0;
  str2 = "";
  while (seenRessources[j] != ',' && seenRessources[j] != '\0')
    {
      str2 += seenRessources[j];
      j++;
    }
  ++j;
  if (str2 != "" || str2.find("{") != std::string::npos)
    this->addList(str2, x, y, ressourcesList, trentonianList, countRess);
  
  while (lvl <= level)
    {
      while (width != (i[lvl] - i[lvl - 1]) )
	{
	  x = coordX - (-lvl);
	  y = coordY + (-lvl) + width;
	  s = j;
	  str2 = "";
	  while (j < seenRessources.size() && seenRessources[j] != '\0' && seenRessources[j] != ',')
	    {
	      str2 += seenRessources[j];
	      j++;
	    }
	  ++j;
	  if (j != s + 1 && str2 != "")
	    this->addList(str2, x, y, ressourcesList, trentonianList, countRess);
	  width ++;
	  id ++;
	}
      lvl ++;
      width = 0;
    }
}

void				ParsingMessage::addList(const std::string &strToAdd, int coordX,
							int coordY, std::list<Ressource*>
							&ressourcesList, std::list<Trentonian*>
							&trentonianList, std::list<int*> &countRess)
{
  MyString			str;
  MyStringArray			strArray;
  int				i;
  unsigned int			j;
  MyStringArray::iterator	it;
  MyStringArray::iterator	rnIt;
  int				coords[100][3];
  int				counter;

  i = 0;
  str = strToAdd;
  if (str == "}")
    return ;
  str.StrWordTab(' ', &strArray);
  it = strArray.begin();
  counter = 0;
  while (counter < 100)
    {
      coords[counter][0] = -1;
      coords[counter][1] = -1;
      coords[counter][2] = -1;
      ++counter;
    }
  while (it != strArray.end())
    {
      if (static_cast<MyString>(*it).contains('}') == true ||
	  static_cast<MyString>(*it).contains('{') == true ||
	  static_cast<MyString>(*it).contains(',') == true)
	(*it).resize((*it).size() - 1);
      if ((*it).size() > 0 && *it != "joueur" && *it != ","
	  && *it != "{" && *it != "}")
	{
	  j = 0;
	  rnIt = this->ressourceNames.begin();
	  while (rnIt != this->ressourceNames.end() && *it != *rnIt)
	    {
	      ++j;
	      ++rnIt;
	    }
	  if (j == this->ressourceNames.size() && *it != "")
	    throw MyException ("Ressource Inconnue");
	  this->addOne(static_cast<RessourceNS::ressourceType>(j), coordX, coordY, ressourcesList,
		       countRess, coords);
	}
      else if (*it == "joueur")
      	this->addOneTrentonian(coordX, coordY, trentonianList);	  
      ++i;
      ++it;
    }
  int				*intPtr;

  counter = 0;
  intPtr = new int[3];
  while (counter < 100 && coords[counter][2] != -1)
    {
      intPtr[0] = coords[counter][0];
      intPtr[1] = coords[counter][1];
      intPtr[2] = coords[counter][2];
      countRess.push_back(intPtr);
       ++counter;
    }
}

void				ParsingMessage::addOne(const RessourceNS::ressourceType &type,
						       int coordX, int coordY, std::list<Ressource*>
						       &ressourcesList, std::list<int*> &countRess,
						       int coords[100][3])
{
  Ressource			ressourceToAdd;
  std::list<int*>::iterator	it;
  std::list<int*>::iterator	endIt;
  
  it = countRess.begin();
  endIt = countRess.end();
  while (it != endIt && ((*it)[0] != coordX || (*it)[1] != coordY))
    ++it;
  if (it == endIt || (*it)[2] == 0)
    {
      ressourceToAdd.setCoordX(coordX);
      ressourceToAdd.setCoordY(coordY);
      ressourceToAdd.setRessourceType(type);
      if (coordinatesExists(coordX, coordY, coords) == false)
	{
	  unsigned int		counter;
	  
	  counter = 0;
	  while (coords[counter][0] != -1 && coords[counter][1] != -1 && coords[counter][2] != -1
		 && counter < 100)
	    ++counter;
	  if (counter < 100)
	    {
	      coords[counter][0] = coordX;
	      coords[counter][1] = coordY;
	      coords[counter][2] = 300;
	    }
	}
      ressourcesList.push_back(new Ressource(ressourceToAdd));
    }
}

bool				ParsingMessage::coordinatesExists(int coordX, int coordY,
								  int coords[100][3])
{
  unsigned int			counter;

  counter = 0;
  while (counter < 100)
    {
      if (coords[counter][0] == coordX && coords[counter][1] == coordY)
	return (true);
      ++counter;
    }
  return (false);
}

void				ParsingMessage::addOneTrentonian(int coordX, int coordY,
								 std::list<Trentonian*> &trentonianList)
{
  Trentonian			*trentonianToAdd;

  trentonianToAdd = new Trentonian;
  trentonianToAdd->getTrentonianActions()->getMoveActions()->setCoordX(coordX);
  trentonianToAdd->getTrentonianActions()->getMoveActions()->setCoordX(coordY);
  trentonianList.push_back(trentonianToAdd);
}

void		ParsingMessage::setItemLoop(InventoryActions &inventoryActions, MyString &strNature)
{
  int			stmNumber;
  unsigned int		tmpCount;
  std::stringstream	sstm;
  MyStringArray		tmp;
  std::string		ressourceNature;
  MyStringArray::iterator	it;
  MyStringArray::iterator	endIt;

  tmpCount = 0;
  stmNumber = 0;
  if (strNature.StrWordTab(' ', &tmp) == false)
    throw MyException ("setItemLoop failure");

  if (tmp.size() != 2)
    throw MyException ("setItemLoop failure");

  it = this->ressourceNames.begin();
  endIt = this->ressourceNames.end();
  ressourceNature = *tmp.begin();
  while (tmpCount < this->ressourceNames.size() && it != endIt && ressourceNature != *it)
    {
      ++it;
      ++tmpCount;
    }
  if (tmpCount < this->ressourceNames.size())
    {
      if (this->_rscs_set[tmpCount] == true)
	throw MyException ("Ressource deja set dans la commande");
      sstm.str(*tmp.GetStringAt(1));
      sstm >> stmNumber;
      
      inventoryActions.getInventory().takeRessource(static_cast<RessourceNS::ressourceType>(tmpCount),
						    stmNumber);
      this->_rscs_set[tmpCount] = true;
    }
}

void		ParsingMessage::set_items(MyStringArray &tab, InventoryActions &inventoryActions)
{
  MyStringArray			tmp;
  MyStringArray::iterator	it;
  MyStringArray::iterator	endIt;

  if (tab.size() == 0)
    throw MyException ("set_items failure : Inventory is empty");
  it = tab.begin();
  endIt = tab.end();
  while (it != endIt)
    {
      this->setItemLoop(inventoryActions, static_cast<MyString&>(*it));
      ++it;
    }
  unsigned int			counter;

  counter = 0;
  while (counter < 7)
    this->_rscs_set[counter++] = false;
}
