################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Animal.cpp \
../Cat.cpp \
../Dog.cpp \
../Kennel.cpp \
../main.cpp 

OBJS += \
./Animal.o \
./Cat.o \
./Dog.o \
./Kennel.o \
./main.o 

CPP_DEPS += \
./Animal.d \
./Cat.d \
./Dog.d \
./Kennel.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<" -std=c++11
	@echo 'Finished building: $<'
	@echo ' '


