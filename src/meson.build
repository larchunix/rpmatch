compiler = meson.get_compiler('c')

# Checks for header files.
headers = [
  'getopt.h',
  'locale.h',
  'stdio.h',
  'stdlib.h',
  'string.h',
]

foreach h: headers
  if not compiler.has_header(h)
    error('Header file @0@ not found.'.format(h))
  endif
endforeach

# Checks for library functions.
functions = [
  'getopt_long',
  'rpmatch',
  'setlocale',
]

foreach f: functions
  if not compiler.has_function(f)
    error('Function @0@() not found.'.format(f))
  endif
endforeach

rpmatch_conf_data = configuration_data()

rpmatch_conf_data.set_quoted('PACKAGE_NAME', meson.project_name())
rpmatch_conf_data.set_quoted('PACKAGE_VERSION', meson.project_version())

configure_file(
  configuration: rpmatch_conf_data,
  output: 'config.h',
)

executable(
  'rpmatch',
  sources: [
    'rpmatch.c',
  ],
  install: true,
)

# vi: set ft=meson et sw=2 ts=2:
