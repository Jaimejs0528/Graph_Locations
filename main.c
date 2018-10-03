#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include <wchar.h>

#include "Library/grafo2D.h"

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Spanish");
    struct location *r = createLocation(1, 2, 5, "Londres");
    struct location *t = createLocation(2, 1, 4, "Los angeles");
    struct location *ts = createLocation(3, 21, 4, "Los angeles");
    addRoute(r, t);
    addRoute(r, ts);
    printLocation(r);
    printLocation(t);
    printLocation(ts);
    FILE* open;
    open = fopen("../hola.txt","w");
    fprintf(open,"%6s\t%15s\t%10s\n", "ID", "NOMBRE", "COORDENADAS");
    fprintf(open,"%6d\t%15s\t(%4.2f,%4.2f)\n", r->id, r->name, r->pointLoc.x, r->pointLoc.y);
    fclose(open);
    addLocation();
    return 0;
}