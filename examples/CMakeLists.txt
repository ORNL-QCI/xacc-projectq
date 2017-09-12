
add_executable(h2_exp_vals h2_exp_vals.cpp)
target_link_libraries(h2_exp_vals ${Boost_LIBRARIES} ${XACC_LIBRARIES} dl)

install(TARGETS h2_exp_vals DESTINATION ${XACC_ROOT}/examples)
   
