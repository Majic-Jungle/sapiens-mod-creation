local mjm = mjrequire "common/mjm"
local vec3 = mjm.vec3

local harvestable = mjrequire "common/harvestable"
local resource = mjrequire "common/resource"
local locale = mjrequire "common/locale"

local mod = {
    loadOrder = 1,
}

function mod:onload(gameObject)
    
	gameObject:addGameObjectsFromTable({
        deadMoa = {
            name = locale:get("object_deadMoa"),
            plural = locale:get("object_deadMoa_plural"),
            modelName = "moaDead",
            harvestableTypeIndex = harvestable.typeIndexMap.moa,
            scale = 1.0,
            hasPhysics = true,
            markerPositions = {
                { 
                    worldOffset = vec3(0.0, mj:mToP(1.0), 0.0)
                }
            },
        },
        
        moaMeat = {
            name = locale:get("object_moaMeat"),
            plural = locale:get("object_moaMeat_plural"),
            modelName = "moaMeat",
            scale = 1.0,
            hasPhysics = true,
            resourceTypeIndex = resource.types.moaMeat.index,
            markerPositions = {
                { 
                    worldOffset = vec3(0.0, mj:mToP(0.3), 0.0)
                }
            },
        },
        
        moaMeatLeg = {
            name = locale:get("object_moaMeat"),
            plural = locale:get("object_moaMeat_plural"),
            modelName = "moaMeatLeg",
            scale = 1.0,
            hasPhysics = true,
            resourceTypeIndex = resource.types.moaMeat.index,
            markerPositions = {
                { 
                    worldOffset = vec3(0.0, mj:mToP(0.3), 0.0)
                }
            },
        },
        
        moaMeatCooked = {
            name = locale:get("object_moaMeatCooked"),
            plural = locale:get("object_moaMeatCooked_plural"),
            modelName = "moaMeatCooked",
            scale = 1.0,
            hasPhysics = true,
            resourceTypeIndex = resource.types.moaMeatCooked.index,
            markerPositions = {
                { 
                    worldOffset = vec3(0.0, mj:mToP(0.3), 0.0)
                }
            },
        },
        
        moaMeatLegCooked = {
            name = locale:get("object_moaMeatCooked"),
            plural = locale:get("object_moaMeatCooked_plural"),
            modelName = "moaMeatLegCooked",
            scale = 1.0,
            hasPhysics = true,
            resourceTypeIndex = resource.types.moaMeatCooked.index,
            markerPositions = {
                { 
                    worldOffset = vec3(0.0, mj:mToP(0.3), 0.0)
                }
            },
        },

    })
end

return mod