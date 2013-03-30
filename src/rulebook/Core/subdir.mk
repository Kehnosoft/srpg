################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Sources/Core/Dice.cpp \
../Sources/Core/RuleEngine.cpp 

OBJS += \
./Sources/Core/Dice.o \
./Sources/Core/RuleEngine.o 

CPP_DEPS += \
./Sources/Core/Dice.d \
./Sources/Core/RuleEngine.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/Core/%.o: ../Sources/Core/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -std=gnu++11 -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


