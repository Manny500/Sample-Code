#include "Glossary.h"

/**
 * @brief Glossary::Glossary
 */
Glossary::Glossary(){

    this->componentTypes = new std::vector<Type*>;
    this->componentStackTypes = new std::vector<Type*>;
    this->locationTypes = new std::vector<Type*>;
    this->playerTypes = new std::vector<Type*>;
    this->playerGroupTypes = new std::vector<Type*>;
}

/**
 * @brief Glossary::~Glossary
 */
Glossary::~Glossary(){

    removeAllComponentTypes();
    removeAllComponentStackTypes();
    removeAllLocationTypes();
    removeAllPlayerTypes();
    removeAllPlayerGroupTypes();

    delete this->componentTypes;
    delete this->componentStackTypes;
    delete this->locationTypes;
    delete this->playerTypes;
    delete this->playerGroupTypes;

    this->componentTypes = NULL;
    this->componentStackTypes = NULL;
    this->locationTypes = NULL;
    this->playerTypes = NULL;
    this->playerGroupTypes = NULL;
}

/**
 * @brief Glossary::addComponentType
 * @param type
 */
void Glossary::addComponentType(Type* type){

    this->componentTypes->push_back(type);
}

/**
 * @brief Glossary::addComponentStackType
 * @param type
 */
void Glossary::addComponentStackType(Type* type){

    this->componentStackTypes->push_back(type);
}

/**
 * @brief Glossary::addLocationType
 * @param type
 */
void Glossary::addLocationType(Type* type){

    this->locationTypes->push_back(type);
}

/**
 * @brief Glossary::addPlayerType
 * @param type
 */
void Glossary::addPlayerType(Type* type){

    this->playerTypes->push_back(type);
}

/**
 * @brief Glossary::addPlayerGroupType
 * @param type
 */
void Glossary::addPlayerGroupType(Type* type){

    this->playerGroupTypes->push_back(type);
}

/**
 * @brief Glossary::getComponentType
 * @param label
 * @return
 */
Type* Glossary::getComponentType(int label){

    for (unsigned int i = 0; i < this->componentTypes->size(); i++){

        Type* tp = this->componentTypes->at(i);
        if (tp->getLabel() == label)
            return tp;
    }

    return NULL;
}

/**
 * @brief Glossary::getComponentType
 * @param name
 * @return
 */
Type* Glossary::getComponentType(std::string name){

    for (unsigned int i = 0; i < this->componentTypes->size(); i++){

        Type* tp = this->componentTypes->at(i);
        if (tp->getName() == name)
            return tp;
    }

    return NULL;
}

/**
 * @brief Glossary::getComponentStackType
 * @param label
 * @return
 */
Type* Glossary::getComponentStackType(int label){

    for (unsigned int i = 0; i < this->componentStackTypes->size(); i++){

        Type* tp = this->componentStackTypes->at(i);
        if (tp->getLabel() == label)
            return tp;
    }

    return NULL;
}

/**
 * @brief Glossary::getComponentStackType
 * @param name
 * @return
 */
Type* Glossary::getComponentStackType(std::string name){

    for (unsigned int i = 0; i < this->componentStackTypes->size(); i++){

        Type* tp = this->componentStackTypes->at(i);
        if (tp->getName() == name)
            return tp;
    }

    return NULL;
}

/**
 * @brief Glossary::getLocationType
 * @param label
 * @return
 */
Type* Glossary::getLocationType(int label){

    for (unsigned int i = 0; i < this->locationTypes->size(); i++){

        Type* tp = this->locationTypes->at(i);
        if (tp->getLabel() == label)
            return tp;
    }

    return NULL;
}

/**
 * @brief Glossary::getLocationType
 * @param name
 * @return
 */
Type* Glossary::getLocationType(std::string name){

    for (unsigned int i = 0; i < this->locationTypes->size(); i++){

        Type* tp = this->locationTypes->at(i);
        if (tp->getName() == name)
            return tp;
    }

    return NULL;
}

/**
 * @brief Glossary::getPlayerType
 * @param label
 * @return
 */
Type* Glossary::getPlayerType(int label){

    for (unsigned int i = 0; i < this->playerTypes->size(); i++){

        Type* tp = this->playerTypes->at(i);
        if (tp->getLabel() == label)
            return tp;
    }

    return NULL;
}

/**
 * @brief Glossary::getPlayerType
 * @param name
 * @return
 */
Type* Glossary::getPlayerType(std::string name){

    for (unsigned int i = 0; i < this->playerTypes->size(); i++){

        Type* tp = this->playerTypes->at(i);
        if (tp->getName() == name)
            return tp;
    }

    return NULL;
}

/**
 * @brief Glossary::getPlayerGroupType
 * @param label
 * @return
 */
Type* Glossary::getPlayerGroupType(int label){

    for (unsigned int i = 0; i < this->playerGroupTypes->size(); i++){

        Type* tp = this->playerGroupTypes->at(i);
        if (tp->getLabel() == label)
            return tp;
    }

    return NULL;
}

/**
 * @brief Glossary::getPlayerGroupType
 * @param name
 * @return
 */
Type* Glossary::getPlayerGroupType(std::string name){

    for (unsigned int i = 0; i < this->playerGroupTypes->size(); i++){

        Type* tp = this->playerGroupTypes->at(i);
        if (tp->getName() == name)
            return tp;
    }

    return NULL;
}

/**
 * @brief Glossary::removeAllComponentTypes
 */
void Glossary::removeAllComponentTypes(){

    for (unsigned int i = 0;  i < this->componentTypes->size(); i++)
        delete this->componentTypes->at(i);

    this->componentTypes->clear();
}

/**
 * @brief Glossary::removeAllComponentStackTypes
 */
void Glossary::removeAllComponentStackTypes(){

    for (unsigned int i = 0;  i < this->componentStackTypes->size(); i++)
        delete this->componentStackTypes->at(i);

    this->componentStackTypes->clear();
}

/**
 * @brief Glossary::removeAllLocationTypes
 */
void Glossary::removeAllLocationTypes(){

    for (unsigned int i = 0;  i < this->locationTypes->size(); i++)
        delete this->locationTypes->at(i);

    this->locationTypes->clear();
}

/**
 * @brief Glossary::removeAllPlayerTypes
 */
void Glossary::removeAllPlayerTypes(){

    for (unsigned int i = 0;  i < this->playerTypes->size(); i++)
        delete this->playerTypes->at(i);

    this->playerTypes->clear();
}

/**
 * @brief Glossary::removeAllPlayerGroupTypes
 */
void Glossary::removeAllPlayerGroupTypes(){

    for (unsigned int i = 0;  i < this->playerGroupTypes->size(); i++)
        delete this->playerGroupTypes->at(i);

    this->playerGroupTypes->clear();
}
