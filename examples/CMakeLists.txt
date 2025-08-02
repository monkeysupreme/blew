# Create an executable target for running the program
add_executable(blew_example main.cpp)

# Link the library to the executable
target_link_libraries(blew_example PRIVATE blew)