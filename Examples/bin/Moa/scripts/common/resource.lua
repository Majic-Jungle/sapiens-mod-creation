local typeMaps = mjrequire "common/typeMaps"
local locale = mjrequire "common/locale"

local mod = {
    loadOrder = 1,
}

function mod:onload(resource)
    
    local gameObjectTypeIndexMap = typeMaps.types.gameObject

    typeMaps:insert("resource", resource.types, {
        key = "moaMeat",
        name = locale:get("resource_moaMeat"),
        plural = locale:get("resource_moaMeat_plural"),
        foodValue = 0.5,
        foodPortionCount = 4,
        defaultToEatingDisabled = true,
        foodPoisoningChance = 0.2,
        displayGameObjectTypeIndex = gameObjectTypeIndexMap.moaMeatLeg,
		isRawMeatForTutorial = true,
    })
    typeMaps:insert("resource", resource.types, {
        key = "moaMeatCooked",
        name = locale:get("resource_moaMeatCooked"),
        plural = locale:get("resource_moaMeatCooked_plural"),
        foodValue = 0.7,
        foodPortionCount = 4,
        displayGameObjectTypeIndex = gameObjectTypeIndexMap.moaMeatLegCooked,
		isCookedMeatForTutorial = true,
    })
end

return mod