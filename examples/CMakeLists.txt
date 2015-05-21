cmake_minimum_required(VERSION 2.8)
project( AnifaceDetect )
find_package( OpenCV REQUIRED )
add_executable( AnifaceDetect detect.cpp )
target_link_libraries( AnifaceDetect ${OpenCV_LIBS} )
add_custom_target(
    Link ALL rm lbpcascade_animeface.xml
    COMMAND ln -s ${CMAKE_SOURCE_DIR}/../lbpcascade_animeface.xml
)
