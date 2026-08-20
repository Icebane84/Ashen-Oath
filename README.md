# Ashen Oath (Unreal Engine C++ Edition)

Welcome to the **Ashen Oath** Unreal Engine C++ workspace. This repository contains the core C++ systems and gameplay architecture for Ashen Oath, designed to work in synergy with Unreal Engine 5.8 and adhere to the **Phoenix Protocol v4.5+** guidelines for Zero-Entropy development.

## 🗺️ Project Structure

- **`AshenOath.uproject`**: The Unreal Engine project description file.
- **`Source/AshenOath/`**: All C++ code files.
  - **Subsystems**: Global engine-native systems ([AshenOath_DirectorSubsystem](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/AshenOath_DirectorSubsystem.h), [AshenOath_GameEventSubsystem](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/AshenOath_GameEventSubsystem.h)).
  - **Components**: Decoupled gameplay components ([AshenOath_HealthComponent](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/AshenOath_HealthComponent.h), [AshenOath_HitboxComponent](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/AshenOath_HitboxComponent.h), [AshenOath_HurtboxComponent](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/AshenOath_HurtboxComponent.h)).
  - **Interfaces**: Decoupled interfaces ([AshenCharacterInterface](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/AshenOath/Source/AshenOath/AshenCharacterInterface.h)).
- **`Docs/`**: Architectural documentation and reference codices.
  - [UNREAL_CODEX.md](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/Docs/UNREAL_CODEX.md): Primary architectural reference for C++ and Blueprints.
  - [RELEASE_HISTORY.md](file:///c:/Users/Chris/Ashen%20Oath%20Unreal%20Engine/Docs/RELEASE_HISTORY.md): Detailed chronicle of builds and completed milestones.

## ⚙️ How to Build

1. Open your terminal in `AshenOath/`.
2. Ensure you have a compatible C++ Redistributable installed.
3. Regenerate project files (Visual Studio 2022/2025/2026):

   ```powershell
   & "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\DotNET\UnrealBuildTool\UnrealBuildTool.exe" -projectfiles -project="C:\Users\Chris\Ashen Oath Unreal Engine\AshenOath\AshenOath.uproject" -game -engine
   ```

4. Open `AshenOath.sln` or `AshenOath.slnx` in Visual Studio or JetBrains Rider.
5. Compile using **Live Coding** inside the editor (`Ctrl + Alt + F11`) for quick hot-reloads during active development.
