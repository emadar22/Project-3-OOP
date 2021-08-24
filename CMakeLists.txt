cmake_minimum_required(VERSION 3.12)
project(HW3_OOP)

set(CMAKE_CXX_STANDARD 98)

add_executable(HW3_OOP SharedPtr.h MathematicalOperations.h MathematicalOperations.cpp Function.h
        ConstantFunction.h ConstantFunction.cpp VariableFunction.h VariableFunction.cpp
        AddFunction.h AddFunction.cpp SubtractFunction.h SubtractFunction.cpp MultiplyFunction.h MultiplyFunction.cpp
        DivideFunction.h   DivideFunction.cpp
        main.cpp)