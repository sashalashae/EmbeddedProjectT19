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
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/FSR.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/FSR.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=../src/sensor.c ../src/main.c ../src/RxThread.c ../src/TxThread.c ../src/RxISRQueue.c ../src/TxISRQueue.c ../src/TxThreadQueue.c ../src/fsr.c ../../../common/debug.c ../../../common/helper_functions.c ../../../common/jsmn.c ../../../common/queue_definitions.c ../../../../../../../../microchip/harmony/v2_06/framework/osal/src/osal_freertos.c ../../../../../../../../microchip/harmony/v2_06/framework/system/int/src/sys_int_pic32.c ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/croutine.c ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/list.c ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/queue.c ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/tasks.c ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/timers.c ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/event_groups.c ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/stream_buffer.c ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MemMang/heap_1.c ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX/port.c ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX/port_asm.S ../src/system_config/default/framework/driver/adc/src/drv_adc_static.c ../src/system_config/default/framework/driver/tmr/src/drv_tmr_static.c ../src/system_config/default/framework/driver/tmr/src/drv_tmr_mapping.c ../src/system_config/default/framework/driver/usart/src/drv_usart_mapping.c ../src/system_config/default/framework/driver/usart/src/drv_usart_static.c ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mx.c ../src/system_config/default/framework/system/devcon/src/sys_devcon.c ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mx.c ../src/system_config/default/framework/system/ports/src/sys_ports_static.c ../src/system_config/default/bsp/bsp.c ../src/system_config/default/system_init.c ../src/system_config/default/system_interrupt.c ../src/system_config/default/system_exceptions.c ../src/system_config/default/system_tasks.c ../src/system_config/default/system_interrupt_a.S ../src/system_config/default/rtos_hooks.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1360937237/sensor.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1360937237/RxThread.o ${OBJECTDIR}/_ext/1360937237/TxThread.o ${OBJECTDIR}/_ext/1360937237/RxISRQueue.o ${OBJECTDIR}/_ext/1360937237/TxISRQueue.o ${OBJECTDIR}/_ext/1360937237/TxThreadQueue.o ${OBJECTDIR}/_ext/1360937237/fsr.o ${OBJECTDIR}/_ext/907750266/debug.o ${OBJECTDIR}/_ext/907750266/helper_functions.o ${OBJECTDIR}/_ext/907750266/jsmn.o ${OBJECTDIR}/_ext/907750266/queue_definitions.o ${OBJECTDIR}/_ext/685969283/osal_freertos.o ${OBJECTDIR}/_ext/1872847683/sys_int_pic32.o ${OBJECTDIR}/_ext/1755465438/croutine.o ${OBJECTDIR}/_ext/1755465438/list.o ${OBJECTDIR}/_ext/1755465438/queue.o ${OBJECTDIR}/_ext/1755465438/tasks.o ${OBJECTDIR}/_ext/1755465438/timers.o ${OBJECTDIR}/_ext/1755465438/event_groups.o ${OBJECTDIR}/_ext/1755465438/stream_buffer.o ${OBJECTDIR}/_ext/1294454783/heap_1.o ${OBJECTDIR}/_ext/1671281964/port.o ${OBJECTDIR}/_ext/1671281964/port_asm.o ${OBJECTDIR}/_ext/1361460060/drv_adc_static.o ${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o ${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o ${OBJECTDIR}/_ext/327000265/drv_usart_mapping.o ${OBJECTDIR}/_ext/327000265/drv_usart_static.o ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o ${OBJECTDIR}/_ext/340578644/sys_devcon.o ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o ${OBJECTDIR}/_ext/822048611/sys_ports_static.o ${OBJECTDIR}/_ext/74298950/bsp.o ${OBJECTDIR}/_ext/1688732426/system_init.o ${OBJECTDIR}/_ext/1688732426/system_interrupt.o ${OBJECTDIR}/_ext/1688732426/system_exceptions.o ${OBJECTDIR}/_ext/1688732426/system_tasks.o ${OBJECTDIR}/_ext/1688732426/system_interrupt_a.o ${OBJECTDIR}/_ext/1688732426/rtos_hooks.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1360937237/sensor.o.d ${OBJECTDIR}/_ext/1360937237/main.o.d ${OBJECTDIR}/_ext/1360937237/RxThread.o.d ${OBJECTDIR}/_ext/1360937237/TxThread.o.d ${OBJECTDIR}/_ext/1360937237/RxISRQueue.o.d ${OBJECTDIR}/_ext/1360937237/TxISRQueue.o.d ${OBJECTDIR}/_ext/1360937237/TxThreadQueue.o.d ${OBJECTDIR}/_ext/1360937237/fsr.o.d ${OBJECTDIR}/_ext/907750266/debug.o.d ${OBJECTDIR}/_ext/907750266/helper_functions.o.d ${OBJECTDIR}/_ext/907750266/jsmn.o.d ${OBJECTDIR}/_ext/907750266/queue_definitions.o.d ${OBJECTDIR}/_ext/685969283/osal_freertos.o.d ${OBJECTDIR}/_ext/1872847683/sys_int_pic32.o.d ${OBJECTDIR}/_ext/1755465438/croutine.o.d ${OBJECTDIR}/_ext/1755465438/list.o.d ${OBJECTDIR}/_ext/1755465438/queue.o.d ${OBJECTDIR}/_ext/1755465438/tasks.o.d ${OBJECTDIR}/_ext/1755465438/timers.o.d ${OBJECTDIR}/_ext/1755465438/event_groups.o.d ${OBJECTDIR}/_ext/1755465438/stream_buffer.o.d ${OBJECTDIR}/_ext/1294454783/heap_1.o.d ${OBJECTDIR}/_ext/1671281964/port.o.d ${OBJECTDIR}/_ext/1671281964/port_asm.o.d ${OBJECTDIR}/_ext/1361460060/drv_adc_static.o.d ${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o.d ${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o.d ${OBJECTDIR}/_ext/327000265/drv_usart_mapping.o.d ${OBJECTDIR}/_ext/327000265/drv_usart_static.o.d ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o.d ${OBJECTDIR}/_ext/340578644/sys_devcon.o.d ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o.d ${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d ${OBJECTDIR}/_ext/74298950/bsp.o.d ${OBJECTDIR}/_ext/1688732426/system_init.o.d ${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d ${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d ${OBJECTDIR}/_ext/1688732426/system_tasks.o.d ${OBJECTDIR}/_ext/1688732426/system_interrupt_a.o.d ${OBJECTDIR}/_ext/1688732426/rtos_hooks.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1360937237/sensor.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1360937237/RxThread.o ${OBJECTDIR}/_ext/1360937237/TxThread.o ${OBJECTDIR}/_ext/1360937237/RxISRQueue.o ${OBJECTDIR}/_ext/1360937237/TxISRQueue.o ${OBJECTDIR}/_ext/1360937237/TxThreadQueue.o ${OBJECTDIR}/_ext/1360937237/fsr.o ${OBJECTDIR}/_ext/907750266/debug.o ${OBJECTDIR}/_ext/907750266/helper_functions.o ${OBJECTDIR}/_ext/907750266/jsmn.o ${OBJECTDIR}/_ext/907750266/queue_definitions.o ${OBJECTDIR}/_ext/685969283/osal_freertos.o ${OBJECTDIR}/_ext/1872847683/sys_int_pic32.o ${OBJECTDIR}/_ext/1755465438/croutine.o ${OBJECTDIR}/_ext/1755465438/list.o ${OBJECTDIR}/_ext/1755465438/queue.o ${OBJECTDIR}/_ext/1755465438/tasks.o ${OBJECTDIR}/_ext/1755465438/timers.o ${OBJECTDIR}/_ext/1755465438/event_groups.o ${OBJECTDIR}/_ext/1755465438/stream_buffer.o ${OBJECTDIR}/_ext/1294454783/heap_1.o ${OBJECTDIR}/_ext/1671281964/port.o ${OBJECTDIR}/_ext/1671281964/port_asm.o ${OBJECTDIR}/_ext/1361460060/drv_adc_static.o ${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o ${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o ${OBJECTDIR}/_ext/327000265/drv_usart_mapping.o ${OBJECTDIR}/_ext/327000265/drv_usart_static.o ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o ${OBJECTDIR}/_ext/340578644/sys_devcon.o ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o ${OBJECTDIR}/_ext/822048611/sys_ports_static.o ${OBJECTDIR}/_ext/74298950/bsp.o ${OBJECTDIR}/_ext/1688732426/system_init.o ${OBJECTDIR}/_ext/1688732426/system_interrupt.o ${OBJECTDIR}/_ext/1688732426/system_exceptions.o ${OBJECTDIR}/_ext/1688732426/system_tasks.o ${OBJECTDIR}/_ext/1688732426/system_interrupt_a.o ${OBJECTDIR}/_ext/1688732426/rtos_hooks.o

# Source Files
SOURCEFILES=../src/sensor.c ../src/main.c ../src/RxThread.c ../src/TxThread.c ../src/RxISRQueue.c ../src/TxISRQueue.c ../src/TxThreadQueue.c ../src/fsr.c ../../../common/debug.c ../../../common/helper_functions.c ../../../common/jsmn.c ../../../common/queue_definitions.c ../../../../../../../../microchip/harmony/v2_06/framework/osal/src/osal_freertos.c ../../../../../../../../microchip/harmony/v2_06/framework/system/int/src/sys_int_pic32.c ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/croutine.c ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/list.c ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/queue.c ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/tasks.c ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/timers.c ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/event_groups.c ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/stream_buffer.c ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MemMang/heap_1.c ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX/port.c ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX/port_asm.S ../src/system_config/default/framework/driver/adc/src/drv_adc_static.c ../src/system_config/default/framework/driver/tmr/src/drv_tmr_static.c ../src/system_config/default/framework/driver/tmr/src/drv_tmr_mapping.c ../src/system_config/default/framework/driver/usart/src/drv_usart_mapping.c ../src/system_config/default/framework/driver/usart/src/drv_usart_static.c ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mx.c ../src/system_config/default/framework/system/devcon/src/sys_devcon.c ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mx.c ../src/system_config/default/framework/system/ports/src/sys_ports_static.c ../src/system_config/default/bsp/bsp.c ../src/system_config/default/system_init.c ../src/system_config/default/system_interrupt.c ../src/system_config/default/system_exceptions.c ../src/system_config/default/system_tasks.c ../src/system_config/default/system_interrupt_a.S ../src/system_config/default/rtos_hooks.c


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/FSR.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

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
${OBJECTDIR}/_ext/1671281964/port_asm.o: ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX/port_asm.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1671281964" 
	@${RM} ${OBJECTDIR}/_ext/1671281964/port_asm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1671281964/port_asm.o 
	@${RM} ${OBJECTDIR}/_ext/1671281964/port_asm.o.ok ${OBJECTDIR}/_ext/1671281964/port_asm.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1671281964/port_asm.o.d" "${OBJECTDIR}/_ext/1671281964/port_asm.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC} $(MP_EXTRA_AS_PRE)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"../src/system_config/default" -MMD -MF "${OBJECTDIR}/_ext/1671281964/port_asm.o.d"  -o ${OBJECTDIR}/_ext/1671281964/port_asm.o ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX/port_asm.S  -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/_ext/1671281964/port_asm.o.asm.d",--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--gdwarf-2,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"../src/system_config/default"
	
${OBJECTDIR}/_ext/1688732426/system_interrupt_a.o: ../src/system_config/default/system_interrupt_a.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_interrupt_a.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_interrupt_a.o 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_interrupt_a.o.ok ${OBJECTDIR}/_ext/1688732426/system_interrupt_a.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1688732426/system_interrupt_a.o.d" "${OBJECTDIR}/_ext/1688732426/system_interrupt_a.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC} $(MP_EXTRA_AS_PRE)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"../src/system_config/default" -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_interrupt_a.o.d"  -o ${OBJECTDIR}/_ext/1688732426/system_interrupt_a.o ../src/system_config/default/system_interrupt_a.S  -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/_ext/1688732426/system_interrupt_a.o.asm.d",--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--gdwarf-2,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"../src/system_config/default"
	
else
${OBJECTDIR}/_ext/1671281964/port_asm.o: ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX/port_asm.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1671281964" 
	@${RM} ${OBJECTDIR}/_ext/1671281964/port_asm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1671281964/port_asm.o 
	@${RM} ${OBJECTDIR}/_ext/1671281964/port_asm.o.ok ${OBJECTDIR}/_ext/1671281964/port_asm.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1671281964/port_asm.o.d" "${OBJECTDIR}/_ext/1671281964/port_asm.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC} $(MP_EXTRA_AS_PRE)  -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"../src/system_config/default" -MMD -MF "${OBJECTDIR}/_ext/1671281964/port_asm.o.d"  -o ${OBJECTDIR}/_ext/1671281964/port_asm.o ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX/port_asm.S  -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/_ext/1671281964/port_asm.o.asm.d",--gdwarf-2,-I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"../src/system_config/default"
	
${OBJECTDIR}/_ext/1688732426/system_interrupt_a.o: ../src/system_config/default/system_interrupt_a.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_interrupt_a.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_interrupt_a.o 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_interrupt_a.o.ok ${OBJECTDIR}/_ext/1688732426/system_interrupt_a.o.err 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1688732426/system_interrupt_a.o.d" "${OBJECTDIR}/_ext/1688732426/system_interrupt_a.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC} $(MP_EXTRA_AS_PRE)  -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"../src/system_config/default" -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_interrupt_a.o.d"  -o ${OBJECTDIR}/_ext/1688732426/system_interrupt_a.o ../src/system_config/default/system_interrupt_a.S  -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/_ext/1688732426/system_interrupt_a.o.asm.d",--gdwarf-2,-I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -I"../src/system_config/default"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1360937237/sensor.o: ../src/sensor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/sensor.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/sensor.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/sensor.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1360937237/sensor.o.d" -o ${OBJECTDIR}/_ext/1360937237/sensor.o ../src/sensor.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/RxThread.o: ../src/RxThread.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/RxThread.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/RxThread.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/RxThread.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1360937237/RxThread.o.d" -o ${OBJECTDIR}/_ext/1360937237/RxThread.o ../src/RxThread.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/TxThread.o: ../src/TxThread.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/TxThread.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/TxThread.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/TxThread.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1360937237/TxThread.o.d" -o ${OBJECTDIR}/_ext/1360937237/TxThread.o ../src/TxThread.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/RxISRQueue.o: ../src/RxISRQueue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/RxISRQueue.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/RxISRQueue.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/RxISRQueue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1360937237/RxISRQueue.o.d" -o ${OBJECTDIR}/_ext/1360937237/RxISRQueue.o ../src/RxISRQueue.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/TxISRQueue.o: ../src/TxISRQueue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/TxISRQueue.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/TxISRQueue.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/TxISRQueue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1360937237/TxISRQueue.o.d" -o ${OBJECTDIR}/_ext/1360937237/TxISRQueue.o ../src/TxISRQueue.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/TxThreadQueue.o: ../src/TxThreadQueue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/TxThreadQueue.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/TxThreadQueue.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/TxThreadQueue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1360937237/TxThreadQueue.o.d" -o ${OBJECTDIR}/_ext/1360937237/TxThreadQueue.o ../src/TxThreadQueue.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/fsr.o: ../src/fsr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/fsr.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/fsr.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/fsr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1360937237/fsr.o.d" -o ${OBJECTDIR}/_ext/1360937237/fsr.o ../src/fsr.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/907750266/debug.o: ../../../common/debug.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/907750266" 
	@${RM} ${OBJECTDIR}/_ext/907750266/debug.o.d 
	@${RM} ${OBJECTDIR}/_ext/907750266/debug.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/907750266/debug.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/907750266/debug.o.d" -o ${OBJECTDIR}/_ext/907750266/debug.o ../../../common/debug.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/907750266/helper_functions.o: ../../../common/helper_functions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/907750266" 
	@${RM} ${OBJECTDIR}/_ext/907750266/helper_functions.o.d 
	@${RM} ${OBJECTDIR}/_ext/907750266/helper_functions.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/907750266/helper_functions.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/907750266/helper_functions.o.d" -o ${OBJECTDIR}/_ext/907750266/helper_functions.o ../../../common/helper_functions.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/907750266/jsmn.o: ../../../common/jsmn.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/907750266" 
	@${RM} ${OBJECTDIR}/_ext/907750266/jsmn.o.d 
	@${RM} ${OBJECTDIR}/_ext/907750266/jsmn.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/907750266/jsmn.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/907750266/jsmn.o.d" -o ${OBJECTDIR}/_ext/907750266/jsmn.o ../../../common/jsmn.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/907750266/queue_definitions.o: ../../../common/queue_definitions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/907750266" 
	@${RM} ${OBJECTDIR}/_ext/907750266/queue_definitions.o.d 
	@${RM} ${OBJECTDIR}/_ext/907750266/queue_definitions.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/907750266/queue_definitions.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/907750266/queue_definitions.o.d" -o ${OBJECTDIR}/_ext/907750266/queue_definitions.o ../../../common/queue_definitions.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/685969283/osal_freertos.o: ../../../../../../../../microchip/harmony/v2_06/framework/osal/src/osal_freertos.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/685969283" 
	@${RM} ${OBJECTDIR}/_ext/685969283/osal_freertos.o.d 
	@${RM} ${OBJECTDIR}/_ext/685969283/osal_freertos.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/685969283/osal_freertos.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/685969283/osal_freertos.o.d" -o ${OBJECTDIR}/_ext/685969283/osal_freertos.o ../../../../../../../../microchip/harmony/v2_06/framework/osal/src/osal_freertos.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1872847683/sys_int_pic32.o: ../../../../../../../../microchip/harmony/v2_06/framework/system/int/src/sys_int_pic32.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1872847683" 
	@${RM} ${OBJECTDIR}/_ext/1872847683/sys_int_pic32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1872847683/sys_int_pic32.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1872847683/sys_int_pic32.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1872847683/sys_int_pic32.o.d" -o ${OBJECTDIR}/_ext/1872847683/sys_int_pic32.o ../../../../../../../../microchip/harmony/v2_06/framework/system/int/src/sys_int_pic32.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1755465438/croutine.o: ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/croutine.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1755465438" 
	@${RM} ${OBJECTDIR}/_ext/1755465438/croutine.o.d 
	@${RM} ${OBJECTDIR}/_ext/1755465438/croutine.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1755465438/croutine.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1755465438/croutine.o.d" -o ${OBJECTDIR}/_ext/1755465438/croutine.o ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/croutine.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1755465438/list.o: ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/list.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1755465438" 
	@${RM} ${OBJECTDIR}/_ext/1755465438/list.o.d 
	@${RM} ${OBJECTDIR}/_ext/1755465438/list.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1755465438/list.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1755465438/list.o.d" -o ${OBJECTDIR}/_ext/1755465438/list.o ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/list.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1755465438/queue.o: ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/queue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1755465438" 
	@${RM} ${OBJECTDIR}/_ext/1755465438/queue.o.d 
	@${RM} ${OBJECTDIR}/_ext/1755465438/queue.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1755465438/queue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1755465438/queue.o.d" -o ${OBJECTDIR}/_ext/1755465438/queue.o ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/queue.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1755465438/tasks.o: ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/tasks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1755465438" 
	@${RM} ${OBJECTDIR}/_ext/1755465438/tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/1755465438/tasks.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1755465438/tasks.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1755465438/tasks.o.d" -o ${OBJECTDIR}/_ext/1755465438/tasks.o ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/tasks.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1755465438/timers.o: ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/timers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1755465438" 
	@${RM} ${OBJECTDIR}/_ext/1755465438/timers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1755465438/timers.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1755465438/timers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1755465438/timers.o.d" -o ${OBJECTDIR}/_ext/1755465438/timers.o ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/timers.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1755465438/event_groups.o: ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/event_groups.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1755465438" 
	@${RM} ${OBJECTDIR}/_ext/1755465438/event_groups.o.d 
	@${RM} ${OBJECTDIR}/_ext/1755465438/event_groups.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1755465438/event_groups.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1755465438/event_groups.o.d" -o ${OBJECTDIR}/_ext/1755465438/event_groups.o ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/event_groups.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1755465438/stream_buffer.o: ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/stream_buffer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1755465438" 
	@${RM} ${OBJECTDIR}/_ext/1755465438/stream_buffer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1755465438/stream_buffer.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1755465438/stream_buffer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1755465438/stream_buffer.o.d" -o ${OBJECTDIR}/_ext/1755465438/stream_buffer.o ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/stream_buffer.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1294454783/heap_1.o: ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MemMang/heap_1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1294454783" 
	@${RM} ${OBJECTDIR}/_ext/1294454783/heap_1.o.d 
	@${RM} ${OBJECTDIR}/_ext/1294454783/heap_1.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1294454783/heap_1.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1294454783/heap_1.o.d" -o ${OBJECTDIR}/_ext/1294454783/heap_1.o ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MemMang/heap_1.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1671281964/port.o: ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX/port.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1671281964" 
	@${RM} ${OBJECTDIR}/_ext/1671281964/port.o.d 
	@${RM} ${OBJECTDIR}/_ext/1671281964/port.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1671281964/port.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1671281964/port.o.d" -o ${OBJECTDIR}/_ext/1671281964/port.o ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX/port.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1361460060/drv_adc_static.o: ../src/system_config/default/framework/driver/adc/src/drv_adc_static.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1361460060" 
	@${RM} ${OBJECTDIR}/_ext/1361460060/drv_adc_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/1361460060/drv_adc_static.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1361460060/drv_adc_static.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1361460060/drv_adc_static.o.d" -o ${OBJECTDIR}/_ext/1361460060/drv_adc_static.o ../src/system_config/default/framework/driver/adc/src/drv_adc_static.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o: ../src/system_config/default/framework/driver/tmr/src/drv_tmr_static.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1407244131" 
	@${RM} ${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o.d" -o ${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o ../src/system_config/default/framework/driver/tmr/src/drv_tmr_static.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o: ../src/system_config/default/framework/driver/tmr/src/drv_tmr_mapping.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1407244131" 
	@${RM} ${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o.d 
	@${RM} ${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o.d" -o ${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o ../src/system_config/default/framework/driver/tmr/src/drv_tmr_mapping.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/327000265/drv_usart_mapping.o: ../src/system_config/default/framework/driver/usart/src/drv_usart_mapping.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/327000265" 
	@${RM} ${OBJECTDIR}/_ext/327000265/drv_usart_mapping.o.d 
	@${RM} ${OBJECTDIR}/_ext/327000265/drv_usart_mapping.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/327000265/drv_usart_mapping.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/327000265/drv_usart_mapping.o.d" -o ${OBJECTDIR}/_ext/327000265/drv_usart_mapping.o ../src/system_config/default/framework/driver/usart/src/drv_usart_mapping.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/327000265/drv_usart_static.o: ../src/system_config/default/framework/driver/usart/src/drv_usart_static.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/327000265" 
	@${RM} ${OBJECTDIR}/_ext/327000265/drv_usart_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/327000265/drv_usart_static.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/327000265/drv_usart_static.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/327000265/drv_usart_static.o.d" -o ${OBJECTDIR}/_ext/327000265/drv_usart_static.o ../src/system_config/default/framework/driver/usart/src/drv_usart_static.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o: ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mx.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/639803181" 
	@${RM} ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o.d 
	@${RM} ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o.d" -o ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mx.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/340578644/sys_devcon.o: ../src/system_config/default/framework/system/devcon/src/sys_devcon.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/340578644" 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon.o.d 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/340578644/sys_devcon.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/340578644/sys_devcon.o.d" -o ${OBJECTDIR}/_ext/340578644/sys_devcon.o ../src/system_config/default/framework/system/devcon/src/sys_devcon.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o: ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mx.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/340578644" 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o.d 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o.d" -o ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mx.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/822048611/sys_ports_static.o: ../src/system_config/default/framework/system/ports/src/sys_ports_static.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/822048611" 
	@${RM} ${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/822048611/sys_ports_static.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d" -o ${OBJECTDIR}/_ext/822048611/sys_ports_static.o ../src/system_config/default/framework/system/ports/src/sys_ports_static.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/74298950/bsp.o: ../src/system_config/default/bsp/bsp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/74298950" 
	@${RM} ${OBJECTDIR}/_ext/74298950/bsp.o.d 
	@${RM} ${OBJECTDIR}/_ext/74298950/bsp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/74298950/bsp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/74298950/bsp.o.d" -o ${OBJECTDIR}/_ext/74298950/bsp.o ../src/system_config/default/bsp/bsp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1688732426/system_init.o: ../src/system_config/default/system_init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_init.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_init.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1688732426/system_init.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_init.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_init.o ../src/system_config/default/system_init.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1688732426/system_interrupt.o: ../src/system_config/default/system_interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_interrupt.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_interrupt.o ../src/system_config/default/system_interrupt.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1688732426/system_exceptions.o: ../src/system_config/default/system_exceptions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_exceptions.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_exceptions.o ../src/system_config/default/system_exceptions.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1688732426/system_tasks.o: ../src/system_config/default/system_tasks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_tasks.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1688732426/system_tasks.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_tasks.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_tasks.o ../src/system_config/default/system_tasks.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1688732426/rtos_hooks.o: ../src/system_config/default/rtos_hooks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/rtos_hooks.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/rtos_hooks.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1688732426/rtos_hooks.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1688732426/rtos_hooks.o.d" -o ${OBJECTDIR}/_ext/1688732426/rtos_hooks.o ../src/system_config/default/rtos_hooks.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/_ext/1360937237/sensor.o: ../src/sensor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/sensor.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/sensor.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/sensor.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1360937237/sensor.o.d" -o ${OBJECTDIR}/_ext/1360937237/sensor.o ../src/sensor.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/RxThread.o: ../src/RxThread.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/RxThread.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/RxThread.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/RxThread.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1360937237/RxThread.o.d" -o ${OBJECTDIR}/_ext/1360937237/RxThread.o ../src/RxThread.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/TxThread.o: ../src/TxThread.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/TxThread.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/TxThread.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/TxThread.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1360937237/TxThread.o.d" -o ${OBJECTDIR}/_ext/1360937237/TxThread.o ../src/TxThread.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/RxISRQueue.o: ../src/RxISRQueue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/RxISRQueue.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/RxISRQueue.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/RxISRQueue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1360937237/RxISRQueue.o.d" -o ${OBJECTDIR}/_ext/1360937237/RxISRQueue.o ../src/RxISRQueue.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/TxISRQueue.o: ../src/TxISRQueue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/TxISRQueue.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/TxISRQueue.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/TxISRQueue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1360937237/TxISRQueue.o.d" -o ${OBJECTDIR}/_ext/1360937237/TxISRQueue.o ../src/TxISRQueue.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/TxThreadQueue.o: ../src/TxThreadQueue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/TxThreadQueue.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/TxThreadQueue.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/TxThreadQueue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1360937237/TxThreadQueue.o.d" -o ${OBJECTDIR}/_ext/1360937237/TxThreadQueue.o ../src/TxThreadQueue.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/fsr.o: ../src/fsr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/fsr.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/fsr.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/fsr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1360937237/fsr.o.d" -o ${OBJECTDIR}/_ext/1360937237/fsr.o ../src/fsr.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/907750266/debug.o: ../../../common/debug.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/907750266" 
	@${RM} ${OBJECTDIR}/_ext/907750266/debug.o.d 
	@${RM} ${OBJECTDIR}/_ext/907750266/debug.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/907750266/debug.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/907750266/debug.o.d" -o ${OBJECTDIR}/_ext/907750266/debug.o ../../../common/debug.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/907750266/helper_functions.o: ../../../common/helper_functions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/907750266" 
	@${RM} ${OBJECTDIR}/_ext/907750266/helper_functions.o.d 
	@${RM} ${OBJECTDIR}/_ext/907750266/helper_functions.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/907750266/helper_functions.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/907750266/helper_functions.o.d" -o ${OBJECTDIR}/_ext/907750266/helper_functions.o ../../../common/helper_functions.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/907750266/jsmn.o: ../../../common/jsmn.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/907750266" 
	@${RM} ${OBJECTDIR}/_ext/907750266/jsmn.o.d 
	@${RM} ${OBJECTDIR}/_ext/907750266/jsmn.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/907750266/jsmn.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/907750266/jsmn.o.d" -o ${OBJECTDIR}/_ext/907750266/jsmn.o ../../../common/jsmn.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/907750266/queue_definitions.o: ../../../common/queue_definitions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/907750266" 
	@${RM} ${OBJECTDIR}/_ext/907750266/queue_definitions.o.d 
	@${RM} ${OBJECTDIR}/_ext/907750266/queue_definitions.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/907750266/queue_definitions.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/907750266/queue_definitions.o.d" -o ${OBJECTDIR}/_ext/907750266/queue_definitions.o ../../../common/queue_definitions.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/685969283/osal_freertos.o: ../../../../../../../../microchip/harmony/v2_06/framework/osal/src/osal_freertos.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/685969283" 
	@${RM} ${OBJECTDIR}/_ext/685969283/osal_freertos.o.d 
	@${RM} ${OBJECTDIR}/_ext/685969283/osal_freertos.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/685969283/osal_freertos.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/685969283/osal_freertos.o.d" -o ${OBJECTDIR}/_ext/685969283/osal_freertos.o ../../../../../../../../microchip/harmony/v2_06/framework/osal/src/osal_freertos.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1872847683/sys_int_pic32.o: ../../../../../../../../microchip/harmony/v2_06/framework/system/int/src/sys_int_pic32.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1872847683" 
	@${RM} ${OBJECTDIR}/_ext/1872847683/sys_int_pic32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1872847683/sys_int_pic32.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1872847683/sys_int_pic32.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1872847683/sys_int_pic32.o.d" -o ${OBJECTDIR}/_ext/1872847683/sys_int_pic32.o ../../../../../../../../microchip/harmony/v2_06/framework/system/int/src/sys_int_pic32.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1755465438/croutine.o: ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/croutine.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1755465438" 
	@${RM} ${OBJECTDIR}/_ext/1755465438/croutine.o.d 
	@${RM} ${OBJECTDIR}/_ext/1755465438/croutine.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1755465438/croutine.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1755465438/croutine.o.d" -o ${OBJECTDIR}/_ext/1755465438/croutine.o ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/croutine.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1755465438/list.o: ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/list.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1755465438" 
	@${RM} ${OBJECTDIR}/_ext/1755465438/list.o.d 
	@${RM} ${OBJECTDIR}/_ext/1755465438/list.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1755465438/list.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1755465438/list.o.d" -o ${OBJECTDIR}/_ext/1755465438/list.o ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/list.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1755465438/queue.o: ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/queue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1755465438" 
	@${RM} ${OBJECTDIR}/_ext/1755465438/queue.o.d 
	@${RM} ${OBJECTDIR}/_ext/1755465438/queue.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1755465438/queue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1755465438/queue.o.d" -o ${OBJECTDIR}/_ext/1755465438/queue.o ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/queue.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1755465438/tasks.o: ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/tasks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1755465438" 
	@${RM} ${OBJECTDIR}/_ext/1755465438/tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/1755465438/tasks.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1755465438/tasks.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1755465438/tasks.o.d" -o ${OBJECTDIR}/_ext/1755465438/tasks.o ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/tasks.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1755465438/timers.o: ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/timers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1755465438" 
	@${RM} ${OBJECTDIR}/_ext/1755465438/timers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1755465438/timers.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1755465438/timers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1755465438/timers.o.d" -o ${OBJECTDIR}/_ext/1755465438/timers.o ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/timers.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1755465438/event_groups.o: ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/event_groups.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1755465438" 
	@${RM} ${OBJECTDIR}/_ext/1755465438/event_groups.o.d 
	@${RM} ${OBJECTDIR}/_ext/1755465438/event_groups.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1755465438/event_groups.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1755465438/event_groups.o.d" -o ${OBJECTDIR}/_ext/1755465438/event_groups.o ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/event_groups.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1755465438/stream_buffer.o: ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/stream_buffer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1755465438" 
	@${RM} ${OBJECTDIR}/_ext/1755465438/stream_buffer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1755465438/stream_buffer.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1755465438/stream_buffer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1755465438/stream_buffer.o.d" -o ${OBJECTDIR}/_ext/1755465438/stream_buffer.o ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/stream_buffer.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1294454783/heap_1.o: ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MemMang/heap_1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1294454783" 
	@${RM} ${OBJECTDIR}/_ext/1294454783/heap_1.o.d 
	@${RM} ${OBJECTDIR}/_ext/1294454783/heap_1.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1294454783/heap_1.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1294454783/heap_1.o.d" -o ${OBJECTDIR}/_ext/1294454783/heap_1.o ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MemMang/heap_1.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1671281964/port.o: ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX/port.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1671281964" 
	@${RM} ${OBJECTDIR}/_ext/1671281964/port.o.d 
	@${RM} ${OBJECTDIR}/_ext/1671281964/port.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1671281964/port.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1671281964/port.o.d" -o ${OBJECTDIR}/_ext/1671281964/port.o ../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX/port.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1361460060/drv_adc_static.o: ../src/system_config/default/framework/driver/adc/src/drv_adc_static.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1361460060" 
	@${RM} ${OBJECTDIR}/_ext/1361460060/drv_adc_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/1361460060/drv_adc_static.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1361460060/drv_adc_static.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1361460060/drv_adc_static.o.d" -o ${OBJECTDIR}/_ext/1361460060/drv_adc_static.o ../src/system_config/default/framework/driver/adc/src/drv_adc_static.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o: ../src/system_config/default/framework/driver/tmr/src/drv_tmr_static.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1407244131" 
	@${RM} ${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o.d" -o ${OBJECTDIR}/_ext/1407244131/drv_tmr_static.o ../src/system_config/default/framework/driver/tmr/src/drv_tmr_static.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o: ../src/system_config/default/framework/driver/tmr/src/drv_tmr_mapping.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1407244131" 
	@${RM} ${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o.d 
	@${RM} ${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o.d" -o ${OBJECTDIR}/_ext/1407244131/drv_tmr_mapping.o ../src/system_config/default/framework/driver/tmr/src/drv_tmr_mapping.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/327000265/drv_usart_mapping.o: ../src/system_config/default/framework/driver/usart/src/drv_usart_mapping.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/327000265" 
	@${RM} ${OBJECTDIR}/_ext/327000265/drv_usart_mapping.o.d 
	@${RM} ${OBJECTDIR}/_ext/327000265/drv_usart_mapping.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/327000265/drv_usart_mapping.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/327000265/drv_usart_mapping.o.d" -o ${OBJECTDIR}/_ext/327000265/drv_usart_mapping.o ../src/system_config/default/framework/driver/usart/src/drv_usart_mapping.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/327000265/drv_usart_static.o: ../src/system_config/default/framework/driver/usart/src/drv_usart_static.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/327000265" 
	@${RM} ${OBJECTDIR}/_ext/327000265/drv_usart_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/327000265/drv_usart_static.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/327000265/drv_usart_static.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/327000265/drv_usart_static.o.d" -o ${OBJECTDIR}/_ext/327000265/drv_usart_static.o ../src/system_config/default/framework/driver/usart/src/drv_usart_static.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o: ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mx.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/639803181" 
	@${RM} ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o.d 
	@${RM} ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o.d" -o ${OBJECTDIR}/_ext/639803181/sys_clk_pic32mx.o ../src/system_config/default/framework/system/clk/src/sys_clk_pic32mx.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/340578644/sys_devcon.o: ../src/system_config/default/framework/system/devcon/src/sys_devcon.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/340578644" 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon.o.d 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/340578644/sys_devcon.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/340578644/sys_devcon.o.d" -o ${OBJECTDIR}/_ext/340578644/sys_devcon.o ../src/system_config/default/framework/system/devcon/src/sys_devcon.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o: ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mx.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/340578644" 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o.d 
	@${RM} ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o.d" -o ${OBJECTDIR}/_ext/340578644/sys_devcon_pic32mx.o ../src/system_config/default/framework/system/devcon/src/sys_devcon_pic32mx.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/822048611/sys_ports_static.o: ../src/system_config/default/framework/system/ports/src/sys_ports_static.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/822048611" 
	@${RM} ${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/822048611/sys_ports_static.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/822048611/sys_ports_static.o.d" -o ${OBJECTDIR}/_ext/822048611/sys_ports_static.o ../src/system_config/default/framework/system/ports/src/sys_ports_static.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/74298950/bsp.o: ../src/system_config/default/bsp/bsp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/74298950" 
	@${RM} ${OBJECTDIR}/_ext/74298950/bsp.o.d 
	@${RM} ${OBJECTDIR}/_ext/74298950/bsp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/74298950/bsp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/74298950/bsp.o.d" -o ${OBJECTDIR}/_ext/74298950/bsp.o ../src/system_config/default/bsp/bsp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1688732426/system_init.o: ../src/system_config/default/system_init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_init.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_init.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1688732426/system_init.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_init.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_init.o ../src/system_config/default/system_init.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1688732426/system_interrupt.o: ../src/system_config/default/system_interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_interrupt.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_interrupt.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_interrupt.o ../src/system_config/default/system_interrupt.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1688732426/system_exceptions.o: ../src/system_config/default/system_exceptions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_exceptions.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_exceptions.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_exceptions.o ../src/system_config/default/system_exceptions.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1688732426/system_tasks.o: ../src/system_config/default/system_tasks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/system_tasks.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1688732426/system_tasks.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1688732426/system_tasks.o.d" -o ${OBJECTDIR}/_ext/1688732426/system_tasks.o ../src/system_config/default/system_tasks.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1688732426/rtos_hooks.o: ../src/system_config/default/rtos_hooks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1688732426" 
	@${RM} ${OBJECTDIR}/_ext/1688732426/rtos_hooks.o.d 
	@${RM} ${OBJECTDIR}/_ext/1688732426/rtos_hooks.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1688732426/rtos_hooks.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -D__XC -I"../src" -I"../src/system_config/default" -I"../src/default" -I"../../../../../../../../microchip/harmony/v2_06/framework" -I"../src/system_config/default/framework" -I"../src/system_config/default/bsp" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/include" -I"../../../../../../../../microchip/harmony/v2_06/third_party/rtos/FreeRTOS/Source/portable/MPLAB/PIC32MX" -MMD -MF "${OBJECTDIR}/_ext/1688732426/rtos_hooks.o.d" -o ${OBJECTDIR}/_ext/1688732426/rtos_hooks.o ../src/system_config/default/rtos_hooks.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/FSR.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ../../../../../../../../microchip/harmony/v2_06/bin/framework/peripheral/PIC32MX795F512L_peripherals.a  
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/FSR.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    ..\..\..\..\..\..\..\..\microchip\harmony\v2_06\bin\framework\peripheral\PIC32MX795F512L_peripherals.a      -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC02000:0x1FC02FEF -mreserve=boot@0x1FC02000:0x1FC024FF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_PK3=1,--defsym=_min_heap_size=0,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/FSR.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ../../../../../../../../microchip/harmony/v2_06/bin/framework/peripheral/PIC32MX795F512L_peripherals.a 
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/FSR.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    ..\..\..\..\..\..\..\..\microchip\harmony\v2_06\bin\framework\peripheral\PIC32MX795F512L_peripherals.a      -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=0,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/FSR.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
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

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
