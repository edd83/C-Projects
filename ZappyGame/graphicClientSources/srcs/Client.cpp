//
// client.cpp for client in /home/lardet_e/rendu/cpp_plazza/lardet_e/server
// 
// Made by lardet
// Login   <lardet_e@epitech.net>
// 
// Started on  Thu Apr 17 14:28:05 2014 lardet
// Last update Sun Jul 20 17:43:23 2014 volpe
//

/*
**			MY INCLUDES
*/

#include		"../headers/Client.hh"

Client::Client()
{

}

Client::Client(char **av)
{
  MyStringArray		strArray;

  this->port = 0;
  //  this->ipAddress = "37.187.74.159";
  //   this->ipAddress = "127.0.0.1";
  this->ipAddress = av[2];
  strArray.clear();
  strArray = this->tfAvToMyStrArray(av);
  if (this->checkPort(strArray) == false ||
      this->checkHostName(strArray) == false)
    throw MyException("Error in arguments of the client");
  this->counter = 0;
  this->game = new GraphClient;
  this->parser = new Parsing;
  this->launcher(this->ipAddress, this->port);
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

void			Client::sendTimeUnit(int timeUnit)
{
  std::stringstream strstm;
  
  strstm.clear();
  strstm << "sst " << timeUnit << "\n";
  
  this->sock.sendSomething(strstm.str());
}

bool			Client::update()
{
  if (this->actualAction != "")
    {
      this->sock.sendSomething(this->actualAction);
      std::cout << "Message to Send : " << this->actualAction << std::endl;
      this->actualAction = "";
    }
  this->slct.launchClient(this->sock.getFd());
  if(select(this->sock.getFd() + 1, this->slct.getReadFds(), NULL, NULL, NULL) != -1)
    {
      if (FD_ISSET(this->sock.getFd(), this->slct.getReadFds()))
	{
	  this->receivedAnswer = "";
	  if (this->reception(&this->counter) == false)
	    return (false);
	}
      else if (FD_ISSET(0, this->slct.getReadFds()))
	{
	  this->receivedAnswer = "";
	  this->receivedAnswer = this->sock.rcvSomething(0);
	}
    }
  return (true);
}

bool			Client::launcher(const std::string &ipAddress, int port)
{
  this->actualAction = "";
  try
    {
      this->sock.connectionClient((char*)ipAddress.c_str(), port);
      while(42)
	{
	  if (!this->update())
	    return (false);
	}
    }
  catch (std::exception &ex)
    {
      std::cerr << "Error : " << ex.what() << std::endl;
      return (false);
    }
  return (true);
}

bool			Client::reception(int *counter)
{
  this->receivedAnswer = this->sock.rcvSomething(this->sock.getFd());
  std::cout << "Received Answer : " << this->receivedAnswer << std::endl;
  this->placeTheString(receivedAnswer);
  if (this->receivedCommandsArray.size() > 0
      && (static_cast<MyString>(*this->receivedCommandsArray.begin())).contains('\n')
      == true)
    {
      if (*counter == 0)
	{
	  this->receivedCommandsArray.pop_front();
	  return (this->checkInits(counter, this->receivedAnswer));
	}
      else
	{
	  while (this->receivedCommandsArray.size() > 0
		 && static_cast<MyString>(*this->receivedCommandsArray.begin()).contains('\n') == true)
	    {
	      this->receivedAnswer = *this->receivedCommandsArray.begin();
	      this->receivedCommandsArray.pop_front();
	      //	      std::cout << "Received Answer : " << this->receivedAnswer << std::endl;
	      this->parser->execute(this->receivedAnswer, *game);
	    }
	  if (isFirstTime == true)
	    {
	      this->isFirstTime = false;
	      if (this->game == NULL)
		std::cout << "NULL 1" << std::endl;
	      this->game->start(*this);
	    }
	}
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
	      *this->receivedCommandsArray.begin() = "Elevation en cours\n" +
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
  if (strToUse.find("Elevation en cours\nniveau actuel : ") == 0
      && strToUse.size() == 35)
    return (true);
  return (false);
}

void			Client::placeTheString(const MyString &strToUse)
{
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
  //  this->rearrangeList();
}

bool			Client::checkInits(int *counter, MyString &buffer)
{
  if (*counter == 0)
    return (this->commandWelcome(counter, buffer));
  return (false);
}

bool			Client::commandWelcome(int *counter, MyString &buffer)
{
  if (buffer != "BIENVENUE\n")
    throw MyException("The first message is not BIENVENUE with an entry.");
  this->actualAction = "GRAPHIC\n";
  *counter = *counter + 1;
  return (true);
}

/*
**                      CHECKING
*/

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
