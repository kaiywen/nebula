set(DATAMAN_TEST_LIBS
    $<TARGET_OBJECTS:common_thrift_obj>
    $<TARGET_OBJECTS:thrift_obj>
    $<TARGET_OBJECTS:dataman_obj>
    $<TARGET_OBJECTS:base_obj>
    $<TARGET_OBJECTS:network_obj>
    $<TARGET_OBJECTS:fs_obj>
    $<TARGET_OBJECTS:thread_obj>
)


add_executable(
    row_reader_test
    RowReaderTest.cpp
    ${DATAMAN_TEST_LIBS}
)
nebula_link_libraries(
    row_reader_test
    ${THRIFT_LIBRARIES}
    wangle
    gtest
)
nebula_add_test(row_reader_test)


add_executable(
    row_writer_test
    RowWriterTest.cpp
    ${DATAMAN_TEST_LIBS}
)
nebula_link_libraries(
    row_writer_test
    ${THRIFT_LIBRARIES}
    wangle
    gtest
)
nebula_add_test(row_writer_test)


add_executable(
    row_updater_test
    RowUpdaterTest.cpp
    ${DATAMAN_TEST_LIBS}
)
nebula_link_libraries(
    row_updater_test
    ${THRIFT_LIBRARIES}
    wangle
    gtest
)
nebula_add_test(row_updater_test)


add_executable(
    rowset_reader_writer_test
    RowSetReaderWriterTest.cpp
    ${DATAMAN_TEST_LIBS}
)
nebula_link_libraries(
    rowset_reader_writer_test
    ${THRIFT_LIBRARIES}
    wangle
    gtest
)
nebula_add_test(rowset_reader_writer_test)


add_executable(
    row_writer_bm
    RowWriterBenchmark.cpp
    ${DATAMAN_TEST_LIBS}
)
nebula_link_libraries(
    row_writer_bm
    ${THRIFT_LIBRARIES}
    follybenchmark
    wangle
    boost_regex
)


add_executable(
    row_reader_bm
    RowReaderBenchmark.cpp
    ${DATAMAN_TEST_LIBS}
)
nebula_link_libraries(
    row_reader_bm
    ${THRIFT_LIBRARIES}
    follybenchmark
    wangle
    boost_regex
)

add_executable(
    nebula_codec_test
    NebulaCodecTest.cpp
    ${DATAMAN_TEST_LIBS}
)
nebula_link_libraries(
    nebula_codec_test
    ${THRIFT_LIBRARIES}
    wangle
    gtest
)
nebula_add_test(nebula_codec_test)
