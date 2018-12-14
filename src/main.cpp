#include <Ogre.h>
#include <Overlay/OgreTextAreaOverlayElement.h>
#include <Overlay/OgreFontManager.h>
#include "ExampleFrameListener.h"
#define FONT_FILE_NAME "solo5.ttf"
// save some horizontal space
using namespace Ogre;
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define FONT_FOLDER "C:\\My\\Font\\Folder"
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT )
#else
#define FONT_FOLDER "/usr/share/ogrenew/Samples/Media/fonts"
int main(int argc, char **argv)
#endif
{
  // create root
  Root *root = new Root();
  // choose renderer
  if(!root->showConfigDialog())
  {
    return 0;
  }
  // initialise root
  root->initialise(false);
  // create main window
  RenderWindow *renderWindow = root->createRenderWindow("Main",320,240,false);
  // create the scene
  SceneManager *sceneMgr = root->createSceneManager(Ogre::ST_GENERIC);
  // add a camera
  Camera *mainCam = sceneMgr->createCamera("MainCam");
  // add viewport
  Viewport *vp = renderWindow->addViewport(mainCam);



  // Create a font
  //
  //

  // get the resource manager
  ResourceGroupManager &resGroupMgr = ResourceGroupManager::getSingleton();
  // tell it to look at this location
  resGroupMgr.addResourceLocation(FONT_FOLDER, "FileSystem");
  // get the font manager
  FontManager &fontMgr = FontManager::getSingleton();
  // create a font resource
  ResourcePtr font = fontMgr.create("MyFont","General");
  // set as truetype
  font->setParameter("type","truetype");
  // set the .ttf file name
  font->setParameter("source",FONT_FILE_NAME);
  // set the size
  font->setParameter("size","26");
  // set the dpi
  font->setParameter("resolution","96");
  // load the ttf
  font->load();


  // Create the TextAreaOverlayElement

  // get the overlay manager
  OverlayManager& overlayMgr = OverlayManager::getSingleton();

  Here we create a panel and set its position and size.

    // Create a panel
    Ogre::OverlayContainer* panel = static_cast<OverlayContainer*>(
        overlayMgr.createOverlayElement("Panel", "PanelName"));
  panel->setMetricsMode(Ogre::GMM_PIXELS);
  panel->setPosition(10, 10);
  panel->setDimensions(300, 120);

  // Create a text area
  TextAreaOverlayElement* textArea = static_cast<TextAreaOverlayElement*>(
      overlayMgr.createOverlayElement("TextArea", "TextAreaName"));
  textArea->setMetricsMode(Ogre::GMM_PIXELS);
  textArea->setPosition(0, 0);
  textArea->setDimensions(300, 120);
  textArea->setCharHeight(26);
  // set the font name to the font resource that you just created.
  textArea->setFontName("MyFont");
  // say something
  textArea->setCaption("Hello, World!");

  // Here we create an Overlay to display the panel

  // Create an overlay, and add the panel
  Ogre::Overlay* overlay = overlayMgr.create("OverlayName");
  overlay->add2D(panel);

  // We have to add the text area to the panel _after_ adding the panel to an overlay to avoid a segfault.

  // Add the text area to the panel
  panel->addChild(textArea);

  // And display our overlay.

  // Show the overlay
  overlay->show();

  // setup frame listener
  ExampleFrameListener *frameListener= new ExampleFrameListener(renderWindow, mainCam);
  frameListener->showDebugOverlay(false);
  root->addFrameListener(frameListener);

  // start rendering
  root->startRendering();

  return 0;
}


