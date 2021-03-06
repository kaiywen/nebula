add_executable(
    parser_test
    ParserTest.cpp
    $<TARGET_OBJECTS:parser_obj>
    $<TARGET_OBJECTS:base_obj>
    $<TARGET_OBJECTS:network_obj>
    $<TARGET_OBJECTS:fs_obj>
)
nebula_link_libraries(
    parser_test
    gtest
    gtest_main
)
target_include_directories(parser_test SYSTEM BEFORE PUBLIC ${FLEX_INCLUDE_DIRS})
nebula_add_test(parser_test)

add_executable(
    scanner_test
    ScannerTest.cpp
    $<TARGET_OBJECTS:parser_obj>
    $<TARGET_OBJECTS:base_obj>
    $<TARGET_OBJECTS:network_obj>
    $<TARGET_OBJECTS:fs_obj>
)
nebula_link_libraries(
    scanner_test
    gtest
    gtest_main
)
target_include_directories(scanner_test SYSTEM BEFORE PUBLIC ${FLEX_INCLUDE_DIRS})
nebula_add_test(scanner_test)

add_compile_options(-Wno-parentheses)

add_executable(
    expression_test
    ExpressionTest.cpp
    $<TARGET_OBJECTS:parser_obj>
    $<TARGET_OBJECTS:base_obj>
    $<TARGET_OBJECTS:network_obj>
    $<TARGET_OBJECTS:fs_obj>
)
nebula_link_libraries(
    expression_test
    gtest
    gtest_main
)
target_include_directories(expression_test SYSTEM BEFORE PUBLIC ${FLEX_INCLUDE_DIRS})
nebula_add_test(expression_test)

add_executable(
    expression_encode_decode_bm
    ExpressionEncodeDecodeBenchmark.cpp
    $<TARGET_OBJECTS:base_obj>
    $<TARGET_OBJECTS:parser_obj>
    $<TARGET_OBJECTS:network_obj>
    $<TARGET_OBJECTS:fs_obj>
)
nebula_link_libraries(
    expression_encode_decode_bm
    follybenchmark
    boost_regex
)
