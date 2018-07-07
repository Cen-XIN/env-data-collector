# EnvDataCollector
A simple program for environment data collecting (temperature, humidity, CO2, etc.). DB &amp; UART required

Specifically speaking, this program contains the following functions:

1. Read data from sensors;

2. Parse raw data;

3. Save data onto database.

# Updates
## Version 1.0
I've just uploaded all the raw codes, which means I haven't tested them yet. So please be careful when using my code, it may damage your UART or sensors.

Generally I designed 3 units for it:

1. 'dbcomm' for communicating with database, mainly for sending data to it;

2. 'parser' for transforming raw data read from UART to different types that we need;

3. 'uart' for basic operation on UART, such as open, read, write and close.

Well I got a really tight schedule these days. Not much time for me to revise these codes in the next few weeks or so.

But I'll go on for it at the end of August (I swear : P)

For any question, just contact me through e-mail : )
