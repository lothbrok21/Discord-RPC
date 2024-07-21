# 🎮 Discord Rich Presence (RPC) for C++ 🎮

## 📚 About

Discord Rich Presence (RPC) allows you to display detailed information about your game or application on your Discord profile. This project provides a C++ DLL implementation for integrating Discord RPC.

## 🚀 Features

- 🎯 Real-time status updates
- 📊 Display game or application details
- 🕹️ Show in-game progress
- 📅 Start events and send invites

## 🛠️ Setup

### Prerequisites

- Visual Studio (2019 or later)
- Discord Developer account

### 1. Uploading Images to Discord Application

1. **Create a Discord Application**:
    - Go to the [Discord Developer Portal](https://discord.com/developers/applications).
    - Click on `New Application` and give your application a name.

2. **Navigate to Rich Presence**:
    - Select your application.
    - Go to the `Rich Presence` section on the left menu.

3. **Upload Images**:
    - Scroll down to the `Rich Presence Assets` section.
    - Upload your images (e.g., large and small icons).
    - Note the key names you give to these images as you will use them in your code.

### 2. Compiling the C++ DLL in Visual Studio

1. **Clone the Repository**:
    ```bash
    git clone https://github.com/lothbrok21/Discord-RPC.git
    cd Discord-RPC
    ```

2. **Open the Project in Visual Studio**:
    - Open Visual Studio.
    - Go to `File` -> `Open` -> `Project/Solution`.
    - Navigate to the cloned repository folder and select the `.sln` file.

3. **Configure the Project**:
    - Right-click on your project in the `Solution Explorer` and select `Properties`.
    - Configure the project settings to match your needs (e.g., target platform, include directories, library directories).

4. **Add Source Files**:
    - Ensure all necessary source files and headers from the repository are included in your Visual Studio project.
    - Set up the include directories for Discord RPC headers and link against the Discord RPC
