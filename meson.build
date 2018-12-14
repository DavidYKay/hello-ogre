project('helloOgre', 'cpp')

src = [
  'src/main.cpp'
]

cc = meson.get_compiler('cpp')
depois = dependency('OIS')
depogre = declare_dependency(
  dependencies : [ 
    cc.find_library('OgreMain'),
    cc.find_library('OgreBites'),
    ],
  include_directories: include_directories(
    '/usr/include/OGRE',
    )
)

exe = executable('main', src,
  link_with: [
    ],
  dependencies: [
    depois,
    depogre,
    #dependency('OgreMain',
  ],
  )

#test('main', test_exe)
