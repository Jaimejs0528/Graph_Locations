//
// Created by Jaime.JS on 1/10/2018.
//

#ifndef GRAFO_GRAFO2D_H
#define GRAFO_GRAFO2D_H

#include <stdbool.h>
#include "Message/errorMessage.h"

#define AMOUNT_TO_INCREASE 15

struct route {
    unsigned short *routes;
    double *distances;
    unsigned short amount;
    unsigned short size;
};

struct point {
    float x;
    float y;
};

struct location {
    unsigned short id;
    struct point pointLoc;
    char *name;
    struct route *routesLoc;
};

struct location *createLocation(unsigned short id, float x, float y, char *name);

void addLocation();

void addRoute(struct location *origin, struct location *destination);

void increaseSizeRoutes(struct location *location);

bool hasRoute(struct route *route, unsigned short id);

void printLocation(struct location *value);

void printRoutes(struct route *routes);

double calcDistCartesian(struct point init, struct point final);

#endif //GRAFO_GRAFO2D_H
