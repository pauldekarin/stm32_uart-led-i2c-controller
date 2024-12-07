
```
FTrade_proj
├─ .DS_Store
├─ .cproject
├─ .mxproject
├─ .project
├─ .settings
│  ├─ language.settings.xml
│  └─ org.eclipse.cdt.core.prefs
├─ Core
│  ├─ .DS_Store
│  ├─ Inc
│  │  ├─ gpio.h
│  │  ├─ i2c.h
│  │  ├─ main.h
│  │  ├─ stm32f1xx_hal_conf.h
│  │  ├─ stm32f1xx_it.h
│  │  ├─ tim.h
│  │  └─ usart.h
│  └─ Src
│     ├─ gpio.c
│     ├─ i2c.c
│     ├─ main.c
│     ├─ stm32f1xx_hal_msp.c
│     ├─ stm32f1xx_it.c
│     ├─ syscalls.c
│     ├─ sysmem.c
│     ├─ system_stm32f1xx.c
│     ├─ tim.c
│     └─ usart.c
├─ Drivers
│  ├─ .DS_Store
│  ├─ CMSIS
│  │  ├─ .DS_Store
│  │  ├─ Device
│  │  │  └─ ST
│  │  │     └─ STM32F1xx
│  │  │        ├─ Include
│  │  │        │  ├─ stm32f103xb.h
│  │  │        │  ├─ stm32f1xx.h
│  │  │        │  └─ system_stm32f1xx.h
│  │  │        ├─ LICENSE.txt
│  │  │        └─ Source
│  │  │           └─ Templates
│  │  ├─ Include
│  │  │  ├─ cmsis_armcc.h
│  │  │  ├─ cmsis_armclang.h
│  │  │  ├─ cmsis_compiler.h
│  │  │  ├─ cmsis_gcc.h
│  │  │  ├─ cmsis_iccarm.h
│  │  │  ├─ cmsis_version.h
│  │  │  ├─ core_armv8mbl.h
│  │  │  ├─ core_armv8mml.h
│  │  │  ├─ core_cm0.h
│  │  │  ├─ core_cm0plus.h
│  │  │  ├─ core_cm1.h
│  │  │  ├─ core_cm23.h
│  │  │  ├─ core_cm3.h
│  │  │  ├─ core_cm33.h
│  │  │  ├─ core_cm4.h
│  │  │  ├─ core_cm7.h
│  │  │  ├─ core_sc000.h
│  │  │  ├─ core_sc300.h
│  │  │  ├─ mpu_armv7.h
│  │  │  ├─ mpu_armv8.h
│  │  │  └─ tz_context.h
│  │  └─ LICENSE.txt
│  └─ STM32F1xx_HAL_Driver
│     ├─ .DS_Store
│     ├─ Inc
│     │  ├─ Legacy
│     │  │  └─ stm32_hal_legacy.h
│     │  ├─ stm32f1xx_hal.h
│     │  ├─ stm32f1xx_hal_cortex.h
│     │  ├─ stm32f1xx_hal_def.h
│     │  ├─ stm32f1xx_hal_dma.h
│     │  ├─ stm32f1xx_hal_dma_ex.h
│     │  ├─ stm32f1xx_hal_exti.h
│     │  ├─ stm32f1xx_hal_flash.h
│     │  ├─ stm32f1xx_hal_flash_ex.h
│     │  ├─ stm32f1xx_hal_gpio.h
│     │  ├─ stm32f1xx_hal_gpio_ex.h
│     │  ├─ stm32f1xx_hal_i2c.h
│     │  ├─ stm32f1xx_hal_pwr.h
│     │  ├─ stm32f1xx_hal_rcc.h
│     │  ├─ stm32f1xx_hal_rcc_ex.h
│     │  ├─ stm32f1xx_hal_tim.h
│     │  ├─ stm32f1xx_hal_tim_ex.h
│     │  ├─ stm32f1xx_hal_uart.h
│     │  ├─ stm32f1xx_ll_bus.h
│     │  ├─ stm32f1xx_ll_cortex.h
│     │  ├─ stm32f1xx_ll_dma.h
│     │  ├─ stm32f1xx_ll_exti.h
│     │  ├─ stm32f1xx_ll_gpio.h
│     │  ├─ stm32f1xx_ll_i2c.h
│     │  ├─ stm32f1xx_ll_pwr.h
│     │  ├─ stm32f1xx_ll_rcc.h
│     │  ├─ stm32f1xx_ll_system.h
│     │  ├─ stm32f1xx_ll_tim.h
│     │  ├─ stm32f1xx_ll_usart.h
│     │  └─ stm32f1xx_ll_utils.h
│     ├─ LICENSE.txt
│     └─ Src
│        ├─ stm32f1xx_hal.c
│        ├─ stm32f1xx_hal_cortex.c
│        ├─ stm32f1xx_hal_dma.c
│        ├─ stm32f1xx_hal_exti.c
│        ├─ stm32f1xx_hal_flash.c
│        ├─ stm32f1xx_hal_flash_ex.c
│        ├─ stm32f1xx_hal_gpio.c
│        ├─ stm32f1xx_hal_gpio_ex.c
│        ├─ stm32f1xx_hal_i2c.c
│        ├─ stm32f1xx_hal_pwr.c
│        ├─ stm32f1xx_hal_rcc.c
│        ├─ stm32f1xx_hal_rcc_ex.c
│        ├─ stm32f1xx_hal_tim.c
│        ├─ stm32f1xx_hal_tim_ex.c
│        └─ stm32f1xx_hal_uart.c
├─ FTrade_proj (1).launch
├─ FTrade_proj (3).launch
├─ FTrade_proj.ioc
├─ Makefile
├─ platforms
│  ├─ .DS_Store
│  └─ stm32f103.repl
├─ startup_stm32f103xb.s
├─ stm32_sumulation.resc
└─ stm32f103cbtx_flash.ld

```