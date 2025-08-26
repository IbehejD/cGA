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

## Julia API Wrapper

The project provides a Julia API wrapper for the C backend, allowing you to call the genetic algorithm from Julia and use Julia-defined fitness functions.

### Usage
1. Build the C shared library (see build instructions above).
2. Use the wrapper and example in `julia_wrapper/` and `examples/julia/`:
   ```sh
   julia examples/julia/main.jl
   ```
   This will call the C algorithm with a Julia callback as the fitness function.

### Example
See `julia_wrapper/algorithm_wrapper.jl` and `examples/julia/main.jl` for details on how to define a Julia fitness function and call the C API.

## License
MIT License. See source files for details.
