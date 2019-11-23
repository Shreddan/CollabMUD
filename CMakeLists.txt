cmake_minimum_required(VERSION 3.7)
project(OlcMud)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} CMakeModules/)
cmake_policy(SET CMP0037 OLD)

# Debug (remove this line for live build if NOT on windows)
set(CMAKE_BUILD_TYPE Debug)

set(executable output)
set(SrcDIR ./OlcMud)
set(IncludeDIR ./include)

# TODO: Include ability to compile / run tests (maybe unit test lib(?))

# Include Windows
if (WIN32)

endif (WIN32)

# Include Linux
if (UNIX)

endif (UNIX)

# Include /include
include_directories(${executable}
	${IncludeDIR}
)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)


file(GLOB SourceFiles 
	${SrcDIR}/*
	${SrcDIR}/Util/*
	${SrcDIR}/Core/Network/*
	${SrcDIR}/Core/Telnet/*
	${SrcDIR}/Items/*
)

add_executable(${executable} ${SourceFiles})

set_target_properties(${executable} PROPERTIES
	CXX_STANDARD 17
	CXX_EXTENSIONS OFF
)

# Link linux
if (UNIX)
	target_link_libraries(${executable}
		Threads::Threads
	)
endif (UNIX)

# Link windows
if (WIN32)
	target_link_libraries(${executable}
		${WinSDK}
	)
endif (WIN32)

target_link_libraries(${executable}
	${CMAKE_DL_LIBS}
)
