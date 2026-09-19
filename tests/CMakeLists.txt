add_executable(pattern_finder_tests PatternFinderTests.cpp)
target_compile_features(pattern_finder_tests PRIVATE cxx_std_20)
target_include_directories(pattern_finder_tests PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../src")

add_test(NAME pattern_finder_tests COMMAND pattern_finder_tests)
