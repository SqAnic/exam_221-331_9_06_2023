FROM ubuntu

LABEL author = "Sorokin Egor"

ENV TZ=Europe/Moscow
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt-get update
RUN apt-get install qtbase5-dev -y
RUN apt-get install qt5-qmake
RUN apt-get install build-essential -y

WORKDIR /root/
RUN mkdir Sorokin_221_331
WORKDIR /root/Sorokin_221_331/
COPY *.cpp /root/Sorokin_221_331/
COPY *.h /root/Sorokin_221_331/
COPY *.pro /root/Sorokin_221_331/
COPY *.txt /root/Sorokin_221_331/

RUN qmake exam_221-331_29_06_2023.pro
RUN make

ENTRYPOINT ["./exam_221-331_29_06_2023"]
