//
// Created by Jaime.JS on 1/10/2018.
//

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include "grafo2D.h"

#define TOTAL_ROUTES 20

struct location array[TOTAL_ROUTES];

struct location *createLocation(unsigned short id, float x, float y, char *name) {
    struct location *newLocation = malloc(sizeof(struct location));
    newLocation->name = malloc(sizeof(char) * strlen(name));
    newLocation->id = id;
    newLocation->pointLoc.x = x;
    newLocation->pointLoc.y = y;
    memcpy(newLocation->name, name, strlen(name));
    newLocation->routesLoc = NULL;
    return newLocation;
}

void printRoutes(struct route routes) {
    int i;
    printf("\t%6s\t%10s\n", "RUTAS", "DISTANCIAS");
    for (i = 0; i < routes.amount && i < routes.size; i++) {
        printf("\t%6hu\t%10.5lf\n", *(routes.routes + i), *(routes.distances + i));
    }
}

void printLocation(struct location *value) {
    printf("%6s\t%15s\t%10s\n", "ID", "NOMBRE", "COORDENADAS");
    printf("%6d\t%15s\t(%4.2f,%4.2f)\n", value->id, value->name, value->pointLoc.x, value->pointLoc.y);
    puts("\n\t\tTABLA DE RUTAS");
    printRoutes(*value->routesLoc);
}

void addRoute(struct location *origin, struct location *destination) {
    if (origin && destination) {
        increaseSizeRoutes(origin);
        increaseSizeRoutes(destination);
        if (!hasRoute(origin->routesLoc, destination->id)) {
            double distance = calcDistCartesian(origin->pointLoc, destination->pointLoc);
            int index = origin->routesLoc->amount;
            *(origin->routesLoc->routes + index) = destination->id;
            *(origin->routesLoc->distances + index) = distance;
            origin->routesLoc->amount++;
            index = destination->routesLoc->amount;
            *(destination->routesLoc->routes + index) = origin->id;
            *(destination->routesLoc->distances + index) = distance;
            destination->routesLoc->amount++;
        } else {
            printf("%s\n", ROUTE_ALREADY_EXIST);
        }
    } else {
        printf("%s\n", LOCATION_NO_EXISTENT);
    }
}

void increaseSizeRoutes(struct location *location) {
    if (!location->routesLoc) {
        location->routesLoc = malloc(sizeof(struct route));
        location->routesLoc->routes = (unsigned short *) malloc(sizeof(unsigned short) * AMOUNT_TO_INCREASE);
        location->routesLoc->distances = (double *) malloc(sizeof(double) * AMOUNT_TO_INCREASE);
        location->routesLoc->amount = 0;
        location->routesLoc->size = AMOUNT_TO_INCREASE;
    } else {
        if (location->routesLoc->amount == location->routesLoc->size) {
            struct route *temp = malloc(sizeof(location->routesLoc));
//            memcpy(temp, location->routesLoc, sizeof(struct route) * location->routesLoc->size);
            free(location->routesLoc);
            /*location->routesLoc = malloc(sizeof(struct route));
            location->routesLoc->routes = malloc(sizeof(unsigned short) *(location->routesLoc->size + AMOUNT_TO_INCREASE));
            location->routesLoc->distances = malloc(sizeof(double) *(location->routesLoc->size + AMOUNT_TO_INCREASE));
            memcpy(location->routesLoc, temp, sizeof(struct route) * location->routesLoc->size);*/
            realloc(location, location->routesLoc->size + AMOUNT_TO_INCREASE);
            location->routesLoc->size += AMOUNT_TO_INCREASE;
//            free(temp);
        }
    }
}

bool hasRoute(struct route *route, unsigned short id) {
    int i;
    for (i = 0; i < route->amount; i++) {
        if (id == *(route->routes + i)) {
            return true;
        }
    }
    return false;
}

double calcDistCartesian(struct point init, struct point final) {
    return sqrt(pow((final.x - init.x), 2) + pow((final.y - init.y), 2));
}
