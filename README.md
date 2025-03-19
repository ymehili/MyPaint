# 🎨 MyPaint

<div align="center">
  <p><em>A lightweight and feature-rich paint application built with SFML</em></p>
</div>

## ✨ Features

- 🖌️ **Drawing Tools**: Pencil and eraser with customizable sizes
- 📑 **Layer System**: Create, manage, and toggle visibility of multiple layers
- 🔍 **Zoom Functionality**: Zoom in and out for detailed work
- 💾 **File Operations**: Open, save, and create new projects
- 🎯 **Shape Selection**: Different drawing shapes for creative flexibility
- 🎨 **Color Selection**: Multiple color options for your artistic needs

## 🚀 Getting Started

### Prerequisites

- SFML library
- C compiler (GCC recommended)
- Make

### Installation

1. Clone this repository:
   ```bash
   git clone https://github.com/yourusername/MyPaint.git
   cd MyPaint
   ```

2. Compile the project:
   ```bash
   make
   ```

3. Run the application:
   ```bash
   ./my_paint
   ```

## 🎮 Usage

### Menu Bar

- **File**: New file, Open file, Save file, Close
- **Edit**: Select pencil or eraser tools
- **Layers**: Add or remove layers
- **Help**: About and help information

### Controls

- **Left Click**: Draw on canvas
- **Mouse Wheel**: Zoom in/out
- **ESC Key**: Exit application

## 📝 Project Structure

```
my_paint/
├── assets/          # Application assets (fonts, etc.)
├── include/         # Header files
├── src/             # Source code files
│   └── tools/       # Utility functions
└── tests/           # Unit tests
```

## 🧪 Testing

Run the unit tests:

```bash
make tests_run
```
