# CMakeList.txt: проект CMake для MoneyManager; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
add_executable (MoneyManager "MoneyManager.cpp" "MoneyManager.h" "CoreFunctions.h" "CoreFunctions.cpp"  "Account.h" "History.h" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET MoneyManager PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
