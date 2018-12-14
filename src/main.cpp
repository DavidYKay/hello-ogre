#include <Ogre.h>
using namespace Ogre;

void loadRenderSystems() {
  Root* ogreRoot = Root::getSingletonPtr();

  try {
    ogreRoot->loadPlugin("RenderSystem_GL");
  }
  catch(Exception& e) {
    LogManager::getSingleton().logMessage(String("Unable to create OpenGL RenderSystem: ") + e.getFullDescription());
  }

//#if defined(_DEBUG)
//    ogre->loadPlugin("Plugin_CgProgramManager_d");
//    ogre->loadPlugin("Plugin_OctreeSceneManager_d");
//#else
//    ogre->loadPlugin("Plugin_CgProgramManager");
//    ogre->loadPlugin("Plugin_OctreeSceneManager");
//#endif

  try {
    ogreRoot->loadPlugin("Plugin_CgProgramManager");
  }
  catch(Exception& e) {
    LogManager::getSingleton().logMessage(String("Unable to create CG Program manager RenderSystem: ") + e.getFullDescription());
  }

  Ogre::RenderSystemList renderSystems = ogreRoot->getAvailableRenderers();
  Ogre::RenderSystemList::const_iterator r_it = renderSystems.begin();
  ogreRoot->setRenderSystem(*r_it);
}
//'const RenderSystemList  {aka const std::vector<Ogre::RenderSystem*, Ogre::STLAllocator<Ogre::RenderSystem*, Ogre::CategorisedAllocPolicy<(Ogre::MemoryCategory)0> > >}'
//'Ogre::RenderSystemList* {aka       std::vector<Ogre::RenderSystem*, Ogre::STLAllocator<Ogre::RenderSystem*, Ogre::CategorisedAllocPolicy<(Ogre::MemoryCategory)0> > >*}'
//in assignment

int main()
{
    Root *root = new Root("plugins.cfg", "mygame.cfg", "mygame.log");
    //root->showConfigDialog();

    loadRenderSystems();

    root->initialise(true, "My Game");
    RenderWindow *window = root->getAutoCreatedWindow();

    SceneManager *smgr = root->createSceneManager(ST_GENERIC, "SceneManager");

    Camera *cam = smgr->createCamera("MainCamera");

    Viewport *vp = window->addViewport(cam);
    vp->setBackgroundColour(ColourValue(0.3, 0.6, 0.9));

    root->startRendering();

    return 0;
}

