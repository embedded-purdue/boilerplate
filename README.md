# boilerplate
Bare-metal programming framework that makes use of vendor-provided HALs. Designed for fast bring-up, hardware interfacing, and modular development in C/C++ for embedded systems.

### Purpose

boilerplate aims to be a starting point for bare-metal projets by striking a balance between bare-metal control, low-level understanding, and ease of development. By leveraging Cube-generated startup code and HALs, we avoid configuration overhead—yet preserve full flexibility to implement hardware drivers, real-time logic, and embedded patterns in clean C/C++.

It's ideal for:

1. Students learning embedded systems without the noise of an RTOS
2. Fast prototyping for STM32-based platforms
3. Teaching modular driver design and HAL integration

### Architecture
```
┌───────────┐         
│Application│         
└┬─┬────────┘         
 │┌▽─────────────────┐
 ││Core (Cube)       │
 │└┬───────────────┬─┘
┌▽─▽──────────────┐│  
│Peripheral Driver││  
└┬────────────────┘│  
┌▽─────────────────▽┐ 
│HAL (Cube)         │ 
└┬──────────────────┘ 
┌▽───────┐            
│Hardware│            
└────────┘ 
```

This translates to the following file tree:

```
<project name>
 ├─src
 │  ├─application
 │  │  ├─app.cpp
 │  │  ├─app.h
 │  │  └─...
 │  ├─core (cube generated, calls to app added)
 │  │  ├─main.c
 │  │  └─...
 │  └─drivers
 │     ├─example_driver.cpp
 │     ├─example_driver.h
 │     └─...
 ├─platformio.ini
 └─<project name>.ioc*

```
