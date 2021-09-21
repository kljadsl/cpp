#define WIDTH 100
#define HEIGHT 100

#include"Terrain.h"

int random(int range) {
    //return a number in 0 ~ range
}

class World{
private:
    Terrain* tiles_[WIDTH][HEIGHT];
public:
    World() : 
    grassTerrain_(1, false, GRASS),
    hillTerrain_(3, false, HILL),
    riverTerrain_(2, true, RIVER)
    {}

    void generateTerrain(){
        for (int i = 0; i < WIDTH; ++i) {
            for (int j = 0; j < HEIGHT; ++j) {
                if (random(10) == 0) {
                    tiles_[i][j] = &hillTerrain_;
                }
                else {
                    tiles_[i][j] = &grassTerrain_;
                }
            }
        }
        int x = random(WIDTH);
        for (int y = 0; y < HEIGHT; ++y){
            tiles_[x][y] = &riverTerrain_;
        }
    }

    const Terrain& getTile(int x, int y) const {
        return *tiles_[x][y];
    }

private:
    Terrain grassTerrain_;
    Terrain hillTerrain_;
    Terrain riverTerrain_;
};