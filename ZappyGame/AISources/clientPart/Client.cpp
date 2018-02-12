//
// client.cpp for client in /home/lardet_e/rendu/cpp_plazza/lardet_e/server
// 
// Made by lardet
// Login   <lardet_e@epitech.net>
// 
// Started on  Thu Apr 17 14:28:05 2014 lardet
// Last update Sun Jul 20 17:00:39 2014 ovoyan_s
//

/*
**			MY INCLUDES
*/

#include		"Client.hh"

Client::Client()
{

}

Client::Client(char **av)
{
  try
    {
      MyStringArray		strArray;
      
      this->port = 0;
      this->ipAddress = "127.0.0.1";
      this->player = new Trentonian;
      strArray.clear();
      strArray = this->tfAvToMyStrArray(av);
      if (this->checkTeamName(strArray) == false ||
	  this->checkPort(strArray) == false ||
	  this->checkHostName(strArray) == false)
	throw MyException("Error in arguments of the client");
      
      this->funcPtr[0] = &Client::sendAvance;
      this->funcPtr[1] = &Client::sendTurnLeft;
      this->funcPtr[2] = &Client::sendTurnRight;
      this->funcPtr[3] = &Client::sendLook;
      this->funcPtr[4] = &Client::sendLookInventory;
      this->funcPtr[5] = &Client::sendPushPlayer;
      this->funcPtr[6] = &Client::sendIncantation;
      this->funcPtr[7] = &Client::sendFork;
      this->funcPtr[8] = &Client::sendConnectNb;
      
      this->funcStrPtr[0] = &Client::sendBroadcastText;
      this->funcStrPtr[1] = &Client::sendTakeObject;
      this->funcStrPtr[2] = &Client::sendPutObject;
      
      this->launcher(this->ipAddress, this->port);
    }
  catch (const std::exception &ex)
    {
      std::cerr << "Error : " << ex.what() << std::endl;
    }  
}

Client::~Client()
{
}

/*
**			The client connects itself on the server
**			if it can't, he throw an Exception
**			the parameter *char[] contains in order :
**			the team name, the server name, the port
*/

bool			Client::launcher(const std::string &ipAddress, int port)
{
  int			counter;
  bool			beginIsGood;

  beginIsGood = false;
  counter = 0;
  try
    {
      this->sock.connectionClient((char*)ipAddress.c_str(), port);
      while(42)
	{
	  if (this->actualAction != "")
	    {
	      std::cout << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=" << std::endl;
	      std::cout << "Message to send : " << this->actualAction << std::endl;
	      std::cout << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=" << std::endl;
	      this->sock.sendSomething(this->actualAction);
	      this->actualAction = "";
	    }
	  this->slct.launchClient(this->sock.getFd());
	  if(select(this->sock.getFd() + 1, this->slct.getReadFds(), NULL, NULL, NULL) != -1)
	    {
	      if (FD_ISSET(this->sock.getFd(), this->slct.getReadFds()))
		{
		  this->receivedAnswer = "";
		  if (this->reception(&counter, &beginIsGood) == false)
		    return (false);
		}
	      else if (FD_ISSET(0, this->slct.getReadFds()))
		{
		  this->receivedAnswer = "";
		  this->receivedAnswer = this->sock.rcvSomething(0);
		}
	    }
	}
    }
  catch (const std::exception &ex)
    {
      std::cerr << "Error : " << ex.what() << std::endl;
      return (false);
    }
  return (true);
}

bool			Client::reception(int *counter, bool *beginIsGood)
{  
  this->receivedAnswer = this->sock.rcvSomething(this->sock.getFd());

  std::list<std::string>::iterator		it;
  std::list<std::string>::iterator		endIt;

  it = this->receivedCommandsArray.begin();
  endIt = this->receivedCommandsArray.end();

  this->placeTheString(receivedAnswer);
  if (this->receivedCommandsArray.size() > 0
      && (static_cast<MyString>(*this->receivedCommandsArray.begin())).contains('\n')
      == true)
    {
      this->receivedAnswer = *this->receivedCommandsArray.begin();
      if (this->receivedAnswer == "elevation en cours\n")
	return (true);
      else if (this->receivedAnswer == "mort\n")
	return (false);
      if (*counter > -1 && *counter < 3 && *beginIsGood == false)
	*beginIsGood = this->checkInits(counter,
					static_cast<MyString&>(this->receivedAnswer));
      if (*counter >= 3)
	{
	  if (this->analyseCommand() == false)
	    return (false);
	}
      this->receivedCommandsArray.pop_front();
    }
  return (true);
}

void			Client::placeCommandsInTab(const MyString &strToUse)
{
  if ((const_cast<MyString&>(strToUse)).contains('\n') == true)
    {
      MyStringArray			strArray;
      MyStringArray::iterator	it;
      MyStringArray::iterator	endIt;

      (const_cast<MyString&>(strToUse)).StrWordTab('\n', &strArray);
      if (strArray.size() > 0)
	{
	  it = strArray.begin();
	  endIt = strArray.end();
	  while (it != endIt)
	    {
	      this->receivedCommandsArray.AddString(*it + '\n');
	      ++it;
	    }
	}
    }
}

void			Client::rearrangeList()
{
  std::list<std::string>::iterator	it;
  std::list<std::string>::iterator	it2;
  std::list<std::string>::iterator	endIt;

  it = this->receivedCommandsArray.begin();
  endIt = this->receivedCommandsArray.end();
  while (it != endIt)
    {
      if ((*it).find("niveau actuel") != std::string::npos
	  && this->isGoodElevationMention(*it) == false)
	{
	  if (it == this->receivedCommandsArray.begin())
	    {
	      *this->receivedCommandsArray.begin() = "elevation en cours\n" +
		*this->receivedCommandsArray.begin();
	    }
	  else
	    {
	      it2 = it;
	      --it2;
	      *it2 += *it;
	      it = this->receivedCommandsArray.erase(it);
	    }
	}
      ++it;
    }
}

bool			Client::isGoodElevationMention(const std::string &strToUse)
{
  if (strToUse.find("elevation en cours\nniveau actuel : ") == 0
      && strToUse.size() == 37)
    return (true);
  return (false);
}

void			Client::placeTheString(const MyString &strToUse)
{
  if (this->receivedCommandsArray.size() > 0 && this->isGoodElevationMention(strToUse) == true
      && (*this->receivedCommandsArray.begin()).find("elevation en cours\n") != std::string::npos)
    this->receivedCommandsArray.pop_front();
  if (this->receivedCommandsArray.size() == 0)
    this->placeCommandsInTab(strToUse);
  else
    {
      MyString		strToPut;
      MyStringArray	strArray;
      
      (const_cast<MyString&>(strToUse)).StrWordTab('\n', &strArray);
      if (strArray.size() > 0)
	{
	  strToPut = *this->receivedCommandsArray.GetStringAt(this->receivedCommandsArray.size()
							      - 1);
	  if ((const_cast<MyString&>(strToPut)).contains('\n') == true)
	    this->placeCommandsInTab(strToUse);
	  else
	    {
	      MyStringArray::iterator	it;
	      MyStringArray::iterator	endIt;
	      
	      it = strArray.begin();
	      endIt = strArray.end();
	      while (it != endIt)
		++it;
	      --it;
	      if (static_cast<MyString>(*it).contains('\n') == false)
		{
		  *it = *it + *strArray.GetStringAt(0);
		  strArray.pop_front();
		}
	      while (strArray.size() > 0)
		{
		  this->receivedCommandsArray.AddString(*strArray.begin());
		  strArray.pop_front();
		}
	    }
	}
    }
  this->rearrangeList();
}

bool			Client::checkInits(int *counter, MyString &buffer)
{
  if (*counter == 0)
    return (this->commandWelcome(counter, buffer));
  else if (*counter > 0)
    {
      if (*counter == 1)
	return (this->commandOne(counter, buffer));
      else if (*counter == 2)
	return (this->commandTwo(counter, buffer));
    }
  return (false);
}

bool			Client::commandWelcome(int *counter, MyString &buffer)
{
  if (buffer != "BIENVENUE\n")
    throw MyException("The first message is not BIENVENUE with an entry.");
  this->actualAction = this->player->getTeamName() + "\n";
  *counter = *counter + 1;
  return (false);
}

bool			Client::commandOne(int *counter, MyString &buffer)
{
  MyStringArray		strArray;
  int			tId;

  buffer.StrWordTab(' ', &strArray);
  if (strArray.size() != 1 && strArray.size() != 2)
    throw MyException ("The gived ID for the player is not valid.");
  if ((tId = NbMath::convertInt(*strArray.GetStringAt(0))) < 0)
    throw MyException ("The gived ID for the player is not valid.");
  this->player->getTrentonianActions()->getExternInteractions().setNbPlayer(tId);
  *counter = *counter + 1;
  if (strArray.size() != 1)
    {
      strArray.clear();
      buffer.StrWordTab('\n', &strArray);
      if (strArray.size() != 2)
	throw MyException ("Error in the process of begin messages.");	
      buffer.SetString(*strArray.GetStringAt(1));
      return (this->commandTwo(counter, buffer));
    }
  return (false);
}

bool			Client::commandTwo(int *counter, MyString &buffer)
{
  MyStringArray		strArray;
  int			tsX;
  int			tsY;
  
  buffer.StrWordTab(' ', &strArray);
  if (strArray.size() != 2)
    throw MyException ("The gived map sizes are not good.");
  if ((tsX = NbMath::convertInt(*strArray.GetStringAt(0))) < 0
      || (tsY = NbMath::convertInt(*strArray.GetStringAt(1))) < 0)
    throw MyException ("The gived map sizes are not good.");
  this->player->getTrentonianActions()->getMoveActions()->setMapSizeX(tsX);
  this->player->getTrentonianActions()->getMoveActions()->setMapSizeY(tsY);
  *counter = *counter + 1;
  return (true);
}

/*
**                      CHECKING
*/

bool                            Client::checkTeamName(const MyStringArray &arrayToCheck)
{
  MyStringArray::const_iterator it;

  it = arrayToCheck.begin();
  while (it != arrayToCheck.end())
    {
      if (*it == "-n")
        {
          ++it;
          if (it == arrayToCheck.end())
            return (false);
          this->player->setTeamName(*it);
          return (true);
        }
      ++it;
    }
  return (false);
}

bool				Client::checkPort(const MyStringArray &arrayToCheck)
{
  MyStringArray::const_iterator it;

  it = arrayToCheck.begin();
  while (it != arrayToCheck.end())
    {
      if (*it == "-p")
        {
          ++it;
          if (it == arrayToCheck.end())
            return (false);
          if ((this->port = NbMath::convertInt(*it)) < 0)
            return (false);
          return (true);
        }
      ++it;
    }
  return (false);
}

bool				Client::checkHostName(const MyStringArray &arrayToCheck)
{
  MyStringArray::const_iterator it;

  it = arrayToCheck.begin();
  while (it != arrayToCheck.end())
    {
      if (*it == "-h")
        {
          ++it;
          if (it == arrayToCheck.end())
            return (false);
          this->ipAddress = *it;
          return (true);
        }
      ++it;
    }
  return (true);
}

MyStringArray			Client::tfAvToMyStrArray(char **av)
{
  unsigned int          counter;
  MyStringArray         arrayToRet;

  counter = 0;
  arrayToRet.clear();
  if (av == NULL)
    return (arrayToRet);
  while (av[counter] != NULL)
    {
      arrayToRet.AddString(av[counter]);
      counter = counter + 1;
    }
  return (arrayToRet);
}

MyString			&Client::getCommand() const
{
  return (const_cast<MyString&>(this->actualAction));
}

void                    Client::setCommand(const std::string &commandToSet)
{
  this->actualAction = commandToSet;
}

bool                    Client::analyseCommand()
{
  TrentonianActionsNS::eSecondaryAction		secondaryActionToDo;
  std::string					answerToDo;

  std::cout << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=" << std::endl;
  std::cout << "Received Answer : " << this->receivedAnswer << std::endl;
  std::cout << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=" << std::endl;
  
  if (this->receivedAnswer.size() > 0)
    {
      if (this->player->actionToDo(this->receivedAnswer, answerToDo) == false)
	return (false);
      if (this->player->getTrentonianActions()->getSecondaryActionList().size() > 0)
	{
	  secondaryActionToDo = *this->player->getTrentonianActions()->getSecondaryActionList().begin();
	  if (secondaryActionToDo <= 8)
	    (this->*funcPtr[secondaryActionToDo])();
	  else if (secondaryActionToDo > 8 && secondaryActionToDo <= 11 && answerToDo != "")
	    (this->*funcStrPtr[secondaryActionToDo - 9])(answerToDo);
	}
    }
  return (true);
}

void                    Client::sendAvance()
{
  this->actualAction = "avance\n";
}

void                    Client::sendTurnRight()
{
  this->actualAction = "droite\n";
}

void                    Client::sendTurnLeft()
{
  this->actualAction = "gauche\n";
}

void                    Client::sendLook()
{
  this->actualAction = "voir\n";
}

void                    Client::sendLookInventory()
{
  this->actualAction = "inventaire\n";
}

void                    Client::sendPushPlayer()
{
  this->actualAction = "expulse\n";
}

void                    Client::sendIncantation()
{
  this->actualAction = "incantation\n";
}

void                    Client::sendFork()
{
  this->actualAction = "fork\n";
}

void                    Client::sendConnectNb()
{
  this->actualAction = "connect_nbr\n";
}

void                    Client::sendBroadcastText(const std::string &textToSend)
{
  this->actualAction = "broadcast " + textToSend + "\n";
}

void                    Client::sendTakeObject(const std::string &textToSend)
{
  this->actualAction = "prend " + textToSend + "\n";
}

void                    Client::sendPutObject(const std::string &textToSend)
{
  this->actualAction = "pose " + textToSend + "\n";
}
