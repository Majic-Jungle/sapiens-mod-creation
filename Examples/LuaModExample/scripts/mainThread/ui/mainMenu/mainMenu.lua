local mjm = mjrequire "common/mjm"
local vec3 = mjm.vec3

local uiCommon = mjrequire "mainThread/ui/uiCommon"
local material = mjrequire "common/material"

local mod = {}

function mod:onload(incoming)
    local mainMenu = incoming
    
    local baseLoadFunction = mainMenu.load
    mainMenu.load = function(self_, uiController)
        baseLoadFunction(mainMenu, uiController)

        local titleText = ModelTextView.new(mainMenu.mainBanner)
        titleText.font = Font(uiCommon.titleFontName, 16)
        titleText:setText("LuaModExample Loaded!", material.types.standardText.index)
        titleText.baseOffset = vec3(0, -40, 0)
        titleText.relativePosition = ViewPosition(MJPositionCenter, MJPositionTop)
    end
    
end

return mod