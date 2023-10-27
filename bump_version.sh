#!/bin/bash

# Specify the path to your version.txt file
VERSION_FILE="./src/VERSION.txt"

# Read the current version from the version.txt file
CURRENT_VERSION=$(grep -oP "(?<=Build: Pre_Rel_v)[0-9]+\.[0-9]+\.[0-9]+" "$VERSION_FILE")

# Split the current version into major, minor, and patch
IFS="." read -ra parts <<< "$CURRENT_VERSION"
MAJOR="${parts[0]}"
MINOR="${parts[1]}"
PATCH="${parts[2]}"

# Increment the patch number
((PATCH++))

# Create the new version in the format "Build: Pre_Rel_v.x.y.z"
NEW_VERSION="Build: Pre_Rel_v$MAJOR.$MINOR.$PATCH"

# Update the version in the version.txt file
sed -i "s/Build: Pre_Rel_v$CURRENT_VERSION/$NEW_VERSION/" "$VERSION_FILE"

echo "Updating to build: $NEW_VERSION"
