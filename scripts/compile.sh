gcc -o ../game/src/Aetheria.exe ../game/src/main.c -lncurses
# When not using ncurses use the following command:
# gcc -o Aetheria.o main.c

if [ $? -eq 0 ]; then
    echo "Build Successful"  
else
    echo "Build Failed"
    exit 1
fi

# After making any chnages to this file us the following command to the file executable permissions:
# chmod +x ./build.sh
