--CleverCreator
require("CleverCreator/Header")

print('Hello sLua')
local demo = require("UIs/Demo/Demo")
local da = demo()
local db = demo()
dump(da)
print("----------------------------------------")
dump(db)

print("----------------------------------------")

function BeginPlay()
    -- print("BeginPlay")
    -- local demo = UIManager:OpenWidget("Demo", "")
    -- UIManager:OpenGroup("Loading")
    -- print("demo", demo)

    -- for k,v in pairs(_G) do
    --     print(k,v)
    -- end
end