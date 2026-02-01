HEXAGON Honey Pot Antivirus (v0.0.2) is totally open-source.

Only for Linux. No Windows, please.

On this stage of development it is not even an antivirus, just basic commands on C.

It's an antivirus, that create honeypots (fake-processes), that lures viruses into it and analyse.
This is also one of most important features in HEXAGON: HEXAGON scans the virus, block it on PC and sent all data of the virus to "HEXAGON Virus DataBase".

HEXAGON Virus DataBase - place, where is all data of scanned viruses. If HEXAGON on the other PC see the same data of virus, which in database, he's automatically block this.

```Please, do not use this now. You can test this, but this is NOT antivirus by now.

-----

If you want to test this, you need:

Linux
GCC or CMake
Make

You just to need clone this repository in somewhat directory. "cd" into it and run it by command:
make

-----

Available commands (v0.0.2):
./hexagon help
./hexagon version
./hexagon status (just text now, so ts is not even important)
./hexagon honeypot start (also just text)
./hexagon honeypot stop (...again text.)
