class Monster{
public:
    virtual ~Monster() {}
    virtual Monster* clone() = 0;
};

class Ghost : public Monster{
public:
    Ghost(int health, int speed) : health_(health), speed_(speed) {}

    virtual Monster* clone(){
        return new Ghost(health_, speed_);
    }
private:
    int health_;
    int speed_;
};

class Spawner{
public:
    Spawner(Monster* prototype) : prototype_(prototype) {}

    Monster* spwanMonster() {
        return prototype_->clone();
    }
private:
    Monster* prototype_;
};