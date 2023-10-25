gcc -o Aetheria.o main.c

if [ $? -eq 0 ]; then
    echo "Build successful"
    ./Aetheria.o
else
    echo "Build failed"
    exit 1
fi

# After making any chnages to this file us the following command to the file executable permissions:
# chmod +x build.sh 
