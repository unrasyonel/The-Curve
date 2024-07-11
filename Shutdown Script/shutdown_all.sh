#!/bin/bash

# A small script to automate the process of shutting down multiple servers.

# list of servers to be shut down
SERVERS=("10.150.1.35" "10.150.1.34" "10.150.1.33" "10.150.1.32")

PASSWORD="blank :)"

# installs shhpass if not insalled
install_sshpass() {
    if ! command -v sshpass &> /dev/null; then
        echo "sshpass is not installed. Installing..."
        sudo apt-get update
        sudo apt-get install -y sshpass
    else
        echo "sshpass is already installed."
    fi
}

shutdown_server() {
    local SERVER_IP=$1
    echo "Attempting to shut down server $SERVER_IP"
    if ! sshpass -p "$PASSWORD" ssh -o StrictHostKeyChecking=no -o ConnectTimeout=10 ubuntu@$SERVER_IP "sudo shutdown now" < /dev/null; then
        echo "Unable to connect to $SERVER_IP. Assuming it is already shut down."
    else
        echo "Successfully shut down $SERVER_IP"
    fi
}

# check and install sshpass if necessary
install_sshpass

# shutdown each server in the list
for SERVER in "${SERVERS[@]}"; do
    shutdown_server $SERVER
done

# shutdown the controller last
echo "Shutting down controller 10.150.1.30"
if ! sshpass -p "$PASSWORD" ssh -o StrictHostKeyChecking=no -o ConnectTimeout=10 ubuntu@10.150.1.30 "sudo shutdown now" < /dev/null; then
    echo "Unable to connect to the controller 10.150.1.30. Assuming it is already shut down."
else
    echo "Successfully shut down controller 10.150.1.30"
fi
