################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Hospital.cpp \
../src/LL_IMP.cpp \
../src/PQ_IMP.cpp 

OBJS += \
./src/Hospital.o \
./src/LL_IMP.o \
./src/PQ_IMP.o 

CPP_DEPS += \
./src/Hospital.d \
./src/LL_IMP.d \
./src/PQ_IMP.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


