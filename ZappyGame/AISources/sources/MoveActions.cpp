//
// MoveActions.cpp for zappy in /home/ovoyan_s/rendu/PSU_2013_zappy/AISources
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Wed Jul  2 11:48:14 2014 ovoyan_s
// Last update Fri Jul 18 16:17:59 2014 ovoyan_s
//

/*
**			MY INCLUDES
*/

#include		"MoveActions.hh"

MoveActions::MoveActions()
{
}

MoveActions::MoveActions(const TrentonianActions *trentonianActionsToSet)
{
  Random		rand;

  this->mapSizeX = 0;
  this->mapSizeY = 0;
  this->coordX = 0;
  this->coordY = 0;
  this->direction = static_cast<MoveNS::eDirection>(rand.GetRandomRN(4));
  this->movePtr[0] = &MoveActions::moveUp;
  this->movePtr[1] = &MoveActions::moveRight;
  this->movePtr[2] = &MoveActions::moveDown;
  this->movePtr[3] = &MoveActions::moveLeft;
  this->trentonianActions = const_cast<TrentonianActions*>(trentonianActionsToSet);
  this->align = false;
  this->isInHigh = false;
}

MoveActions::~MoveActions()
{

}

MoveActions		&MoveActions::operator=(const MoveActions &maToSet)
{
  this->setMapSizeX(maToSet.getMapSizeX());
  this->setMapSizeY(maToSet.getMapSizeY());
  this->setCoordX(maToSet.getCoordX());
  this->setCoordY(maToSet.getCoordY());
  this->setDirection(maToSet.getDirection());
  return (*this);
}

/*
**			SETTERS
*/

void                    MoveActions::setMapSizeX(unsigned int sizeMapToSetX)
{
  this->mapSizeX = sizeMapToSetX;
}

void                    MoveActions::setMapSizeY(unsigned int sizeMapToSetY)
{
  this->mapSizeY = sizeMapToSetY;
}

void                    MoveActions::setCoordX(int coordToSetX)
{
  this->coordX = coordToSetX;
}

void                    MoveActions::setCoordY(int coordToSetY)
{
  this->coordY = coordToSetY;
}

void                    MoveActions::setDirection(const MoveNS::eDirection &directionToSet)
{
  this->direction = directionToSet;
}

/*
**			GETTERS
*/

int                             MoveActions::getCoordX() const
{
  return (this->coordX);
}

int                             MoveActions::getCoordY() const
{
  return (this->coordY);
}

unsigned int                    MoveActions::getMapSizeX() const
{
  return (this->mapSizeX);
}

unsigned int                    MoveActions::getMapSizeY() const
{
  return (this->mapSizeY);
}

MoveNS::eDirection		MoveActions::getDirection() const
{
  return (this->direction);
}

/*
**			ROTATIONS
*/

//-------------------------------------------------------------------------------                      
//------------------------------------ 25 % ------------------------------------- 

/*                                                                                                     
**                      The IA turns in her Right Side                                                 
**                      100 % finished                                                                 
*/

void                    MoveActions::turnRight()
{
  if (this->direction == MoveNS::Left)
    this->direction = MoveNS::Up;
  else
    this->direction = static_cast<MoveNS::eDirection>(this->direction + 1);
}

/*                                                                                                     
**                      The IA turns in her Left Side                                                  
**                      100 % finished                                                                 
*/

void                    MoveActions::turnLeft()
{
  if (this->direction == MoveNS::Up)
    this->direction = MoveNS::Left;
  else
    this->direction = static_cast<MoveNS::eDirection>(this->direction - 1);
}

/*                                                                                                     
**                      These methods are to turn the Trentorian in a certain direction                
*/

void			MoveActions::lookLeft()
{
  MoveNS::eDirection	directionLeft;
  directionLeft = this->direction;
  if (directionLeft == MoveNS::Down)
    {
      this->trentonianActions->addSecondaryAction(TrentonianActionsNS::turnRight);
      directionLeft = MoveNS::Left;
    }
  while (directionLeft != MoveNS::Left)
    {
      this->trentonianActions->addSecondaryAction(TrentonianActionsNS::turnLeft);
      if (directionLeft == MoveNS::Up)
	directionLeft = MoveNS::Left;
      else
	directionLeft = static_cast<MoveNS::eDirection>(directionLeft - 1);
    }
}

void			MoveActions::lookRight()
{
  MoveNS::eDirection	directionRight;

  directionRight = this->direction;
  if (directionRight == MoveNS::Down)
    {
      this->trentonianActions->addSecondaryAction(TrentonianActionsNS::turnLeft);
      directionRight = MoveNS::Right;
    }
  while (directionRight != MoveNS::Right)
    {
      this->trentonianActions->addSecondaryAction(TrentonianActionsNS::turnRight);
      if (directionRight == MoveNS::Left)
	directionRight = MoveNS::Up;
      else
	directionRight = static_cast<MoveNS::eDirection>(directionRight + 1);
    }
}

void			MoveActions::lookUp()
{
  MoveNS::eDirection	directionUp;

  directionUp = this->direction;
  if (directionUp == MoveNS::Left)
    {
      this->trentonianActions->addSecondaryAction(TrentonianActionsNS::turnRight);
      directionUp = MoveNS::Up;
    }
  while (directionUp != MoveNS::Up)
    {
      this->trentonianActions->addSecondaryAction(TrentonianActionsNS::turnLeft);
      if (directionUp == MoveNS::Up)
	directionUp = MoveNS::Left;
      else
	directionUp = static_cast<MoveNS::eDirection>(directionUp - 1);
    }
}

void			MoveActions::lookDown()
{
  MoveNS::eDirection	directionDown;

  directionDown = this->direction;
  if (directionDown == MoveNS::Left)
    {
      this->trentonianActions->addSecondaryAction(TrentonianActionsNS::turnLeft);
      directionDown = MoveNS::Down;
    }
  while (directionDown != MoveNS::Down)
    {
      this->trentonianActions->addSecondaryAction(TrentonianActionsNS::turnRight);
      if (directionDown == MoveNS::Left)
	directionDown = MoveNS::Up;
      else
	directionDown = static_cast<MoveNS::eDirection>(directionDown + 1);
    }
}

/*
**			These methods changes the parameter DIRECTION which serves in other functions
*/

void			MoveActions::lookChangeDirLeft(MoveNS::eDirection &directionLeft)
{
  if (directionLeft == MoveNS::Down)
    {
      this->trentonianActions->addSecondaryAction(TrentonianActionsNS::turnRight);
      directionLeft = MoveNS::Left;
    }
  while (directionLeft != MoveNS::Left)
    {
      this->trentonianActions->addSecondaryAction(TrentonianActionsNS::turnLeft);
      if (directionLeft == MoveNS::Up)
	directionLeft = MoveNS::Left;
      else
	directionLeft = static_cast<MoveNS::eDirection>(directionLeft - 1);
    }
}

void			MoveActions::lookChangeDirRight(MoveNS::eDirection &directionRight)
{
  if (directionRight == MoveNS::Down)
    {
      this->trentonianActions->addSecondaryAction(TrentonianActionsNS::turnLeft);
      directionRight = MoveNS::Right;
    }
  while (directionRight != MoveNS::Right)
    {
      this->trentonianActions->addSecondaryAction(TrentonianActionsNS::turnRight);
      if (directionRight == MoveNS::Left)
	directionRight = MoveNS::Up;
      else
	directionRight = static_cast<MoveNS::eDirection>(directionRight + 1);
    }
}

void			MoveActions::lookChangeDirUp(MoveNS::eDirection &directionUp)
{
  if (directionUp == MoveNS::Left)
    {
      this->trentonianActions->addSecondaryAction(TrentonianActionsNS::turnRight);
      directionUp = MoveNS::Up;
    }
  while (directionUp != MoveNS::Up)
    {
      this->trentonianActions->addSecondaryAction(TrentonianActionsNS::turnLeft);
      if (directionUp == MoveNS::Up)
	directionUp = MoveNS::Left;
      else
	directionUp = static_cast<MoveNS::eDirection>(directionUp - 1);
    }
}

void			MoveActions::lookChangeDirDown(MoveNS::eDirection &directionDown)
{
  if (directionDown == MoveNS::Left)
    {
      this->trentonianActions->addSecondaryAction(TrentonianActionsNS::turnLeft);
      directionDown = MoveNS::Down;
    }
  while (directionDown != MoveNS::Down)
    {
      this->trentonianActions->addSecondaryAction(TrentonianActionsNS::turnRight);
      if (directionDown == MoveNS::Left)
	directionDown = MoveNS::Up;
      else
	directionDown = static_cast<MoveNS::eDirection>(directionDown + 1);
    }
}


/*
**			These methods changes the parameter DIRECTION which serves in other functions
**			in the LIST parameter
*/

void	MoveActions::lookChangeDirLeftList(MoveNS::eDirection &directionLeft,
					   std::list<TrentonianActionsNS::eSecondaryAction> &list)
{
  if (directionLeft == MoveNS::Down)
    {
      list.push_back(TrentonianActionsNS::turnRight);
      directionLeft = MoveNS::Left;
    }
  while (directionLeft != MoveNS::Left)
    {
      list.push_back(TrentonianActionsNS::turnLeft);
      if (directionLeft == MoveNS::Up)
	directionLeft = MoveNS::Left;
      else
	directionLeft = static_cast<MoveNS::eDirection>(directionLeft - 1);
    }
}

void	MoveActions::lookChangeDirRightList(MoveNS::eDirection &directionRight,
					    std::list<TrentonianActionsNS::eSecondaryAction> &list)
{
  if (directionRight == MoveNS::Down)
    {
      list.push_back(TrentonianActionsNS::turnLeft);
      directionRight = MoveNS::Right;
    }
  while (directionRight != MoveNS::Right)
    {
      list.push_back(TrentonianActionsNS::turnRight);
      if (directionRight == MoveNS::Left)
	directionRight = MoveNS::Up;
      else
	directionRight = static_cast<MoveNS::eDirection>(directionRight + 1);
    }
}

void	MoveActions::lookChangeDirUpList(MoveNS::eDirection &directionUp,
					 std::list<TrentonianActionsNS::eSecondaryAction> &list)
{
  if (directionUp == MoveNS::Left)
    {
      list.push_back(TrentonianActionsNS::turnRight);
      directionUp = MoveNS::Up;
    }
  while (directionUp != MoveNS::Up)
    {
      list.push_back(TrentonianActionsNS::turnLeft);
      if (directionUp == MoveNS::Up)
	directionUp = MoveNS::Left;
      else
	directionUp = static_cast<MoveNS::eDirection>(directionUp - 1);
    }
}

void	MoveActions::lookChangeDirDownList(MoveNS::eDirection &directionDown,
					   std::list<TrentonianActionsNS::eSecondaryAction> &list)
{
  if (directionDown == MoveNS::Left)
    {
      list.push_back(TrentonianActionsNS::turnLeft);
      directionDown = MoveNS::Down;
    }
  while (directionDown != MoveNS::Down)
    {
      list.push_back(TrentonianActionsNS::turnRight);
      if (directionDown == MoveNS::Left)
	directionDown = MoveNS::Up;
      else
	directionDown = static_cast<MoveNS::eDirection>(directionDown + 1);
    }
}

/*                                                                                                     
**                      The Trentonian moves in relationship with where he's looking (he's looking)    
**                      100 % finished                                                                 
*/

void                    MoveActions::moveTo()
{
  (this->*movePtr[this->direction])();
}

/*                                                                                                     
**                      Moving Up                                                                      
**                      100 % finished                                                                 
*/

void                    MoveActions::moveUp()
{
  ++this->coordY;
}

/*                                                                                                     
**                      Moving Right                                                                   
**                      100 % finished                                                                 
*/

void                    MoveActions::moveRight()
{
  ++this->coordX;
}

/*                                                                                                     
**                      Move Down                                                                      
**                      100 % finished                                                                 
*/

void                    MoveActions::moveDown()
{
  --this->coordY;
}

/*                                                                                                     
**                      Moving Left                                                                    
**                      100 % finished                                                                 
*/

void                    MoveActions::moveLeft()
{
  --this->coordX;
}

/*
**			GROUP OF COMPLEX MOVES
*/

void			MoveActions::moveZigZag()
{
  int			counterX;
  int			counterY;
  int			counterDecalageX;
  MoveNS::eDirection	directionToTurn;

  counterX = this->coordX;
  counterY = this->coordY;
  counterDecalageX = this->coordX + 3;
  directionToTurn = this->direction;
  if (counterY == static_cast<int>(this->mapSizeY))
    this->isInHigh = true;
  else if (counterY == 0)
    this->isInHigh = false;

  if (this->isInHigh == false)
    {
      this->lookChangeDirUp(directionToTurn);
      while (counterY < static_cast<int>(this->mapSizeY))
	{
	  this->Move();
	  counterY = counterY + 1;
	}
    }
  else if (this->isInHigh == true)
    {
      this->lookChangeDirDown(directionToTurn);
      while (counterY > 0)
	{
	  this->Move();
	  counterY = counterY - 1;
	}
    }
  this->lookChangeDirRight(directionToTurn);
  while (counterX < counterDecalageX)
    {
      this->Move();
      counterX = counterX + 1;
    }
  this->trentonianActions->addSecondaryAction(TrentonianActionsNS::endOfPrimaryAction);
}

void				MoveActions::brSearchT(unsigned int *voiceCounter, unsigned int level)
{
  if (*voiceCounter % 8 == 0)
    if (level > 1)
      {
	this->trentonianActions->getCommunication().sndAloneToAlone(this->trentonianActions->getTrentonian()->getName());
	this->trentonianActions->getSecondaryActionList().push_front(TrentonianActionsNS::broadcastText);
	this->trentonianActions->getListOfStr().push_front(*this->trentonianActions->getCommunication().getListToSend()->begin());
	this->trentonianActions->getCommunication().getListToSend()->pop_front();
      }
  ++(*voiceCounter);
}

/*
**			COMPLEX MOVES
*/

MoveNS::eDirection		MoveActions::goTo(int *counterX, int *counterY, int aimX, int aimY,
						  MoveNS::eDirection &directionOfTrentonian,
						  std::list<TrentonianActionsNS::eSecondaryAction>
						  &listUse)
{
  if (*counterY != aimY)
    {
      if (*counterY < aimY)
        {
          this->lookChangeDirUpList(directionOfTrentonian, listUse);
          while (*counterY < aimY)
            {
              listUse.push_back(TrentonianActionsNS::advance);
              ++(*counterY);
            }
        }
      else if (*counterY > aimY)
        {
          this->lookChangeDirDownList(directionOfTrentonian, listUse);
          while (*counterY > aimY)
            {
              listUse.push_back(TrentonianActionsNS::advance);
              --(*counterY);
            }
        }
    }
  
  if (*counterX != aimX)
    {
      if (*counterX < aimX)
        {
          this->lookChangeDirRightList(directionOfTrentonian, listUse);
          while (*counterX < aimX)
            {
              listUse.push_back(TrentonianActionsNS::advance);
              ++(*counterX);
            }
        }
      else if (*counterX > aimX)
        {
          this->lookChangeDirLeftList(directionOfTrentonian, listUse);
          while (*counterX > aimX)
            {
              listUse.push_back(TrentonianActionsNS::advance);
              --(*counterX);
            }
        }
    }
  return (directionOfTrentonian);
}

void    MoveActions::Move()
{
  this->trentonianActions->addSecondaryAction(TrentonianActionsNS::look);
  this->trentonianActions->addSecondaryAction(TrentonianActionsNS::advance);
}

// OTHER ACTIONS


void        MoveActions::move_to1()
{
    this->trentonianActions->addSecondaryAction(TrentonianActionsNS::advance);
}

void        MoveActions::move_to2()
{
    this->trentonianActions->addSecondaryAction(TrentonianActionsNS::advance);
}

void        MoveActions::move_to3()
{
    this->trentonianActions->addSecondaryAction(TrentonianActionsNS::turnRight);
    this->trentonianActions->addSecondaryAction(TrentonianActionsNS::advance);
}

void        MoveActions::move_to4()
{
    this->trentonianActions->addSecondaryAction(TrentonianActionsNS::turnRight);
    this->trentonianActions->addSecondaryAction(TrentonianActionsNS::advance);
}

void        MoveActions::move_to5()
{
    this->trentonianActions->addSecondaryAction(TrentonianActionsNS::turnRight);
    this->trentonianActions->addSecondaryAction(TrentonianActionsNS::turnRight);
    this->trentonianActions->addSecondaryAction(TrentonianActionsNS::advance);
}

void        MoveActions::move_to6()
{
    this->trentonianActions->addSecondaryAction(TrentonianActionsNS::turnLeft);
    this->trentonianActions->addSecondaryAction(TrentonianActionsNS::advance);
}

void        MoveActions::move_to7()
{
    this->trentonianActions->addSecondaryAction(TrentonianActionsNS::turnLeft);
    this->trentonianActions->addSecondaryAction(TrentonianActionsNS::advance);
}

void        MoveActions::move_to8()
{
    this->trentonianActions->addSecondaryAction(TrentonianActionsNS::advance);
}

void        MoveActions::move_to(int i)
{
    void    (MoveActions::*tab[9])(void);

    tab[1] = &MoveActions::move_to1;
    tab[2] = &MoveActions::move_to2;
    tab[3] = &MoveActions::move_to3;
    tab[4] = &MoveActions::move_to4;
    tab[5] = &MoveActions::move_to5;
    tab[6] = &MoveActions::move_to6;
    tab[7] = &MoveActions::move_to7;
    tab[8] = &MoveActions::move_to8;
    (this->*tab[i])();
}
