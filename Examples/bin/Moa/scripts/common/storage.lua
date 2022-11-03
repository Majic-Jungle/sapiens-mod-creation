local mjm = mjrequire "common/mjm"
local vec3 = mjm.vec3
local mat3Identity = mjm.mat3Identity
local mat3Rotate = mjm.mat3Rotate

local rng = mjrequire "common/randomNumberGenerator"
local typeMaps = mjrequire "common/typeMaps"
local locale = mjrequire "common/locale"
local resource = mjrequire "common/resource"

local mod = {
    loadOrder = 1,
}

function mod:onload(storage)
    
    local gameObjectTypeIndexMap = typeMaps.types.gameObject

    typeMaps:insert("storage", storage.types, {
        key = "moaMeat",
        name = locale:get("storage_moaMeat"),
        displayGameObjectTypeIndex = gameObjectTypeIndexMap.moaMeatLeg,
        resources = {
            resource.types.moaMeat.index,
            resource.types.moaMeatCooked.index,
        },
        storageBox = {
			size =  vec3(0.9, 0.2, 0.33),
			rotationFunction = function(uniqueID, seed)
				local randomValue = rng:valueForUniqueID(uniqueID, seed)
				local rotation = mat3Rotate(mat3Identity, randomValue * 0.4 - 0.2, vec3(0.0,1.0,0.0))
                rotation = mat3Rotate(rotation, -randomValue * 0.2 - 0.4, vec3(1.0,0.0,0.0))
				return rotation
			end,
        },
        maxCarryCount = 1,
        maxCarryCountLimitedAbility = 1,
        maxCarryCountForRunning = 1,
		carryOffset = vec3(-0.04,0.09,0.1),
        carryRotation = mat3Rotate(mat3Rotate(mat3Identity, 1.0, vec3(0.0, 0.0, 1.0)), -0.5, vec3(0.0, 1.0, 0.0)),
    })
end

return mod