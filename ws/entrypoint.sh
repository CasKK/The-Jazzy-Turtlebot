#!/bin/bash
set -e
source /opt/ros/jazzy/setup.bash

# Also source your workspace if it's been built
if [ -f /ws/install/setup.bash ]; then
  source /ws/install/setup.bash
fi

exec "$@"