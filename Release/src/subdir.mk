################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/audioTags.cpp \
../src/configurationFile.cpp \
../src/musicDB.cpp \
../src/prepareMusic.cpp 

OBJS += \
./src/audioTags.o \
./src/configurationFile.o \
./src/musicDB.o \
./src/prepareMusic.o 

CPP_DEPS += \
./src/audioTags.d \
./src/configurationFile.d \
./src/musicDB.d \
./src/prepareMusic.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I/usr/include/taglib -I"/home/jdellaria/eclipse-workspace/DLiriumLib" -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


