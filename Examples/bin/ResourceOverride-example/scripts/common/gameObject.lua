
local mod = {
    loadOrder = 1, -- lower numbers are loaded first, and should be preffered. If you require the mod be loaded after other mods, use a higher number.
}

function mod:onload(gameObject)
    
    local baseAddGameObjects = gameObject.addGameObjects
    gameObject.addGameObjects = function(self_) -- gameObject.addGameObjects(self_) is equivilant to gameObject:addGameObjects() in lua. :() syntax is used by convention for function calls in Sapiens, but the implicit self argument is rarely used.
        gameObject.gameObjectsTable.limestoneRock.modelName = "torusTestModel"

        baseAddGameObjects(gameObject)
    end
end

return mod