FROM ubuntu:latest

RUN apt update && \
    apt -y install flex bison g++ make

WORKDIR /MDP

ENTRYPOINT [ "make" ]