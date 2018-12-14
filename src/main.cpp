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

void log(const char * s) {
  printf("%s\n", s);
}

int main()
{

  log("making root");

  //Root *root = new Root("plugins.cfg", "mygame.cfg", "mygame.log");
  Root *root = new Root("", "");
  //root->showConfigDialog();

  log("loading RenderSystem_GL");

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

  log("getting available renderers");
  Ogre::RenderSystemList renderSystems = root->getAvailableRenderers();
  Ogre::RenderSystemList::const_iterator r_it = renderSystems.begin();

  log("setting RendererSystem");
  root->setRenderSystem(*r_it);

  log("initializing OGRE");
  root->initialise(false);

  log("getting window");
  RenderWindow *window = root->getAutoCreatedWindow();

  log("creating scene manager");
  SceneManager *smgr = root->createSceneManager(ST_GENERIC, "SceneManager");

  log("creating camera");
  Camera *cam = smgr->createCamera("MainCamera");

  log("adding viewPort");
  Viewport *vp = window->addViewport(cam);
  vp->setBackgroundColour(ColourValue(0.3, 0.6, 0.9));

  log("startRendering");
  root->startRendering();

  return 0;
}

