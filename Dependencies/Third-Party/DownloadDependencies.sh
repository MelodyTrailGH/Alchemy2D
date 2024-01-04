#!/usr/bin/env bash

#Code is courtesy of Dave Dopson.
SOURCE=${BASH_SOURCE[0]}
while [ -L "$SOURCE" ]; do
  DIR=$( cd -P "$( dirname "$SOURCE" )" >/dev/null 2>&1 && pwd )
  SOURCE=$(readlink "$SOURCE")
  [[ $SOURCE != /* ]] && SOURCE=$DIR/$SOURCE
done
DIR=$( cd -P "$( dirname "$SOURCE" )" >/dev/null 2>&1 && pwd )

#Command check code courtesy of Daniel Kaplan and Maarten Billemont

if ! command -v "wget" &> /dev/null
then
    echo "\"wget\" could not be found"
    exit 1
fi

if ! command -v "zip" &> /dev/null
then
    echo "\"zip\" could not be found"
    exit 1
fi

if ! command -v "tar" &> /dev/null
then
    echo "\"tar\" could not be found"
    exit 1
fi


if ! command -v "xz" &> /dev/null
then
    echo "\"xz\" could not be found"
    exit 1
fi

GLFW_VERSION="3.3.9"
GLFW_URI="https://github.com/glfw/glfw/releases/download/$GLFW_VERSION/glfw-$GLFW_VERSION.zip"
GLFW_DOWNLOAD_PATH="$DIR/glfw-$GLFW_VERSION.zip"
GLFW_EXTRACT_DIR="$DIR/glfw-$GLFW_VERSION"

if [ -f "$GLFW_DOWNLOAD_PATH" ]; then
    rm -r "$GLFW_DOWNLOAD_PATH"
fi

if [ -d "$GLFW_EXTRACT_DIR" ]; then
    rm -r "$GLFW_EXTRACT_DIR"
fi

echo "Downloading GLFW-$GLFW_VERSION."
wget -q "$GLFW_URI" -O "$GLFW_DOWNLOAD_PATH"
echo "Downloaded GLFW-$GLFW_VERSION to $GLFW_DOWNLOAD_PATH."

echo "Extracting $GLFW_DOWNLOAD_PATH to $GLFW_EXTRACT_DIR."
unzip -q "$GLFW_DOWNLOAD_PATH"
echo "Extracted $GLFW_DOWNLOAD_PATH to $GLFW_EXTRACT_DIR."

GLEW_VERSION="2.2.0"
GLEW_URI="https://github.com/nigels-com/glew/releases/download/glew-$GLEW_VERSION/glew-$GLEW_VERSION.zip"
GLEW_DOWNLOAD_PATH="$DIR/glew-$GLEW_VERSION.zip"
GLEW_EXTRACT_DIR="$DIR/glew-$GLEW_VERSION"

if [ -f "$GLEW_DOWNLOAD_PATH" ]; then
    rm -r "$GLEW_DOWNLOAD_PATH"
fi

if [ -d "$GLEW_EXTRACT_DIR" ]; then
    rm -r "$GLEW_EXTRACT_DIR"
fi

echo "Downloading GLEW-$GLEW_VERSION."
wget -q "$GLEW_URI" -O "$GLEW_DOWNLOAD_PATH"
echo "Downloaded GLEW-$GLEW_VERSION to $GLEW_DOWNLOAD_PATH."

echo "Extracting $GLEW_DOWNLOAD_PATH to $GLEW_EXTRACT_DIR."
unzip -q "$GLEW_DOWNLOAD_PATH"
echo "Extracted $GLEW_DOWNLOAD_PATH to $GLEW_EXTRACT_DIR."


FMT_VERSION="10.2.0"
FMT_URI="https://github.com/fmtlib/fmt/releases/download/$FMT_VERSION/fmt-$FMT_VERSION.zip"
FMT_DOWNLOAD_PATH="$DIR/fmt-$FMT_VERSION.zip"
FMT_EXTRACT_DIR="$DIR/fmt-$FMT_VERSION"

if [ -f "$FMT_DOWNLOAD_PATH" ]; then
    rm -r "$FMT_DOWNLOAD_PATH"
fi

if [ -d "$FMT_EXTRACT_DIR" ]; then
    rm -r "$FMT_EXTRACT_DIR"
fi

echo "Downloading fmt-$FMT_VERSION."
wget -q "$FMT_URI" -O "$FMT_DOWNLOAD_PATH"
echo "Downloaded fmt-$FMT_VERSION to $FMT_DOWNLOAD_PATH."

echo "Extracting $FMT_DOWNLOAD_PATH to $FMT_EXTRACT_DIR."
unzip -q "$FMT_DOWNLOAD_PATH"
echo "Extracted $FMT_DOWNLOAD_PATH to $FMT_EXTRACT_DIR."


SPDLOG_VERSION="1.12.0"
SPDLOG_URI="https://github.com/gabime/spdlog/archive/refs/tags/v$SPDLOG_VERSION.zip"
SPDLOG_DOWNLOAD_PATH="$DIR/spdlog-$SPDLOG_VERSION.zip"
SPDLOG_EXTRACT_DIR="$DIR/spdlog-$SPDLOG_VERSION"

if [ -f "$SPDLOG_DOWNLOAD_PATH" ]; then
    rm -r "$SPDLOG_DOWNLOAD_PATH"
fi

if [ -d "$SPDLOG_EXTRACT_DIR" ]; then
    rm -r "$SPDLOG_EXTRACT_DIR"
fi

echo "Downloading spdlog-$SPDLOG_VERSION."
wget -q "$SPDLOG_URI" -O "$SPDLOG_DOWNLOAD_PATH"
echo "Downloaded spdlog-$SPDLOG_VERSION to $SPDLOG_DOWNLOAD_PATH."

echo "Extracting $SPDLOG_DOWNLOAD_PATH to $SPDLOG_EXTRACT_DIR."
unzip -q "$SPDLOG_DOWNLOAD_PATH"
echo "Extracted $SPDLOG_DOWNLOAD_PATH to $SPDLOG_EXTRACT_DIR."
