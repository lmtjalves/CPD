FROM opensuse:13.1
MAINTAINER Luis Alves <lmtjalves@gmail.com>

# Install all required packages
RUN zypper in -y  openmpi openmpi-devel gcc gcc-c++ cmake

ENV PATH $PATH:/usr/lib64/mpi/gcc/openmpi/bin
ENV LIBRARY_PATH $LIBRARY_PATH:/usr/lib64/mpi/gcc/openmpi/lib64

ADD "make_script" /
RUN chmod 777 /make_script

WORKDIR "/mpi"
CMD ["/make_script"]
