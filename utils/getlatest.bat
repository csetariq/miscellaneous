@ECHO off

REM This script assumes (\\bgl11-netapp04b\projects\pqemb-common\mng\cm\builds) is mounted in Z:
REM and C:\InternalRelease\<version> directory exists!
:menu
ECHO 1) 4.2.0
ECHO 2) 5.0.0
ECHO 3) 5.1.0
SET /P choice=Enter your choice: 
IF "%choice%" EQU "1" (
    SET ver=4.2.0
    SET destConfig=devconfig.txt
) ELSE IF "%choice%" EQU "2" (
    SET ver=5.0.0
    SET destConfig=ngconfig.txt
) ELSE IF "%choice%" EQU "3" (
    SET ver=5.1.0
    SET destConfig=ng51config.txt
) ELSE (
    GOTO menu
)


FOR /F "tokens=2 delims=:" %%a IN (Z:\v%ver%\latest\buildnumber.txt) DO (SET buildNum=%%a)
SET srcDir=Z:\v%ver%\%buildNum%
SET dstDir=C:\InternalRelease\%ver%
SET packageFile=SCMSCM_CD_%ver%_B%buildNum%.tar
SET releaseNotesFile=ReleaseNotes.doc
SET configTemplate=config_template.txt

DEL /F %dstDir%\SCMSCM_CD_%ver%_B*.tar

ECHO Changing config file...

FOR /F "tokens=1,2 delims==" %%a IN (%configTemplate%) DO (
    IF "%%a" NEQ "[release section]" (
        IF "%%a" EQU "package" (
            ECHO %%a=%dstDir%\%packageFile%;>>%destConfig%
        ) ELSE IF "%%a" EQU "build" (
            ECHO %%a=%buildNum%;>>%destConfig%
        ) ELSE IF "%%a" EQU "Version" (
            ECHO %%a=%ver%;>>%destConfig%
        ) ELSE IF "%%a" EQU "release_notes" (
            ECHO %%a=%dstDir%\%releaseNotesFile%;>>%destConfig%
        ) ELSE (
            ECHO %%a=%%b>>%destConfig%
        )
    ) ELSE (
        ECHO %%a>%destConfig%
    )
)

ROBOCOPY %srcDir% %dstDir% %packageFile% /W:5 /R:5

CHOICE /C yn /M "Are you done with Release Note?"
IF "%ERRORLEVEL%" EQU "1" (
    CHOICE /C yn /M "Are you sure you want to release?"
    IF "%ERRORLEVEL%" EQU "1" (
        ECHO Yes
    ) ELSE (
        ECHO No
    )
) ELSE (
    ECHO No
)