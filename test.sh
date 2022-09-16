#/bin/bash
clang++ -std=c++98 ftVector.cpp -o ftVector.out
clang++ -Wall -Wextra -Werror -std=c++98 stdVector.cpp -o stdVector.out
./ftVector.out > ftVector.txt
./stdVector.out > stdVector.txt
diff ftVector.txt stdVector.txt
#rm -rf ftVector.out stdVector.out ftVector.txt stdVector.txt
