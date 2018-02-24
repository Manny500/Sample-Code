TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

include(deployment.pri)
qtcAddDeployment()

  INCLUDEPATH += gtest                       \
                 gtest/src                   \
                 gtest/src/gtest             \
                 gtest/include               \
                 gtest/include/gtest         \
                 gtest/include/gtest/internal

 LIBS +=  -L/usr/lib -Wall -Wextra -pthread

  SOURCES += "gtest/src/gtest.cc"            \
             "gtest/src/gtest-death-test.cc" \
             "gtest/src/gtest-filepath.cc"   \
             "gtest/src/gtest-port.cc"       \
             "gtest/src/gtest-printers.cc"   \
             "gtest/src/gtest-test-part.cc"  \
             "gtest/src/gtest-typed-test.cc"
