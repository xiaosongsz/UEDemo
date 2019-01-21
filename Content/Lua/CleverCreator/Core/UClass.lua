--虚幻类
UClass = class("UClass")

function UClass:constructor(userdata)
    self._userdata = userdata
    local u_mtable = getmetatable(userdata)
    local u_index = u_mtable.__index
    
    local mtable = getmetatable(self)
    local index = mtable.__index
    setmetatable(self, {__index = function(obj, key)
        local ufunc = u_index(userdata, key)
        if ufunc then
            return function(obj, ...)
                return ufunc(userdata, ...)
            end
        end
    end
    })
end

function UClass:doUClass()
    print("UClass:doUClass")
end