cmake_minimum_required(VERSION 2.8.2)

project(googletest-download NONE)

include(ExternalProject)
ExternalProject_Add(googletest
  GIT_REPOSITORY    https://github.com/google/googletest.git
  GIT_TAG           master
  SOURCE_DIR        "C:/Users/Patrick/Desktop/SkyDrive/Studium/3_WS_1718/algorithmen_und_datenstrukturen_1/praktikum/07/blatt-7-aufgabe-1-0815/cmake-build-debug/googletest-src"
  BINARY_DIR        "C:/Users/Patrick/Desktop/SkyDrive/Studium/3_WS_1718/algorithmen_und_datenstrukturen_1/praktikum/07/blatt-7-aufgabe-1-0815/cmake-build-debug/googletest-build"
  CONFIGURE_COMMAND ""
  BUILD_COMMAND     ""
  INSTALL_COMMAND   ""
  TEST_COMMAND      ""
)
