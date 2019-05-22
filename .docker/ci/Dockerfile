FROM ubuntu:bionic

LABEL maintainer="Lander Usategui lander@erlerobotics.com"

ENV TERM xterm
ENV ROS_DISTRO dashing
ENV ROS_WS=/opt/ws_moveit
WORKDIR $ROS_WS

ENV LANG C.UTF-8
ENV LC_ALL C.UTF-8

RUN \
     echo 'Etc/UTC' > /etc/timezone \
      && ln -s /usr/share/zoneinfo/Etc/UTC /etc/localtime \
      && apt-get update -qq && apt-get install -qq -y tzdata dirmngr gnupg2 lsb-release curl \
      # setup ros2 keys
      && curl http://repo.ros2.org/repos.key | apt-key add - \
      # setup sources.list
      && echo "deb http://packages.ros.org/ros2-testing/ubuntu bionic  main" > /etc/apt/sources.list.d/ros2-testing.list \
      && apt-get update -qq && apt-get install -qq -y \
         $(apt-cache search 'ros-dashing-.*' | awk '/dbgsym|connext|opensplice/ { next; } { print $1; }') \
         build-essential \
         cmake \
         git \
         python3-colcon-common-extensions \
         python3-pip \
         python3-vcstool \
         python3-wstool \
         python-rosdep \
         wget \
      	 libboost-all-dev \
         libglew-dev \
         freeglut3-dev \
         pkg-config \
         libfcl-dev \
         libassimp-dev \
         libqhull-dev \
         libopencv-dev \
         clang clang-format-3.9 clang-tidy clang-tools \
         libompl-dev \
      && rm -rf /var/lib/apt/lists/*
      # && mkdir -p $ROS_WS/src \
      # && wget https://raw.githubusercontent.com/AcutronicRobotics/moveit2/master/moveit2.repos \
      # && vcs import src < moveit2.repos

# Install Fast-RTPS dependencies
RUN apt-get -qq update && \
        apt-get install -qq --no-install-recommends -y \
            libasio-dev \
            libtinyxml2-dev \
            && \
            # Clear apt-cache to reduce image size
            rm -rf /var/lib/apt/lists/*

# Download moveit source, so that we can get necessary dependencies
RUN mkdir -p $ROS_WS/src \
    && wget https://raw.githubusercontent.com/AcutronicRobotics/moveit2/master/moveit2.repos \
    && vcs import src < moveit2.repos
    # wstool init --shallow . https://raw.githubusercontent.com/ros-planning/moveit2/master/moveit.rosinstall

# Download all MoveIt 2 dependencies
RUN \
    apt-get -qq update && \
    rosdep init && \
    rosdep update -q && \
    rosdep install -q -y --from-paths . --ignore-src --rosdistro ${ROS_DISTRO} --as-root=apt:false || true && \
    # Clear apt-cache to reduce image size
    rm -rf /var/lib/apt/lists/*

# Remove the source code from this container
# TODO: in the future we may want to keep this here for further optimization of later containers
RUN cd $ROS_WS && \
    rm -rf src/


# Continous Integration Setting
ENV IN_DOCKER 1
ENV DOCKER 1 # old version, keep for now

# setup entrypoint https://github.com/docker/hub-feedback/issues/811
#RUN echo '#!/bin/bash\nset -e\nsource "/opt/ros/$ROS_DISTRO/setup.bash"\nexec "$@"' > /docker-entrypoint.sh && chmod +x /docker-entrypoint.sh
RUN find /opt/ros/dashing/ -name image_* | xargs rm -rf && find /opt/ros/dashing/ -name tf2* | xargs rm -rf
COPY ./docker-entrypoint.sh /
ENTRYPOINT ["/docker-entrypoint.sh"]

CMD ["bash"]
