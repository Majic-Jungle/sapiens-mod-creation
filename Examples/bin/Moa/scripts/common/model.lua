
local mod = {
    loadOrder = 1,
}

function mod:onload(model)
    local prevLoadRemaps = model.loadRemaps
    model.loadRemaps = function(model_)
        model.remapModels.moaMeat = {
            moaMeatCooked = {
                moaMeat = "moaMeatCooked",
            },
        }
        model.remapModels.moaMeatLeg = {
            moaMeatLegCooked = {
                moaMeat = "moaMeatCooked",
            },
        }

        prevLoadRemaps(model_)
    end
end

return mod