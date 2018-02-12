//
// TrentonianActions.cpp for zappy in /home/ovoyan_s/rendu/PSU_2013_zappy/AISources
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Sat Jun 28 14:35:41 2014 ovoyan_s
// Last update Sun Jul 20 13:48:22 2014 ovoyan_s
//

/*
**				MY INCLUDES
*/

#include			"TrentonianActions.hh"

TrentonianActions::TrentonianActions()
{
  this->stateList.clear();
  this->primaryActionList.clear();
  this->secondaryActionList.clear();
  this->answerPtr[0] = &TrentonianActions::answerAloneToAlone;
  this->answerPtr[1] = &TrentonianActions::answerGroupToAlone;
  this->answerPtr[2] = &TrentonianActions::answerChiefForWork;
  this->answerPtr[3] = &TrentonianActions::answerChiefEvolution;
  this->answerPtr[4] = &TrentonianActions::answerMemberNeedFood;
  this->answerPtr[5] = &TrentonianActions::answerChief1ToChief2;
  this->answerPtr[6] = &TrentonianActions::answerChief2ToChief1;
  this->answerPtr[7] = &TrentonianActions::answerChiefToMembersDirection;
  this->answerPtr[8] = &TrentonianActions::answerChief1ToChief2Come;  
  this->moveActions = new MoveActions(this);
}

TrentonianActions::~TrentonianActions()
{

}

/*
**						SETTERS
*/

void                    TrentonianActions::setStateList(const std::list<TrentonianActionsNS::eState>
							&stateListToSet)
{
  this->stateList = stateListToSet;
}

void                    TrentonianActions::setPrimaryActionList(const std::list<TrentonianActionsNS::ePrimaryAction> &primaryActionListToSet)
{
  this->primaryActionList = primaryActionListToSet;
}

void                    TrentonianActions::setSecondaryActionList(const std::list<TrentonianActionsNS::eSecondaryAction> &secondaryActionListToSet)
{
  this->secondaryActionList = secondaryActionListToSet;
}

void			TrentonianActions::setTrentonian(const Trentonian *trentonianToSet)
{
  this->trentonian = const_cast<Trentonian*>(trentonianToSet);
}

void			TrentonianActions::setExternInteractions(const ExternInteractions &eaToSet)
{
  this->externInteractions = eaToSet;
}

void			TrentonianActions::setInventoryActions(const InventoryActions &iaToSet)
{
  this->inventoryActions = iaToSet;
}

void			TrentonianActions::setMoveActions(const MoveActions *maToSet)
{
  this->moveActions = const_cast<MoveActions*>(maToSet);
}

void			TrentonianActions::setListOfStr(const std::list<std::string> &strListToSet)
{
  this->listOfStrToUse = strListToSet;
}

/*
**						GETTERS
*/

std::list<TrentonianActionsNS::eState>                  &TrentonianActions::getStateList() const
{
  return (const_cast<std::list<TrentonianActionsNS::eState>& >(this->stateList));
}

std::list<TrentonianActionsNS::ePrimaryAction>		&TrentonianActions::getPrimaryActionList() const
{
  return (const_cast<std::list<TrentonianActionsNS::ePrimaryAction>& >(this->primaryActionList));
}

std::list<TrentonianActionsNS::eSecondaryAction>	&TrentonianActions::getSecondaryActionList()
  const
{
  return (const_cast<std::list<TrentonianActionsNS::eSecondaryAction>& >(this->secondaryActionList));
}

void	TrentonianActions::addPrimaryAction(const TrentonianActionsNS::ePrimaryAction &action)
{
    this->primaryActionList.push_back(action);
}

void	TrentonianActions::addSecondaryAction(const TrentonianActionsNS::eSecondaryAction &action)
{
    this->secondaryActionList.push_back(action);
}

void				TrentonianActions::addStrCommand(const std::string &strCommandToAdd)
{
  this->listOfStrToUse.push_back(strCommandToAdd);
}

std::list<std::string>		&TrentonianActions::getListOfStr() const
{
  return (const_cast<std::list<std::string>& >(this->listOfStrToUse));
}
	
Trentonian			*TrentonianActions::getTrentonian() const
{
  return (this->trentonian);
}

ExternInteractions		&TrentonianActions::getExternInteractions() const
{
  return ((ExternInteractions&)this->externInteractions);
}

InventoryActions		&TrentonianActions::getInventoryActions() const
{
  return ((InventoryActions&)this->inventoryActions);
}

MoveActions			*TrentonianActions::getMoveActions() const
{
  return (this->moveActions);
}

Communication			&TrentonianActions::getCommunication() const
{
  return (const_cast<Communication&>(this->communication));
}

unsigned int	TrentonianActions::secondaryListContains(const TrentonianActionsNS::eSecondaryAction
							 &actionToSearch)
{
  unsigned int		counter;
  std::list<TrentonianActionsNS::eSecondaryAction>::iterator	it;
  std::list<TrentonianActionsNS::eSecondaryAction>::iterator	endIt;

  it = this->secondaryActionList.begin();
  endIt = this->secondaryActionList.end();
  counter = 0;
  while (it != endIt)
    {
      if (*it == actionToSearch)
	counter = counter + 1;
      ++it;
    }
  return (counter);
}

/*
**				SHOW METHODS
*/

void				TrentonianActions::showSecondaryList()
{
  std::list<TrentonianActionsNS::eSecondaryAction>::iterator	it;
  std::list<TrentonianActionsNS::eSecondaryAction>::iterator	endIt;
  std::vector<std::string>					listOfActions;
  std::list<std::string>::iterator				strIt;

  strIt = this->listOfStrToUse.begin();
  std::cout << std::endl << "===============================================" << std::endl;

  it = this->secondaryActionList.begin();
  endIt = this->secondaryActionList.end();
  listOfActions.push_back("avance");
  listOfActions.push_back("tourne a gauche");
  listOfActions.push_back("tourne a droite");
  listOfActions.push_back("regarde");
  listOfActions.push_back("regarde l'inventaire");
  listOfActions.push_back("pousse un joueur");
  listOfActions.push_back("incantation");
  listOfActions.push_back("reproduction");
  listOfActions.push_back("nombre joueurs");

  listOfActions.push_back("crie");
  listOfActions.push_back("prend un objet");
  listOfActions.push_back("pose un objet");
  listOfActions.push_back("supprime une liste");
  listOfActions.push_back("est mort");
  while (it != endIt)
    {
      std::cout << listOfActions[(*it)];
      if ((*it) == TrentonianActionsNS::takeObject || (*it) == TrentonianActionsNS::putObject ||
	  (*it) == TrentonianActionsNS::broadcastText)
	{
	  if (strIt != this->listOfStrToUse.end())
	    {
	      std::cout << "   " << *strIt;
	      ++strIt;
	    }
	}
      std::cout << std::endl;
      ++it;
    }
  std::cout << std::endl << "===============================================" << std::endl;
}

/*
**					Adds secondary actions list by the last
*/

void			TrentonianActions::addByLastString(const std::list<std::string> &listToUse)
{
  std::list<std::string>::const_iterator	beginIt;
  std::list<std::string>::const_iterator	trueEndIt;
  std::list<std::string>::const_iterator	endIt;

  beginIt = listToUse.begin();
  trueEndIt = listToUse.end();
  endIt = listToUse.end();
  while (endIt != beginIt)
    {
      if (endIt != trueEndIt)
	this->listOfStrToUse.push_front(*endIt);
      --endIt;
    }
  this->listOfStrToUse.push_front(*endIt);
}

void	TrentonianActions::addByLast(const std::list<TrentonianActionsNS::eSecondaryAction> &listToUse)
{
  std::list<TrentonianActionsNS::eSecondaryAction>::const_iterator	beginIt;
  std::list<TrentonianActionsNS::eSecondaryAction>::const_iterator	trueEndIt;
  std::list<TrentonianActionsNS::eSecondaryAction>::const_iterator	endIt;

  beginIt = listToUse.begin();
  trueEndIt = listToUse.end();
  endIt = listToUse.end();
  while (endIt != beginIt)
    {
      if (endIt != trueEndIt)
	this->secondaryActionList.push_front(*endIt);
      --endIt;
    }
  this->secondaryActionList.push_front(*endIt);
}

/*
**				This method is to gather ressources on a case, then return in the
**				initial case 60 % achieved
*/

void					TrentonianActions::searchRessource(int coordX, int coordY)
{
  MoveNS::eDirection			directionToUse;
  MoveNS::eDirection			initialDirection;
  std::list<RessourceNS::ressourceType>	ressourcesInCaseList;
  std::list<RessourceNS::ressourceType>::iterator	iter;
  std::list<RessourceNS::ressourceType>::iterator	iterEnd;
  std::list<TrentonianActionsNS::eSecondaryAction>	listToUse;
  int					posX;
  int					posY;

  ressourcesInCaseList = this->trentonian->typeOfRessourcesInCase(coordX, coordY, this->trentonian->getEncountredRessources());

  if (ressourcesInCaseList.size() > 0)
    {
      this->primaryActionList.push_front(TrentonianActionsNS::searchRessource);
      posX = this->moveActions->getCoordX();
      posY = this->moveActions->getCoordY();
      initialDirection = this->moveActions->getDirection();

      directionToUse = this->moveActions->goTo(&posX, &posY, coordX, coordY, initialDirection,
					       listToUse);
      iter = ressourcesInCaseList.begin();
      iterEnd = ressourcesInCaseList.end();
      while (iter != iterEnd)
	{
	  listToUse.push_back(TrentonianActionsNS::takeObject);
	  this->inventoryActions.putTakeRessourceList((*iter), this->listOfStrToUse);
	  ++iter;
	}
      directionToUse = this->moveActions->goTo(&posX, &posY, this->moveActions->getCoordX(),
					       this->moveActions->getCoordY(), directionToUse,
					       listToUse);  
      this->moveActions->lookChangeDirUpList(directionToUse, listToUse);
      if (listToUse.size() > 0)
	listToUse.push_back(TrentonianActionsNS::look);
      listToUse.push_back(TrentonianActionsNS::endOfPrimaryAction);
      this->addByLast(listToUse);
    }
}

void				TrentonianActions::addDead(int coordX, int coordY)
{
  std::stringstream		cX;
  std::stringstream		cY;
  std::string			commandToAdd;

  cX.clear();
  cY.clear();
  cX << coordX;
  cY << coordY;
  commandToAdd = static_cast<std::string>("MORT :  X ") + cX.str() + " Y " + cY.str();
  this->addSecondaryAction(TrentonianActionsNS::broadcastText);
  this->addStrCommand(commandToAdd);
  this->addSecondaryAction(TrentonianActionsNS::dead);
}

void				TrentonianActions::addEvolution()
{
  std::list<TrentonianActionsNS::eSecondaryAction>	listToUse;
  std::list<std::string>				strListToUse;

  this->primaryActionList.push_front(TrentonianActionsNS::searchEvolution);
  this->ramasseInCase(listToUse, strListToUse);
  strListToUse.push_back("linemate");
  listToUse.push_back(TrentonianActionsNS::putObject);
  listToUse.push_back(TrentonianActionsNS::incantation);
  listToUse.push_back(TrentonianActionsNS::endOfPrimaryAction);
  this->addByLast(listToUse);
  this->addByLastString(strListToUse);
}

void				TrentonianActions::ramasseInCase(std::list<TrentonianActionsNS::eSecondaryAction> &listToUse, std::list<std::string> &strListToUse)
{
  std::list<RessourceNS::ressourceType>	ressourceList;

  ressourceList = this->trentonian->typeOfRessourcesInCase(this->moveActions->getCoordX(),
								   this->moveActions->getCoordY(), this->trentonian->getEncountredRessources());
  if (ressourceList.size() > 0)
    {
      std::list<RessourceNS::ressourceType>::iterator	it;
      std::list<RessourceNS::ressourceType>::iterator	endIt;

      it = ressourceList.begin();
      endIt = ressourceList.end();
      while (it != endIt)
	{
	  this->inventoryActions.putTakeRessourceList((*it), strListToUse);
	  listToUse.push_back(TrentonianActionsNS::takeObject);
	  ++it;
	}
    }
}

/*
**						MESSAGE ANSWERS
*/

void				TrentonianActions::answerOfMessage(const MyStringArray &strToAnswer,
								   unsigned int typeOfMessage)
{
  (this->*answerPtr[typeOfMessage])(strToAnswer);
}

void				TrentonianActions::answerAloneToAlone(const MyStringArray &message)
{
  int				direction;

  direction = NbMath::convertInt((*message.GetStringAt(7)).c_str());
  (void)direction;
  //faire les actions de move vers cette direction;
}

void				TrentonianActions::answerGroupToAlone(const MyStringArray &message)
{
  int				direction;

  direction = NbMath::convertInt((*message.GetStringAt(7)).c_str());
  (void)direction;
}

void				TrentonianActions::answerChiefForWork(const MyStringArray &message)
{
  int				direction;

  direction = NbMath::convertInt((*message.GetStringAt(7)).c_str());
  (void)direction;
}

void				TrentonianActions::answerChiefEvolution(const MyStringArray &message)
{
  int				direction;

  direction = NbMath::convertInt((*message.GetStringAt(7)).c_str());
  (void)direction;
}

void				TrentonianActions::answerMemberNeedFood(const MyStringArray &message)
{
  int				direction;

  direction = NbMath::convertInt((*message.GetStringAt(7)).c_str());
  (void)direction;
}

void				TrentonianActions::answerChief1ToChief2(const MyStringArray &message)
{
  int				direction;

  direction = NbMath::convertInt((*message.GetStringAt(7)).c_str());
  (void)direction;
}

void				TrentonianActions::answerChief2ToChief1(const MyStringArray &message)
{
  int				direction;

  direction = NbMath::convertInt((*message.GetStringAt(7)).c_str());
  (void)direction;
}

void				TrentonianActions::answerChiefToMembersDirection(const MyStringArray
										 &message)
{
  int				direction;

  direction = NbMath::convertInt((*message.GetStringAt(7)).c_str());
  (void)direction;
}

void				TrentonianActions::answerChief1ToChief2Come(const MyStringArray
									    &message)
{
  int				direction;

  direction = NbMath::convertInt((*message.GetStringAt(7)).c_str());
  (void)direction;
}

