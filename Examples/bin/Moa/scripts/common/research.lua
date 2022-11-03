
local order = mjrequire "common/order"
local locale = mjrequire "common/locale"
local resource = mjrequire "common/resource"

local mod = {
    loadOrder = 1,
}

function mod:onload(research)
    local prevLoad = research.load
    research.load = function(research_, gameObject, constructable, flora)
        prevLoad(research_, gameObject, constructable, flora)

        research.types.butchery.orderTypeIndexesByBaseObjectTypeIndex[gameObject.types.deadMoa.index] = order.types.butcher.index
        table.insert(research.types.butchery.additionalUnlocksToShowInBreakthroughUI, {
            iconObjectTypeIndex = gameObject.types.moaMeatLeg.index,
            text = locale:get("research_unlock_butcherMoa"),
        })

        research.types.campfireCooking.constructableTypeIndexesByBaseResourceTypeIndex[resource.types.moaMeat.index] = constructable.types.cookedMoa.index
        table.insert(research.types.campfireCooking.resourceTypeIndexes, resource.types.moaMeat.index)
    end
end

return mod