-- different types of animations are specified here in common, so the animations types can be assigned and used across all threads.
-- the configuration for each animation is in mainThread/animations

local animations = mj:enum {
    "stand1", 
    "peckRight",
    "peckLeft",
    "peckRandom",
    "walk",
    "run",
    "die",
    "dead",
    "attack",
}

animations.uiAnimation = animations.stand1

return animations