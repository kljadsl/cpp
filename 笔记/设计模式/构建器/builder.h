#include<iostream>
using namespace std;

class House{

};

class HouseBuilder{
public:
    House* getResult() {
        return pHouse;
    }
    virtual void BuildWall() = 0;
    virtual void BuildWindow() = 0;
    virtual void BuildRoof() = 0;
    virtual ~HouseBuilder(){}
protected:
    House* pHouse;
};

class StoneHouse : public House{

};

class StoneHouseBuilder : public HouseBuilder{
public:
    virtual void BuildWall() {
        cout << "Creating stone walls." << endl;
    }

    virtual void BuildWindow() {
        cout << "Creating stone windows." << endl;
    }

    virtual void BuildRoof() {
        cout << "Creating stone roof." << endl;
    }
};//变化的部分

class HouseDirector{
public:
    HouseBuilder* pHouseBuilder;

    HouseDirector(HouseBuilder* p) : pHouseBuilder(p){}

    House* Construct() {
        pHouseBuilder->BuildWall();
        pHouseBuilder->BuildWindow();
        pHouseBuilder->BuildRoof();
        return pHouseBuilder->getResult();
    }
};//稳定的部分