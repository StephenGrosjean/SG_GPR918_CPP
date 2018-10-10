//
// Created by efarhan on 10.10.18.
//

#ifndef SAE918_VECTOR2D_H
#define SAE918_VECTOR2D_H

struct Vector2D {
    Vector2D(int x, int y) :x(x), y(y) {

    }
    Vector2D() {
      x = 0;
      y = 0;
    }
    int x;
    int y;
};

#endif //SAE918_VECTOR2D_H
