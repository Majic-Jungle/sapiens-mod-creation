
local gameObject = mjrequire "common/gameObject"

local mod = {
    loadOrder = 1,
}


function mod:onload(evolvingObject)
    
    local prevInit = evolvingObject.init
    evolvingObject.init = function(evolvingObject_, dayLength, yearLength)
        prevInit(evolvingObject_, dayLength, yearLength)

        evolvingObject.evolutions[gameObject.types.deadMoa.index] = {
            minTime = yearLength,
            toTypes = {
                gameObject.types.bone.index,
                gameObject.types.bone.index,
            },
            categoryIndex = evolvingObject.categories.rot.index,
        }

        
        evolvingObject.evolutions[gameObject.types.moaMeat.index] = {
            minTime = yearLength * 0.5,
            toType = gameObject.types.bone.index,
            categoryIndex = evolvingObject.categories.rot.index,
        }

        evolvingObject.evolutions[gameObject.types.moaMeatLeg.index] = {
            minTime = yearLength * 0.5,
            toType = gameObject.types.bone.index,
            categoryIndex = evolvingObject.categories.rot.index,
        }

        evolvingObject.evolutions[gameObject.types.moaMeatCooked.index] = {
            minTime = yearLength * 0.5,
            toType = gameObject.types.bone.index,
            categoryIndex = evolvingObject.categories.rot.index,
        }

        evolvingObject.evolutions[gameObject.types.moaMeatLegCooked.index] = {
            minTime = yearLength * 0.5,
            toType = gameObject.types.bone.index,
            categoryIndex = evolvingObject.categories.rot.index,
        }
    end
end

return mod