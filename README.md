# Sapiens Mod Creation Tools
This is the official tools and examples for mod creation in the game [Sapiens](https://playsapiens.com)

The tools and this readme are an extremely early work in progress, the game isn't out yet, and there is no way to test any created mods without the game. So for now, you can have a look around, maybe try to compile a C mod, and let me (Dave) know on the [Sapiens Discord](https://discord.gg/VAkYw2r) if you have any problems.

# Overview

Currently only the C plugin (SPlugins) API is available.  Lua tools are coming later, and will offer a much easier method of modding, with a lot more flexibility.

# SPlugins

C Plugins (SPlugins) in Sapiens are only intended for performance intensive tasks, and at the moment that is per vertex terrain generation/biome and climate assignment, and the particle engine.

In the SPlugins directory, you will the SPCommon library. SPCommon is the common code used by both the game engine and plugins, including math, Perlin noise functions and random number generation. This source repository includes the pre-built libraries and the required includes for using SPCommon. It also contains the source and projects for building SPCommon, though you shouldn't need to do that, it's only included for reference and debugging purposes. 

In SPlugins/Examples you will find SPVanilla. This is the vanilla/default plugin code, which is used by the game if no mods are installed. To create your own SPlugin library for inclusion in a mod, you would create a similar project that then overrode one or more of those functions.

# Windows/Linux/Client/Server

More information on this will be added later, but the plan is to release the server for both Windows and Linux (testing on Ubuntu only). At the moment, there will only be a Windows game client, though this could change later.

Example VS2017 solutions are provided to compile mods for Windows, and the same dll can be used for both the client and the standalone Windows server. For Linux it is using cmake to create a .so library, which only needs to be used by standalone servers.