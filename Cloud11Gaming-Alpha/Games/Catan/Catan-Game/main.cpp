#include <iostream>

#include "Catan.h"

int main()
{
    Catan* c = new Catan();
    c->staticSettings();
    c->startProgress();
    c->buildGlossary();
    c->setActualPlayers(4);
    c->buildGlossary();
    c->buildPlayerGroups();
    c->buildComponentStacks();
    c->buildPhysicalSpaces();
    c->startGame();
    c->refreshStats();

    c->affordable(3);



    delete c;

}

