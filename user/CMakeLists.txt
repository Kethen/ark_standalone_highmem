cmake_minimum_required(VERSION 2.8)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  if(DEFINED ENV{VITASDK})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE PATH "toolchain file")
  else()
    message(FATAL_ERROR "Please define VITASDK to point to your SDK path!")
  endif()
endif()

project(ark_standalone_highmem_user)
include("${VITASDK}/share/vita.cmake" REQUIRED)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wl,-q -O3 -std=gnu99")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fno-rtti -fno-exceptions")

add_executable(ark_standalone_highmem_user
	PspEmu.c
	Main.c
)

target_link_libraries(ark_standalone_highmem_user
	taihen_stub
	SceLibc_stub_weak
	SceKernelModulemgr_stub
)

set_target_properties(ark_standalone_highmem_user
  PROPERTIES LINK_FLAGS "-nostdlib"
)

vita_create_self(ark_standalone_highmem_user.suprx ark_standalone_highmem_user CONFIG exports.yml UNSAFE)
vita_create_stubs(stubs ark_standalone_highmem_user ${CMAKE_SOURCE_DIR}/exports.yml)
