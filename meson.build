project('Tutorial', ['cpp', 'c'], version : '0.0.1')
executable('hello', 'Source/main.cpp')

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

vulkan = dependency('vulkan')
c_args = get_option('c_args')
cpp_args = get_option('cpp_args')

message('\n'.join(['','',
' @0@-@1@'.format(meson.project_name(),meson.project_version()),
'',
' C Args: @0@'.format(c_args),
' C++ Args: @0@'.format(cpp_args),
' Buildtype: @0@'.format(buildtype),
' Install Prefix: @0@'.format(prefix),
''
]))
