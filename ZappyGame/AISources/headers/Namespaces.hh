//
// Namespaces.hh for zappy in /home/ovoyan_s/rendu/PSU_2013_zappy/AISources
// 
// Made by ovoyan_s
// Login   <ovoyan_s@epitech.net>
// 
// Started on  Wed Jul  2 13:23:45 2014 ovoyan_s
// Last update Fri Jul 18 18:59:37 2014 ovoyan_s
//

#ifndef				NAMESPACES_HH_
# define			NAMESPACES_HH_

namespace                       RessourceNS
{
  enum                          ressourceType
    {
      food,
      linemate,
      deraumere,
      sibur,
      mendiane,
      phiras,
      thystame
    };
};

namespace                       MoveNS
{
  enum                          eDirection
    {
      Up,
      Right,
      Down,
      Left
    };
};

namespace                                               TrentonianActionsNS
{
  enum                                                  eState
    {
      criticalSurvival,
      groupWork
    };

  enum                                                  ePrimaryAction
    {
      searchRessource,
      searchTrentonian,
      searchEvolution,
      moveToTrentonian,
      manageArea,
      moveOfArea,
      askFood,
      askRessources,
      moveUp,
      moveRight,
      moveDown,
      moveLeft,
      evolve,
      putGoodCoordinates,
    };

  enum                                                  eSecondaryAction
    {
      advance,
      turnLeft,
      turnRight,
      look,
      lookInventory,
      pushPlayer,
      incantation,
      fork,
      connectNb,

      broadcastText,
      takeObject,
      putObject,
      endOfPrimaryAction,
      dead
    };
};

#endif				/*	NAMESPACES_HH_	*/
