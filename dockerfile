FROM ubuntu
COPY ProgIntel.cpp .
RUN apt update
RUN apt install nano -y
RUN apt install gcc -y
RUN apt-get install gcc-multilib g++-multilib -y
RUN apt install libc6-dev-i386 -y
RUN g++ -m32 -masm=intel ProgIntel.cpp -o ProgIntel
