@echo off
chcp 65001 >nul
:: Activer ou désactiver le mode debug
set "debug=1"  :: 1 = debug activé, 0 = debug désactivé

:: Début du script
echo Début du script...
pause

:: Chemin du répertoire à analyser
set "repertoire=%~dp0"

:: Vérifie si le répertoire existe
if not exist "%repertoire%" (
    echo Le répertoire "%repertoire%" n'existe pas.
    pause
    exit /b
)

:: Vérifie s'il y a des fichiers .md dans le répertoire
dir "%repertoire%*.md" >nul 2>&1
if errorlevel 1 (
    echo Aucun fichier .md trouvé dans le répertoire "%repertoire%".
    pause
    exit /b
) else (
    if "%debug%"=="1" echo Des fichiers .md existent dans le répertoire "%repertoire%".
)

:: Reste du script
echo Continuer avec le traitement des fichiers...
pause

:: Activation de l'expansion différée
setlocal enabledelayedexpansion

:: Parcours des fichiers et ajout au tableau
for %%f in (*.md) do (
	if "%%f" neq "checklist.md" (
        if "%%f" neq "README.md" (
            set "filename=%%~nf"

            rem Créer le dossier
            md "!filename!" 2>nul

            rem Déplacer le fichier dans le dossier
            move "%%f" "!filename!\%%f"

            echo Fichier "%%f" déplacé dans le dossier "!filename!".
		)
	)
)

:: Désactiver l'expansion différée
endlocal

echo Script terminé.
pause
