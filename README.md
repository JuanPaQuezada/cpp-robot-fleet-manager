# cpp-robot-fleet-manager
A C++ console application demonstrating Object-Oriented Programming (Polymorphism) and custom Linked Lists for dynamic robotic fleet management.
# C++ Dynamic Robot Fleet Manager

## Overview
This project is a console-based management system designed to register and operate a fleet of different robotic units. It is built entirely in **C++** from scratch, avoiding standard template libraries (like `<vector>`) to demonstrate a deep understanding of low-level memory management and data structures.

## 🚀 Key Features
* **Object-Oriented Programming (OOP):** Utilizes inheritance to create specific robot types (`Drone`, `IndustrialRobot`) from a base abstract class (`Robot`).
* **Polymorphism:** The system can issue a generic `operate()` command to the entire fleet, and each robot executes its specific, overridden behavior.
* **Custom Data Structures:** Implements a custom **Singly Linked List** (`NodoFlota`) to store objects dynamically in the Heap.
* **Dynamic Memory Management:** Safe allocation (`new`) and deallocation (`delete`) of memory to prevent memory leaks during runtime and upon system exit.
* **Input Validation:** Robust handling of standard input buffer (`cin.clear()`, `cin.ignore()`) to prevent infinite loops on invalid user inputs.

## Technologies
* C++ (Standard Console Application)
* Windows API (`<windows.h>` for console manipulation)

## Concepts Demonstrated
- Abstract Classes and Pure Virtual Functions (`= 0`).
- Base Class Constructor Initialization.
- Pointers, References, and Heap Memory Management.
- Structs nested within Classes.

## Author
**Juan Pablo Quezada** *B.Sc. in Intelligent Computing Engineering Universidad Autónoma de Aguascalientes (UAA)*

