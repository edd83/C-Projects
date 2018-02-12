//
// TrentonianActions.hh for zappy in /home/ovoyan_s/rendu/PSU_2013_zappy/AISources
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Sat Jun 28 14:26:56 2014 ovoyan_s
// Last update Sun Jul 20 13:48:10 2014 ovoyan_s
//

#ifndef							TRENTONIAN_ACTIONS_HH_
# define						TRENTONIAN_ACTIONS_HH_

/*
**							GENERAL INCLUDES
*/

# include						<iostream>
# include						<list>
# include						<string>
# include						<vector>

/*
**							MY INCLUDES
*/

# include						"ExternInteractions.hh"
# include						"InventoryActions.hh"
# include						"MoveActions.hh"
# include						"Namespaces.hh"
# include						"NbMath.hh"
# include						"Trentonian.hh"
# include			                        "Communication.hh"

/*
**							DEFINES AND NAMESPACES
*/

class							Trentonian;
class							MoveActions;

class							TrentonianActions
{
private:
  std::list<TrentonianActionsNS::eState>		stateList;
  std::list<TrentonianActionsNS::ePrimaryAction>	primaryActionList;
  std::list<TrentonianActionsNS::eSecondaryAction>	secondaryActionList;
  std::list<std::string>				listOfStrToUse;
  void					(TrentonianActions::*answerPtr[9])(const MyStringArray&);
  Trentonian						*trentonian;
  ExternInteractions					externInteractions;
  InventoryActions					inventoryActions;
  MoveActions						*moveActions;
  Communication			                        communication;
  
  //						Private Methods

  bool			messageOkHelpIsValide(const std::string &strToCheck);
  bool			message3IsValide(const std::string &strToCheck);
  int			getIntAt(int post, const std::string &strToCheck);

public:
  TrentonianActions();

  //						Setters

  void			setStateList(const std::list<TrentonianActionsNS::eState> &stateListToSet);
  void	                setPrimaryActionList(const std::list<TrentonianActionsNS::ePrimaryAction>
					     &primaryActionListToSet);
  void			setSecondaryActionList(const std::list<TrentonianActionsNS::eSecondaryAction>
					       &secondaryActionListToSet);
  void			setTrentonian(const Trentonian *trentonianToSet);
  void			setExternInteractions(const ExternInteractions &eaToSet);
  void			setInventoryActions(const InventoryActions &iaToSet);
  void			setMoveActions(const MoveActions *maToSet);
  void			setListOfStr(const std::list<std::string> &strListToSet);
  void				addPrimaryAction(const TrentonianActionsNS::ePrimaryAction&);
  void				addSecondaryAction(const TrentonianActionsNS::eSecondaryAction&);
  void				addStrCommand(const std::string &strCommandToAdd);
  void							addEvolution();

  //						Getters

  std::list<TrentonianActionsNS::eState>		&getStateList() const;
  std::list<TrentonianActionsNS::ePrimaryAction>	&getPrimaryActionList() const;
  std::list<TrentonianActionsNS::eSecondaryAction>	&getSecondaryActionList() const;
  std::list<std::string>				&getListOfStr() const;
  Trentonian						*getTrentonian() const;
  ExternInteractions					&getExternInteractions() const;
  InventoryActions					&getInventoryActions() const;
  MoveActions						*getMoveActions() const;
  Communication						&getCommunication() const;

  //						Show methods

  void						showSecondaryList();
  
  //						Look

  void						look();
  void						ramasseInCase(std::list<TrentonianActionsNS::eSecondaryAction> &listToUse, std::list<std::string> &strListToUse);

  //						PutActions

  unsigned int			secondaryListContains(const TrentonianActionsNS::eSecondaryAction
                              &actionToSearch);
  //
  bool				enoughMembers();
  bool				enoughRessources();
  bool				moveFormation();
  //

  //				60 %

  void				addByLastString(const std::list<std::string> &listToUse);
  void              addByLast(const std::list<TrentonianActionsNS::eSecondaryAction> &listToUse);
  void				searchRessource(int coordX, int coordY);
  void				addDead(int coordX, int coordY);

  //				Message Answers

  void				answerOfMessage(const MyStringArray &strToAnswer,
						unsigned int typeOfMessage);
  void				answerAloneToAlone(const MyStringArray &message);
  void				answerGroupToAlone(const MyStringArray &message);
  void				answerChiefForWork(const MyStringArray &message);
  void				answerChiefEvolution(const MyStringArray &message);
  void				answerMemberNeedFood(const MyStringArray &message);
  void				answerChief1ToChief2(const MyStringArray &message);
  void				answerChief2ToChief1(const MyStringArray &message);
  void				answerChiefToMembersDirection(const MyStringArray
					      &message);
  void				answerChief1ToChief2Come(const MyStringArray &message);

  //				Others

  ~TrentonianActions();
};

#endif				/*	TRENTONIAN_ACTION_HH_	*/
