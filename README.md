# cGA: Compact Genetic Algorithm

A Python/C/Cython project implementing a compact genetic algorithm (cGA) with a C backend and Python/Cython interface. Includes a development environment for VS Code and Docker.

## Features
- C implementation of the compact genetic algorithm (`src/cGA.c`)
- Python interface via Cython (`python_wrapper/algorithm_wrapper.pyx`)
- Example usage in Python (`examples/python/main.py`)
- Build system using CMake and Python setuptools
- Dev container support for VS Code (`.devcontainer/`)
- Dockerfile for reproducible development

## Project Structure
```
cGA/
├── src/                  # C source code (cGA.c)
├── python_wrapper/       # Cython wrapper and build scripts
├── examples/python/      # Example Python usage
├── Dockerfile            # Development Dockerfile
├── .devcontainer/        # VS Code dev container config
├── fabricate.py          # Build helper script
├── requirements.txt      # Python dependencies
├── CMakeLists.txt        # CMake build config
```

## Getting Started

### Prerequisites
- Python 3.13+
- C compiler (clang/gcc)
- CMake
- Docker (optional, for containerized dev)
- VS Code (optional, for devcontainer support)

### Build and Run (Locally)
1. Install Python dependencies:
   ```sh
   pip install -r requirements.txt
   ```
2. Build the Cython extension:
   ```sh
   python fabricate.py
   ```
   necessary for python API
   
3. Run the Python example:
   ```sh
   python examples/python/main.py
   ```
   main.py uses objective function definition as shown in fitness.py

## License
MIT License. See source files for details.
