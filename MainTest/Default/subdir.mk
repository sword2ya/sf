################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../CHeap_test.cpp \
../MergeTest.cpp \
../SortTest.cpp \
../testmain.cpp 

OBJS += \
./CHeap_test.o \
./MergeTest.o \
./SortTest.o \
./testmain.o 

CPP_DEPS += \
./CHeap_test.d \
./MergeTest.d \
./SortTest.d \
./testmain.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../../include -I../ -I../../head -O0 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


