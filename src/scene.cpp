#include "scene.h"

Scene::Scene()
{

}

void Scene::initScene()
{

    Scene::a=new Square*[xmaxscene];
    for(int x=0; x<xmaxscene; x++)
        Scene::a[x] = new Square[ymaxscene];

}

Scene::Scene(const Scene &TimeScene){
    xmaxscene = TimeScene.xmaxscene;
    ymaxscene = TimeScene.ymaxscene;
    a = new Square* [xmaxscene];
    for (int x = 0; x < xmaxscene; x++) {
        a[x] = new Square[ymaxscene];
    }
    int x=-1,y=-1;
    while(++x<xmaxscene)
        while(++y<ymaxscene)
        {
            if(TimeScene.a[x][y].type == 2) a[x][y].type=2;
            if(TimeScene.a[x][y].type == 3) a[x][y].type=3;
            a[x][y] = TimeScene.a[x][y];
        }

}

Scene& Scene::operator= (const Scene &TimeScene){
    if(this != &TimeScene) {
        Square** an = new Square *[xmaxscene];
        for (int i = 0; i < TimeScene.xmaxscene; i++) {
            an[i] = new Square[ymaxscene];
        }
        int x=-1,y=-1;
        while(++x<xmaxscene) delete a[x];
        delete a;
        a = an;
        ymaxscene = TimeScene.ymaxscene; xmaxscene = TimeScene.xmaxscene;
        x=-1;
        while(++x<xmaxscene)
            while(++y<ymaxscene)
            {
                if(TimeScene.a[x][y].type == 2) a[x][y].type=2;
                if(TimeScene.a[x][y].type == 3) a[x][y].type=3;
                a[x][y] = TimeScene.a[x][y];
            }
    }
    return *this;
}

Scene::Scene (Scene&& TimeScene){
    ymaxscene = TimeScene.ymaxscene; xmaxscene = TimeScene.xmaxscene;
    a = TimeScene.a;
    TimeScene.a = nullptr;
}

Scene& Scene::operator=(Scene&& TimeScene){
    if (&TimeScene == this)
        return *this;
    int x=-1;
    while(++x<xmaxscene) delete a[x];
    delete a;
    xmaxscene = TimeScene.xmaxscene; ymaxscene = TimeScene.ymaxscene;
    a = TimeScene.a;
    TimeScene.a = nullptr;
    return *this;
}

void Scene::GenerateRandomLandscapeOfScene()
{
    int x=0,y=0, random;
    srand( time(0) );

   for(int i=0; i<2; i++)
   {
    x=0,y=0;
    while((x>=0)&&(y>=0)&&(x<xmaxscene-1)&&(y<ymaxscene-1))
    {
          random=rand()%2+0;
          switch(random)
          {
          case 0:
              if(x<xmaxscene-1) { Scene::a[x][y].SetSquare(1, standard, 0); x++; }
          case 1:
              if(y<ymaxscene-1) { Scene::a[x][y].SetSquare(1, standard, 0); y++; }
          }
    }
    Scene::a[2][1].SetSquare(1, standard, 0);
    Scene::a[0][1].SetSquare(1, standard, 0);
    }



    Scene::a[0][0].SetSquare(1, entry, 2);
    Scene::a[x-1][y-1].SetSquare(1, exite, 3);


}





Scene* Scene::getInstance()
{
    static Scene instance;
            return &instance;

}


void Scene::delete_elements()
{
    for(int x = 0;x<xmaxscene;x++) {
                delete a[x];
            }
            delete[] a;

}
Scene::~Scene(){
    for(int x = 0;x<xmaxscene;x++) {
                delete a[x];
            }
            delete[] a;
}
