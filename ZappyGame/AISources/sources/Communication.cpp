//
// Communication.cpp for zappy in /home/ovoyan_s/rendu/PSU_2013_zappy/AISources
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Tue Jun 24 18:20:08 2014 ovoyan_s
// Last update Sat Jul 19 12:45:39 2014 ovoyan_s
//

/*
**				MY INCLUDES
*/

#include			"Communication.hh"

Communication::Communication()
{
  this->parseFct[0] = &Communication::rcvAloneToAlone;
  this->parseFct[1] = &Communication::rcvGroupToAlone;
  this->parseFct[2] = &Communication::rcvChiefForWork;
  this->parseFct[3] = &Communication::rcvChiefEvolution;
  this->parseFct[4] = &Communication::rcvMemberNeedFood;
  this->parseFct[5] = &Communication::rcvChief1ToChief2;
  this->parseFct[6] = &Communication::rcvChief2ToChief1;
  this->parseFct[7] = &Communication::rcvChiefToMembersDirection;
  this->parseFct[8] = &Communication::rcvChief1ToChief2Come;
  this->parseFct[9] = &Communication::rcvMemberHelpFood;
  this->listToSend = new std::list<std::string>;
  this->hearedList = new std::list<std::string>;
}

Communication::~Communication()
{

}

Communication::Communication(Communication &communicationToSet)
{
  this->setListToSend(communicationToSet.getListToSend());
  this->setHearedList(communicationToSet.getHearedList());
}

Communication			&Communication::operator=(Communication &communicationToSet)
{
  this->setListToSend(communicationToSet.getListToSend());
  this->setHearedList(communicationToSet.getHearedList());
  return (*this);
}

/*
**				GETTERS
*/

//				Returns the list of messages which would be sent by the player

std::list<std::string>		*Communication::getListToSend() const
{
  return (static_cast<std::list<std::string>* >(this->listToSend));
}

//				Returns the list of heared messages by the player

std::list<std::string>		*Communication::getHearedList() const
{
  return (static_cast<std::list<std::string>* >(this->hearedList));
}

/*
**				SETTERS
*/

//				Sets the list of messages which would be sent by the player

void				Communication::setListToSend(const std::list<std::string>
							     *listToSendToSet)
{
  this->listToSend = (std::list<std::string>*)listToSendToSet;
}

//				Sets the list of heared messages by the player

void				Communication::setHearedList(const std::list<std::string>
							     *hearedListToSet)
{
  this->hearedList = (std::list<std::string>*)hearedListToSet;
}

/*
**				TYPES OF COMMUNICATION
*/

//----------------------------------------------------------------------------------------
//----------------------------- Alone to Alone or to a Group -----------------------------

void				Communication::sndAloneToAlone(const std::string &playerName)
{
  this->listToSend->push_back(playerName + " SEUL LVL 2");
}

//----------------------------------------------------------------------------------------
//----------------------------- Group to Alone -------------------------------------------

void				Communication::sndGroupToAlone(const std::string &teamName,
							       unsigned int groupId,
							       unsigned int groupLvl, bool agreement)
{
  std::stringstream		stmGroup;
  std::stringstream		stmGroupLvl;

  stmGroup.clear();
  stmGroupLvl.clear();
  stmGroup << groupId;
  stmGroupLvl << groupLvl;
  if (agreement == true)
    this->listToSend->push_back("TEAM " + teamName + " GROUP " +
			       stmGroup.str() + " LVL " + stmGroupLvl.str() + " OK");
  else
    this->listToSend->push_back("TEAM " + teamName + " GROUP " +
			       stmGroup.str() + " LVL " + stmGroupLvl.str() + " NOT OK");    
}

//----------------------------------------------------------------------------------------
//----------------------------- Communication in Group -----------------------------------

void				Communication::sndChiefForWork(const std::string &teamName,
							       unsigned int groupId,
							       unsigned int playerId, const
							       RessourceNS::ressourceType &ressourceId)
{
  std::stringstream		stmPlayer;
  std::stringstream		stmGroup;
  std::stringstream		stmRessource;

  stmPlayer.clear();
  stmGroup.clear();
  stmRessource.clear();
  stmPlayer << playerId;
  stmGroup << groupId;
  stmRessource << ressourceId;
  this->listToSend->push_back("TEAM " + teamName + " GROUP " +
			     stmGroup.str() + " PLAYER " + stmPlayer.str() + " SEARCH "
			     + stmRessource.str());  
}

void				Communication::sndMemberNeedFood(const std::string &teamName,
								 unsigned int groupId,
                                 unsigned int playerId,
                                 unsigned int x,
                                 unsigned int y)
{
  std::stringstream		stmPlayer;
  std::stringstream		stmGroup;
  std::stringstream		stmPosX;
  std::stringstream		stmPosY;

  stmPlayer.clear();
  stmGroup.clear();
  stmPosX.clear();
  stmPosY.clear();
  stmPlayer << playerId;
  stmGroup << groupId;
  stmPosX << x;
  stmPosY << y;
  this->listToSend->push_back("TEAM " + teamName + " GROUP " + stmGroup.str()
			      + " PLAYER " + stmPlayer.str() + " NEED FOOD "
			      + stmPosX.str() + " " + stmPosY.str());
}

void				Communication::sndChiefEvolution(const std::string &teamName,
								 unsigned int groupId, int coordX,
								 int coordY)
{
  std::stringstream		stmGroup;
  std::stringstream		stmCoordX;
  std::stringstream		stmCoordY;

  stmGroup.clear();
  stmCoordX.clear();
  stmCoordY.clear();
  stmGroup << groupId;
  stmCoordX << coordX;
  stmCoordY << coordY;
  this->listToSend->push_back("TEAM " + teamName + " GROUP " + stmGroup.str()
			      + " EVOLUTION X " + stmCoordX.str() + " Y " + stmCoordY.str());
}

void                Communication::sndMemberHelpFood(const std::string &teamName, unsigned int groupId,
						     unsigned int playerId, unsigned int coordX,
						     unsigned int coordY)
{
  std::stringstream		stmGroup;
  std::stringstream		stmPlayer;
  std::stringstream		stmCoordX;
  std::stringstream		stmCoordY;
  
  stmGroup.clear();
  stmPlayer.clear();
  stmCoordX.clear();
  stmCoordY.clear();
  stmGroup << groupId;
  stmPlayer << playerId;
  stmCoordX << coordX;
  stmCoordY << coordY;
  this->listToSend->push_back("TEAM " + teamName + " GROUP " + stmGroup.str() + " PLAYER "
			      + stmPlayer.str() + " OMW " + stmCoordX.str() + " " + stmCoordY.str());
}

//----------------------------------------------------------------------------------------
//----------------------------- Communication between Groups -----------------------------

//				Chief 1 ask of other groups if they are valid (good number and good lvl)

void				Communication::sndChief1ToChief2(const std::string &teamName,
								 unsigned int groupId,
								 unsigned int groupLvl)
{
  std::stringstream		stmGroup;
  std::stringstream		stmGroupLvl;

  stmGroup.clear();
  stmGroupLvl.clear();
  stmGroup << groupId;
  stmGroupLvl << groupLvl;
  this->listToSend->push_back("TEAM " + teamName + " GROUP " + stmGroup.str() +
			     " LVL " + stmGroupLvl.str() + " NEED GROUPEMENT");
}

//				Chief 2 answers to the chief1 if his group is valid

void				Communication::sndChief2ToChief1(const std::string &teamName,
								 unsigned int groupId,
								 bool agreement)
{
  std::stringstream		stmGroup;

  stmGroup.clear();
  stmGroup << groupId;
  if (agreement == true)
    this->listToSend->push_back("TEAM " + teamName + " GROUP " + stmGroup.str() +
			       " GROUPEMENT OK");
  else
    this->listToSend->push_back("TEAM " + teamName + " GROUP " + stmGroup.str() +
			       " GROUPEMENT NOT OK");
}

//				If Chief 2 answers OK, the Chief 1 says to their group member to move

void				Communication::sndChiefToMembersDirection(const std::string &teamName,
									  unsigned int groupId,
									  unsigned int direction)
{
  std::stringstream		stmGroup;
  std::stringstream		stmDirection;

  stmGroup.clear();
  stmDirection.clear();
  stmGroup << groupId;
  stmDirection << direction;
  this->listToSend->push_back("TEAM " + teamName + " GROUP " + stmGroup.str() +
			     " GO " + stmDirection.str()); 
}

//				If Chief 2 answers OK, the Chief 1 says him that he and his group comes

void				Communication::sndChief1ToChief2Come(const std::string &teamName,
								     unsigned int groupId)
{
  std::stringstream		stmGroup;

  stmGroup.clear();
  stmGroup << groupId;
  this->listToSend->push_back("TEAM " + teamName + " GROUP " + stmGroup.str() +
			     " WE COME TO YOU");
}

/*
**				PARSING OF THE EXPRESSED TEXTS
**				These functions parses the received sentences
*/

int				Communication::parsingReceivedSentence(const MyString &strToParse,
								       int groupLvl)
{
  int				counter;
  MyStringArray			strArray;

  counter = -1;
  const_cast<MyString&>(strToParse).StrWordTab(' ', &strArray);
  while (++counter < 9)
    {
      if ((this->*parseFct[counter])(strArray) == true)
	{
	  if (counter == 5)
	    if (groupLvl != NbMath::convertInt((*strArray.GetStringAt(5)).c_str()))
	      return (-1);
	  return (counter);
	}
    }
  return (-1);
}

bool				Communication::rcvAloneToAlone(MyStringArray &strArray)
{
  if (strArray.size() != 4)
    return (false);
  if (*strArray.GetStringAt(1) != "SEUL" ||
      *strArray.GetStringAt(2) != "LVL" ||
      *strArray.GetStringAt(3) != "1")
    return (false);
  this->hearedList->push_back("0 : " + *strArray.GetStringAt(0));
  return (true);
}

bool				Communication::rcvGroupToAlone(MyStringArray &strArray)
{
  if (strArray.size() != 7 && strArray.size() != 8)
    return (false);
  if (*strArray.GetStringAt(0) != "TEAM" ||
      *strArray.GetStringAt(2) != "GROUP" ||
      *strArray.GetStringAt(4) != "LVL")
    return (false);

  if (strArray.size() == 7)
    {
      if (*strArray.GetStringAt(6) != "OK")
	return (false);
      this->hearedList->push_back("1 : " + *strArray.GetStringAt(1) + " " + *strArray.GetStringAt(3)
				 + " " + *strArray.GetStringAt(5) + " OK ");
    }

  if (strArray.size() == 8)
    {
      if (*strArray.GetStringAt(6) != "NOT" || *strArray.GetStringAt(7) != "OK")
	return (false);
      this->hearedList->push_back("1 : " + *strArray.GetStringAt(1) + " " + *strArray.GetStringAt(3)
				 + " " + *strArray.GetStringAt(5) + " NOK ");
    }
  return (true);
}

bool				Communication::rcvChiefForWork(MyStringArray &strArray)
{
  if (strArray.size() != 8)
    return (false);
  if (*strArray.GetStringAt(0) != "TEAM" ||
      *strArray.GetStringAt(2) != "GROUP" ||
      *strArray.GetStringAt(4) != "PLAYER" ||
      *strArray.GetStringAt(6) != "SEARCH")
    return (false);
  this->hearedList->push_back("2 : " + *strArray.GetStringAt(1) + " " + *strArray.GetStringAt(3)
			     + " " + *strArray.GetStringAt(5) + " " + *strArray.GetStringAt(7));
  return (true);
}

bool				Communication::rcvMemberNeedFood(MyStringArray &strArray)
{
  if (strArray.size() != 8)
    return (false);
  if (*strArray.GetStringAt(0) != "TEAM" ||
      *strArray.GetStringAt(2) != "GROUP" ||
      *strArray.GetStringAt(4) != "PLAYER" ||
      *strArray.GetStringAt(6) != "NEED" ||
      *strArray.GetStringAt(7) != "FOOD")
    return (false);
  this->hearedList->push_back("3 : " + *strArray.GetStringAt(1) + " " + *strArray.GetStringAt(3)
                 + " " + *strArray.GetStringAt(5) + " " + *strArray.GetStringAt(8) + " " + *strArray.GetStringAt(9));
  return (true);
}

bool				Communication::rcvChiefEvolution(MyStringArray &strArray)
{
  if (strArray.size() != 9)
    return (false);
  if (*strArray.GetStringAt(0) != "TEAM" ||
      *strArray.GetStringAt(2) != "GROUP" ||
      *strArray.GetStringAt(4) != "EVOLUTION" ||
      *strArray.GetStringAt(5) != "X" ||
      *strArray.GetStringAt(7) != "Y")
    return (false);
  this->hearedList->push_back("4 : " + *strArray.GetStringAt(1) + " " + *strArray.GetStringAt(3)
			     + " " + *strArray.GetStringAt(5) + " " + *strArray.GetStringAt(7));
  return (true);
}

bool				Communication::rcvChief1ToChief2(MyStringArray &strArray)
{
  if (strArray.size() != 9)
    return (false);
  if (*strArray.GetStringAt(0) != "TEAM" ||
      *strArray.GetStringAt(2) != "GROUP" ||
      *strArray.GetStringAt(4) != "LVL" ||
      *strArray.GetStringAt(6) != "NEED" ||
      *strArray.GetStringAt(7) != "GROUPEMENT")
    return (false);
  this->hearedList->push_back("5 : " + *strArray.GetStringAt(1) + " " + *strArray.GetStringAt(3)
			     + " " + *strArray.GetStringAt(5));
  return (true);
}

bool				Communication::rcvChief2ToChief1(MyStringArray &strArray)
{
  if (strArray.size() != 6 || strArray.size() != 7)
    return (false);
  if (*strArray.GetStringAt(0) != "TEAM" ||
      *strArray.GetStringAt(2) != "GROUP" ||
      *strArray.GetStringAt(4) != "GROUPEMENT")
    return (false);

  if (strArray.size() == 6)
    {
      if (*strArray.GetStringAt(5) != "OK")
	return (false);
      this->hearedList->push_back("6 : " + *strArray.GetStringAt(1) + " " + *strArray.GetStringAt(3)
				 + " OK");
    }

  if (strArray.size() == 7)
    {
      if (*strArray.GetStringAt(5) != "NOT" || *strArray.GetStringAt(6) != "OK")
	return (false);
      this->hearedList->push_back("6 : " + *strArray.GetStringAt(1) + " " + *strArray.GetStringAt(3)
				 + " NOK");
    }

  return (true);
}

bool				Communication::rcvChiefToMembersDirection(MyStringArray &strArray)
{
  if (strArray.size() != 6)
    return (false);
  if (*strArray.GetStringAt(0) != "TEAM" ||
      *strArray.GetStringAt(2) != "GROUP" ||
      *strArray.GetStringAt(4) != "GO")
    return (false);
  this->hearedList->push_back("7 : " + *strArray.GetStringAt(1) + " " + *strArray.GetStringAt(3)
			     + " " + *strArray.GetStringAt(5));  
  return (true);
}

bool				Communication::rcvChief1ToChief2Come(MyStringArray &strArray)
{
  if (strArray.size() != 8)
    return (false);
  if (*strArray.GetStringAt(0) != "TEAM" ||
      *strArray.GetStringAt(2) != "GROUP" ||
      *strArray.GetStringAt(4) != "WE" ||
      *strArray.GetStringAt(5) != "COME" ||
      *strArray.GetStringAt(6) != "TO" ||
      *strArray.GetStringAt(7) != "YOU")
    return (false);
  this->hearedList->push_back("8 : " + *strArray.GetStringAt(1) + " " + *strArray.GetStringAt(3));
  return (true);
}

bool				Communication::rcvMemberHelpFood(MyStringArray &strArray)
{
  if (strArray.size() != 8)
    return (false);
  if (*strArray.GetStringAt(0) != "TEAM" ||
      *strArray.GetStringAt(2) != "GROUP" ||
      *strArray.GetStringAt(4) != "PLAYER" ||
      *strArray.GetStringAt(6) != "OMW")
    return (false);
  this->hearedList->push_back("9 : " + *strArray.GetStringAt(1) + " " + *strArray.GetStringAt(3)
                 + " " + *strArray.GetStringAt(5) + " " + *strArray.GetStringAt(7) + " " + *strArray.GetStringAt(8));
  return (true);
}
