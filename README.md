# Sapiens Mod Creation Tools
This is the official tools and examples for mod creation in the upcoming game [Sapiens](https://playsapiens.com)

The tools and this readme are an extremely early work in progress, the game isn't out yet, and there is no way to test any created mods without the game. So for now, you can have a look around, maybe try to compile a C mod, and let me (Dave) know on the [Sapiens Discord](https://discord.gg/VAkYw2r) if you have any problems.

# Overview

Sapiens is designed with modding in mind, to the extent that a mod could actually create a whole different kind of game. Nearly half of the game's code is written in Lua, and pretty much all of that code can be overridden. All of the game's shaders, images, models, sounds, and fonts can also be replaced or added to, and there is also a C based plugin system  to allow even more flexibility where performance matters in areas like terrain generation, biome assignment, and the particle engine.

# Lua

Mods that wish to override or add Lua code can do so by creating their lua files in a directory structure that mirrors the game's scripts directory. More documentation will be added on this later, but for now you can have a look at the scripts directory in the BlueUI-Lua-app-example.

All you need to do is place the lua scripts in the right place, and they will get loaded. The vanilla lua code is always loaded first, and then the mod files are loaded, and mod:onload() is called, passing the vanilla module as an argument. This allows the mod to replace any data and/or functions of the vanilla object.

# Resources

If you wish to override any of the vanilla shaders, sounds, images etc. then you do so again by mirroring the game's directory structure, and placing the resources within.

# C Mods

C Mods in Sapiens are intended for performance intensive tasks, and at the moment that is per vertex terrain generation/biome and climate assignment, and the particle engine.

In the SPlugins directory, is the SPCommon library. SPCommon is the common code used by both the game engine and plugins, including math, Perlin noise functions and random number generation. This source repository includes the pre-built libraries and the required includes for using SPCommon. It also contains the source and projects for building SPCommon, though you shouldn't need to do that, it's only included for reference and debugging purposes. 

In SPlugins/Examples you will find SPVanilla. This is the vanilla/default plugin code, which is used by the game if no mods are installed. To create your own SPlugin library for inclusion in a mod, you would create a similar project that then overrode one or more of those functions.

# modInfo.lua

Every mod needs a modInfo.lua file. This is hopefully pretty self explanatory, you just need to populate it with your own values. There are two types of mod that you specify in the "type" field, "world" or "app". 

"world" should be used for anything that modifies the behavior of the world, anything that should be saved alongside the world's save data files, or anything that requires the server and client to agree. 

"app" should be used for usability type mods, things that players would want to install across all of their worlds, and that don't affect the world save data in any way, so can be switched on and off without consequence.

# Windows/Linux/Client/Server

More information on this will be added later, but the plan is to release the server for both Windows and Linux (testing on Ubuntu only). At the moment, there will only be a Windows game client, though this could change later.

Example VS2017 solutions are provided to compile mods for Windows, and the same dll can be used for both the client and the standalone Windows server. For Linux it is using cmake to create a .so library, which only needs to be used by standalone servers.