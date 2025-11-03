# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/langa/project214/Chaos_Compilers_COS214_Project_2025/_deps/googletest-src"
  "/home/langa/project214/Chaos_Compilers_COS214_Project_2025/_deps/googletest-build"
  "/home/langa/project214/Chaos_Compilers_COS214_Project_2025/_deps/googletest-subbuild/googletest-populate-prefix"
  "/home/langa/project214/Chaos_Compilers_COS214_Project_2025/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "/home/langa/project214/Chaos_Compilers_COS214_Project_2025/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "/home/langa/project214/Chaos_Compilers_COS214_Project_2025/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "/home/langa/project214/Chaos_Compilers_COS214_Project_2025/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/langa/project214/Chaos_Compilers_COS214_Project_2025/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/langa/project214/Chaos_Compilers_COS214_Project_2025/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
