#***********************************************************************************
# Copyright (c) 2016, UT-Battelle
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#   * Redistributions of source code must retain the above copyright
#     notice, this list of conditions and the following disclaimer.
#   * Redistributions in binary form must reproduce the above copyright
#     notice, this list of conditions and the following disclaimer in the
#     documentation and/or other materials provided with the distribution.
#   * Neither the name of the xacc nor the
#     names of its contributors may be used to endorse or promote products
#     derived from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
# DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
# (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
# ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
# SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
# Contributors:
#   Initial API and implementation - Alex McCaskey
#   ANTLR compiler implementation - H. Charles Zhao
#
#**********************************************************************************/

set (PACKAGE_NAME "ProjectQ XACC Compiler")
set (PACKAGE_DESCIPTION "ProjectQ XACC Compiler Bundle")
set (LIBRARY_NAME xacc-projectq-compiler)

file (GLOB_RECURSE HEADERS *.hpp)
file (GLOB SRC *.cpp generated/*.cpp)

# Set up dependencies to resources to track changes
usFunctionGetResourceSource(TARGET ${LIBRARY_NAME} OUT SRC)
# Generate bundle initialization code
usFunctionGenerateBundleInit(TARGET ${LIBRARY_NAME} OUT SRC)

add_library(${LIBRARY_NAME} SHARED ${SRC})

set(_bundle_name xacc_projectq_compiler)

set_target_properties(${LIBRARY_NAME} PROPERTIES
  # This is required for every bundle
  COMPILE_DEFINITIONS US_BUNDLE_NAME=${_bundle_name}
  # This is for convenience, used by other CMake functions
  US_BUNDLE_NAME ${_bundle_name}
  )

if(BUILD_SHARED_LIBS)
	#  set_target_properties(${LIBRARY_NAME} PROPERTIES
	#    CXX_VISIBILITY_PRESET hidden
	#    VISIBILITY_INLINES_HIDDEN 1
	#    )
endif()

# Embed meta-data from a manifest.json file
usFunctionEmbedResources(TARGET ${LIBRARY_NAME}
  WORKING_DIRECTORY
    ${CMAKE_CURRENT_SOURCE_DIR}
  FILES
    manifest.json
  )


# ANTLR setup

add_subdirectory(runtime)

set(xacc_projectq_compiler-GENERATED_SRC
        ${CMAKE_CURRENT_SOURCE_DIR}/generated/ProjectQLexer.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/generated/ProjectQParser.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/generated/ProjectQBaseListener.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/generated/ProjectQListener.cpp
        )

foreach( src_file ${xacc_projectq_compiler-GENERATED_SRC} )
    set_source_files_properties(
            ${src_file}
            PROPERTIES
            GENERATED TRUE
    )
endforeach( src_file )

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/runtime/src
        ${CMAKE_CURRENT_SOURCE_DIR}/runtime/src/misc
        ${CMAKE_CURRENT_SOURCE_DIR}/runtime/src/atn
        ${CMAKE_CURRENT_SOURCE_DIR}/runtime/src/dfa
        ${CMAKE_CURRENT_SOURCE_DIR}/runtime/src/tree
        ${CMAKE_CURRENT_SOURCE_DIR}/runtime/src/support
        ${CMAKE_CURRENT_SOURCE_DIR}/generated
)

set(xacc_projectq_compiler_SRC
        ${CMAKE_CURRENT_SOURCE_DIR}/ProjectQCompiler.cpp
        ${xacc_projectq_compiler-GENERATED_SRC}
        )

if (NOT CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    set (flags_1 "-Wno-overloaded-virtual")
else()
    set (flags_1 "-MP /wd4251")
endif()

foreach( src_file ${xacc_projectq_compiler_SRC} )
    set_source_files_properties(
            ${src_file}
            PROPERTIES
            COMPILE_FLAGS "${COMPILE_FLAGS} ${flags_1}"
    )
endforeach( src_file )

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    target_compile_options(xacc_projectq_compiler PRIVATE "/MT$<$<CONFIG:Debug>:d>")
endif()

target_link_libraries(${LIBRARY_NAME} antlr4_static)

target_link_libraries(${LIBRARY_NAME} ${XACC_LIBRARIES})
if(APPLE)
   set_target_properties(${LIBRARY_NAME} PROPERTIES INSTALL_RPATH "@loader_path/../lib")
   set_target_properties(${LIBRARY_NAME} PROPERTIES LINK_FLAGS "-undefined dynamic_lookup")
else()
   set_target_properties(${LIBRARY_NAME} PROPERTIES INSTALL_RPATH "$ORIGIN/../lib")
   set_target_properties(${LIBRARY_NAME} PROPERTIES LINK_FLAGS "-shared")
endif()

install(TARGETS ${LIBRARY_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX}/plugins)

