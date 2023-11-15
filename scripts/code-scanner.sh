cd ../game

# Build the Aetheria executable
gcc -o Aetheria.exe src/main.c -lncurses

if [ $? -eq 0 ]; then
  echo -e "\e[32mBuild Successful!\e[0m"
  sleep 1
  echo "Clearing Terminal"
  sleep 1
  clear
  echo "Running Aetheria..."
  ./Aetheria.exe
else
  echo -e "\e[31mBuild Failed.\e[0m"
  exit 1
fi
