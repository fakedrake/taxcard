project(taxcard C)
cmake_minimum_required(VERSION 2.6.0)

set(PRODUCT_ID_SIZE 4)
set(CODE_SIZE 25)
set(MAX_ALLOWED_ENTRIES 200000)
set(VENDOR_NAME_SIZE 20);

include_directories(include)
link_directories(${taxcard_SOURCE_DIR}/lib)

add_subdirectory(include)
add_subdirectory(src lib)
add_subdirectory(tests bin)
