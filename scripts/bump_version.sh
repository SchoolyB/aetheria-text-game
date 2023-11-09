#!/bin/bash

# Path to the JSON file
json_file="/version.json"

# Check if the JSON file exists
if [ ! -f "$json_file" ]; then
  echo "Version JSON file not found: $json_file"
  exit 1
fi

# Extract the current version numbers
current_game_version=$(jq -r .game_version "$json_file")
current_website_version=$(jq -r .website_version "$json_file")

# Function to increment version numbers
increment_version() {
  local version=$1
  local updated_version=""
  local patch=""
  if [[ $version =~ ([0-9]+)$ ]]; then
    patch="${BASH_REMATCH[1]}"
    updated_patch=$((patch + 1))
    updated_version="${version%$patch}$updated_patch"
    echo "$updated_version"
  else
    echo "Invalid version format: $version"
  fi
}

# Increment the patch numbers
patch_game=$(increment_version "$current_game_version")
patch_website=$(increment_version "$current_website_version")

# Update the JSON file with the new version numbers
jq ".game_version = \"$patch_game\" | .website_version = \"$patch_website\"" "$json_file" > "$json_file.tmp"
mv "$json_file.tmp" "$json_file"

echo "Updated game_version to $patch_game"
echo "Updated website_version to $patch_website"
