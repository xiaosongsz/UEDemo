--类表
local ClassTable = {}
CleverCreator.ClassTable = ClassTable

--定义一个类
function class(name, base)
    if ClassTable[name] then
        error("class.已经定义过此类")
        return
    end

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

    ClassTable[name] = _class

    return _class
end

--寻找定义好的类
function findClass(name)
    return ClassTable[name]
end