//
// Trentonian.cpp for zappy in /home/ovoyan_s/rendu/PSU_2013_zappy/AISources
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Thu Jun 19 11:40:05 2014 ovoyan_s
// Last update Sun Jul 20 16:59:42 2014 ovoyan_s
//

/*
**			MY INCLUDES
*/

#include		"Trentonian.hh"

Trentonian::Trentonian()
{  
  this->teamName = "";
  this->fieldOfView = 1;
  this->fieldOfView = 0;
  this->trentonianActions = new TrentonianActions;
  this->trentonianActions->setTrentonian(this);
  this->level = 1;

  this->methPtr[0] = &Trentonian::advanceAction;
  this->methPtr[1] = &Trentonian::turnLeftAction;
  this->methPtr[2] = &Trentonian::turnRightAction;
  this->methPtr[3] = &Trentonian::lookAction;
  this->methPtr[4] = &Trentonian::lookInventoryAction;
  this->methPtr[5] = &Trentonian::pushPlayerAction;
  this->methPtr[6] = &Trentonian::incantationAction;
  this->methPtr[7] = &Trentonian::forkAction;
  this->methPtr[8] = &Trentonian::connectNbAction;
  this->methPtr[9] = &Trentonian::broadcastTextAction;
  this->methPtr[10] = &Trentonian::takeObjectAction;
  this->methPtr[11] = &Trentonian::putObjectAction;
  this->methPtr[12] = &Trentonian::endOfPrimaryAction;
  this->methPtr[13] = &Trentonian::deadAction;
  this->methPtr[14] = &Trentonian::hearAction;

  this->deplacementFuncPtr[0] = &Trentonian::deplacementUp;
  this->deplacementFuncPtr[1] = &Trentonian::deplacementRight;
  this->deplacementFuncPtr[2] = &Trentonian::deplacementDown;
  this->deplacementFuncPtr[3] = &Trentonian::deplacementLeft;

  this->trentonianName = "";
  this->isFirst = false;

  unsigned int		counter;
  char			c;
  unsigned int		cc;

  counter = 0;
  while (counter < 10)
    {
      c = '\0';
      cc = 0;
      while ((c <= ' ' || c >= '~') && cc < 500)
	{
	  c = Random::getRandomChar();
	  ++cc;
	}
      this->trentonianName.append(const_cast<char*>(&c));
      counter = counter + 1;
    }
  this->voiceCounter = 0;
}

Trentonian::~Trentonian()
{

}

void				Trentonian::showRessources()
{
  std::list<Ressource*>::iterator		it;
  std::list<Ressource*>::iterator		endIt;

  it = this->encountredRessources.begin();
  endIt = this->encountredRessources.end();
  std::cout << "====== SEEN RESSOURCES ==========" << std::endl;
  while (it != endIt)
    {
      std::cout << "X : " << (*it)->getCoordX() << " Y : " << (*it)->getCoordY() << " Type : "
		<< (*it)->getRessourceType() << std::endl;
      ++it;
    }
  std::cout << "==================================" << std::endl;
}

void				Trentonian::showSeenCases()
{
  std::list<int*>::iterator		it;
  std::list<int*>::iterator		endIt;

  it = this->seenCases.begin();
  endIt = this->seenCases.end();

  std::cout << "========== SEEN CASES ============" << std::endl;
  while (it != endIt)
    {
      std::cout << "X : " << (*it)[0] << " Y : " << (*it)[1] << " Time : "
		<< (*it)[2] << std::endl;
      ++it;
    }
  std::cout << "==================================" << std::endl;
}

bool				Trentonian::actionToDo(const MyString &strToAnalyse,
						       std::string &answerToDo)
{
  if (isFirst == true)
    {
      this->trentonianActions->addSecondaryAction(TrentonianActionsNS::lookInventory);
      this->isFirst = false;
      return (true);
    }

  if (this->modificationsOfTrentonian(strToAnalyse) == false)
    return (false);

  if (this->level == 1)
    this->isLevelOne(strToAnalyse);
  else if (this->level > 1 && this->level < 8)
    {
      if (this->level == 2)
	this->isLevelTwo(strToAnalyse);
      if (this->voiceCounter == 0)
	return (true);
    }

  this->nettoyage();

  if (this->trentonianActions->secondaryListContains(TrentonianActionsNS::incantation) > 0
      && this->typeOfRessourcesInCase(this->trentonianActions->getMoveActions()->getCoordX(),
				      this->trentonianActions->getMoveActions()->getCoordX(),
				      this->encountredRessources).size() == 0)
    {
      if (this->trentonianActions->getListOfStr().size() > 0)
	answerToDo = *this->trentonianActions->getListOfStr().begin();
      return (true);
    }

  if (this->level == 1 && this->encountredRessources.size() > 0 && *this->trentonianActions->getPrimaryActionList().begin() != TrentonianActionsNS::searchRessource)
    this->trentonianActions->searchRessource((*this->encountredRessources.begin())->getCoordX(),
					     (*this->encountredRessources.begin())->getCoordY());
  if (this->trentonianActions->getListOfStr().size() > 0)
    answerToDo = *this->trentonianActions->getListOfStr().begin();

  return (true);
}

bool				Trentonian::conditionSearchTrentonian()
{
  if (this->trentonianActions->getExternInteractions().getGroupNumber() == 0
      && (this->trentonianActions->getPrimaryActionList().size() == 0
	  || (*this->trentonianActions->getPrimaryActionList().begin()
	      == TrentonianActionsNS::searchTrentonian
	      && *this->trentonianActions->getSecondaryActionList().begin()
	      == TrentonianActionsNS::endOfPrimaryAction)))
    return (true);
  return (false);
}

bool				Trentonian::isLevelOne(const MyString &strToAnalyse)
{
  if (this->conditionSearchTrentonian() == true)
    {
      if (this->trentonianActions->getPrimaryActionList().size() > 0)
	  this->trentonianActions->getPrimaryActionList().pop_front();
      this->trentonianActions->addPrimaryAction(TrentonianActionsNS::searchTrentonian);
      this->trentonianActions->getMoveActions()->moveZigZag();
    }

  if (this->trentonianActions->getInventoryActions().getInventory().getRInfo(RessourceNS::linemate)
      >= 1 && this->trentonianActions->secondaryListContains(TrentonianActionsNS::incantation) == 0
      && strToAnalyse.find("elevation en cours") == std::string::npos
      && this->typeOfRessourcesInCase(this->trentonianActions->getMoveActions()->getCoordX(),
				      this->trentonianActions->getMoveActions()->getCoordY(),
				      this->encountredRessources).size() == 0)
    this->trentonianActions->addEvolution();
  return (true);
}

bool				Trentonian::isLevelTwo(const MyString &strToAnalyse)
{
  (void)strToAnalyse;
  if (this->conditionSearchTrentonian() == true)
    {
      this->trentonianActions->addPrimaryAction(TrentonianActionsNS::searchTrentonian);
      this->trentonianActions->getMoveActions()->moveZigZag();    
    }
  if (this->level > 1)
    this->trentonianActions->getMoveActions()->brSearchT(&this->voiceCounter, this->level);
  return (true);
}

void				Trentonian::nettoyage()
{
  if (this->trentonianActions->getSecondaryActionList().size() > 0 &&
      *this->trentonianActions->getSecondaryActionList().begin() ==
      TrentonianActionsNS::endOfPrimaryAction)
    {
      if (this->trentonianActions->getPrimaryActionList().size() > 0)
	this->trentonianActions->getPrimaryActionList().pop_front();	
      this->trentonianActions->getSecondaryActionList().pop_front();
    }
}

bool				Trentonian::modificationsOfTrentonian(const MyString &strToAnalyse)
{
  unsigned int			iter;

  iter = 20;  
  this->nettoyage();
  if (this->level > 1 && strToAnalyse.size() > 10
      && strToAnalyse.find("message ") != std::string::npos)
    {
      if (strToAnalyse[8] >= '0' && strToAnalyse[8] <= '8'
	  && strToAnalyse[9] == ',')
	iter = 14;
    }
  else if (strToAnalyse.containsStr("deplacement: ") == true && strToAnalyse.size() == 15)
    {
      unsigned int			nbOfFunction;

      nbOfFunction = strToAnalyse[strToAnalyse.size() - 2];
      nbOfFunction -= '0';
      if (nbOfFunction <= 4 && nbOfFunction >= 1)
	(this->*deplacementFuncPtr[nbOfFunction - 1])();
      return (true);
    }
  else
    iter = static_cast<int>(*this->trentonianActions->getSecondaryActionList().begin());
  if (iter < 14 && (iter > 0 || iter == 0))
    (this->*methPtr[iter])(strToAnalyse);
  std::list<int*>::iterator	it;
  std::list<int*>::iterator	endIt;

  it = this->seenCases.begin();
  endIt = this->seenCases.end();
  while(it != endIt)
    {
      (*it)[2] = (*it)[2] - 1;
      ++it;
    }
  return (true);
}

bool				Trentonian::advanceAction(const MyString &strToAnalyse)
{
  if (strToAnalyse == "ok\n")
    this->trentonianActions->getMoveActions()->moveTo();
  if (this->trentonianActions->getSecondaryActionList().size() > 0)
    this->trentonianActions->getSecondaryActionList().pop_front();
  return (true);
}

bool				Trentonian::turnLeftAction(const MyString &strToAnalyse)
{
  if (strToAnalyse == "ok\n")
    this->trentonianActions->getMoveActions()->turnLeft();
  if (this->trentonianActions->getSecondaryActionList().size() > 0)
    this->trentonianActions->getSecondaryActionList().pop_front();
  return (true);
}

bool				Trentonian::turnRightAction(const MyString &strToAnalyse)
{
  if (strToAnalyse == "ok\n")
    this->trentonianActions->getMoveActions()->turnRight();
  if (this->trentonianActions->getSecondaryActionList().size() > 0)
    this->trentonianActions->getSecondaryActionList().pop_front();
  return (true);
}

bool				Trentonian::lookAction(const MyString &strToAnalyse)
{
  int			coordX;
  int			coordY;
  MoveNS::eDirection	direction;
  ParsingMessage	parsingMessage;

  if (strToAnalyse.size() > 2 && strToAnalyse[0] == '{' && strToAnalyse[strToAnalyse.size() - 2] == '}')
    {
      coordX = this->trentonianActions->getMoveActions()->getCoordX();
      coordY = this->trentonianActions->getMoveActions()->getCoordY();
      direction = this->trentonianActions->getMoveActions()->getDirection();
      parsingMessage.setSee(strToAnalyse,
			    static_cast<std::list<Ressource*>& >(this->encountredRessources),
			    this->encountredTrentonians, this->seenCases,
			    direction, coordX, coordY, this->level);
      if (this->trentonianActions->getSecondaryActionList().size() > 0)
	this->trentonianActions->getSecondaryActionList().pop_front();
    }
  return (true);
}

bool				Trentonian::lookInventoryAction(const MyString &strToAnalyse)
{
  ParsingMessage		parsingMessage;

  parsingMessage.parseSeenInventory(const_cast<MyString&>(strToAnalyse), this->trentonianActions->getInventoryActions());
  this->trentonianActions->getInventoryActions().getInventory().showInventory();
  if (this->trentonianActions->getSecondaryActionList().size() > 0)
    this->trentonianActions->getSecondaryActionList().pop_front();
  return (true);
}

bool				Trentonian::pushPlayerAction(const MyString &strToAnalyse)
{
  (void)strToAnalyse;
  return (true);
}

bool				Trentonian::incantationAction(const MyString &strToAnalyse)
{
  if (strToAnalyse.size() == 0)
    return (false);
  if (strToAnalyse.find("niveau actuel : ") != std::string::npos
      && strToAnalyse[strToAnalyse.size() - 2] == char(this->level + 49))
    this->level = this->level + 1;
  if (this->trentonianActions->getSecondaryActionList().size() > 0)
    this->trentonianActions->getSecondaryActionList().pop_front();  
  return (true);
}

bool				Trentonian::forkAction(const MyString &strToAnalyse)
{
  (void)strToAnalyse;
  return (true);
}

bool				Trentonian::connectNbAction(const MyString &strToAnalyse)
{
  (void)strToAnalyse;
  return (true);
}

bool				Trentonian::broadcastTextAction(const MyString &strToAnalyse)
{
  if (strToAnalyse == "ok\n")
    {
    }
  if (this->trentonianActions->getSecondaryActionList().size() > 0)
    this->trentonianActions->getSecondaryActionList().pop_front();
  if (this->trentonianActions->getListOfStr().size() > 0)
    this->trentonianActions->getListOfStr().pop_front();  
  return (true);
}

bool				Trentonian::takeObjectAction(const MyString &strToAnalyse)
{
  if (strToAnalyse == "ok\n")
    {
      int			ressourceTypeInt;
      MyString			ressource;

      if (this->trentonianActions->getListOfStr().size() <= 0 ||
	  this->trentonianActions->getSecondaryActionList().size() <= 0)
	throw MyException ("Take Object Action failure");
      ressource.SetString(*this->trentonianActions->getListOfStr().begin());
      ressourceTypeInt = this->trentonianActions->getInventoryActions().transformRessource(ressource);
      if (ressourceTypeInt < 0)
	throw MyException ("Take Object Action failure");
      this->trentonianActions->getInventoryActions().takeObject(static_cast<RessourceNS::ressourceType>(ressourceTypeInt));
    }
  if (this->encountredRessources.size() > 0)
    this->encountredRessources.pop_front();
  if (this->trentonianActions->getSecondaryActionList().size() > 0)
    this->trentonianActions->getSecondaryActionList().pop_front();  
  if (this->trentonianActions->getListOfStr().size() > 0)
    this->trentonianActions->getListOfStr().pop_front();    
  return (true);
}

bool				Trentonian::putObjectAction(const MyString &strToAnalyse)
{
  if (strToAnalyse == "ok\n")
    {
      int			ressourceTypeInt;
      MyString			ressource;

      if (this->trentonianActions->getListOfStr().size() <= 0
	  || this->trentonianActions->getSecondaryActionList().size() <= 0)
	throw MyException ("Put Object Action failure");
      ressource.SetString(*this->trentonianActions->getListOfStr().begin());
      ressourceTypeInt = this->trentonianActions->getInventoryActions().transformRessource(ressource);

      if (ressourceTypeInt < 0)
	throw MyException ("Take Object Action failure");
      this->trentonianActions->getInventoryActions().putObject(static_cast<RessourceNS::ressourceType>(ressourceTypeInt));
    }
  if (this->trentonianActions->getSecondaryActionList().size() > 0)
    this->trentonianActions->getSecondaryActionList().pop_front();
  if (this->trentonianActions->getListOfStr().size() > 0)
    this->trentonianActions->getListOfStr().pop_front();  
  return (true);
}

bool				Trentonian::endOfPrimaryAction(const MyString&)
{
  if (this->trentonianActions->getSecondaryActionList().size() > 0)
    this->trentonianActions->getSecondaryActionList().pop_front();  
  if (this->trentonianActions->getPrimaryActionList().size() > 0)
    this->trentonianActions->getPrimaryActionList().pop_front();  
  return (true);
}

bool				Trentonian::deadAction(const MyString &strToAnalyse)
{
  if (strToAnalyse == "mort\n")
    {
      if (this->trentonianActions->getSecondaryActionList().size() > 0)
	this->trentonianActions->getSecondaryActionList().pop_front();
      return (false);
    }
  if (this->trentonianActions->getSecondaryActionList().size() > 0)
    this->trentonianActions->getSecondaryActionList().pop_front();
  return (true);
}

bool				Trentonian::hearAction(const MyString &strToAnalyse)
{
  (void)strToAnalyse;
  return (true);
}

void				Trentonian::deplacementUp()
{
  this->trentonianActions->getMoveActions()->setCoordY(this->trentonianActions->getMoveActions()->getCoordY() - 1);
}

void				Trentonian::deplacementRight()
{
  this->trentonianActions->getMoveActions()->setCoordX(this->trentonianActions->getMoveActions()->getCoordX() - 1);
}

void				Trentonian::deplacementDown()
{
  this->trentonianActions->getMoveActions()->setCoordY(this->trentonianActions->getMoveActions()->getCoordY() + 1);
}

void				Trentonian::deplacementLeft()
{
  this->trentonianActions->getMoveActions()->setCoordX(this->trentonianActions->getMoveActions()->getCoordX() + 1);
}


//-------------------------------------------------------------------------------
//---------------------------------- 100 % --------------------------------------

/*
**			SETTERS
*/

void                            Trentonian::setEncountredTrentonians(const std::list<Trentonian*>
								     &listToSet)
{
  this->encountredTrentonians = listToSet;
}

void                            Trentonian::setEncountredRessources(const std::list<Ressource*>
                                                                            &listToSet)
{
  this->encountredRessources = listToSet;
}

void                    Trentonian::setFieldOfView(unsigned int fieldOfViewToSet)
{
  this->fieldOfView = fieldOfViewToSet;
}

void                    Trentonian::setLevel(unsigned int levelToSet)
{
  this->level = levelToSet;
}

void			Trentonian::setTeamName(const std::string &teamNameToSet)
{
  this->teamName = teamNameToSet;
}

void			Trentonian::setTrentonianActions(const TrentonianActions *taToSet)
{
  this->trentonianActions = const_cast<TrentonianActions*>(taToSet);
}

//-------------------------------------------------------------------------------
//--------------------------------- 100 % ---------------------------------------

/*
**                      GETTERS
*/

std::list<Trentonian*>		&Trentonian::getEncountredTrentonians() const
{
  return (const_cast<std::list<Trentonian*>& >(this->encountredTrentonians));
}

std::list<Ressource*>           &Trentonian::getEncountredRessources() const
{
  return (const_cast<std::list<Ressource*>& >(this->encountredRessources));
}

unsigned int			Trentonian::getFieldOfView() const
{
  return (this->fieldOfView);
}

std::string			Trentonian::getTeamName() const
{
  return (this->teamName);
}

unsigned int			Trentonian::getLevel() const
{
  return (this->level);
}

TrentonianActions		*Trentonian::getTrentonianActions() const
{
  return (this->trentonianActions);
}

std::string			Trentonian::getName() const
{
  return (this->trentonianName);
}

std::list<RessourceNS::ressourceType>	Trentonian::typeOfRessourcesInCase(int coordX, int coordY,
									   std::list<Ressource*> &list)
{
  std::list<RessourceNS::ressourceType>	listOfTypes;
  std::list<Ressource*>::iterator	iter;
  std::list<Ressource*>::iterator	endList;

  iter = list.begin();
  endList = list.end();
  while (iter != endList)
    {
      if ((*iter)->getIsInAction() == false)
	{
	  if ((*iter)->getCoordX() == coordX && (*iter)->getCoordY() == coordY)
	    {
	      listOfTypes.push_back((*iter)->getRessourceType());
	      (*iter)->setIsInAction(true);
	    }
	}
      ++iter;
    }
  return (listOfTypes);
}

//-------------------------------------------------------------------------------
//---------------------------------- 10 % ---------------------------------------

/*
**			The client receives the answer of server if he can evolve
**			(if he can, the memeber returs true, otherwise, false)
**			10 % finished : Client part to do
*/

bool			Trentonian::evolve()
{
  return (true);
}

/*
**			The IA levels up when the conditions for the level are acquired
**			and thus, evolve send true
**			20 % finished : The case when the trentonian is pushed
*/

bool			Trentonian::levelUp()
{
  if (this->evolve() == false)
    return (false);
  return (true);
}

//-------------------------------------------------------------------------------
//----------------------------------- 10 % -------------------------------------- 

/*
**			The IA can scream around himelf
**			The screams can be heared by everyone
**			He must find a protocol
**			10 % finished : client part to do / protocol to do
*/

void			Trentonian::scream(const std::string &messageToScream)
{
  (void)messageToScream;
}

/*
**			The IA can hear around himself
**			He will receive a message with our protocol			
**			It's a passive function, it's called everytime
**			10 % finished : client part to do (particular client part)
**			protocol to do
*/

void			Trentonian::hear()
{

}

/*
**			The IA can pushs other players in a case
**			The pushed players must be go on the case which is front of their
**			precedent case relative with the direction of player
**			10 % finished : The function must be finished (client part and linkage).
*/

void			Trentonian::push()
{
  
}
