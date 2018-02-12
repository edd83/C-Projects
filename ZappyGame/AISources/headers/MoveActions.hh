//
// MoveActions.hh for zappy$ in /home/ovoyan_s/rendu/PSU_2013_zappy/AISources
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Tue Jul  1 18:05:27 2014 ovoyan_s
// Last update Sat Jul 12 22:29:51 2014 ovoyan_s
//

#ifndef					MOVE_ACTIONS_HH_
# define				MOVE_ACTIONS_HH_

/*
**					MY INCLUDES
*/

# include				"Namespaces.hh"
# include				"TrentonianActions.hh"

class					TrentonianActions;

class					MoveActions
{
private:
  unsigned int                          mapSizeX; // Size of Map X
  unsigned int                          mapSizeY; // Size of Map Y
  int                                   coordX; // Coordinate X
  int                                   coordY; // Coordinate Y
  MoveNS::eDirection			direction; // Direction of the Trentorian
  TrentonianActions			*trentonianActions;
  bool					align;
  void                                  (MoveActions::*movePtr[4])(); // List of move method pointers
  bool					isInHigh;
  MoveActions();

public:
  MoveActions(const TrentonianActions *trentonianActionsToSet);
  ~MoveActions();

  MoveActions				&operator=(const MoveActions &maToSet);

  //					Setters

  void                                  setMapSizeX(unsigned int mapSizeToSetX);
  void                                  setMapSizeY(unsigned int mapSizeToSetY);
  void                                  setCoordX(int coordToSetX);
  void                                  setCoordY(int coordToSetY);
  void					setDirection(const MoveNS::eDirection &directionToSet);

  //					Getters

  unsigned int                          getMapSizeX() const;
  unsigned int                          getMapSizeY() const;
  int                                   getCoordX() const;
  int                                   getCoordY() const;
  MoveNS::eDirection			getDirection() const;

  //					Rotations

  void					turnRight();
  void					turnLeft();
  void                                  lookChangeDirLeft(MoveNS::eDirection &directionLeft);
  void                                  lookChangeDirRight(MoveNS::eDirection &directionRight);
  void                                  lookChangeDirUp(MoveNS::eDirection &directionUp);
  void                                  lookChangeDirDown(MoveNS::eDirection &directionDown);

  void                                  lookChangeDirLeftList(MoveNS::eDirection &directionLeft, std::list<TrentonianActionsNS::eSecondaryAction> &list);
  void                                  lookChangeDirRightList(MoveNS::eDirection &directionRight, std::list<TrentonianActionsNS::eSecondaryAction> &list);
  void                                  lookChangeDirUpList(MoveNS::eDirection &directionUp, std::list<TrentonianActionsNS::eSecondaryAction> &list);
  void                                  lookChangeDirDownList(MoveNS::eDirection &directionDown, std::list<TrentonianActionsNS::eSecondaryAction> &list);

  void                                  lookLeft();
  void                                  lookRight();
  void                                  lookUp();
  void                                  lookDown();

  //					Simple moves

  void					moveTo();
  void					moveLeft();
  void					moveRight();
  void					moveUp();
  void					moveDown();

  //					Group Of Complex Moves

  void					moveZigZag();
  void					brSearchT(unsigned int *voiceCounter, unsigned int level);

  //					Complex moves

  MoveNS::eDirection			goTo(int *counterX, int *counterY, int aimX, int aimY,
					     MoveNS::eDirection &directionOfTrentonian,
                         std::list<TrentonianActionsNS::eSecondaryAction> &listUse);
  void                                  Move();
  void                                  move_to1();
  void                                  move_to2();
  void                                  move_to3();
  void                                  move_to4();
  void                                  move_to5();
  void                                  move_to6();
  void                                  move_to7();
  void                                  move_to8();

  void                                  move_to(int);
};

#endif				/*	MOVE_ACTIONS_HH_	*/
