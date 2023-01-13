# generated from
# rosidl_cmake/cmake/template/rosidl_cmake_export_typesupport_targets.cmake.in

set(_exported_typesupport_targets
  "__rosidl_typesupport_introspection_c:custom_messages_pkg__rosidl_typesupport_introspection_c;__rosidl_typesupport_introspection_cpp:custom_messages_pkg__rosidl_typesupport_introspection_cpp")

# populate custom_messages_pkg_TARGETS_<suffix>
if(NOT _exported_typesupport_targets STREQUAL "")
  # loop over typesupport targets
  foreach(_tuple ${_exported_typesupport_targets})
    string(REPLACE ":" ";" _tuple "${_tuple}")
    list(GET _tuple 0 _suffix)
    list(GET _tuple 1 _target)

    set(_target "custom_messages_pkg::${_target}")
    if(NOT TARGET "${_target}")
      # the exported target must exist
      message(WARNING "Package 'custom_messages_pkg' exports the typesupport target '${_target}' which doesn't exist")
    else()
      list(APPEND custom_messages_pkg_TARGETS${_suffix} "${_target}")
    endif()
  endforeach()
endif()
