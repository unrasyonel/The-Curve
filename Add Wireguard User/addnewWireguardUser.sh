#!/bin/bash

# Directory for WireGuard configuration
sudo wg-quick down wg0
WG_CONF="/etc/wireguard/wg0.conf"
CLIENTS_DIR="/etc/WireGuard"

# Prompt for the user name (identifier)
read -p "Enter the user name: " USER_LABEL

# Find the last used IP address from the WireGuard configuration
LAST_IP=$(grep AllowedIPs $WG_CONF | tail -n 1 | awk -F '[/.]' '{print $4}')

# Calculate the next IP address (increment last IP by 1)
NEXT_IP=$((LAST_IP + 1))
NEXT_IP_ADDRESS="10.0.0.$NEXT_IP"

# Create a new directory for the client based on the next IP address
CLIENT_DIR="$CLIENTS_DIR/$NEXT_IP_ADDRESS"
mkdir -p "$CLIENT_DIR"

# Generate new private and public keys for the client
PRIVATE_KEY=$(wg genkey)
PUBLIC_KEY=$(echo "$PRIVATE_KEY" | wg pubkey)

# Save the private and public keys to the client's IP folder
echo "$PRIVATE_KEY" > "$CLIENT_DIR/privatekey"
echo "$PUBLIC_KEY" > "$CLIENT_DIR/publickey"

# Add the new peer configuration to the WireGuard configuration
echo "[Peer]
# $USER_LABEL
PublicKey = $PUBLIC_KEY
AllowedIPs = $NEXT_IP_ADDRESS/32
" | sudo tee -a $WG_CONF
sudo wg-quick up wg0

# Create a new client configuration file in the client folder
CLIENT_CONF="$CLIENT_DIR/WireGuardVPN_$USER_LABEL.conf"

# Get the server's public IP address using ip command
# Don't forget to change your network adapter name. In my case, it is ens192 
ENDPOINT_IP=$(ip -4 addr show ens192 | grep -oP '(?<=inet\s)\d+(\.\d+){3}')

# Create the client's WireGuard configuration file
# Here I used Adguard DNS for adblocking.
echo "[Interface]
PrivateKey = $PRIVATE_KEY
Address = $NEXT_IP_ADDRESS/32
DNS = 94.140.14.14

[Peer]
PublicKey = $(sudo wg show wg0 public-key)
Endpoint = $ENDPOINT_IP:51820
AllowedIPs = 0.0.0.0/0, ::/0
PersistentKeepalive = 25
" > "$CLIENT_CONF"

echo "$CLIENT_CONF has been created and saved in $CLIENT_DIR."

# Ask if the user wants to restart the WireGuard service
read -p "Do you want to restart the WireGuard service? (y/n): " RESTART

if [[ "$RESTART" == "y" ]]; then
    sudo wg show
    cat "$CLIENT_CONF"
    sudo systemctl restart wg-quick@wg0
    echo "WireGuard service has been restarted."
else
    cat "$CLIENT_CONF"
    echo "WireGuard service has not been restarted."
fi
