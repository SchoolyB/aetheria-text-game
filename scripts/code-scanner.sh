# !This is only used for code scanning actions on GitHub
gcc -o ../game/Aetheria.exe src/main.c -lncurses

if [ $? -eq 0 ]; then
    echo "\e[32mBuild Successful!\e[0m"
    sleep 1
    echo "Clearing Terminal"
    sleep 1
    clear
    echo "Running Aetheria..."
    ./../game/Aetheria.exe
else
    echo "\e[31mBuild Failed.\e[0m"
    exit 1
fi
