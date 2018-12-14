platform = ARGUMENTS.get('OS', Platform())
#mode = ARGUMENTS.get('mode', "release")
mode = ARGUMENTS.get('mode', "debug")

listinc=[
   # our main include directory
   'include',
   # location of ogre includes
   '/usr/include/OGRE',
   # location of ois includes
   '/usr/include/OIS',
]


debugcflags=['-g']
releasecflags=[]

if mode=="debug":
   env=Environment(CPPPATH=listinc, LIBPATH='.', CCFLAGS = debugcflags)
else:
   env=Environment(CPPPATH=listinc, LIBPATH='.', CCFLAGS = releasecflags)

#print env.Dump()

# check for required include files and libraries
conf = Configure(env)
if not conf.CheckCXXHeader('Ogre.h'):
   print 'Ogre must be installed!'
   Exit(1)
if not conf.CheckCXXHeader('OISPrereqs.h'):
   print 'OIS must be installed!'
   Exit(1)
if platform.name == "linux":
   if not conf.CheckLib('OgreMain'):
      print 'OgreMain library must be in path'
      Exit(1)
   if not conf.CheckLib('OgreBites'):
      print 'OgreBites library must be in path'
      Exit(1)
   if not conf.CheckLib('OIS'):
      print 'OIS library must be in path'
      Exit(1)

# list of files needed for compiling the program
main_program_list=Split("""
   src/main.cpp
   """)

# list of libraries needed for linking
libs_list=Split("""
   OgreMain
   OgreBites
   OIS
   """)

if mode=="debug":
  env.Program('bin/linux/debug/main_d', main_program_list, LIBS=libs_list, LIBPATH='.')
else:
  env.Program('bin/linux/release/main', main_program_list, LIBS=libs_list, LIBPATH='.')
