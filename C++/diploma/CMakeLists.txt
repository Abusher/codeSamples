CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

project (RingSign)

set(CMAKE_BUILD_TYPE Debug)



#find_package(Boost 1.66.0 REQUIRED system program_options )
if(NOT Boost_FOUND)
    set (BOOST_ROOT /home/user/boost_1_66_0)
    find_package(Boost 1.66.0 REQUIRED system program_options filesystem )
endif()
if(Boost_FOUND)
    
    add_library(RSA include/rsa_elem.hpp src/rsa_elem.cpp  include/rsa_generator.hpp  src/rsa_generator.cpp)
    target_include_directories(RSA PUBLIC include)
    target_include_directories(RSA PUBLIC ${Boost_INCLUDE_DIRS})
    target_link_libraries(RSA PUBLIC ${Boost_LIBRARIES} ${CMAKE_DL_LIBS} pthread gmp gmpxx)

    add_library(RingLib include/ringsignature.hpp src/ringsignature.cpp)
    target_include_directories(RingLib PUBLIC include)
    target_include_directories(RingLib PUBLIC ${Boost_INCLUDE_DIRS})
    target_link_libraries(RingLib PUBLIC ${Boost_LIBRARIES} ${CMAKE_DL_LIBS} RSA pthread gmp gmpxx)

    add_executable(Sign main.cpp)
    target_include_directories(Sign PUBLIC include)
    target_include_directories(Sign PUBLIC ${Boost_INCLUDE_DIRS})
    target_link_libraries(Sign PUBLIC ${Boost_LIBRARIES} ${CMAKE_DL_LIBS} RingLib pthread gmp gmpxx)
else()
    message(ERROR " Cannot find Boost 1.66.0 library. Please, specify the place with boost library\n ")
endif()

