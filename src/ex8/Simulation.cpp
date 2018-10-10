//
// Created by efarhan on 10.10.18.
//

#include <ex8/Simulation.h>
#include <ex8/GameObject.h>

Simulation::Simulation(int seed) : random(seed) {

}

void Simulation::Init () {
  //Create 5 creatures
  for (int i = 0; i < 5; i++) {
      map.AddGameObjectAt(std::move(GameObjectBuilder::BuildCreature (*this)));
    }


  //Create 6 foods
  for (int i = 0; i < 6; i++) {
      map.AddGameObjectAt(std::move(GameObjectBuilder::BuildFood (*this)));
    }

}

void Simulation::Start () {
  while (IsEndSimulation ()) {
      Update ();
      map.DisplayMap();
    }
  std::cout << std::endl << "------ END OF SIMULATION -------------" << std::endl;
#ifdef WIN32
  system("Pause");
#endif
}


int Simulation::GetValueRandom(int min, int max) {
  std::uniform_int_distribution<int> distribution(min, max);
  int randomValue = distribution(random);
  return randomValue;
}

void Simulation::Update () {

  map.Update ();


}

bool Simulation::IsEndSimulation () {
  return map.CountCreaturesInMap () <= 0;
}