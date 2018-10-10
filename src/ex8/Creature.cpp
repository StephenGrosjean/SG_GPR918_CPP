//
// Created by efarhan on 10.10.18.
//

#include <ex8/Creature.h>
#include <ex8/Simulation.h>

Creature::Creature(Simulation * simulation, int hungerSpeedIncrement) : GameObject(simulation), hungerSpeedIncrement(hungerSpeedIncrement) {
    hungerPercent = 0;
}

void Creature::Update () {
  if (isDestroyed) {
      return;
  }
  RandomMove ();
  IncrementHunger ();
  if (hungerPercent >= 100){
    Die ();
    return;
  }
  Vector2D foodPosition = FindNearbyFoodPosition ();
  if (abs(foodPosition.x - position.x) <= 1 && abs(foodPosition.y - position.y) <= 1) {

      auto* gameObject = simulation->map.GetContentAtPosition (foodPosition);
      if (gameObject != nullptr && !gameObject->IsObjectDestroyed ()) {
          gameObject->Destroy ();
          hungerPercent = 0;
        }
  }

  //TODO Implement reproduction method

}

Vector2D Creature::FindNearbyFoodPosition () {
  Vector2D positionCentral = position;
  for (int x = positionCentral.x - 1; x < positionCentral.x + 3; x++) {
      if (x < 0 || x >= MAP_SIZE) {
          continue;
        }
      for (int y = positionCentral.y; y < positionCentral.y + 3; y++) {
          if (y < 0 || y >= MAP_SIZE) {
              continue;
            }
          Vector2D currentPosition(x, y);
          if (simulation->map.GameObjectOfTypeExistAt<Food> (currentPosition)) {

              return currentPosition;
            }
        }
    }

  return Vector2D(-1, -1);
}

void Creature::RandomMove () {
  int positionXMin = position.x - 1;
  if (positionXMin < 0)
    positionXMin = 0;
  int positionXMax = position.x + 1;
  if (positionXMax >= MAP_SIZE)
    positionXMax = MAP_SIZE - 1;

  int positionYMin = position.y - 1;
  if (positionYMin < 0)
    positionYMin = 0;
  int positionYMax = position.y + 1;
  if (positionYMax >= MAP_SIZE)
    positionYMax = MAP_SIZE - 1;
  int newX = simulation->GetValueRandom(positionXMin, positionXMax);
  int newY = simulation->GetValueRandom(positionYMin, positionYMax);
  simulation->map.MoveGameObjetTo(*this, newX, newY);
}

void Creature::Die () {

  isDestroyed = true;
}

void Creature::IncrementHunger () {
  hungerPercent += hungerSpeedIncrement;
}
void Creature::Start ()
{

}
