# NanoTekSpice 🔌

<div align="center">
  <img src="https://img.shields.io/badge/language-C++-blue.svg" alt="Language">
  <img src="https://img.shields.io/badge/platform-Linux%20%7C%20macOS-lightgrey.svg" alt="Platform">
</div>

<p align="center">
  <b>A digital circuit simulator supporting various components from elementary logic gates to complex integrated circuits</b>
</p>

---

## 📋 Overview

NanoTekSpice is an electronic circuit simulator that models and simulates digital electronic circuits. It allows you to build circuits using various components like logic gates (AND, OR, XOR, NOT), gate components (4001, 4011, 4030, 4069, 4071, 4081), and more advanced components such as adders, decoders, and shifters.

The simulator reads circuit descriptions from configuration files and provides an interactive command prompt for simulation control.

## ✨ Features

- **Component Support**:
  - Elementary logic components (AND, OR, XOR, NOT)
  - Gate components (4001, 4011, 4030, 4069, 4071, 4081)
  - Advanced components (4008 adder, 4017 Johnson counter, 4040 counter, 4094 shift register, etc.)
  - Special components (Input, Output, Clock, True, False, Logger)

- **Interactive Commands**:
  - Set values for inputs and clocks
  - Simulate circuit behavior step by step
  - Display current component states
  - Exit the simulation

## 🚀 Getting Started

### Prerequisites

- C++ compiler with C++17 support
- Make

### Installation

```bash
git clone https://github.com/yourusername/NanoTekSpice.git
cd NanoTekSpice
make
```

### Usage

```bash
./nanotekspice [circuit_file]
```

### Circuit File Format

The circuit file describes components and their connections using a simple text format:

```
# Circuit Example
.chipsets:
input a
input b
output s
and gate
.links:
a:1 gate:1
b:1 gate:2
gate:3 s:1
```

## 🎮 Command Line Interface

Once the simulation starts, you can use the following commands:

- `exit`: Exit the program
- `display`: Print the values of all inputs and outputs
- `simulate`: Simulate a tick of the circuit
- `loop`: Run the simulation continuously until SIGINT (Ctrl+C)
- `[component]=[value]`: Set an input or clock value (0, 1, or U for undefined)

## 🧩 Components Library

### Elementary Components
- `and`: AND logic gate
- `or`: OR logic gate
- `xor`: XOR logic gate
- `not`: NOT logic gate

### Special Components
- `input`: Input pin that can be set to 0, 1, or undefined
- `output`: Output pin that displays the computed value
- `clock`: Clock component that switches between states
- `true`: Component that always outputs 1
- `false`: Component that always outputs 0
- `logger`: Component that logs signal changes

### Gates Components
- `4001`: Quad NOR gates
- `4011`: Quad NAND gates
- `4030`: Quad XOR gates
- `4069`: Hex NOT gates
- `4071`: Quad OR gates
- `4081`: Quad AND gates

### Advanced Components
- `4008`: 4-bit binary adder
- `4017`: Decade counter with 10 decoded outputs
- `4040`: 12-bit binary counter
- `4094`: 8-stage shift-and-store register
- `4512`: 8-channel data selector
- `4514`: 4-bit latched/4-to-16 line decoder
