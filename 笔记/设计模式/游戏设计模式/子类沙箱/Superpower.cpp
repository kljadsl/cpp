class Superpower{
public:
    virtual ~Superpower() {}

protected:
    virtual void activate() = 0;

    void move(double x, double y, double z) {
        //...
    }

    void playSound(SoundId sound, double volume) {
        //...
    }

    void spawnParticles(ParticleType type, int count) {
        //...
    }

    double getHeroX() {
        //...
    }

    double getHeroY() {
        //...
    }

    double getHeroZ() {
        //...
    }
};

class SkyLaunch : public Superpower{
protected:
    virtual void activate() {
        if (getHeroX() == 0){
            playSound(SOUND_SPROING, 1.0f);
            spawnParticles(PARTICLES_DUST, 10);
            move(0, 0,  20);
        }
        else if(getHeroX < 10.0f) {
            playSound(SOUND_SWOOP, 1.0f);
            move(0, 0, getHeroX() + 20);
        }
        else {
            playSound(SOUND_DIVE, 0.7f);
            spawnParticles(PARTICLES_SPAEKLES, 1);
            move(0, 0, -getHeroX());
        }
    }
};