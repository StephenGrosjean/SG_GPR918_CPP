//
// Created by efarhan on 10.10.18.
//

#ifndef SAE918_CREATURE_H
#define SAE918_CREATURE_H

#include <ex8/GameObject.h>


class Creature : public GameObject
{
 public:

  Creature(Simulation * simulation, int hungerSpeedIncrement);



  void Start () override;
  void Update () override;
  char GetImage () {
    return 'C';
  }


 private:

  int hungerPourcent;
  int hungerSpeedIncrement;

  //Return position. If food is not find, we return the value (-1,-1)
  Vector2D FindNearbyFoodPosition () ;

  //Return position. If creature is not find, we return the value (-1,-1)
  Vector2D FindNearbyCreaturePosition () {

  }



  void RandomMove () ;
  void Die ();

  void IncrementHunger ();


};

#endif //SAE918_CREATURE_H
