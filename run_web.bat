@echo off
rem =====================================================================
rem The Battle Cats Rebuilt - Web & Room-Code PvP Server Launcher
rem =====================================================================
set "ROOT_DIR=%~dp0"
set "PYTHONPATH=%ROOT_DIR%"
cd /d "%ROOT_DIR%"

if exist "venv\Scripts\python.exe" (
    set "PY_CMD=venv\Scripts\python.exe"
) else (
    set "PY_CMD=python"
)

echo [*] Starting The Battle Cats Web PvP Server on http://127.0.0.1:8080 ...
"%PY_CMD%" -m game_project.web_server 8080
if %ERRORLEVEL% NEQ 0 (
    echo [!] Server exited with error code %ERRORLEVEL%
    pause
)
