include_directories(${CMAKE_SOURCE_DIR}/compiler)
add_xacc_test(ProjectQCompiler)
target_link_libraries(ProjectQCompilerTester xacc-projectq-compiler)
