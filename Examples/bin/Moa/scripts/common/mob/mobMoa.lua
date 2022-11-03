local mjm = mjrequire "common/mjm"
local vec3 = mjm.vec3
--local tool = mjrequire "common/tool"
--local plan = mjrequire "common/plan"
--local skill = mjrequire "common/skill"
local locale = mjrequire "common/locale"
local animationGroups = mjrequire "common/animations/animationGroups"

local mobMoa = {}

function mobMoa:load(mob, gameObject)
    mob:addType("moa", {
        
        deadObjectTypeIndex = gameObject.typeIndexMap.deadMoa,

        initialHealth = 0.4,
        spawnFrequency = 1.0,
        spawnDistance = mj:mToP(200.0),
        
        reactDistance = mj:mToP(50.0),
        agroDistance = mj:mToP(1.0),
        runDistance = mj:mToP(15.0),

        agroTimerDuration = 3.0,
        aggresionLevel = nil,

        pathFindingRayRadius = mj:mToP(0.2),
        pathFindingRayYOffset = mj:mToP(0.2),
        walkSpeed = mj:mToP(2.5),
        runSpeedMultiplier = 4.0,
        embedBoxHalfSize = vec3(0.1,0.1,0.1),
        
        maxSoundDistance2 = mj:mToP(100.0) * mj:mToP(100.0),
        soundVolume = 0.4,
        soundRandomBaseName = "chicken",
        soundRandomBaseCount = 4,
        soundAngryBaseName = "chickenAngry",
        soundAngryBaseCount = 1,
        deathSound = "chickenDie",
        
        animationGroupIndex = animationGroups.moa.index,
        idleAnimations = {
            "stand1", 
            "peckRight",
            "peckLeft",
            "peckRandom",
        },

        sleepAnimations = {
            "stand1",
        },
        
        runAnimation = "run",
        deathAnimation = "die",
        
        addGameObjectInfo = {
            name = locale:get("mob_moa"),
            plural = locale:get("mob_moa_plural"),
            modelName = "moa",
            mobTypeIndex = mob.typeIndexMap.moa,
            projectileAimHeightOffsetMeters = 0.2,
            scale = 1.0,
            hasPhysics = false,
			ignoreBuildRay = true,
            markerPositions = {
                { 
                    worldOffset = vec3(0.0, mj:mToP(0.8), 0.0)
                }
            },
        },
    })
end

return mobMoa

