@echo off
rem =====================================================================
rem The Battle Cats Rebuilt - Windows Desktop Launcher
rem =====================================================================
set "ROOT_DIR=%~dp0"
set "PYTHONPATH=%ROOT_DIR%"
cd /d "%ROOT_DIR%"

if exist "venv\Scripts\python.exe" (
    set "PY_CMD=venv\Scripts\python.exe"
) else (
    set "PY_CMD=python"
)

echo [*] Starting The Battle Cats Desktop Game...
"%PY_CMD%" -m game_project.main %*
if %ERRORLEVEL% NEQ 0 (
    echo [!] Game exited with error code %ERRORLEVEL%
    pause
)
