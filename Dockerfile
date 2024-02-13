# Dockerfile

# Use an official Ubuntu runtime as a parent image
FROM ubuntu:latest

# Set the working directory in the container
WORKDIR /app

# Copy the current directory contents into the container at /app
COPY . .

# Install gcc compiler
RUN apt-get update && apt-get install -y gcc

# Compile the C program
RUN gcc -o server server.c shop.c -lpthread

# Expose port 40076 to the outside world
EXPOSE 40076

# Run the server when the container launches
CMD ["./server"]
