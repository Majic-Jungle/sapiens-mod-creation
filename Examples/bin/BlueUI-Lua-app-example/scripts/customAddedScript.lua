-- this lua file is an example to show that you can create and mjrequire your own scripts too.
-- Added scipts like these shouldn't contain an onLoad function (use mjInit instead)
-- These added scripts can then be modded by other mods, using the same method as they would use to mod vanilla scripts
-- If two different mods add a script with the same file name, and neither has an onLoad function (which would signify it is meant to mod an existing script), then an undefined one will win, the other will not be loaded.
-- So please try to give these scripts unique file names, eg. by prefixing with an identifier for your mod.

local customAddedScript = {}

customAddedScript.success = true

return customAddedScript