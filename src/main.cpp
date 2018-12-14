#include <Ogre.h>
#include <stdio.h>
using namespace Ogre;

//#if defined(_DEBUG)
//    ogre->loadPlugin("Plugin_CgProgramManager_d");
//    ogre->loadPlugin("Plugin_OctreeSceneManager_d");
//#else
//    ogre->loadPlugin("Plugin_CgProgramManager");
//    ogre->loadPlugin("Plugin_OctreeSceneManager");
//#endif


int main()
{
    //Root *root = new Root("plugins.cfg", "mygame.cfg", "mygame.log");
    Root *root = new Root("", "");
    //root->showConfigDialog();

    try {
      root->loadPlugin("/usr/lib64/OGRE/RenderSystem_GL");
    }
    catch(Exception& e) {
      LogManager::getSingleton().logMessage(String("Unable to create OpenGL RenderSystem: ") + e.getFullDescription());
    }

    //try {
    //  root->loadPlugin("/usr/lib64/OGRE/Plugin_CgProgramManager");
    //}
    //catch(Exception& e) {
    //  LogManager::getSingleton().logMessage(String("Unable to create CG Program manager RenderSystem: ") + e.getFullDescription());
    //}

    Ogre::RenderSystemList renderSystems = root->getAvailableRenderers();
    Ogre::RenderSystemList::const_iterator r_it = renderSystems.begin();
    root->setRenderSystem(*r_it);

    root->initialise(false);
    RenderWindow *window = root->getAutoCreatedWindow();

    SceneManager *smgr = root->createSceneManager(ST_GENERIC, "SceneManager");

    Camera *cam = smgr->createCamera("MainCamera");

    Viewport *vp = window->addViewport(cam);
    vp->setBackgroundColour(ColourValue(0.3, 0.6, 0.9));

    root->startRendering();

    return 0;
}

