--luacheck: globals globals max_line_length unused_args ignore

-- This file isn't requirted in a Sapiens mod. It is a configuration file that can be used to help develop Lua mods. 
-- If you use VSCode to edit the lua code in a mod, you can install the vscode-lua extension and configure the luacheck path.
-- Doing this and leaving this .luacheckrc file here will give you much better linting warnings while you edit lua code.

globals = {

    "mjNoise", -- mjNoise(seed, persistance)

    "LuaEnvironment",
    "mj",
    "mjrequire",

    "Database",
    "MJCache",

    "fileUtils",

    "MeshTypeUndefined",
    "MeshTypeTerrain",
    "MeshTypeGameObject",

    "PHYSICS_TYPE_NONE",
    "PHYSICS_TYPE_STATIC_MESH",
    "PHYSICS_TYPE_STATIC_BOX",
    "PHYSICS_TYPE_DYNAMIC_BOX",
    "PHYSICS_TYPE_STATIC_MODEL_COLLIDERS",
    "RENDER_TYPE_NONE",
    "RENDER_TYPE_STATIC",
    "RENDER_TYPE_STATIC_TRANSPARENT_BUILD",
    "RENDER_TYPE_DYNAMIC",

    "VEGETATION_STATE_DEFAULT",
    "VEGETATION_STATE_ALL_STRIPPED",

    "GameStateMainMenu",
    "GameStateLoading",
    "GameStateLoadedRunning",
    "GameStateLoadedPaused",

    "View",
    "ColorView",
    "ImageView",
    "TextView",
    "GameObjectView",
    "ModelView",
    "ModelTextView",
    "ModelImageView",
    "GlobeView",

    "Font",

    "ViewPosition",
    "MJPositionCenter",
    "MJPositionInnerLeft",
    "MJPositionInnerRight",
    "MJPositionOuterLeft",
    "MJPositionOuterRight",
    "MJPositionBottom",
    "MJPositionTop",
    "MJPositionAbove",
    "MJPositionBelow",

    "MJHorizontalAlignmentLeft",
    "MJHorizontalAlignmentCenter",
    "MJHorizontalAlignmentRight",

    -- debug global functions
    "logPlayer",
    "setSunrise",
    "setSunset",
    --end
}

max_line_length = false
unused_args = false

ignore = {"311", "331", "611", "612", "613", "614"}