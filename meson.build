project('Tutorial', ['cpp', 'c'], version : '0.0.1')

pkgconfig = import('pkgconfig')

cc = meson.get_compiler('c')
cxx = meson.get_compiler('cpp')

system = build_machine.system()

if (system == 'linux') or (system == 'darwin')
	message(true)
endif

buildtype = get_option('buildtype')
prefix = get_option('prefix')

if get_option('UNITY_BUILD') == true
	message('Setting unity build successful')
	MSG = 'UNITY_BUILD: ' + get_option('UNITY_BUILD').to_string()
	message(MSG)
endif

if meson.is_cross_build() != true
  vulkan = dependency('vulkan')
endif

c_args = get_option('c_args')
cpp_args = get_option('cpp_args')

  add_global_arguments([
    '-Wno-pragmas',
    '-Wno-unused-variable',
    '-Wno-switch',
    '-Wno-unused-value',
    '-Winvalid-pch',
    '-Wno-multichar'
  ], language: ['c','cpp'])
  
glew = ''
if get_option('USE_SYSTEM_GLEW')
  glew = dependency('GLEW')
elif (glew.found() != true) or (get_option('USE_SYSTEM_GLEW') != true)
  glew = declare_dependency(include_directories : 'ThirdParty/glew/include', compile_args : '-DGLEW_STATIC', sources : 'ThirdParty/glew/src/glew.c')
endif

message('\n'.join(['','',
' @0@-@1@'.format(meson.project_name(),meson.project_version()),
'',
' C Args: @0@'.format(c_args),
' C++ Args: @0@'.format(cpp_args),
' Buildtype: @0@'.format(buildtype),
' Install Prefix: @0@'.format(prefix),
' Vulkan: @0@'.format(vulkan.include_directories()),
' GLEW: @0@'.format(glew),
''
]))

executable('hello', 'Source/main.cpp', dependency : glew)
