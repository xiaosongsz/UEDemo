
--定义一个类
function class(name, base)
    local _class = {}

    _class._type = name

    local super = {}
    super.constructor = function() end
    super.__call = function(class, ...)
        local _object = {}
        _object._class = class
        setmetatable(_object, {__index = class})
        _object:constructor(...)
        return _object
    end

    base = (base and type(base) == 'table' and base._type) and base or nil
    if base then
        setmetatable(super, base)
    end

    _class._base = base

    setmetatable(_class, super)

    return _class
end