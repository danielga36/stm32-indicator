#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "moon_riders::moon_riders_objects" for configuration "Release"
set_property(TARGET moon_riders::moon_riders_objects APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(moon_riders::moon_riders_objects PROPERTIES
  IMPORTED_COMMON_LANGUAGE_RUNTIME_RELEASE ""
  IMPORTED_OBJECTS_RELEASE "${_IMPORT_PREFIX}/moon_riders_ert_rtw/objects-Release/moon_riders_objects/moon_riders.c.obj"
  )

list(APPEND _IMPORT_CHECK_TARGETS moon_riders::moon_riders_objects )
list(APPEND _IMPORT_CHECK_FILES_FOR_moon_riders::moon_riders_objects "${_IMPORT_PREFIX}/moon_riders_ert_rtw/objects-Release/moon_riders_objects/moon_riders.c.obj" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
