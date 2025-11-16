add_executable(test_app
    test_app.c
    ../src/app.c
    ../tests/mocks/mock_hal_gpio.c
    ../third_party/Unity/src/unity.c
)

target_include_directories(test_app PRIVATE
    ../include
    ../third_party/Unity/src
    ../tests/mocks
)

# اضافه کردن تعریف UNIT_TEST فقط در زمان تست
target_compile_definitions(test_app PRIVATE UNIT_TEST=1)

add_test(NAME app_test COMMAND test_app)
