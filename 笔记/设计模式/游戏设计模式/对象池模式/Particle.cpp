class Particle{
public:
    Particle() : framesLeft_(0) {}

    void init(double x, double y, double xVel, double yVel, int lifetime) {
        state_.live.x_ = x;
        state_.live.y_ = y;
        state_.live.xVel_ = xVel;
        state_.live.yVel_ = yVel;
        framesLeft_ = lifetime;
    }

    bool animate() {
        if (!inUse()) return false;

        framesLeft_--;
        state_.live.x_ += state_.live.xVel_;
        state_.live.y_ += state_.live.yVel_;

        return framesLeft_ == 0;
    }

    bool inUse() const { return framesLeft_ > 0; }

    Particle* getNext() const { return state_.next; }
    void setNext(Particle* next) ( state_.next = next; )
private:
    int framesLeft_;

    union
    {   
        //using state
        struct
        {
            double x_, y_;
            double xVel_, yVel_;
        }live;    

        //can be reused state
        Particle* next;
    }state_;
};

class ParticlePool{
public:
    void create(double x, double y, double xVel, double yVel, int lifetime);

    void animate() {
        for (int i = 0; i < POOL_SIZE; ++i) {
            if (particles_[i].animate()) {
                particles_[i].setNext(firstAvailable_);
                firstAvailable_ = &particles_[i];
            }
        }
    }
private:
    static const int POOL_SIZE = 100;
    Particle particles_[POOL_SIZE];
    Particle* firstAvailable_;
};

ParticlePool::ParticlePool() {
    firstAvailable_ = &particles_[0];

    for (int i = 0; i < POOL_SIZE - 1; ++i) {
        particles_[i].setNext(&particles_[i + 1]);
    }
    particles_[POOL_SIZE - 1].setNext(NULL);
}

ParticlePool::create(double x, double y, double xVel, double yVel, int lifetime) {
    assert(firstAvailable_ != NULL);

    Particle* newParticle = firstAvailable_;
    firstAvailable_ = firstAvailable_->getNext();

    newParticle->init(x, y, xVel, yVel, lifetime);
}