# Use an image that includes a C compiler, such as gcc
FROM gcc:latest

# Install netcat
RUN apt-get update && apt-get install -y netcat

# Set the working directory in the container
WORKDIR /usr/src/app

# Copy the current directory contents into the container at /usr/src/app
COPY . .

# Compile your C program
RUN gcc -o shop shop.c

# Command to run the executable
CMD ["./shop"]
