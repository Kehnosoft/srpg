################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Sources/Creatures/Abilities.cpp \
../Sources/Creatures/Attack.cpp \
../Sources/Creatures/BaseSkills.cpp \
../Sources/Creatures/Character.cpp \
../Sources/Creatures/Creature.cpp \
../Sources/Creatures/Defence.cpp \
../Sources/Creatures/HitPoints.cpp \
../Sources/Creatures/SaveThrows.cpp 

OBJS += \
./Sources/Creatures/Abilities.o \
./Sources/Creatures/Attack.o \
./Sources/Creatures/BaseSkills.o \
./Sources/Creatures/Character.o \
./Sources/Creatures/Creature.o \
./Sources/Creatures/Defence.o \
./Sources/Creatures/HitPoints.o \
./Sources/Creatures/SaveThrows.o 

CPP_DEPS += \
./Sources/Creatures/Abilities.d \
./Sources/Creatures/Attack.d \
./Sources/Creatures/BaseSkills.d \
./Sources/Creatures/Character.d \
./Sources/Creatures/Creature.d \
./Sources/Creatures/Defence.d \
./Sources/Creatures/HitPoints.d \
./Sources/Creatures/SaveThrows.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/Creatures/%.o: ../Sources/Creatures/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -std=gnu++11 -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


