[![Gitter](https://badges.gitter.im/janbar/noson-app.svg)](https://gitter.im/janbar/noson-app?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge)
[![Build Status](https://travis-ci.org/janbar/noson-app.svg?branch=master)](https://travis-ci.org/janbar/noson-app)

## Noson
A fast and smart SONOS controller for Linux platforms.

Go to [project page](http://janbar.github.io/noson-app/index.html) for further details. Translations are managed by **transifex** at [noson-translations](https://www.transifex.com/janbar/noson/).

<p align="center">
  <img src="http://janbar.github.io/noson-app/download/noson3.png"/>
<p>

## Build instructions

The build can be achieved on any platform supporting Qt version 5.9. See `debian/control` file for more details about dependencies.

### Linux/BSD

- Install the packages `libpulse-dev`, `libflac-dev`, `libflac++-dev` to enable the stream output feature. 
- `git clone https://github.com/janbar/noson-app.git`
- `cd noson-app && mkdir build && cd build`
- `cmake -DCMAKE_BUILD_TYPE=Release ..`
- `make -j5`
- `sudo make install`

The noson-app files will be placed in `/usr/local/bin` `/usr/local/lib/${ARCH}` `/usr/local/share`.

## Enabling debug output

Launch the *Noson* application from command line as follows.

- `noson-app --debug 2>&1 | tee noson.log`

Also that will write debug output into the file `noson.log`. **Please be carefull to not paste debug log on public area before cleaning it from any credentials**. Debugging registration of music services will log entered credentials.

