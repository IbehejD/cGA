# syntax=docker/dockerfile:1

FROM python:3.13-slim

# Install build tools and C dependencies
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
    build-essential \
    clang \
    cmake \
    cython3 \
    python3-dev \
    git \
    valgrind \
    && rm -rf /var/lib/apt/lists/*

# Set workdir
WORKDIR /workspace

# Copy requirements if present
COPY requirements.txt ./
RUN pip install --no-cache-dir -r requirements.txt || true

# Copy the rest of the code
COPY . .

# Set environment variables for Python
ENV PYTHONUNBUFFERED=1
ENV PYTHONDONTWRITEBYTECODE=1

# Default shell
CMD ["/bin/bash"]
