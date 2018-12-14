#include <Ogre.h>
#include <OgreColourValue.h>

int main(int argc, char *argv[])
{
  // the root
  Ogre::Root *root = new Ogre::Root("", "");

  // load the rendersystem
  root->loadPlugin("/usr/lib64/OGRE/RenderSystem_GL");
  root->setRenderSystem(*(root->getAvailableRenderers().begin()));
  root->initialise(false);

  // the window
  Ogre::RenderWindow *window = root->createRenderWindow("Hello World!", 800, 600, false);
  window->setActive(true);
  window->setAutoUpdated(true);
  window->setDeactivateOnFocusChange(false);

  Ogre::SceneManager *sceneMgr = root->createSceneManager(Ogre::ST_GENERIC);

  // viewport and camera
  Ogre::Camera *camera = sceneMgr->createCamera("cam");
  Ogre::Viewport *viewport = window->addViewport(camera);
  viewport->setClearEveryFrame(true);
  viewport->setBackgroundColour(Ogre::ColourValue(0.3, 0.6, 0.9));

  // TODO: set-up your camera

  // TODO: set-up your resources

  // TODO: set-up your lighting


  // main loop
  while (true) {
    // TODO: do your game logic here

    Ogre::WindowEventUtilities::messagePump();

    if (!root->renderOneFrame())
      break;
  }

  // clean up
  delete root;

  // the end.
  return 0;
}

