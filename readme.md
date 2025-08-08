# Alpakka Firmware

*Alpakka controller reference firmware (for Raspberry Pi Pico)*
## Project links
- [Alpakka Manual](https://inputlabs.io/devices/alpakka/manual).
- [Alpakka Firmware](https://github.com/inputlabs/alpakka_firmware). _(you are here)_
- [Alpakka PCB](https://github.com/inputlabs/alpakka_pcb).
- [Alpakka 3D-print](https://github.com/inputlabs/alpakka_case).
- [Input Labs Roadmap](https://github.com/orgs/inputlabs/projects/2/views/2).

## Documentation
- **API Documentation**: Generated using Doxygen. Run `make docs` to generate the latest documentation, then open `docs/doxygen/html/index.html` in your browser.
- **Development Guide**: See [docs/README.md](docs/README.md) for detailed documentation generation instructions.

## Supported developer operative systems
- GNU/Linux (and MacOS) - See [Development in Linux](https://inputlabs.io/devices/alpakka/manual/dev_unix).
- Windows - See [Development in Windows](https://inputlabs.io/devices/alpakka/manual/dev_windows).

## System dependencies
With `apt`, `rpm`, `pacman`, `brew`, or the equivalent package manager of your system, install:
- **gcc**
- **git**
- **cmake**

## Project dependencies
- `make install`: Download and configure dependencies automatically.

## Compilation targets
- `alpakka_v0`: Alpakka v0.x.x with Raspberry Pico.
- `alpakka_v1`: Alpakka v1.x.x with Marmota module.
- `dongle`: Wireless dongle.
- `llama`: ESP wireless module flasher (ESP-LLAMA repository).

Example usage:
```
DEVICE=alpakka_v1 make
```

## Development commands
- `DEVICE=<device> make`: Build compilation environment and build executables.
- `make rebuild`: Build executables again using cache (faster).
- `make load`: Load built .uf2 file into the Pico (requires bootsel mode or active session).
- `make reload`: Do both `rebuild` and `load` commands (for dev convenience).
- `make clean`: Delete previous build files.
- `make session`: Connect to UART serial stdio, and display controller log.

While having an active session:
- `make restart`: Restart the controller.
- `make bootsel`: Put the controller in bootsel mode.
- `make calibrate`: Calibrate thumbstick and IMUs.
- `make format`: Format NVM sector and reset to initial values.
- `make test`: Start a semi-manual testing procedure for the buttons and axis.

## Devkit button
- Single press: Restart the controller.
- Double press: Put the controller in bootsel mode.

Read the [Alpakka developer manual](https://inputlabs.io/devices/alpakka/manual/dev) for details about the **devkit** and more.
