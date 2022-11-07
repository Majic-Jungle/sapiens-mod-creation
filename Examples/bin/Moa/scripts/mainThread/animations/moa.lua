-- different types of animations are specified in common/animations, so the animations types can be assigned and used across all threads.
-- the list of keyframes here correspond with animation frames in the model file. So the moa model file contains a ~30 frame long animation, with each frame containing a unique pose.
-- Then those poses are named here, in the ordered keyframes enum below, and combined algorithmically in this lua module, for each animation specified in common/animations/moa.

-- proceduralType = 1 means that it will shuffle the keyframes. Without this, the animations are performed in the order given
-- for { keyframes.base, 0.4, {randomVariance = 0.4} }, the first parameter is the pose/keyframe, the second is the duration, and the third is a table of additional options
-- the engine will interpolate to the next key frame over the duration given.

-- additional options:
-- "randomVariance" is added to the base time. result = duration + randomFloatBetweenZeroAndOne * randomVariance
-- "trigger" calls a function every time that keyframe is hit, used for sounds and particle effects
-- "composites" can also be used here, to apply additional animations to individual specified bones over the top, eg. when a sapien waves while doing other things. See sapienCommon for an example

local model = mjrequire "common/model"
local animationGroups = mjrequire "common/animations/animationGroups"
local rng = mjrequire "common/randomNumberGenerator"
local audio = mjrequire "mainThread/audio"

local mainThreadAnimationGroup = {

}

local keyframes = mj:enum {
    "base", 
    "lookRight", 
    "lookLeft",
    "peck1",
    "peck2",
    "peckRight1",
    "peckRight2",
    "peckLeft1",
    "peckLeft2",
    "walk1",
    "walk2",
    "walk3",
    "walk4",
    "death1",
    "death2",
    "old_1",
    "old_2",
    "old_3",
    "old_4",
    "old_5",
    "old_6",
    "old_7",
    "old_8",
    "run1",
    "run2",
    "run3",
    "run4",
    "old_9",
    "old_10",
    "dead",
}


local animationTypes = animationGroups.moa.animations

mainThreadAnimationGroup.modelTypeIndex = model:modelIndexForModelNameAndDetailLevel("moa", 1)
mainThreadAnimationGroup.default = animationTypes.lookRight

local stepVolume = 0.2
local stepIndex = 1
local function playRandomSound(pos, name, max)
    local pitchOffset = 1.0 + (rng:randomValue() - 0.5) * 0.2
    if audio:playWorldSound("audio/sounds/" .. name .. mj:tostring(stepIndex) .. ".wav", pos, stepVolume, pitchOffset, 130) then
        stepIndex = stepIndex + 1
        if rng:randomBool() then
            stepIndex = stepIndex + 1
        end

        if stepIndex > max then
            stepIndex = (stepIndex % max) + 1
        end
    end
end

local function stepTrigger(objectPos)
    playRandomSound(objectPos, "moaStep", 3)
end

mainThreadAnimationGroup.animations = {
    [animationTypes.stand1] = {
        proceduralType = 1,
        keyframes = {
            { keyframes.base, 0.4, {randomVariance = 0.4} },
            { keyframes.base, 0.4, {randomVariance = 0.4} },
            { keyframes.lookRight, 0.4, {randomVariance = 1.4} },
            { keyframes.lookLeft, 0.4, {randomVariance = 1.4} },
            { keyframes.base, 0.4, {randomVariance = 0.4} },
            { keyframes.base, 0.4, {randomVariance = 0.8} },
            { keyframes.lookLeft, 0.4, {randomVariance = 3.8} },
            { keyframes.base, 0.4, {randomVariance = 1.8} },
            { keyframes.lookRight, 0.4, {randomVariance = 3.8} },
        },
    },
    [animationTypes.peckRight] = {
        keyframes = {
            { keyframes.base, 0.8, {randomVariance = 0.4}  },
            { keyframes.base, 0.2, {randomVariance = 0.2}  },
            { keyframes.peckRight1, 0.2, {randomVariance = 0.2} },
            { keyframes.peckRight2, 0.2, {randomVariance = 0.4} },
            { keyframes.peckRight1, 0.2, {randomVariance = 0.4} },
            { keyframes.peckRight2, 0.2, {randomVariance = 0.4} },
            { keyframes.base, 0.4, {randomVariance = 0.4} },
            { keyframes.lookRight, 0.4, {randomVariance = 0.4} },
            { keyframes.peckRight1, 0.2, {randomVariance = 0.2} },
            { keyframes.peckRight2, 0.2, {randomVariance = 0.4} },
            { keyframes.peckRight1, 0.2, {randomVariance = 2.4} },
            { keyframes.peckRight2, 0.2, {randomVariance = 2.4} },
            { keyframes.peckRight1, 0.1, {randomVariance = 1.4} },
            { keyframes.peckRight2, 0.1, {randomVariance = 1.4} },
            { keyframes.lookLeft, 0.4, {randomVariance = 0.4} },
            { keyframes.base, 0.4, {randomVariance = 0.4} },
            { keyframes.base, 0.4, {randomVariance = 0.8} },
            { keyframes.lookLeft, 0.4, {randomVariance = 1.8} },
            { keyframes.base, 0.4, {randomVariance = 1.8} },
            { keyframes.lookRight, 0.4, {randomVariance = 1.8} },
        },
    },
    [animationTypes.peckLeft] = {
        keyframes = {
            { keyframes.base, 0.8, {randomVariance = 0.4}  },
            { keyframes.base, 0.2, {randomVariance = 0.2}  },
            { keyframes.peckLeft1, 0.2, {randomVariance = 0.4} },
            { keyframes.peckLeft2, 0.2, {randomVariance = 0.4} },
            { keyframes.peckLeft1, 0.2, {randomVariance = 0.4} },
            { keyframes.peckLeft2, 0.2, {randomVariance = 0.4} },
            { keyframes.base, 0.4, {randomVariance = 0.4} },
            { keyframes.peckLeft1, 0.2, {randomVariance = 0.2} },
            { keyframes.peckLeft2, 0.2, {randomVariance = 0.4} },
            { keyframes.peckLeft1, 0.2, {randomVariance = 2.4} },
            { keyframes.peckLeft2, 0.2, {randomVariance = 2.4} },
            { keyframes.peckLeft1, 0.1, {randomVariance = 1.4} },
            { keyframes.peckLeft2, 0.1, {randomVariance = 1.4} },
            { keyframes.base, 0.4, {randomVariance = 0.8} },
            { keyframes.lookLeft, 0.4, {randomVariance = 1.8} },
            { keyframes.base, 0.4, {randomVariance = 1.8} },
            { keyframes.lookRight, 0.4, {randomVariance = 1.8} },
        },
    },
    [animationTypes.peckRandom] = {
        proceduralType = 1,
        keyframes = {
            { keyframes.base, 0.4, {randomVariance = 0.8}  },
            { keyframes.base, 0.4, {randomVariance = 0.8}  },
            { keyframes.base, 0.4, {randomVariance = 0.8}  },
            { keyframes.base, 0.4, {randomVariance = 0.8}  },
            { keyframes.base, 0.4, {randomVariance = 0.8}  },
            { keyframes.base, 0.4, {randomVariance = 0.8}  },
            { keyframes.lookRight, 0.8, {randomVariance = 0.4} },
            { keyframes.lookRight, 0.8, {randomVariance = 0.4} },
            { keyframes.lookLeft, 0.8, {randomVariance = 0.4} },
            { keyframes.lookLeft, 0.2, {randomVariance = 0.2} },
            { keyframes.peck1, 0.2, {randomVariance = 0.4} },
            { keyframes.peck2, 0.2, {randomVariance = 0.4} },
            { keyframes.peckLeft1, 0.2, {randomVariance = 0.4} },
            { keyframes.peckLeft2, 0.2, {randomVariance = 0.4} },
            { keyframes.peckRight1, 0.2, {randomVariance = 0.4} },
            { keyframes.peckRight2, 0.2, {randomVariance = 0.2} },
        },
    },
    [animationTypes.walk] = {
        keyframes = {
            { keyframes.walk1, 0.4, { trigger = stepTrigger } },
            { keyframes.walk2, 0.2 },
            { keyframes.walk3, 0.4, { trigger = stepTrigger } },
            { keyframes.walk4, 0.2 },
        },
    },
    [animationTypes.run] = {
        keyframes = {
            { keyframes.run1, 0.4, { trigger = stepTrigger } },
            { keyframes.run2, 0.4 },
            { keyframes.run3, 0.4, { trigger = stepTrigger } },
            { keyframes.run4, 0.4 },
        },
    },
    [animationTypes.die] = {
        keyframes = {
            { keyframes.death1, 0.1 },
            { keyframes.death2, 0.1 },
            { keyframes.dead, 0.1 },
            { keyframes.dead, 1.0 },
            { keyframes.dead, 1.0 },
            { keyframes.dead, 1.0 },
            { keyframes.dead, 1.0 },
            { keyframes.dead, 1.0 },
        },
    },
    [animationTypes.dead] = {
        keyframes = {
            { keyframes.dead, 0.5 },
        },
    },
    [animationTypes.attack] = {
        keyframes = {
            { keyframes.base, 0.2, {randomVariance = 0.2}  },
            { keyframes.peck1, 0.2, {randomVariance = 0.4} },
            { keyframes.base, 0.2, {randomVariance = 0.2}  },
            { keyframes.peckLeft1, 0.2, {randomVariance = 0.4} },
            { keyframes.base, 0.2, {randomVariance = 0.2}  },
            { keyframes.peckRight1, 0.2, {randomVariance = 0.4} },
            { keyframes.base, 0.2, {randomVariance = 0.2}  },
        },
    },
}

return mainThreadAnimationGroup
