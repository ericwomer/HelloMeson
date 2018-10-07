
project(
  'Tutorial',
  ['cpp', 'c'],
  version : '0.0.1'
)

pkgconfig = import('pkgconfig')

cc = meson.get_compiler('c')
cxx = meson.get_compiler('cpp')

system = build_machine.system()

if (system == 'darwin')
	message('System darwin: ' + true.to_string())
endif

buildtype = get_option('buildtype')
prefix = get_option('prefix')

hello_source = 'Source/main.cpp'
hello_include = include_directories('Source/')
hello_arguments = [] # Empty list for compiler arguments specifically for hello app
hello_deps = [] # Create an empy list to store depencies in

if get_option('UNITY_BUILD')
	message('Setting unity build successful')
	MSG = 'UNITY_BUILD: ' + get_option('UNITY_BUILD').to_string()
	message(MSG)
endif

if not meson.is_cross_build() and get_option('ENABLE_VULKAN')
  vulkan = dependency('vulkan')
  hello_deps += vulkan
  hello_arguments += '-DENABLE_VULKAN'
endif

glew = dependency('glew')
gl = dependency('gl', required: true)

if get_option('USE_SYSTEM_GLEW') and glew.found()
  hello_deps += glew
  glew_source = ''
  glew_include = include_directories('')
  glew_arguments = ''
else
  glew_source = 'Source/ThirdParty/glew/src/glew.c'
  glew_include = include_directories('Source/ThirdParty/glew/include')
  glew_arguments = '-DGLEW_STATIC'
endif

if gl.found()
  hello_deps += gl
endif

hello_source = [ hello_source, glew_source ]
hello_include = [ hello_include, glew_include ]
hello_arguments = [ hello_arguments, glew_arguments ]

add_global_arguments([
  '-Wno-pragmas',
  '-Wno-unused-variable',
  '-Wno-switch',
  '-Wno-unused-value',
  '-Winvalid-pch',
  '-Wno-multichar'], language: ['c','cpp'])

hello = executable(
  'hello',
  hello_source,
  dependencies : hello_deps,
  include_directories: [ hello_include , ],
  cpp_args: hello_arguments, # redundency since this is per project only and already added to global?
  install: false
  )

c_args = get_option('c_args')
cpp_args = get_option('cpp_args')

 message('\n'.join(['','',
' @0@-@1@'.format(meson.project_name(),meson.project_version()),
'',
' C Args: @0@'.format(c_args),
' C++ Args: @0@'.format(cpp_args),
' Buildtype: @0@'.format(buildtype),
' Install Prefix: @0@'.format(prefix),
' Include Directories: @0@'.format(hello_include),
''
]))