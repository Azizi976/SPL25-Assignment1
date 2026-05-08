# SPL Assignment 1: DJ Track Session Manager

## Project Overview
This project was developed as part of Assignment 1 in the Systems Programming (SPL) course at Ben-Gurion University of the Negev. 
Written in C++, the project focuses on low-level memory management, Object-Oriented Programming (OOP) principles, polymorphism, and the implementation of advanced data structures in an environment without a Garbage Collector.

**Developers:** Tal Azizi & Ifat Nahmani

## Project Objectives
The system simulates a professional DJ workstation built through four cumulative phases. Each phase addresses specific engineering challenges related to memory management and software architecture:

### Phase 1: A Broken Playlist (Ownership & Linked Lists)
Implementation of a custom linked list representing a musical playlist. This phase required a deep understanding of dynamic memory allocation and the prevention of memory leaks during insertion, removal, and modification of elements. Strict ownership principles were applied throughout.

### Phase 2: Master of 5 and Polymorphism (Rule of 5)
Extending the system to support various audio track types (e.g., `MP3Track` and `WAVTrack`) inheriting from a polymorphic base class `AudioTrack`. This phase emphasized the precise implementation of the **Rule of 5** to ensure proper resource management:
- Copy Constructor
- Copy Assignment Operator
- Move Constructor
- Move Assignment Operator
- Virtual Destructor

### Phase 3: Pointer Wrapper (Custom Smart Pointers)
Creation of a custom wrapper class for pointer management, mimicking the behavior of C++ smart pointers (similar to `std::unique_ptr`). The goal was to encapsulate the lifecycle of pointed objects and provide a safe interface for access.

### Phase 4: DJ Controller System (System Integration)
The final phase where all components were integrated into a complex software system:
- **DJLibraryService**: Manages the global track library.
- **MixingEngineService**: The engine managing the players (Decks).
- **LRU Cache**: A custom-implemented Least Recently Used (LRU) cache mechanism for efficient access to frequently used tracks.

## Architecture Overview

```text
├── include/                # Header files (.h)
│   ├── AudioTrack.h        # Polymorphic base class
│   ├── MP3Track.h          # MP3 track implementation
│   ├── WAVTrack.h          # WAV track implementation
│   ├── Playlist.h          # Playlist data structure
│   ├── LRUCache.h          # Cache management mechanism
│   ├── PointerWrapper.h    # Secure pointer management
│   ├── DJControllerService.h # Core system controller
│   └── ...                 
├── src/                    # Source files (.cpp)
│   ├── main.cpp            # Entry point
│   └── ...                 # Class implementations
├── bin/                    # Binaries and configuration files (e.g., dj_config.txt)
├── input_2/                # Alternative test inputs/outputs
├── Makefile                # Build script
└── README.md               # Project documentation
