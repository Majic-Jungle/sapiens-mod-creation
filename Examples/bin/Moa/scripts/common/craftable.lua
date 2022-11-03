local mjm = mjrequire "common/mjm"
local vec3 = mjm.vec3
local vec3xMat3 = mjm.vec3xMat3
local mat3Identity = mjm.mat3Identity
local mat3Rotate = mjm.mat3Rotate
--local mat3Inverse = mjm.mat3Inverse

local constructable = mjrequire "common/constructable"
local locale = mjrequire "common/locale"
local resource = mjrequire "common/resource"
local actionSequence = mjrequire "common/actionSequence"
local skill = mjrequire "common/skill"
local craftAreaGroup = mjrequire "common/craftAreaGroup"

local mod = {
    loadOrder = 1,
}

function mod:onload(craftable)
    local prevLoad = craftable.load
    craftable.load = function(craftable_, gameObject, flora)
        prevLoad(craftable_, gameObject, flora)

        craftable:addCraftable("cookedMoa", {
            name = locale:get("craftable_cookedMoa"),
            plural = locale:get("craftable_cookedMoa_plural"),
            summary = locale:get("craftable_cookedMoa_summary"),
            iconGameObjectType = gameObject.typeIndexMap.moaMeatLegCooked,
            classification = constructable.classifications.craft.index,
            isFoodPreperation = true,
            disabledUntilCraftableResearched = true,
    
            outputObjectInfo = {
                outputArraysByResourceObjectType = {
                    [gameObject.typeIndexMap.moaMeat] = {
                        gameObject.typeIndexMap.moaMeatCooked,
                    },
                    [gameObject.typeIndexMap.moaMeatLeg] = {
                        gameObject.typeIndexMap.moaMeatLegCooked,
                    },
                }
            },
            buildSequence = craftable:createStandardBuildSequence(actionSequence.types.fireStickCook.index, nil),
            inProgressBuildModel = "craftSimple",
    
            skills = {
                required = skill.types.campfireCooking.index,
            },
    
            requiredResources = {
                {
                    type = resource.types.moaMeat.index,
                    count = 1,
                },
            },
    
            requiredCraftAreaGroups = {
                craftAreaGroup.types.campfire.index,
            },
    
            attachResourceToHandIndex = 1,
            attachResourceOffset = vec3xMat3(vec3(-0.7,0.1,0.02), craftable.cookingStickRotationOffset),
            attachResourceRotation = mat3Rotate(mat3Identity, math.pi * 0.5, vec3(0.0,0.0,1.0)),
    
            temporaryToolObjectType = gameObject.typeIndexMap.stick,
            temporaryToolOffset = vec3xMat3(vec3(-0.35,0.0,0.0), craftable.cookingStickRotationOffset),
            temporaryToolRotation = craftable.cookingStickRotation,
        })
    end
end

return mod