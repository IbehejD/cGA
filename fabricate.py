# Copyright (c) 2025 David Ibehej
# 
# This software is released under the MIT License.
# https://opensource.org/licenses/MIT

import os
import subprocess
import sys

def run_cmake_and_build():
    build_dir = "build"
    wrapper_dir = "python_wrapper"

    os.makedirs(wrapper_dir, exist_ok=True)

    # Run cmake and build the C shared library
    subprocess.check_call(["cmake", "-S", ".", "-B", build_dir])
    subprocess.check_call(["cmake", "--build", build_dir])

    # Run python setup.py build_ext --inplace, output to wrapper_dir
    subprocess.check_call([
        sys.executable, "setup.py", "build_ext", "--inplace", f"--build-lib=../{wrapper_dir}"
    ], cwd=wrapper_dir)

if __name__ == "__main__":
    run_cmake_and_build()