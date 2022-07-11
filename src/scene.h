#ifndef SCENE_H
#define SCENE_H
#include "Square.h"

class Scene
{
private:

    Scene(const Scene& TimeScene);
    Scene& operator=(const Scene& TimeScene);

    Scene (Scene&& TimeScene);
    Scene& operator=(Scene&& TimeScene);

public:
    Scene();
    int xmaxscene=5, ymaxscene=5;
    Square** a;
   static Scene* getInstance();
    ~Scene();
    void delete_elements();
    void GenerateRandomLandscapeOfScene();
    void initScene();



    
};

#endif // SCENE_H
