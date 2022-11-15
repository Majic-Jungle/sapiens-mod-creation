
local gameObject = mjrequire "common/gameObject"
local constructable = mjrequire "common/constructable"

local mod = {
    loadOrder = 1,
}

function mod:onload(inspectCraftPanel)
    
    local prevLoad = inspectCraftPanel.load
    inspectCraftPanel.load = function(inspectCraftPanel_, serinspectUI_, inspectObjectUI_, world_, parentContainerView)

        local function insertAfter(addType, afterType, list)
            local afterFoundIndex = nil
            for i,otherType in ipairs(list) do
                if otherType == afterType then
                    afterFoundIndex = i
                    break
                end
            end
            table.insert(list, afterFoundIndex or #list, addType)
        end

        insertAfter(constructable.types.cookedMoa.index, constructable.types.cookedAlpaca.index, inspectCraftPanel.itemLists[gameObject.typeIndexMap.campfire])

        prevLoad(inspectCraftPanel_, serinspectUI_, inspectObjectUI_, world_, parentContainerView)
    end
end

return mod