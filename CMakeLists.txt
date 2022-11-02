project("zmq_test")

cmake_minimum_required(VERSION 3.16.3)

add_executable(zmq_pub src/zmq_publisher.cpp)
target_link_libraries(zmq_pub zmq)

add_executable(zmq_sub src/zmq_subscriber.cpp)
target_link_libraries(zmq_sub zmq)

add_executable(zmq_server_example src/zmq_exmpl_server.cpp)
target_link_libraries(zmq_server_example zmq)

add_executable(zmq_client_example src/zmq_exmpl_client.cpp)
target_link_libraries(zmq_client_example zmq)