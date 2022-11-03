
local model = mjrequire "common/model"
local animationGroups = mjrequire "common/animations/animationGroups"
--local rng = mjrequire "common/randomNumberGenerator"

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


mainThreadAnimationGroup.animations = {
    [animationTypes.stand1] = {
        proceduralType = 1,
        keyframes = {
            { keyframes.base, 0.4, {randomVariance = 0.4} },
            { keyframes.lookRight, 0.4, {randomVariance = 0.4} },
            { keyframes.lookLeft, 0.4, {randomVariance = 0.4} },
        },
    },
    [animationTypes.peckRight] = {
        proceduralType = 1,
        keyframes = {
            { keyframes.base, 0.8, {randomVariance = 0.4}  },
            { keyframes.peckRight1, 0.4, {randomVariance = 0.4} },
            { keyframes.peckRight2, 0.4, {randomVariance = 0.4} },
            { keyframes.peckRight1, 0.4, {randomVariance = 0.4} },
            { keyframes.peckRight2, 0.4, {randomVariance = 0.4} },
        },
    },
    [animationTypes.peckLeft] = {
        proceduralType = 1,
        keyframes = {
            { keyframes.base, 0.8, {randomVariance = 0.4}  },
            { keyframes.peckLeft1, 0.4, {randomVariance = 0.4} },
            { keyframes.peckLeft2, 0.4, {randomVariance = 0.4} },
            { keyframes.peckLeft1, 0.4, {randomVariance = 0.4} },
            { keyframes.peckLeft2, 0.4, {randomVariance = 0.4} },
        },
    },
    [animationTypes.peckRandom] = {
        proceduralType = 1,
        keyframes = {
            { keyframes.base, 0.8, {randomVariance = 0.4}  },
            { keyframes.lookRight, 0.8, {randomVariance = 0.4} },
            { keyframes.lookLeft, 0.8, {randomVariance = 0.4} },
            { keyframes.peck1, 0.4, {randomVariance = 0.4} },
            { keyframes.peck2, 0.4, {randomVariance = 0.4} },
            { keyframes.peck1, 0.4, {randomVariance = 0.4} },
            { keyframes.peck2, 0.4, {randomVariance = 0.4} },
            { keyframes.peckLeft1, 0.4, {randomVariance = 0.4} },
            { keyframes.peckLeft2, 0.4, {randomVariance = 0.4} },
            { keyframes.peckRight1, 0.4, {randomVariance = 0.4} },
            { keyframes.peckRight2, 0.4, {randomVariance = 0.4} },
        },
    },
    [animationTypes.walk] = {
        keyframes = {
            { keyframes.walk1, 0.2 },
            { keyframes.walk2, 0.4 },
            { keyframes.walk3, 0.2 },
            { keyframes.walk4, 0.4 },
        },
    },
    [animationTypes.run] = {
        keyframes = {
            { keyframes.run1, 0.4 },
            { keyframes.run2, 0.4 },
            { keyframes.run3, 0.4 },
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
}

return mainThreadAnimationGroup
