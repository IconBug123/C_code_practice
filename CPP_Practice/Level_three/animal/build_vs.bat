@echo off
chcp 65001 >nul
setlocal enabledelayedexpansion

echo ==============================
echo   AnimalSim - VS2022 Builder
echo ==============================
echo.
echo 1) Configure + Build (Debug x64)
echo 2) Configure + Build (Release x64)
echo 3) Only Configure (Debug x64)
echo 4) Only Configure (Release x64)
echo 5) Open Debug .sln
echo 6) Open Release .sln
echo 7) Exit
echo.

set /p choice=请选择(1-7): 

if "%choice%"=="1" (
  cmake --preset vs2022-debug-x64 || goto :fail
  cmake --build --preset build-vs2022-debug-x64 || goto :fail
  set "SLN=build\vs2022-debug-x64\AnimalSim.sln"
  if exist "%SLN%" start "" "%SLN%"
  goto :end
)

if "%choice%"=="2" (
  cmake --preset vs2022-release-x64 || goto :fail
  cmake --build --preset build-vs2022-release-x64 || goto :fail
  set "SLN=build\vs2022-release-x64\AnimalSim.sln"
  if exist "%SLN%" start "" "%SLN%"
  goto :end
)

if "%choice%"=="3" (
  cmake --preset vs2022-debug-x64 || goto :fail
  goto :end
)

if "%choice%"=="4" (
  cmake --preset vs2022-release-x64 || goto :fail
  goto :end
)

if "%choice%"=="5" (
  set "SLN=build\vs2022-debug-x64\AnimalSim.sln"
  if exist "%SLN%" (
    start "" "%SLN%"
  ) else (
    echo 未找到 %SLN% ，请先执行配置（选项1或3）。
  )
  goto :end
)

if "%choice%"=="6" (
  set "SLN=build\vs2022-release-x64\AnimalSim.sln"
  if exist "%SLN%" (
    start "" "%SLN%"
  ) else (
    echo 未找到 %SLN% ，请先执行配置（选项2或4）。
  )
  goto :end
)

if "%choice%"=="7" goto :end

:fail
echo.
echo *** 失败：请查看上方错误信息并修正后重试。
echo.

:end
endlocal
