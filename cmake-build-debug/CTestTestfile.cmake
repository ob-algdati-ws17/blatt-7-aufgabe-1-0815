# CMake generated Testfile for 
# Source directory: C:/Users/Patrick/Desktop/SkyDrive/Studium/3_WS_1718/algorithmen_und_datenstrukturen_1/praktikum/07/blatt-7-aufgabe-1-0815
# Build directory: C:/Users/Patrick/Desktop/SkyDrive/Studium/3_WS_1718/algorithmen_und_datenstrukturen_1/praktikum/07/blatt-7-aufgabe-1-0815/cmake-build-debug
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(testList "test/testList" "--gtest_output=xml:report.xml")
subdirs("avlTree")
subdirs("googletest-build")
subdirs("test")
