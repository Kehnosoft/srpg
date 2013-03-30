################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Sources/Items/Armor.cpp \
../Sources/Items/Inventory.cpp \
../Sources/Items/Item.cpp \
../Sources/Items/Weapon.cpp 

OBJS += \
./Sources/Items/Armor.o \
./Sources/Items/Inventory.o \
./Sources/Items/Item.o \
./Sources/Items/Weapon.o 

CPP_DEPS += \
./Sources/Items/Armor.d \
./Sources/Items/Inventory.d \
./Sources/Items/Item.d \
./Sources/Items/Weapon.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/Items/%.o: ../Sources/Items/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -std=gnu++11 -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


