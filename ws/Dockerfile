FROM ros:jazzy

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    python3-pip \
    python3-pandas \
    python3-serial \
    python3-colcon-common-extensions \
    ros-jazzy-std-msgs \
    ros-jazzy-ament-index-python \
    ros-jazzy-joy \
    ros-jazzy-sensor-msgs \
    && rm -rf /var/lib/apt/lists/*

# Ubuntu 24.04 blocks system-wide pip without this flag
RUN pip3 install --no-cache-dir --break-system-packages feetech-servo-sdk

ENV DISPLAY=:0
ENV QT_X11_NO_MITSHM=1
ENV ROS_DOMAIN_ID=7

RUN echo "source /opt/ros/jazzy/setup.bash" >> /root/.bashrc && \
    echo '[ -f /ws/install/setup.bash ] && source /ws/install/setup.bash' >> /root/.bashrc

WORKDIR /ws
COPY entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh
ENTRYPOINT ["/entrypoint.sh"]
CMD ["bash"]