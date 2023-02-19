#include "Objects.h"
#include <iostream>

void setGameObject(int row, int col, Objects Objects) {
    board[row][col] = static_cast<char>(Objects);
}

GameObject getGameObject(int row, int col) {
    return static_cast<GameObject>(board[row][col]);
}
 
void addAlienAttack(int attack) {
    alien_attack += attack;
}

int getAlienAttack() {
    return alien_attack;
}

void addAlienLife(int life) {
    alien_life += life;
}

void reduceAlienLife(int damage) {
    alien_life -= damage;
}

int getAlienLife() {
    return alien_life;
}

void handleCollision(int row, int col) {
    GameObject gameObject = getGameObject(row, col);

    switch (gameObject) {
        case ARROW_UP:
            // change Alien's direction of movement to up
            break;
        case ARROW_DOWN:
            // change Alien's direction of movement to down
            break;
        case ARROW_LEFT:
            // change Alien's direction of movement to left
            break;
        case ARROW_RIGHT:
            // change Alien's direction of movement to right
            break;
        case HEALTH:
            addAlienLife(20);
            break;
        case POD:
            // inflict 10 damage to any zombie on the board
            break;
        case ROCK:
            // reveal the hidden game object underneath the rock and stop Alien from moving
            break;
        case EMPTY_SPACE:
            // do nothing
            break;
        case TRAIL:
            // reset to a random game object (except Trail) and apply its effects on Alien
            break;
        default:
            break;
    }
}