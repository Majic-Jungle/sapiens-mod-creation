local mjm = mjrequire "common/mjm"
local vec3 = mjm.vec3
local locale = mjrequire "common/locale"

local mobMoa = {}

function mobMoa:load(mob, gameObject)
    mob:addType("moa", {
        
        deadObjectTypeIndex = gameObject.typeIndexMap.deadMoa,

        initialHealth = 7.9,
        spawnFrequency = 0.4,
        spawnDistance = mj:mToP(600.0), --heard will spawn approx this distance away from some sapien, then walk moderately close, pass by and despawn this same distance further on
        minSapienProximityDistanceForSpawning = mj:mToP(50.0),
        
        reactDistance = mj:mToP(50.0),
        runDistance = mj:mToP(15.0),
        agroDistance = mj:mToP(1.0),
        attackDistance = mj:mToP(2.0), --the existence of this is also used to determine if mob is hostile

        agroTimerDuration = 3.0,
        aggresionLevel = 1, -- nil or 0 will always run away from moderately close sapiens. 1 will hold ground sometimes, and also charge at the sapien when agro.

        pathFindingRayRadius = mj:mToP(1.0),
        pathFindingRayYOffset = mj:mToP(2.0),
        walkSpeed = mj:mToP(1.5),
        runSpeedMultiplier = 4.0,
        rotationSpeedMultiplier = 1.5,
        embedBoxHalfSize = vec3(0.5,1.0,0.5),
        
        maxSoundDistance2 = mj:mToP(100.0) * mj:mToP(100.0),
        soundVolume = 0.4,
        soundRandomBaseName = "moa",
        soundRandomBaseCount = 3,
        soundAngryBaseName = "moaAngry",
        soundAngryBaseCount = 1,
        deathSound = "moaAngry1",
        
        pooFrequencyDays = 1,
        pooQuantity = 1,
        
        maxHunterAssignCount = 5,
        
        animationGroup = "moa",
        idleAnimations = {
            "stand1", 
            --"peckRight",
            --"peckLeft",
            --"peckRandom",
        },

        agroIdleAnimations = {
            "stand1",
            --"stand2",
            --"stand3",
            --"stand4",
        },

        sleepAnimations = {
            "stand1",
        },
        
        runAnimation = "run",
        deathAnimation = "die",

        agroWalkAnimation = "run",
        
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
                    worldOffset = vec3(0.0, mj:mToP(2.8), 0.0)
                }
            },
        },
    })
end

return mobMoa

