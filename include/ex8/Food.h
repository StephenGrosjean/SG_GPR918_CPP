//
// Created by efarhan on 10.10.18.
//

#ifndef SAE918_FOOD_H
#define SAE918_FOOD_H

#include <ex8/GameObject.h>

class Food : public GameObject {
 public:
  Food(Simulation * simulation);

  void Start () override;
  void Update() override;

  char GetImage ();

};

#endif //SAE918_FOOD_H
