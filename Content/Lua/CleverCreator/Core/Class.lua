
--定义一个类
function class(name, base)
    local _class = {}
    _class._type = name
    _class._base = base

    local _index = {}
    _index.__call = function(class, ...)
        local _object = {}
        _object._class = class
        setmetatable(_object, {__index = class})
        if _object.constructor then
            _object:constructor(...)
        end
        return _object
    end

    if base then
        _index.__index = base
    end

    setmetatable(_class, _index)

    return _class
end

--虚幻类
UClass = class("UClass")

function UClass:constructor(userdata)
    self._userdata = userdata
    local u_mtable = getmetatable(userdata)
    local u_index = u_mtable.__index
    
    local mtable = getmetatable(self)
    setmetatable(self, {__index = function(obj, key)
        return function(obj, ...)
            local func = u_index(userdata, key)
            if func then
                return func(userdata, ...)
            end
        end
    end
    })
end

function UClass:doUClass()
    print("UClass:doUClass")
end