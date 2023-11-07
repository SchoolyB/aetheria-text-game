gcc -o Aetheria.o main.c -lncurses
# When not using ncurses use the following command:
# gcc -o Aetheria.o main.c

if [ $? -eq 0 ]; then
    sleep 1
    echo "Clearing Terminal"
    sleep 1
    clear
    echo "Build Successful"
    echo "Running Aetheria"
    ./Aetheria.o
else
    echo "Build Failed"
    exit 1
fi

# After making any chnages to this file us the following command to the file executable permissions:
# chmod +x ./build_n_run.sh 
