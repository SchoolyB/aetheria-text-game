cd ../game

# Build the Aetheria executable
gcc -o Aetheria.exe src/main.c -lncurses

if [ $? -eq 0 ]; then
  echo -e "\e[32mBuild Successful!\e[0m"
else
  echo -e "\e[31mBuild Failed.\e[0m"
  exit 1
fi
