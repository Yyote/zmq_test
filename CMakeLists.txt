project("zmq_test")

cmake_minimum_required(VERSION 3.16.3)

add_executable(zmq_pub src/zmq_publisher.cpp)
target_link_libraries(zmq_pub zmq)

add_executable(zmq_sub src/zmq_subscriber.cpp)
target_link_libraries(zmq_sub zmq)

