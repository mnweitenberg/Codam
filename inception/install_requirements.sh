#!/bin/bash
set -e

# Install dependencies
sudo apt-get update
sudo apt-get upgrade -y
sudo apt-get install -y make curl lsb-release ca-certificates apt-transport-https software-properties-common hostsed -y

# Check if docker-ce is already installed
if dpkg-query -W docker-ce; then
  echo "Docker CE is already installed."
else
  # Add Docker’s official GPG key
  curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo gpg --dearmor -o /usr/share/keyrings/docker-archive-keyring.gpg

  # Set up the repository
  echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/docker-archive-keyring.gpg] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable" | sudo tee /etc/apt/sources.list.d/docker.list > /dev/null

  # Install Docker Engine
  sudo apt-get update
  sudo apt-get install -y docker-ce
fi

# Install docker-compose
if dpkg-query -W docker-compose; then
  echo "Docker Compose is already installed."
else
  sudo apt-get update
  sudo apt-get install -y docker-compose
fi

# Clean up
sudo rm -rf /var/lib/apt/lists/*
