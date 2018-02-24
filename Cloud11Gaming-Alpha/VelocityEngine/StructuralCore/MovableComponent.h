#ifndef MOVABLECOMPONENT_H
#define MOVABLECOMPONENT_H

//Project
#include "LocatableComponent.h"


/**
 * @brief The MovableComponent class
 */
class MovableComponent : public LocatableComponent{


protected:

    Coordinates* nextCoordinates;
    std::vector<Coordinates*>* historyCoordinates;


public:

    MovableComponent();
    MovableComponent(ID* id);
    MovableComponent(unsigned int serialID);
    MovableComponent(unsigned int serialID, int assignedID);
    MovableComponent(Type* type);
    MovableComponent(ID* id, Type* type);
    MovableComponent(unsigned int serialID, int assignedID, Type* type);
    ~MovableComponent();

    void setNextCoordinates(Coordinates* nextCoordinates);
    void setAllHistoryCoordinates(std::vector<Coordinates*>* historyCoordinates);
    void addRecentCoordinates(Coordinates* coordinates);

    Coordinates* getNextCoordinates();
    unsigned int getHistoryCoordinatesCount();
    std::vector<Coordinates*>* getAllHistoryCoordinates();
    Coordinates* getRecentCoordinates(unsigned int stepsBack);
    std::vector<Coordinates*>* getRecentCoordinatesBetween(unsigned int stepsBack, unsigned int moreStepsBack);

    void removeRecentCoordinatesBetween(unsigned int stepsBack, unsigned int moreStepsBack);
    void removeAllHistoryCoordinates();


};

#endif // MOVABLECOMPONENT_H
