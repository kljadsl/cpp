class Breed{
public:
    Monster* newMonster() { 
        //可以做内存分配
        return new Monster(*this); 
    }

    Breed(int health, const char* attack) : health_(health), attack_(attack) {}
    
    int getHealth() { return health_; }
    const char* getAttack() { return attack_; }
private:
    int health_;
    const char* attack_;
};

class Monster{
    friend Breed;
public:
    Monster(Breed& breed) : health_(breed.getHealth()), breed_(breed) {}

    const char* getAttack() {
        return breed_.getAttack();
    }
private:
    int health_;
    Breed& breed_;
};