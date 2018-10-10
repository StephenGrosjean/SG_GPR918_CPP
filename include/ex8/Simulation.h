//
// Created by efarhan on 10.10.18.
//

#ifndef SAE918_SIMULATION_H
#define SAE918_SIMULATION_H

#include <random>
#include <iostream>

#include <ex8/Map.h>

class Simulation {
 public:

  Map map;



  Simulation(int seed);

  void Init ();
  void Start ();

  int GetValueRandom (int min, int max);




 private:

  int nbrCreatures;
  int nbrHunters;
  int nbrFoodStuff;

  std::default_random_engine random;



  void Update ();
  bool IsEndSimulation ();


};

#endif //SAE918_SIMULATION_H
