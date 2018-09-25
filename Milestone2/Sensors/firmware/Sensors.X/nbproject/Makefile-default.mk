#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Sensors.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Sensors.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../../Milestone1/firmware/src/system_config/default/bsp/bsp.c ../../Milestone1/firmware/src/system_config/default/framework/driver/adc/src/drv_adc_static.c ../../Milestone1/firmware/src/system_config/default/framework/driver/tmr/src/drv_tmr_static.c ../../Milestone1/firmware/src/system_config/default/framework/driver/tmr/src/drv_tmr_mapping.c ../../Milestone1/firmware/src/system_config/default/framework/driver/usart/src/drv_usart_mapping.c ../../Milestone1/firmware/src/system_config/default/framework/driver/usart/src/drv_usart_static.c ../../Milestone1/firmware/src/system_config/default/framework/driver/usart/src/drv_usart_static_byte_model.c ../../Milestone1/firmware/src/system_config/default/framework/system/clk/src/sys_clk_pic32mx.c ../../Milestone1/firmware/src/system_config/default/framework/system/devcon/src/sys_devcon.c ../../Milestone1/firmware/src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mx.c ../../Milestone1/firmware/src/system_config/default/framework/system/ports/src/sys_ports_static.c ../../Milestone1/firmware/src/system_config/default/system_init.c ../../Milestone1/firmware/src/system_config/default/system_interrupt.c ../../Milestone1/firmware/src/system_config/default/system_exceptions.c ../../Milestone1/firmware/src/system_config/default/system_tasks.c ../../Milestone1/firmware/src/system_config/default/system_interrupt_a.S ../../Milestone1/firmware/src/system_config/default/rtos_hooks.c ../../Milestone1/firmware/src/appThread.c ../../Milestone1/firmware/src/main.c ../../../../../../../microchip/harmony/v2_06/framework/osal/src/osal_freertos.c ../../../../../../../microchip/harmony/v2_06/framework/system/int/src/sys_int_pic32.c ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MemMang/heap_1.c ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX/port.c ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX/port_asm.S ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/croutine.c ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/list.c ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/queue.c ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/tasks.c ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/timers.c ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/event_groups.c ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/stream_buffer.c ../../Milestone1/firmware/src/sensor.c ../../Milestone1/firmware/src/sensor_debug.c ../../Milestone1/firmware/src/sensor_drivers.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1484260413/bsp.o ${OBJECTDIR}/_ext/880468539/drv_adc_static.o ${OBJECTDIR}/_ext/834684468/drv_tmr_static.o ${OBJECTDIR}/_ext/834684468/drv_tmr_mapping.o ${OBJECTDIR}/_ext/1253198688/drv_usart_mapping.o ${OBJECTDIR}/_ext/1253198688/drv_usart_static.o ${OBJECTDIR}/_ext/1253198688/drv_usart_static_byte_model.o ${OBJECTDIR}/_ext/1413235516/sys_clk_pic32mx.o ${OBJECTDIR}/_ext/2082105931/sys_devcon.o ${OBJECTDIR}/_ext/2082105931/sys_devcon_pic32mx.o ${OBJECTDIR}/_ext/1892719732/sys_ports_static.o ${OBJECTDIR}/_ext/950918765/system_init.o ${OBJECTDIR}/_ext/950918765/system_interrupt.o ${OBJECTDIR}/_ext/950918765/system_exceptions.o ${OBJECTDIR}/_ext/950918765/system_tasks.o ${OBJECTDIR}/_ext/950918765/system_interrupt_a.o ${OBJECTDIR}/_ext/950918765/rtos_hooks.o ${OBJECTDIR}/_ext/1048187810/appThread.o ${OBJECTDIR}/_ext/1048187810/main.o ${OBJECTDIR}/_ext/400469038/osal_freertos.o ${OBJECTDIR}/_ext/1020727214/sys_int_pic32.o ${OBJECTDIR}/_ext/33242672/heap_1.o ${OBJECTDIR}/_ext/315077059/port.o ${OBJECTDIR}/_ext/315077059/port_asm.o ${OBJECTDIR}/_ext/1504750355/croutine.o ${OBJECTDIR}/_ext/1504750355/list.o ${OBJECTDIR}/_ext/1504750355/queue.o ${OBJECTDIR}/_ext/1504750355/tasks.o ${OBJECTDIR}/_ext/1504750355/timers.o ${OBJECTDIR}/_ext/1504750355/event_groups.o ${OBJECTDIR}/_ext/1504750355/stream_buffer.o ${OBJECTDIR}/_ext/1048187810/sensor.o ${OBJECTDIR}/_ext/1048187810/sensor_debug.o ${OBJECTDIR}/_ext/1048187810/sensor_drivers.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1484260413/bsp.o.d ${OBJECTDIR}/_ext/880468539/drv_adc_static.o.d ${OBJECTDIR}/_ext/834684468/drv_tmr_static.o.d ${OBJECTDIR}/_ext/834684468/drv_tmr_mapping.o.d ${OBJECTDIR}/_ext/1253198688/drv_usart_mapping.o.d ${OBJECTDIR}/_ext/1253198688/drv_usart_static.o.d ${OBJECTDIR}/_ext/1253198688/drv_usart_static_byte_model.o.d ${OBJECTDIR}/_ext/1413235516/sys_clk_pic32mx.o.d ${OBJECTDIR}/_ext/2082105931/sys_devcon.o.d ${OBJECTDIR}/_ext/2082105931/sys_devcon_pic32mx.o.d ${OBJECTDIR}/_ext/1892719732/sys_ports_static.o.d ${OBJECTDIR}/_ext/950918765/system_init.o.d ${OBJECTDIR}/_ext/950918765/system_interrupt.o.d ${OBJECTDIR}/_ext/950918765/system_exceptions.o.d ${OBJECTDIR}/_ext/950918765/system_tasks.o.d ${OBJECTDIR}/_ext/950918765/system_interrupt_a.o.d ${OBJECTDIR}/_ext/950918765/rtos_hooks.o.d ${OBJECTDIR}/_ext/1048187810/appThread.o.d ${OBJECTDIR}/_ext/1048187810/main.o.d ${OBJECTDIR}/_ext/400469038/osal_freertos.o.d ${OBJECTDIR}/_ext/1020727214/sys_int_pic32.o.d ${OBJECTDIR}/_ext/33242672/heap_1.o.d ${OBJECTDIR}/_ext/315077059/port.o.d ${OBJECTDIR}/_ext/315077059/port_asm.o.d ${OBJECTDIR}/_ext/1504750355/croutine.o.d ${OBJECTDIR}/_ext/1504750355/list.o.d ${OBJECTDIR}/_ext/1504750355/queue.o.d ${OBJECTDIR}/_ext/1504750355/tasks.o.d ${OBJECTDIR}/_ext/1504750355/timers.o.d ${OBJECTDIR}/_ext/1504750355/event_groups.o.d ${OBJECTDIR}/_ext/1504750355/stream_buffer.o.d ${OBJECTDIR}/_ext/1048187810/sensor.o.d ${OBJECTDIR}/_ext/1048187810/sensor_debug.o.d ${OBJECTDIR}/_ext/1048187810/sensor_drivers.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1484260413/bsp.o ${OBJECTDIR}/_ext/880468539/drv_adc_static.o ${OBJECTDIR}/_ext/834684468/drv_tmr_static.o ${OBJECTDIR}/_ext/834684468/drv_tmr_mapping.o ${OBJECTDIR}/_ext/1253198688/drv_usart_mapping.o ${OBJECTDIR}/_ext/1253198688/drv_usart_static.o ${OBJECTDIR}/_ext/1253198688/drv_usart_static_byte_model.o ${OBJECTDIR}/_ext/1413235516/sys_clk_pic32mx.o ${OBJECTDIR}/_ext/2082105931/sys_devcon.o ${OBJECTDIR}/_ext/2082105931/sys_devcon_pic32mx.o ${OBJECTDIR}/_ext/1892719732/sys_ports_static.o ${OBJECTDIR}/_ext/950918765/system_init.o ${OBJECTDIR}/_ext/950918765/system_interrupt.o ${OBJECTDIR}/_ext/950918765/system_exceptions.o ${OBJECTDIR}/_ext/950918765/system_tasks.o ${OBJECTDIR}/_ext/950918765/system_interrupt_a.o ${OBJECTDIR}/_ext/950918765/rtos_hooks.o ${OBJECTDIR}/_ext/1048187810/appThread.o ${OBJECTDIR}/_ext/1048187810/main.o ${OBJECTDIR}/_ext/400469038/osal_freertos.o ${OBJECTDIR}/_ext/1020727214/sys_int_pic32.o ${OBJECTDIR}/_ext/33242672/heap_1.o ${OBJECTDIR}/_ext/315077059/port.o ${OBJECTDIR}/_ext/315077059/port_asm.o ${OBJECTDIR}/_ext/1504750355/croutine.o ${OBJECTDIR}/_ext/1504750355/list.o ${OBJECTDIR}/_ext/1504750355/queue.o ${OBJECTDIR}/_ext/1504750355/tasks.o ${OBJECTDIR}/_ext/1504750355/timers.o ${OBJECTDIR}/_ext/1504750355/event_groups.o ${OBJECTDIR}/_ext/1504750355/stream_buffer.o ${OBJECTDIR}/_ext/1048187810/sensor.o ${OBJECTDIR}/_ext/1048187810/sensor_debug.o ${OBJECTDIR}/_ext/1048187810/sensor_drivers.o

# Source Files
SOURCEFILES=../../Milestone1/firmware/src/system_config/default/bsp/bsp.c ../../Milestone1/firmware/src/system_config/default/framework/driver/adc/src/drv_adc_static.c ../../Milestone1/firmware/src/system_config/default/framework/driver/tmr/src/drv_tmr_static.c ../../Milestone1/firmware/src/system_config/default/framework/driver/tmr/src/drv_tmr_mapping.c ../../Milestone1/firmware/src/system_config/default/framework/driver/usart/src/drv_usart_mapping.c ../../Milestone1/firmware/src/system_config/default/framework/driver/usart/src/drv_usart_static.c ../../Milestone1/firmware/src/system_config/default/framework/driver/usart/src/drv_usart_static_byte_model.c ../../Milestone1/firmware/src/system_config/default/framework/system/clk/src/sys_clk_pic32mx.c ../../Milestone1/firmware/src/system_config/default/framework/system/devcon/src/sys_devcon.c ../../Milestone1/firmware/src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mx.c ../../Milestone1/firmware/src/system_config/default/framework/system/ports/src/sys_ports_static.c ../../Milestone1/firmware/src/system_config/default/system_init.c ../../Milestone1/firmware/src/system_config/default/system_interrupt.c ../../Milestone1/firmware/src/system_config/default/system_exceptions.c ../../Milestone1/firmware/src/system_config/default/system_tasks.c ../../Milestone1/firmware/src/system_config/default/system_interrupt_a.S ../../Milestone1/firmware/src/system_config/default/rtos_hooks.c ../../Milestone1/firmware/src/appThread.c ../../Milestone1/firmware/src/main.c ../../../../../../../microchip/harmony/v2_06/framework/osal/src/osal_freertos.c ../../../../../../../microchip/harmony/v2_06/framework/system/int/src/sys_int_pic32.c ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MemMang/heap_1.c ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX/port.c ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX/port_asm.S ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/croutine.c ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/list.c ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/queue.c ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/tasks.c ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/timers.c ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/event_groups.c ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/stream_buffer.c ../../Milestone1/firmware/src/sensor.c ../../Milestone1/firmware/src/sensor_debug.c ../../Milestone1/firmware/src/sensor_drivers.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Sensors.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX795F512L
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/950918765/system_interrupt_a.o: ../../Milestone1/firmware/src/system_config/default/system_interrupt_a.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/950918765" 
	@${RM} ${OBJECTDIR}/_ext/950918765/system_interrupt_a.o.d 
	@${RM} ${OBJECTDIR}/_ext/950918765/system_interrupt_a.o 
	@${RM} ${OBJECTDIR}/_ext/950918765/system_interrupt_a.o.ok ${OBJECTDIR}/_ext/950918765/system_interrupt_a.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/950918765/system_interrupt_a.o.d" "${OBJECTDIR}/_ext/950918765/system_interrupt_a.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC} $(MP_EXTRA_AS_PRE)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/950918765/system_interrupt_a.o.d"  -o ${OBJECTDIR}/_ext/950918765/system_interrupt_a.o ../../Milestone1/firmware/src/system_config/default/system_interrupt_a.S  -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/_ext/950918765/system_interrupt_a.o.asm.d",--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--gdwarf-2,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1
	
${OBJECTDIR}/_ext/315077059/port_asm.o: ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX/port_asm.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/315077059" 
	@${RM} ${OBJECTDIR}/_ext/315077059/port_asm.o.d 
	@${RM} ${OBJECTDIR}/_ext/315077059/port_asm.o 
	@${RM} ${OBJECTDIR}/_ext/315077059/port_asm.o.ok ${OBJECTDIR}/_ext/315077059/port_asm.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/315077059/port_asm.o.d" "${OBJECTDIR}/_ext/315077059/port_asm.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC} $(MP_EXTRA_AS_PRE)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/315077059/port_asm.o.d"  -o ${OBJECTDIR}/_ext/315077059/port_asm.o ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX/port_asm.S  -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/_ext/315077059/port_asm.o.asm.d",--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--gdwarf-2,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1
	
else
${OBJECTDIR}/_ext/950918765/system_interrupt_a.o: ../../Milestone1/firmware/src/system_config/default/system_interrupt_a.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/950918765" 
	@${RM} ${OBJECTDIR}/_ext/950918765/system_interrupt_a.o.d 
	@${RM} ${OBJECTDIR}/_ext/950918765/system_interrupt_a.o 
	@${RM} ${OBJECTDIR}/_ext/950918765/system_interrupt_a.o.ok ${OBJECTDIR}/_ext/950918765/system_interrupt_a.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/950918765/system_interrupt_a.o.d" "${OBJECTDIR}/_ext/950918765/system_interrupt_a.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC} $(MP_EXTRA_AS_PRE)  -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/950918765/system_interrupt_a.o.d"  -o ${OBJECTDIR}/_ext/950918765/system_interrupt_a.o ../../Milestone1/firmware/src/system_config/default/system_interrupt_a.S  -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/_ext/950918765/system_interrupt_a.o.asm.d"
	
${OBJECTDIR}/_ext/315077059/port_asm.o: ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX/port_asm.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/315077059" 
	@${RM} ${OBJECTDIR}/_ext/315077059/port_asm.o.d 
	@${RM} ${OBJECTDIR}/_ext/315077059/port_asm.o 
	@${RM} ${OBJECTDIR}/_ext/315077059/port_asm.o.ok ${OBJECTDIR}/_ext/315077059/port_asm.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/315077059/port_asm.o.d" "${OBJECTDIR}/_ext/315077059/port_asm.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC} $(MP_EXTRA_AS_PRE)  -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/315077059/port_asm.o.d"  -o ${OBJECTDIR}/_ext/315077059/port_asm.o ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX/port_asm.S  -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/_ext/315077059/port_asm.o.asm.d"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1484260413/bsp.o: ../../Milestone1/firmware/src/system_config/default/bsp/bsp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1484260413" 
	@${RM} ${OBJECTDIR}/_ext/1484260413/bsp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1484260413/bsp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1484260413/bsp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1484260413/bsp.o.d" -o ${OBJECTDIR}/_ext/1484260413/bsp.o ../../Milestone1/firmware/src/system_config/default/bsp/bsp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/880468539/drv_adc_static.o: ../../Milestone1/firmware/src/system_config/default/framework/driver/adc/src/drv_adc_static.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/880468539" 
	@${RM} ${OBJECTDIR}/_ext/880468539/drv_adc_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/880468539/drv_adc_static.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/880468539/drv_adc_static.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/880468539/drv_adc_static.o.d" -o ${OBJECTDIR}/_ext/880468539/drv_adc_static.o ../../Milestone1/firmware/src/system_config/default/framework/driver/adc/src/drv_adc_static.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/834684468/drv_tmr_static.o: ../../Milestone1/firmware/src/system_config/default/framework/driver/tmr/src/drv_tmr_static.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/834684468" 
	@${RM} ${OBJECTDIR}/_ext/834684468/drv_tmr_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/834684468/drv_tmr_static.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/834684468/drv_tmr_static.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/834684468/drv_tmr_static.o.d" -o ${OBJECTDIR}/_ext/834684468/drv_tmr_static.o ../../Milestone1/firmware/src/system_config/default/framework/driver/tmr/src/drv_tmr_static.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/834684468/drv_tmr_mapping.o: ../../Milestone1/firmware/src/system_config/default/framework/driver/tmr/src/drv_tmr_mapping.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/834684468" 
	@${RM} ${OBJECTDIR}/_ext/834684468/drv_tmr_mapping.o.d 
	@${RM} ${OBJECTDIR}/_ext/834684468/drv_tmr_mapping.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/834684468/drv_tmr_mapping.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/834684468/drv_tmr_mapping.o.d" -o ${OBJECTDIR}/_ext/834684468/drv_tmr_mapping.o ../../Milestone1/firmware/src/system_config/default/framework/driver/tmr/src/drv_tmr_mapping.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1253198688/drv_usart_mapping.o: ../../Milestone1/firmware/src/system_config/default/framework/driver/usart/src/drv_usart_mapping.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1253198688" 
	@${RM} ${OBJECTDIR}/_ext/1253198688/drv_usart_mapping.o.d 
	@${RM} ${OBJECTDIR}/_ext/1253198688/drv_usart_mapping.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1253198688/drv_usart_mapping.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1253198688/drv_usart_mapping.o.d" -o ${OBJECTDIR}/_ext/1253198688/drv_usart_mapping.o ../../Milestone1/firmware/src/system_config/default/framework/driver/usart/src/drv_usart_mapping.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1253198688/drv_usart_static.o: ../../Milestone1/firmware/src/system_config/default/framework/driver/usart/src/drv_usart_static.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1253198688" 
	@${RM} ${OBJECTDIR}/_ext/1253198688/drv_usart_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/1253198688/drv_usart_static.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1253198688/drv_usart_static.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1253198688/drv_usart_static.o.d" -o ${OBJECTDIR}/_ext/1253198688/drv_usart_static.o ../../Milestone1/firmware/src/system_config/default/framework/driver/usart/src/drv_usart_static.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1253198688/drv_usart_static_byte_model.o: ../../Milestone1/firmware/src/system_config/default/framework/driver/usart/src/drv_usart_static_byte_model.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1253198688" 
	@${RM} ${OBJECTDIR}/_ext/1253198688/drv_usart_static_byte_model.o.d 
	@${RM} ${OBJECTDIR}/_ext/1253198688/drv_usart_static_byte_model.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1253198688/drv_usart_static_byte_model.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1253198688/drv_usart_static_byte_model.o.d" -o ${OBJECTDIR}/_ext/1253198688/drv_usart_static_byte_model.o ../../Milestone1/firmware/src/system_config/default/framework/driver/usart/src/drv_usart_static_byte_model.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1413235516/sys_clk_pic32mx.o: ../../Milestone1/firmware/src/system_config/default/framework/system/clk/src/sys_clk_pic32mx.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1413235516" 
	@${RM} ${OBJECTDIR}/_ext/1413235516/sys_clk_pic32mx.o.d 
	@${RM} ${OBJECTDIR}/_ext/1413235516/sys_clk_pic32mx.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1413235516/sys_clk_pic32mx.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1413235516/sys_clk_pic32mx.o.d" -o ${OBJECTDIR}/_ext/1413235516/sys_clk_pic32mx.o ../../Milestone1/firmware/src/system_config/default/framework/system/clk/src/sys_clk_pic32mx.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/2082105931/sys_devcon.o: ../../Milestone1/firmware/src/system_config/default/framework/system/devcon/src/sys_devcon.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2082105931" 
	@${RM} ${OBJECTDIR}/_ext/2082105931/sys_devcon.o.d 
	@${RM} ${OBJECTDIR}/_ext/2082105931/sys_devcon.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2082105931/sys_devcon.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/2082105931/sys_devcon.o.d" -o ${OBJECTDIR}/_ext/2082105931/sys_devcon.o ../../Milestone1/firmware/src/system_config/default/framework/system/devcon/src/sys_devcon.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/2082105931/sys_devcon_pic32mx.o: ../../Milestone1/firmware/src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mx.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2082105931" 
	@${RM} ${OBJECTDIR}/_ext/2082105931/sys_devcon_pic32mx.o.d 
	@${RM} ${OBJECTDIR}/_ext/2082105931/sys_devcon_pic32mx.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2082105931/sys_devcon_pic32mx.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/2082105931/sys_devcon_pic32mx.o.d" -o ${OBJECTDIR}/_ext/2082105931/sys_devcon_pic32mx.o ../../Milestone1/firmware/src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mx.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1892719732/sys_ports_static.o: ../../Milestone1/firmware/src/system_config/default/framework/system/ports/src/sys_ports_static.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1892719732" 
	@${RM} ${OBJECTDIR}/_ext/1892719732/sys_ports_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/1892719732/sys_ports_static.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1892719732/sys_ports_static.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1892719732/sys_ports_static.o.d" -o ${OBJECTDIR}/_ext/1892719732/sys_ports_static.o ../../Milestone1/firmware/src/system_config/default/framework/system/ports/src/sys_ports_static.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/950918765/system_init.o: ../../Milestone1/firmware/src/system_config/default/system_init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/950918765" 
	@${RM} ${OBJECTDIR}/_ext/950918765/system_init.o.d 
	@${RM} ${OBJECTDIR}/_ext/950918765/system_init.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/950918765/system_init.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/950918765/system_init.o.d" -o ${OBJECTDIR}/_ext/950918765/system_init.o ../../Milestone1/firmware/src/system_config/default/system_init.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/950918765/system_interrupt.o: ../../Milestone1/firmware/src/system_config/default/system_interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/950918765" 
	@${RM} ${OBJECTDIR}/_ext/950918765/system_interrupt.o.d 
	@${RM} ${OBJECTDIR}/_ext/950918765/system_interrupt.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/950918765/system_interrupt.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/950918765/system_interrupt.o.d" -o ${OBJECTDIR}/_ext/950918765/system_interrupt.o ../../Milestone1/firmware/src/system_config/default/system_interrupt.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/950918765/system_exceptions.o: ../../Milestone1/firmware/src/system_config/default/system_exceptions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/950918765" 
	@${RM} ${OBJECTDIR}/_ext/950918765/system_exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/950918765/system_exceptions.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/950918765/system_exceptions.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/950918765/system_exceptions.o.d" -o ${OBJECTDIR}/_ext/950918765/system_exceptions.o ../../Milestone1/firmware/src/system_config/default/system_exceptions.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/950918765/system_tasks.o: ../../Milestone1/firmware/src/system_config/default/system_tasks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/950918765" 
	@${RM} ${OBJECTDIR}/_ext/950918765/system_tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/950918765/system_tasks.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/950918765/system_tasks.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/950918765/system_tasks.o.d" -o ${OBJECTDIR}/_ext/950918765/system_tasks.o ../../Milestone1/firmware/src/system_config/default/system_tasks.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/950918765/rtos_hooks.o: ../../Milestone1/firmware/src/system_config/default/rtos_hooks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/950918765" 
	@${RM} ${OBJECTDIR}/_ext/950918765/rtos_hooks.o.d 
	@${RM} ${OBJECTDIR}/_ext/950918765/rtos_hooks.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/950918765/rtos_hooks.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/950918765/rtos_hooks.o.d" -o ${OBJECTDIR}/_ext/950918765/rtos_hooks.o ../../Milestone1/firmware/src/system_config/default/rtos_hooks.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1048187810/appThread.o: ../../Milestone1/firmware/src/appThread.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1048187810" 
	@${RM} ${OBJECTDIR}/_ext/1048187810/appThread.o.d 
	@${RM} ${OBJECTDIR}/_ext/1048187810/appThread.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1048187810/appThread.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1048187810/appThread.o.d" -o ${OBJECTDIR}/_ext/1048187810/appThread.o ../../Milestone1/firmware/src/appThread.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1048187810/main.o: ../../Milestone1/firmware/src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1048187810" 
	@${RM} ${OBJECTDIR}/_ext/1048187810/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1048187810/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1048187810/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1048187810/main.o.d" -o ${OBJECTDIR}/_ext/1048187810/main.o ../../Milestone1/firmware/src/main.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/400469038/osal_freertos.o: ../../../../../../../microchip/harmony/v2_06/framework/osal/src/osal_freertos.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/400469038" 
	@${RM} ${OBJECTDIR}/_ext/400469038/osal_freertos.o.d 
	@${RM} ${OBJECTDIR}/_ext/400469038/osal_freertos.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/400469038/osal_freertos.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/400469038/osal_freertos.o.d" -o ${OBJECTDIR}/_ext/400469038/osal_freertos.o ../../../../../../../microchip/harmony/v2_06/framework/osal/src/osal_freertos.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1020727214/sys_int_pic32.o: ../../../../../../../microchip/harmony/v2_06/framework/system/int/src/sys_int_pic32.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1020727214" 
	@${RM} ${OBJECTDIR}/_ext/1020727214/sys_int_pic32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1020727214/sys_int_pic32.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1020727214/sys_int_pic32.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1020727214/sys_int_pic32.o.d" -o ${OBJECTDIR}/_ext/1020727214/sys_int_pic32.o ../../../../../../../microchip/harmony/v2_06/framework/system/int/src/sys_int_pic32.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/33242672/heap_1.o: ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MemMang/heap_1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/33242672" 
	@${RM} ${OBJECTDIR}/_ext/33242672/heap_1.o.d 
	@${RM} ${OBJECTDIR}/_ext/33242672/heap_1.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/33242672/heap_1.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/33242672/heap_1.o.d" -o ${OBJECTDIR}/_ext/33242672/heap_1.o ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MemMang/heap_1.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/315077059/port.o: ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX/port.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/315077059" 
	@${RM} ${OBJECTDIR}/_ext/315077059/port.o.d 
	@${RM} ${OBJECTDIR}/_ext/315077059/port.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/315077059/port.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/315077059/port.o.d" -o ${OBJECTDIR}/_ext/315077059/port.o ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX/port.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1504750355/croutine.o: ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/croutine.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1504750355" 
	@${RM} ${OBJECTDIR}/_ext/1504750355/croutine.o.d 
	@${RM} ${OBJECTDIR}/_ext/1504750355/croutine.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1504750355/croutine.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1504750355/croutine.o.d" -o ${OBJECTDIR}/_ext/1504750355/croutine.o ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/croutine.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1504750355/list.o: ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/list.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1504750355" 
	@${RM} ${OBJECTDIR}/_ext/1504750355/list.o.d 
	@${RM} ${OBJECTDIR}/_ext/1504750355/list.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1504750355/list.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1504750355/list.o.d" -o ${OBJECTDIR}/_ext/1504750355/list.o ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/list.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1504750355/queue.o: ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/queue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1504750355" 
	@${RM} ${OBJECTDIR}/_ext/1504750355/queue.o.d 
	@${RM} ${OBJECTDIR}/_ext/1504750355/queue.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1504750355/queue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1504750355/queue.o.d" -o ${OBJECTDIR}/_ext/1504750355/queue.o ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/queue.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1504750355/tasks.o: ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/tasks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1504750355" 
	@${RM} ${OBJECTDIR}/_ext/1504750355/tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/1504750355/tasks.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1504750355/tasks.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1504750355/tasks.o.d" -o ${OBJECTDIR}/_ext/1504750355/tasks.o ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/tasks.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1504750355/timers.o: ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/timers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1504750355" 
	@${RM} ${OBJECTDIR}/_ext/1504750355/timers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1504750355/timers.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1504750355/timers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1504750355/timers.o.d" -o ${OBJECTDIR}/_ext/1504750355/timers.o ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/timers.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1504750355/event_groups.o: ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/event_groups.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1504750355" 
	@${RM} ${OBJECTDIR}/_ext/1504750355/event_groups.o.d 
	@${RM} ${OBJECTDIR}/_ext/1504750355/event_groups.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1504750355/event_groups.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1504750355/event_groups.o.d" -o ${OBJECTDIR}/_ext/1504750355/event_groups.o ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/event_groups.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1504750355/stream_buffer.o: ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/stream_buffer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1504750355" 
	@${RM} ${OBJECTDIR}/_ext/1504750355/stream_buffer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1504750355/stream_buffer.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1504750355/stream_buffer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1504750355/stream_buffer.o.d" -o ${OBJECTDIR}/_ext/1504750355/stream_buffer.o ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/stream_buffer.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1048187810/sensor.o: ../../Milestone1/firmware/src/sensor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1048187810" 
	@${RM} ${OBJECTDIR}/_ext/1048187810/sensor.o.d 
	@${RM} ${OBJECTDIR}/_ext/1048187810/sensor.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1048187810/sensor.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1048187810/sensor.o.d" -o ${OBJECTDIR}/_ext/1048187810/sensor.o ../../Milestone1/firmware/src/sensor.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1048187810/sensor_debug.o: ../../Milestone1/firmware/src/sensor_debug.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1048187810" 
	@${RM} ${OBJECTDIR}/_ext/1048187810/sensor_debug.o.d 
	@${RM} ${OBJECTDIR}/_ext/1048187810/sensor_debug.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1048187810/sensor_debug.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1048187810/sensor_debug.o.d" -o ${OBJECTDIR}/_ext/1048187810/sensor_debug.o ../../Milestone1/firmware/src/sensor_debug.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1048187810/sensor_drivers.o: ../../Milestone1/firmware/src/sensor_drivers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1048187810" 
	@${RM} ${OBJECTDIR}/_ext/1048187810/sensor_drivers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1048187810/sensor_drivers.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1048187810/sensor_drivers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1048187810/sensor_drivers.o.d" -o ${OBJECTDIR}/_ext/1048187810/sensor_drivers.o ../../Milestone1/firmware/src/sensor_drivers.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/_ext/1484260413/bsp.o: ../../Milestone1/firmware/src/system_config/default/bsp/bsp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1484260413" 
	@${RM} ${OBJECTDIR}/_ext/1484260413/bsp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1484260413/bsp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1484260413/bsp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1484260413/bsp.o.d" -o ${OBJECTDIR}/_ext/1484260413/bsp.o ../../Milestone1/firmware/src/system_config/default/bsp/bsp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/880468539/drv_adc_static.o: ../../Milestone1/firmware/src/system_config/default/framework/driver/adc/src/drv_adc_static.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/880468539" 
	@${RM} ${OBJECTDIR}/_ext/880468539/drv_adc_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/880468539/drv_adc_static.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/880468539/drv_adc_static.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/880468539/drv_adc_static.o.d" -o ${OBJECTDIR}/_ext/880468539/drv_adc_static.o ../../Milestone1/firmware/src/system_config/default/framework/driver/adc/src/drv_adc_static.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/834684468/drv_tmr_static.o: ../../Milestone1/firmware/src/system_config/default/framework/driver/tmr/src/drv_tmr_static.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/834684468" 
	@${RM} ${OBJECTDIR}/_ext/834684468/drv_tmr_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/834684468/drv_tmr_static.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/834684468/drv_tmr_static.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/834684468/drv_tmr_static.o.d" -o ${OBJECTDIR}/_ext/834684468/drv_tmr_static.o ../../Milestone1/firmware/src/system_config/default/framework/driver/tmr/src/drv_tmr_static.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/834684468/drv_tmr_mapping.o: ../../Milestone1/firmware/src/system_config/default/framework/driver/tmr/src/drv_tmr_mapping.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/834684468" 
	@${RM} ${OBJECTDIR}/_ext/834684468/drv_tmr_mapping.o.d 
	@${RM} ${OBJECTDIR}/_ext/834684468/drv_tmr_mapping.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/834684468/drv_tmr_mapping.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/834684468/drv_tmr_mapping.o.d" -o ${OBJECTDIR}/_ext/834684468/drv_tmr_mapping.o ../../Milestone1/firmware/src/system_config/default/framework/driver/tmr/src/drv_tmr_mapping.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1253198688/drv_usart_mapping.o: ../../Milestone1/firmware/src/system_config/default/framework/driver/usart/src/drv_usart_mapping.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1253198688" 
	@${RM} ${OBJECTDIR}/_ext/1253198688/drv_usart_mapping.o.d 
	@${RM} ${OBJECTDIR}/_ext/1253198688/drv_usart_mapping.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1253198688/drv_usart_mapping.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1253198688/drv_usart_mapping.o.d" -o ${OBJECTDIR}/_ext/1253198688/drv_usart_mapping.o ../../Milestone1/firmware/src/system_config/default/framework/driver/usart/src/drv_usart_mapping.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1253198688/drv_usart_static.o: ../../Milestone1/firmware/src/system_config/default/framework/driver/usart/src/drv_usart_static.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1253198688" 
	@${RM} ${OBJECTDIR}/_ext/1253198688/drv_usart_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/1253198688/drv_usart_static.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1253198688/drv_usart_static.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1253198688/drv_usart_static.o.d" -o ${OBJECTDIR}/_ext/1253198688/drv_usart_static.o ../../Milestone1/firmware/src/system_config/default/framework/driver/usart/src/drv_usart_static.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1253198688/drv_usart_static_byte_model.o: ../../Milestone1/firmware/src/system_config/default/framework/driver/usart/src/drv_usart_static_byte_model.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1253198688" 
	@${RM} ${OBJECTDIR}/_ext/1253198688/drv_usart_static_byte_model.o.d 
	@${RM} ${OBJECTDIR}/_ext/1253198688/drv_usart_static_byte_model.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1253198688/drv_usart_static_byte_model.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1253198688/drv_usart_static_byte_model.o.d" -o ${OBJECTDIR}/_ext/1253198688/drv_usart_static_byte_model.o ../../Milestone1/firmware/src/system_config/default/framework/driver/usart/src/drv_usart_static_byte_model.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1413235516/sys_clk_pic32mx.o: ../../Milestone1/firmware/src/system_config/default/framework/system/clk/src/sys_clk_pic32mx.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1413235516" 
	@${RM} ${OBJECTDIR}/_ext/1413235516/sys_clk_pic32mx.o.d 
	@${RM} ${OBJECTDIR}/_ext/1413235516/sys_clk_pic32mx.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1413235516/sys_clk_pic32mx.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1413235516/sys_clk_pic32mx.o.d" -o ${OBJECTDIR}/_ext/1413235516/sys_clk_pic32mx.o ../../Milestone1/firmware/src/system_config/default/framework/system/clk/src/sys_clk_pic32mx.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/2082105931/sys_devcon.o: ../../Milestone1/firmware/src/system_config/default/framework/system/devcon/src/sys_devcon.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2082105931" 
	@${RM} ${OBJECTDIR}/_ext/2082105931/sys_devcon.o.d 
	@${RM} ${OBJECTDIR}/_ext/2082105931/sys_devcon.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2082105931/sys_devcon.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/2082105931/sys_devcon.o.d" -o ${OBJECTDIR}/_ext/2082105931/sys_devcon.o ../../Milestone1/firmware/src/system_config/default/framework/system/devcon/src/sys_devcon.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/2082105931/sys_devcon_pic32mx.o: ../../Milestone1/firmware/src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mx.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2082105931" 
	@${RM} ${OBJECTDIR}/_ext/2082105931/sys_devcon_pic32mx.o.d 
	@${RM} ${OBJECTDIR}/_ext/2082105931/sys_devcon_pic32mx.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2082105931/sys_devcon_pic32mx.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/2082105931/sys_devcon_pic32mx.o.d" -o ${OBJECTDIR}/_ext/2082105931/sys_devcon_pic32mx.o ../../Milestone1/firmware/src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mx.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1892719732/sys_ports_static.o: ../../Milestone1/firmware/src/system_config/default/framework/system/ports/src/sys_ports_static.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1892719732" 
	@${RM} ${OBJECTDIR}/_ext/1892719732/sys_ports_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/1892719732/sys_ports_static.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1892719732/sys_ports_static.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1892719732/sys_ports_static.o.d" -o ${OBJECTDIR}/_ext/1892719732/sys_ports_static.o ../../Milestone1/firmware/src/system_config/default/framework/system/ports/src/sys_ports_static.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/950918765/system_init.o: ../../Milestone1/firmware/src/system_config/default/system_init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/950918765" 
	@${RM} ${OBJECTDIR}/_ext/950918765/system_init.o.d 
	@${RM} ${OBJECTDIR}/_ext/950918765/system_init.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/950918765/system_init.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/950918765/system_init.o.d" -o ${OBJECTDIR}/_ext/950918765/system_init.o ../../Milestone1/firmware/src/system_config/default/system_init.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/950918765/system_interrupt.o: ../../Milestone1/firmware/src/system_config/default/system_interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/950918765" 
	@${RM} ${OBJECTDIR}/_ext/950918765/system_interrupt.o.d 
	@${RM} ${OBJECTDIR}/_ext/950918765/system_interrupt.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/950918765/system_interrupt.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/950918765/system_interrupt.o.d" -o ${OBJECTDIR}/_ext/950918765/system_interrupt.o ../../Milestone1/firmware/src/system_config/default/system_interrupt.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/950918765/system_exceptions.o: ../../Milestone1/firmware/src/system_config/default/system_exceptions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/950918765" 
	@${RM} ${OBJECTDIR}/_ext/950918765/system_exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/950918765/system_exceptions.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/950918765/system_exceptions.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/950918765/system_exceptions.o.d" -o ${OBJECTDIR}/_ext/950918765/system_exceptions.o ../../Milestone1/firmware/src/system_config/default/system_exceptions.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/950918765/system_tasks.o: ../../Milestone1/firmware/src/system_config/default/system_tasks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/950918765" 
	@${RM} ${OBJECTDIR}/_ext/950918765/system_tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/950918765/system_tasks.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/950918765/system_tasks.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/950918765/system_tasks.o.d" -o ${OBJECTDIR}/_ext/950918765/system_tasks.o ../../Milestone1/firmware/src/system_config/default/system_tasks.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/950918765/rtos_hooks.o: ../../Milestone1/firmware/src/system_config/default/rtos_hooks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/950918765" 
	@${RM} ${OBJECTDIR}/_ext/950918765/rtos_hooks.o.d 
	@${RM} ${OBJECTDIR}/_ext/950918765/rtos_hooks.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/950918765/rtos_hooks.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/950918765/rtos_hooks.o.d" -o ${OBJECTDIR}/_ext/950918765/rtos_hooks.o ../../Milestone1/firmware/src/system_config/default/rtos_hooks.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1048187810/appThread.o: ../../Milestone1/firmware/src/appThread.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1048187810" 
	@${RM} ${OBJECTDIR}/_ext/1048187810/appThread.o.d 
	@${RM} ${OBJECTDIR}/_ext/1048187810/appThread.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1048187810/appThread.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1048187810/appThread.o.d" -o ${OBJECTDIR}/_ext/1048187810/appThread.o ../../Milestone1/firmware/src/appThread.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1048187810/main.o: ../../Milestone1/firmware/src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1048187810" 
	@${RM} ${OBJECTDIR}/_ext/1048187810/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1048187810/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1048187810/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1048187810/main.o.d" -o ${OBJECTDIR}/_ext/1048187810/main.o ../../Milestone1/firmware/src/main.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/400469038/osal_freertos.o: ../../../../../../../microchip/harmony/v2_06/framework/osal/src/osal_freertos.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/400469038" 
	@${RM} ${OBJECTDIR}/_ext/400469038/osal_freertos.o.d 
	@${RM} ${OBJECTDIR}/_ext/400469038/osal_freertos.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/400469038/osal_freertos.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/400469038/osal_freertos.o.d" -o ${OBJECTDIR}/_ext/400469038/osal_freertos.o ../../../../../../../microchip/harmony/v2_06/framework/osal/src/osal_freertos.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1020727214/sys_int_pic32.o: ../../../../../../../microchip/harmony/v2_06/framework/system/int/src/sys_int_pic32.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1020727214" 
	@${RM} ${OBJECTDIR}/_ext/1020727214/sys_int_pic32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1020727214/sys_int_pic32.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1020727214/sys_int_pic32.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1020727214/sys_int_pic32.o.d" -o ${OBJECTDIR}/_ext/1020727214/sys_int_pic32.o ../../../../../../../microchip/harmony/v2_06/framework/system/int/src/sys_int_pic32.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/33242672/heap_1.o: ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MemMang/heap_1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/33242672" 
	@${RM} ${OBJECTDIR}/_ext/33242672/heap_1.o.d 
	@${RM} ${OBJECTDIR}/_ext/33242672/heap_1.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/33242672/heap_1.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/33242672/heap_1.o.d" -o ${OBJECTDIR}/_ext/33242672/heap_1.o ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MemMang/heap_1.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/315077059/port.o: ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX/port.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/315077059" 
	@${RM} ${OBJECTDIR}/_ext/315077059/port.o.d 
	@${RM} ${OBJECTDIR}/_ext/315077059/port.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/315077059/port.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/315077059/port.o.d" -o ${OBJECTDIR}/_ext/315077059/port.o ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX/port.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1504750355/croutine.o: ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/croutine.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1504750355" 
	@${RM} ${OBJECTDIR}/_ext/1504750355/croutine.o.d 
	@${RM} ${OBJECTDIR}/_ext/1504750355/croutine.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1504750355/croutine.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1504750355/croutine.o.d" -o ${OBJECTDIR}/_ext/1504750355/croutine.o ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/croutine.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1504750355/list.o: ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/list.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1504750355" 
	@${RM} ${OBJECTDIR}/_ext/1504750355/list.o.d 
	@${RM} ${OBJECTDIR}/_ext/1504750355/list.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1504750355/list.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1504750355/list.o.d" -o ${OBJECTDIR}/_ext/1504750355/list.o ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/list.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1504750355/queue.o: ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/queue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1504750355" 
	@${RM} ${OBJECTDIR}/_ext/1504750355/queue.o.d 
	@${RM} ${OBJECTDIR}/_ext/1504750355/queue.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1504750355/queue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1504750355/queue.o.d" -o ${OBJECTDIR}/_ext/1504750355/queue.o ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/queue.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1504750355/tasks.o: ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/tasks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1504750355" 
	@${RM} ${OBJECTDIR}/_ext/1504750355/tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/1504750355/tasks.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1504750355/tasks.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1504750355/tasks.o.d" -o ${OBJECTDIR}/_ext/1504750355/tasks.o ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/tasks.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1504750355/timers.o: ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/timers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1504750355" 
	@${RM} ${OBJECTDIR}/_ext/1504750355/timers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1504750355/timers.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1504750355/timers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1504750355/timers.o.d" -o ${OBJECTDIR}/_ext/1504750355/timers.o ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/timers.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1504750355/event_groups.o: ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/event_groups.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1504750355" 
	@${RM} ${OBJECTDIR}/_ext/1504750355/event_groups.o.d 
	@${RM} ${OBJECTDIR}/_ext/1504750355/event_groups.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1504750355/event_groups.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1504750355/event_groups.o.d" -o ${OBJECTDIR}/_ext/1504750355/event_groups.o ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/event_groups.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1504750355/stream_buffer.o: ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/stream_buffer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1504750355" 
	@${RM} ${OBJECTDIR}/_ext/1504750355/stream_buffer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1504750355/stream_buffer.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1504750355/stream_buffer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1504750355/stream_buffer.o.d" -o ${OBJECTDIR}/_ext/1504750355/stream_buffer.o ../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/stream_buffer.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1048187810/sensor.o: ../../Milestone1/firmware/src/sensor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1048187810" 
	@${RM} ${OBJECTDIR}/_ext/1048187810/sensor.o.d 
	@${RM} ${OBJECTDIR}/_ext/1048187810/sensor.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1048187810/sensor.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1048187810/sensor.o.d" -o ${OBJECTDIR}/_ext/1048187810/sensor.o ../../Milestone1/firmware/src/sensor.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1048187810/sensor_debug.o: ../../Milestone1/firmware/src/sensor_debug.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1048187810" 
	@${RM} ${OBJECTDIR}/_ext/1048187810/sensor_debug.o.d 
	@${RM} ${OBJECTDIR}/_ext/1048187810/sensor_debug.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1048187810/sensor_debug.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1048187810/sensor_debug.o.d" -o ${OBJECTDIR}/_ext/1048187810/sensor_debug.o ../../Milestone1/firmware/src/sensor_debug.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1048187810/sensor_drivers.o: ../../Milestone1/firmware/src/sensor_drivers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1048187810" 
	@${RM} ${OBJECTDIR}/_ext/1048187810/sensor_drivers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1048187810/sensor_drivers.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1048187810/sensor_drivers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1048187810/sensor_drivers.o.d" -o ${OBJECTDIR}/_ext/1048187810/sensor_drivers.o ../../Milestone1/firmware/src/sensor_drivers.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Sensors.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ../../../../../../../../microchip/harmony/v2_06/bin/framework/peripheral/PIC32MX795F512L_peripherals.a  
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Sensors.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    ../../../../../../../../microchip/harmony/v2_06/bin/framework/peripheral/PIC32MX795F512L_peripherals.a      -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC02000:0x1FC02FEF -mreserve=boot@0x1FC02000:0x1FC024FF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_PK3=1,--defsym=_min_heap_size=0,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Sensors.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ../../../../../../../../microchip/harmony/v2_06/bin/framework/peripheral/PIC32MX795F512L_peripherals.a 
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Sensors.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    ../../../../../../../../microchip/harmony/v2_06/bin/framework/peripheral/PIC32MX795F512L_peripherals.a      -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=0,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	${MP_CC_DIR}/xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/Sensors.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
