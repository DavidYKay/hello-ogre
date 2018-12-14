#include <Ogre.h>
#include <OgreColourValue.h>

ManualObject* createCubeMesh(Ogre::String name, Ogre::String matName) {
  ManualObject* cube = new ManualObject(name);
  cube->begin(matName);

   cube-> position( 0.5,-0.5,1.0);  cube-> normal(0.408248,-0.816497,0.408248);   cube-> textureCoord(1,0);
   cube-> position(-0.5,-0.5,0.0); cube-> normal(-0.408248,-0.816497,-0.408248); cube-> textureCoord(0,1);
   cube-> position( 0.5,-0.5,0.0);  cube-> normal(0.666667,-0.333333,-0.666667);  cube-> textureCoord(1,1);
   cube-> position(-0.5,-0.5,1.0); cube-> normal(-0.666667,-0.333333,0.666667);  cube-> textureCoord(0,0);
   cube-> position( 0.5,0.5,1.0);   cube-> normal(0.666667,0.333333,0.666667);    cube-> textureCoord(1,0);
   cube-> position(-0.5,-0.5,1.0); cube-> normal(-0.666667,-0.333333,0.666667);  cube-> textureCoord(0,1);
   cube-> position( 0.5,-0.5,1.0);  cube-> normal(0.408248,-0.816497,0.408248);   cube-> textureCoord(1,1);
   cube-> position(-0.5,0.5,1.0);  cube-> normal(-0.408248,0.816497,0.408248);   cube-> textureCoord(0,0);
   cube-> position(-0.5,0.5,0.0);  cube-> normal(-0.666667,0.333333,-0.666667);  cube-> textureCoord(0,1);
   cube-> position(-0.5,-0.5,0.0); cube-> normal(-0.408248,-0.816497,-0.408248); cube-> textureCoord(1,1);
   cube-> position(-0.5,-0.5,1.0); cube-> normal(-0.666667,-0.333333,0.666667);  cube-> textureCoord(1,0);
   cube-> position( 0.5,-0.5,0.0);  cube-> normal(0.666667,-0.333333,-0.666667);  cube-> textureCoord(0,1);
   cube-> position( 0.5,0.5,0.0);   cube-> normal(0.408248,0.816497,-0.408248);   cube-> textureCoord(1,1);
   cube-> position( 0.5,-0.5,1.0);  cube-> normal(0.408248,-0.816497,0.408248);   cube-> textureCoord(0,0);
   cube-> position( 0.5,-0.5,0.0);  cube-> normal(0.666667,-0.333333,-0.666667);  cube-> textureCoord(1,0);
   cube-> position(-0.5,-0.5,0.0); cube-> normal(-0.408248,-0.816497,-0.408248); cube-> textureCoord(0,0);
   cube-> position(-0.5,0.5,1.0);  cube-> normal(-0.408248,0.816497,0.408248);   cube-> textureCoord(1,0);
   cube-> position( 0.5,0.5,0.0);   cube-> normal(0.408248,0.816497,-0.408248);   cube-> textureCoord(0,1);
   cube-> position(-0.5,0.5,0.0);  cube-> normal(-0.666667,0.333333,-0.666667);  cube-> textureCoord(1,1);
   cube-> position( 0.5,0.5,1.0);   cube-> normal(0.666667,0.333333,0.666667);    cube-> textureCoord(0,0);

  cube->triangle(0,1,2);    cube->triangle(3,1,0);
  cube->triangle(4,5,6);    cube->triangle(4,7,5);
  cube->triangle(8,9,10);   cube->triangle(10,7,8);
  cube->triangle(4,11,12);  cube->triangle(4,13,11);
  cube->triangle(14,8,12);  cube->triangle(14,15,8);
  cube->triangle(16,17,18); cube->triangle(16,19,17);
  cube->end();

  return cube;
}

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

  SceneNode* mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
  mNode->setPosition(0,0.5,0);
  mNode->attachObject(createCubeMesh("Cube", "myMaterial"));

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

