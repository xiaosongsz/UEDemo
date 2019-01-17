local tParent = class('tParent')
function tParent:doSome()
    print("tParent.doSome")
end

local tClass = class("tClass", tParent)

function tClass:constructor()
    print("tClass:constructor")
    self:doSome()
    self.super:doSome()
end

function tClass:doSome()
    print("tClass.doSome")
end

return tClass