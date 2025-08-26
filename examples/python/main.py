# Copyright (c) 2025 David Ibehej
# 
# This software is released under the MIT License.
# https://opensource.org/licenses/MIT

import sys
import os
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), '../..')))
from python_wrapper import algorithm_wrapper
import fitness

if __name__ == "__main__":
    algorithm_wrapper.call_algorithm(100, 32, 10, fitness.fitness)
