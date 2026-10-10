## I am unable to test future Revived builds due to the fact I no longer own a Oculus VR headset that is usable. Please make a GitHub issue if you are able to test.
## Use the issues tab to suggest features or fixes. I do not know what to fix or add right now.
# Revived Compatibility Layer
A fork of Revive meant to fix most issues in Revive, and to add some features. Wikis in this readme point to LibreVR's, it is not obsolete. (yet)

This is a compatibility layer between the Oculus SDK and OpenVR/OpenXR. It allows you to play Oculus-exclusive games on your HTC Vive or Valve Index.

Fork of [LibreVR/Revive](https://github.com/LibreVR/Revive) by CrossVR and contributors.

## Changes in this fork

This repository ([ThePhaseless/Revived](https://github.com/ThePhaseless/Revived)) is a fork of [cfm-miku-en/Revived](https://github.com/cfm-miku-en/Revived). On top of it, it adds:

- **Input focus after the SteamVR dashboard:** Revive only updated a game's input focus, dashboard state and connected controllers when SteamVR sent an event, and right after the dashboard closes SteamVR can still report that input is unavailable. Games could then stay without input focus for good, e.g. Lone Echo II's UI pointer never came back after opening the dashboard. These values are now re-read every time the game polls its session status.
- **Sturdier tracking data:** when the compositor can't provide poses for the requested frame they are predicted from the current time instead of using the failed lookup's output, accelerations no longer divide by a zero time step, non-finite poses are reported as untracked, and losing tracking holds the last known pose instead of snapping to the origin.
- **VS2022 build fixes.**
- **Automatic builds:** every push is built by [GitHub Actions](https://github.com/ThePhaseless/Revived/actions/workflows/build.yml). Open a run and download the installer or the runtime binaries from its Artifacts section (requires signing in to GitHub). These builds are untested nightlies, the installer will warn about that.

[Refer to the wiki](https://github.com/LibreVR/Revive/wiki) if you run into any problems. You can also find a [community-compiled list of working games on the wiki](https://github.com/LibreVR/Revive/wiki/Compatibility-list), feel free to add your own results.

## Installation

*Always check the [compatibility list](https://github.com/LibreVR/Revive/wiki/Compatibility-list) before making a purchase.*

1. Download and install [Oculus Rift Software](https://www.oculus.com/rift/setup/). When you get to "Select Your Headset", choose to "Skip".
2. [Download the latest Revived installer.](https://github.com/cfm-miku-en/Revived/releases/latest)
3. Install Revived in your preferred directory.
4. Start SteamVR if it's not already running.
5. Put on the headset, open the dashboard and click the new Revived tab.
6. If you run into any problems, read the known issues below or refer to the [wiki](https://github.com/LibreVR/Revive/wiki).

## Known Issues

- Newly installed applications may refuse to start when you try to launch them for the first time, [simply follow these instructions to fix it](https://github.com/LibreVR/Revive/wiki/Troubleshooting#im-getting-an-entitlement-error-or-oculus-rift-not-found) or reboot your PC.
- If you don't see the Revived tab, go to the start menu on your desktop and start the Revived Dashboard. Or check the Applications tab in the SteamVR settings to see if the tab is enabled.
