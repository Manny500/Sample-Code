#ifndef GLOSSARY
#define GLOSSARY

// Properties
#include "Type.h"


/**
 * @brief The Glossary class
 */
class Glossary: public Accessible{


public:

    std::vector<Type*>* componentTypes;
    std::vector<Type*>* componentStackTypes;
    std::vector<Type*>* locationTypes;
    std::vector<Type*>* playerTypes;
    std::vector<Type*>* playerGroupTypes;

    Glossary();
    ~Glossary();

    void addComponentType(Type* type);
    void addComponentStackType(Type* type);
    void addLocationType(Type* type);
    void addPlayerType(Type* type);
    void addPlayerGroupType(Type* type);

    Type* getComponentType(int label);
    Type* getComponentType(std::string name);
    Type* getComponentStackType(int label);
    Type* getComponentStackType(std::string name);
    Type* getLocationType(int label);
    Type* getLocationType(std::string name);
    Type* getPlayerType(int label);
    Type* getPlayerType(std::string name);
    Type* getPlayerGroupType(int label);
    Type* getPlayerGroupType(std::string name);

    void removeAllComponentTypes();
    void removeAllComponentStackTypes();
    void removeAllLocationTypes();
    void removeAllPlayerTypes();
    void removeAllPlayerGroupTypes();


};

#endif // GLOSSARY

