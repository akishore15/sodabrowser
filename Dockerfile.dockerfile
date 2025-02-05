# Use an official GCC image from the Docker Hub
FROM gcc:latest

# Set the working directory
WORKDIR /app

# Copy the current directory contents into the container at /app
COPY . /app

# Compile the C program
RUN gcc search.c -o search

# Run the C program
CMD ["./search"]
