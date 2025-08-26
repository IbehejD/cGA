# Copyright (c) 2025 David Ibehej
# 
# This software is released under the MIT License.
# https://opensource.org/licenses/MIT


from setuptools import setup, Extension
from Cython.Build import cythonize
import os

here = os.path.dirname(os.path.abspath(__file__))
pyx_path = os.path.join(here, "algorithm_wrapper.pyx")


pyx_path = "algorithm_wrapper.pyx"  # relative path

parent_dir = os.path.abspath(os.path.join(here, os.pardir))
src_dir = os.path.join(parent_dir, "src")


ext = Extension(
    name="algorithm_wrapper",
    sources=[pyx_path],  # relative path
    include_dirs=[parent_dir, src_dir],
)

setup(
    ext_modules=cythonize([ext]),
)
